CC = gcc
CLFAGS = -g -Wall

INCLUDES =

MAIN = writer

.PHONY: clean

default: $(MAIN)
	@echo Finished compiling writer utility

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
