#include<bits/stdc++.h>
#define MAX 51
#define PLAYER_NUM 10
using namespace std;

int n, answer;
int order[PLAYER_NUM];
int game[MAX][PLAYER_NUM];
bool selec[PLAYER_NUM];
vector<int> v;

int cmd(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void Play_the_Game()
{
	int score = 0;
	int start_player = 1;
	int base_state[4];

	for (int i = 1; i <= n; i++)
	{
		int out_cnt = 0;
		bool next_ining = false;
		memset(base_state, 0, sizeof(base_state));

		while (1)
		{
			for (int j = start_player; j < PLAYER_NUM; j++)
			{
				int player = game[i][order[j]];

				if (player == 0)
					out_cnt++;
				else if (player == 1)
				{
					for (int F = 3; F >= 1; F--)
					{
						if (base_state[F] == 1)
						{
							if (F == 3)
							{
								base_state[F] = 0;
								score++;
							}
							else
							{
								base_state[F + 1] = 1;
								base_state[F] = 0;
							}
						}
					}
					base_state[1] = 1;
				}
				else if (player == 2)
				{
					for (int F = 3; F >= 1; F--)
					{
						if (base_state[F] == 1)
						{
							if (F == 3 || F == 2)
							{
								base_state[F] = 0;
								score++;
							}
							else
							{
								base_state[F + 2] = 1;
								base_state[F] = 0;
							}
						}
					}
					base_state[2] = 1;
				}
				else if (player == 3)
				{
					for (int s = 3; s >= 1; s--)
					{
						if (base_state[s] == 1)
						{
							base_state[s] = 0;
							score++;
						}
					}
					base_state[3] = 1;
				}
				else
				{
					for (int F = 1; F <= 3; F++)
					{
						if (base_state[F] == 1)
						{
							base_state[F] = 0;
							score++;
						}
					}
					score++;
				}
				if (out_cnt == 3)
				{
					start_player = j + 1;
					if (start_player == PLAYER_NUM)
						start_player = 1;

					next_ining = true;
					break;
				}
			}
			if (next_ining == true)
				break;
			start_player = 1;
		}
	}
	answer = cmd(answer, score);
}
void DFS(int cnt)
{
	if (cnt == PLAYER_NUM)
	{
		Play_the_Game();
		return;
	}

	for (int i = 1; i < PLAYER_NUM; i++)
	{
		if (selec[i] == true)
			continue;
		selec[i] = true;
		order[i] = cnt;
		DFS(cnt + 1);
		selec[i] = false;
	}
}
int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < PLAYER_NUM; j++)
		{
			cin >> game[i][j];
		}
	}

	selec[4] = true;
	order[4] = 1;
	DFS(2);
	cout << answer << "\n";
}
