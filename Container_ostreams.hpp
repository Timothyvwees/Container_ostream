//
//  Container_ostreams.hpp
//
//  Created by Timothy van Wees on 23/02/2021.
//  Copyright © 2021 Timothy van Wees. All rights reserved.
//

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#else
#error this header only supports c++17 and above
#endif


#ifdef _OSTREAM_
#ifdef CONTAINER_INDENTIFIER_FOR_PRETTY_CONTAINER_PRINTING
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

#ifdef CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING
#define CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << "{"
#define CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END << "} "
#else
#define CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN
#define CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END << " "
#endif

/*----------------------These are all the sequence containers------------------*/
#if defined(_ARRAY_) && !defined(_ARRAY_OSTREAM_DEFINED)
template <class _Type, std::size_t _Size>
std::ostream& operator<<(std::ostream& os, const std::array<_Type, _Size>& arr);
#endif

#if defined(_VECTOR_) && !defined(_VECTOR_OSTREAM_DEFINED)
template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::vector<_Type, _Alloc>& vec);
#endif

#if defined(_DEQUE_) && !defined(_DEQUE_OSTREAM_DEFINED)
template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::deque<_Type, _Alloc>& deq);
#endif

#if defined(_LIST_) && !defined(_LIST_OSTREAM_DEFINED)
template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::list<_Type, _Alloc>& list);
#endif

#if defined(_FORWARD_LIST_) && !defined(_FORWARD_LIST_OSTREAM_DEFINED)
template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::forward_list<_Type, _Alloc>& flist);
#endif
/*------------------------------------------------------------------------------*/


/*--------------------These are all the container adapters-----------------------*/
#if defined(_STACK_) && !defined(_STACK_OSTREAM_DEFINED)
template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::stack<_Type, _Container>& stack);
#endif

#if defined(_QUEUE_) && !defined(_QUEUE_OSTREAM_DEFINED)
template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::queue<_Type, _Container>& queue);

template <class _Type, class _Container, class _Compare>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<_Type, _Container, _Compare>& pqueue);
#endif
/*-------------------------------------------------------------------------------*/



/*----------------------These are all the associative containers-----------------*/
#if defined(_MAP_) && !defined(_MAP_OSTREAM_DEFINED)
template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::map<_Key, _Types, _Compare, _Alloc>& map);

template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multimap<_Key, _Types, _Compare, _Alloc>& multimap);
#endif

#if defined(_SET_) && !defined(_SET_OSTREAM_DEFINED)
template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::set<_Key, _Compare, _Alloc>& set);

template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multiset<_Key, _Compare, _Alloc>& multiset);
#endif
/*-------------------------------------------------------------------------------*/

 

/*-------------------These are all the unordered associative containers----------*/
#if defined(_UNORDERED_MAP_) && !defined(_UNORDERED_MAP_OSTREAM_DEFINED)
template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_map);

template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_multimap);
#endif

#if defined(_UNORDERED_SET_) && !defined(_UNORDERED_SET_OSTREAM_DEFINED)
template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<_Key, _Hasher, _Keyeq, _Alloc>& unordered_set);

template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<_Key, _Hasher, _Keyeq, _Alloc>& unordered_multiset);
#endif
/*-------------------------------------------------------------------------------*/



/*--------------------These are all the tuples types-----------------------------*/
#if defined(_TUPLE_) && !defined(_TUPLE_OSTREAM_DEFINED)
template <std::size_t tuple_pos, class... _Types>
constexpr void print_tuple_excluding_last(std::ostream& os, const std::tuple<_Types...>& tuple);

template<class... _Types>
std::ostream& operator<<(std::ostream& os, const std::tuple<_Types...>& tuple);
#endif

#if defined(_UTILITY_) && !defined(_UTILITY_OSTREAM_DEFINED)
template<class _Type1, class _Type2>
std::ostream& operator<<(std::ostream& os, const std::pair<_Type1, _Type2>& pair);
#endif
/*-------------------------------------------------------------------------------*/



/*----------------------These are all the sequence containers--------------------*/

