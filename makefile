CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2

default:
	$(CC) $(CFLAGS) -c vector.c -o vector.o
	$(CC) $(CFLAGS) -c vector_push.c -o vector_push.o
	ar ruv vector.a vector.o vector_push.o
	ranlib vector.a
	rm *.o