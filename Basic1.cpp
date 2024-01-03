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
  Person p[3];

  for(int i=0; i<3; i++) {
    cout << "Enter id " << "#"<<i+1<<": " ;
    cin>>p[i].id;
    cout << "Enter name " << "#"<<i+1<<": " ;
    cin>>p[i].name;
    cout << "Enter father's name " << "#"<<i+1<<": " ;
    cin>>p[i].fName;
    cout << "Enter mother's name " << "#"<<i+1<<": " ;
    cin>>p[i].mName;
  }

  // Display
  for(int i=0; i<3; i++) {
    p[i].DisplayInfo(p[i]);
  }

  return 0;
}