#if defined(_ARRAY_) && !defined(_ARRAY_OSTREAM_DEFINED)
template <class _Type, std::size_t _Size>
std::ostream& operator<<(std::ostream& os, const std::array<_Type, _Size>& arr){
	os ARRAY_INDENTIFIER << "[ ";
	for (std::size_t i = 0; i < (arr.size() - 1ULL); i++) {
		os << arr[i] << ", ";
	}
	os << arr.back() << " ]";
	return os;
}
#define _ARRAY_OSTREAM_DEFINED
#endif

#if defined(_VECTOR_) && !defined(_VECTOR_OSTREAM_DEFINED)
template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::vector<_Type, _Alloc>& vec){
	os VECTOR_INDENTIFIER << "[ ";
	for (std::size_t i = 0; i < (vec.size() - 1ULL); i++) {
		os << vec[i] << ", ";
	}
	os << vec.back() << " ]";
	return os;
}
#define _VECTOR_OSTREAM_DEFINED
#endif

#if defined(_DEQUE_) && !defined(_DEQUE_OSTREAM_DEFINED)
template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::deque<_Type, _Alloc>& deq){
	os DEQUE_INDENTIFIER << "[ ";
	for (std::size_t i = 0; i < (deq.size() - 1ULL); i++) {
		os << deq[i] << ", ";
	}
	os << deq.back() << " ]";
	return os;
}
#define _DEQUE_OSTREAM_DEFINED
#endif

#if defined(_LIST_) && !defined(_LIST_OSTREAM_DEFINED)
template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::list<_Type, _Alloc>& list){
    os LIST_INDENTIFIER << "[ ";
    for (const auto& element : list) {
        os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;    
    }
    os << "]";
	return os;
}
#define _LIST_OSTREAM_DEFINED
#endif

#if defined(_FORWARD_LIST_) && !defined(_FORWARD_LIST_OSTREAM_DEFINED)
template <class _Type, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::forward_list<_Type, _Alloc>& flist){
	os FLIST_INDENTIFIER << "[ ";
	for (const auto& element : flist) {
		os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;
	}
	os << "]";
	return os;
}
#define _FORWARD_LIST_OSTREAM_DEFINED
#endif
/*-----------------------------------------------------------------------------*/



/*--------------------These are all the container adapters-----------------------*/
#if defined(_STACK_) && !defined(_STACK_OSTREAM_DEFINED)
template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::stack<_Type, _Container>& stack) {

    auto stack_copy = stack;

    os STACK_INDENTIFIER << "[";
    while (stack_copy.size() > 1) {
        os << stack_copy.top() << ", ";
        stack_copy.pop();
    }
    os << stack_copy.top() << "]";

    return os;
}
#define _STACK_OSTREAM_DEFINED
#endif

#if defined(_QUEUE_) && !defined(_QUEUE_OSTREAM_DEFINED)
template <class _Type, class _Container>
std::ostream& operator<<(std::ostream& os, const std::queue<_Type, _Container>& queue) {

    auto queue_copy = queue;

    os QUEUE_INDENTIFIER << "[";
    while (queue_copy.size() > 1) {
        os << queue_copy.front() << ", ";
        queue_copy.pop();
    }
    os << queue_copy.front() << "]";

    return os;
}

template <class _Type, class _Container, class _Compare>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<_Type, _Container, _Compare>& pqueue) {
    auto pqueue_copy = pqueue;
    
    os PQUEUE_INDENTIFIER << "[";
    while (pqueue_copy.size() > 1) {
        os << pqueue_copy.top() << ", ";
        pqueue_copy.pop();
    }
    os << pqueue_copy.top() << "]";

    return os;
}
#define _QUEUE_OSTREAM_DEFINED
#endif
/*-------------------------------------------------------------------------------*/



/*----------------------These are all the associative containers---------------*/
#if defined(_MAP_) && !defined(_MAP_OSTREAM_DEFINED)
template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::map<_Key, _Types, _Compare, _Alloc>& map)
{
	os MAP_INDENTIFIER << "[ ";
	for (const auto& element : map) {
		os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element.first << ":" << element.second CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;
	}
	os << "]";
	return os;
}

