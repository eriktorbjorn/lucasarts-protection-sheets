CC=gcc
CFLAGS=-Wall -Wextra -pedantic

all: loom_create_table indy3_create_table maniac_create_table zak_create_table loom_decode indy3_decode maniac_decode zak_decode monkey1_decode monkey2_decode

util.o: util.c util.h

indy3_decoder.o: indy3_decoder.c decoder.h util.h
loom_decoder.o: loom_decoder.c loom_decoder.h util.h
maniac_decoder.o: maniac_decoder.c decoder.h util.h
zak_decoder.o: zak_decoder.c decoder.h util.h

indy3_decode.o: indy3_decode.c decoder.h
loom_decode.o: loom_decode.c loom_decoder.h
maniac_decode.o: maniac_decode.c decoder.h
zak_decode.o: zak_decode.c decoder.h

indy3_create_table.o: indy3_create_table.c decoder.h
loom_create_table.o: loom_create_table.c loom_symbols.h loom_decoder.h
maniac_create_table.o: maniac_create_table.c maniac_zak_symbols.h decoder.h
zak_create_table.o: zak_create_table.c maniac_zak_symbols.h decoder.h

indy3_decode: indy3_decode.o indy3_decoder.o util.o
loom_decode: loom_decode.o loom_decoder.o util.o
maniac_decode: maniac_decode.o maniac_decoder.o util.o
zak_decode: zak_decode.o zak_decoder.o util.o

loom_create_table: loom_create_table.o loom_decoder.o util.o
indy3_create_table: indy3_create_table.o indy3_decoder.o util.o
maniac_create_table: maniac_create_table.o maniac_decoder.o util.o
zak_create_table: zak_create_table.o zak_decoder.o util.o

clean:
	rm -f util.o
	rm -f indy3_decoder.o loom_decoder.o maniac_decoder.o zak_decoder.o
	rm -f indy3_decode.o loom_decode.o maniac_decode.o zak_decode.o indy3_create_table.o loom_create_table.o maniac_create_table.o zak_create_table.o monkey1_decode.o monkey2_decode.o

	rm -f indy3_decode loom_decode maniac_decode zak_decode monkey1_decode monkey2_decode
	rm -f loom_create_table indy3_create_table maniac_create_table zak_create_table
