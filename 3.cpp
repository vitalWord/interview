// Напишите функцию Add(), которая создает новый 
// объект List, инициализирует его входным значением 
// value и добавляет его в конец списка l, полученного 
// на вход. В функции main() создайте проинициализированный 
// список, со значениями value равными: 1, 2, 3, 4 и 5.

struct List
{
      int value;
      List* next;
      ~List();
};

+List::~List() {
 +    if (this->next)
 +        delete this->next;
  }

// Add should create new List object, initialize it by value and add it to the end of the list.
// It should return pointer to the added List object.
List* Add(List* l, int value)
{
    List **p = &l;
    while (*p)
        p = &(*p)->next;
    *p = new List;
    (*p)->next = NULL;
    (*p)->value = value;

    return *p;
}

int main(int argc, char* argv[])
{
    List *begin = Add(NULL, 1);
    Add(Add(Add(Add(begin, 2), 3), 4), 5);
    
    delete begin;
    return 0;
}
