#include <stdio.h>
#include <string.h>

static const char* str = "The string!";

void strreverse_inplace(char * aStr);

#define swap_char(left, right) \
	do {                       \
		left = left ^ right;   \
		right = left ^ right;  \
		left = left ^ right;   \
	} while (0)

int main()
{
	char* reverse_string = strdup(str);
	printf("%s\n", str);
	strreverse(reverse_string);
	printf("%s\n", reverse_string);
	return 0;
}

void strreverse(char * p)
{
  char *q = p;
  q += strlen(p);
  for(--q; p < q; ++p, --q)
  	swap_char(*p, *q);
}
