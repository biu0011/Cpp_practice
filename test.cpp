// shuffle algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;
int genUniformRandom(int begin, int end) {
    // std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937_64 gen(std::random_device{}()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(begin, end);
   
    return distrib(gen);
}

int main () {
  // std::vector<int> foo {1,2,3,4,5};

  // // obtain a time-based seed:
  // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  // shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));

  // std::cout << "shuffled elements:";
  // for (int& x: foo) std::cout << ' ' << x;
  // std::cout << '\n';

  cout << genUniformRandom(1,12) << endl;


  return 0;
}