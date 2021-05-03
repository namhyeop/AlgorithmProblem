#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

struct pos
{
	int y;
	int x;
};

int M, N;
vector<string> m_board;
vector<vector<pos>> alpha_pos;
int moveY[] = { 1, 0, -1, 0 };
int moveX[] = { 0, 1, 0, -1 };

bool reachable(char c, pos from, pos to)
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = from.x + moveX[i];
		int nextY = from.y + moveY[i];
		while (!(nextY < 0 || nextY >= M || nextX < 0 || nextX >= N))
		{
			if (nextX == to.x && nextY == to.y)
				return true;
			if (m_board[nextY][nextX] != '.')
				break;
			
			for (int j = ((i + 1) % 2); j < 4; j += 2)
			{
				int nnx = nextX + moveX[j];
				int nny = nextY + moveY[j];

				while (!(nnx < 0 || nnx >= N || nny < 0 || nny >= M))
				{
					if (nnx == to.x && nny == to.y)
						return true;
					if (m_board[nny][nnx] != '.')
						break;

					nnx += moveX[j];
					nny += moveY[j];
				}
			}

			nextX += moveX[i];
			nextY += moveY[i];
		}
	}
	return false;
}

bool game(string &answer, int left)
{
	while (true)
	{
		bool match = false;

		for (int i = 0; i < 26; i++)
		{
			if (!alpha_pos[i].empty())
			{
				char c = i + 'A';
				pos from = alpha_pos[i][0];
				pos to = alpha_pos[i][1];

				if (reachable(c, from, to))
				{
					answer += c;

					m_board[from.y][from.x] = '.';
					m_board[to.y][to.x] = '.';
					alpha_pos[i].clear();
					match = true;
					left -= 2;
					break;
				}
			}
		}

		if (!match)
			break;
	}
	return (left == 0);
}
string solution(int m, int n, vector<string> board)
{
	M = m;
	N = n;
	m_board = board;
	alpha_pos = vector<vector<pos>>(26);

	int left = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isalpha(board[i][j]))
			{
				left++;
				alpha_pos[board[i][j] - 'A'].push_back({ i, j });
			}
		}
	}
	
	string answer = "";
	if (game(answer, left))
	{
		return answer;
	}
	return "IMPOSSIBLE";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m = 3;
	int n = 3;
	vector<string> board = { "DBA", "C*A", "CDB" };
	cout << solution(m, n, board) << "\n";

	m = 2;
	n = 4;
	board = { "NRYN", "ARYA" };
	cout << solution(m, n, board) << "\n";

	m = 4;
	n = 4;
	board = { ".ZI.", "M.**", "MZU.", ".IU." };
	cout << solution(m, n, board) << "\n";

	m = 2;
	n = 2;
	board = { "AB", "BA" };
	cout << solution(m, n, board) << "\n";
}
