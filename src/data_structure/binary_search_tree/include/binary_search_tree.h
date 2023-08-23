#include <format>
#include <functional>
#include <iostream>
#include <utility>

using namespace std;

template <typename T>
class Node {
 public:
  int key;
  T value;
  Node* left;
  Node* right;

  explicit Node(int key, T value, Node* left = nullptr, Node* right = nullptr)
      : key{key}, value{std::move(value)}, left{left}, right{right} {}
};

template <typename T>
class BinarySearchTree {
 public:
  Node<T>* root;

  BinarySearchTree() = default;

  bool isEmpty();

  void insert(int key, T value);

  void remove(int key);

  Node<T>* search(int key);

  void print(bool showValue = false);

  void traversePreOrder(function<void(Node<T>*)> func);

  void traverseInOrder(function<void(Node<T>*)> func);

  void traversePostOrder(function<void(Node<T>*)> func);

 private:
  Node<T>* insertNode(Node<T>* curr, int key, T value);

  Node<T>* removeNode(Node<T>* curr, int key);

  Node<T>* searchNode(Node<T>* curr, int key);

  void print(const string& prefix, const Node<T>* node, bool isLeft,
             bool showValue);
};

template <typename T>
bool BinarySearchTree<T>::isEmpty() {
  return root == nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(int key, T value) {
  if (this->isEmpty()) {
    this->root = new Node(key, value);
  }

  this->insertNode(this->root, key, value);
}

template <typename T>
Node<T>* BinarySearchTree<T>::insertNode(Node<T>* curr, int key, T value) {
  if (curr == nullptr) {
    auto* node = new Node(key, value);
    return node;
  }

  if (key < curr->key) {
    curr->left = this->insertNode(curr->left, key, value);
  } else if (key > curr->key) {
    curr->right = this->insertNode(curr->right, key, value);
  }

  return curr;
}

template <typename T>
void BinarySearchTree<T>::remove(int key) {
  if (this->isEmpty()) {
    throw runtime_error("empty tree");
  }

  this->removeNode(this->root, key);
}

template <typename T>
Node<T>* BinarySearchTree<T>::removeNode(Node<T>* curr, int key) {
  if (key < curr->key) {
    curr->left = this->removeNode(curr->left, key);
  } else if (key > curr->key) {
    curr->right = this->removeNode(curr->right, key);
  } else {
    // If node have single children
    if (curr->left == nullptr) {
      Node<T>* successor = curr->right;
      delete curr;
      return successor;
    } else if (curr->right == nullptr) {
      Node<T>* successor = curr->left;
      delete curr;
      return successor;
    }

    // If node have two children
    Node<T>* successor = curr->right;

    // Get the inorder successor of that node
    while (successor && successor->left != NULL)
      successor = successor->left;

    cout << successor->key << endl;

    // Replace key and value with the successor
    curr->key = successor->key;
    curr->value = successor->value;

    // Delete the successor
    curr->right = this->removeNode(curr->right, successor->key);
  }

  return curr;
}

template <typename T>
Node<T>* BinarySearchTree<T>::search(int key) {
  if (this->isEmpty()) {
    throw runtime_error("empty tree");
  }

  return this->searchNode(this->root, key);
}

template <typename T>
Node<T>* BinarySearchTree<T>::searchNode(Node<T>* curr, int key) {
  if (curr == nullptr) {
    return nullptr;
  }

  if (key < curr->key) {
    return this->searchNode(curr->left, key);
  } else if (key > curr->key) {
    return this->searchNode(curr->right, key);
  } else {
    return curr;
  }
}

template <typename T>
void BinarySearchTree<T>::print(bool showValue) {
  cout << "Tree:" << endl;
  if (this->isEmpty())
    cout << "Tree Empty" << endl;
  else
    print("", this->root, false, showValue);
}

template <typename T>
void BinarySearchTree<T>::print(const string& prefix, const Node<T>* node,
                                bool isLeft, bool showValue) {
  if (this->root != node) {
    cout << prefix;
    cout << (isLeft ? "L ├──" : "R └──");
  } else {
    cout << "     ";
  }

  if (node != nullptr) {
    cout << (showValue ? format(" {} ({})", node->key, node->value)
                       : format(" {}", node->key))
         << endl;

    print(prefix + (isLeft ? "  │   " : "      "), node->left, true, showValue);
    print(prefix + (isLeft ? "  │   " : "      "), node->right, false,
          showValue);
  } else {
    cout << " NULL" << endl;
  }
}
