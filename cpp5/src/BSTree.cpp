#include "../include/BSTree.h"
#include <algorithm>
#include <iostream>
#include <utility>

void BSTree::clearElements(Node* root) {
  if (!root) {
    return;
  }
  clearElements(root->left_);
  clearElements(root->right_);
  delete root;
}

std::ostream& operator<<(std::ostream& os, const BSTree& tree) {
  if (!tree.root_) {
    os << "Tree is empty!";
    return os;
  }
  if (tree.root_->left_ != nullptr) {
    os << tree.root_->left_;
  }
  os << "< " << tree.root_->data_ << " > ";
  if (tree.root_->right_ != nullptr) {
    os << tree.root_->right_;
  }
  return os;
}

Node* BSTree::findNode(const Node* root, const int& x) {
  Node* rt = const_cast<Node*>(root);
  while (rt) {
    if (x < rt->data_) {
      rt = rt->left_;
    } else if (x > rt->data_) {
      rt = rt->right_;
    } else {
      return rt;
    }
  }
  return nullptr;
}

Node* BSTree::findNodeRec(const Node* root, const int& x) {
  if (!root) {
    return nullptr;
  }
  if (x < root->data_) {
    return findNodeRec(root->left_, x);
  }
  if (x > root->data_) {
    return findNodeRec(root->right_, x);
  }
  return const_cast<Node*>(root);
}

bool BSTree::insertNode(Node*& root, const int& x) {
  if (!root) {
    root = new Node(x);
    return true;
  }
  if (x < root->data_) {
    return insertNode(root->left_, x);
  }
  if (x > root->data_) {
    return insertNode(root->right_, x);
  }
  return false;
}

Node* BSTree::copyTree(const Node* root) {
  if (!root) {
    return nullptr;
  }
  Node* copy = new Node(root->data_);
  copy->left_ = copyTree(root->left_);
  copy->right_ = copyTree(root->right_);
  return copy;
}

int BSTree::getEvenCountRec(const Node* root) {
  int result = 0;
  if (!root) {
    return result;
  }
  if (root->data_ % 2 == 0) {
    result = 1;
  }
  return result + getEvenCountRec(root->left_) + getEvenCountRec(root->right_);
}

bool BSTree::isAllPositiveRec(const Node* root) {
  if (!root) {
    return true;
  }
  if (root->data_ > 0) {
    return isAllPositiveRec(root->left_) && isAllPositiveRec(root->right_);
  } else {
    return false;
  }
}

void BSTree::deleteLeavesRec2(Node* root, Node* parent, const bool& left) {
  if (root->left_ != nullptr && root->right_ != nullptr) {
    deleteLeavesRec2(root->left_, root, true);
    deleteLeavesRec2(root->right_, root, false);
  } else if (root->left_ != nullptr) {
    deleteLeavesRec2(root->left_, root, true);
  } else if (root->right_ != nullptr) {
    deleteLeavesRec2(root->right_, root, false);
  } else {
    if (left) {
      parent->left_ = nullptr;
    } else {
      parent->right_ = nullptr;
    }
    delete root;
  }
}

void BSTree::deleteLeavesRec(Node* root) {
  if (root->left_ != nullptr && root->right_ != nullptr) {
    deleteLeavesRec2(root->left_, root, true);
    deleteLeavesRec2(root->right_, root, false);
  } else if (root->left_ != nullptr) {
    deleteLeavesRec2(root->left_, root, true);
  } else if (root->right_ != nullptr) {
    deleteLeavesRec2(root->right_, root, false);
  } else {
    delete root;
  }
}

double BSTree::getArifmeticAverageRec(Node* root, double& c) {
  if (!root) {
    return 0;
  }
  c++;
  return root->data_ + getArifmeticAverageRec(root->left_, c) +
         getArifmeticAverageRec(root->right_, c);
}

bool BSTree::findElementRec(Node* root, const int& x, std::vector<int>& v) {
  if (!root) {
    return false;
  }
  if (x < root->data_) {
    v.push_back(0);
    return findElementRec(root->left_, x, v);
  }
  if (x > root->data_) {
    v.push_back(1);
    return findElementRec(root->right_, x, v);
  }
  return true;
}

bool BSTree::isBSTRec(const Node* root) {
  if (!root) {
    return true;
  }
  return ((root->left_ == nullptr) || root->data_ > root->left_->data_) &&
         ((root->right_ == nullptr) || root->data_ < root->right_->data_) &&
         isBSTRec(root->left_) && isBSTRec(root->right_);
}

void BSTree::printByLevelsRec(const Node* root, int tabSize) {
  if (!root) {
    return;
  }
  tabSize += 4;
  printByLevelsRec(root->right_, tabSize);
  std::cout << "\n";
  std::cout << std::string(tabSize - 4, ' ') << root->data_ << "\n";
  printByLevelsRec(root->left_, tabSize);
}

BSTree::BSTree() {
  root_ = nullptr;
}

BSTree::BSTree(const BSTree& cp) {
  root_ = copyTree(cp.root_);
}

BSTree& BSTree::operator=(const BSTree& cp) {
  clear();
  root_ = copyTree(cp.root_);
  return *this;
}

BSTree::BSTree(BSTree&& mv) {
  std::swap(root_, mv.root_);
  mv.root_ = nullptr;
}

BSTree& BSTree::operator=(BSTree&& mv) {
  std::swap(root_, mv.root_);
  return *this;
}

BSTree::~BSTree() {
  clear();
}

bool BSTree::addElement(const int& x, const std::vector<int>& path) {
  if (std::count(path.begin(), path.end(), 0) +
          std::count(path.begin(), path.end(), 1) !=
      path.size()) {
    return false;
  }
  Node** rt = &root_;
  for (int i : path) {
    if (i == 0) {
      rt = &(*rt)->left_;
    } else if (i == 1) {
      rt = &(*rt)->right_;
    }
  }
  if (!(*rt)) {
    *rt = new Node(x);
  } else {
    (*rt)->data_ = x;
  }
  return true;
}

int BSTree::getEvenCount() {
  return getEvenCountRec(root_);
}

bool BSTree::isAllPositive() {
  return isAllPositiveRec(root_);
}

void BSTree::clear() {
  clearElements(root_);
  root_ = nullptr;
}

void BSTree::deleteLeaves() {
  if (!isEmpty()) {
    deleteLeavesRec(root_);
  }
}

double BSTree::getArifmeticAverage() {
  double count = 0;
  return getArifmeticAverageRec(root_, count) / count;
}

std::vector<int> BSTree::findElement(const int& x) {
  std::vector<int> v;
  if (findElementRec(root_, x, v)) {
    return v;
  } else {
    v.clear();
    v.push_back(-1);
    return v;
  }
}

bool BSTree::isEmpty() const {
  return root_ == nullptr;
}

bool BSTree::isBinarySearchTree() {
  return isBSTRec(root_);
}

void printTreeByLevels(Node* root) {
  if (root == nullptr) {
    return;
  }
  std::queue<Node*> levelQueue;
  levelQueue.push(root);
  while (!levelQueue.empty()) {
    for (int i = 0; i < levelQueue.size(); i++) {
      Node* current = levelQueue.front();
      levelQueue.pop();
      std::cout << current->data_ << " ";
      if (current->left_) {
        levelQueue.push(current->left_);
      }
      if (current->right_) {
        levelQueue.push(current->right_);
      }
    }
    std::cout << std::endl;
  }
}

void BSTree::printByLevels(bool rotate) {
  if (rotate) {
    printByLevelsRec(root_, 4);
  } else {
    printTreeByLevels(root_);
  }
}
