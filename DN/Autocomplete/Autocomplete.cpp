#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

// idea -> sestavi tree z radix sort
// isci po tistem tree-ju

typedef struct Node
{
    char c;
    int priority;
    Node* children[26];
} Node;


class Tree
{
public:
    Node* root;

    Tree()
    {
        root = new Node();
        root->c = 'R';
        root->priority = 0;
        for (auto &child : root->children)
            child = nullptr;

    };

    /*~Tree()
    {
        free(root);
    }*/

    void add(string s, int const priority) const
    {
        add(root, std::move(s), priority);
    }

    void printTree() const
    {
        printTree(root);
    }

private:
    static void add(Node* node, string s, int const priority)
    {
        if (s.empty()) return; // empty string -> end of the tree
        //if (node->children[s[0] - 'a'] != nullptr)
        if (node->children[s[0] - 'a'] != nullptr)
        {
            if (priority <= node->children[s[0] - 'a']->priority)
                add(node->children[s[0] - 'a'], s.substr(1), priority);
            else
            {
                node->priority = priority;
                add(node->children[s[0] - 'a'], s.substr(1), priority);
            }
        }
        else
        {
            node->children[s[0] - 'a'] = new Node();
            node->children[s[0] - 'a']->c = s[0];
            node->children[s[0] - 'a']->priority = priority;

            for (auto &el : node->children[s[0] - 'a']->children)
                el = nullptr;
            add(node->children[s[0] - 'a'], s.substr(1), priority);
        }

    }

    static void printTree(Node* node)
    {
        for (const auto & el : node->children)
        {
            if (el == nullptr) continue;
            cout << "{" << el->c <<";" << el->priority << "} -> ";
            printTree(el);
            cout << endl;
        }
    }


};

int main(int argc, char *argv[])
{
    string s = "algebra", s2 = "alga";
    int priority = 20;
    Tree t;
    t.add(s2,16);
    t.add(s, priority);
    t.printTree();

    return 0;
}
