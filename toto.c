#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <wchar.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	int a;
//	unsigned char c;
//    c = 0xe1;
//    write(1, &c, 1);
//    c = 0x88;
//    write(1, &c, 1);
//    c = 0xb4;
//    write(1, &c, 1);
 //	c = 0x0a;
//	write(1, &c, 1);
//	printf("\n%C\n", (wint_t)'Ș');
	a = printf("[%06.5C]", (wchar_t)0X60);
	printf("[%06.5S]", (wchar_t*)"  [좘]");
	printf("%0-12d", a);
	printf("\\\n");
	printf("\"\'\n");
	printf("%-0 12.14d\n", 42);
	printf("%-0 10.9d\n", 42424242);
	return(0);
}
