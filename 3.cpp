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
	List *list = new List;
	list->value = value;
	l->next = list;
	return list;
}

int main(int argc, char* argv[])
{
	List * list = new List;
	list->value = 1;
	for (int i = 1; i < 5; i++)
		Add(list,i+1);
	return 0;
}
