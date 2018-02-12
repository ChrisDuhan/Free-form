#include <iostream>
#include <vector>
#include <chrono>
#include <list>
#include <fstream>
#include <random>

int main(int argc, char *argv[]) {
  if ( argc != 5 ) // argc should be 2 for correct execution
    // argv[0] assumed to be the program name
    std::cout <<"usage: " << argv[0] << " <output file name> <vec/list size> <ins/del pairs> <num of tests to average>\n";
  else {
    // assumed argv[1] is the filename to write
    std::ofstream the_file(argv[1]);
    if (!the_file.is_open()) {
      std::cout<<"Could not open outfile\n";
      return 0;
    }
    else {
      std::vector<int> vec;
      std::list<int> lst;
      std::random_device randgen;
      std::mt19937 mt(randgen());
      std::uniform_real_distribution<int> dist(1, INT_MAX);
      int size = argv[2];
      
      for (int i = 0; i < size; ++i) {
        vec.push_back(dist(mt));
        lst.push_back(vec[i]);
      }
      
      const auto vecbegin = std::chrono::high_resolution_clock::now(); // use steady_clock if high_resolution_clock::is_steady is false
      auto vectime = std::chrono::high_resolution_clock::now() - vecbegin;
      std::cout << "Elapsed time: " << std::chrono::duration<double, std::milli>(vectime).count() << ".\n";
    }
  }
  return 0;
}
