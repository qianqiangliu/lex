CFLAGS := -Wall

all: myscanner

myscanner: myscanner.o lex.yy.o
	$(CC) -o $@ $^

myscanner.o: myscanner.c myscanner.h
	$(CC) $(CFLAGS) -o $@ -c $<

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -o $@ -c $<

lex.yy.c: myscanner.l myscanner.h
	flex -o $@ $<

clean:
	rm -f *.o .tags lex.yy.c myscanner
