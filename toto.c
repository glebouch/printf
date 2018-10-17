#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int main()
{
	int i;
	int	j;

	i = printf("%-12.10d\n", 42);
	printf(" i = [%d]\n", i);
	//printf("%- 12.10d\n", 42);
	//printf("%-0 12.10d\n", 42);
	//printf("%-0 12d\n", 42);
	printf("%-0 12.14d\n", 42);
	printf("%-0 10.9d\n", 42424242);
	return(0);
}
