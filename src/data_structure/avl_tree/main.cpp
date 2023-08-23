#include <avl_tree.h>

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
