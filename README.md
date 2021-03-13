# Container_ostream
This c++ header makes it possible to print every container in c++ using the << operator overloading. You can also print combined containers like std::vector<std::array<int, 5>> or std::vector<std::tuple<int, std::string>>. Currently only for c++17 and above because of the tuple printing using some c++17 features. If you dont need tuple printing you can use the Container_ostreams.hpp for C++11 and C++14 which are without tuple printing. Some test coded is also included in the main.cpp. this header does not define the container includes like #include<vector> this must be done before including this header. for example:

#include <iostream>
#include <vector> 
#include "Container_ostreams.hpp"
  
This will only define the vector ostream overload. This header file can be included again if another container needs to be printed. for example:

#include <iostream>
#include <vector> 
#include "Container_ostreams.hpp"

#include <array> 
#include "Container_ostreams.hpp"
  
This will only define the array ostream overload and because the vector ostream overload was already included above will thus not be redefined.

