// Разверните строку. Указатель reverse_string должен 
// указывать на развернутую строку.
#include <cstring>
char* string = "The string!";

int main()
{
    char* reverse_string;
    int Len = strlen(string);
    reverse_string = new char[Len + 1];
    char *start = string;
    char *end = start + Len; 
    char *start_rev = reverse_string;
    char *end_rev = start_rev + Len;
	*end_rev-- = *end--; // copy ending 0
    while (end >= start)
    {
    	// copy
    	*end_rev = *start;
    	*start_rev = *end;
    	// move
    	++start;
		++start_rev;
    	--end;
		--end_rev;
    }
	delete [] reverse_string;
	return 0;
}