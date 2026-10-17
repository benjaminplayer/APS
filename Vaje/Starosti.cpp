#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Compare {
    bool operator()(const pair<string, int>& a,
                    const pair<string, int>& b) const {
        return a.second > b.second;
    }
};

int main()
{

    int n, k;

    int max[k];

    cin >> n >> k; // prebere n in k
    vector<pair<string,int>> osebe;

    set<pair<string,int>, Compare> os;

    // napolni vector
    while ((n--) > 0)
    {
        pair<string,int> o;
        cin >> o.first >> o.second;
        os.insert(o);
    }

    cout << "Osebe list" << endl;
    for (auto o : os)
        cout << o.first << " " << o.second <<endl;

    vector<pair<string,int>> ord;

    for (int i = 0; i < k; i++)
        ord.push_back(osebe[i]);

    sort(ord.begin(), ord.end(),
        [](const pair<string, int>& a,
                const pair<string, int>& b)
                {
                    return a.first < b.first;
                }
    );

    for (const auto i : ord)
        cout << i.first << endl;

    return 0;
}
