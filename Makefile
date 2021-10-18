# Makefile

st_lib_calculator_make : calculator.o
	gcc -pg -g -o st_lib_calculator_make calculator.o -I./lib -L./lib -ltest
calculator.o : calculator.c
	gcc -pg -c calculator.c -I./lib -L./lib -ltest
clean :
	rm -f st_lib_calculator_make calculator.o 
