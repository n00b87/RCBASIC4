#!/bin/bash


BASEDIR=$(dirname 0)
cd $BASEDIR

RCBASIC_BUILD_ERROR=2
RCBASIC_RUNTIME_ERROR=2

export RCBASIC_BUILD_MAIN_DIR=/home/n00bc0de/Projects

export RCBASIC_BUILD_JOURNAL=build_journal.sh

#RCBASIC_BUILD
if [ -e $RCBASIC_BUILD_JOURNAL ]
then
rm $RCBASIC_BUILD_JOURNAL
fi

touch build_journal.sh
chmod +x build_journal.sh

pushd $BASEDIR/RCBASIC4/rcbasic_build
./build.sh
popd

source $RCBASIC_BUILD_JOURNAL

echo "RCBASIC_BUILD STATUS = $RCBASIC_BUILD_ERROR"


#RCBASIC_RUNTIME
if [ $RCBASIC_BUILD_ERROR == 0 ]
then

pushd $BASEDIR/RCBASIC4/rcbasic_runtime
./build.sh
popd

source $RCBASIC_BUILD_JOURNAL

echo "RCBASIC_RUNTIME STATUS = $RCBASIC_RUNTIME_ERROR"

fi


echo "rcbasic_build status=$RCBASIC_BUILD_ERROR"
echo "rcbasic_RUNTIME status=$RCBASIC_RUNTIME_ERROR"
