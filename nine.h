#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <fstream>

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

string func9_49(const string &filePath){
    const string sAscend = "bdfhk";
    const string sDscend = "gjpqtyFJLTY";
    ifstream ifs(filePath);
    string buf;
    string target;
    size_t maxSize = 0;

    if(ifs){
        while(ifs >> buf){
            if( buf.find_first_of(sAscend) == string::npos && buf.find_first_of(sDscend) == string::npos)
            {
                if(buf.size() > maxSize){
                    maxSize = buf.size();
                    target = buf;
                }
            }
        }

        
    }

    return target;

}

struct date{
    private:
        unsigned year,month,day;

        void converseOne(const string &s);
        void converseTwo(const string &s);
        void converseThree(const string &s);
        unsigned monthToNum(const string &s);
    public:
        date(const string &s){
            if(s.find_first_of(",")!=string::npos){
                converseOne(s);
            }else if(s.find_first_of("/")!=string::npos){
                converseTwo(s);
            }else if(s.find_first_of(" ")!=string::npos){
                converseThree(s);
            }else{
                cout << "the input date is wrong, new date failed " << endl;
            }
    }    
        void prinfDate();
};

void date::prinfDate(){
    cout << "Date is: " << endl; 
    cout << "year:" << year << " month:" << month << " day:" << day <<endl;
}

void date::converseOne(const string &s){
    year = stoi(s.substr(s.find_first_of(",")+1,4));
    month = monthToNum(s);
    day = stoi(s.substr(s.find_first_of("1234567890"),s.find_first_of(",")-s.rfind("/")));
}

void date::converseTwo(const string &s){
    year = stoi(s.substr(s.rfind("/")+1,4));
    day = stoi(s.substr(s.find("/")+1,s.rfind("/")-s.find("/")));
    month = stoi(s.substr(0,s.find_first_of("/")));
}

void date::converseThree(const string &s){
    year = stoi(s.substr(s.find_last_of(" ")+1,4));
    month = monthToNum(s);
    day = stoi(s.substr(s.find_first_of(" ")+1,s.find_last_of(" ")-s.find_first_of(" ")));
}

unsigned date::monthToNum(const string &s){
    if(s.find_first_of("Jan")!=string::npos) return 1;
    else if(s.find_first_of("Feb")!=string::npos) return 2;
    else if(s.find_first_of("Mar")!=string::npos) return 3;
    else if(s.find_first_of("Apr")!=string::npos) return 4;
    else if(s.find_first_of("May")!=string::npos) return 5;
    else if(s.find_first_of("Jun")!=string::npos) return 6;
    else if(s.find_first_of("Jul")!=string::npos) return 7;
    else if(s.find_first_of("Aug")!=string::npos) return 8;
    else if(s.find_first_of("Sep")!=string::npos) return 9;
    else if(s.find_first_of("Oct")!=string::npos) return 10;
    else if(s.find_first_of("Nov")!=string::npos) return 11;
    else if(s.find_first_of("Dec")!=string::npos) return 12;

    return 100;
}