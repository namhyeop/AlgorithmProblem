#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
#define MAX 51
using namespace std;

typedef struct
{
	int y, x, s;
}state;

int n, m, k;
int board[MAX][MAX];
vector<int> spins;
map<int, state> spinMap;
int ret = INT_MAX;

void func(int board[][MAX], int idx)
{
	if (idx == k)
	{
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < m; j++)
				sum += board[i][j];

			ret = min(ret, sum);
		}
		return;
	}
	
	int copyboard[MAX][MAX];

	for (int i = 0; i < n; i++) 
	for (int j = 0; j < m; j++)
	{
		copyboard[i][j] = board[i][j];
	}

	state st = spinMap[spins[idx]];
	int y = st.y;
	int x = st.x;

	
	//상,우,하,좌 순으로 자리값 이동
	for (int i = 1; i <= st.s; i++)
	{
		for (int j = -i + 1; j <= i; j++)
			board[y - i][x + j] = copyboard[y - i][x + j - 1];

		for (int j = -i + 1; j <= i; j++)
			board[y + j][x + i] = copyboard[y + j - 1][x + i];

		for (int j = i - 1; j >= -i; j--)
			board[y + i][x + j] = copyboard[y + i][x + j + 1];

		for (int j = i - 1; j >= -i; j--)
			board[y + j][x - i] = copyboard[y + j + 1][x - i];
	}

	func(board, idx + 1);
}

int main(int argc, char *argv[])
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	for (int i = 0; i < k; i++)
	{
		state tmp;
		cin >> tmp.y >> tmp.x >> tmp.s;

		tmp.y--;
		tmp.x--;

		spins.push_back(i); //spins로 회전연산이 일어나는 모든 경우의 수를 계산한다.
		spinMap[i] = tmp; //spinMap에 회전연산의 입력값을 저장한다. spins의 값의로 회전연산의 수와 일치시킨다.	
	}

	do
	{
		int copyboard[MAX][MAX];

		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			copyboard[i][j] = board[i][j];
		}
		func(copyboard, 0);
	} while (next_permutation(spins.begin(), spins.end()));

	cout << ret << "\n";
	return 0;
}
