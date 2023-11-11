#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "loom_decoder.h"

int main(int argc, char *argv[]) {
	char *guild_name, *thread_name;
	size_t guild_len, thread_len, i;
	int guild, thread;
	int sequence[4];

	if (argc != 3) {
		fprintf(stderr, "Usage: %s staff|sheep|spinning-wheel|anvil|goblet|soundwave throw|beat|treadle|rest\n", argv[0]);
		return 1;
	}

	guild_len = strlen(argv[1]);
	thread_len = strlen(argv[2]);

	guild_name = (char *)malloc(guild_len + 1);
	thread_name = (char *)malloc(thread_len + 1);

	for (i = 0; i < guild_len; i++) {
		guild_name[i] = (char)tolower(argv[1][i]);
	}
	for (i = 0; i < thread_len; i++) {
		thread_name[i] = (char)tolower(argv[2][i]);
	}

	if (strcmp(guild_name, "staff") == 0) {
		guild = 1;
	} else if (strcmp(guild_name, "sheep") == 0) {
		guild = 2;
	} else if (strcmp(guild_name, "spinning-wheel") == 0) {
		guild = 3;
	} else if (strcmp(guild_name, "anvil") == 0) {
		guild = 4;
	} else if (strcmp(guild_name, "goblet") == 0) {
		guild = 5;
	} else if (strcmp(guild_name, "soundwave") == 0) {
		guild = 6;
	} else {
		fprintf(stderr, "The guild symbol must be one of `staff', `sheep', `spinning-wheel', `anvil', `goblet', or `soundwave'.\n");
		return 1;
	}

	if (strcmp(thread_name, "throw") == 0) {
		thread = 1;
	} else if (strcmp(thread_name, "beat") == 0) {
		thread = 2;
	} else if (strcmp(thread_name, "treadle") == 0) {
		thread = 3;
	} else if (strcmp(thread_name, "rest") == 0) {
		thread = 4;
	} else {
		fprintf(stderr, "The thread name must be one of `throw', `beat', `treadle', or `rest'\n");
		return 1;
	}

	decode(sequence, guild, thread);

	for (i = 0; i < 4; i++) {
		printf("%d ", sequence[i] + 1);
	}

	printf("\n");
	return 0;
}
