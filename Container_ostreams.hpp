//
//  Container_ostreams.hpp
//  Created by Timothy van Wees on 23/02/2021.
//

#pragma once

#ifndef CONTAINER_OSTREAMS_GUARD
#define CONTAINER_OSTREAMS_GUARD

#include <iostream>

#ifdef USE_CONTAINER_OSTREAMS_INDENTIFIERS
#define ARRAY_INDENTIFIER << "a"
#define VECTOR_INDENTIFIER << "v"
#define DEQUE_INDENTIFIER << "d"
#define LIST_INDENTIFIER << "l"
#define FLIST_INDENTIFIER << "fl"

#define STACK_INDENTIFIER << "st"
#define QUEUE_INDENTIFIER << "q"
#define PQUEUE_INDENTIFIER << "pq"

#define MAP_INDENTIFIER << "m"
#define MULTIMAP_INDENTIFIER << "Mm"
#define SET_INDENTIFIER << "s"
#define MULTISET_INDENTIFIER << "Ms"

#define UNORDEDED_MAP_INDENTIFIER << "Um"
#define UNORDEDED_MULTIMAP_INDENTIFIER << "UMm"
#define UNORDEDED_SET_INDENTIFIER << "Us"
#define UNORDEDED_MULTISET_INDENTIFIER << "UMs"
#else
#define ARRAY_INDENTIFIER
#define VECTOR_INDENTIFIER
#define DEQUE_INDENTIFIER
#define LIST_INDENTIFIER
#define FLIST_INDENTIFIER

#define STACK_INDENTIFIER
#define QUEUE_INDENTIFIER
#define PQUEUE_INDENTIFIER

#define MAP_INDENTIFIER
#define MULTIMAP_INDENTIFIER
#define SET_INDENTIFIER
#define MULTISET_INDENTIFIER

#define UNORDEDED_MAP_INDENTIFIER
#define UNORDEDED_MULTIMAP_INDENTIFIER
#define UNORDEDED_SET_INDENTIFIER
#define UNORDEDED_MULTISET_INDENTIFIER
#endif

#ifdef USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR
#define USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << "{"
#define USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END << "} "
#else
#define USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN
#define USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END << " "
#endif

#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_SEQUENCE_OSTREAM_CONTAINER_OVERLOADS)
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
/*----------------------These are all the sequence containers------------------*/
template <class _Type, std::size_t _Size>
std::ostream& operator<<(std::ostream& os, const std::array<_Type, _Size>& arr);

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::vector<_Type, _Alloc>& vec);

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::deque<_Type, _Alloc>& deq);

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::list<_Type, _Alloc>& list);

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::forward_list<_Type, _Alloc>& flist);
/*------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_ADAPTERS_OSTREAM_CONTAINER_OVERLOADS)
#include <queue>
#include <stack>
/*--------------------These are all the container adapters-----------------------*/
template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::stack<_Type, _Container>& stack);

template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::queue<_Type, _Container>& queue);

template <class _Type, class _Container, class _Compare>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<_Type, _Container, _Compare>& pqueue);
/*-------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_ASSOCIATIVE_OSTREAM_CONTAINER_OVERLOADS)
#include <map>
#include <set>
/*----------------------These are all the associative containers-----------------*/
template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::map<_Key, _Types, _Compare, _Alloc>& map);

template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multimap<_Key, _Types, _Compare, _Alloc>& multimap);

template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::set<_Key, _Compare, _Alloc>& set);

template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multiset<_Key, _Compare, _Alloc>& multiset);
/*-------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_UNORDERED_ASSOCIATIVE_OSTREAM_CONTAINER_OVERLOADS)
#include <unordered_map>
#include <unordered_set>
/*-------------------These are all the unordered associative containers----------*/
template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_map);

template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_multimap);

template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<_Key, _Hasher, _Keyeq, _Alloc>& unordered_set);

template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<_Key, _Hasher, _Keyeq, _Alloc>& unordered_multiset);
/*-------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_TUPLE_OSTREAM_CONTAINER_OVERLOADS)
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#else
#error this header only supports c++17 and above for tuple printing
#endif

#include <tuple>
#include <utility>
/*--------------------These are all the tuples types-----------------------------*/
template <std::size_t tuple_pos, class... _Types>
constexpr void print_tuple_excluding_last(std::ostream& os, const std::tuple<_Types...>& tuple);

template<class... _Types>
std::ostream& operator<<(std::ostream& os, const std::tuple<_Types...>& tuple);

template<class _Type1, class _Type2>
std::ostream& operator<<(std::ostream& os, const std::pair<_Type1, _Type2>& pair);
/*-------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_SEQUENCE_OSTREAM_CONTAINER_OVERLOADS)
/*----------------------These are all the sequence containers--------------------*/
template <class _Type, std::size_t _Size>
std::ostream& operator<<(std::ostream& os, const std::array<_Type, _Size>& arr) {
	os ARRAY_INDENTIFIER << "[ ";
	for (std::size_t i = 0ULL; i < (arr.size() - 1ULL); i++) {
		os << arr[i] << ", ";
	}
	os << arr.back() << " ]";
	return os;
}

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::vector<_Type, _Alloc>& vec) {
	os VECTOR_INDENTIFIER << "[ ";
	for (std::size_t i = 0ULL; i < (vec.size() - 1ULL); i++) {
		os << vec[i] << ", ";
	}
	os << vec.back() << " ]";
	return os;
}

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::deque<_Type, _Alloc>& deq) {
	os DEQUE_INDENTIFIER << "[ ";
	for (std::size_t i = 0ULL; i < (deq.size() - 1ULL); i++) {
		os << deq[i] << ", ";
	}
	os << deq.back() << " ]";
	return os;
}

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::list<_Type, _Alloc>& list) {
	os LIST_INDENTIFIER << "[ ";
	for (const auto& element : list) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::forward_list<_Type, _Alloc>& flist) {
	os FLIST_INDENTIFIER << "[ ";
	for (const auto& element : flist) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}
