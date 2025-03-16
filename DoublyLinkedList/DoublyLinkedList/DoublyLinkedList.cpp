
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;
int main()
{
    DoublyLinkedList* dll = new DoublyLinkedList(10);
    dll->append(2);
    dll->append(6);
    dll->append(5);
    dll->swapPairs();
    dll->printList();
}

