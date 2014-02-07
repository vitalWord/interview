#include <string.h>

char* string = "The string!";
int main()
{
	char* reverse_string;
	int len = strlen(string);
	reverse_string = new char[strlen(string)+1];

	for(int i = len-1; i > -1; i--)
	{
		reverse_string[i] = string[len-i-1];
	}
	reverse_string[len] = '\0';

	return 0;
}