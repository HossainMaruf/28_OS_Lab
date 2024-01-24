#include <bits/stdc++.h>
using namespace std;

struct comp {
    bool operator()(int a, int b) { 
        if (a > b) return true;
        else return false;
    }
};

int main() {
    priority_queue<int, vector<int>, comp> pq;
    pq.push(10);
    pq.push(92);
    pq.push(100);
    pq.push(2);
    pq.push(45);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
}