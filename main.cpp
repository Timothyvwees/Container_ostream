//
//  main.cpp
//  Punto banco
//
//  Created by Timothy van Wees on 03/03/2021.
//

#include <iostream>

#include <thread>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>


//#define CONTAINER_INDENTIFIER_FOR_PRETTY_CONTAINER_PRINTING
//#define CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING
#include "Container_ostreams.hpp"
#include "done.hpp"

typedef std::tuple<int, char, std::string, std::vector<std::array<int, 2>>> test_tuple;

int main() {
	test_tuple tuple00 = { 1, 'a', "hello", {{ 1, 2 }, { 3, 4 }, { 5, 6 }} };
	test_tuple tuple01 = { 2, 'b', "hello", {{ 1, 2 }, { 3, 4 }, { 5, 6 }} };
	test_tuple tuple02 = { 3, 'c', "hello", {{ 1, 2 }, { 3, 4 }, { 5, 6 }} };
	test_tuple tuple03 = { 4, 'd', "hello", {{ 1, 2 }, { 3, 4 }, { 5, 6 }} };

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

	std::map<uint64_t, std::string> map0;
	map0.insert(std::make_pair(1, "hello"));
	map0.insert(std::make_pair(1, "hello"));

	map0.insert(std::make_pair(2, "hello"));
	map0.insert(std::make_pair(3, "hello"));
	map0.insert(std::make_pair(4, "hello"));
	map0.insert(std::make_pair(2, "hello"));
	map0.insert(std::make_pair(1, "hello"));

	std::map<uint64_t, std::string, std::greater<uint64_t>> map1;
	map1.insert(std::make_pair(1, "hello"));
	map1.insert(std::make_pair(1, "hello"));

	map1.insert(std::make_pair(2, "hello"));
	map1.insert(std::make_pair(3, "hello"));
	map1.insert(std::make_pair(4, "hello"));
	map1.insert(std::make_pair(2, "hello"));
	map1.insert(std::make_pair(1, "hello"));

	std::map<uint64_t, test_tuple, std::greater<uint64_t>> map2;
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

	uint64_t temp_arr[] = { 1, 1, 2, 3, 4, 2, 1 };

	std::set<uint64_t> set(temp_arr, temp_arr + 7) ;
	std::multiset<uint64_t> multi_set(temp_arr, temp_arr + 7);

	std::unordered_set<uint64_t, std::hash<uint64_t>, std::equal_to<uint64_t>> unordered_set(temp_arr, temp_arr + 7);
	std::unordered_multiset<uint64_t> unordered_multiset(temp_arr, temp_arr + 7);

	std::pair<int, int> pair = {1, 2};

	std::cout << "array0: " << array0 << std::endl;
	std::cout << "array1: " << array1 << std::endl;
	std::cout << std::endl;

	std::cout << "vector0: " << vector0 << std::endl;
	std::cout << "vector1: " << vector1 << std::endl;
	std::cout << std::endl;

	std::cout << "deque0: " << deque0 << std::endl;
	std::cout << "deque1: " << deque1 << std::endl;
	std::cout << std::endl;

	std::cout << "list0: " << list0 << std::endl;
	std::cout << "list1: " << list1 << std::endl;
	std::cout << std::endl;

	std::cout << "flist0: " << flist0 << std::endl;
	std::cout << "flist1: " << flist1 << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "stack0: " << stack0 << std::endl;
	std::cout << "queue0: " << queue0 << std::endl;
	std::cout << "pqueue0: " << pqueue0 << std::endl;
	std::cout << "pqueue1: " << pqueue1 << std::endl;
	std::cout << std::endl;

	std::cout << "map0: " << map0 << std::endl;
	std::cout << "map1: " << map1 << std::endl;
	std::cout << "map2: " << map2 << std::endl;
	std::cout << "unordered_map: " << unordered_map << std::endl;
	std::cout << "multimap: " << multimap << std::endl;
	std::cout << "unordered_multimap: " << unordered_multimap << std::endl;
	std::cout << std::endl;

	std::cout << "set: " << set << std::endl;
	std::cout << "multi_set: " << multi_set << std::endl;
	std::cout << "unordered_set: " << unordered_set << std::endl;
	std::cout << "unordered_multiset: " << unordered_multiset << std::endl;
	std::cout << std::endl;

	std::cout << "pair: " << pair << std::endl;
	return 0;
}