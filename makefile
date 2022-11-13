CC = gcc
CFLAGS = -Wall -Wextra -O2 -Wno-varargs -Werror
OBJ_FILES = vector.o vector_push.o
LIB_NAME = libvector.a

default:
	$(CC) $(CFLAGS) -c vector.c -o vector.o
	$(CC) $(CFLAGS) -c vector_push.c -o vector_push.o
	ar ruv $(LIB_NAME) $(OBJ_FILES)
	ranlib $(LIB_NAME)
	rm $(OBJ_FILES)

test:
	gcc test.c $(LIB_NAME)
	./a.out
	rm a.out