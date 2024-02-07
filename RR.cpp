#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, at, bt, rt, st = -1, ct, wt, tt;
    bool pushed = false;
};

void printProcess(struct Process p[], int n) {
    for(int i=0; i<n; i++) {
       cout << p[i].id << " " << p[i].at << " " << p[i].bt << endl;
    }
}
void printTable(struct Process p[], int n) {
    cout << "ID\tAT\tBT\tST\tCT" << endl;

    for(int i=0; i<n; i++) {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    struct Process p[n];
    for(int i=0; i<n; i++) {
        cin >> p[i].id >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt;
    }

    printProcess(p, n);

    /**
     * ROUND ROBIN IMPLEMENTATION
    */
   int minIndex = 0;
   for(int i=1; i<n; i++) {
    if(p[i].at < p[minIndex].at) minIndex = i;
   }

//    cout << minIndex << endl;
    vector<struct Process*> ready_queue;
    ready_queue.push_back(&p[minIndex]);
    p[minIndex].pushed = true;
    int t = p[minIndex].at, count = 0, TQ = 5;
    while(count != n) {
        struct Process* selected =  ready_queue.front();
        cout << selected->id << endl;
        // delete from the ready queue
        ready_queue.erase(ready_queue.begin());
        if(selected->rt < TQ) {
            if(selected->st == -1) {
                selected->st = t;
            }
            selected->ct = t + selected->rt;
            selected->rt = 0;
            t = selected->ct;
            count++;
        } else {
            // when BT > TQ
            if(selected->st == -1) {
                selected->st = t;
            }
            selected->ct = t + TQ;
            t = selected->ct;
            selected->rt = selected->rt - TQ;
            // recently arrived process
            for(int i=0; i<n; i++) {
                if((p[i].pushed == false) && (p[i].at <= t)) {
                    ready_queue.push_back(&p[i]);
                    p[i].pushed = true;
                }
            }
            if(selected->rt > 0) {
                // have remaining time
                ready_queue.push_back(selected);
            } else {
                // no remaining time
                count++;
            }
        }
        
    }

    printTable(p, n);

    return 0;
}