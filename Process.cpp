#include <bits/stdc++.h>

using namespace std;

struct Process {
  int at; // Arrival Time
  int priority;
};

void display(Process p[], int n) {
  cout << endl;
  for(int i=0; i<n; i++) {
    cout << "ID: " << i+1 << "\t" << p[i].at << "\t" << p[i].priority << endl;
  }
  cout << endl << endl;
}

bool compAt(Process p1, Process p2) {
  // if(p1.at < p2.at) return true;
  // else return false;
  return p1.at < p2.at;
}

bool compPriority(Process p1, Process p2) {
  // if(p1.at < p2.at) return true;
  // else return false;
  return p1.priority < p2.priority;
}

bool compAtPriority(Process p1, Process p2) {
  if(p1.at == p2.at) {
    return p1.priority < p2.priority;
  } else {
    return p1.at < p2.at;
  }
}

typedef struct Process Process;

int main() {
  #ifndef MARUF
    freopen("input.txt", "r", stdin);
  #endif

  int n;
  cout << "Enter number of process: ";
  cin >> n;
  Process p[n];

  for(int i=0; i<n; i++) {
    cout << "Enter at and priority of process: #" << i+1 << ": ";
    cin >> p[i].at >> p[i].priority;
  }

  display(p, n);
  // using at
  sort(p, p+n, compAt);
  display(p, n);
  // using priority
  sort(p, p+n, compPriority);
  display(p, n);
  // using multiple criteria 
  sort(p, p+n, compAtPriority);
  display(p, n);


  return 0;
}