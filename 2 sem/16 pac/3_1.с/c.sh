gcc -c level1.c 
gcc -c level2.c 
gcc -c level3.c
ar rc libmyblas.a level1.o level2.o level3.o
