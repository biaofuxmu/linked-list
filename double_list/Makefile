# Compiling under Linux
TARGE  = double_list
OBJ    = test_double_list.o double_list.o
CC     = gcc
CFLAGS = -std=c11

all:$(OBJ)
	$(CC) $(OBJ) -o $(TARGE)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ) $(TARGE)
