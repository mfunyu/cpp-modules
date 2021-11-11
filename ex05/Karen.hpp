/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:48:18 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/11 15:31:50 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen
{
	public:
		Karen();
		~Karen();
		void	complain( std::string level );

	private:
		struct complain_types
		{
			std::string		level;
			void (Karen::*FuncPtr)();
		};
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	nop( void );
};

#endif /* KAREN_HPP */
