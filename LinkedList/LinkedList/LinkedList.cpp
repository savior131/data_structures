#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
int main()
{
   /* LinkedList linkedList(1);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(4);
    linkedList.append(5);
    linkedList.append(6);
    linkedList.append(7);
    linkedList.append(8);
    linkedList.reverseBetween(2, 5);
    linkedList.printList();*/
    Queue queue(2);
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(3);
    queue.dequeue();
    queue.enqueue(15);
    queue.printQueue();

}
