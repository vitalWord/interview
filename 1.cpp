// Разверните строку. Указатель reverse_string должен 
// указывать на развернутую строку.

char* string = “The string!”;

int main()
{
	char* reverse_string;
	int sz = strlen(string);
	reverse_string= new char[sz+1];
	for(int i=0; i<sz;i++)
		reverse_string[i]=string[sz-1-i];
	reverse_string[sz]='\0';
	std::cout << reverse_string;
	return 0;
}
