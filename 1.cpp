// Разверните строку. Указатель reverse_string должен 
// указывать на развернутую строку.

#include <cstring>

char* string = "The string!";

int main()
{
	char* reverse_string;
	size_t len = strlen(string);
	
	reverse_string = new char[len + 1];
	for (int i = 0; i < len; i++)
		reverse_string[i] = string[len - 1 - i];
	reverse_string[len] = '\0';
	
	// [...]
	
	delete [] reverse_string;
	return 0;
}
