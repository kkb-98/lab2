# Makefile

st_lib_calculator_make : calculator.o
	gcc -o st_lib_calculator_make calculator.o -I./lib -L./lib -ltest
	
clean :
	rm -f st_lib_calculator_make calculator.o 
