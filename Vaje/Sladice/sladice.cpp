#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// sort the list
// binary search za prvo kom. vsoto vecje od current denarja
// upper_bound(beg, end, element);

int main(int argc, char *argv[])
{
    int s, d, read;
    cin>>s>>d;

    vector<long long> sums(s);
    for (int i = 0; i < s; i++)
        cin >> sums[i];
    sort(sums.begin(), sums.end());
    for (int i = 1; i < s; i++) sums[i] += sums[i - 1];

    for (int i = 0; i < d; i++)
    {
        cin >> read;
        cout << upper_bound(sums.begin(), sums.end(), read) - sums.begin() << " ";
    }
    cout <<endl;
    return 0;
}
