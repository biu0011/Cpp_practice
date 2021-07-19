#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
    Person(string &s1,string &s2):name(s1),address(s2){}
    Person(istream &is);
    string name;
    string address;
    string get_name() const { return name; };
    string get_adress() const { return address; };
};

istream& read(istream &is,Person &p){
    is >> p.name >> p.address;

    return is;
}

ostream& print(ostream &io,const Person &p){
    io << p.name << " "<< p.address;

    return io;
}

Person::Person(istream &is){
    read(is,*this);
}