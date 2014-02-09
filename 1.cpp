// Разверните строку. Указатель reverse_string должен 
// указывать на развернутую строку.
#include <cstring>
char* string = "The string!";

int main()
{
	char* reverse_string;
	int Len = strlen(string);
	reverse_string = new char[Len + 1];
	reverse_string[Len] = '\0'; // ending 0
	for(int beg = 0, end = Len - 1; beg <= end; beg++, end--)
	{
		reverse_string[beg] = string[end];
		reverse_string[end] = string[beg];
	}
	delete [] reverse_string;
	return 0;
}