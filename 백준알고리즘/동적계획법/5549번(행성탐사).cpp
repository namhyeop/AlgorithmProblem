#include<iostream>
#include<string>
#include<vector>
#include<queue>
#define MAX 1001

using namespace std;

int height;
int width;
int K;
int a, b, c, d;
char board[MAX][MAX];
int cJungle[MAX][MAX];
int cOcean[MAX][MAX];
int cIce[MAX][MAX];

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> height >> width;
	cin >> K;

	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'J')
			{
				cJungle[i][j] = cJungle[i - 1][j] + cJungle[i][j - 1] - cJungle[i - 1][j - 1] + 1;
				cOcean[i][j] = cOcean[i - 1][j] + cOcean[i][j - 1] - cOcean[i - 1][j - 1];
				cIce[i][j] = cIce[i - 1][j] + cIce[i][j - 1] - cIce[i - 1][j - 1];
				
				/*누적합 확인 디버깅
				cout << i << " " << j << "\n";
				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= width; j++)
						cout << cJungle[i][j] << " ";
					cout << "\n";
				}
				cout << "\n";

				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= width; j++)
						cout << cOcean[i][j] << " ";
					cout << "\n";
				}
				cout << "\n";

				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= width; j++)
						cout << cIce[i][j] << " ";
					cout << "\n";
				}*/
			}
			else if (board[i][j] == 'O')
			{
				cJungle[i][j] = cJungle[i - 1][j] + cJungle[i][j - 1] - cJungle[i - 1][j - 1];
				cOcean[i][j] = cOcean[i - 1][j] + cOcean[i][j - 1] - cOcean[i - 1][j - 1] + 1;
				cIce[i][j] = cIce[i - 1][j] + cIce[i][j - 1] - cIce[i - 1][j - 1];
				
				/*누적합 확인 디버깅
				cout << i << " " << j << "\n";
				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= width; j++)
						cout << cJungle[i][j] << " ";
					cout << "\n";
				}
				cout << "\n";

				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= width; j++)
						cout << cOcean[i][j] << " ";
					cout << "\n";
				}
				cout << "\n";

				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= width; j++)
						cout << cIce[i][j] << " ";
					cout << "\n";
				}*/
			}
			else
			{
				cJungle[i][j] = cJungle[i - 1][j] + cJungle[i][j - 1] - cJungle[i - 1][j - 1];
				cOcean[i][j] = cOcean[i - 1][j] + cOcean[i][j - 1] - cOcean[i - 1][j - 1];
				cIce[i][j] = cIce[i - 1][j] + cIce[i][j - 1] - cIce[i - 1][j - 1] + 1;
			
				/* 누적합 확인 디버깅
				cout << i << " " << j << "\n";
				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= width; j++)
						cout << cJungle[i][j] << " ";
					cout << "\n";
				}
				cout << "\n";

				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= width; j++)
						cout << cOcean[i][j] << " ";
					cout << "\n";
				}
				cout << "\n";

				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= width; j++)
						cout << cIce[i][j] << " ";
					cout << "\n";
				}*/
			}
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> c >> d;
		cout << cJungle[c][d] - cJungle[c][b - 1] - cJungle[a - 1][d] + cJungle[a - 1][b - 1] << " ";
		cout << cOcean[c][d] - cOcean[c][b - 1] - cOcean[a - 1][d] + cOcean[a - 1][b - 1] << " ";
		cout << cIce[c][d] - cIce[c][b - 1] - cIce[a - 1][d] + cIce[a - 1][b - 1] << "\n";
	}

	return 0;
}

/* BFS식 탐사 - 시간초과 발생
int height;
int width;
int K;
string board[MAX];
queue <pair<pair<int, int>, pair<int, int>>> q;

void search()
{
	while (!q.empty())
	{
		int jungle = 0, ocean = 0, ice = 0;
		int y1 = q.front().first.first;
		int x1 = q.front().first.second;
		int y2 = q.front().second.first;
		int x2 = q.front().second.second;
		q.pop();

		for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++)
		{
			if (board[i][j] == 'J')
				jungle++;
			else if (board[i][j] == 'O')
				ocean++;
			else
				ice++;
		}

		cout << jungle << " " << ocean << " " << ice << "\n";
	}
}

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> height >> width;
	cin >> K;

	for (int i = 0; i < height; i++)
		cin >> board[i];

	for (int j = 0; j < K; j++)
	{
		int a, b, c, d;

		cin >> a >> b >> c >> d;
		int y1 = a-1;
		int x1 = b-1;
		int y2 = c-1;
		int x2 = d-1;

		int jungle = 0, ocean = 0, ice = 0;
		for (int i = y1; i <= y2; i++)
		for (int j = x1; j <= x2; j++)
		{
			if (board[i][j] == 'J')
				jungle++;
			else if (board[i][j] == 'O')
				ocean++;
			else
				ice++;
		}

		cout << jungle << " " << ocean << " " << ice << "\n";
	}

	return 0;
}
*/
