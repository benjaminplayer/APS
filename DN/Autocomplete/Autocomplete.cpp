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
        root = new Node();
        root->c = 'R';
        root->priority =  0;
        root->idx = -1;
        root->best_child = nullptr;
        for (auto &child : root->children)
            child = nullptr;
        elements_added = 1;
    };

    void add(const string& s, int const priority)
    {
        add(root, &s[0], priority, elements_added++);
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

    static void add(Node* node,const char* cp, int const priority, int const element_idx)
    {
        // empty string -> end of the tree
        if (*cp == '\0')
        {
            node->idx = element_idx; // only add the index of the best priority word at the end
            return;
        }
        //if (node->children[s[0] - 'a'] != nullptr)
        if (Node* child = node->children[(*cp) - 'a']; child != nullptr)
        {

            child->idx = -1; // reset the indicies
            if (priority > child->priority)
            {
                child->priority = priority;
                //child->best_child = child;
            }
            add(child, cp + 1, priority,element_idx);

        }
        else
        {
            const int idx = (*cp) - 'a';
            /*node->children[idx] = new Node();
            node->children[idx]->c = *cp;
            node->children[idx]->priority = priority;
            node->children[idx]->idx = element_idx;
            node->children[idx]->best_child = nullptr;*/

            node->children[idx] = createNode(*cp, priority, -1);

            /*
            // store the idx of the word on the last letter
            node->children[idx]->idx = -1;*/

            if (node->best_child == nullptr || node->best_child->priority < node->children[idx]->priority)
                node->best_child = node->children[idx]; // nov child za ta path je automatically best
                /*for (auto &el : node->children[idx]->children)
                el = nullptr;*/
            add(node->children[idx], cp+1, priority,element_idx);
        }

    }

    void addIt(const char* cp, int const priority)
    {
        // empty string -> end of the tree
        Node* node = root;
        elements_added++;

        while (*cp != '\0')
        {
            int idx = *cp - 'a';

            if (node->children[idx] == nullptr) createNode(*cp, priority, idx);

            Node* child = node->children[idx];
            child->idx = -1;

            if (priority > child->priority)
                child->priority = priority;

            if (node->best_child->priority < child->priority || node->best_child == nullptr)
                node->best_child = child;

            node = child;
            cp++;
        }

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
