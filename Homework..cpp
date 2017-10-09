

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void f(int n)
{
	if (n)
		f(n / 2);
	else
		return;
	printf("%d", n % 2);

}

int main(int argc, char **argv) {
	char c;
	char mindChar[100];
	int len, l, i, j;
	//只输入test.exe --help获取帮助
	if (argc == 2 && strcmp(argv[1], "--help") == 0) {
		printf("help message:\n\t-d Decimal table\n\t-o Octal table\n\t-x Hex table\n\t-b Binary table\n\t--d(o)(x)(b)  can printf more mode\n");
		return 0;
	}
	if (argc != 3) {
		printf("sorry arg error,--help for help\n");
		return 1;
	}
	else {
		// atoi是将数组转为int型变量
		l = atoi(argv[1]);
		if (strlen(argv[2])<2 || strlen(argv[2])>5) {
			printf("error: arg bad\n");
			return 1;
		}

		for (i = 1; i<strlen(argv[2]); i++) {
			c = argv[2][i];
			if (c == 'd') {
				// 将十进制转化为十进制
				printf("Decimal table: %d\n", l);
				continue;
			}
			if (c == 'x') {
				// 将十进制转化为十六进制
				printf("Hex table: %x\n", l);
				continue;
			}
			if (c == 'b') {
				// 将十进制转化为二进制
				// itoa(l,mindChar,2);
				printf("Binary table: ");
				f(l);
				printf("\n");
				continue;
			}
			if (c == 'o') {
				// 将十进制转化为八进制
				printf("Octal table: %o\n", l);
				continue;
			}
			printf("errr: unKnow args\n");

			return 1;
		}
		return 0;
	}

}

