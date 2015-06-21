################################################################################
#
#            !!!!!   Do NOT edit this file directly!   !!!!!
#
#            Edit mktests.PL and/or parts/inc/cop instead.
#
################################################################################

BEGIN {
  if ($ENV{'PERL_CORE'}) {
    chdir 't' if -d 't';
    @INC = ('../lib', '../ext/Devel/PPPort/t') if -d '../lib' && -d '../ext';
    require Config; import Config;
    use vars '%Config';
    if (" $Config{'extensions'} " !~ m[ Devel/PPPort ]) {
      print "1..0 # Skip -- Perl configured without Devel::PPPort module\n";
      exit 0;
    }
  }
  else {
    unshift @INC, 't';
  }

  eval "use Test";
  if ($@) {
    require 'testutil.pl';
    print "1..2\n";
  }
  else {
    plan(tests => 2);
  }
}

use Devel::PPPort;
use strict;
$^W = 1;

my $package;
{
  package MyPackage;
  $package = &Devel::PPPort::CopSTASHPV();
}
print "# $package\n";
ok($package, "MyPackage");

my $file = &Devel::PPPort::CopFILE();
print "# $file\n";
ok($file =~ /cop/i);

