#!/bin/sh

CURRENT_PATH=`pwd`

which qmake > /dev/null

if [ 0 -ne "$?" ]
then
        echo "Could not find qmake in the PATH"
        exit 1;
fi

QMAKE=`which qmake`

if [ "${Configuration}" == "" ]
then
Configuration="debug"
fi
if [ "${PlatformArchitecture}" == "" ]
then
PlatformArchitecture=64
fi
if [ "${DEVELOPMENT}" == "" ]
then
DEVELOPMENT=yes
fi

if [ "${BUILD_OUTPUT}" == "" ]
then
BUILD_OUTPUT="${CURRENT_PATH}/build/${Configuration}x${PlatformArchitecture}"
fi

QMAKESPEC="linux-g++-64"

echo "environment variables"
echo "-- Found qmake in ${QMAKE}"
echo "-- Configuration set to ${Configuration}"
echo "-- PlatformArchitecture set to ${PlatformArchitecture}"
echo "-- QMAKESPEC set to ${QMAKESPEC}"
echo "-- BUILD_OUTPUT set to ${BUILD_OUTPUT}"

qmake distribution.pro BUILD_OUTPUT="${BUILD_OUTPUT}" CONFIG+=${Configuration}
make
