INCLUDE_FOLDERS="/includes"
BIN_FOLDER="bins"
MAIN_CODE="main"

all:
	mkdir -p ${BIN_FOLDER}
	gcc ${MAIN_CODE}.c -I${INCLUDE_FOLDERS} -o ${BIN_FOLDER}/${MAIN_CODE}.bin
	
	reset
	./${BIN_FOLDER}/${MAIN_CODE}.bin