# Compiling under Linux
TARGE  = single_list
OBJ    = test_single_list.o single_list.o
CC     = gcc
CFLAGS = -std=c11

all:$(OBJ)
	$(CC) $(OBJ) -o $(TARGE)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ) $(TARGE)
