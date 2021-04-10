#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int ret = 0;

void DFS(vector<int> &numbers, int &target, int level, int sum)
{
	if (level == numbers.size() - 1)
	{
		if (sum == target)
			ret++;
		return;
	}
	DFS(numbers, target, level + 1, sum + numbers[level + 1]);
	DFS(numbers, target, level + 1, sum - numbers[level + 1]);
}

int solution(vector<int> numbers, int target)
{
	int answer = 0;
	int level = 0;
	DFS(numbers, target, 0, numbers[level]);
	DFS(numbers, target, 0, -numbers[level]);
	answer = ret;
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a = { 1, 1, 1, 1, 1 };
	int target = 3;
	cout << solution(a, target) << "\n";

	return 0;
}
