#pragma once

#include <vector>
#include <list>
#include <forward_list>
#include <iostream>

/// Global output of vectors
template <typename T>
inline std::ostream& operator<<(std::ostream& out,
								const std::vector<T>& vec) {
    out << "[ ";
    for (const auto& v:vec) out << v << ' ';
	if (vec.size()==0) out << ' ';
	out << "]";
    return out;

}

namespace containersoutputdetails {
/// Global output of lists
template <typename LIST_T>
inline std::ostream& list_printing_helper(std::ostream& out,
										  const LIST_T& l,
										  size_t size,
										  const char* sep) {
    out << "{ ";
	if (size!=0) {
		auto it= l.cbegin();
		for (size_t i=0; i<size-1; ++i) {
			out << *it << sep;
			++it;
		}
		out << (*it);
	}
	out << " }";
    return out;
}
}

/// Global output of list
template <typename T>
inline std::ostream& operator<<(std::ostream& out,
								const std::list<T>& l) {
	containersoutputdetails::list_printing_helper(out,
												  l,
												  l.size(),
												  "<=>");
	return out;
}

/// Global output of list
template <typename T>
inline std::ostream& operator<<(std::ostream& out,
								const std::forward_list<T>& l) {
	containersoutputdetails::list_printing_helper(out,
												  l,
												  std::distance(l.cbegin(),l.cend()),
												  "->");
	return out;
}
