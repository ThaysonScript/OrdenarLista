all: obj bin main.bin
	./bin/main.bin

main.bin: insertionSort.o selectionSort.o menus.o geradorCargaInsertion.o main.o
	gcc -Iincludes -c main.c -o bin/main.bin
	gcc -Iincludes objects/insertionSort.o objects/selectionSort.o objects/menus.o objects/geradorCargaInsertion.o objects/main.o -o bin/main.bin

insertionSort.o:
	gcc -Iincludes -c src/insertionSort.c -o objects/insertionSort.o

selectionSort.o:
	gcc -Iincludes -c src/selectionSort.c -o objects/selectionSort.o

menus.o:
	gcc -Iincludes -c src/menus.c -o objects/menus.o

geradorCargaInsertion.o:
	gcc -Iincludes -c geradorCarga/geradorCargaInsertion.c -o objects/geradorCargaInsertion.o

main.o:
	gcc -Iincludes -c main.c -o objects/main.o

obj:
	mkdir -p ./objects

bin:
	mkdir -p ./bin