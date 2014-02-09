// Разверните строку. Указатель reverse_string должен 
// указывать на развернутую строку.

#define USE_VERSION 1

static const char* str = "The string!";

#if (USE_VERSION == 1)

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void strreverse(char * aStr);

# define swap_char(left, right) { char _t = left; left = right; right = _t; }
	
# ifdef _MSC_VER
#  define strdup _strdup
# endif

int main()
{
    char* reverse_string = strdup(str); //strlen + alloc + memcpy

    strreverse(reverse_string);

    printf("%s\n", str);
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

#endif

#if (USE_VERSION == 2)

# include <iostream>
# include <algorithm>
    // std::reverse
# include <string>

int main () {
    std::string result(str);

    std::reverse(result.begin(), result.end());

    char* reverse_string = &result[0];

    std::cout << "Original: " << str << std::endl;
    std::cout << "Reversed: " << reverse_string << std::endl;

    return 0;
}

#endif
