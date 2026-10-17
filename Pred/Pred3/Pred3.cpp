#include <iostream>
#include <vector>
#include <random>

using namespace std;

class DynamicArray {
private:
    int *t, size, capacity;
public:
    DynamicArray()
    {
        t = static_cast<int *>(malloc(1 * sizeof(int)));
        size = 0;
        capacity = 1;
    }
    ~DynamicArray()
    {
        free(t);
    }

    int operator[](int i)
    {
        return t[i];
    }

    void add(const int x)
    {
        if (size == capacity)
        {
            capacity *= 2;
            t = static_cast<int *>(realloc(t, capacity * sizeof(int)));
        }
        t[size++] = x;
    }
};

class BinaryHeap {
    private:
        vector<int> t;
    public:
        void insert(int x)
        {
            t.push_back(x);
            int i = t.size()-1;
            while (i>= 1 && t[i] < t[i/2])
            {
                swap(t[i],t[i/2]);
                i /= 2;
            }
        }

        int pull()
        {
            int x = t[1], i = 1;
            t[i] = t.back();
            t.pop_back();

            while (1)
            {
                int j = i;
                if (2*i < t.size() && t[2*i] < t[j]) j = 2*i;
                if (2*i+1 < t.size() && t[2*i+1] < t[j]) j = 2*i+1;
                if (i == j) break;

                swap(t[i],t[j]);
                i = j;

            }
        }

};

int main(int argc, char *argv[])
{
    constexpr int n = 10000;
    DynamicArray a;
    BinaryHeap bh;

    mt19937 rnd(123); // random z nekim seedom


    // heap sort -> vse el das v heap nato vzames vn

    for (int i = 0; i < n; i++)
    {
        bh.insert(rnd()%1000000);
    }

    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(bh.pull());

    /*for (int i = 0; i < n; i++)
    {
        a.add(i+10);
    }*/

    return 0;
}
