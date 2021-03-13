# Container_ostream
This c++ header makes it possible to print every container in c++ in the quickest way using the << operator overloading. You can also print nested containers like std::vector<std::array<int, 5>> or std::vector<std::tuple<int, std::string>>. Currently only for c++17 and above because of the tuple printing using some c++17 features. If you dont need tuple printing you can use the Container_ostreams_no_tuple.hpp for C++11 and above which are without tuple printing. test code can be found in test.cpp. 

## how to include
this header does not define the container includes like include vector this must be done before including Container_ostream.hpp. for example
```markdown
  #include <iostream>
  #include <vector>
  #include "Container_ostreams.hpp"
```
This will only define the vector ostream overload. This header file can be included again if another container type needs to be printed. for example:
```markdown
  #include <array>
  #include "Container_ostreams.hpp"
```
This will only define the array ostream overload and because the vector ostream overload was already included above will thus not be redefined.

## short explanation how printing will look.
containers std::array, std::vector and std::deque will be printed as follows:
```markdown
std::array<int, 4> arr = { 1, 2, 3, 4 };
std::cout << arr << std::endl; //----> will print [ 1, 2, 3, 4 ]

std::vector<int> vec = { 1, 2, 3, 4 };
std::cout << vec << std::endl; //----> will print [ 1, 2, 3, 4 ]
```
containers std::list and std::forward_list will be printed as follows 
```markdown
std::list<int> list = { 1, 2, 3, 4 };
std::cout << list << std::endl; //----> will print [ 1 2 3 4 ]
```
The elements are not seperated by a comma because these containers do not have a size() function or element access function and are printed by using a ranged based for loop. This makes it possible to differentiate them.

containers std::stack, std::queue and std::priority_queue will print as follows:
```markdown
std::deque<int> deque = { 1, 10, 2, 3, 4, 5, 7 };
  
std::stack<int> stack(deque);
std::cout << stack << std::endl; //----> will print [ 7 5 4 3 2 10 1 ]
  
std::queue<int> queue(deque);
std::cout << queue << std::endl; //----> will print [ 1 10 2 3 4 5 7]
```
these containers will print where the first element of the print is the first element that will be returned by top() or front() so std::stack will return the reverse because it is last in first out.

containers std::map, std::multimap, std::unordered_map and std::unordered_multimap will print as follows:
```markdown
std::map<uint64_t, std::string> map;
map.insert(std::make_pair(1, "hello"));
map.insert(std::make_pair(1, "hello"));
map.insert(std::make_pair(2, "hello"));
map.insert(std::make_pair(3, "hello"));
map.insert(std::make_pair(4, "hello"));
map.insert(std::make_pair(2, "hello"));
map.insert(std::make_pair(1, "hello"));
std::cout << map << std::endl; //----> will print [ 1:hello 2:hello 3:hello 4:hello ]
```
where the sign : indicates one element. the left side of the : is the key and the right side is the type.

containers std::set, std::multiset, std::unordered_set and std::unordered_multiset will print as follows:
```markdown
uint64_t temp_arr[] = { 1, 1, 2, 3, 4, 2, 1 };
std::set<uint64_t> set(temp_arr, temp_arr + 7);
std::cout << set << std::endl; //----> will print [ 1 2 3 4 ]
```
in addition to containers I also included a std::pair and std::tuple ostream overload these will print as follows:
```markdown
std::tuple<int, char, std::string, std::vector<std::array<int, 2>>> tuple = { 1, 'a', "hello", {{ 1, 2 }, { 3, 4 }, { 5, 6 }} };
std::pair<int, int> pair = {1, 2};
std::cout << tuple << std::endl; //----> will print (1, a, hello, [ [ 1, 2 ], [ 3, 4 ], [ 5, 6 ] ])
std::cout << pair << std::endl; //----> will print (1, 2)
```
## defines to edit printing
The printing of the containers can be slightly edited by defining one or both of the macros below: 
```markdown
#define CONTAINER_INDENTIFIER_FOR_PRETTY_CONTAINER_PRINTING
#define CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING
```
The macro CONTAINER_INDENTIFIER_FOR_PRETTY_CONTAINER_PRINTING will add an indentifier in front of every container for example a[ 1, 2, 3 ]. This indicates that the container is an std::array the identifiers are:
```markdown
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
```
The macro CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING will do the following which might make it easier to read:
```markdown
not [ 1 2 3 4 5 ] but [ {1} {2} {3} {4} {5} ]
not [ 1:a 2:b ] but [ {1:a} {2:b} ] 
 ```
In general [] indicates a container () indicates a tuple or pair  {} indicates a element in a container without size() function or element access and a , indicates size() function and element access.
