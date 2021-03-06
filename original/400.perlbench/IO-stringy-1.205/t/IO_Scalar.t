#!/usr/bin/perl -w         #-*-Perl-*-

use lib "./t";
use IO::Scalar;
use ExtUtils::TBone;
use Common;


#--------------------
#
# TEST...
#
#--------------------

# Make a tester:
my $T = typical ExtUtils::TBone;
Common->test_init(TBone=>$T);

# Set the counter:
my $tie_tests = (($] >= 5.004) ? (4 + 5) : 0);
$T->begin(17 + $tie_tests);

# Open a scalar on a string, containing initial data:
my $s = $Common::DATA_S;
my $SH = IO::Scalar->new(\$s);
$T->ok($SH, "OPEN: open a scalar on a ref to a string");

# Run standard tests:
Common->test_print($SH);
$T->ok(($s eq $Common::FDATA_S), "FULL",
       S=>$s, F=>$Common::FDATA_S);
Common->test_getc($SH);
Common->test_getline($SH);
Common->test_read($SH);
Common->test_seek($SH);
Common->test_close($SH);

# Run tie tests:
if ($tie_tests) {
    Common->test_tie(TieArgs => ['IO::Scalar']);       # 4
    Common->test_new_tie(TieArgs => ['IO::Scalar']);   # 5
}

# So we know everything went well...
$T->end;

