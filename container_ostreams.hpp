#include <stack>
#include <queue>
#include <iostream>
#include <tuple>
#include <utility>

#define CONTAINER_OSTREAM_NAMESPACE os

namespace CONTAINER_OSTREAM_NAMESPACE {

	constexpr char tuple_begin_ostream = '(';
	constexpr char tuple_end_ostream = ')';
	constexpr const char* tuple_seperator_ostream = ", ";
	constexpr const char* pair_seperator_ostream = ":";

	constexpr char container_begin_ostream = '[';
	constexpr char container_end_ostream = ']';
	constexpr const char* container_seperator_ostream = ", ";

	template<typename ContainerType>
	concept container_properties = requires (ContainerType a, const ContainerType b) {
		requires std::regular<ContainerType>;
		requires std::swappable<ContainerType>;
		requires std::destructible<typename ContainerType::value_type>;
		requires std::same_as<typename ContainerType::reference, typename ContainerType::value_type&>;
		requires std::same_as<typename ContainerType::const_reference, const typename ContainerType::value_type&>;
		requires std::forward_iterator<typename ContainerType::iterator>;
		requires std::forward_iterator<typename ContainerType::const_iterator>;
		requires std::signed_integral<typename ContainerType::difference_type>;
		requires std::unsigned_integral<typename ContainerType::size_type>;
		requires std::same_as<typename ContainerType::difference_type, typename std::iterator_traits<typename ContainerType::iterator>::difference_type>;
		requires std::same_as<typename ContainerType::difference_type, typename std::iterator_traits<typename ContainerType::const_iterator>::difference_type>;
		{ a.begin()   }	-> std::same_as<typename ContainerType::iterator>;
		{ a.end()	  }	-> std::same_as<typename ContainerType::iterator>;
		{ b.begin()   }	-> std::same_as <typename ContainerType::const_iterator>;
		{ b.end()	  }	-> std::same_as <typename ContainerType::const_iterator>;
		{ a.cbegin()  }	-> std::same_as <typename ContainerType::const_iterator>;
		{ a.cend()    }	-> std::same_as <typename ContainerType::const_iterator>;
		//{ a.size()    }	-> std::same_as <typename ContainerType::size_type>;
		{ a.max_size()} -> std::same_as <typename ContainerType::size_type>;
		{ a.empty()   }	-> std::same_as <bool>;
	};

	template<class ContainerType>
	concept associative_containers = requires(ContainerType a) {
		requires container_properties<ContainerType>;

		{ a.key_comp() }	-> std::same_as <typename ContainerType::key_compare>;
		{ a.value_comp() }	-> std::same_as <typename ContainerType::value_compare>;
	};

	template<class ContainerType>
	concept unordered_associative_containers = requires(ContainerType a) {
		requires container_properties<ContainerType>;

		{ a.hash_function() }	-> std::same_as <typename ContainerType::hasher>;
		{ a.key_eq() }			-> std::same_as <typename ContainerType::key_equal>;
	};

	template<class ContainerType>
	concept string_type = requires (ContainerType a) {
		requires container_properties<ContainerType>;

		{ a.c_str() }	-> std::same_as <const typename ContainerType::value_type*>;
		{ a.substr() }	-> std::same_as <ContainerType>;
	};

	template<typename ContainerType>
	concept sequence_container = container_properties<ContainerType> && !string_type<ContainerType> && !associative_containers<ContainerType> && !unordered_associative_containers<ContainerType>;
	
	template<typename ContainerType>
	concept container = (container_properties<ContainerType> || associative_containers<ContainerType> || unordered_associative_containers<ContainerType>) && !string_type<ContainerType>;
}

template <class Type1, class Type2>
std::ostream& operator<<(std::ostream& os, const std::pair<Type1, Type2>& pair);
template <class... Types>
std::ostream& operator<<(std::ostream& os, const std::tuple<Types...>& tuple);
template <CONTAINER_OSTREAM_NAMESPACE::container con>
std::ostream& operator<<(std::ostream& os, const con& container);
template<class T, class Container>
std::ostream& operator<<(std::ostream& os, const std::stack<T, Container>& container);
template<class T, class Container>
std::ostream& operator<<(std::ostream& os, const std::queue<T, Container>& container);
template<class T, class Container, class Compare = std::less<typename Container::value_type>>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<T, Container, Compare>& container);


template <class Type1, class Type2>
std::ostream& operator<<(std::ostream& os, const std::pair<Type1, Type2>& pair) {
	os << CONTAINER_OSTREAM_NAMESPACE::tuple_begin_ostream << pair.first << CONTAINER_OSTREAM_NAMESPACE::pair_seperator_ostream << pair.second << CONTAINER_OSTREAM_NAMESPACE::tuple_end_ostream;
	return os;
}

template<typename... Ts>
std::ostream& operator<<(std::ostream& os, std::tuple<Ts...> const& theTuple) {

	std::apply([&os](Ts const&... tupleArgs) {
		os << CONTAINER_OSTREAM_NAMESPACE::tuple_begin_ostream;
		std::size_t n = 0ULL;
		((os << tupleArgs << (++n != sizeof...(Ts) ? CONTAINER_OSTREAM_NAMESPACE::tuple_seperator_ostream : "")), ...);
		os << CONTAINER_OSTREAM_NAMESPACE::tuple_end_ostream;
	}, theTuple);

	return os;
}

template <CONTAINER_OSTREAM_NAMESPACE::container con>
std::ostream& operator<<(std::ostream& os, const con& container) {
	os << CONTAINER_OSTREAM_NAMESPACE::container_begin_ostream;

	if (std::distance(container.begin(), container.end()) != 0ULL) {
		os << *container.begin();
		std::for_each(std::next(container.begin()), container.end(), [&](const auto& element) {
			os << CONTAINER_OSTREAM_NAMESPACE::container_seperator_ostream << element;
		});
	}

	os << CONTAINER_OSTREAM_NAMESPACE::container_end_ostream;

	return os;
}

template<class T, class Container>
std::ostream& operator<<(std::ostream& os, const std::stack<T, Container>& container) {
	auto con_copy = container;

	os << CONTAINER_OSTREAM_NAMESPACE::container_begin_ostream;
	while (con_copy.size() > 1ULL) {
		os << con_copy.top() << CONTAINER_OSTREAM_NAMESPACE::container_seperator_ostream;
		con_copy.pop();
	}
	os << con_copy.top() << CONTAINER_OSTREAM_NAMESPACE::container_end_ostream;
	return os;
}

template<class T, class Container>
std::ostream& operator<<(std::ostream& os, const std::queue<T, Container>& container) {
	auto con_copy = container;

	os << CONTAINER_OSTREAM_NAMESPACE::container_begin_ostream;
	while (con_copy.size() > 1ULL) {
		os << con_copy.front() << CONTAINER_OSTREAM_NAMESPACE::container_seperator_ostream;
		con_copy.pop();
	}
	os << con_copy.front() << CONTAINER_OSTREAM_NAMESPACE::container_end_ostream;
	return os;
}

template<class T, class Container, class Compare>
std::ostream& operator<<(std::ostream& os, const std::priority_queue<T, Container, Compare>& container) {
	auto con_copy = container;

	os << CONTAINER_OSTREAM_NAMESPACE::container_begin_ostream;
	while (con_copy.size() > 1ULL) {
		os << con_copy.top() << CONTAINER_OSTREAM_NAMESPACE::container_seperator_ostream;
		con_copy.pop();
	}
	os << con_copy.top() << CONTAINER_OSTREAM_NAMESPACE::container_end_ostream;
	return os;
}
