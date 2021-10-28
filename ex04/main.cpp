/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:07:12 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/28 23:36:35 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

void	put_error(std::string error_msg)
{
	std::cerr << "Error: " << error_msg << std::endl;
	std::exit(1);
}

void	write_to_newfile(const std::string filename, const std::string file_content)
{
	std::ofstream	ofs(filename);

	if (!ofs) {
		put_error("failed to open");
	}
	ofs << file_content;
	if (ofs.fail()) {
		put_error("failed to open");
	}
}

void	replace_string(std::string& file_content, const std::string s1, const std::string s2)
{
	std::size_t	found;
	std::size_t	s1_len = s1.length();
	std::size_t	s2_len = s2.length();
	std::size_t	pos = 0;

	while (1) {
		found = file_content.find(s1, pos);
		if (found == std::string::npos)
			break ;
		file_content.erase(found, s1_len);
		file_content.insert(found, s2);
		pos = found + s2_len;
	}
}

std::string		read_from_file(std::string filename)
{
	std::ifstream	ifs(filename);

	if (!ifs) {
		put_error("failed to open");
	}

	std::string	file_content;

	char	c;
	while (ifs.get(c)) {
		file_content += c;

	}
	if (ifs.fail())

	if (!ifs.eof()) {
		put_error("failed to read");
	}
	return file_content;
}

int		main(int ac, char **av)
{
	if (ac != 4) {
		put_error("invalid arguments");
	}

	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	if (s1.empty() || s2.empty()) {
		put_error("empty string");
	}

	std::string	file_content = read_from_file(filename);

	replace_string(file_content, s1, s2);

	std::string	new_filename = filename + ".replace";
	write_to_newfile(new_filename, file_content);
}
