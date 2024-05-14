#pragma once


template<typename ITER, typename T>
const ITER* Find(const ITER* begin, const ITER* end, const T& value)
{
	const ITER* p = begin;
	while (p != end) {
		if (*p == value) {
			return p;
		}
	}

	return p;
}

