#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct tower {
    int h;
    int idx;
};

/*
 * Na stacku hranimo element: (h,i)
 * Na njega pushamo indexe vseh stolpov, ki so visji od trenutnega
 * j => index neboticnika, i => index na stacku; n_j^l = j - i - 1
 */

long long calculate(vector<tower>& v)
{
    stack<tower> s;
    long long sum = 0;
    s.push(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].h >= s.top().h)
        {
            while (!s.empty() && v[i].h >= s.top().h) s.pop();
            sum += (!s.empty())? v[i].idx - s.top().idx - 1 : v[i].idx + 1; // if the stack is empty, add one to the index
        }
        s.push(v[i]);
    }

    return sum;
}

void solve(vector<tower>& v)
{
    long long sum = 0;
    sum += calculate(v);

    // reverses a vector
    for (int i = 0; i < v.size()/2; i++)
    {
        tower temp = v[i];
        int temp_i = v[i].idx;
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = temp;
        v[v.size() - i - 1].idx = v[i].idx;
        v[i].idx = temp_i;
    }

    sum+= calculate(v);
    cout << sum << endl;
}

int main()
{
    int n, h;
    cin >> n;

    vector<tower> v;

    // fill the vector with towers
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        v.push_back({h,i-1});
    }

    solve(v);

    return 0;
}