#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 1e8;
bool visitedNum[MAX];
int visited[7];
string testValue;
int answer;

bool isValied(int testValue)
{
	if (testValue == 0 || testValue == 1)
		return false;
	for (int i = 2; i < testValue; i++)
	if (testValue % i == 0)
		return false;

	return true;
}

void backTrack(int level, int size, string numbers)
{
	if (level == size)
	{
		if (isValied(stoi(testValue)) && !visitedNum[stoi(testValue)])
		{
			visitedNum[stoi(testValue)] = true;
			answer++;
		}
		return;
	}

	for (int i = 0; i < numbers.size(); i++)
	{
		if (visited[i])
			continue;

		testValue += numbers[i];
		visited[i] = true;
		backTrack(level + 1, size, numbers);
		visited[i] = false;
		testValue.pop_back();
	}
}
int solution(string numbers)
{

	for (int i = 1; i <= numbers.size(); i++)
	{
		backTrack(0, i, numbers);
	}

	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string numbers;

	numbers = "011";

	solution(numbers);
	cout << answer << "\n";

}
