#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void merge_k(vector<int>& vec, vector<queue<int>>& vq, int& offset)
{
    int k = vq.size();
    int min = vq[0].front(), midx = 0;
    while (k > 0)
    {
        min = vq[0].front();
        midx = 0;

        for (int i = 0; i < k; i++) // gets the min element looking only at the first columns of the vector of queues
        {
            if (vq[i].front() < min)
            {
                min = vq[i].front();
                midx = i;
            }
        }

        vec[offset++] = min; // inserts the elements of the k-group in the right place in the original vector
        vq[midx].pop(); // pops the min element in the vq vector
        if (vq[midx].empty())
        {
            vq.erase(vq.begin() + midx); // erase the empty queue
            k--;
        }
    }

}

void printVector(const vector<int>& vec)
{
    for (const auto el : vec)
        cout << el << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{

    int n, k, a;
    cin >> n >> k >> a;
    vector<int> vec(n);
    vector<queue<int>> vq;

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    while (a --> 0)
    {
        vq.emplace_back();
        vq[0].push(vec[0]);
        int r = 0, begin = 0;
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] < vec[i-1])
            {
                if (++r == k)
                {
                    merge_k(vec, vq, begin);
                    r = 0;
                }

                vq.emplace_back(); // create an empty queue
            }
            // fill the queues
            vq[r].push(vec[i]);
        }
        if (vq[0].size() == vec.size()) break; // if there were none subdivisions the array is sorted
        if (!vq.empty()) merge_k(vec,vq,begin); // if the queue vector isn't empty -> k was not divisible

    }

    printVector(vec);

    return 0;
}
