#include <iostream>
#include <unordered_map>

using namespace std;

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

		int coordx[] = { 0, -1, 0, 1 };	//left, top, right, bottom
		int coordy[] = { -1, 0, 1, 0 };

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
		res.clear();
		resIndex = 0;
		row = matrix.size();
		visited.clear();
		visited.resize(row);

		for (int i = 0; i < matrix.size(); i++)
		{
			visited[i] = vector<bool>(matrix[i].size());
			for (int j = 0; j < matrix[i].size(); j++)
			{
				visited[i][j] = false;
			}
		}

		for (int i = 0; i < matrix.size(); i++)
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
}