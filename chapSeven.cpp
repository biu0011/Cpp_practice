#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "sreen.h"

using namespace std;

int main()
{
    string s1 = "biu";
    string s2 = "America";
    Person p1(s1,s2);

    //print(cout,p1);

    //7.27
    Sreen mysreen(5,5,'X');
    mysreen.move(4,0).set('#').display(cout);
    cout << "\n";
    mysreen.display(cout);
    cout << "\n";
    return 0;
}

