/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:59:36 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/11 12:22:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>

class Replace
{
	private:
		std::string	_fileContent;
		std::string	_inputFileName;
		std::string	_outputFileName;
		std::string	_s1;
		std::string	_s2;

		static std::string const	extention;

	public:
		Replace(std::string filename, std::string s1, std::string s2);
		~Replace();

		void	exec();
		void	readInputFile();
		void	replaceStrings();
		void	writeOutputFile() const;
		void	putError(std::string error) const;

	private:
		Replace();
};

#endif /* REPLACE_HPP */
