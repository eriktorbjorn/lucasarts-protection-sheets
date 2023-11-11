#include <stdio.h>

#define PAGE_TITLE "NUKE'M ALARMS Owner's Disarmament Quick Reference Guide"

extern const char *html_preamble;
extern const char *svg_symbols;

#include "maniac_zak_symbols.h"
#include "decoder.h"

static void print_sequence(int section, int row, int column) {
	int sequence[4];
	int i;

	decode(sequence, section, row, column);
	
	for (i = 0; i < 4; i++) {
		printf("<svg><use href=\"#%c\" /></svg>", sequence[i] + 'A');
	}
}

static void print_code_table(int section) {
	int i, j;

	if (section < 7)
		printf("<table style=\"page-break-after: always;\">\n");
	else
		printf("<table>\n");

	printf("<caption>Section %d</caption>\n", section);
	printf("<tr style=\"text-align: center;\"><td></td>");

	for (i = 0; i < 9; i++)
		printf("<th>%c</th>", 'A' + i);

	printf("</tr>\n");

	for (i = 1; i <= 37; i++) {
		printf("<tr><th>%d</th>", i);

		for (j = 1; j <= 9; j++) {
			printf("<td>");
			printf("<div class=\"symbols\">");
			print_sequence(section, i, j);
			printf("</div>");
			printf("</td>");
		}

		printf("</tr>\n");
	}

	printf("</table>\n");
}

int main() {
	int i;

	puts(html_preamble);
	printf("<body>\n");
	puts(svg_symbols);

	for (i = 1; i <= 7; i++) {
		print_code_table(i);
	}

	printf("</body>\n");
	printf("</html>\n");

	return 0;
}
	
