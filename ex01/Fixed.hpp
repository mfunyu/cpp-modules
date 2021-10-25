/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:57:48 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/25 23:25:53 by mfunyu           ###   ########.fr       */
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
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed(const Fixed &fixed_obj);

		Fixed	&operator=(const Fixed &fixed_obj);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
};

#endif /* FIXED_HPP */
