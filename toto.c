#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int main()
{
	int i;

	i = printf("\ntoto\n");
	printf("\ttoto\n");
	printf("\rtoto\n");
	printf("\\\n");
	printf("\"\'\%\o\n");
	printf("%-0 12.14d\n", 42);
	printf("%-0 10.9d\n", 42424242);
	return(0);
}
