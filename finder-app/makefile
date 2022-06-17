CC = ${CROSS_COMPILE}gcc
CFLAGS = -Wall -g 

#INCLUDES=

.PHONY: all clean

SRCS = writer.c

OBJS = $(SRCS:.c=.o)

MAIN = writer

all:	$(MAIN)
	@echo Finished compiling writer utility

$(MAIN):	$(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)

run: all
	./writer
