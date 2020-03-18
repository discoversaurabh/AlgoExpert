//https://www.algoexpert.io/questions/Largest%20Range
#include <vector>
#include <unordered_map>
#include<iostream>
using namespace std;

int arrSize;
vector<bool> visited(arrSize);
unordered_map<int, int> map;
int gmin=INT_MAX, gmax=INT_MIN, gcount = 0;

vector<int> largestRange(vector<int> array) {
	// Write your code here.
	arrSize = array.size();
	map.clear();
	visited.clear();
	gmin = INT_MAX, gmax = INT_MIN, gcount = 0;

	int lmin = INT_MAX, lmax = INT_MIN, lcount = 0, tmp;
	for (int i = 0; i < array.size(); i++)
	{
		map[array[i]] = i;
	}

	for (int i = 0; i < array.size(); i++)
	{
		if (map.find(array[i]) != map.end())
		{
			//traverse both directions sequentially in map now from this particular element and store local min, max and count
			tmp = array[i];
			while (map.find(tmp) != map.end())
			{
				tmp--;
			}
			lmin = tmp + 1;
			tmp = array[i];
			while (map.find(tmp) != map.end())
			{
				tmp++;
			}
			lmax = tmp - 1;
			lcount = lmax - lmin + 1;

			if (lcount > gcount)
			{
				gcount = lcount;
				gmin = lmin;
				gmax = lmax;
			}
		}
	}
	return {gmin, gmax};
}

int main()
{
	vector<int> arr = {1,11,3,0,15,5,2,4,10,7,12,6};
	vector<int> res(2);
	res = largestRange(arr);
	cout << "Largest Range:" << "{" << res[0] << "," << res[1] << "}" << endl;
	return 0;
}