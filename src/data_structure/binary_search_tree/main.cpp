#include <binary_search_tree.h>

int main() {
  auto* tree = new BinarySearchTree<string>();

  tree->insert(50, "value-30");
  tree->insert(10, "value-50");
  tree->insert(20, "value-20");
  tree->insert(42, "value-42");
  tree->insert(60, "value-46");
  tree->insert(55, "value-46");
  tree->insert(15, "value-46");
  tree->insert(33, "value-46");
  tree->insert(44, "value-46");

  tree->remove(60);
  tree->remove(20);
  tree->remove(55);
  tree->remove(44);

  tree->print();
  Node<string>* node = tree->search(15);
  cout << node->key << " : " << node->value << endl;
}
