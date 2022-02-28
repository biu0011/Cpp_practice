#include "ten.h"
#include <cmath>
#include <map>
#include <time.h>
#include <random>
#include <numeric>
#include <iomanip>
#include <sstream>
#include<algorithm>
#include <chrono>       // std::chrono::system_clock
#include <random>       // std::default_random_engine

using namespace std;

void myfunction (int i) {  // function:
std::cout << ' ' << i;
}

/*
generate random num in [begin,end], uniform distribute
*/
int genUniformRandom(int begin, int end) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(begin, end);
   
    return distrib(gen);
}

int main(){
    //10.6
    // vector<int> vect;
    // fill_n(back_inserter(vect),10,0);

    //10.11
    // vector<string> words{"the","quicl","red","fox","jumps","over","the","slow","red","turtle"};
    // func10_11(words);
    // return 0;
    
    //10.13
    // auto v = std::vector<std::string>{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    // func10_13(v);

    // cout <<"-------test:" << fmod(5777.33455, 1.0f) <<endl;

    //test map

    // 定义一个map对象
    // class T{
    //     public:
    //     int getInt(){
    //         return ti;
    //     }
    //     private:
    //     int ti = 0;
    // };

    // map<int, T> mapStudent;
    
    // int i = mapStudent[123].getInt();
    // cout << i << endl;


    // std::string s = "123454";
    // cout << s.substr(2) << endl;

    // std::random_device rd;
    // // for(int n=0; n<20000; ++n)
    // //     cout << rd() << endl;

    // std::default_random_engine engine(rd());
    // std::uniform_int_distribution<> dis(10, 20); 
    // for (int n = 0; n < 10; n++) 
    //     std::cout << dis(engine) << " " << std::endl;

    //平均分布
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> distrib(1, 5);
    // for(int n=0; n<100; ++n)
    //     cout << distrib(gen) << ' ' << endl;
    // cout << '\n' << endl;

    // std::vector<std::string> v
    //     {
    //     "1234", "1234", "1234", "hi~", "alan", "alan", "cp"
    // };
    // std::cout << "ex10.16: ";
    // biggies(v, 3);
    // std::cout << std::endl;

    // vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	// string s("12345");
    // auto it = find_if(v.begin(), v.end(), bind(check_size, _1, s));
    // if(it!=v.end())
    //     cout << *it <<endl;

    // double a = 1701.0000, b = 31.25;
    // std::cout << fmod(a, 1.0f) << endl;
    // cout << int(fmod(a, 1.0f) >0) << endl;

    // float val = 0.777779;

    // float rounded_down = floorf(val * 10000) / 10000;   /* Result: 37.77 */
    // float nearest = roundf(val * 10000) / 10000;  /* Result: 37.78 */
    // float rounded_up = ceilf(val * 10000) / 10000;      /* Result: 37.78 */
    // string s = to_string(nearest);

    // cout << rounded_down << endl;
    // cout << s.erase ( s.find_last_not_of('0') + 1, std::string::npos ) << endl;
    // cout << rounded_up << endl;



    int TrialNum = 24;   
    vector<int> cueIdxVec, targetIdxVecU, targetIdxVecD, targetIdxVec; 
    vector<int> cueIdxArry;
    map<int,int> cueToTargetIdxMap;    

    //initial index of target
    for (int i = 0; i < TrialNum; i++) {
        if (i < TrialNum / 8) {
            targetIdxVecU.push_back(1);
            continue;
        }
        else if (i < TrialNum / 8 * 2) {
            targetIdxVecU.push_back(2);
            continue;
        }
        else if (i < TrialNum / 8 * 3) {
            targetIdxVecU.push_back(3);
            continue;
        }
        else if (i < TrialNum / 8 * 4) {
            targetIdxVecU.push_back(4);
            continue;
        }
        else if (i < TrialNum / 8 * 5) {
            targetIdxVecD.push_back(5);
            continue;
        }
        else if (i < TrialNum / 8 * 6) {
            targetIdxVecD.push_back(6);
            continue;
        }
        else if (i < TrialNum / 8 * 7) {
            targetIdxVecD.push_back(7);
            continue;
        }
        else if (i < TrialNum        ) {
            targetIdxVecD.push_back(8);
            continue;
        }
    }



    //initial index of cue  & associate cue idx with target value
    for (int i = 0;                i < TrialNum / 6;     i++) {
        cueIdxVec.push_back(4);
        cueIdxArry.push_back(i);
        int temp = genUniformRandom(0,targetIdxVecD.size()-1);
        cueToTargetIdxMap[i] = targetIdxVecD[temp];
        targetIdxVecD.erase(targetIdxVecD.begin() + temp);
    }
    for (int i = TrialNum / 6;     i < TrialNum / 3;     i++) {
        cueIdxVec.push_back(3);
        cueIdxArry.push_back(i);
        int temp = genUniformRandom(0,targetIdxVecU.size()-1);
        cueToTargetIdxMap[i] = targetIdxVecU[temp];
        targetIdxVecU.erase(targetIdxVecU.begin() + temp);
    }
    for (int i = TrialNum / 3;     i < TrialNum / 3 * 2; i++) {
        cueIdxVec.push_back(2);
        cueIdxArry.push_back(i);
    }
    for (int i = TrialNum / 3 * 2; i < TrialNum ; i++) {
        cueIdxVec.push_back(1);
        cueIdxArry.push_back(i);
    }

    //concat two vector
    targetIdxVec.reserve( targetIdxVecU.size() + targetIdxVecD.size() ); // preallocate memory
    targetIdxVec.insert( targetIdxVec.end(), targetIdxVecU.begin(), targetIdxVecU.end() );
    targetIdxVec.insert( targetIdxVec.end(), targetIdxVecD.begin(), targetIdxVecD.end() );

    for (int i = TrialNum / 3;     i < TrialNum; i++) {
        int temp = genUniformRandom(0,targetIdxVec.size()-1);
        cueToTargetIdxMap[i] = targetIdxVec[temp];
        targetIdxVec.erase(targetIdxVec.begin() + temp);
    }
        
        
    
    cout << "\nbefore shuffle" <<endl;
    for_each (cueIdxVec.begin(), cueIdxVec.end(), myfunction);
    cout << endl;
    for_each (cueIdxArry.begin(), cueIdxArry.end(), myfunction);
  

    //shuffle cue
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (cueIdxArry.begin(), cueIdxArry.end(), std::default_random_engine(seed));

    cout << "\n after shuffle : " << endl;
    for(int i=0; i != TrialNum; i++){
        cout << " " << cueIdxVec[cueIdxArry[i]];
    }
    cout << endl;
    for_each (cueIdxArry.begin(), cueIdxArry.end(), myfunction);

    
    // cout <<"\n1: " <<count(cueIdxVec.begin(), cueIdxVec.end(), 1)<<endl;
    // cout <<"2: " <<count(cueIdxVec.begin(), cueIdxVec.end(), 2)<<endl;
    // cout <<"3: " <<count(cueIdxVec.begin(), cueIdxVec.end(), 3)<<endl;
    // cout <<"4: " <<count(cueIdxVec.begin(), cueIdxVec.end(), 4)<<endl;

// show map content:
    cout << "\n show map" << endl;
//   for (std::map<int,int>::iterator it=cueToTargetIdxMap.begin(); it!=cueToTargetIdxMap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
    for(int i = 0; i < TrialNum; i++){
        cout << cueIdxVec[cueIdxArry[i]] << " => "<< cueToTargetIdxMap[cueIdxArry[i]] << endl;
        //check the map
        if(cueIdxVec[cueIdxArry[i]] == 3 && cueToTargetIdxMap[cueIdxArry[i]] > 4 ){
            cout << "wrong!! " << endl;
        }
        if(cueIdxVec[cueIdxArry[i]] == 4 && cueToTargetIdxMap[cueIdxArry[i]] <= 4 ){
            cout << "wrong!! " << endl;
        }
    }




    
    // cout <<"\n1: " <<count(targetIdxVecU.begin(), targetIdxVecU.end(), 1)<<endl;
    // cout <<"2: " <<count(targetIdxVecU.begin(), targetIdxVecU.end(), 2)<<endl;
    // cout <<"3: " <<count(targetIdxVecU.begin(), targetIdxVecU.end(), 3)<<endl;
    // cout <<"4: " <<count(targetIdxVecU.begin(), targetIdxVecU.end(), 4)<<endl;

    // for_each (targetIdxVecU.begin(), targetIdxVecU.end(), myfunction);
    // cout << endl;
    // for_each (targetIdxVecD.begin(), targetIdxVecD.end(), myfunction);
    // cout << endl;


    return 0;
    
}