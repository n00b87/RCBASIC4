#!/bin/bash

BASEDIR=$(dirname 0)


echo "build journal path: $RCBASIC_BUILD_JOURNAL"

codeblocks --clean rcbasic_runtime.cbp
codeblocks --target=Release --build rcbasic_runtime.cbp

if [ ! -e $BASEDIR/bin/Release/rcbasic_runtime ]
then

pushd $RCBASIC_BUILD_MAIN_DIR
echo "export RCBASIC_RUNTIME_ERROR=1" >> "$RCBASIC_BUILD_JOURNAL"
popd

else

pushd $RCBASIC_BUILD_MAIN_DIR
echo "export RCBASIC_RUNTIME_ERROR=0" >> "$RCBASIC_BUILD_JOURNAL"
popd

fi

