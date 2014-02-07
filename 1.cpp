// Разверните строку. Указатель reverse_string должен указывать на развернутую строку.

#include <cstring>

char* string = "The string!";
int main()
{

    size_t length = strlen(string);
	char* reverse_string = new char[length + 1];
	reverse_string[length] = '\0';

	for (size_t i=0; i < length; i++)
        reverse_string[i] = string[length-i-1];

	return 0;
}
