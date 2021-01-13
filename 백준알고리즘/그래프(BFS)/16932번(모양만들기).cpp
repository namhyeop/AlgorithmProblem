#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 1000

using namespace std;

/*
개인적으로 너무 어려웠던 문제.
배열값으로 다음 배열값을 찾아서 문제를 해결하는 이런 종류의 문제를 예전부터
약하다는것을 알고는 있었지만 여기에 + BFS 탐색을 해야 하는 문제다 보니 너무 힘들었다.
처음에는 BFS 탐색을 한 (x,y)값 마다 다 할려고 했으나 실행시간 초과로 실패했다. (안 될줄 알면서도 이 방법말고는 생각이 안남)

이 문제를 해결하기 위한 최적의 알고리즘은
1. 입력으로 들어온 위치에서 1인 것은 모양이 있는 것이므로 위치값을 저장하고
2. 저장한 위치값에서 BFS를 실시하여 모양마다 고유의 번호를 부여해준다.
3. 고유의 번호로 입력으로 받은 배열(board)에서 값을 변경해주고 고유의 모양의 사이즈를 따로 배열(W)에 저장한다.
4. 우리는 0의 위치에서 한 개를 바꿔 최대 값을 찾는 것이므로 0의 위치만 따로 담아두었던 zero 배열에서 탐색을 실행하여 각 값의 최대값을 구한다.
5. 4번 과정에서 중복을 제거해주기 위한 정렬, 배열 두 가지를 활용한 탐색을 유의해서 살펴보자
*/
int height;
int width;
int ret;
int num;
int board[MAX][MAX];
bool visited[MAX][MAX];
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };

queue<pair<int,int>> q;
vector<pair<int,int>> zero;
vector<int> w; //영역별 크기를 정의하기 위한 백터

void BFS_Rename(int y, int x)//기존에 있던 그림의 묶여있는 그룹마다 다른 숫자를 지정해주는 과정(1 ~ 모양이있는갯수)
{
	int checkNum = 0; //지금 확인할 영영의 숫자의 개수
	q.push({ y, x });
	visited[y][x] = true;
	board[y][x] = num;

	while (!q.empty())
	{
		checkNum++;
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveY[i];
			int nextX = x + moveX[i];

			if (nextY >= 0 && nextY < height && nextX >=0 && nextX < width)
			if (!visited[nextY][nextX] && board[nextY][nextX] == 1)
			{
				q.push({ nextY, nextX });
				visited[nextY][nextX] = true;
				board[nextY][nextX] = num;
			}
		}
	}
	w.push_back(checkNum);
}

int main(int argc, char *argv[])
{
	cin >> height >> width;

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 0)
			zero.push_back({ i, j });
	}

	num = 1; //영역 표시 숫자
	w.push_back(0); // 0은 공간의 크기 정의가 아니므로 자릿수를 위한 삽입

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == 1 && !visited[i][j])
			{
				BFS_Rename(i, j);
				num++;
			}
		}
	}

	for (int i = 0; i < zero.size(); i++)
	{
		int value = 0;
		vector<int> v;

		for (int j = 0; j < 4; j++)
		{
			int nextY = zero[i].first + moveY[j];
			int nextX = zero[i].second + moveX[j];

			if (nextY >= 0 && nextY < height && nextX >= 0 && nextX < width)
			if (board[nextY][nextX] != 0)
				v.push_back(board[nextY][nextX]); //n그룹의 숫자를 만난것이므로 만난 그룹의 그룹명를 넣어준다.
		}
		
		if (!v.empty())
		{
			sort(v.begin(), v.end()); //방문의 중복을 제거해주기 위해 정렬을 한다.

			value += w[v[0]]; //v가 비어있지 않다는건 적어도 첫 번째 위치값은 있다는 뜻
			for (int k = 1; k < v.size(); k++)
			{

				/*
				110
				100
				010
				이런식으로 주어졌다고 생각해보자 탐색을
				*/
				if (v[k] == v[k - 1])
					continue;
				value += w[v[k]];
			}
		}
		ret = max(ret, value);
	}

	cout << ret + 1 << "\n";

	return 0;
}
