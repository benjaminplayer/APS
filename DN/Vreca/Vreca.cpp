#include <iostream>
#include <vector>
#include <cmath>

/*
 * Idea:
 *  Staticno drevo, ki hrani feq parov -> RMQ
 *
 *
 *  Hint na vajah: array freq velikosti 10^6 -> probs slow to count ker O(n)
 *
 */
using namespace std;

class RMQ {
private:
    int n;
    vector<int> array;
    struct Node {int freq, begin, end;};
    vector<Node> tree;
    int INF = 1e9; // 10^9


public:

    RMQ()
    {
        //array = vector<int>(1e6); // array of frequencies
        array = vector<int>(8);
        n = static_cast<int>(pow(2, ceil(log2(array.size())))); //size tree-ja
        array.resize(n, INF);
        tree.resize(2*n);
        build();
    }

    void build(const int id = 1)
    {
        if (id >= n)//imam opravek z listom
        {
            tree[id] = {
                //array[id - n],
                0, // usi freq so na zacetku 0
                id-n,
                id-n+1
            };
            return;
        }

        const int left = 2*id, right = 2*id + 1;
        build(left);
        build(right);
        tree[id] = {
            //min(tree[left].min,tree[right].min),
            0, // to nej bo frequency
            tree[left].begin,
            tree[right].end
        };
    }


    // zdej gleda samo [l,r) ne pa [l,r]
    int query(const int l, const int r, const int id = 1)
    {

        // if complete match, return the frequency
        if (l <= tree[id].begin && tree[id].end <= r)
            return tree[id].freq;

        //to more nekak, ce je zuni poledat, al je completely off, alpa sam gleda za en specific value
        if (r < tree[id].begin || tree[id].end < l) //to popravi da je inclusive,
            return 0; // zuni

        return query(l,r,2*id) + query(l,r,2*id + 1); //add right

    }


    void add(const int l, const int r, const int id = 1)
    {
        if (l <= tree[id].begin && tree[id].end <= r)
        {
            tree[id].freq++; // increment the frequency
            return;
        }

        if (l >= tree[2*id].begin && r <= tree[2*id].end)
            add(l,r,2*id); // add left
        else
            add(l,r,2*id + 1); //add right

        tree[id].freq++;

    }

    void remove(const int l, const int r, const int id = 1)
    {
        if (l <= tree[id].begin && tree[id].end <= r)
        {
            tree[id].freq--; // increment the frequency
            return;
        }

        if (l >= tree[2*id].begin && tree[2*id].end <= r)
            add(l,r,2*id); // add left
        else
            add(l,r,2*id + 1); //add right

        tree[id].freq--;

    }

    void add(const int x)
    {
        add(x,x+1);
    }

    void remove(const int x)
    {
      remove(x+n,x+n+1);
    }

};


int main()
{

    RMQ rmq;
    rmq.build();
    rmq.add(7);
    rmq.add(7);
    cout << rmq.query(6,8) << endl; // query zdej gleda [4,6)

    return 0;
}