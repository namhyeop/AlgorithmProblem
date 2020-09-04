#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char *argv[])
{
	int boardSize; //보드 크기
	int appleNum; //사과 수
	int changeRoadNum;//방향 전환 횟수

	int board[101][101] = { 0, }; //0으로 초기화
	pair<int, char> changeRoad[101];//방향 변환

	const int apple = 1;
	const int snake = -1;

	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { 1, 0, -1, 0 };

	int cursor = 0; //방향 값

	board[0][0] = snake;
	pair<int, int> head = { 0, 0 };
	queue<pair<int, int>> snakeState;
	snakeState.push(head);

	cin >> boardSize;
	cin >> appleNum;

	for (int i = 0; i < appleNum; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = apple;
	}

	cin >> changeRoadNum; //방향 전환 횟수
	for (int i = 0; i < changeRoadNum; i++)
	{
		cin >> changeRoad[i].first >> changeRoad[i].second;
	}

	int sec = 0;

	int changeCursor = 0;// 반복횟수 및 새로운 뱀의 방향전환 초를 가져옴
	while (1)
	{
		sec++;
		int ny = head.first + dy[cursor];
		int nx = head.second + dx[cursor];

		if (nx < 0 || ny < 0 || nx >= boardSize || ny >= boardSize)
		{
			break;
		}
		else if (board[ny][nx] == snake)
		{
			break;
		}
		else if (board[ny][nx] != apple)
		{
			auto tail = snakeState.front();
			snakeState.pop();
			board[tail.first][tail.second] = 0;
		}

		head = { ny, nx };
		snakeState.push(head);

		board[ny][nx] = snake; //다시 반복문을 진행시 뱀의 몸통이면 종료시키게 설정하기 위해 현재 머리 위치를 -1로 남겨둠

		int newSec = changeRoad[changeCursor].first;
		if (changeCursor < changeRoadNum && newSec == sec)
		{
			char dir = changeRoad[changeCursor].second;
			if (dir == 'L')
			{
				cursor = (cursor + 3) % 4;
			}
			else if (dir == 'D')
			{
				cursor = (cursor + 1) % 4;
			}
			changeCursor++;
		}
	}
	cout << sec << endl;

	return 0;
}
