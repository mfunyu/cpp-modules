/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:07:12 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 23:43:11 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

void	put_error(std::string error_msg)
{
	std::cerr << error_msg << std::endl;
	std::exit(1);
}

void	write_to_file(const std::string filename, const std::string file_content)
{
	std::string	new_filename = filename + ".replace";
	std::ofstream	ofs(new_filename);

	if (ofs.fail())	{
		put_error("Failed to open file");
	}
	ofs << file_content;
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

	char	c;
	while (ifs.get(c)) {
		file_content += c;
	}
	if (!ifs.eof()) {
		put_error("Failed to read");
	}
	return file_content;
}

void	replace(const std::string filename, const std::string s1, const std::string s2)
{
	if (s1.empty() || s2.empty()) {
		put_error("Invalid strings");
	}

	std::ifstream	ifs(filename);

	if (ifs.fail())	{
		put_error("Failed to open file");
	}

	std::string	file_content = read_file(ifs);

	replace_str(file_content, s1, s2);
	write_to_file(filename, file_content);
}
