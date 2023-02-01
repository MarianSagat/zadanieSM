#include "../src/Graph.h"
#include "../src/split.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>


//NOTE 1: no controll for correctness of operations based on file format



int main(int argc, char* argv[])
{
	std::string localFileName;

	auto provideFileName = [&localFileName](char* argv[])
	{
		std::cout << std::string(argv[0]) << std::endl;
		std::cout << "Please, provide full file path." << std::endl;
		std::getline(std::cin, localFileName);
	};

	if (argc == 1)
	{
		provideFileName(argv);
	}

	if (argc > 1)
	{
		localFileName = std::string(argv[1]);
		std::cout << localFileName << std::endl;
	}

	if (!std::filesystem::exists(localFileName))
	{
		std::cout << "File is not loaded" << std::endl;
		provideFileName(argv);

		if (!std::filesystem::exists(localFileName))
			return -1;
	}
	std::ifstream inputFile(localFileName);

	std::string line;

	std::getline(inputFile, line);
	std::unique_ptr<siemens::Graph> graph = std::make_unique<siemens::Graph>(line);

	std::vector<std::pair< std::string, std::string>> connections;
	while (std::getline(inputFile, line))
	{
		std::vector<std::string> cities = siemens::split(line, ",");
		//no correctness controll
		connections.push_back(std::make_pair(cities.front(), cities[1]));
	}

	std::string outputFileName = siemens::split(localFileName, ".").front() + ".out";
	std::ofstream outputFile(outputFileName);

	for (auto const& con : connections)
	{
		outputFile << (graph->connectionExists(con.first, con.second) ? "Yes" : "No");
		outputFile << std::endl;
	}

	outputFile.close();

	return 0;
}
