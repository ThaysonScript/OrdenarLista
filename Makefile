COMPILER="gcc"
INCLUDE_FOLDERS="/includes"
BIN_FOLDER="/bins"
MAIN_CODE="main"

mkdir -p /bins

all:
 ${COMPILER} ${MAIN_CODE}.c -I${INCLUDE_FOLDERS} -o ${BIN_FOLDER}/${MAIN_CODE}.bin

 ./bins/main.bin
