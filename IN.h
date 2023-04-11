#pragma once
#include<vector>

bool in(int item, std::vector<int> row)
{
	for (auto it : row)
		if (it == item)
			return true;
	return false;
}