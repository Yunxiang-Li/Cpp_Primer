#include <vector>
#include <iterator>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

//Check vector<int> objects' size and values.
void check(const vector<int>& vec)
{
    if (vec.empty())
        cout << "size: 0; no values." << endl;
    else {
        cout << "size: " << vec.size() << "; values:";
        for (auto it = vec.begin(); it != vec.end(); ++it) cout << *it << ",";
        //Use '\b' to delete the last comma since there is no element after the last element.
        cout << "\b." << endl;
    }
}

//Check vector<string> objects' size and values.
void check(const vector<string>& vec)
{
    if (vec.empty())
        cout << "size: 0; no values." << endl;
    else {
        cout << "size: " << vec.size() << "; values:";
        for (auto it = vec.begin(); it != vec.end(); ++it)
            if (it->empty())
                cout << "(null)"
                     << ",";
            else
                cout << *it << ",";
        //Use '\b' to delete the last comma since there is no element after the last element.
        cout << "\b." << endl;
    }
}

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    check(v1);
    check(v2);
    check(v3);
    check(v4);
    check(v5);
    check(v6);
    check(v7);

    return 0;
}
