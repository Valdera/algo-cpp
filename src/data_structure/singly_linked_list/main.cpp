#include <singly_linked_list.h>
#include <iostream>

using namespace std;

int main() {

  Node node("hello");
  cout << node.value << endl;

  LinkedList<int> list{};
  cout << list.isEmpty() << endl;

  list.insertLast(1);
  list.insertLast(2);
  list.insertFirst(3);
  list.insertLast(4);

  list.insertAt(10, 1);

  list.print();

  cout << list.deleteFirst() << endl;
  list.print();

  cout << list.deleteLast() << endl;
  list.print();

  cout << list.deleteAt(1) << endl;
  list.print();

  cout << list.contains(2) << endl;

  cout << list.getMiddleValue() << endl;

  list.insertAt(90, 1);
  list.print();

  cout << list.getMiddleValue() << endl;

  list.insertAt(3, 1);
  list.print();

  cout << list.getMiddleValue() << endl;

  list.print();
  list.reverse();
  list.print();
}
