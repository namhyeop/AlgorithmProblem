#include<iostream>

using namespace std;

int N;
int S[100000];
int vaildcnt;
bool visited[100000];
bool finished[100000];

void dfs(int curr)
{
	visited[curr] = true;
	int next = S[curr];
	if (visited[next])
	{
		if (!finished[next])
		{
			for (int temp = next; temp != curr; temp = S[temp])
				vaildcnt++;
			vaildcnt++; //자기 자신 더 해주기
		}
	}
	else
		dfs(next);
	finished[curr] = true;
}
int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> S[i];
			S[i]--;
		}

		fill(visited, visited + N, false);
		fill(finished, finished + N, false);
		vaildcnt = 0;
		for (int i = 0; i < N; i++)
		if (!visited[i])
			dfs(i);

		int ret = N - vaildcnt;
		cout << ret << "\n";
	}
}
