#=======================================================================
#    ____  ____  _____              _    ____ ___   ____
#   |  _ \|  _ \|  ___|  _   _     / \  |  _ \_ _| |___ \
#   | |_) | | | | |_    (_) (_)   / _ \ | |_) | |    __) |
#   |  __/| |_| |  _|    _   _   / ___ \|  __/| |   / __/
#   |_|   |____/|_|     (_) (_) /_/   \_\_|  |___| |_____|
#
#   A Perl Module Chain to faciliate the Creation and Modification
#   of High-Quality "Portable Document Format (PDF)" Files.
#
#   Copyright 1999-2005 Alfred Reibenschuh <areibens@cpan.org>.
#
#=======================================================================
#
#   This library is free software; you can redistribute it and/or
#   modify it under the terms of the GNU Lesser General Public
#   License as published by the Free Software Foundation; either
#   version 2 of the License, or (at your option) any later version.
#
#   This library is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#   Lesser General Public License for more details.
#
#   You should have received a copy of the GNU Lesser General Public
#   License along with this library; if not, write to the
#   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
#   Boston, MA 02111-1307, USA.
#
#   $Id: code3of9.pm,v 2.0 2005/11/16 02:18:23 areibens Exp $
#
#=======================================================================

package PDF::API2::Resource::XObject::Form::BarCode::code3of9;

BEGIN {

    use PDF::API2::Util;
    use PDF::API2::Basic::PDF::Utils;
    use PDF::API2::Resource::XObject::Form::BarCode;

    use POSIX;

    use vars qw(@ISA $VERSION);

    @ISA = qw( PDF::API2::Resource::XObject::Form::BarCode );

    ( $VERSION ) = sprintf '%i.%03i', split(/\./,('$Revision: 2.0 $' =~ /Revision: (\S+)\s/)[0]); # $Date: 2005/11/16 02:18:23 $

}
no warnings qw[ deprecated recursion uninitialized ];

=item $res = PDF::API2::Resource::XObject::Form::BarCode::code3of9->new $pdf

Returns a code3of9 object.

=cut

sub new {
    my ($class,$pdf,%opts) = @_;
    my $self;

    $class = ref $class if ref $class;

    $self=$class->SUPER::new($pdf,%opts);

    my @bar;
    if($opts{-ext} && $opts{-chk}) {
        @bar = &encode_3of9_ext_w_chk($opts{-code});
    } elsif($opts{-ext}) {
        @bar = &encode_3of9_ext($opts{-code});
    } elsif($opts{-chk}) {
        @bar = &encode_3of9_w_chk($opts{-code});
    } else {
        @bar = &encode_3of9($opts{-code});
    }

    $self->drawbar([@bar]);

    return($self);
}

my $code3of9 = q|1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ-. $/+%*|;
my $code3of9_chk = q|0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-. $/+%|;

my @bar3of9 = qw/
    2112111121  1122111121  2122111111  1112211121
    2112211111  1122211111  1112112121  2112112111
    1122112111  1112212111  2111121121  1121121121
    2121121111  1111221121  2111221111  1121221111
    1111122121  2111122111  1121122111  1111222111
    2111111221  1121111221  2121111211  1111211221
    2111211211  1121211211  1111112221  2111112211
    1121112211  1111212211  2211111121  1221111121
    2221111111  1211211121  2211211111  1221211111
    1211112121  2211112111  1221112111  1212121111
    1212111211  1211121211  1112121211  abaababaa1
/;


my %bar3of9ext=(
    "\x00" => '%U',
    "\x01" => '$A',
    "\x02" => '$B',
    "\x03" => '$C',
    "\x04" => '$D',
    "\x05" => '$E',
    "\x06" => '$F',
    "\x07" => '$G',
    "\x08" => '$H',
    "\x09" => '$I',
    "\x0a" => '$J',
    "\x0b" => '$K',
    "\x0c" => '$L',
    "\x0d" => '$M',
    "\x0e" => '$N',
    "\x0f" => '$O',
    "\x10" => '$P',
    "\x11" => '$Q',
    "\x12" => '$R',
    "\x13" => '$S',
    "\x14" => '$T',
    "\x15" => '$U',
    "\x16" => '$V',
    "\x17" => '$W',
    "\x18" => '$X',
    "\x19" => '$Y',
    "\x1a" => '$Z',
    "\x1b" => '%A',
    "\x1c" => '%B',
    "\x1d" => '%C',
    "\x1e" => '%D',
    "\x1f" => '$E',
    "\x20" => ' ',
    "!" => '/A',
    '"' => '/B',
    "#" => '/C',
    '$' => '/D',
    '%' => '/E',
    '&' => '/F',
    "'" => '/G',
    '(' => '/H',
    ')' => '/I',
    '*' => '/J',
    '+' => '/K',
    ',' => '/L',
    '-' => '-',
    '.' => '.',
    '/' => '/O',
    '0' => '0',
    '1' => '1',
    '2' => '2',
    '3' => '3',
    '4' => '4',
    '5' => '5',
    '6' => '6',
    '7' => '7',
    '8' => '8',
    '9' => '9',
    ':' => '/Z',
    ';' => '%F',
    '<' => '%G',
    '=' => '%H',
    '>' => '%I',
    '?' => '%J',
    '@' => '%V',
    'A' => 'A',
    'B' => 'B',
    'C' => 'C',
    'D' => 'D',
    'E' => 'E',
    'F' => 'F',
    'G' => 'G',
    'H' => 'H',
    'I' => 'I',
    'J' => 'J',
    'K' => 'K',
    'L' => 'L',
    'M' => 'M',
    'N' => 'N',
    'O' => 'O',
    'P' => 'P',
    'Q' => 'Q',
    'R' => 'R',
    'S' => 'S',
    'T' => 'T',
    'U' => 'U',
    'V' => 'V',
    'W' => 'W',
    'X' => 'X',
    'Y' => 'Y',
    'Z' => 'Z',
    '[' => '%K',
    '\\' => '%L',
    ']' => '%M',
    '^' => '%N',
    '_' => '%O',
    '`' => '%W',
    'a' => '+A',
    'b' => '+B',
    'c' => '+C',
    'd' => '+D',
    'e' => '+E',
    'f' => '+F',
    'g' => '+G',
    'h' => '+H',
    'i' => '+I',
    'j' => '+J',
    'k' => '+K',
    'l' => '+L',
    'm' => '+M',
    'n' => '+N',
    'o' => '+O',
    'p' => '+P',
    'q' => '+Q',
    'r' => '+R',
    's' => '+S',
    't' => '+T',
    'u' => '+U',
    'v' => '+V',
    'w' => '+W',
    'x' => '+X',
    'y' => '+Y',
    'z' => '+Z',
    '{' => '%P',
    '|' => '%Q',
    '}' => '%R',
    '~' => '%S',
    "\x7f" => '%T'
);

