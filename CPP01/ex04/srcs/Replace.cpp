#include "Replace.hpp"

/*
 * creation d un objet, instance de ifstream, classe de flux de fichiers
 * la methode string.c_str renvoie un const char *, necessaire pour le constructeur
*/
void replaceInFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream inFile(filename.c_str());
	if (!inFile)
		throw std::runtime_error("Unable to open input file: " + filename);
	std::string newFilename = filename + ".replace";
	std::ofstream outFile(newFilename.c_str());
	if (!outFile)
		throw std::runtime_error("Unable to open output file: " + newFilename);
	
	std::string line;
	while (std::getline(inFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outFile << line << std::endl;
	}

	inFile.close();
	outFile.close();
}
