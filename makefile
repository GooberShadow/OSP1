RELEASE_NAME=dt

ALL: main.o
	gcc -o $(RELEASE_NAME) main.c options.c print.c -I .
.PHONY: clean

clean:
	rm -f *.o $(RELEASE_NAME)
