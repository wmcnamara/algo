/*
	Counting sort implementation created by Weston McNamara

	Time Complexity: O(N)
	Space Complexity: O(B) where B is the maximum numeric limit of the data type being sorted
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits>

/*
	Templated counting sort implementation
*/
template<typename T>
void countingSort(std::vector<T>& arr)
{
	constexpr size_t bucketSize = std::numeric_limits<T>::max();

	//Occurance count
	static int occurances[bucketSize]{};

	for (int n : arr)
	{
		++occurances[n];
	}

	//Index to write back into the array
	int index = 0;

	//Go back through each bucket and write the occurances back into the array
	for (int value = 0; value < bucketSize; value++)
	{
		int occ = occurances[value];

		for (int j = 0; j < occ; j++)
		{
			arr[index] = value;
			index++;
		}
	}
}

int main()
{
	std::vector<short> v{ 8, 2, 1, 10, 120, 64, 2, 1 }; //1 1 2 2 8 10 64 120

	std::cout << "UNSORTED: \n";
	std::for_each(v.begin(), v.end(), [](short c) { std::cout << c << " "; });
	std::cout << "\n\n";

	std::cout << "SORTED: \n";
	countingSort(v);
	std::for_each(v.begin(), v.end(), [](short c) { std::cout << c << " "; });
}