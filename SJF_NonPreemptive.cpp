#include <bits/stdc++.h>

using namespace std;


struct Process {
    int id, at, bt, st, ct, wt, tt;
};

void printProcess(struct Process p[], int n) {
    for(int i=0; i<n; i++) {
       cout << p[i].id << " " << p[i].at << " " << p[i].bt << endl;
    }
}

bool comp(struct Process p1, struct Process p2) {
    if(p1.at < p2.at) return true;
    else return false;
}
bool compBT(struct Process p1, struct Process p2) {
    if(p1.bt < p2.bt) return true;
    else return false;
}



int main() {
    freopen("input.txt", "r", stdin);
    int n;
    int sum_wt = 0;
    cout << "Enter number of process: ";
    cin >> n;
    struct Process p[n];

    for(int i=0; i<n; i++) {
        cin >> p[i].id >> p[i].at >> p[i].bt;
    }
    cout << endl;
    cout << "Before sorting the process" << endl;
    printProcess(p, n);
    sort(p, p+n, comp);
    cout << endl << "After sorting the process" << endl;
    printProcess(p, n);

    struct Process selected_process = p[0];
    p[0].ct = p[0].at + p[0].bt;

    // cout << p[0].ct << endl; 

    vector<struct Process> ready_queue;
    for(int i=1; i<n; i++) {
        if(p[i].at <= p[0].ct) {
            ready_queue.push_back(p[i]);
        }
    }

    // cout << ready_queue.size() << endl;
    sort(ready_queue.begin(), ready_queue.begin()+ready_queue.size(), compBT);
    selected_process = ready_queue[0];

    // for(int i=0; i<ready_queue.size(); i++) { cout << ready_queue[i].id << endl;
    // }
     ready_queue[0].st = p[0].ct;
    for(int i=ready_queue.size()+1; i<n; i++) {
        if(p[i].at <= (ready_queue[0].st+ready_queue[0].bt)) {
            ready_queue.push_back(p[i]);
        }
    }

    cout << ready_queue[ready_queue.size()-1].id << endl;
    selected_process.id = 1000;
    cout << p[2].id << endl;

    return 0;
}