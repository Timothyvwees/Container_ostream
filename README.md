# Container_ostream
This c++ header makes it possible to print every container in c++ in the quickest way using the << operator overloading. You can also print nested containers like std::vector<std::array<int, 5>> or std::vector<std::tuple<int, std::string>>. Currently only for c++17 and above because of the tuple printing using some c++17 features. If you dont need tuple printing you can use the Container_ostreams_no_tuple.hpp for C++11 and C++14 which are without tuple printing. test code can be found in main.cpp. this header does not define the container includes like include vector this must be done before including this header. for example

  #include iostream

  #include vector

  #include Container_ostreams.hpp
  
This will only define the vector ostream overload. This header file can be included again if another container type needs to be printed. for example:

  #include array
  
  #include Container_ostreams.hpp
  
This will only define the array ostream overload and because the vector ostream overload was already included above will thus not be redefined.

containers std::array, std::vector and std::deque like containers will be printed as follows [ 1, 2 ,3 ,4 ] seperated by a comma

containers std::list and std::forward_list like containers will be printed as follows [ 1 2 3 4 ] not seperated by a comma because these containers do not have a size or element access function and are printed by using a ranged based for loop. This makes it possible to differentiate them.

containers std::stack, std::queue and std::priority_queue will print as follows [ 1 2 3 4 ] these containers will print where the first element of the print is the first element that will be returned by top() or front() so std::stack will return the reverse [ 4 3 2 1 ] because it is last in first out.

containers std::map, std::multimap, std::unordered_map and std::unordered_multimap will print as follows [ 1:a 2:b 3:c ] where the : indicates one element. the left side of the : is the key and the right side is the type.

containers std::set, std::multiset, std::unordered_set and std::unordered_multiset will print as follows [ 1 2 3 4 ]

in addition to containers I also included a std::pair and std::tuple ostream overload these will print as follows (1, a, hello, 4, 5) or (a, 5)

The printing of the containers can be edited slightly by defining one or both of the macros below: 

  CONTAINER_INDENTIFIER_FOR_PRETTY_CONTAINER_PRINTING
  
  CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING
  
The macro CONTAINER_INDENTIFIER_FOR_PRETTY_CONTAINER_PRINTING will add an indentifier in front of every container for example a[ 1, 2, 3 ]. This indicates that the container is an std::array the identifiers are:

 std::array               = a
 
 std::vector              = v
 
 std::deque               = d
 
 std::list                = l
 
 std::forward_list        = fl
 
 std::stack               = st
 
 std::queue               = q
 
 std::priority_queue      = pq
 
 std::map                 = m
 
 std::set                 = s
 
 std::multimap            = Mm
 
 std::multiset            = Ms
 
 std::unordered_map       = Um
 
 std::unordered_multimap  = UMm
 
 std::unordered_set       = Us
 
 std::unordered_multiset  = UMs
 
The macro CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING will do instead of [ 1 2 3 4 5 ] do [ {1} {2} {3} {4} {5} ] which might make it easier to read.
