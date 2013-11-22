#!/bin/bash
BPHOMEDIR="/home/kbrown/MentorGraphics/BridgePoint"
BP_VERSION="4.1.0"

function die() {
  echo -e $@
  exit 1
}

if [ "${MGLS_LICENSE_FILE}" == "" ]; then
  if [ "${LM_LICENSE_FILE}" == "" ]; then
    #
    # Since the license path is not already set, use the standard location.  BridgePoint users may
    # choose to set the value in the environment, or modify the following line to point to the correct
    # location (either local or remote).
    #
    # example configuration for a remote license server
    #    export MGLS_LICENSE_FILE=1717@svr-taz-eng-05
    #
    MGLS_LICENSE_FILE="$BPHOMEDIR/license/license.dat"
  else
    MGLS_LICENSE_FILE=$LM_LICENSE_FILE
  fi
fi

# Replace any ':' in environment variable with ',' for compatibility
# with MC3020
MGLS_LICENSE_FILE=`echo $MGLS_LICENSE_FILE | sed 's/:/,/g'`

MGLS_LICENSE_FILE=1717@wv-lic-01.wv.mentorg.com,1717@wv-lic-02.wv.mentorg.com
export MGLS_LICENSE_FILE

[ $MGLS_LICENSE_FILE ] || die "No license is setup (missing \$LM_LICENSE_FILE)"

#
# DO NOT MODIFY ANY OF THE FOLLOWING LINES.
#
export ORIGINAL_PATH=$PATH
export PATH=$PATH:$BPHOMEDIR/tools/docgen/docbook
export GDK_NATIVE_WINDOWS=true
export MGC_EMBEDDED_HOME=$BPHOMEDIR
export MGLS_DLL=
#export MGLS_PKGINFO_FILE=
export MGC_HOME=
export MGLS_HOME=$BPHOMEDIR/eclipse_extensions/BridgePoint/eclipse/plugins/com.mentor.nucleus.bp.core.linux.x86_$BP_VERSION/os/linux/x86
export BP_JVM=$BPHOMEDIR/jre/lib/i386/client/libjvm.so

#$BPHOMEDIR/eclipse/eclipse -vm $BP_JVM $1 $2 $3 $4 $5 $6 $7 $8 $9

export BPMCHOME=$BPHOMEDIR/eclipse_extensions/BridgePoint/eclipse/plugins/com.mentor.nucleus.bp.mc.c.binary_4.1.0/
rm -f src/*
cd gen
$BPMCHOME/mc3020/bin/xtumlmc_build -home $BPMCHOME -l3b -e -d code_generation -O ../../src/
cd ../
touch src/.mcpaas_done

# Restore the path
export PATH=$ORIGINAL_PATH