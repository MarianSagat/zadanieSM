#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace siemens
{
	class Graph
	{
	public:
		Graph() = delete;
		Graph(const std::string& directDirs);

		bool connectionExists(const std::string& city, const std::string& otherCity);

	private:

		void insertOrientedEdge(const std::string& city, const std::string& connectedCity);
		void visitCity(const std::string& city);
		void unvisitAllCities();


	private:
		std::unordered_map<std::string, std::unordered_set<std::string>> m_graph;
		std::unordered_map<std::string, bool> m_visitedCities;
	};
}