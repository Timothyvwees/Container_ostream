//
//  Container_ostreams.hpp
//  Created by Timothy van Wees on 23/02/2021.
//

#pragma once

#ifndef CONTAINER_OSTREAMS_GUARD
#define CONTAINER_OSTREAMS_GUARD

//this is for programming purpose dont define them inside this file
//#define INCLUDE_TUPLE_OSTREAM_CONTAINER_OVERLOADS
//#define INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS

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

#ifdef USE_CONTAINER_OSTREAMS_SPACES
#define OSTREAM_CONTAINER_COMMA ", "

#define OSTREAM_CONTAINER_BEGIN "[ "
#define OSTREAM_CONTAINER_END " ]"

#define OSTREAM_TUPLE_BEGIN "( "
#define OSTREAM_TUPLE_END " )"

#else
#define OSTREAM_CONTAINER_COMMA ","

#define OSTREAM_CONTAINER_BEGIN "["
#define OSTREAM_CONTAINER_END "]"

#define OSTREAM_TUPLE_BEGIN "("
#define OSTREAM_TUPLE_END ")"

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
template <std::size_t tuple_pos = 0ULL, class... _Types>
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
	os ARRAY_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!arr.empty()) {
		os << arr.front();
		auto it_begin = ++arr.begin();
		auto it_end = arr.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::vector<_Type, _Alloc>& vec) {
	os VECTOR_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!vec.empty()) {
		os << vec.front();
		auto it_begin = ++vec.begin();
		auto it_end = vec.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::deque<_Type, _Alloc>& deq) {
	os DEQUE_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!deq.empty()) {
		os << deq.front();
		auto it_begin = ++deq.begin();
		auto it_end = deq.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::list<_Type, _Alloc>& list) {
	os LIST_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!list.empty()) {
		os << list.front();
		auto it_begin = ++list.begin();
		auto it_end = list.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::forward_list<_Type, _Alloc>& flist) {
	os FLIST_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!flist.empty() ) {
		os << flist.front();
		auto it_begin = ++flist.begin();
		auto it_end = flist.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}
/*-----------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_ADAPTERS_OSTREAM_CONTAINER_OVERLOADS)
/*--------------------These are all the container adapters-----------------------*/
template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::stack<_Type, _Container>& stack) {
	auto stack_copy = stack;

	os STACK_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	while (stack_copy.size() > 1ULL) {
		os << stack_copy.top() << OSTREAM_CONTAINER_COMMA;
		stack_copy.pop();
	}
	os << stack_copy.top() << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::queue<_Type, _Container>& queue) {
	auto queue_copy = queue;

	os QUEUE_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	while (queue_copy.size() > 1ULL) {
		os << queue_copy.front() << OSTREAM_CONTAINER_COMMA;
		queue_copy.pop();
	}
	os << queue_copy.front() << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Type, class _Container, class _Compare>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<_Type, _Container, _Compare>& pqueue) {
	auto pqueue_copy = pqueue;

	os PQUEUE_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	while (pqueue_copy.size() > 1ULL) {
		os << pqueue_copy.top() << OSTREAM_CONTAINER_COMMA;
		pqueue_copy.pop();
	}
	os << pqueue_copy.top() << OSTREAM_CONTAINER_END;
	return os;
}
/*-------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_ASSOCIATIVE_OSTREAM_CONTAINER_OVERLOADS)
/*----------------------These are all the associative containers---------------*/
template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::map<_Key, _Types, _Compare, _Alloc>& map){
	os MAP_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!map.empty()) {
		auto it_begin = map.begin();
		os << it_begin->first << ":" << it_begin->second;
		++it_begin;

		auto it_end = map.end();

		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element.first << ":" << element.second;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multimap<_Key, _Types, _Compare, _Alloc>& multimap){
	os MULTIMAP_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!multimap.empty()) {
		auto it_begin = multimap.begin();
		os << it_begin->first << ":" << it_begin->second;
		++it_begin;
		auto it_end = multimap.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element.first << ":" << element.second;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::set<_Key, _Compare, _Alloc>& set) {
	os SET_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!set.empty()) {
		auto it_begin = set.begin();
		os << *it_begin;
		++it_begin;
		auto it_end = set.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multiset<_Key, _Compare, _Alloc>& multiset) {
	os MULTISET_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!multiset.empty()) {
		auto it_begin = multiset.begin();
		os  << *it_begin;
		++it_begin;

		auto it_end = multiset.end();

		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}
