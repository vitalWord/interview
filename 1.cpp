#include <string.h>
#include <iostream>

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

	std::cout << reverse_string << std::endl;

	delete [] reverse_string;
	reverse_string = nullptr;
	
	return 0;
}