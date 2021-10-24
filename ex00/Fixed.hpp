/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:57:48 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/24 20:48:35 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int					_fixedPointValue;
		static const int	_nbFractionalBit;
};



#endif /* FIXED_HPP */
