
//#define USE_CONTAINER_OSTREAMS_INDENTIFIERS
//#define USE_CONTAINER_OSTREAMS_SPACES

#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <vector>
#include <iostream>
#include <array>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <forward_list>
#include <thread>
#include <string>
#include "container_ostreams.hpp"

typedef std::tuple<int, char, int> test_tuple;
typedef std::tuple<std::forward_list<test_tuple>, std::map<uint64_t, std::string, std::greater<uint64_t>>, std::priority_queue<int, std::vector<int>, std::greater<int> >> test_tuple_complex;

int main() {
    test_tuple tuple00 = { 1, 'a', 2 };
    test_tuple tuple01 = { 2, 'b', 3 };
    test_tuple tuple02 = { 3, 'c', 4 };
    test_tuple tuple03 = { 4, 'd', 5 };

    std::array<int, 0> array_empty;
    std::array<int, 1> array_one = { 1 };
    std::array<int, 5> array0 = { 1, 2, 3, 4, 5 };
    std::array<test_tuple, 4> array1 = { tuple00 , tuple01 , tuple02 , tuple03 };

    std::vector<int> vector0 = { 1, 2, 3, 4, 5 };
    std::vector<test_tuple> vector1 = { tuple00 , tuple01 , tuple02 , tuple03 };

    std::deque<int> deque0 = { 1, 2, 3, 4, 5 };
    std::deque<test_tuple> deque1 = { tuple00 , tuple01 , tuple02 , tuple03 };

    std::list<int> list0 = { 1, 2, 3, 4, 5 };
    std::list<test_tuple> list1 = { tuple00 , tuple01 , tuple02 , tuple03 };

    std::forward_list<int> flist0 = { 1, 2, 3, 4, 5, 6 };
    std::forward_list<test_tuple> flist1 = { tuple00 , tuple01 , tuple02 , tuple03 };

    std::stack<int> stack0;
    stack0.push(1);
    stack0.push(1);
    stack0.push(2);
    stack0.push(3);
    stack0.push(4);
    stack0.push(2);
    stack0.push(1);

    std::queue<int> queue0;
    queue0.push(1);
    queue0.push(1);
    queue0.push(2);
    queue0.push(3);
    queue0.push(4);
    queue0.push(2);
    queue0.push(1);

    std::priority_queue<int> pqueue0;
    pqueue0.push(1);
    pqueue0.push(1);
    pqueue0.push(2);
    pqueue0.push(3);
    pqueue0.push(4);
    pqueue0.push(2);
    pqueue0.push(1);

    std::priority_queue<int, std::vector<int>, std::greater<int> > pqueue1;
    pqueue1.push(1);
    pqueue1.push(1);
    pqueue1.push(2);
    pqueue1.push(3);
    pqueue1.push(4);
    pqueue1.push(2);
    pqueue1.push(1);
    //
    std::map<uint64_t,char> map0;
    map0.insert(std::make_pair(1, 'a'));
    map0.insert(std::make_pair(1, 'b'));
    map0.insert(std::make_pair(2, 'c'));
    map0.insert(std::make_pair(3, 'd'));
    map0.insert(std::make_pair(4, 'e'));
    map0.insert(std::make_pair(2, 'f'));
    map0.insert(std::make_pair(1, 'g'));

    std::map<uint64_t, std::string, std::greater<uint64_t>> map1;
    map1.insert(std::make_pair(1, "hello"));
    map1.insert(std::make_pair(1, "hello"));
    map1.insert(std::make_pair(2, "hello"));
    map1.insert(std::make_pair(3, "hello"));
    map1.insert(std::make_pair(4, "hello"));
    map1.insert(std::make_pair(2, "hello"));
    map1.insert(std::make_pair(1, "hello"));

    std::map<uint64_t, test_tuple, std::less<uint64_t>> map2;
    map2.insert(std::make_pair(1, tuple00));
    map2.insert(std::make_pair(1, tuple00));
    map2.insert(std::make_pair(2, tuple01));
    map2.insert(std::make_pair(3, tuple02));
    map2.insert(std::make_pair(4, tuple03));
    map2.insert(std::make_pair(2, tuple01));
    map2.insert(std::make_pair(1, tuple00));

    std::multimap<uint64_t, std::string> multimap;
    multimap.insert(std::make_pair(1, "hello"));
    multimap.insert(std::make_pair(1, "hello"));
    multimap.insert(std::make_pair(2, "hello"));
    multimap.insert(std::make_pair(3, "hello"));
    multimap.insert(std::make_pair(4, "hello"));
    multimap.insert(std::make_pair(2, "hello"));
    multimap.insert(std::make_pair(1, "hello"));

    std::unordered_map<uint64_t, std::string> unordered_map;
    unordered_map.insert(std::make_pair(1, "hello"));
    unordered_map.insert(std::make_pair(1, "hello"));
    unordered_map.insert(std::make_pair(2, "hello"));
    unordered_map.insert(std::make_pair(3, "hello"));
    unordered_map.insert(std::make_pair(4, "hello"));
    unordered_map.insert(std::make_pair(2, "hello"));
    unordered_map.insert(std::make_pair(1, "hello"));

    std::unordered_multimap<uint64_t, std::string> unordered_multimap;
    unordered_multimap.insert(std::make_pair(1, "hello"));
    unordered_multimap.insert(std::make_pair(1, "hello"));
    unordered_multimap.insert(std::make_pair(2, "hello"));
    unordered_multimap.insert(std::make_pair(3, "hello"));
    unordered_multimap.insert(std::make_pair(4, "hello"));
    unordered_multimap.insert(std::make_pair(2, "hello"));
    unordered_multimap.insert(std::make_pair(1, "hello"));


    std::unordered_multimap<uint64_t, std::string> unordered_multimap_one;
    unordered_multimap_one.insert(std::make_pair(1, "hello"));

    std::unordered_multimap<uint64_t, std::string> unordered_multimap_empty;

    uint64_t temp_arr[] = { 1, 1, 2, 3, 4, 2, 1 };

    std::set<uint64_t> set(temp_arr, temp_arr + 7);
    std::multiset<uint64_t> multi_set(temp_arr, temp_arr + 7);

    std::unordered_set<uint64_t, std::hash<uint64_t>, std::equal_to<uint64_t>> unordered_set(temp_arr, temp_arr + 7);
    std::unordered_multiset<uint64_t> unordered_multiset(temp_arr, temp_arr + 7);

    std::pair<int, std::string> pair = { 1, "Hello" };

    test_tuple_complex test_tuple_complex1 = { flist1, map1, pqueue1 };

    std::map<uint64_t, test_tuple_complex> map_complex;
    map_complex.insert(std::make_pair(uint64_t{ 1 }, test_tuple_complex1));
    map_complex.insert(std::make_pair(uint64_t{ 2 }, test_tuple_complex1));
    map_complex.insert(std::make_pair(uint64_t{ 3 }, test_tuple_complex1));

    std::cout << "array0: " << array0 << std::endl;
    std::cout << "array1: " << array1 << std::endl;
    std::cout << "array0: " << array_empty << std::endl;
    std::cout << "array0: " << array_one << std::endl;
    std::cout << std::endl;

    std::cout << "vector0: " << vector0 << std::endl;
    std::cout << "vector1: " << vector1 << std::endl;
    std::cout << std::endl;

    std::cout << "deque0: " << deque0 << std::endl;
    std::cout << "deque1: " << deque1 << std::endl;
    std::cout << std::endl;
    //auto t1 = std::chrono::steady_clock::now();
    //for (std::size_t i = 0; i < 1000; i++) {

    std::cout << "list0: " << list0 << std::endl;
    std::cout << "list1: " << list1 << std::endl;
    std::cout << std::endl;

    std::cout << "flist0: " << flist0 << std::endl;
    std::cout << "flist1: " << flist1 << std::endl;
    std::cout << std::endl;

    std::cout << "stack0: " << stack0 << std::endl;
    std::cout << "queue0: " << queue0 << std::endl;
    std::cout << "pqueue0: " << pqueue0 << std::endl;
    std::cout << "pqueue1: " << pqueue1 << std::endl;
    std::cout << std::endl;

    std::cout << "map0: " << map0 << std::endl;
    std::cout << "hello" << std::endl;
    std::cout << "map1: " << map1 << std::endl;
    std::cout << "map2: " << map2 << std::endl;
    std::cout << "unordered_map: " << unordered_map << std::endl;
    std::cout << "multimap: " << multimap << std::endl;
    std::cout << "unordered_multimap: " << unordered_multimap << std::endl;
    std::cout << unordered_multimap_one << std::endl;
    std::cout << unordered_multimap_empty << std::endl;
    std::cout << std::endl;

    std::cout << "set: " << set << std::endl;
    std::cout << "multi_set: " << multi_set << std::endl;
    std::cout << "unordered_set: " << unordered_set << std::endl;
    std::cout << "unordered_multiset: " << unordered_multiset << std::endl;
    std::cout << std::endl;
    //}
    //auto t2 = std::chrono::steady_clock::now();
    //auto dur = t2 - t1;
    //std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << std::endl;
    std::cout << "pair: " << pair << std::endl;
    std::cout << "tuple: " << tuple00 << std::endl;
    std::cout << "map_complex: " << map_complex << std::endl;

    return 0;
}
