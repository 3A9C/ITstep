#pragma once

template <class T>
void sort(T begin, T end) {
	T i, j;
	for (i = begin; i != end; i++) {
		for (j = begin;;) {
			T q = j;
			j++;
			if (j == end) {
				break;
			}

			if (*q > *j) {
				auto helper = *j;
				*j = *q;
				*q = helper;
			}
		}
	}
}