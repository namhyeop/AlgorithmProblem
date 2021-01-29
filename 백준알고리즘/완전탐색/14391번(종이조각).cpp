#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int n, m;
int a[4][4];
bool check[4][4];
int xy[4][4];
vector<int> ans;

int dfs(int x, int y, int sum)
{
	check[x][y] = true;
	if (xy[x][y] == 0)
	{
		if (y + 1 < m && xy[x][y] == xy[x][y + 1] && !check[x][y + 1])
			sum = dfs(x, y + 1, (sum * 10) + a[x][y]);
		else
			return sum * 10 + a[x][y];
	}
	if (xy[x][y] == 1)
	{
		if (x + 1 < n && xy[x][y] == xy[x + 1][y] && !check[x + 1][y])
			sum = dfs(x + 1, y, (sum * 10) + a[x][y]);
		else
			return sum * 10 + a[x][y];
	}
	return sum;
}

int makeSum()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if (!check[i][j])
			sum += dfs(i, j, 0);
	}
	return sum;
}

void go(int index)
{

	cout << "함수들어간후";
	cout << index << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << xy[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

	if (index == m*n)
	{
		memset(check, false, sizeof(check));
		ans.push_back(makeSum());
		return ;
	}
	//cout << "\n";
	xy[index / m][index % m] = 1;

	cout << "함수들어가기전";
	cout << index << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << xy[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
	go(index + 1);
	xy[index / m][index % m] = 0;

	cout << "함수들어가기전";
	cout << index << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << xy[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
	go(index + 1);
}

int main(int argc, char*argv[])
{
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			a[i][j] = str[j] - '0';
	}

	go(0);

	auto max = max_element(ans.begin(), ans.end());
	cout << *max << "\n";

	return 0;
}
