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
void printTable(struct Process p[], int n) {
    cout << "ID\tAT\tBT\tST\tCT\tWT\tTT" << endl;

    for(int i=0; i<n; i++) {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << "\t" << p[i].wt << "\t" << p[i].tt << endl;
    }
}
bool comp(struct Process p1, struct Process p2) {
    if(p1.at < p2.at) return true;
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

    // calculation of table
    for(int i=0; i<n; i++) {
        if(i == 0) {
            // first process
            p[i].st = p[i].at;
            p[i].ct = p[i].bt;

        } else {
            // rest of the process
            p[i].st = p[i-1].ct;
            p[i].ct = p[i-1].ct + p[i].bt;
        }
        p[i].wt = p[i].st - p[i].at;
        p[i].tt = p[i].wt + p[i].bt;
        sum_wt += p[i].wt;
    }

    printTable(p, n);

    cout << endl << "Avg. WT: " << ((float)sum_wt / n) << endl;

return 0;
}














