#include<bits/stdc++.h>

using namespace std;

int Testcase;
int ret;
int green[6][4];
int blue[4][6];

void greenOne(int x)
{
	int idx = 0;

	for (int y = 0; y < 6; y++)
	{
		if (green[y][x])
		{
			idx = y;
			break;
		}
	}
	if (idx == 0)
	{
		green[5][x] = 1;
		return;
	}
	green[idx - 1][x] = 1;
}

void blueOne(int y)
{
	int idx = 0;

	for (int x = 0; x < 6; x++)
	{
		if (blue[y][x])
		{
			idx = x;
			break;
		}
	}

	if (idx == 0)
	{
		blue[y][5] = 1;
		return;
	}

	blue[y][idx - 1] = 1;
}

void greenTwo(int x)
{
	int idx = 0;
	
	for (int y = 0; y < 6; y++)
	{
		if (green[y][x] || green[y][x + 1])
		{
			idx = y;
			break;
		}
	}

	if (idx == 0)
	{
		green[5][x] = 2;
		green[5][x + 1] = 2;
		return;
	}

	if (idx == 0)
	{
		green[5][x] = 2;
		green[5][x + 1] = 2;
		return;
	}

	green[idx - 1][x] = 2;
	green[idx - 1][x + 1] = 2;
}

void blueTwo(int y)
{
	int idx = 0;

	for (int x = 0; x < 6; x++)
	{
		if (blue[y][x])
		{
			idx = x;
			break;
		}
	}

	if (idx == 0)
	{
		blue[y][5] = 2;
		blue[y][4] = 2;
		return;
	}

	blue[y][idx - 1] = 2;
	blue[y][idx - 2] = 2;
}

void greenThree(int x)
{
	int idx = 0;

	for (int y = 0; y < 6; y++)
	{
		if (green[y][x])
		{
			idx = y;
			break;
		}
	}

	if (idx == 0)
	{
		green[5][x] = 3;
		green[4][x] = 3;
		return;
	}

	green[idx - 1][x] = 3;
	green[idx - 2][x] = 3;
}

void blueThree(int y)
{
	int idx = 0;

	for (int x = 0; x < 6; x++)
	{
		if (blue[y][x] || blue[y + 1][x])
		{
			idx = x;
			break;
		}
	}

	if (idx == 0)
	{
		blue[y][5] = 3;
		blue[y + 1][5] = 3;
		return;
	}

	blue[y][idx - 1] = 3;
	blue[y + 1][idx - 1] = 3;
}

void simul_green(void)
{
	bool flag = false;

	for (int y = 2; y < 6; y++)
	{
		bool lineCleard = true;

		for (int x = 0; x < 4; x++)
		{
			if (green[y][x] == false)
			{
				lineCleard = false;
				break;
			}
		}

		if (lineCleard == false)
			continue;

		ret++;

		for (int x = 0; x < 4; x++)
			green[y][x] = 0;
		
		flag = true;
	}

	if (flag == false)
		return;

	int idx = 0;

	for (int y = 4; y >= 0; y--)
	{
		for (int x = 0; x < 4; x++)
		{
			idx = 0;
			if (green[y][x] == 2)
			{
				for (int i = y + 1; i < 6; i++)
				{
					if (green[i][x] || green[i][x + 1])
					{
						idx = i;
						break;
					}
				}

				if (idx == 0)
				{
					green[5][x] = 2;
					green[5][x + 1] = 2;
					green[y][x] = 0;
					green[y][x + 1] = 0;
					x++;

					continue;
				}

				if (idx - 1 == y) //자기 자신일 경우 다음 탐색
				{
					x++;
					continue;
				}

				green[idx - 1][x] = 2;
				green[idx - 1][x + 1] = 2;
				green[y][x] = 0;
				green[y][x + 1] = 0;

				x++;

				continue;
			}
			
			for (int i = y + 1; i < 6; i++)
			{
				if (green[i][x])
				{
					idx = i;
					break;
				}
			}

			if (idx == 0)
			{
				green[5][x] = green[y][x];
				green[y][x] = 0;
				continue;
			}

			if (idx - 1 == y)
				continue;

			green[idx - 1][x] = green[y][x];
			green[y][x] = 0;
		}
	}

	simul_green();
}

void simulateBlue()
{
	bool flag = false;

	for (int x = 2; x < 6; x++)
	{
		bool lineCleared = true;

		for (int y = 0; y < 4; y++)
		{
			if (blue[y][x] == false)
			{
				lineCleared = false;
				break;
			}
		}

		if (lineCleared == false)
			continue;

		ret++;

		for (int y = 0; y < 4; y++)
			blue[y][x] = 0;

		flag = true;
	}

	if (flag == false)
		return;

	int idx = 0;

	for (int x = 4; x >= 0; x--)
	{
		for (int y = 0; y < 4; y++)
		{
			idx = 0;

			if (blue[y][x] == 3)
			{
				for (int i = x + 1; i < 6; i++)
				{
					if (blue[y][i] || blue[y + 1][i])
					{
						idx = i;
						break;
					}
				}

				if (idx == 0)
				{
					blue[y][5] = 3;
					blue[y + 1][5] = 3;
					blue[y][x] = 0;
					blue[y + 1][x] = 0;
					y++;
					continue;
				}
				if (idx - 1 == x)
				{
					y++;
					continue;
				}

				blue[y][idx - 1] = 3;
				blue[y+1][idx - 1] = 3;
				blue[y][x] = 0;
				blue[y + 1][x] = 0;
				y++;
				continue;
			}

			for (int i = x + 1; i < 6; i++)
			{
				if (blue[y][i])
				{
					idx = i;
					break;
				}
			}

			if (idx == 0)
			{
				blue[y][5] = blue[y][x];
				blue[y][x] = 0;
				continue;
			}

			if (idx - 1 == x)
				continue;

			blue[y][idx - 1] = blue[y][x];
			blue[y][x] = 0;
		}
	}
	simulateBlue();
}

int main(void)
{
	cin >> Testcase;

	for (int n = 0; n < Testcase; n++)
	{
		int t, y, x;
		cin >> t >> y >> x;

		int idx = 0;

		switch (t)
		{
		case 1:
			greenOne(x);
			blueOne(y);
			break;
		case 2:
			greenTwo(x);
			blueTwo(y);
			break;
		case 3:
			greenThree(x);
			blueThree(y);
			break;
		}

		simul_green();

		int specialGreenCnt = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (green[i][j])
				{
					specialGreenCnt++;
					break;
				}
			}
		}

		for (int k = 0; k < specialGreenCnt; k++)
		{
			for (int j = 0; j < 4; j++)
			{
				green[5][j] = 0;
			}

			for (int j = 0; j < 4; j++)
			{
				for (int i = 5; i > 0; i--)
					green[i][j] = green[i - 1][j];	
				green[0][j] = 0;
			}
		}

		simulateBlue();

		int specialBluecnt = 0;

		for (int j = 0; j < 2; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (blue[i][j])
				{
					specialBluecnt++;
					break;
				}
			}
		}

		for (int k = 0; k < specialBluecnt; k++)
		{
			for (int i = 0; i < 4; i++)
				blue[i][5] = 0;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 5; j > 0; j--)
					blue[i][j] = blue[i][j - 1];
				blue[i][0] = 0;
			}
		}
	}

	cout << ret << "\n";

	int cnt = 0;
	for (int y = 2; y < 6; y++)
	for (int x = 0; x < 4; x++)
	{
		if (green[y][x])
			cnt++;
	}

	for (int y = 0; y < 4; y++)
	for (int x = 2; x < 6; x++)
	{
		if (blue[y][x])
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}
