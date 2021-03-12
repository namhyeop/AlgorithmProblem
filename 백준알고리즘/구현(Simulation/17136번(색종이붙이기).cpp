#include<bits/stdc++.h>
#define MAX 10
using namespace std;

int board[MAX][MAX];
int ret;
int cnt;
int paper[6] = { 0, 5, 5, 5, 5, 5 }; //종이들의 갯수를 나타내는 배열

void search(int y, int x)
{
	//현재 줄에 대한 탐색이 끝났으므로 다음줄 탐색으로 진행한다.
	if (x == MAX)
	{
		search(y + 1, 0);
		return;  
	}

	//맨 밑 단계까지 탐색이 끝났으므로 색종이의 갯수를 반환한다.
	if (y == MAX)
	{
		ret = min(ret, cnt);
		return;
	}

	if (board[y][x] == 0)
	{
		search(y, x + 1);
		return;
	}
	for (int len = 5; len >= 1; len--)
	{
		//현재 길이의 조이가 없거나 범위를 넘게 덮을 경우 
		if (paper[len] == 0 || y + len > MAX || x + len > MAX)
			continue;

		bool flag = true;
		for (int j = 0; j < len; j++)
		{
			for (int k = 0; k < len; k++)
			{
				if (board[y + j][x + k] == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag == false)
				break;
		}
		if (flag == false)
			continue;

		for (int j = 0; j < len; j++)
		for (int k = 0; k < len; k++)
			board[y + j][x + k] = 0;

		paper[len]--;
		cnt++;

		search(y, x + len);

		for (int j = 0; j < len; j++)
		for (int k = 0; k < len; k++)
			board[y + j][x + k] = 1;
		
		paper[len]++;
		cnt--;
	}
}
int main()
{
	for (int i = 0; i < MAX; i++)
	for (int j = 0; j < MAX; j++)
		cin >> board[i][j];
	
	ret = INT_MAX;
	search(0, 0);

	if (ret == INT_MAX)
		cout << -1 << "\n";
	else
		cout << ret << "\n";
	
	return 0;
}
