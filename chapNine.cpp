#include <iostream>
#include <string>
#include <vector>
#include "nine.h"

using namespace std;

int main()
{
    //9.18
    // string s;
    // deque<string> dq;
    // while (cin>>s)
    // {
    //     dq.push_back(s);
    // }

    // for(auto const &dit : dq){
    //     cout << dit << endl;
    // }

    //9.20
    // list<int> list{1,2,3,4,5,6,7,8,9,10};
    // deque<int> even,odd;
    // for(auto const &l : list){
    //     (l%2 ? odd : even).push_back(l);
    // }

    // cout << "even :";
    // for(auto const &e : even){
    //     cout << " "<<e;
    // }
    // cout << endl;
    
    // cout << "odd :";
    // for(auto const &o : odd){
    //     cout << " "<<o;
    // }
    // cout << endl;

    //9.23
    // vector<int> vect;
    // cout << *vect.begin()<<endl;;
    // cout << vect.front()<<endl;;
    // cout << vect.at(0)<<endl;;
    // cout << vect[0]<<endl;; 

    //9.26
    // int ia[]={0,1,1,2,3,5,8,13,21,55,89};
    // vector<int> vect(ia,end(ia));
    // list<int> list(ia,end(ia));
    // for(vector<int>::iterator v=vect.begin() ; v!=vect.end();){
    //     if(*v % 2){
    //         vect.erase(v);
    //     }else{
    //         v++;
    //     }
    // }    
    
    //9.43
    // string s = "To drive straight thru is a foolish, tho courageous tho act.";
    // string oldVal = "tho";
    // string newVal = "through";
    // func9_44(s,oldVal,newVal);
    // cout << s << endl;

    //9.45
    string s = "xiaowang";
    func9_46(s,"Mr","Jr.");
    cout << s <<endl;

    return 0;
}