template <class _Key, class _Types, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multimap<_Key, _Types, _Compare, _Alloc>& multimap)
{
    os MULTIMAP_INDENTIFIER << "[ ";

    for (const auto& element : multimap) {
        os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element.first << ":" << element.second CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;
    }
    os << "]";

    return os;
}
#define _MAP_OSTREAM_DEFINED
#endif

#if defined(_SET_) && !defined(_SET_OSTREAM_DEFINED)
template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::set<_Key, _Compare, _Alloc>& set) {

    os SET_INDENTIFIER << "[ ";
    for (const auto& element : set) {
        os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;
    }
    os << "]";

    return os;
}

template <class _Key, class _Compare, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::multiset<_Key, _Compare, _Alloc>& multiset) {

    os MULTISET_INDENTIFIER << "[ ";
    for (const auto& element : multiset) {
        os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;
    }
    os << "]";

    return os;
}
#define _SET_OSTREAM_DEFINED
#endif
/*------------------------------------------------------------------------------*/



/*-----------------These are all the unordered associative containers-----------*/

#if defined(_UNORDERED_MAP_) && !defined(_UNORDERED_MAP_OSTREAM_DEFINED)
template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_map)
{
	os UNORDEDED_MAP_INDENTIFIER << "[ ";
	for (const auto& element : unordered_map) {
		os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element.first << ":" << element.second CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;
	}
	os << "]";
	return os;
}

template <class _Key, class _Types, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multimap<_Key, _Types, _Hasher, _Keyeq, _Alloc>& unordered_multimap)
{
	os UNORDEDED_MULTIMAP_INDENTIFIER << "[ ";
	for (const auto& element : unordered_multimap) {
		os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element.first << ":" << element.second CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;
	}
	os << "]";

	return os;
}
#define _UNORDERED_MAP_OSTREAM_DEFINED
#endif

#if defined(_UNORDERED_SET_) && !defined(_UNORDERED_SET_OSTREAM_DEFINED)
template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_set<_Key, _Hasher, _Keyeq, _Alloc>& unordered_set) {
    os UNORDEDED_SET_INDENTIFIER << "[ ";
    for (const auto& element : unordered_set) {
        os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;
    }
    os << "]";

    return os;
}

template <class _Key, class _Hasher, class _Keyeq, class _Alloc>
std::ostream& operator<<(std::ostream& os, const std::unordered_multiset<_Key, _Hasher, _Keyeq, _Alloc>& unordered_multiset) {
    os UNORDEDED_MULTISET_INDENTIFIER << "[ ";
    for (const auto& element : unordered_multiset) {
        os CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_BEGIN << element CONTAINER_ELEMENT_SEPERATOR_FOR_PRETTY_PRINTING_END;
    }
    os << "]";

    return os;
}
#define _UNORDERED_SET_OSTREAM_DEFINED
#endif
/*-------------------------------------------------------------------------------*/



/*--------------------These are all the tuples types-----------------------------*/
#if defined(_TUPLE_) && !defined(_TUPLE_OSTREAM_DEFINED)
template <std::size_t tuple_pos = 0, class... _Types>
constexpr void print_tuple_excluding_last(std::ostream& os, const std::tuple<_Types...>& tuple){
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
std::ostream& operator<<(std::ostream& os, const std::tuple<_Types...>& tuple){
    const auto tuple_last_type = std::tuple_size<std::tuple<_Types...>>::value - 1;

    os << "(";
    print_tuple_excluding_last(os, tuple);
    os << std::get<tuple_last_type>(tuple) << ")";
    return os;
}
#define _TUPLE_OSTREAM_DEFINED
#endif

#if defined(_UTILITY_) && !defined(_UTILITY_OSTREAM_DEFINED)
template<class _Type1, class _Type2>
std::ostream& operator<<(std::ostream& os, const std::pair<_Type1, _Type2>& pair) {
    os << "(" << pair.first << ", " << pair.second << ")";
    return os;
}
#define _UTILITY_OSTREAM_DEFINED
#endif
/*-------------------------------------------------------------------------------*/



#else
#error Dont include Container_ostreams.hpp if ostream is not included somewhere before this one because it wont do anything
#endif //no ostream include