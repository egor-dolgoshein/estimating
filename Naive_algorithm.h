#pragma once
#include<vector>
#include<random>
#include<cassert>
#include"IN.h"


long long int naive_path_generation(std::vector<std::vector<int>> A, int finish)
{
	int v = 0; // current vertex
	long double g = 1; // probobility
	int t = 1; // counter
	long double estimation = 0;
	std::vector<long double> G;
	std::vector<int> track;
	std::vector<int> nu;
	for (auto& row : A)
	{
		auto it = find(row.begin(), row.end(), v);
		if(it == row.end())
			continue;  // to ensure path will not return to 0
		row.erase(it);
	}
	track.push_back(v);
	G.push_back(g);
	while(true)
	{
		//estimation += 1 / g;
		nu.clear();
		for (int i = 0; i < A[v].size(); ++i)
			nu.push_back(A[v][i]);

		if (nu.empty())
		{
			estimation = -1;
			break;
		}

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, nu.size() - 1);
		v = nu[dist(gen)];
		g /= nu.size();
		G.push_back(g);
		t++;
		for (auto& row : A)
		{
			auto it = find(row.begin(), row.end(), v);
			if (it == row.end())
				continue;
			row.erase(it);
		}
		track.push_back(v);
		if (v == finish)
			break;

		//std::cout << "Processing\n";

	}
/*	for (auto item : track)
		std::cout << item << ' ';
	std::cout << std::endl;
	*/
	assert(t != 0);
	for (auto n : G)
	{
		if (estimation == -1)
			break;
		estimation += 1. / (t * n);
	}
	return estimation;
	 
}