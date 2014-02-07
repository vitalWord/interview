#include <string.h>
#include <iostream>

char * reverse(char * s)
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++)
	{
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
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
