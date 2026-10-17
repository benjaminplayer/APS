#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void podvoji(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        v.push_back(v[i]);
}

void izpisi(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

bool cmpAbs(int x, int y)
{
    return abs(x) < abs(y);
}

int main()
{
    /*
    std::cout << "Ne :)" << std::endl;

    int a, b;
    std::cin >> a;
    std::cin >> b;

    std::cout << a+b << std::endl; //cin cout ima buffer; endl dodatno flusha output
    */

    /*
    string ime, priimek;
    std::cin >> ime;
    std::cin >> priimek;

    string oseba = ime + priimek;

    //endl = '\n' << flush

    std::cout << "hewwo" << oseba << std::endl;
    std::cout << ime[0] << priimek[0] << std::endl;
    std::cout << oseba.size() << std::endl;
    */

    /*
    pair<int,int> xy, coord = {-1,7};

    xy = make_pair(4,8);
    cout << xy.first << " " << xy.second << endl;
    cout << coord.first << " " << coord.second << endl;

    pair<pair<string,string>,int> ocena = {{"pinko","palinko"},10};
    cout << ocena.first << " " << ocena.second << endl; */

    /*
    vector<int> v = {-2,1};
    for (int i = 0; i < 10; i++) v.push_back(i);
    cout<< v.size()<<endl;

    for (int i = 0; i < v.size(); i++) cout<< v[i]<<" ";
    cout<< endl;


    //v.begin()//iterattor ki kaze na zacetek
    //v.end()//iterattor ki kaze na konec

    for (auto it = v.begin(); it != v.end(); it++) cout << *it << " ";
    cout << endl;

    for (int x : v) cout << x << " ";
    cout << endl;

    vector<pair<int,int>> coords = {{2,3},{-1,5},{9,0}};
    /*for (pair<int, int> k : coords)
    {
        /*int x = k.first;
        int y = k.second;
        #2#
        auto [x,y] = k;

        cout<< x <<" "<< y <<endl;

    }#1#

    // isto kot loop zgori
    for (auto [x,y] : coords) // automatsko razpakiranje struct
        cout << x << " " << y << " ";
    cout << endl;

    array<int,3> a = {2,4,6};
    auto [x,y,z] = a;
    cout << x + y + z << " ";
    cout << endl;
    */

    /*set<string> prisotni = {"Ana","Miha","Tine"}; // set je urejen po abecedi
    prisotni.insert("Matej");
    prisotni.insert("Miha");

    for (string ime : prisotni)
        cout << ime << endl;

    map<string, int> vpisna = {{"Ana",123},{"Tine",456}}; // basically ordered hash map
    vpisna["Miha"] = 543;

    for (auto [key,val] : vpisna)
        cout << key << " " << val << endl;

    cout << vpisna["Janze"] << endl; // ne crasha, naredi default vrednost*/

    //references -> drugo ime za isti var

    /*
    int x = 10;

    int &y = x; // gre za 1 location v mem, preko katere lahko dostopam po x in po y
    x = 9;
    cout << x << " " << y << endl;

    vector<int> soda = {2,4,6};
    podvoji(soda);
    izpisi(soda);
    */

    vector<int> st = {-6,7,1,10,5};
    cout << min(4,5) << " " << min({3,1,4,5}) <<endl;
    cout << *min_element(st.begin(), st.end()) <<endl; // min structa; vrne iterator na min el

    //sort(st.begin(),st.end()); // rabi random access iterator

    //sort(st.begin(), st.end(), cmpAbs); // sort po abs

    sort(st.begin(), st.end(),
    [](int x, int y) { return abs(x) < abs(y); }
    );
    izpisi(st);


    return 0;
}
