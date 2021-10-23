/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:07:12 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 16:35:31 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

void	write_to_file(const std::string filename, const std::string file_content)
{
	std::string	new_filename = filename + ".replace";
	std::ofstream	ofs(new_filename);

	if (ofs.fail())	{
		std::cout << "Failed to open file" << std::endl;
		exit(EXIT_FAILURE);
	}
	ofs << file_content << std::endl;
}

void	replace_str(std::string& file_content, const std::string s1, const std::string s2)
{
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
}

std::string		read_file(std::ifstream& ifs)
{
	std::string	file_content;

	while (ifs) {
		std::string	line;
		std::getline(ifs, line);
		file_content.append(line);
		file_content.append("\n");
	}
	return file_content;
}

void	replace(const std::string filename, const std::string s1, const std::string s2)
{
	std::ifstream	ifs(filename);

	if (ifs.fail())	{
		std::cout << "Failed to open file" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string	file_content = read_file(ifs);

	replace_str(file_content, s1, s2);
	write_to_file(filename, file_content);
}
