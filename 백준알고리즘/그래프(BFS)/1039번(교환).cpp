#include<iostream>
#include<queue>

using namespace std;
#define MAX 1000001

int N; //문제의 숫자
int K; //연산 횟수
int M; //정수 N의 자릿수를 의미


// 정수 n의 10^i자리의 숫자 리턴
int digit(int n, int i)
{
	for (int k = 0; k < i; k++)
		n /= 10;
	return n % 10;
}

int swapDigit(int n, int i, int j)
{
	char S[8];
	sprintf(S, "%d", n);
	swap(S[M - i - 1], S[M - j - 1]);
	sscanf(S, "%d", &n);
	return n;
}

int bfs()
{
	int ret = -1;
	queue<int> q;
	q.push(N);

	for (int i = 0; i < K; i++)
	{
		int qSize = q.size();
		bool visited[MAX] = { 0 };

		for (int j = 0; j < qSize; j++)
		{
			int curr = q.front();
			q.pop();

			for (int k = 0; k < M - 1; k++)
			for (int l = k + 1; l < M; l++)
			{
				if (l < M - 1 || digit(curr, k))
				{
					int next = swapDigit(curr, k, l);
					if (!visited[next])
					{
						visited[next] = true;
						q.push(next);
					}
				}
			}
		}
	}

	while (!q.empty())
	{
		ret = max(ret, q.front());
		q.pop();
	}

	return ret;
}
int main(int argc, char *argv[])
{
	cin >> N >> K;

	//N의 자릿수를 알기 위한 연산이다, 나누기를 진행한만큼 카운팅을 진행.
	int tmp = N;
	while (tmp)
	{
		M++;
		tmp /= 10;
	}

	int ret = bfs();

	cout << ret << "\n";
}
