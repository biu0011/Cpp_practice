#include "ten.h"
#include <cmath>
#include <map>
#include <time.h>
#include <random>

using namespace std;

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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 5);
    for(int n=0; n<100; ++n)
        cout << distrib(gen) << ' ' << endl;
    cout << '\n' << endl;

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

    
    return 0;

}