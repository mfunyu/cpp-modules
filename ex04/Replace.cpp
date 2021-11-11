/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:59:32 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/11 14:27:55 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include "Replace.hpp"

std::string const	Replace::extention = ".replace";

Replace::Replace(std::string filename, std::string s1, std::string s2) :
	_inputFileName(filename), _outputFileName(filename + extention), _s1(s1), _s2(s2)
{
	if (s1.empty() || s2.empty()) {
		putError("empty string");
	}
}

Replace::~Replace() {}

void	Replace::exec()
{
	readInputFile();
	replaceStrings();
	writeOutputFile();
}

void	Replace::readInputFile()
{
	std::ifstream	ifs(_inputFileName);

	if (!ifs) {
		putError("failed to open");
	}

	std::string	line;
	while (ifs.good()) {
		std::getline(ifs, line);
		_fileContent.append(line);
		if (!ifs.eof()) {
			_fileContent.append("\n");
		}
	}

	if (!ifs.eof()) {
		putError("failed to read");
	}
}

void	Replace::replaceStrings()
{
	std::size_t	found;
	std::size_t	s1_len = _s1.length();
	std::size_t	s2_len = _s2.length();
	std::size_t	pos = 0;

	while (1) {
		found = _fileContent.find(_s1, pos);
		if (found == std::string::npos)
			break ;
		_fileContent.erase(found, s1_len);
		_fileContent.insert(found, _s2);
		pos = found + s2_len;
	}
}

void	Replace::writeOutputFile() const
{
	std::ofstream	ofs(_outputFileName);

	if (!ofs) {
		putError("failed to open");
	}

	ofs << _fileContent;

	if (ofs.fail()) {
		putError("failed to open");
	}
}

void	Replace::putError(std::string error) const
{
	std::cerr << "Error: " << error << std::endl;
	std::exit(1);
}
