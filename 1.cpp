#include <iostream>
#include <string>

char* string = "The string!";
int main()
{
	char* reverse_string = new char[strlen(string)];
	for(int i = 0 ; i < strlen(string); i++)
	{
		reverse_string[i] = string[strlen(string)-1 - i];
	}
	reverse_string[strlen(string)] = '\0';
	std::cout << reverse_string;
	system("pause");
	return 0;
}
