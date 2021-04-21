#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int n, m;
vector<vector<int>> board;

bool check(vector<vector<int>> &key, int y, int x)
{
	bool ret = true;

	for (int i = y; i < y + m; i++)
	for (int j = x; j < x + m; j++)
		board[i][j] += key[i - y][j - x];

	for (int i = m; i < m + n; i++)
	for (int j = m; j < m + n; j++)
	{
		{
			if (board[i][j] != 1)
			{
				ret = false;
				break;
			}
		}
		if (!ret)
			break;
	}

	for (int i = y; i < y + m; i++)
	for (int j = x; j < x + m; j++)
		board[i][j] -= key[i - y][j - x];

	return ret;
}

void rotate(vector<vector<int>> &key)
{
	vector<vector<int>> temp(m, vector<int>(m));

	for (int i = 0; i < m; i++)
	for (int j = 0; j < m; j++)
		temp[i][j] = key[i][j];
	for (int i = 0; i < m; i++)
	for (int j = 0; j < m; j++)
		key[i][j] = temp[m - 1 -j][i];
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	bool answer = false;
	
	m = key.size();
	n = lock.size();

	board = vector<vector<int>>(2 * m + n, vector<int>(2 * m + n));

	for (int i = m; i < m + n; i++)
	for (int j = m; j < m + n; j++)
		board[i][j] = lock[i - m][j - m];

	for (int i = 0; i < n + m; i++)
	{
		for (int j = 0; j < n + m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				rotate(key);
				if (check(key, i, j))
				{
					answer = true;
					break;
				}
			}
			if (answer)
				break;
		}
		if (answer)
			break;
	}

	return answer;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> key = { { 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 1 } };
	vector<vector<int>> map = { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
	cout << solution(key, map) << "\n";
}

