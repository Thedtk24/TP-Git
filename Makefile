CC=gcc
CFLAGS=-O3 -g

TARGET=test

all: $(TARGET)

libppm.so: ppm.c
	$(CC) $(CFLAGS) -fpic -shared $^ -o $@

test: mandel.c libppm.so
	$(CC) $(CFLAGS) -L. mandel.c -o $@ -lppm -lm

clean:
	rm -fr $(TARGET) *.so
