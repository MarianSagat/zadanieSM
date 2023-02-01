#include "pch.h"

#include "Graph.h"
#include "split.h"

#include <queue>


siemens::Graph::Graph(const std::string& directDirs)
{
	std::vector<std::string> existingDirectConnections = split(directDirs, ",");
	for (const auto directConnection : existingDirectConnections)
	{
		std::vector<std::string> cities = split(directConnection, "-");
		std::string city{ cities.front() };
		std::string connectedCity{ cities[1] };

		insertOrientedEdge(city, connectedCity);
		insertOrientedEdge(connectedCity, city);

	}

	for (auto iter = m_graph.begin(); iter != m_graph.end(); iter++)
	{
		m_visitedCities.insert(std::make_pair(iter->first, false));
	}
}

bool siemens::Graph::connectionExists(const std::string& city, const std::string& otherCity)
{

	if (m_graph.find(city) == m_graph.end())
		return false;

	if (m_graph.find(otherCity) == m_graph.end())
		return false;

	//clear cache
	unvisitAllCities();

	std::queue<std::string> frontOfCities;
	frontOfCities.push(city);

	while (!frontOfCities.empty())
	{
		std::string currentCity = frontOfCities.front();
		auto nextCities = m_graph[currentCity];
		for (auto const& c : nextCities)
		{
			//compare->0 means equality
			if (c.compare(otherCity)==0)
				return true;

			//we can have dupliciy cities, solution with set...
			if (m_visitedCities[c])
				continue;

			frontOfCities.push(c);
		}

		visitCity(currentCity);
		frontOfCities.pop();
		
	}

	return false;
}

void siemens::Graph::insertOrientedEdge(const std::string& city, const std::string& connectedCity)
{
	std::unordered_set< std::string> connectedCities{ connectedCity };

	auto resultOfInsertion = m_graph.insert(std::make_pair(city, connectedCities)).second;
	if (!resultOfInsertion)
	{
		m_graph[city].insert(connectedCity);
	}
}

void siemens::Graph::visitCity(const std::string& city)
{
	//dont check existence
	m_visitedCities[city] = true;
}

void siemens::Graph::unvisitAllCities()
{
	for (auto iter = m_visitedCities.begin(); iter != m_visitedCities.end(); iter++)
	{
		iter->second = false;
	}
}
