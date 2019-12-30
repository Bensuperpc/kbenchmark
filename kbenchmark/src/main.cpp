#include <iostream>
#include <bits/stdc++.h> 
#include "odd/odd.hpp"
#include "my_chrono.hpp"
 
int main()
{
  my_chrono chrono;
  chrono.start();
  std::cout << "Hello World!" << std::endl;
  chrono.stop();
  std::cout << "Time :" << chrono.elapsed_ms() << " ns" <<  std::endl;
  return 0;
}