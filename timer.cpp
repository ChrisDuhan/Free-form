// for vector vs list random insert/delete

#include <iostream>
#include <vector>
#include <chrono>
#include <list>
#include <fstream>

int main() {
  const auto begin = std::chrono::high_resolution_clock::now(); // use steady_clock if (high_resolution_clock::is_steady == false)
  auto time = std::chrono::high_resolution_clock::now() - begin;
  std::cout << "Elapsed time: " << std::chrono::duration<double, std::milli>(time).count() << ".\n";
  
  return 0;
}
