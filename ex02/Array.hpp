/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:32:45 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/23 13:34:40 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
  private:
	T*			 _array;
	unsigned int _size;

  public:
	Array<T>() : _size(0)
	{
		_array = new T[0]();
	}
	Array<T>(unsigned int n) : _size(n)
	{
		_array = new T[n]();
	}

	Array<T>(Array<T> const& other);

	Array<T>& operator=(Array<T> const& other);
	T&		  operator[](unsigned int i);

	unsigned int size(void) const
	{
		return _size;
	}

	~Array<T>()
	{
		delete[] _array;
	}
};

/* ------------------------------- definitions ------------------------------ */

/* Copy constructor */
template <typename T>
Array<T>::Array(Array<T> const& other)
{
	_size  = other._size;
	_array = new T[_size]();

	for (unsigned int i = 0; i < other._size; i++) {
		_array[i] = other._array[i];
	}
}

/* Assignment operator = overload */
template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& other)
{
	if (this != &other) {
		delete[] _array;
		_size  = other._size;
		_array = new T[other._size]();

		for (unsigned int i = 0; i < other._size; i++) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

/* Subscript operator [] overload */
template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i < 0 || i >= _size) {
		throw std::out_of_range("index out of range");
	}
	return _array[i];
}

#endif /* ARRAY_HPP */
