#pragma once

#include <iostream>
#include <cstdlib>
#include <stdexcept>

template<class T>
class Array
{
	private:
		T *arr;
		size_t n;
	public:
		Array() : arr(NULL), n(0) {}

		Array(unsigned int n) : n(n) {
			arr = new T[n];
			for (size_t i = 0; i < n; i++) {
				arr[i] = T();
			}
		}

		Array(const Array<T> &cpy): arr(NULL), n(0) {
			*this = cpy;
		}

		Array<T> &operator = (const Array<T> &cpy) {
			if (arr) delete []arr, arr = NULL;
			n = cpy.size();
			if (!n) return *this;
			arr = new T[n];
			for (size_t i = 0; i < n; i++) {
				arr[i] = cpy[i];
			}
			return *this;
		}

		T &operator [] (size_t index) const {
			if (index >= n) {
				throw std::out_of_range("index out of range");
			}
			return arr[index];
		}

		size_t size() const {
			return n;
		}

		~Array() {
			delete[] arr;
		}
};