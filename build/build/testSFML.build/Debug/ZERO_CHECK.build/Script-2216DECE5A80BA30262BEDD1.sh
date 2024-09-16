#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/alexiapappas/MSD/ShapeDodge2/build
  make -f /Users/alexiapappas/MSD/ShapeDodge2/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/alexiapappas/MSD/ShapeDodge2/build
  make -f /Users/alexiapappas/MSD/ShapeDodge2/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/alexiapappas/MSD/ShapeDodge2/build
  make -f /Users/alexiapappas/MSD/ShapeDodge2/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/alexiapappas/MSD/ShapeDodge2/build
  make -f /Users/alexiapappas/MSD/ShapeDodge2/build/CMakeScripts/ReRunCMake.make
fi

