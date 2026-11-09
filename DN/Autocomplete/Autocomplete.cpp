#include <iostream>
#include <vector>

using namespace std;


typedef struct Node {
    char c;
    int priority, best_idx;
    Node *children[26];
} Node;

Node treeNodes[1'000'006]; // pre allocated nodes, ker speed (alleged)

class Tree {
public:
    Node *root;
    int elements_added;
    int nodes_created;

    Tree()
    {
        nodes_created = 0;
        root = createNode('R', -1, -1);
        elements_added = 0;
    };

    void add(const string &s, int const priority)
    {
        addIt(&s[0], priority);
    }

    [[nodiscard]] int find(const string &s) const
    {
        return findIt(&s[0]);
    }

private:
    Node *createNode(const char c, const int priority, const int idx)
    {
        auto *node = &treeNodes[nodes_created++];
        node->c = c;
        node->priority = priority;
        node->best_idx = idx;
        return node;
    }

    void addIt(const char *cp, int const priority)
    {
        // Start with the root
        Node *node = root;
        elements_added++;

        while (*cp != '\0')
        {
            const int idx = *cp - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = createNode(*cp, priority, elements_added);

            Node *child = node->children[idx];

            if (priority > child->priority)
            {
                child->best_idx = elements_added;
                child->priority = priority;
            }

            node = child;
            cp++;
        }
    }

    int findIt(const char *cp) const
    {
        const Node *node = root;

        while (node != nullptr)
        {
            // if the word is a complete or a partial match,
            // return the best index of the current node
            if (*cp == '\0') return node->best_idx;

            // otherwise search the next child
            auto const child = node->children[(*cp) - 'a'];
            if (child == nullptr) return 0;
            node = child;
            cp++;
        }

        return 0;
    }
};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Tree t;
    int n, p;
    string word;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> word >> p;
        t.add(word, p);
    }

    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        res.push_back(t.find(word));
    }

    for (const auto el: res)
        cout << el << "\n";

    return 0;
}