/*------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_ALL_OSTREAM_CONTAINER_OVERLOADS) || defined(INCLUDE_UNORDERED_ASSOCIATIVE_OSTREAM_CONTAINER_OVERLOADS)
/*-----------------These are all the unordered associative containers-----------*/
template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_map){
	os UNORDEDED_MAP_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!unordered_map.empty()) {
		auto it_begin = unordered_map.begin();
		os << it_begin->first << ":" << it_begin->second;
		++it_begin;
		auto it_end = unordered_map.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element.first << ":" << element.second;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_multimap){
	os UNORDEDED_MULTIMAP_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!unordered_multimap.empty()) {
		auto it_begin = unordered_multimap.begin();
		os << it_begin->first << ":" << it_begin->second;
		++it_begin;
		auto it_end = unordered_multimap.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element.first << ":" << element.second;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<_Key, _Hasher, _Keyeq, _Alloc>& unordered_set) {
	os UNORDEDED_SET_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!unordered_set.empty()) {
		auto it_begin = unordered_set.begin();
		os << *it_begin;
		++it_begin;
		auto it_end = unordered_set.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}

template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<_Key, _Hasher, _Keyeq, _Alloc>& unordered_multiset) {
	os UNORDEDED_MULTISET_INDENTIFIER << OSTREAM_CONTAINER_BEGIN;
	if (!unordered_multiset.empty()) {
		auto it_begin = unordered_multiset.begin();
		os << *it_begin;
		++it_begin;
		auto it_end = unordered_multiset.end();
		std::for_each(it_begin, it_end, [&](const auto& element) {
			os << OSTREAM_CONTAINER_COMMA << element;
		});
	}
	os << OSTREAM_CONTAINER_END;
	return os;
}
/*-------------------------------------------------------------------------------*/
#endif



#if defined(INCLUDE_TUPLE_OSTREAM_CONTAINER_OVERLOADS)
/*--------------------These are all the tuples types-----------------------------*/
template <std::size_t tuple_pos, class... _Types>
constexpr void print_tuple_excluding_last(std::ostream& os, const std::tuple<_Types...>& tuple) {
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
	if constexpr (tuple_pos == (sizeof...(_Types) - 1ULL)) {
#else
	if (tuple_pos == (sizeof...(_Types) - 1ULL)) {
#endif
		return;
	}
	else {
		os << std::get<tuple_pos>(tuple) << OSTREAM_CONTAINER_COMMA;
		print_tuple_excluding_last<tuple_pos + 1ULL>(os, tuple);
	}
}

template<class... _Types>
std::ostream& operator<<(std::ostream & os, const std::tuple<_Types...>&tuple) {
	const auto tuple_last_type = std::tuple_size<std::tuple<_Types...>>::value - 1ULL;
	os << OSTREAM_TUPLE_BEGIN;
	print_tuple_excluding_last(os, tuple);
	os << std::get<tuple_last_type>(tuple) << OSTREAM_TUPLE_END;
	return os;
}

template<class _Type1, class _Type2>
std::ostream& operator<<(std::ostream & os, const std::pair<_Type1, _Type2>&pair) {
	os << OSTREAM_TUPLE_BEGIN << pair.first << OSTREAM_CONTAINER_COMMA << pair.second << OSTREAM_TUPLE_END;
	return os;
}
/*-------------------------------------------------------------------------------*/
#endif

#endif //CONTAINER_OSTREAMS_GUARD
//
//  Container_ostreams.hpp
//  Created by Timothy van Wees on 23/02/2021.
//
