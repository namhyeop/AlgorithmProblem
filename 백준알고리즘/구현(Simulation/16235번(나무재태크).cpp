#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 11;
int n, m, k;
int board[MAX][MAX];
int A[MAX][MAX];
vector<int> tree[MAX][MAX];
int moveY[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int moveX[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int main()
{
	fastio;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		board[i][j] = 5;
		cin >> A[i][j];
	}

	for (int i = 0; i < m; i++)
	{
		int y, x, value;
		cin >> y >> x >> value;
		tree[y-1][x-1].push_back(value);
	}

	auto springSummer = [&]()
	{
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int dieTreeEnergy = 0;
			vector<int> tmp;
			sort(tree[i][j].begin(), tree[i][j].end());
			for (auto curTree : tree[i][j])
			{
				if (board[i][j] >= curTree)
				{
					board[i][j] -= curTree;
					tmp.push_back(curTree + 1);
				}
				else
					dieTreeEnergy += (curTree / 2);
			}
			tree[i][j].clear();
			for (int curTree : tmp)
				tree[i][j].push_back(curTree);
			board[i][j] += dieTreeEnergy;
		}
	};

	auto fall = [&]()
	{
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			for (auto curTree : tree[i][j])
			{
				if (curTree % 5 == 0)
				{
					for (int d = 0; d < 8; d++)
					{
						int nextY = i + moveY[d];
						int nextX = j + moveX[d];
						if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n)
						{
							tree[nextY][nextX].push_back(1);
						}
					}
				}
			}
		}
	};

	auto winter = [&]()
	{
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] += A[i][j];
	};

	for (int i = 0; i < k; i++)
	{
		springSummer();
		fall();
		winter();
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (tree[i][j].size())
			ret += tree[i][j].size();
	}
	cout << ret << "\n";
}
/*
#include<bits/stdc++.h>
#define MAX 11
using namespace std;

int n, m, k;
int A[MAX][MAX];//로봇이 돌면서 채워줄 양분의 양
int baseBoard[MAX][MAX]; //5로 초기화된 기본 양분
vector<int> tree[MAX][MAX];

int moveY[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int moveX[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void SpringSummer()
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (tree[i][j].size() == 0)
			continue;

		int DieTreeEnergy = 0;
		vector<int> tmp;
		
		sort(tree[i][j].begin(), tree[i][j].end());
		for (int k = 0; k < tree[i][j].size(); k++)
		{
			int Age = tree[i][j][k];

			if (baseBoard[i][j] >= Age)
			{
				baseBoard[i][j] = baseBoard[i][j] - Age;
				tmp.push_back(Age + 1);
			}
			else
			{
				DieTreeEnergy = DieTreeEnergy + (Age / 2);
			}
		}		
		tree[i][j].clear();
		for (int k = 0; k < tmp.size(); k++)
		{
			tree[i][j].push_back(tmp[k]);
		}
		baseBoard[i][j] = baseBoard[i][j] + DieTreeEnergy;
	}
}

void Fall()
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (tree[i][j].size() == 0)
			continue;
		for (int l = 0; l < tree[i][j].size(); l++)
		{
			int Age = tree[i][j][l];
			if (Age % 5 == 0)
			{
				for (int d = 0; d < 8; d++)
				{
					int nextY = i + moveY[d];
					int nextX = j + moveX[d];
					
					if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n)
					{
						tree[nextY][nextX].push_back(1);
					}
				}
			}
		}
	}
}

void Winter()
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		baseBoard[i][j] += A[i][j];
}

int main(void)
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		cin >> A[i][j];
		baseBoard[i][j] = 5;
	}

	for (int i = 0; i < m; i++)
	{
		int y, x, age;
		cin >> y >> x >> age;
		tree[y-1][x-1].push_back(age);
	}

	for (int i = 0; i < k; i++)
	{
		SpringSummer();
		Fall();
		Winter();
	}
	
	int ret = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		ret += tree[i][j].size();
	}

	cout << ret << "\n";

	return 0;
}
*/
