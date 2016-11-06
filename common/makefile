
OBJS = euler.o
# Name of your compiler
CC = gcc

# Compiler options
CFLAGS = -O2

a.out: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) 
clean:
	rm -f  a.out *.o

# Some make-programs do not know about the f90 suffix,
# so we may have to add a rule for how to produce
# an object file (.o) from a Fortran90 file (.f90).
.SUFFIXES: .c
	$(CC) -c $(CFLAGS) $<
