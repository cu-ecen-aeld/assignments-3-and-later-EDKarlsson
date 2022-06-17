CC = gcc
CFLAGS = -Wall -g 

#INCLUDES=

SRCS = writer.c

OBJS = $(SRCS:.c=.o)

MAIN = writer

.PHONY: clean

all:	$(MAIN)
	@echo Finished compiling writer utility

$(MAIN):	$(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
