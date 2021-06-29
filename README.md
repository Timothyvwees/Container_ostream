# Container ostreams
This c++ header makes it possible to print every std container in c++ using << operator overloading. The overload functions are programmed to be highly efficient. You can also print nested containers like std::vector<std::array<int, 5>> or std::vector<std::tuple<int, std::string>>. Currently the tuple printing is only for c++20.

## how to include
You can include container_ostreams.hpp in your project.

## short explanation how printing will look.
containers std::array, std::vector and std::deque will be printed as follows:
```markdown
std::array<int, 4> arr = { 1, 2, 3, 4 };
std::cout << arr << std::endl; //----> will print [1, 2, 3, 4]

std::vector<int> vec = { 1, 2, 3, 4 };
std::cout << vec << std::endl; //----> will print [1, 2, 3, 4]
```
containers std::list and std::forward_list will be printed as follows 
```markdown
std::list<int> list = { 1, 2, 3, 4 };
std::cout << list << std::endl; //----> will print [1, 2, 3, 4]
```

containers std::stack, std::queue and std::priority_queue will print as follows:
```markdown
std::deque<int> deque = { 1, 10, 2, 3, 4, 5, 7 };
std::stack<int> stack(deque);
std::cout << stack << std::endl; //----> will print [7, 5, 4, 3, 2, 10, 1]
  
std::queue<int> queue(deque);
std::cout << queue << std::endl; //----> will print [1, 10, 2, 3, 4, 5, 7]
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
std::cout << map << std::endl; //----> will print [(1:hello), (2:hello), (3:hello), (4:hello)]
```
where the sign : indicates one pair.

containers std::set, std::multiset, std::unordered_set and std::unordered_multiset will print as follows:
```markdown
uint64_t temp_arr[] = { 1, 1, 2, 3, 4, 2, 1 };
std::set<uint64_t> set(temp_arr, temp_arr + 7);
std::cout << set << std::endl; //----> will print [1, 2, 3, 4]
```
in addition to containers I also included a std::pair and std::tuple ostream overload these will print as follows:
```markdown
std::tuple<int, char, std::string, std::vector<std::array<int, 2>>> tuple = { 1, 'a', "hello", {{ 1, 2 }, { 3, 4 }, { 5, 6 }} };
std::pair<int, int> pair = {1, 2};
std::cout << tuple << std::endl; //----> will print (1, a, hello, [[1, 2], [3, 4], [5, 6]])
std::cout << pair << std::endl; //----> will print (1:2)
```
