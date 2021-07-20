#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;


bool func_9_3(std::vector<int>::const_iterator begin,std::vector<int>::const_iterator end, int i){
    while (begin++!=end)
    {
        if(*begin == i){
            return true;
        }
    }
    return false;    
}

std::vector<int>::const_iterator func_9_4(std::vector<int>::const_iterator begin,std::vector<int>::const_iterator end, int i){
    while (begin++!=end)
    {
        if(*begin == i){
            return begin;
        }
    }
    return end;    
}

//9.11
std::vector<int> v1;
std::vector<int> v2(10);
std::vector<int> v3(10,1);
std::vector<int> v4{0,1,2,3};
std::vector<int> v5(v3);
std::vector<int> v6(v4.begin(),v4.end());

//9.12
std::list<int> l1 = {1,2,3};
std::vector<double> vct1(l1.begin(),l1.end());
std::vector<int> vct2{1,2,3,4,5};
std::vector<double> vct3(vct2.begin(),vct2.end());

//9.13
std::list<const char*>list1 {"dd","cd","ff"};
std::vector<std::string> vec1;
// vec1.assign(list1.cbegin(), list1.cend());

void func9_43(string &s, const string &oldVal, const string &newVal){
    for(auto it = s.begin(); it != s.end()-oldVal.size();){
        if(oldVal == string(it,it+oldVal.size())){
            it=s.erase(it,it+oldVal.size());
            it=s.insert(it,newVal.begin(),newVal.end());
            it = it+newVal.size()-1;
        }
        it++;
    }
}

void func9_44(string &s, const string &oldVal, const string &newVal){
    for(int pos = 0; pos != s.size()-oldVal.size();){
        if(oldVal[0] == s[pos] && oldVal == s.substr(pos,oldVal.size()) ){
            s = s.replace(pos,oldVal.size(),newVal);
            pos = pos+newVal.size();
        }
        else
            pos++;
    }
}

void func9_45(string &s, const string& preS,const string& afterS){
    // auto it = preS.begin();
    // while (it!=preS.end())
    // {
    //     s.begin()=s.insert(s.begin(),*it);
    //     it++;
    //     s.begin()=s.begin()+1;
    // }
    s.insert(s.begin(),preS.begin(),preS.end());
    s.append(afterS);
}

void func9_46(string &s, const string& preS,const string& afterS){
    s.insert(0,preS);
    s.insert(s.size(),afterS);
}