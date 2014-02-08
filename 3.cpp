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
	List*new_lst = new List{value,0};
	if(l) {
		for (;(l->next != 0); l = l->next){}
		l->next = new_lst;
	}
	return new_lst;
}

int main(int argc, char* argv[])
{
	List*l = Add(0, 1);
	for (int i = 2; i <= 5; i++) {
		Add(l, i);
	}
	return 0;
}
