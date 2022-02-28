#include <iostream>
#include <string>
#include <vector>
#include "nine.h"
#include<algorithm>
#include <chrono>

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
    // string s = "xiaowang";
    // func9_46(s,"Mr","Jr.");
    // cout << s <<endl;

    //9.49
    // string target;
    // target = func9_49("temp9.txt");
    // if(target.size() > 0){
    //         cout << target << endl;
    // }else
    //     cout << "can't find the character" << endl;

    //9.51
    // date d1{"January 2,1900"};
    // date d2{"1/2/1900"};
    // date d3{"Jan 2 1900"};
    // d1.prinfDate();
    // d2.prinfDate();
    // d3.prinfDate();


    // const char *p = "SignalGenerator\0SpectralSignalProcessing\0CursorTask\0";
    // std::vector<std::string> modules;
    // while (*p)
    // {
    //     modules.push_back(p);
    //     p += modules.back().length() + 1;
    //     cout << modules.back().length() << endl;
    // }
    // for(int i = 0; i != modules.size(); i++){
    //     cout <<"index: " << i << " " << modules[i] <<endl;
    // }
    // float top = 0.489f;//0.47f;
    // float bottom = 0.511f;//0.53f;
    // float fixation_cross_center = top + ( bottom - top)/2;

    // cout << fixation_cross_center <<endl;

  chrono::steady_clock sc;   // create an object of `steady_clock` class
   auto start = sc.now();     // start timer

   // do stuff....

   auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
   auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
   cout<<"Operation took: "<<time_span.count()<<" seconds !!!";
    return 0;
}