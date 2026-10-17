#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void merge_k(vector<int>& vec, vector<queue<int>>& vq, int& offset)
{
    int k = vq.size();
    int min = vq[0].front(), midx = 0;
    while (vq.size() > 0)
    {
        min = vq[0].front();
        midx = 0;

        for (int i = 0; i < k; i++)
        {
            if (vq[i].front() < min)
            {
                min = vq[i].front();
                midx = i;
            }
        }

        vec[offset++] = min;
        vq[midx].pop();
        if (vq[midx].empty())
        {
            k--;
            vq.erase(vq.begin() + midx); // erase the empty queue
        }
    }

}

void printVector(vector<int>& vec)
{
    for (const auto el : vec)
        cout << el << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    int n, k, a, read;
    cin >> n >> k >> a;

    vector<int> vec;
    vector<queue<int>> vq;

    for (int i = 0; i < n; i++)
    {
        cin >> read;
        vec.push_back(read);
    }

    int r, begin;

    while (a-- > 0)
    {
        vq.push_back(queue<int>());
        vq[0].push(vec[0]);
        r = 0;
        begin = 0;
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] < vec[i-1])
            {
                if (++r == k)
                {
                    merge_k(vec, vq, begin);
                    r = 0;
                }

                vq.push_back(queue<int>());
            }
            // fill the queues
            vq[r].push(vec[i]);
        }
        if (vq[0].size() == vec.size()) break; // if there were none subdivision the array is sorted
        if (!vq.empty()) merge_k(vec,vq,begin);
        //cout << a << endl;
    }

    printVector(vec);

    return 0;
}
