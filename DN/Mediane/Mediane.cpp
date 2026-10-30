#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    int size, el;
    cin >> size;
    priority_queue<int> l; // max heap
    priority_queue<int, vector<int>, greater<int>> r; // min heap
    //vector<int> meds;
    // 2 heap, l in d
    // l je max heap, d je min heap
    // za vsak element poledas:
    // ce je <= med dam na L, cene na d.
    // na L strani mora biti >= el kot na D
    for (int i = 0; i < size; i++)
    {
        cin >> el;
        if (l.empty() || el <= l.top()) l.push(el);
        else r.push(el);

        if (l.size() > r.size()+1)
        {
            r.push(l.top());
            l.pop();
        }
        else if (r.size() >= l.size()+1)
        {
            l.push(r.top());
            r.pop();
        }

        cout << l.top() << "\n";
    }

    return 0;
}