//90점 풀이
//#include<bits/stdc++.h>
//#define pill pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define ll long long
//
//using namespace std;
//
//void moveRectangle(int num, int n, vector<vector<int>> &tmpKey)
//{
//	for (int t = 0; t < num; t++)
//	{
//		vector<vector<int>> tmptmpKey = tmpKey;
//		for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			tmpKey[i][j] = tmptmpKey[n-1-j][i];
//	}
//}
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock)
//{
//	bool answer = false;
//	int n = key.size();
//	int m = lock.size();
//
//	//오른쪽으로 아래로
//	for (int i = 0; i < 4; i++)
//	{
//		vector<vector<int>> tmpKey = key;
//
//		if (i != 0)//첫 번째의 경우에는 도형을 바꾸지 않는다.
//			moveRectangle(i, n, tmpKey);
//		
//
//		for (int y = 0; y < n; y++)
//		{
//			bool okFlag = false;
//
//			for (int x = 0; x < n; x++)
//			{
//				okFlag = false;
//
//				vector<vector<int>> tmptmpKey = tmpKey;
//
//				/*if (y == 1 && x == 1)
//				{
//					getchar();
//				}*/
//
//				if (!(y == 0 && x == 0))
//				{
//					for (int i = n - 1; i >= 0; i--) //도형을 오른쪽 밑으로 움직이는 경우
//					{
//						for (int j = n - 1; j >= 0; j--)
//						{
//							if (!(i + y >= n || j + x >= n))
//							{
//								tmptmpKey[i + y][j + x] = tmptmpKey[i][j];
//							}
//							tmptmpKey[i][j] = 0;
//						}
//					}
//				}
//
//
//				for (int i = 0; i < n; i++) //돌린 도형을 확인하는 과정
//				{
//					vector < vector < int >> locktmp = lock;
//					bool checkFlag = false;
//					for (int j = 0; j < n; j++)
//					{
//						locktmp[i][j] += tmptmpKey[i][j];
//						if (locktmp[i][j] != 1)
//						{
//							checkFlag = true;
//							okFlag = true;
//							break;
//						}
//					}
//					if (checkFlag)
//						break;
//
//				}
//
//				if (!okFlag)
//				{
//					answer = true;
//					break;
//				}
//			}
//			if (!okFlag)
//			{
//				break;
//			}
//		}
//	}
//
//	//오른쪽으로 위로
//	if (answer == false)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			vector<vector<int>> tmpKey = key;
//
//			if (i != 0)//첫 번째의 경우에는 도형을 바꾸지 않는다.
//				moveRectangle(i, n, tmpKey);
//
//			for (int y = 0; y < n; y++)
//			{
//				bool okFlag = false;
//
//				for (int x = 0; x < n; x++)
//				{
//					okFlag = false;
//
//					vector<vector<int>> tmptmpKey = tmpKey;
//
//					/*if (y == 1 && x == 1)
//					{
//					getchar();
//					}*/
//
//					if (!(y == 0 && x == 0))
//					{
//						for (int i = 0; i < n; i++) //도형을 오른쪽 밑으로 움직이는 경우
//						{
//							for (int j = 0; j < n; j++)
//							{
//								if (!(i - y < 0 || j + x >= n))
//								{
//									tmptmpKey[i - y][j + x] = tmptmpKey[i][j];
//								}
//								tmptmpKey[i][j] = 0;
//							}
//						}
//					}
//
//
//					for (int i = 0; i < n; i++) //돌린 도형을 확인하는 과정
//					{
//						vector < vector < int >> locktmp = lock;
//						bool checkFlag = false;
//						for (int j = 0; j < n; j++)
//						{
//							locktmp[i][j] += tmptmpKey[i][j];
//							if (locktmp[i][j] != 1)
//							{
//								checkFlag = true;
//								okFlag = true;
//								break;
//							}
//						}
//						if (checkFlag)
//							break;
//					}
//
//					if (!okFlag)
//					{
//						answer = true;
//						break;
//					}
//				}
//				if (!okFlag)
//				{
//					break;
//				}
//			}
//		}
//	}
//
//	//왼쪽으로 아래로
//	if (answer == false)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			vector<vector<int>> tmpKey = key;
//
//			if (i != 0)//첫 번째의 경우에는 도형을 바꾸지 않는다.
//				moveRectangle(i, n, tmpKey);
//
//			for (int y = 0; y < n; y++)
//			{
//				bool okFlag = false;
//
//				for (int x = 0; x < n; x++)
//				{
//					okFlag = false;
//
//					vector<vector<int>> tmptmpKey = tmpKey;
//
//					/*if (y == 1 && x == 1)
//					{
//					getchar();
//					}*/
//
//					if (!(y == 0 && x == 0))
//					{
//						for (int i = 0; i < n; i++) //도형을 오른쪽 밑으로 움직이는 경우
//						{
//							for (int j = 0; j < n; j++)
//							{
//								if (!(i + y >= n || j - x < 0))
//								{
//									tmptmpKey[i + y][j - x] = tmptmpKey[i][j];
//								}
//								tmptmpKey[i][j] = 0;
//							}
//						}
//					}
//
//
//					for (int i = 0; i < n; i++) //돌린 도형을 확인하는 과정
//					{
//						vector < vector < int >> locktmp = lock;
//						bool checkFlag = false;
//						for (int j = 0; j < n; j++)
//						{
//							locktmp[i][j] += tmptmpKey[i][j];
//							if (locktmp[i][j] != 1)
//							{
//								checkFlag = true;
//								okFlag = true;
//								break;
//							}
//						}
//						if (checkFlag)
//							break;
//					}
//
//					if (!okFlag)
//					{
//						answer = true;
//						break;
//					}
//				}
//				if (!okFlag)
//				{
//					break;
//				}
//			}
//		}
//	}
//
//	//왼쪽으로 위로
//	if (answer == false)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			vector<vector<int>> tmpKey = key;
//
//			if (i != 0)//첫 번째의 경우에는 도형을 바꾸지 않는다.
//				moveRectangle(i, n, tmpKey);
//
//			for (int y = 0; y < n; y++)
//			{
//				bool okFlag = false;
//
//				for (int x = 0; x < n; x++)
//				{
//					okFlag = false;
//
//					vector<vector<int>> tmptmpKey = tmpKey;
//
//					/*if (y == 1 && x == 1)
//					{
//					getchar();
//					}*/
//
//					if (!(y == 0 && x == 0))
//					{
//						for (int i = 0; i < n; i++) //도형을 오른쪽 밑으로 움직이는 경우
//						{
//							for (int j = 0; j < n; j++)
//							{
//								if (!(i - y < 0 || j - x < 0))
//								{
//									tmptmpKey[i-y][j - x] = tmptmpKey[i][j];
//								}
//								tmptmpKey[i][j] = 0;
//							}
//						}
//					}
//
//
//					for (int i = 0; i < n; i++) //돌린 도형을 확인하는 과정
//					{
//						vector < vector < int >> locktmp = lock;
//						bool checkFlag = false;
//						for (int j = 0; j < n; j++)
//						{
//							locktmp[i][j] += tmptmpKey[i][j];
//							if (locktmp[i][j] != 1)
//							{
//								checkFlag = true;
//								okFlag = true;
//								break;
//							}
//						}
//						if (checkFlag)
//							break;
//					}
//
//					if (!okFlag)
//					{
//						answer = true;
//						break;
//					}
//				}
//				if (!okFlag)
//				{
//					break;
//				}
//			}
//		}
//	}
//	return answer;
//}
