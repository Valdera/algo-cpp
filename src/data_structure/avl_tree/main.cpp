#include <format>
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
  int height;

  explicit Node(int key, T value, Node* left = nullptr, Node* right = nullptr,
                int height = 1)
      : key{key},
        value{std::move(value)},
        left{left},
        right{right},
        height{height} {}

  void updateHeight();
};

template <typename T>
void Node<T>::updateHeight() {
  int left_height = this->left ? this->left->height : 0;
  int right_height = this->right ? this->right->height : 0;

  this->height = max(left_height, right_height) + 1;
}

template <typename T>
class AVLTree {
 public:
  Node<T>* root;

  AVLTree() = default;

  bool isEmpty();

  void insert(int key, T value);

  void print(bool showValue = false);

 private:
  int balanceFactor(const Node<T>* node);

  Node<T>* insertNode(Node<T>* curr, int key, T value);

  Node<T>* llRotate(Node<T>* curr);

  Node<T>* rrRotate(Node<T>* curr);

  Node<T>* lrRotate(Node<T>* curr);

  Node<T>* rlRotate(Node<T>* curr);

  void print(const string& prefix, const Node<T>* node, bool isLeft,
             bool showValue);
};

template <typename T>
bool AVLTree<T>::isEmpty() {
  return root == nullptr;
}

template <typename T>
void AVLTree<T>::insert(int key, T value) {
  if (this->isEmpty()) {
    this->root = new Node(key, value);
  }

  this->insertNode(this->root, key, value);
}

template <typename T>
int AVLTree<T>::balanceFactor(const Node<T>* node) {
  if (!node) {
    return 0;
  }

  int left_height = node->left ? node->left->height : 0;
  int right_height = node->right ? node->right->height : 0;

  return left_height - right_height;
}

template <typename T>
Node<T>* AVLTree<T>::insertNode(Node<T>* curr, int key, T value) {
  if (curr == nullptr) {
    auto* node = new Node(key, value);
    return node;
  }

  if (key < curr->key) {
    curr->left = this->insertNode(curr->left, key, value);
  } else if (key > curr->key) {
    curr->right = this->insertNode(curr->right, key, value);
  }

  curr->updateHeight();

  if (balanceFactor(curr) == 2 && balanceFactor(curr->left) == 1)
    return this->llRotate(curr);
  else if (balanceFactor(curr) == 2 && balanceFactor(curr->left) == -1)
    return this->lrRotate(curr);
  else if (balanceFactor(curr) == -2 && balanceFactor(curr->right) == -1)
    return this->rrRotate(curr);
  else if (balanceFactor(curr) == -2 && balanceFactor(curr->right) == 1)
    return this->rlRotate(curr);

  return curr;
}

template <typename T>
Node<T>* AVLTree<T>::llRotate(Node<T>* c) {
  Node<T>* cl = c->left;
  Node<T>* clr = c->left->right;

  cl->right = c;
  c->left = clr;

  c->updateHeight();
  cl->updateHeight();

  if (this->root == c)
    this->root = cl;

  return cl;
}

template <typename T>
Node<T>* AVLTree<T>::rrRotate(Node<T>* c) {
  Node<T>* cr = c->right;
  Node<T>* crl = c->right->left;

  cr->left = c;
  c->right = crl;

  c->updateHeight();
  cr->updateHeight();

  if (this->root == c)
    this->root = cr;

  return cr;
}

template <typename T>
Node<T>* AVLTree<T>::lrRotate(Node<T>* c) {
  Node<T>* cl = c->left;
  Node<T>* clr = c->left->right;

  cl->right = clr->left;
  c->left = clr->right;

  clr->left = cl;
  clr->right = c;

  cl->updateHeight();
  c->updateHeight();
  clr->updateHeight();

  if (this->root == c)
    this->root = clr;

  return clr;
}

template <typename T>
Node<T>* AVLTree<T>::rlRotate(Node<T>* c) {
  Node<T>* cr = c->right;
  Node<T>* crl = c->right->left;

  cr->left = crl->right;
  c->right = crl->left;

  crl->right = cr;
  crl->left = c;

  cr->updateHeight();
  c->updateHeight();
  crl->updateHeight();

  if (this->root == c)
    this->root = crl;

  return crl;
}

template <typename T>
void AVLTree<T>::print(bool showValue) {
  cout << "Tree:" << endl;
  if (this->isEmpty())
    cout << "Tree Empty" << endl;
  else
    print("", this->root, false, showValue);
}

template <typename T>
void AVLTree<T>::print(const string& prefix, const Node<T>* node, bool isLeft,
                       bool showValue) {
  if (this->root != node) {
    cout << prefix;
    cout << (isLeft ? "L ├──" : "R └──");
  } else {
    cout << "     ";
  }

  if (node != nullptr) {
    cout << (showValue ? format(" {} ({})", node->key, node->value)
                       : format(" {} - bl: {}", node->key, balanceFactor(node)))
         << endl;

    print(prefix + (isLeft ? "  │   " : "      "), node->left, true, showValue);
    print(prefix + (isLeft ? "  │   " : "      "), node->right, false,
          showValue);
  } else {
    cout << " NULL" << endl;
  }
}

int main() {
  auto* tree = new AVLTree<string>();

  tree->insert(50, "value-30");
  tree->insert(10, "value-50");
  tree->insert(20, "value-20");
  tree->insert(10, "value-10");
  tree->insert(42, "value-42");
  tree->insert(46, "value-46");
  tree->print();
}
