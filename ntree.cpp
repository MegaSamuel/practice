#include <iostream>
#include <vector>
#include <stack>

#if 0

struct Node{  
    int value;  
    const Node* left = nullptr;  
    const Node* right = nullptr;  
  };
  
  void findMax(const Node* node, int& value)
  {
      // определяем максимальное значение
      if( node->value > value )
          value = node->value;
  
      // если есть левый потомок - рекурсивно запускаем поиск
      if( nullptr != node->left )
          findMax(node->left, value);
  
      // если есть правый потомок - рекурсивно запускаем поиск
      if( nullptr != node->right )
          findMax(node->right, value);
  }
  
  int Solution(const Node* root) {
      int max = 0;
  
      // если дерево есть, то запускаем поиск
      if(nullptr != root)
          findMax(root, max);
  
      return max;
  }
  
  void test() {
      Node node1({1, nullptr, nullptr});
      Node node2({-5, nullptr, nullptr});
      Node node3({3, &node1, &node2});
      Node node4({2, &node3, nullptr});
      assert(Solution(&node4) == 3);
  }

#endif

struct Node
{
    int value;
    // const Node* parent;
    std::vector<Node*> children;
};

void printTree(const Node* tree)
{
    if (tree == nullptr)
    {
        return;
    }

    std::cout << tree->value << std::endl;

    for (const Node* child : tree->children)
    {
        printTree(child);
    }
}

int main()
{
    Node node323({323, {}});
    Node node322({322, {}});
    Node node321({321, {}});

    Node node23({23, {}});
    Node node22({22, {&node321, &node322, &node323}});
    Node node21({21, {}});

    Node node1({1, {&node21, &node22, &node23}});

    printTree(&node1);
}
