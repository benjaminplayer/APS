#include <iostream>
#include <vector>

using namespace std;

/*
 * Idea:
 *  Staticno drevo, ki hrani feq parov -> RMQ
 *
 *
 *  Hint na vajah: array freq velikosti 10^6 -> probs slow to count ker O(n)
 *
 */

#define MAX_I 1'000'001 // 1 vec od max inputa, saj je tree 1-indexed

int tree[MAX_I] = {0}; // binary indexed drevo
int count[MAX_I] = {0}; // dodaten array za pregled vsebovanosti stevila

/**
 * Delta: 1 ali -1
 * i = index kamor se ustavi element
 **/
void add (int i, int const delta)
{
    if (count[i] == 0 && delta < 0) return; // ce provamo odstraniti stevilo, ki ne obstaja, ne naredi nic
    count[i] += delta;
    while (i < MAX_I) // sprehod po celotnem drevesu
    {
        tree[i] += delta;
        i+= i & -i; // premik po drevesu glede na LSB
    }
}

/**
 * @brief Calculates the number of elements in the tree up to the index i
 *
**/
long long sum(int i)
{
    long long sum = 0;
    while (i > 0)
    {
        sum += tree[i];
        i -= i & -i; // premik po drevesu navzdol
    }
    return sum;
}

/**
 * @brief Finds the number of elements in the bag in the interval [min(a,b), max(a.b)]
 *
 ***/
long long query(const int a, const int b)
{
    return sum(max(a,b)) - sum(min(a,b) - 1);
}

int main()
{

    int n, s, x;
    long long sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> x;
        if (s < 0) add(x,1);
        else if (s == 0) add(x,-1);
        else sum += query(s,x);
    }

    cout << sum << endl;

    return 0;
}