/*-----------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_ADAPTERS_OSTREAM_CONTAINER_OVERLOADS)
/*--------------------These are all the container adapters-----------------------*/
template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::stack<_Type, _Container>& stack) {
	auto stack_copy = stack;

	os STACK_INDENTIFIER << "[ ";
	while (stack_copy.size() > 1ULL) {
		os << stack_copy.top() << ", ";
		stack_copy.pop();
	}
	os << stack_copy.top() << " ]";
	return os;
}

template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::queue<_Type, _Container>& queue) {
	auto queue_copy = queue;

	os QUEUE_INDENTIFIER << "[ ";
	while (queue_copy.size() > 1ULL) {
		os << queue_copy.front() << ", ";
		queue_copy.pop();
	}
	os << queue_copy.front() << " ]";
	return os;
}

template <class _Type, class _Container, class _Compare>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<_Type, _Container, _Compare>& pqueue) {
	auto pqueue_copy = pqueue;

	os PQUEUE_INDENTIFIER << "[ ";
	while (pqueue_copy.size() > 1ULL) {
		os << pqueue_copy.top() << ", ";
		pqueue_copy.pop();
	}
	os << pqueue_copy.top() << " ]";
	return os;
}
/*-------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_ASSOCIATIVE_OSTREAM_CONTAINER_OVERLOADS)
/*----------------------These are all the associative containers---------------*/
template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::map<_Key, _Types, _Compare, _Alloc>& map){
	os MAP_INDENTIFIER << "[ ";
	for (const auto& element : map) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element.first << ":" << element.second USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}

template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multimap<_Key, _Types, _Compare, _Alloc>& multimap){
	os MULTIMAP_INDENTIFIER << "[ ";

	for (const auto& element : multimap) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element.first << ":" << element.second USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}

template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::set<_Key, _Compare, _Alloc>& set) {
	os SET_INDENTIFIER << "[ ";
	for (const auto& element : set) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}

template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multiset<_Key, _Compare, _Alloc>& multiset) {
	os MULTISET_INDENTIFIER << "[ ";
	for (const auto& element : multiset) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}
/*------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_UNORDERED_ASSOCIATIVE_OSTREAM_CONTAINER_OVERLOADS)
/*-----------------These are all the unordered associative containers-----------*/
template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_map){
	os UNORDEDED_MAP_INDENTIFIER << "[ ";
	for (const auto& element : unordered_map) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element.first << ":" << element.second USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}

template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_multimap){
	os UNORDEDED_MULTIMAP_INDENTIFIER << "[ ";
	for (const auto& element : unordered_multimap) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element.first << ":" << element.second USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}

template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<_Key, _Hasher, _Keyeq, _Alloc>& unordered_set) {
	os UNORDEDED_SET_INDENTIFIER << "[ ";
	for (const auto& element : unordered_set) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}

template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<_Key, _Hasher, _Keyeq, _Alloc>& unordered_multiset) {
	os UNORDEDED_MULTISET_INDENTIFIER << "[ ";
	for (const auto& element : unordered_multiset) {
		os USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_BEGIN << element USE_CONTAINER_OSTREAMS_ELEMENT_SEPERATOR_END;
	}
	os << "]";
	return os;
}
/*-------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_TUPLE_OSTREAM_CONTAINER_OVERLOADS)
/*--------------------These are all the tuples types-----------------------------*/
template <std::size_t tuple_pos = 0ULL, class... _Types>
constexpr void print_tuple_excluding_last(std::ostream& os, const std::tuple<_Types...>& tuple) {
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
	if constexpr (tuple_pos == (sizeof...(_Types) - 1ULL)) {
#else
	if (tuple_pos == (sizeof...(_Types) - 1ULL)) {
#endif
		return;
	}
	else {
		os << std::get<tuple_pos>(tuple) << ", ";
		print_tuple_excluding_last<tuple_pos + 1ULL>(os, tuple);
	}
}

template<class... _Types>
std::ostream& operator<<(std::ostream & os, const std::tuple<_Types...>&tuple) {
	const auto tuple_last_type = std::tuple_size<std::tuple<_Types...>>::value - 1ULL;
	os << "(";
	print_tuple_excluding_last(os, tuple);
	os << std::get<tuple_last_type>(tuple) << ")";
	return os;
}

template<class _Type1, class _Type2>
std::ostream& operator<<(std::ostream & os, const std::pair<_Type1, _Type2>&pair) {
	os << "(" << pair.first << ", " << pair.second << ")";
	return os;
}
/*-------------------------------------------------------------------------------*/
#endif

#endif //CONTAINER_OSTREAMS_GUARD
//
//  Container_ostreams.hpp
//  Created by Timothy van Wees on 23/02/2021.
//
