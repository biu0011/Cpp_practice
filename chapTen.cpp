#include "ten.h"

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
    auto v = std::vector<std::string>{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    func10_13(v);
}