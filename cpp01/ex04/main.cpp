/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:21:27 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/11 11:21:27 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string content, std::string s1, std::string s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	if (s1.empty())
		return content;
	while (pos < content.length())
	{
		found = content.find(s1, pos);
		if (found == std::string::npos)
		{
			result += content.substr(pos);
			break;
		}
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: cannot open file " << filename << std::endl;
		return 1;
	}

	std::string content;
	std::string line;
	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += "\n";
	}
	infile.close();

	std::string result = replaceAll(content, s1, s2);

	std::string outfilename = filename + ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: cannot create file " << outfilename << std::endl;
		return 1;
	}

	outfile << result;
	outfile.close();

	return 0;
}
