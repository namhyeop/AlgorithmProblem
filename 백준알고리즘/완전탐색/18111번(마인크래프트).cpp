#include<iostream>
#include <climits>
#define MAX 501
using namespace std;

int height;
int width;
int ownBlock;

int board[MAX][MAX] = { 0, };

int main(int argc, char * argv[])
{
	cin >> height >> width >> ownBlock;

	int minValue = INT_MAX;
	int maxValue = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> board[i][j];

			if (board[i][j] < minValue)
				minValue = board[i][j];

			if (board[i][j] > maxValue)
				maxValue = board[i][j];
		}
	}

	int time = INT_MAX;
	int length = 0;

	for (int i = minValue; i <= maxValue; i++)
	{
		int sum_build = 0;
		int sum_remove = 0;

		for (int j = 0; j < height; j++)
		{
			for (int k = 0; k < width; k++)
			{
				int temp = i - board[j][k];

				if (temp < 0)
					sum_remove += temp * -1;
				else
					sum_build += temp;
			}
		}

		if (sum_build <= sum_remove + ownBlock)
		{
			int temp = sum_build + sum_remove * 2;
			if (time > temp)
			{
				time = temp;
				length = i;
			}

			if (temp == time)
			if (length < i)
			{
				length = i;
			//	cout << "newi " << "length" << "\n";
			}
		}
	}
	cout << time << " " << length;

	return 0;
}
