#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long int64;

pair<vector<int64>,int64> merge(vector<int64> a, vector<int64> b)
{
    int i = 0, j = 0;
    vector<int64> c;
    int64 inv = 0;
    while (i < a.size() || j < b.size())
    {
        if (i < a.size() && j < b.size())
        {
            if (a[i] <= b[j])
            {
                c.push_back(a[i++]);
                inv += j;
            }
            else
                c.push_back(b[j++]);
        }
        else if (i < a.size())
        {
            c.push_back(a[i++]);
            inv += j;
        }
        else
            c.push_back(b[j++]);
    }

    return {c,inv};
}

pair<vector<int64>,int64> mergeSort(vector<int64> v)
{
    int mid = v.size() / 2;
    if (v.size() <= 1)
        return {v,0};

    vector<int64> l(v.begin(), v.begin() + mid);
    vector<int64> r(v.begin() + mid, v.end());

    auto [l_sorted, li] = mergeSort(l);
    auto [r_sorted,ri] = mergeSort(r);
    auto [mrg, inv] = merge(l_sorted, r_sorted);

    return {mrg,li + ri + inv};
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int64> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    cout << mergeSort(vec).second << endl;

    return 0;
}