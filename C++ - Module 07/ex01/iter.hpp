#pragma once

#include <cstdlib>

template<class T>
void iter(T *arr, size_t sz, void (*f)(const T &)) {
	for (size_t i = 0; i < sz; i++) {
		f(arr[i]);
	}
}
