#include <stdio.h>

int main()
{
	unsigned long i;
	unsigned int random;

	random = ((unsigned int)&i % 123) % 4;

	printf("ptr: %u\n",(unsigned int)(&i) );
	i = 0;
	printf("%u\n", random);
}