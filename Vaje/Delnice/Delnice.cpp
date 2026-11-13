#include <iostream>
#include <set>

/*
 * Racuna se delna vsota
 * izpis: min_{i,j}\abs{\textbf{I}_{i,j} - z}
 *
 * I_{i,j} = I_j - I_{i-1}:
 * \abs{\textbf{I}_{i,j} - z} = \abs{I_j - I{i-1} - z}
 * t_j = I_j - z
 *
 * delne vsote: I_i = {I_i-1} + x_i -> shrani v preinit array, alpa sam v vector
 *
 * I-je das v AVL
 * Not poisces min el manjsi, ki je vecji od targeta t_j
 * Pole primerjas tista 2 nodes ki omejista t_j
 *
 * Za AVL tree rabis set
 * Lowerbound(target) -> itterator na najnizji element
 *
 */

using namespace std;

int main()
{
    set<int> tree;

    int n, z, x;
    cin >> n >> z;

    int last_sum = 0;
    int min = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        tree.insert(x +last_sum);
        

        auto lower = lower_bound(tree.begin(), tree.end(), x);
        // target j = i, sum i - 1 = last sum
        // isces min|target j - sum I i- 1|

        last_sum += x;

    }



    return 0;
}