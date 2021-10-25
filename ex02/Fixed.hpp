/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:57:48 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/25 23:10:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed &fixed_obj);
		Fixed &operator =(const Fixed &fixed_obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed	operator ++(int i);
		Fixed	&operator ++();
		Fixed	operator *(Fixed const &RHS);
		bool	operator >=(Fixed const &RHS) const;

		static const Fixed&	max(Fixed const &fixed1, Fixed const &fixed2);


	private:
		int					_fixedPointValue;
		static const int	_nbFractionalBit;
};



#endif /* FIXED_HPP */
