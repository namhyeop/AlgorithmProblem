#include<iostream>

//알고리즘
//1.시작 채널은 P로 시작한다.
//2.채널을 싫어하는 사람이 그 채널을 끄고 자기가 좋아하는 채널로 바꾼다.
//3.바꾼 채널을 싫어하는 사람이 그 채널을 또 바꾼다.
//4.바꾼 경우가 Cycle이 발생하면 -1을 출력해야한다.
//5.싫어하는 채널이 중첩될 경우에는 첫 번째로 입력받은 사람의 입력값으로 설정해야한다.
using namespace std;

int N;
int M;
int P;
bool visited[100001];
int board[100001];

int dfs(int i)
{
	visited[i] = true;

	int next = board[i];
	if (next == 0)
		return 0;

	if (visited[next])
		return -1;

	int nextdfs = dfs(next);

	if (nextdfs == -1)
		return -1;
	else
		return nextdfs + 1;
}
int main(int argc, char *argv[])
{
	cin >> N >> M >> P;

	for (int i = 0; i < N; i++)
	{
		int likeCh;
		int hateCh;
		cin >> likeCh >> hateCh;

		if (board[hateCh] == 0)
			board[hateCh] = likeCh;
	}

	cout << dfs(P);
	return 0;
}
