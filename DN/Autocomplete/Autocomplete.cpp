#include <iostream>
#include <vector>

using namespace std;

typedef struct Node
{
    char c;
    int priority, idx;
    Node* children[26];
    Node* best_child;

} Node;

class Tree
{
public:
    Node* root;
    int elements_added;
    Tree()
    {
        root = createNode('R',-1,-1);
        for (auto &child : root->children)
            child = nullptr;
        elements_added = 0;
    };

    void add(const string& s, int const priority)
    {
        addIt(&s[0], priority);
    }

    int find(const string &s) const
    {
        return findIt(&s[0]);
    }

private:

    static Node* createNode(const char c, const int priority, const int idx)
    {
        auto* node = new Node();
        node->c = c;
        node->priority = priority;
        node->idx = idx;
        node->best_child = nullptr;
        return node;
    }

    void addIt(const char* cp, int const priority)
    {
        // empty string -> end of the tree
        Node* node = root;
        elements_added++;


        while (*cp != '\0')
        {
            const int idx = *cp - 'a';

            if (node->children[idx] == nullptr)
                node->children[idx] = createNode(*cp, priority, -1);

            Node* child = node->children[idx];

            if (priority > child->priority)
            {
                child->idx = -1;
                child->priority = priority;
            }

            if (node->best_child == nullptr || node->best_child->priority < child->priority)
                node->best_child = child;

            node = child;
            cp++;
        }

        if (node->idx == -1 && node->priority <= priority)
            node->idx = elements_added;

    }

    int findIt(const char* cp) const
    {
        const Node* node = root;

        while (node != nullptr)
        {
            if (*cp == '\0')
            {
                if (node->idx != -1) return node->idx; // complete match
                const auto best = node->best_child;

                //if (max_it == end(node->children) || *max_it == nullptr) return 0;
                if (best == nullptr) return 0;

                node = best;
            }
            else
            {
                auto const child = node->children[(*cp) - 'a'];
                if (child == nullptr) return 0;
                node = child;
                cp++;
            }

        }

        return 0;
    }

};

int main(int argc, char *argv[])
{
    Tree t;
    int n, p;
    string word;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> word >> p;
        t.add(word,p);
    }

    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        res.push_back(t.find(word));
    }

    for (const auto el : res)
        cout << el << "\n";

    return 0;
}
