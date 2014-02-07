#include <string.h>
#include <iostream>

char * reverse(char * s)
{
	int length = strlen(s);
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	return s;
}

char * string = "The string!";

int main()
{
	char* reverse_string = new char [strlen(string) + 1];
	strcpy(reverse_string, string);
	reverse_string = reverse(reverse_string);
	std::cout << reverse_string << std::endl;
	return 0;
}
