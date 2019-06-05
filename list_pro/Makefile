# Compiling under Linux
TARGE  = list_pro
OBJ    = test_list_pro.o list_pro.o
CC     = gcc
CFLAGS = -std=c11

all:$(OBJ)
	$(CC) $(OBJ) -o $(TARGE)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ) $(TARGE)
