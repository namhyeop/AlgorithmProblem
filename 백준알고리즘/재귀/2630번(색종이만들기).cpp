#include<bits/stdc++.h>
#define MAX 128
using namespace std;

int n;
int board[MAX][MAX];

int whitePaper;
int bluePaper;
void divide(int startY, int startX, int endY, int endX)
{
	bool flag = true;
	int paper = board[startY][startX];
	for (int i = startY; i < endY; i++)
	{
		for (int j = startX; j < endX; j++)
		{
			if (paper == 1 && board[i][j] == 0)
				flag = false;
			else if (paper == 0 && board[i][j] == 1)
				flag = false;

			if (!flag)
			{
				divide(startY, startX, (startY+endY) / 2, (startX + endX) / 2);
				divide(startY, (startX + endX)/2, (startY+endY) / 2, endX);
				divide((startY + endY)/2, startX , endY, (startX+endX) / 2);
				divide((startY + endY)/2, (startX +endX)/2, endY, endX);
				return;
			}
		}
	}

	if (paper == 1)
		bluePaper++;
	else if (paper == 0)
		whitePaper++;

	return;
}
int main(int argc, char*argv[])
{
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];

	divide(0, 0, n, n);

	cout << whitePaper << "\n";
	cout << bluePaper << "\n";

	return 0;
}
