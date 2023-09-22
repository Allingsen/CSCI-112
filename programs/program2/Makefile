program2: program2.o funcs.o
	gcc -o program2 program2.o funcs.o -Wall
program2.o: program2.c structs.h
	gcc -c program2.c structs.h
funcs.o: funcs.c structs.h
	gcc -c funcs.c -Wall