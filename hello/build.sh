#!/bin/bash

WD=$(dirname $0)
WD=$(cd $WD;pwd)

source ${WD}/../kbuild_include.sh

TARGET=${3:?"complile target: module or clean"}

BUILD_CMD="make EXTRAVERSION=${EXTRAVERSION} -C ${WORKDIR} M=${WD} ${TARGET}"

echo "Executing ${BUILD_CMD}"

eval ${BUILD_CMD}
