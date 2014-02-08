#include <iostream>

char* string = "The string!";
int main()
{
	int len = strlen(string);
	char* reverse_string = new char[len];
	for(int i = 0 ; i < len; i++)
	{
		reverse_string[i] = string[len-1 - i];
	}
	reverse_string[len] = '\0';
	std::cout << reverse_string;
	system("pause");
	return 0;
}
