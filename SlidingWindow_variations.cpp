#if 1
#include <iostream>
#include <unordered_map>

using namespace std;

class LongestSubstringKDistinct {
public:
	static int findLength(const string& str, int k) {
		int maxLength = 0, l = 0;
		// TODO: Write your code here
		unordered_map<char, int>freq;

		for (int r = 0; r < str.length(); r++)
		{
			freq[str[r]]++;
			while (freq.size() > k)
			{
				freq[str[l]]--;
				if (freq[str[l]] == 0)
				{
					freq.erase(str[l]);
					//l++;	//DID WRONG HERE, THIS INCREMENT SHOULD OCCUR OUTSIDE IF
				}
				l++;
			}
			if (freq.size() == k)
				maxLength = maxLength > (r - l + 1) ? maxLength : (r - l + 1);
		}
		return maxLength;
	}
};

class MaxFruitCountOf2Types {
public:
	static int findLength(const vector<char>& arr) {
		int maxLength = 0, l = 0, r = 0;
		unordered_map<char, int>freq;
		// TODO: Write your code here
		for (r = 0; r < arr.size(); r++)
		{
			freq[arr[r]]++;
			while (freq.size() > 2)
			{
				freq[arr[l]]--;
				if (freq[arr[l]] == 0)
					freq.erase(arr[l]);
				l++;
			}
			if (freq.size() == 2)
				maxLength = maxLength > r - l + 1 ? maxLength : r - l + 1;
		}
		return maxLength;
	}
};

class NoRepeatSubstring {
public:
	static int findLength(const string& str) {
		int l=0, maxLength = 0;
		char c;
		unordered_map<char, int> freq;

		for (int r = 0; r < str.length(); r++)
		{
			freq[str[r]]++;
			if (freq[str[r]] > 1)
			{
				c = str[r];
				while(freq[c] > 1)
				{
					freq[str[l]]--;
					l++;
				}
			}
			maxLength = maxLength > r - l + 1 ? maxLength : r - l + 1;
		}
		return maxLength;
	}
};

class CharacterReplacement {
public:
	static int findLength(const string& str, int k) {
		int maxLength = 0;
		// TODO: Write your code here
		int l = 0, replaced = 0;
		char c;

		for (int r = 1; r < str.length(); r++)
		{
			//c = str[l];
			if (str[l] != str[r])
			{
				replaced++;
				if (replaced > k)
				{
					l++;
					r = l + 1;	//reset r
					replaced = 0;
				}
			}
			maxLength = maxLength > r - l + 1 ? maxLength : r - l + 1;
		}
		return maxLength;
	}
};

class ReplacingOnes {
public:
	static int findLength(const vector<int>& arr, int k) {
		int  maxLength = 0;
		// TODO: Write your code here
		int l = 0, freq[2] = { 0, 0 };

		for (int r = 0; r < arr.size(); r++)
		{
			freq[arr[r]]++;
			while (freq[0] > k && l < r)
			{
				freq[arr[l]]--;
				l++;
			}
			maxLength = maxLength > r - l + 1 ? maxLength : r - l + 1;
		}
		return maxLength;
	}
};

class RiverSizes {
public:
	const int DIRECTION = 4;
	int row;
	int qIndex = 0;
	int resIndex = 0;	//result index
	
	struct queue
	{
		int x, y, count;
	};
	
	vector<queue> que;
	vector<int> res;
	vector<vector<bool>> visited;// (matrix.size());

	/*bool isValid(int x, int y, int size)
	{
		if (x >= 0 && x < row && y >= 0 && y < size)
		{
			return true;
		}
		return false;
	}*/

	void pushInQ(int x, int y, vector<vector<int>> &mat) {

		int coordx[] = {0, -1, 0, 1};	//left, top, right, bottom
		int coordy[] = {-1, 0, 1, 0};

		for (int i = 0; i < 4; i++)
		{
			int tmpx = x + coordx[i];
			int tmpy = y + coordy[i];
			if (tmpx >= 0 && tmpx < row && tmpy >= 0 && tmpy < mat[tmpx].size() && mat[tmpx][tmpy] && !visited[tmpx][tmpy])
			{
				visited[tmpx][tmpy] = true;
				que.push_back({ tmpx, tmpy, que.back().count + 1 });
				//qIndex++;
			}
		}
	}

	vector<int> riverSizes(vector<vector<int>> matrix) {
		// Write your code here.
		// init
		que.clear();
		row = matrix.size();
		visited.resize(row);

		for (int i = 0; i < matrix.size(); i++)
		{
			visited[i] = vector<bool>(matrix[i].size());
			for (int j = 0; j < matrix[i].size(); j++)
			{
				visited[i][j] = false;
			}
		}

		for (int i=0; i<matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (!visited[i][j] && matrix[i][j])
				{
					que.clear();
					qIndex = 0;
					visited[i][j] = true;
					que.push_back({ i,j,1 });
					while (qIndex < que.size())
					{
						//if (!matrix[que[qIndex].x][que[qIndex].y] && isValid(que[qIndex].x, que[qIndex].y, matrix[que[qIndex].x].size()))
						//{
						pushInQ(que[qIndex].x, que[qIndex].y, matrix);
						//}
						//pushInQ(i, j, matrix);
						qIndex++;
					}

					//enter is result array
					res.push_back(que[qIndex - 1].count);
					resIndex++;
				}
			}
		}
		return res;
	}

	void printRS(vector<vector<int>> &matrix)
	{
		vector<int> res = riverSizes(matrix);
		for (auto a = res.begin(); a != res.end(); a++)
		{
			cout << *a << " ";
		}
		cout << endl;
	}
};

//Example 1:
//Input: String = "aabccbb", k = 2
//Output : 5
//Explanation : Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".
//Example 2 :
//Input : String = "abbcb", k = 1
//Output : 4
//Explanation : Replace the 'c' with 'b' to have a longest repeating substring "bbbb".
int main()
{
	vector<vector<int>> arrRS = {
								{1,0,0,1,0},
								{1,0,1,0,0},
								{0,0,1,0,1},
								{1,0,1,0,1},
								{1,0,1,1,0},
								};
	cout << "All River Sizes :" << endl;
	RiverSizes rs;
	rs.printRS(arrRS);

	//WORKING CODES
	//string str("cbbebi"), str3("aabccbb"), str4("abccde");
	//vector<int> arr = { 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1 };
	//vector<char> str2 = { 'A', 'B', 'C', 'B', 'B', 'C' };	 //char str2[] = {'A', 'B', 'C', 'B', 'B', 'C'};
	//cout << "ReplacingOnes : " << ReplacingOnes::findLength(arr, 3) << endl;
	//cout << "CharacterReplacement : " << CharacterReplacement::findLength(str4, 1) << endl;
	//cout << "NoRepeatSubstring : " << NoRepeatSubstring::findLength(str) << endl;
	//cout << "MaxFruitCountOf2Types : " << MaxFruitCountOf2Types::findLength(str2)<<endl;
	//cout<<"LongestSubstringKDistinct :"<< LongestSubstringKDistinct::findLength(str, 3)<<endl;

	return 0;
}
#endif