#include<bits/stdc++.h>

using namespace std;

int board1[21][21];
int board2[21][21];
int n;

void rotate()
{
	int tmp[21][21];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		tmp[i][j] = board2[i][j];

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		board2[i][j] = tmp[n - 1 - j][i];

	//cout << "돌린값" << "\n";
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//		cout << board2[i][j] << " ";
	//	cout << "\n";
	//}
}

void tilt(int dir)
{
	/*cout << "첫 번째 dir" << dir << "\n";
	cout << "\n";*/

	while (dir--)
	{
	/*	cout << "감소 후 dir" << dir << "\n";*/
		rotate();
	}
		for (int i = 0; i < n; i++)
	{
		int tilted[21] = {}; // board2[i]를 왼쪽으로 기울인 결과를 저장할 변수
		int idx = 0; // tilted 배열에서 어디에 삽입해야 하는지를 가리키는 변수
		for (int j = 0; j < n; j++)
		{
			if (board2[i][j] == 0)
				continue;
			if (tilted[idx] == 0) //삽입할 위치가 비어있을 경우
				tilted[idx] = board2[i][j];
			else if (tilted[idx] == board2[i][j])//같은 값의 블록을 만날 경우
				tilted[idx++] *= 2;
			else
				tilted[++idx] = board2[i][j];
		}
		for (int j = 0; j < n; j++)
			board2[i][j] = tilted[j];

		/*for (int j = 0; j < n; j++)
			cout << board2[i][j] << " ";
		cout << "\n";
		cout << "\n";*/
	}
}
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board1[i][j];

	int mx = 0;
	for (int tmp = 0; tmp < 1024; tmp++) //5번의 방향을 이동하기에 4^5개의 경우의 수 발생
	{
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board2[i][j] = board1[i][j];
		int brute = tmp;
		/*cout << "brute는  " << brute << '\n';
		cout << "\n";*/
		for (int i = 0; i < 5; i++)
		{
			int dir = brute % 4;
			/*cout << "들어가기전 dir " << dir << '\n';
			cout << "\n";*/
			brute /= 4;
			tilt(dir);
		}
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mx = max(mx, board2[i][j]);
	}
	cout << mx;
}
