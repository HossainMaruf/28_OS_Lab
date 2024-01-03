#include <bits/stdc++.h>
using namespace std;

struct Person {
  int id;
  string name, fName, mName;
  void DisplayInfo(struct Person);
};
typedef struct Person Person;

void Person::DisplayInfo(Person p) {
  cout << "ID: " << p.id << endl;
  cout << "Name: " << p.name << endl;
  cout << "Father's Name: " << p.fName << endl;
  cout << "Mother's Name: " << p.mName << endl;
}

int main() {
  Person p;
  cout << "Enter id: ";
  cin>>p.id;
  cout << "Enter name: ";
  cin>>p.name;
  cout << "Enter father's name: ";
  cin>>p.fName;
  cout << "Enter mother's name: ";
  cin>>p.mName;

  // Display
  p.DisplayInfo(p);

  return 0;
}