/*
* Created by Weston McNamara | wmcnamara.com
*
* This is a full, 15/15 solution to "Escape Room" problem from the senior question set for the 2020 Canadian Computing Computing Competition (CEMC)
*
* The problem set can be found here: (J5/S2)
* https://www.cemc.uwaterloo.ca/contests/computing/2020/ccc/seniorEF.pdf
*
* This solution takes an O(N) recursive approach to solving the problem.
*
* Time Complexity: O(N)
* Space Complexity: O(N)
*/


#include <iostream>
#include <vector>
#include <string>

#include <utility>
#include <algorithm>
#include <sstream>

using Room = std::vector<std::vector<int>>;
using BoolArray2D = std::vector<std::vector<bool>>;

//Returns factor pairs for a specific number, and bounds checks the factors to ensure that they can be used to index a given room.
std::vector<std::pair<int, int>> factors(int x, const Room& room)
{
	if (x <= 0) throw std::exception("Room cannot be indexed by negative numbers, therefore negative or 0 factors are an error.");
	if (x == 1) return std::vector<std::pair<int, int>>{ { 1, 1 } };

	const int roomRows = room.size();
	const int roomColumns = room[0].size();

	std::vector<std::pair<int, int>> factors;

	//Modification of https://www.geeksforgeeks.org/program-to-print-factors-of-a-number-in-pairs/
	for (int i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			const int factor1 = i;
			const int factor2 = x / i;

			if (factor1 <= roomRows && factor2 <= roomColumns) //Bounds check
				factors.push_back({ factor1, factor2 });

			if (factor2 <= roomRows && factor1 <= roomColumns) //Bounds check
				factors.push_back({ factor2, factor1 });
		}
	}

	return factors;
}


/*
	Underlying recursive function to calculate if a specific room can be escaped.

	It works by checking if the current coordinate is the correct one. If so, the room is escapable.
	If not, check if the coordinate has been visited before. If it has, return false.

	If the coordinate has not been visited, and isnt the endpoint:

	1. Mark it as visited
	2. Retrieve its factors
	3. Recurse this function through each of the factors until a solution is found.


	data is the Room data that the function should recurse through to find a solution for.
	current is the current coordinate that the function should check, and possibly recurse through.
	visited is a 2D boolean array that keeps track of which coordinates have been visited
*/

bool IsEscapable_R(const Room& data, const std::pair<int, int>& current, BoolArray2D& visited)
{
	//The end point of the room is the bottom right corner
	const int endPointX = data.size();
	const int endPointY = data[0].size();

	const auto [x, y] = current; //structured bindings. Requires C++17


	//Base case checking if we found the correct coord
	if (x == endPointX && y == endPointY)
		return true;

	//If this coord is previously visited, return false.
	else if (visited[x - 1][y - 1] == true)
	{
		return false;
	}
	else
	{
		//Mark this as visited
		visited[x - 1][y - 1] = true;

		//Get the factors
		const auto& facs = factors(data[x - 1][y - 1], data);

		//Recurse through each factor until the correct one is found.
		for (const auto& factor : facs)
		{
			if (IsEscapable_R(data, factor, visited))
			{
				return true;
			}
		}

		return false; //No answer for this coord
	}
}

/*
*	Solution for problem J5/S2 from the 2020 Canadian Computing Competition problem set.
*   https://www.cemc.uwaterloo.ca/contests/computing/2020/ccc/seniorEF.pdf
*
*
*	data is the Room data that the function should recurse through to find a solution for.
*/
bool IsEscapable(const Room& data)
{
	//The end point of the room is the bottom right corner
	const int endPointX = data.size();
	const int endPointY = data[0].size();

	const int roomRows = data.size();
	const int roomColumns = data[0].size();

	//2D boolean array for keeping track of visited squares
	//Initialize the marked array with zero'd rows
	BoolArray2D visited(roomRows);

	for (auto& r : visited)
	{
		r.resize(roomColumns, 0);
	}

	//Start at 1, 1
	return IsEscapable_R(data, { 1, 1 }, visited);
}

int main()
{
	//Get row and column data
	std::string colStr, rowStr;

	std::getline(std::cin, rowStr);
	std::getline(std::cin, colStr);

	int row = std::stoi(rowStr);
	int col = std::stoi(colStr);

	//Create a room
	Room map(row);

	//Parse room coordinate data
	for (int i = 0; i < row; i++)
	{
		std::string dat;
		std::getline(std::cin, dat);

		std::stringstream text_stream(dat);
		std::string item;

		while (std::getline(text_stream, item, ' ')) {
			map[i].push_back(std::stoi(item));
		}

	}

	std::cout << (IsEscapable(map) ? "yes" : "no");
}