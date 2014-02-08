// Напишите функцию Add(), которая создает новый 
// объект List, инициализирует его входным значением 
// value и добавляет его в конец списка l, полученного 
// на вход. В функции main() создайте проинициализированный 
// список, со значениями value равными: 1, 2, 3, 4 и 5.

#define     NULL  0

struct List
{
      int value;
      List* next;
      ~List(void);
};

// Add should create new List object, initialize it by value and add it to the end of the list.
// It should return pointer to the added List object.
List* Add(List* l, int value)
{
      List* new_item = new List;
      new_item->value = value;
      new_item->next = NULL;
      
      if (l) {
            List* temp = beg;
            while (temp->next)
                  temp = temp->next;
            temp->next = new_item;
      }
      
      return new_item;
}

List::~List(void) {
      if (this->next)
            delete this->next;
      
}

int main(int argc, char* argv[])
{
      List* begin = NULL;
      begin = Add(begin, 1);
      Add(begin, 2);
      Add(begin, 3);
      Add(begin, 4);
      Add(begin, 5);
      
      // [...]
      
      delete begin;
      
      return 0;
}
