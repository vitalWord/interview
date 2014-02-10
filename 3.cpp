// Напишите функцию Add(), которая создает новый 
// Напишите функцию Add(), которая создает новый объект List, инициализирует его входным значением value и добавляет его в конец списка l, полученного на вход. В функции main() создайте проинициализированный список, со значениями value равными: 1, 2, 3, 4 и 5.

struct List
{
      int value;
      List* next;
};

// Add should create new List object, initialize it by value and add it to the end of the list.
// It should return pointer to the added List object.
List* Add(List* l, int value)
{
	List *newList=new List;
	newList->value=value;
	newList->next=NULL;
	if(l)
	{
		
		l->next=newList;
		return (l);
	}
	else
	return(newList);
}

int main(int argc, char* argv[])
{
	List *_lst=new List;
	_lst->value=1;
	for(int i=1;i<5;i++)
		_lst=Add(_lst,i);
return 0;
}
