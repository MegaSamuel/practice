#include <iostream>
#include <vector>
#include <algorithm>


struct Node
{
    int value;
    int childValue;
    std::vector<Node*> children;
};

void calcAndSortTree(Node* tree)
{
    if (tree == nullptr)
    {
        return;
    }

    if (tree->children.empty())
    {
        tree->childValue = tree->value;
    }
    else
    {
        for (Node* child : tree->children)
        {
            tree->childValue += child->value;
            calcAndSortTree(child);
        }
    }

    std::sort(tree->children.begin(), tree->children.end(),
        [](const Node* a, const Node* b)
        {
            return a->childValue > b->childValue;
        });

    std::cout << "sort " << tree->value << " " << tree->childValue << std::endl;
}

void addTreeToTable(Node* tree, void* tableItem)
{
    if (tree == nullptr)
    {
        return;
    }

    std::cout << "add " << tree->value << " " << tree->childValue << std::endl;

    for (Node* child : tree->children)
    {
        addTreeToTable(child, nullptr);
    }
}

int main()
{
    Node node3233({9, 0, {}});
    Node node3232({8, 0, {}});
    Node node3231({7, 0, {}});

    Node node3223({6, 0, {}});
    Node node3222({5, 0, {}});
    Node node3221({4, 0, {}});

    Node node3213({3, 0, {}});
    Node node3212({2, 0, {}});
    Node node3211({1, 0, {}});

    Node node23({23, 0, {&node3231, &node3232, &node3233}});
    Node node22({22, 0, {&node3221, &node3222, &node3223}});
    Node node21({21, 0, {&node3211, &node3212, &node3213}});

    Node node1({111, 0, {&node21, &node22, &node23}});

    calcAndSortTree(&node1);

    addTreeToTable(&node1, nullptr);
}
