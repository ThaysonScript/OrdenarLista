INCLUDE_FOLDERS="/includes"
BIN_FOLDER="bins"
MAIN_CODE="main"

all:
	# criar pasta de binarios caso nao existir
	mkdir -p ${BIN_FOLDER}

	# compilar main
	gcc ${MAIN_CODE}.c -I${INCLUDE_FOLDERS} -o ${BIN_FOLDER}/${MAIN_CODE}.bin

	# compilar geradorCarga
	gcc ./geradorCarga/geradorCarga.c -I${INCLUDE_FOLDERS} -o ${BIN_FOLDER}/geradorCarga.bin
	
	reset
	./${BIN_FOLDER}/${MAIN_CODE}.bin