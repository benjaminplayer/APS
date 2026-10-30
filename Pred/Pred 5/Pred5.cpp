#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
using namespace std;

// Range minimum query
class RMQ {
private:
    int n;
    vector<int> array;
    struct Node {int min, begin, end;};
    vector<Node> tree;
    int INF = 1e9; // 10^9
public:

    RMQ(vector<int> &a)
    {
        n = static_cast<int>(pow(2, ceil(log2(a.size()))));
        array = a;
        array.resize(n, INF);
        tree.resize(2*n);
        build();
    }

    void build(int id = 1)
    {
        if (id >= n)//imam opravek z listom
        {
            tree[id] = {
                array[id - n],
                id-n,
                id-n+1
            };
            return;
        }

        int left = 2*id, right = 2*id + 1;
        build(left);
        build(right);
        tree[id] = {
            min(tree[left].min,tree[right].min),
            tree[left].begin,
            tree[right].end
        };
    }

    int query(int l, int r, int id = 1)
    {
        // znotraj
        if (l <= tree[id].begin && tree[id].end <= r) return tree[id].min;
        // zunaj
        if (r <= tree[id].begin || tree[id].end <= l) return INF;

        return min(query(l,r,2*id), query(l,r,2*id + 1));

    }

};

int main()
{
    int n = 1'000;
    mt19937 rng(123);
    vector<int> a;
    for (int i = 0; i < n; i++) a.push_back(rng()%100'000'000);
    RMQ rmq(a);

    for (int it = 0; it < 100; it++)
    {
        int l = rng()%n, r = rng()%n;
        if (l>= r) continue;
        int ans = rmq.query(l, r);
        /*int ans2 =*min_element(a.begin()+l, a.begin()+r);
        if (ans != ans2) cout << "oops" << endl;
        cout << ans << endl;*/
    }

    return 0;
}