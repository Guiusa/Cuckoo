FLAS = -Wall
CC = gcc
PROG = main.c
OUT = myht

all:
	$(CC) $(FLAGS) hashlib.c $(PROG) -o $(OUT) -lm
purge:
	rm myht
