// Напишите функцию Add(), которая создает новый 
// объект List, инициализирует его входным значением 
// value и добавляет его в конец списка l, полученного 
// на вход. В функции main() создайте проинициализированный 
// список, со значениями value равными: 1, 2, 3, 4 и 5.

struct List
{
      int value;
      List* next;
};

// Add should create new List object, initialize it by value and add it to the end of the list.
// It should return pointer to the added List object.
List* Add(List* l, int value)
{
	List * new_last = new List();
	new_last->next = nullptr;
	new_last->value = value;
	if(!l) // if empty
		return new_last;
	while(l->next) // find the last element
		l = l->next;
	l->next = new_last;
	return new_last;
}

void FreeList(List* head)
{
	if(!head)
		return;
	FreeList(head->next);
	delete head;
	head = nullptr;
}
int main(int argc, char* argv[])
{
	const int N = 6;
	List * l = Add(nullptr, 1);
	for(int i = 2; i < N; i++)
	{
		Add(l, i);
	}
	FreeList(l);

return 0;
}