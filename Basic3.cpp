#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector is a template class
    vector<int> v;
    v.push_back(10);
    v.push_back(14);
    v.push_back(19);
    v.push_back(3);


    // cout << v.size() << endl;
    // for(int i=0; i<v.size(); i++) {
    //     cout << v[i] << endl;
    // }
    // for(int i=0; i<v.size(); i++) {
    //     cout << &v[i] << endl;
    // }
    // cout << *v.begin() << endl;
    // cout << *(v.end()-1) << endl;

    // cout << v.at(0) << endl;
    // cout << v[0] << endl;

    v.erase(v.begin()+2);

    for(int i=0; i<v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}