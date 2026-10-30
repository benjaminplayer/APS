#include <iostream>
#include <queue>

using namespace std;

void printPq(priority_queue<pair<int,int>> pq)
{
    while (!pq.empty())
    {
        cout << "{ "<<pq.top().first << " " << pq.top().second << "}" << endl;
        pq.pop();
    }
}

int main()
{
    int n, k, beg = 0, end = 0;
    char c;
    string s;

    cin >> n >> k;

    priority_queue<pair<int,int>> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        s += c;

        if (c == '*' && end - beg > 0)
        {
            pq.push(pair<int,int>(end - beg,-beg));
            beg = end;
            end = i;
        }
        end++;
    }

    if (c != '*') pq.push(pair<int,int>(end - beg,-(beg + 1)));

    cout << "read:\n" << s << endl;

    cout << "pq:" << endl;
    printPq(pq);

    while (k --> 0)
    {
        pair <int,int> pair = pq.top();
        pq.pop();
        int i = -pair.second, j = i + pair.first, p = (i + j) / 2;
        s[i] = '*';
        s[p + 1] = '*';
        pq.push({p-i,-i});
        pq.push({j-p,-(p+1)});
    }

    cout << s << endl;

    return 0;
}