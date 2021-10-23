/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:07:12 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 16:14:04 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

int		replace(std::string filename, std::string s1, std::string s2)
{
	//open filename
	std::ifstream	ifs(filename);

	if (ifs.fail())	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}

	std::string	file_content;

	while (ifs) {
		std::string	line;
		std::getline(ifs, line);
		file_content.append(line);
		file_content.append("\n");
	}

	//replace s1 -> s2
	std::size_t	found;
	std::size_t	s1_len = s1.length();
	std::size_t	pos = 0;

	while (1) {
		found = file_content.find(s1, pos);
		if (found == std::string::npos)
			break ;
		file_content.erase(found, s1_len);
		file_content.insert(found, s2);
		pos = found + s1_len;
	}

	//write to filaname.replace
	std::string	new_filename = filename + ".replace";
	std::ofstream	ofs(new_filename);

	if (ofs.fail())	{
		std::cout << "Failed to create file" << std::endl;
		return 1;
	}
	ofs << file_content << std::endl;
	return 0;
}
