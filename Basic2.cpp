#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) {
  if(a < b) return false;
  else return true;
}

int main() {
  int arr[5] = {3, -1, 7, 10, 2};
  // 100 104 108 112 116
  // cout << arr[0] << endl;
  // cout << &arr[0] << endl;
  // cout << arr << endl;

  sort(arr, arr+5, comp);

  for(int i=0; i<5; i++) 
    cout << arr[i] << " ";

  return 0;
}