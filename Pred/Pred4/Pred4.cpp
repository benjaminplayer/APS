#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
public:
    vector<list<pair<int,int>>> t;
    int size, capacity;
    int hash(int x) {return x % capacity;}

    HashTable()
    {
        size = 0;
        capacity = 100;
        t.resize(capacity);
    }

    void rehash()
    {
        capacity *= 2;
        vector<list<pair<int,int>>> t2(capacity);
        for (int h = 0; h < t.size(); h++)
        {
            for (auto& [key,value] : t[h])
            {
                int h2 = hash(key);
                t2[h2].push_back({key,value});
            }
        }
        t = t2;

    }

    void insert(int k, int v)
    {
        if (size == capacity) rehash();

        int h = hash(k);
        for (auto& [key,value] : t[h])
        {
            if (key == k )
                value = v;
            return;
        }
        t[h].push_back({k,v});
        size++;
    }

    int get(int k)
    {
        int h = hash(k);
        for (auto& [key,value] : t[h])
        {
            if (key == k) return value;
        }
        return -1;
    }

};

int main()
{

    return 0;
}