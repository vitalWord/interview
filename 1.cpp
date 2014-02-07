#include <iostream>
char* string="The string!";;
int main()
{
	char* reverse_string;
	reverse_string=new char[strlen(string)+1];
	int it(0);
	for (int i=strlen(string)-1;i>=0;i--)
	{
		reverse_string[it]=string[i];
		it++;
	}
	reverse_string[it]='\0';
	std::cout<<reverse_string<<std::endl;
	system("pause");
	return 0;
}
