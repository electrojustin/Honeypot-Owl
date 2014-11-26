all: orly.so
orly.so: orly.o
	gcc -shared orly.o -o orly.so -ldl
orly.o: orly.c
	gcc -c -fPIC orly.c
clean:
	rm orly.o
