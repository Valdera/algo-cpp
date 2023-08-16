#pragma once
#include <format>
#include <iostream>

using namespace std;

template <typename T>
class Node {
 public:
  T value;
  Node* next;

  explicit Node(T value = 0, Node* next = nullptr) : value{value}, next{next} {}
};

template <typename T>
class LinkedList {
 public:
  Node<T>* head{nullptr};
  Node<T>* tail{nullptr};
  int size{0};

  explicit LinkedList() = default;

  /**
   * Check if linked list is empty or not O(1)
   *
   * @return `true` if list is empty, otherwise `false`
   */
  bool isEmpty();

  /**
   * Print linked list to display output O(N)
   */
  void print();

  /**
   * Insert node at the beginning of the linked list O(1)
   *
   * @param value value of the node
   */
  void insertFirst(T value);

  /**
   * Insert node at the tail of the linked list O(1)
   *
   * @param value value of the node
   */
  void insertLast(T value);

  /**
   * Insert node at a specified index of the linked list O(N)
   *
   * @param value value of the node
   * @param index specified index
   */
  void insertAt(T value, int index);

  /**
   * Delete node at the beginning of the linked list O(1)
   *
   * @return value of the deleted node
   */
  T deleteFirst();

  /**
   * Delete node at the tail of the linked list O(N)
   *
   * @return value of the deleted node
   */
  T deleteLast();

  /**
   * Delete node at a specified index of the linked list O(N)
   *
   * @param index specified index
   * @return value of the deleted node
   */
  T deleteAt(int index);

  /**
   * Check if linked list contains node with specified value O(N)
   *
   * @param value value of the node
   * @return `true` if node with the given value present, otherwise `false`
   */
  bool contains(T value);

  /**
   * Get the index of the node with specified value O(N)
   *
   * @param value value of the node
   * @return the index of node with specified value. If node doesn't exists will return -1
   */
  int indexOf(T value);

  /**
   * Get the value of the middle index node in the linked list
   *
   * @return value of the middle node
   */
  T getMiddleValue();

  /**
   * Reverse the linked list
   */
  void reverse();

 private:
  /**
   * Get the middle index node in the linked list
   *
   * @return middle node
   */
  Node<T>* getMiddle();
};

template <typename T>
bool LinkedList<T>::isEmpty() {
  return this->size == 0;
}

template <typename T>
void LinkedList<T>::print() {
  if (this->isEmpty()) {
    cout << "List Empty" << endl;
    return;
  }

  Node<T>* curr = this->head;

  while (curr != nullptr) {
    cout << curr->value << " -> ";
    curr = curr->next;
  }
  cout << "NULL" << endl;
}

template <typename T>
void LinkedList<T>::insertFirst(T value) {
  auto* node = new Node(value);

  if (this->isEmpty()) {
    this->head = this->tail = node;
  } else {
    node->next = this->head;
    this->head = node;
  }

  this->size++;
}

template <typename T>
void LinkedList<T>::insertLast(T value) {
  auto* node = new Node(value);

  if (this->isEmpty()) {
    this->head = this->tail = node;
  } else {
    this->tail->next = node;
    this->tail = this->tail->next;
  }

  this->size++;
}

template <typename T>
void LinkedList<T>::insertAt(T value, int index) {
  if (index < 0 && index > this->size) {
    throw out_of_range(format("index {} out of range", index));
  }

  if (index == 0)
    return this->insertFirst(value);

  if (index == size)
    return this->insertLast(value);

  auto* node = new Node(value);

  Node<T>* prev = this->head;
  for (int i = 0; i < index - 1; ++i) {
    prev = prev->next;
  }

  Node<T>* temp = prev->next;
  prev->next = node;
  node->next = temp;

  this->size++;
}

template <typename T>
T LinkedList<T>::deleteFirst() {
  if (this->isEmpty()) {
    throw runtime_error("empty list");
  }

  Node<T>* temp = this->head;
  T value = temp->value;

  this->head = this->head->next;

  if (this->isEmpty()) {
    this->tail = nullptr;
  }

  delete temp;
  this->size--;
  return value;
}

template <typename T>
T LinkedList<T>::deleteLast() {
  if (this->isEmpty()) {
    throw runtime_error("empty list");
  }

  Node<T>* temp = this->tail;
  T value = temp->value;

  if (this->size == 1) {
    this->tail = nullptr;
    this->head = nullptr;
  } else {
    Node<T>* prev = this->head;
    while (prev->next != this->tail) {
      prev = prev->next;
    }

    prev->next = nullptr;
    this->tail = prev;
  }

  delete temp;
  this->size--;
  return value;
}

template <typename T>
T LinkedList<T>::deleteAt(int index) {
  if (index < 0 && index > this->size) {
    throw out_of_range(format("index {} out of range", index));
  }

  if (index == 0)
    return this->deleteFirst();
  if (index == size)
    return this->deleteLast();

  Node<T>* prev = this->head;
  for (int i = 0; i < index - 1; ++i) {
    prev = prev->next;
  }

  Node<T>* temp = prev->next;
  T value = temp->value;

  prev->next = prev->next->next;

  delete temp;
  this->size--;
  return value;
}

template <typename T>
bool LinkedList<T>::contains(T value) {
  Node<T>* curr = this->head;
  while (curr) {
    if (curr->value == value)
      return true;
    curr = curr->next;
  }
  return false;
}

template <typename T>
int LinkedList<T>::indexOf(T value) {
  Node<T>* curr = this->head;
  int i = 0;
  while (curr) {
    if (curr->value == value)
      return i;
    curr = curr->next;
    i++;
  }

  return -1;
}

template <typename T>
Node<T>* LinkedList<T>::getMiddle() {
  if (isEmpty()) {
    throw runtime_error("list empty");
  }

  Node<T>* slow = this->head;
  Node<T>* fast = this->head->next;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Even
  if (fast)
    return slow->next;
  // Odd
  else
    return slow;
}

template <typename T>
T LinkedList<T>::getMiddleValue() {
  return this->getMiddle()->value;
}

template <typename T>
void LinkedList<T>::reverse() {
  Node<T>* curr = this->head;
  Node<T>* prev = nullptr;

  this->tail = this->head;

  while (curr) {
    Node<T>* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  this->head = prev;
}
