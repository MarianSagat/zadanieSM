#include "pch.h"
#include "../businessLogic/src/Graph.h"

TEST(SimpleGraph, existConnections) {
	siemens::Graph graph(std::string("Google-Amazon,51X-Google,Amazon-Hello4,3X-Bingo,Hello4-A"));

	EXPECT_TRUE(graph.connectionExists("Amazon", "51X"));
	EXPECT_TRUE(graph.connectionExists("51X", "Amazon"));

	EXPECT_TRUE(graph.connectionExists("Google", "Hello4"));
	EXPECT_TRUE(graph.connectionExists("Hello4", "Google"));

	EXPECT_TRUE(graph.connectionExists("51X", "A"));
	EXPECT_TRUE(graph.connectionExists("A", "51X"));
}

TEST(SimpleGraph, dontExistConnections) {
	siemens::Graph graph(std::string("Google-Amazon,51X-Google,Amazon-Hello4,3X-Bingo,Hello4-A"));

	EXPECT_TRUE(!graph.connectionExists("Bingo", "Google"));
	EXPECT_TRUE(!graph.connectionExists("Google", "Bingo"));

	EXPECT_TRUE(!graph.connectionExists("3X", "A"));
	EXPECT_TRUE(!graph.connectionExists("A", "3X"));
}

TEST(Graph, connections) {
	siemens::Graph graph(std::string(
		"1-2,1-4,1-5\
		2-3,\
		4-5,\
		5-3,\
		6-9,6-10,6-7,9-7,9-10,7-10\
		7-8,8-11,10-11,10-17,17-16,16-15,15-14,14-13,13-12,12-8\
		"));

	EXPECT_TRUE(!graph.connectionExists("5", "14"));

	EXPECT_TRUE(graph.connectionExists("6", "14"));
	EXPECT_TRUE(graph.connectionExists("8", "17"));
}