#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;


void func10_9(vector<string> &words){
    sort(words.begin(),words.end());
    auto it = unique(words.begin(),words.end());
    words.erase(it,words.end());
}

bool isShorter(const string & s1,const string &s2){
    return s1.size() < s2.size();
}

void func10_11(vector<string> &words){
    func10_9(words);
    stable_sort(words.begin(),words.end(),isShorter);
    for(const auto &w : words)
        cout << w << " ";
    cout << endl;
}

bool isShorter2(const string &s){
    return s.size() < 5;
}

void func10_13(vector<string> &words){
    auto it = partition(words.begin(),words.end(),isShorter2);
    for(;it!=words.end();it++)
        cout << *it << " ";
    cout << endl;
} 

//10.14
auto f = [](int i,int j){return i+j;};
// auto h = [i](int j){return i+j;};
