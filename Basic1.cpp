#include <bits/stdc++.h>
using namespace std;

struct Person {
  int id;
  string name, fName, mName;
};

int main() {
  struct Person p;
  cout << "Enter id: ";
  cin>>p.id;
  cout << "Enter name: ";
  cin>>p.name;
  cout << "Enter father's name: ";
  cin>>p.fName;
  cout << "Enter mother's name: ";
  cin>>p.mName;

  // // Display Information
  cout << "ID: " << p.id << endl;
  cout << "Name: " << p.name << endl;
  cout << "Father's Name: " << p.fName << endl;
  cout << "Mother's Name: " << p.mName << endl;

  return 0;
}