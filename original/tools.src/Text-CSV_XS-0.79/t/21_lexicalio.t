#!/usr/bin/perl

use strict;
$^W = 1;	# use warnings;

use Test::More;

BEGIN {
    if ($] < 5.006) {
	plan skip_all => "No lexical file handles in in this ancient perl version";
	}
    else {
	plan tests => 105;
	}
    }

BEGIN {
    use_ok "Text::CSV_XS";
    plan skip_all => "Cannot load Text::CSV_XS" if $@;
    require "t/util.pl";
    }

$|  = 1;
$/  = "\n";
$\  = undef;

my $io;
my $csv = Text::CSV_XS->new ();

my $UTF8 = ($ENV{LANG} || "C").($ENV{LC_ALL} || "C") =~ m/utf-?8/i ? 1 : 0;

ok (!$csv->print ($io, ["abc", "def\007", "ghi"]), "print bad character");

for ( [  1, 1, 1, '""'				],
      [  2, 1, 1, '', ''			],
      [  3, 1, 0, '', 'I said, "Hi!"', ''	],
      [  4, 1, 0, '"', 'abc'			],
      [  5, 1, 0, 'abc', '"'			],
      [  6, 1, 1, 'abc', 'def', 'ghi'		],
      [  7, 1, 1, "abc\tdef", 'ghi'		],
      [  8, 1, 0, '"abc'			],
      [  9, 1, 0, 'ab"c'			],
      [ 10, 1, 0, '"ab"c"'			],
      [ 11, 0, 0, qq("abc\nc")			],
      [ 12, 1, 1, q(","), ','			],
      [ 13, 1, 0, qq("","I said,\t""Hi!""",""), '', qq(I said,\t"Hi!"), '' ],
      ) {
    my ($tst, $validp, $validg, @arg, $row) = @$_;

    open  $io, ">_21test.csv" or die "_21test.csv: $!";
    is ($csv->print ($io, \@arg), $validp||"", "$tst - print ()");
    close $io;

    open  $io, ">_21test.csv" or die "_21test.csv: $!";
    print $io join ",", @arg;
    close $io;

    open  $io, "<_21test.csv" or die "_21test.csv: $!";
    $row = $csv->getline ($io);
    unless ($validg) {
	is ($row, undef, "$tst - false getline ()");
	next;
	}
    ok ($row, "$tst - good getline ()");
    $tst == 12 and @arg = (",", "", "");
    foreach my $a (0 .. $#arg) {
	(my $exp = $arg[$a]) =~ s/^"(.*)"$/$1/;
	is ($row->[$a], $exp, "$tst - field $a");
	}
    }

unlink "_21test.csv";

# This test because of a problem with DBD::CSV

ok (1, "Tests for DBD::CSV");
open  $io, ">_21test.csv" or die "_21test.csv: $!";
$csv->binary (1);
$csv->eol    ("\r\n");
ok ($csv->print ($io, [ "id", "name"			]), "Bad character");
ok ($csv->print ($io, [   1,  "Alligator Descartes"	]), "Name 1");
ok ($csv->print ($io, [  "3", "Jochen Wiedmann"		]), "Name 2");
ok ($csv->print ($io, [   2,  "Tim Bunce"		]), "Name 3");
ok ($csv->print ($io, [ " 4", "Andreas K�nig"		]), "Name 4");
ok ($csv->print ($io, [   5				]), "Name 5");
close $io;

my $expected = <<"CONTENTS";
id,name\015
1,"Alligator Descartes"\015
3,"Jochen Wiedmann"\015
2,"Tim Bunce"\015
" 4","Andreas K�nig"\015
5\015
CONTENTS

open  $io, "<_21test.csv" or die "_21test.csv: $!";
my $content = do { local $/; <$io> };
close $io;
is ($content, $expected, "Content");
open  $io, ">_21test.csv" or die "_21test.csv: $!";
print $io $content;
close $io;
open  $io, "<_21test.csv" or die "_21test.csv: $!";

my $fields;
print "# Retrieving data\n";
for (0 .. 5) {
    ok ($fields = $csv->getline ($io),			"Fetch field $_");
    is ($csv->eof, "",					"EOF");
    print "# Row $_: $fields (@$fields)\n";
    }
is ($csv->getline ($io), undef,				"Fetch field 6");
is ($csv->eof, 1,					"EOF");

# Edge cases
$csv = Text::CSV_XS->new ({ escape_char => "+" });
for ([  1, 1,    0, "\n"		],
     [  2, 1,    0, "+\n"		],
     [  3, 1,    0, "+"			],
     [  4, 0, 2021, qq{"+"\n}		],
     [  5, 0, 2025, qq{"+\n}		],
     [  6, 0, 2011, qq{""+\n}		],
     [  7, 0, 2027, qq{"+"}		],
     [  8, 0, 2024, qq{"+}		],
     [  9, 0, 2011, qq{""+}		],
     [ 10, 0, 2037, "\r"		],
     [ 11, 0, 2031, "\r\r"		],
     [ 12, 0, 2032, "+\r\r"		],
     [ 13, 0, 2032, "+\r\r+"		],
     [ 14, 0, 2022, qq{"\r"}		],
     [ 15, 0, 2022, qq{"\r\r" }		],
     [ 16, 0, 2022, qq{"\r\r"\t}	],
     [ 17, 0, 2025, qq{"+\r\r"}		],
     [ 18, 0, 2025, qq{"+\r\r+"}	],
     [ 19, 0, 2022, qq{"\r"\r}		],
     [ 20, 0, 2022, qq{"\r\r"\r}	],
     [ 21, 0, 2025, qq{"+\r\r"\r}	],
     [ 22, 0, 2025, qq{"+\r\r+"\r}	],
     ) {
    my ($tst, $valid, $err, $str) = @$_;
    open  my $io, ">_21test.csv" or die "_21test.csv: $!";
    print $io $str;
    close $io;
    open  $io, "<_21test.csv" or die "_21test.csv: $!";
    my $row = $csv->getline ($io);
    close $io;
    my @err  = $csv->error_diag;
    my $sstr = _readable ($str);
    SKIP: {
	$tst == 10 && $] >= 5.008 && $] < 5.008003 && $UTF8 and
	    skip "Be reasonable, this perl version does not do Unicode reliable", 2;
	ok ($valid ? $row : !$row, "$tst - getline ESC +, '$sstr'");
	is ($err[0], $err, "Error expected $err");
	}
    }

unlink "_21test.csv";
