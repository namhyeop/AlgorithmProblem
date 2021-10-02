#include<bits/stdc++.h>

using namespace std;

int n,ans;
int efficacy[10][4][4][4];
char element[10][4][4][4];
bool visited[10];

struct state
{
	int eff;
	char ele;
	state(){}
	state(int _eff, char _ele) : eff(_eff), ele(_ele) {}
};

vector<vector<state>> board(5, vector<state>(5));

void rotateArr(int type, int dir)
{
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		efficacy[type][dir][i][j] = efficacy[type][dir-1][3 - j][i];
		element[type][dir][i][j] = element[type][dir - 1][3 - j][i];
	}
}

int getQuality(vector<vector<state>> v)
{
	int red = 0, blu = 0, grn = 0, yel = 0;

	for (int i = 0; i < 5; i++)
	for (int j = 0; j < 5; j++)
	{
		switch (v[i][j].ele)
		{
		case 'R':
			red += v[i][j].eff;
			break;
		case 'B':
			blu += v[i][j].eff;
			break;
		case 'G':
			grn += v[i][j].eff;
			break;
		case 'Y':
			yel += v[i][j].eff;
			break;
		default:
			break;
		}
	}
	return 7 * red + 5 * blu + 3 * grn + 2 * yel;
}
vector<vector<state>> putMaterial(vector<vector<state>> v, int row, int col, int type, int dir)
{
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		v[row + i][col + j].eff += efficacy[type][dir][i][j];

		if (v[row + i][col + j].eff < 0)
			v[row + i][col + j].eff = 0;
		else if (v[row + i][col + j].eff > 9)
			v[row + i][col + j].eff = 9;

		if (element[type][dir][i][j] != 'W')
		{
			v[row + i][col + j].ele = element[type][dir][i][j];
		}
	}
	return v;
}

void dfs(vector<vector<state>> v, int cnt)
{
	if (cnt == 3)
	{
		ans = max(ans, getQuality(v));
		return;
	}

	for (int t = 0; t < n; t++)
	{
		if (!visited[t])
		{
			visited[t] = true;
			for (int i = 0; i <= 1; i++)
			{
				for (int j = 0; j <= 1; j++)
				{
					for (int d = 0; d < 4; d++)
					{
						//vector,row,col,type(좌표의 존재 경우),dir
						vector<vector<state>> tmp = putMaterial(v, i, j, t, d);
						dfs(tmp, cnt + 1);
					}
				}
			}
			visited[t] = false;
		}
	
	}

}
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
			cin >> efficacy[i][0][j][k];

		for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
			cin >> element[i][0][j][k];

		for (int d = 1; d <= 3; d++)
			rotateArr(i, d);
	}
	
	for (int i = 0; i < 5; i++)
	for (int j = 0; j < 5; j++)
		board[i][j] = state(0, 'W');
	
	ans = INT_MIN;

	dfs(board, 0);

	cout << ans << "\n";
}
