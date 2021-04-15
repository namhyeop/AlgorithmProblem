#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
bool visited[50001];

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end(), greater<int>());

	int idx = people.size() - 1;
	for (int i = 0; i < people.size(); i++)
	{
		if (limit >= people[i] + people[idx] && !visited[i])
		{
			visited[i] = true;
			visited[idx] = true;
			answer++;
			idx--;
		}
	}

	for (int i = 0; i < people.size(); i++)
	if (!visited[i])
	{
		answer++;
	}

	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> people = { 70,50, 80, 50 };
	int limit = 100;
	cout << solution(people, limit);

}
