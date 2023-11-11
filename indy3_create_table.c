#include <stdio.h>

#include "decoder.h"

static const char *html_preamble =
	"<!DOCTYPE html>\n"
	"<html lang=\"en\">\n"
	"<head>\n"
	"<meta charset=\"utf-8\">\n"
	"<link href=\"https://fonts.googleapis.com/css2?family=Gentium+Book+Basic&family=Gentium+Basic&family=Noto+Sans+Coptic\" rel=\"stylesheet\">\n"
	"<title>Indiana Jones and the Last Crusade, Translation Table</title>\n"
	"<style>\n"
	"table {\n"
	"    border: 1px solid black;\n"
	"}\n"
	"caption {\n"
	"    font-family: 'Gentium Book Basic';\n"
	"    font-size: 20px;\n"
	"}\n"
	"th {\n"
	"    font-family: 'Gentium Book Basic';\n"
	"    font-size: 18px;\n"
	"    font-weight: normal;\n"
	"}\n"
	".code-greek {\n"
	"    padding-left: 10px;\n"
	"    padding-right: 10px;\n"
	"    font-family: 'Gentium Basic';\n"
	"    font-size: 20px;\n"
	"    height: 30px;\n"
	"}\n"
	".code-coptic {\n"
	"    padding-left: 10px;\n"
	"    padding-right: 10px;\n"
	"    font-family: 'Noto Sans Coptic';\n"
	"    font-size: 20px;\n"
	"    text-decoration: underline;\n"
	"    text-underline-offset: -18px;\n"
	"    height: 30px;\n"
	"}\n"
	"</style>\n"
        "</head>";

static const int greek[12] = {
	0x0391, // Greek capital letter Alpha
	0x0392, // Greek capital letter Beta
	0x039F, // Greek capital letter Omicron
	0x0394, // Greek capital letter Delta
	0x0395, // Greek capital letter Epsilon
	0x03A6, // Greek capital letter Phi
	0x0393, // Greek capital letter Gamma
	0x0397, // Greek capital letter Eta
	0x0399, // Greek capital letter Iota
	0x03A7, // Greek capital letter Chi
	0x039A, // Greek capital letter Kappa
	0x039B  // Greek capital letter Lambda
};

static const int coptic[12] = {
	0x2C80, // Coptic capital letter Alfa
	0x2C82, // Coptic capital letter Vida
	0x03E2, // Coptic capital letter Shei
	0x2C86, // Coptic capital letter Dalda
	0x2C88, // Coptic capital letter Eie
	0x03E4, // Coptic capital letter Fei
	0x2C84, // Coptic capital letter Gamma
	0x03E8, // Coptic capital letter Hori
	0x2C92, // Coptic capital letter Iauda
	0x03EA, // Coptic capital letter Gangia
	0x2C94, // Coptic capital letter Kapa
	0x2C96  // Coptic capital letter Laula
};

static void print_sequence(int section, int row, int column) {
	const int *alphabet;
	int sequence[4];
	int i;

	decode(sequence, section, row, column);

	if (section == 1 || section == 3) {
		alphabet = greek;
	} else {
		alphabet = coptic;
	}

	for (i = 0; i < 4; i++) {
		printf("&#x%04X;", alphabet[sequence[i]]);
	}
}

static void print_code_table(int section) {
	int i, j;
	const char *code_class;

	if (section < 4)
		printf("<table style=\"page-break-after: always;\">\n");
	else
		printf("<table>\n");

	printf("<caption>Section %d</caption>\n", section);
	printf("<tr style=\"text-align: center;\"><td></td>");

	for (i = 1; i <= 7; i++)
		printf("<th>%d</th>", i);

	printf("</tr>\n");

	if (section == 1 || section == 3)
		code_class = "code-greek";
	else
		code_class = "code-coptic";

	for (i = 1; i <= 26; i++) {
		printf("<tr><th>%c</th>", i + 'A' - 1);

		for (j = 1; j <= 7; j++) {
			printf("<td class=\"%s\">", code_class);
			print_sequence(section, i, j);
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

	for (i = 1; i <= 4; i++) {
		print_code_table(i);
	}

	printf("</body>\n");
	printf("</html>\n");

	return 0;
}
	
