#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <wchar.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <locale.h>
#include <limits.h>

int main()
{
	setlocale(LC_ALL, "");
	int a;
	a = printf("\nprintf %+f\n", 42);
	ft_putnbr(a);
	a = ft_printf("\nft_pri %+f\n", 42);
	ft_putnbr(a);
	a = printf("\nprintf %f\n", 42);
	ft_putnbr(a);
	a = ft_printf("\nft_pri %f\n", 42);
	ft_putnbr(a);
	a = printf("\nprintf % f\n", 42);
	ft_putnbr(a);
	a = ft_printf("\nft_pri % f\n", 42);
	ft_putnbr(a);
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
//	ft_printf("%", "test");
	/*
	ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
	printf("@main_ftprintf: %033.6.12.5d\n", 256);
	ft_printf("@main_ftprintf: %10d\n", 256);
	ft_printf("%p\n", 0);
	printf("ori %s\n", "toto");
	ft_printf("me  %s\n", "toto");
	ft_printf("\n\n\n");
	a = printf("ori %S\n", L"Á±≥trtrtr");
	ft_putnbr(a);
	a = ft_printf("me  %S\n", L"Á±≥trtrtr");
	ft_putnbr(a);

	a = printf("toto %.4S  \n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_putnbr(a);
	a = ft_printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_putnbr(a);
	a = ft_printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_putnbr(a);
	ft_printf("\n\ntotototo\n");
	
	a = printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\n\ntotototo  %d\n", a);
	a = ft_printf("%.4S ", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\n\ntotototo  %d\n", a);
	a = printf("[%.0p, %.p]\n", &a, &a);
	ft_putnbr(a);
	a = ft_printf("[%.0p, %.p]\n", &a, &a);
	ft_putnbr(a);

	a = printf("\nprintf %+i\n", 42);
	ft_putnbr(a);
	a = ft_printf("\nft_pri %+i\n", 42);
	ft_putnbr(a);
	a = printf("\nprintf %+d\n", 42);
	ft_putnbr(a);
	a = ft_printf("\nft_pri %+d\n", 42);
	ft_putnbr(a);
	a = printf("\nprintf %+D\n", 42);
	ft_putnbr(a);
	a = ft_printf("\nft_pri %+D\n", 42);
	ft_putnbr(a);

	a = printf("\nprintf %#o\n", 0);
	ft_putnbr(a);
	a = printf("\nft_pri %#o\n", 0);
	ft_putnbr(a);*/
/*	printf("@moulitest: %s\n", NULL);
	printf("@moulitest: %s\n", "");
	ft_printf("@moulitest: %s\n", NULL);
	ft_printf("@moulitest: %s\n", "");
	printf("%d\n", INT_MIN);
	printf("%d\n", INT_MAX);
//	printf("%u\n", UINT_MIN);
	printf("%u\n", UINT_MAX);
	printf("%ld\n", LONG_MIN);
	printf("%ld\n", LONG_MAX);
	printf("%lld\n", LLONG_MIN);
	printf("%lld\n", LLONG_MAX);
	printf("@moulitest: [%05.o %05.0o]\n", 0, 0);
	printf("@moulitest: [%#0.o %#0.0o]\n", 0, 0);
	printf("@moulitest: [%#05.o %#05.0o]\n", 0, 0);
	printf("@moulitest: [%05.x %05.0x]\n", 0, 0);
	printf("@moulitest: [%0#.x %0#.0x]\n", 0, 0);
	printf("@moulitest: [%0#5.x %0#5.0x]\n", 0, 0);
	printf("@moulitest: [%05.u %05.0u]\n", 0, 0);
	printf("@moulitest: [%0#.u %0#.0u]\n", 0, 0);
	printf("@moulitest: [%0#5.u %0#5.0u]\n", 0, 0);


	ft_printf("[%5.o %5.0o]\n", 0, 0);
	ft_printf("[%#.o %#.0o]\n", 0, 0);
	ft_printf("[%#5.o %#5.0o]\n", 0, 0);
	ft_printf("[%5.x %5.0x]\n", 0, 0);
	ft_printf("[%#.x %#.0x]\n", 0, 0);
	ft_printf("[%#5.x %#5.0x]\n", 0, 0);
	ft_printf("[%5.u %5.0u]\n", 0, 0);
	ft_printf("[%#.u %#.0u]\n", 0, 0);
	ft_printf("[%#5.u %#5.0u]\n", 0, 0);
	ft_printf("[%lld]\n", 42);
	ft_printf("[%   %]\n", "test");
	ft_printf("[%x]\n", -42);
	ft_printf("[%010x]\n", 542);
	ft_printf("[%#8x]", 42);
	ft_printf("[%#08x]", 42);
	a = printf("[%06.5C]", (wchar_t)0X60);
	printf("[%06.5S]", (wchar_t*)"  [좘]");
	printf("%0-12d", a);
	printf("%+D\n", 123456789999L);
	printf("\"\'\n");
	printf("%-0 12.14d\n", 42);
	printf("%-0 10.9d\n", 42424242);*/
	return(0);
}



