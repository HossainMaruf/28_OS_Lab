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

bool comp(Person p1, Person p2) {
  if(p1.id < p2.id) return true;
  else return false;
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

  // sort
  // for(int i=0; i<3; i++) {
  //   for(int j=i+1; j<3; j++) {
  //     if(p[i].id > p[j].id) {
  //       Person temp = p[i];
  //       p[i] = p[j];
  //       p[j] = temp;
  //     }
  //   }
  // }

  sort(p, p+3, comp);

  // Display
  for(int i=0; i<3; i++) {
    p[i].DisplayInfo(p[i]);
  }

  return 0;
}