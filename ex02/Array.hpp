/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:32:45 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/09 23:37:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
  private:
	T*				_array;
	unsigned int	_size;

  public:
	Array<T>() : _size(0) {}
	Array<T>(unsigned int n) : _size(n) {
		_array = new T[n]();
	}

	Array<T>(Array<T> const &other) {
		_array = new T[other._size]();
		_size = other._size;
		for (unsigned int i = 0; i < other._size; i++) {
			_array[i] = other._array[i];
		}
	}

	Array<T>	&operator=(Array<T> const &other) {
		if (this != &other) {
			delete [] _array;
			_array = new T[other._size]();
			_size = other._size;
			for (unsigned int i = 0; i < other._size; i++) {
				_array[i] = other._array[i];
			}
		}
		return *this;
	}

	T	&operator[](unsigned int i) {
		if (i < 0 || i >= _size) {
			throw std::out_of_range("index out of range");
		}
		return _array[i];
	}

	unsigned int	size(void) const {
		return _size;
	}

	~Array<T>() {
		delete [] _array;
	}
};

#endif /* ARRAY_HPP */
