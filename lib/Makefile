 # Makefile

CC=gcc
CFLAGS=
OBJS=add.o subtract.o multiply.o divide.o
LIBS=libtest.a

$(LIBS) : $(OBJS)
	ar rcs $(LIBS) $(OBJS)
	
all: add

add: $(OBJS)
	$(CC) $(CFLAGS) -o add $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS) add core

