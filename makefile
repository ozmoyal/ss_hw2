CC = gcc -g
AR = ar -rcs
OBJECTS_MAIN = main.o
OBJECTS_LIB = myBank.o
CFLAGS = -Wall -fPIC

all: mybanks mybankd mains maind
mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(CFLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a
maind: $(OBJECTS_MAIN) libmyBank.so
	$(CC) $(CFLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.so
mybanks: libmyBank.a
libmyBank.a: $(OBJECTS_LIB) myBank.h
	$(AR) libmyBank.a $(OBJECTS_LIB)
mybankd: libmyBank.so
libmyBank.so: $(OBJECTS_LIB) myBank.h
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c myBank.c

.PHONY: clean all mybanks mybankd

clean:
	rm -f *.o *.a *.so mains maind