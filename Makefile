CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lcrypto -lssl
DEPS = dummy.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dummy: dummy.o
	$(CC) $(CFLAGS) -o dummy dummy.o $(LDFLAGS)