sub encode_3of9_char {
    my $char=shift @_;
    return($bar3of9[index($code3of9,$char)]);
}

sub encode_3of9_string {
    my $string=shift @_;
    my $bar;
    my @c=split(//,$string);

    foreach my $char (@c) {
        $bar.=encode_3of9_char($char);
    }
    return($bar);
}

sub encode_3of9_string_w_chk {
    my $string=shift @_;
    my ($bar,$num);
    my @c=split(//,$string);

    foreach my $char (@c) {
        $num+=index($code3of9_chk,$char);
        $bar.=encode_3of9_char($char);
    }
    $num%=43;
    $bar.=$bar3of9[$num];
    return($bar);
}

sub encode_3of9 {
    my $string=shift @_;
    my @bar;

    $string=uc($string);
    $string=~s/[^0-9A-Z\-\.\ \$\/\+\%]+//g;

    push(@bar, encode_3of9_char('*') );
    push(@bar, [ encode_3of9_string($string), $string ] );
    push(@bar, $bar[0] );

    return(@bar);
}

sub encode_3of9_w_chk {
    my $string=shift @_;
    my @bar;

    $string=uc($string);
    $string=~s/[^0-9A-Z\-\.\ \$\/\+\%]+//g;

    push(@bar, encode_3of9_char('*') );
    push(@bar, [ encode_3of9_string_w_chk($string), $string ] );
    push(@bar, $bar[0] );

    return(@bar);
}

sub encode_3of9_ext {
    my $string=shift @_;
    my @c=split(//,$string);
    my ($enc,@bar);
    map { $enc.=$bar3of9ext{$_}; } (@c);

    push(@bar, encode_3of9_char('*') );
    push(@bar, [ encode_3of9_string($enc), $string ] );
    push(@bar, $bar[0] );

    return(@bar);
}

sub encode_3of9_ext_w_chk {
    my $string=shift @_;
    my @c=split(//,$string);
    my ($enc,@bar);
    map { $enc.=$bar3of9ext{$_}; } (@c);

    push(@bar, encode_3of9_char('*') );
    push(@bar, [ encode_3of9_string_w_chk($enc), $string ] );
    push(@bar, $bar[0] );

    return(@bar);
}

1;

__END__

=head1 AUTHOR

alfred reibenschuh

=head1 HISTORY

    $Log: code3of9.pm,v $
    Revision 2.0  2005/11/16 02:18:23  areibens
    revision workaround for SF cvs import not to screw up CPAN

    Revision 1.2  2005/11/16 01:27:50  areibens
    genesis2

    Revision 1.1  2005/11/16 01:19:27  areibens
    genesis

    Revision 1.10  2005/06/17 19:44:03  fredo
    fixed CPAN modulefile versioning (again)

    Revision 1.9  2005/06/17 18:53:34  fredo
    fixed CPAN modulefile versioning (dislikes cvs)

    Revision 1.8  2005/03/14 22:01:31  fredo
    upd 2005

    Revision 1.7  2004/12/16 00:30:54  fredo
    added no warn for recursion

    Revision 1.6  2004/06/15 09:14:54  fredo
    removed cr+lf

    Revision 1.5  2004/06/07 19:44:44  fredo
    cleaned out cr+lf for lf

    Revision 1.4  2003/12/08 13:06:09  Administrator
    corrected to proper licencing statement

    Revision 1.3  2003/11/30 17:36:59  Administrator
    merged into default

    Revision 1.2.2.1  2003/11/30 16:57:09  Administrator
    merged into default

    Revision 1.2  2003/11/30 11:53:10  Administrator
    added CVS id/log


=cut
