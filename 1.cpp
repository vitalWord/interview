// Разверните строку. Указатель reverse_string должен 
// указывать на развернутую строку.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char* str = "The string!";

void strreverse(char * aStr);

#define swap_char(left, right) \
	do {                       \
		left = left ^ right;   \
		right = left ^ right;  \
		left = left ^ right;   \
	} while (0)
	
#ifdef _MSC_VER
# define strdup _strdup
#endif

int main()
{
	char* reverse_string = strdup(str); //strlen + alloc + memcpy
	printf("%s\n", str);
	strreverse(reverse_string);
	printf("%s\n", reverse_string);

	free(reverse_string);
	
	return 0;
}

void strreverse(char * p)
{
  char *q = p + strlen(p);
  for(--q; p < q; ++p, --q)
  	swap_char(*p, *q);
}
