/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:57:48 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/27 00:32:13 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_nbFractionalBit;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed_obj);
		Fixed	&operator=(const Fixed &fixed_obj);

		Fixed(const int i);
		Fixed(const float f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;

		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed&	min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed&	min(Fixed const &fixed1, Fixed const &fixed2);
		static Fixed&	max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed&	max(Fixed const &fixed1, Fixed const &fixed2);
};


std::ostream	&operator<<(std::ostream& os, const Fixed& fixed_obj);

#endif /* FIXED_HPP */
