#include<bits/stdc++.h>
#define MAX 15
using namespace std;

int row;
int col;
int creteriaDist;
int board[MAX][MAX];
int tmpboard[MAX][MAX];

int main()
{
	cin >> row >> col >> creteriaDist;

	vector<pair<int, int>> enemy;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> board[i][j];
			
			if (board[i][j] == 1)
			{
				enemy.push_back({ i, j });
			}
		}
	}
	
	vector<int> archer;
	for (int i = 0; i < col - 3; i++)
		archer.push_back(0);

	for (int i = 0; i < 3; i++)
		archer.push_back(1);

	int ret = 0;

	do
	{
		int cnt = 0;
		vector<pair<int, int>> temp = enemy;
		vector<int> v;

		for (int i = 0; i < archer.size(); i++)
		{
			if (archer[i] == 1)
				v.push_back(i);
		}

		while (!temp.empty())
		{
			int y = row;
			vector<int> target;

			for (int i = 0; i < v.size(); i++)
			{
				int x = v[i];
				int idx = 0;
				int enemyX = temp[0].second;
				int dist = abs(y - temp[0].first) + abs(x - temp[0].second); //가장 왼쪽에 있고 멀리있는 적을 먼저 입력받는다
				for (int j = 1; j < temp.size(); j++)
				{
					int tempDist = abs(y - temp[j].first) + abs(x - temp[j].second);
					
					if (dist > tempDist)
					{
						enemyX = temp[j].second;
						dist = tempDist;
						idx = j;
					}
					else if (dist == tempDist && enemyX > temp[j].second)
					{
						enemyX = temp[j].second;
						idx = j;
					}
				}

				if (dist <= creteriaDist)
				{
					target.push_back(idx);
				}
			}

			sort(target.begin(), target.end());
			target.erase(unique(target.begin(), target.end()), target.end());
			int shoot = 0;

			for (int i = 0; i < target.size(); i++)
			{
				temp.erase(temp.begin() + (target[i] - shoot++));
				cnt++;
			}

			if (temp.empty())
				break;

			vector<pair<int, int>> copyTemp;
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i].first < row - 1)
				{
					copyTemp.push_back({ temp[i].first + 1, temp[i].second });
				}
			}
			temp = copyTemp;
		}
		ret = max(ret, cnt);
	} while (next_permutation(archer.begin(), archer.end()));
	
	cout << ret << "\n";

	return 0;
}
