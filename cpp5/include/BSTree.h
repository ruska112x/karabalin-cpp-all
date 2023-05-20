#ifndef CPP5_BSTREE_H
#define CPP5_BSTREE_H

#include <iostream>
#include <vector>
#include <queue>

struct Node {
  Node(const int& data = int(), Node* left = nullptr, Node* right = nullptr)
      : data_(data), left_(left), right_(right) {}

  friend std::ostream& operator<<(std::ostream& os, Node* node) {
    if (!node) {
      return os;
    }
    if (node) {
      if (node->left_) {
        os << node->left_;
      }
      os << node->data_ << " ";
      if (node->right_) {
        os << node->right_;
      }
    }
    return os;
  }
  int data_;
  Node* left_;
  Node* right_;
};

class BSTree {
  void clearElements(Node*);
  Node* findNode(const Node*, const int&);
  Node* findNodeRec(const Node*, const int&);
  bool insertNode(Node*&, const int&);
  Node* copyTree(const Node*);
  int getEvenCountRec(const Node*);
  bool isAllPositiveRec(const Node*);
  void deleteLeavesRec2(Node*, Node*, const bool&);
  void deleteLeavesRec(Node*);
  double getArifmeticAverageRec(Node*, double&);
  bool findElementRec(Node*, const int&, std::vector<int>&);
  bool isBSTRec(const Node*);
  void printByLevelsRec(const Node*, int);

 public:
  // конструктор по умолчанию
  BSTree();

  // конструктор копирования
  BSTree(const BSTree&);

  // оператор копирования
  BSTree& operator=(const BSTree&);

  // конструктор перемещения
  BSTree(BSTree&&);

  // оператор перемещения
  BSTree& operator=(BSTree&&);

  // деструктор
  ~BSTree();

  // оператор вывода
  friend std::ostream& operator<<(std::ostream&, const BSTree&);

  /* вствавка элемента в дерево
   * 1-й аргумент - число, которое нужно вставить
   * 2-й аргумент - путь(вектор 0 и 1)
  */
  bool addElement(const int&, const std::vector<int>&);

  // кол-во чётных чисел в дереве
  int getEvenCount();

  // проверка того, что в дереве только положительные числа
  bool isAllPositive();

  // очистка дерева
  void clear();

  // удаление в дереве всех листьев
  void deleteLeaves();

  // среднее арифметическое всех чисел в дереве
  double getArifmeticAverage();

  // поиск заданного элемента в дереве
  std::vector<int> findElement(const int&);

  // проверка на пустоту
  bool isEmpty() const;

  // ДОПЫ:

  // проверка того, что дерево является деревом двоичного поиска
  bool isBinarySearchTree();

  /* вывод дерева в поток по уровням
   * можно задать разворот на 90 градусов
   */
  void printByLevels(bool);

 private:
  Node* root_;
};

#endif  //CPP5_BSTREE_H
