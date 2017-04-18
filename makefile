PROG_NAME=kini
SRCS= kini_alloc.c
OBJS=$(SRCS:.c=.o)
CC=gcc
CFLAGS=-Wall

MAIN=main.c

$(PROG_NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG_NAME) $(MAIN)

$(OBJS): $(SRCS)
	$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	rm -f *.*~ *~ $(PROG_NAME) $(OBJS)
