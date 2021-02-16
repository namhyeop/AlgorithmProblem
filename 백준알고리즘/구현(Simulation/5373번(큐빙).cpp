#include<bits/stdc++.h>
#define MAX 3
using namespace std;

int N;
string color = "wyrogb";
string flip;
char cube[6][3][3];
char copy2d[3][3];


void clockwise(int num)
{
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		copy2d[i][j] = cube[num][i][j];

	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		cube[num][i][j] = copy2d[3-1-j][i];
}

void counterClockwise(int num)
{
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		copy2d[i][j] = cube[num][i][j];

	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		cube[num][i][j] = copy2d[j][3 - 1 - i];
}

void U(int num)
{
	char temp[3];

	for (int i = 0; i < 3; i++)
		temp[i] = cube[4][num][i];
	for (int i = 0; i < 3; i++)
		cube[4][num][i] = cube[2][num][i];
	for (int i = 0; i < 3; i++)
		cube[2][num][i] = cube[5][num][i];
	for (int i = 0; i < 3; i++)
		cube[5][num][i] = cube[3][num][i];
	for (int i = 0; i < 3; i++)
		cube[3][num][i] = temp[i];
}


void D(int num)
{
	char temp[3];
	for (int i = 0; i < 3; i++)
		temp[i] = cube[4][num][i];
	for (int i = 0; i < 3; i++)
		cube[4][num][i] = cube[3][num][i];
	for (int i = 0; i < 3; i++)
		cube[3][num][i] = cube[5][num][i];
	for (int i = 0; i < 3; i++)
		cube[5][num][i] = cube[2][num][i];
	for (int i = 0; i < 3; i++)
		cube[2][num][i] = temp[i];
}

void F(int num)
{
	char temp[3];
	int idx = (num == 0 ? 2 : 0);

	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][num][i];
	for (int i = 0; i < 3; i++)
		cube[0][num][i] = cube[4][2 - i][num];
	for (int i = 0; i < 3; i++)
		cube[4][i][num] = cube[1][idx][i];
	for (int i = 0; i < 3; i++)
		cube[1][idx][i] = cube[5][2 - i][idx];
	for (int i = 0; i < 3; i++)
		cube[5][i][idx] = temp[i];
}

void B(int num)
{
	char temp[3];

	int idx = (num == 0 ? 2 : 0);
	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][num][i];
	for (int i = 0; i < 3; i++)
		cube[0][num][i] = cube[5][i][idx];
	for (int i = 0; i < 3; i++)
		cube[5][i][idx] = cube[1][idx][2 - i];
	for (int i = 0; i < 3; i++)
		cube[1][idx][i] = cube[4][i][num];
	for (int i = 0; i < 3; i++)
		cube[4][i][num] = temp[2 - i];
}

void L(int num)
{
	char temp[3];
	int idx = (num == 0 ? 2 : 0);

	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][i][num];
	for (int i = 0; i < 3; i++)
		cube[0][i][num] = cube[3][2 - i][idx];
	for (int i = 0; i < 3; i++)
		cube[3][i][idx] = cube[1][2 - i][num];
	for (int i = 0; i < 3; i++)
		cube[1][i][num] = cube[2][i][num];
	for (int i = 0; i < 3; i++)
		cube[2][i][num] = temp[i];
}

void R(int num)
{
	int temp[3];
	int idx = (num == 0 ? 2 : 0);
	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][i][num];
	for (int i = 0; i < 3; i++)
		cube[0][i][num] = cube[2][i][num];
	for (int i = 0; i < 3; i++)
		cube[2][i][num] = cube[1][i][num];
	for (int i = 0; i < 3; i++)
		cube[1][i][num] = cube[3][2 - i][idx];
	for (int i = 0; i < 3; i++)
		cube[3][i][idx] = temp[2 - i];
}

int main(void)
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
		for (int k = 0; k < 3; k++)
			cube[i][j][k] = color[i];

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> flip;

			switch (flip[0])
			{
			case 'U':
				if (flip[1] == '+')
				{
					clockwise(0);
					U(0);

				}
				else
				{
					counterClockwise(0);
					D(0);
				}
				break;

			case 'D':
				if (flip[1] == '+')
				{
					clockwise(1);
					D(2);
				}
				else
				{
					counterClockwise(1);
					U(2);
				}
				break;

			case 'F':
				if (flip[1] == '+')
				{
					clockwise(2);
					F(2);
				}
				else
				{
					counterClockwise(2);
					B(2);
				}
				break;

			case 'B':
				if (flip[1] == '+')
				{
					clockwise(3);
					B(0);
				}
				else
				{
					counterClockwise(3);
					F(0);
				}
				break;

			case 'L':
				if (flip[1] == '+')
				{
					clockwise(4);
					L(0);
				}
				else
				{
					counterClockwise(4);
					R(0);
				}
				break;
			case 'R':
				if (flip[1] == '+')
				{
					clockwise(5);
					R(2);
				}
				else
				{
					counterClockwise(5);
					L(2);
				}
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << cube[0][i][j];
			cout << "\n";
		}
	}
	return 0;
}
