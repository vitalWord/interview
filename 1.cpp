// Разверните строку. Указатель reverse_string должен 
// указывать на развернутую строку.

char* string = "The string!";

int main()
{
	//для завдання нема потреба оформляти у вигляді функції
	int len = strlen(string);
	char* reverse_string = new char[len + 1];
	for (int i = 0; i < len; i++) {
		reverse_string[i] = string[len - i - 1];
	}
	reverse_string[len] = 0;
	//
	
	delete[] reverse_string;
	return 0;
}