//int main (void)
//{
//	int a;
//	char *str = "toto d";
//	ft_printf("\"\t%0#24O\n", 1567567);
//	a = printf("\"\t%0#24lo\n", 1567567L);
//	printf("a = %d\n", a);
//	ft_printf("a = %d\n", a);
//	printf("a = \"%24.10d\"\n", -42);
//	ft_printf("a = \"%24.10d\"\n", -42);
//	printf("%+d\n", -34);
//	ft_printf("%+d\n", -34);
//	printf("%+d et %#o\n", -34, 89);
//	ft_printf("%+d et %#o\n", -34, 89);
//	printf("%-+itoto\n", -25);
//	ft_printf("%-+itoto\n", -25);
//	printf("%itoto\n", -36);
//	ft_printf("%itoto\n", -36);
//	printf("%d\n", 36);
//	ft_printf("%d\n", 36);
/*	a = printf("%12d\n", 356489);
	ft_putnbr(a);
	a = ft_printf("%12d\n", 356489);
	ft_putnbr(a);
	a = printf("%12k\n", -356489);
	ft_putnbr(a);
	a = ft_printf("%12k\n", -356489);
	ft_putnbr(a);

	a = printf("\ntoto[%-4 d]\n", 123456);
	ft_putnbr(a);
	a = printf("\ntoto[%-12.14 d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[%-12.14d]\n", -15);
	ft_putnbr(a);
	a = printf("\ntoto[%-12.14d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[%+12.14 d]\n", -15);
	ft_putnbr(a);
	a = printf("\ntoto[%12 d]\n", -15);
	ft_putnbr(a);
	a = printf("\ntoto[%012 d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[% #.8x]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[%012d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[%- d]\n", 15);
	ft_putnbr(a);
	a = printf("\ntoto[% d]\n", 15);

	ft_putnbr(a);
	a = ft_printf("\ntoto[%-4 d]\n", 123456);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%-12.14 d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%-12.14d]\n", -15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%-12.14d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%+12.14 d]\n", -15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%12 d]\n", -15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%012 d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[% #.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%012d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[%- d]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\ntoto[% d]\n", 15);
*/
//	setlocale(LC_ALL, "");
//	a = printf("\ntoto[%.0#x]\n", 3);
//	ft_putnbr(a);
//
//	a = ft_printf("\ntoto[%.0#x]\n", 3);
//		ft_putnbr(a);
//
/*  a = printf("[%12o]\n", 356489);
	ft_putnbr(a);
	a = printf("[%12lo]\n", 356489);
	ft_putnbr(a);
	a = printf("[%12x]\n", 356489);
	ft_putnbr(a);
	a = printf("[%12X]\n", 356489);
	ft_putnbr(a);
	a = printf("\n[%-4 x]\n", 123456);
	ft_putnbr(a);
//	a = printf("\n[%-12.14 X]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%-12.14X]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%-12.14x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%+12.14 x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%12 x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%012 x]\n", 15);
	ft_putnbr(a);
//	a = printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%012x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[%- x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% x]\n", 15);
	ft_putnbr(a);

	a = ft_printf("[%12o]\n", 356489);
	ft_putnbr(a);
	a = ft_printf("[%12O]\n", 356489);
	ft_putnbr(a);
	a = ft_printf("[%12x]\n", 356489);
	ft_putnbr(a);
	a = ft_printf("[%12X]\n", 356489);
	ft_putnbr(a);
	a = ft_printf("\n[%-4 x]\n", 123456);
	ft_putnbr(a);
	a = ft_printf("\n[%-12.14 X]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%-12.14X]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%-12.14x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%+12.14 x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%12 x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%012 x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%012x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%- x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% x]\n", 15);


	printf("\n\n\n\n");
	a = printf("\n[%#.8x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% #.1x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% #.1x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% .8x]\n", 15);
	ft_putnbr(a);
	a = printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[%#.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.1x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.1x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% .8x]\n", 15);
	ft_putnbr(a);
	a = ft_printf("\n[% #.8x]\n", 15);
	ft_putnbr(a);
*/
//	printf("%s\n", "356489");
//	ft_printf("%s\n", "356489");
//	ft_printf("%O\n", 1567567);
//	ft_printf("%u\n", 1567567);
//	ft_printf("%U\n", 1567567);
//	ft_printf("%x\n", 1567567);
//	ft_printf("%X\n", 1567567);
//	ft_printf("%p\n", &a);
//	printf("%%%% toto");
//	return (0);
//}