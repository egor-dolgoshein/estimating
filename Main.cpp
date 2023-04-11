#include<iostream>
#include<vector>
#include"Naive_algorithm.h"

using namespace std;

// filling square grid as Adjacency list
std::vector<std::vector<int>> fill_grid(int N = 5)
{
	std::vector<std::vector<int>> grid(N * N + 2, std::vector<int>(0));

	for (size_t i = 1; i < grid.size() - 2; ++i)
	{
		if ((i) % N != 0)
		{
			if (i < grid.size() - N - 1)
			{
				grid[i].push_back(i+1);
				grid[i+1].push_back(i);
				grid[i].push_back(i + N);
				grid[i + N].push_back(i);
			}
			else
			{
				grid[i].push_back(i+1);
				grid[i+1].push_back(i);
			}
		}
		else
		{
			grid[i].push_back(i + N);
			grid[i + N].push_back(i);
		}
	}
	for (int i = 1; i < N + 1; ++i)
	{
		grid[0].push_back(i);
		grid[i].push_back(0);
		grid[N * N + 1].push_back(N * N - i + 1);
		grid[N * N - i + 1].push_back(N * N + 1);
	}
	return grid;
}





int main()
{
	vector<vector<int>> test = {
		{1,3},
		{0,3,4},
		{3,4},
		{0,1,2},
		{1,2}
	};
	vector<vector<int>> test1 = {
		{1,3},
		{0,3,4},
		{3,4},
		{0,1,2},
		{1,2}
	};
	vector<vector<int>> test2 = fill_grid(6);
	//cout << naive_path_generation(test, 4);
	long long int s = 0;
	for (int i = 0; i < 10000; ++i)
	{
		long long int avg = naive_path_generation(test2, test2.size() - 1);
		s += avg;
	}
	cout << s / 10000;
}