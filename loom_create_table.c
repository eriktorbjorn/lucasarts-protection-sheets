#include <stdio.h>

#include "loom_symbols.h"
#include "loom_decoder.h"

static void print_sequence(int guild, int draft) {
	int sequence[4];
	int i;

	// I don't know how the fake answers are generated, so hard-code them.

	const int fake_guild_answers[6][4][4] = {
		{ { 1, 0, 4, 0 }, { 10, 1, 7, 9 }, { 7, 4, 10, 8 }, { 0, 4, 10, 2 } },
		{ { 1, 4, 10, 0 }, { 9, 7, 10, 0 }, { 4, 11, 0, 10 }, { 0,10, 7, 2 } },
		{ { 9, 3, 2, 6 }, { 7, 8, 0, 4 }, { 1, 9, 11, 10 }, { 4, 3, 2, 6 } },
		{ { 2, 9, 8, 10 }, { 11, 9, 10, 1 }, { 6, 3, 0, 1 }, { 8, 5, 6, 1 } },
		{ { 6, 10, 11, 6 }, { 10, 0, 11, 4 }, { 9, 4, 4, 10 }, { 1, 4, 8, 11 } },
		{ { 7, 8, 10, 4 }, { 3, 8, 2, 10 }, { 0, 11, 5, 5 }, { 9, 0, 2, 10 } },
	};

	if (guild >= 7) {
		for (i = 0; i < 4; i++) {
			sequence[i] = fake_guild_answers[guild - 7][draft - 1][i];
		}
	} else {
		decode(sequence, guild, draft);
	}

	for (i = 0; i < 4; i++) {
		printf("<svg class=\"symbol\"><use href=\"#S%d\" /></svg>", sequence[i] + 1);
	}
}

int main() {
	const char *guild_id[] = {
		"G1", "G2", "G3", "G4", "G5", "G6", "GU1", "GU2", "GU3", "GU4", "GU5", "GU6"
	};

	const int guild_order[] = {
		6, 1, 2, 7, 4, 8, 9, 0, 10, 3, 5, 11
	};

	unsigned int i, thread;

	puts(html_preamble);
	printf("<body>\n");

	for (i = 0; i < sizeof(svg_symbols) / sizeof(svg_symbols[0]); i++)
		puts(svg_symbols[i]);

	printf("<table>\n");

	printf("<tr><th></th><th class=\"thread\">Throw</th><th class=\"thread\">Beat</th><th class=\"thread\">Treadle</th><th class=\"thread\">Rest</th></tr>\n");

	for (i = 0; i < 12; i++) {
		printf("<tr><td><div class=\"guild\"><svg class=\"guild-symbol\"><use href=\"#%s\" /></svg></div></td>", guild_id[guild_order[i]]);
		for (thread = 1; thread <= 4; thread++) {
			printf("<td>");
			printf("<div class=\"weave\">");
			print_sequence(guild_order[i] + 1, thread);
			printf("</div>");
			printf("</td>");
		}
		printf("</tr>\n");
	}

	printf("</table>\n");
	printf("</body>\n");
	printf("</html>\n");

	return 0;
}

