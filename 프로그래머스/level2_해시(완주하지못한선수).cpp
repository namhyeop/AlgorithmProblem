#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

map<string, int> m;
string solution(vector<string> participant, vector<string> completion)
{
	string answer = "";

	for (int i = 0; i < completion.size(); i++)
		m[completion[i]]++;

	for (int i = 0; i < participant.size(); i++)
	{
		if (m[participant[i]] >= 1)
			m[participant[i]] -= 1;
		else
		{
			answer = participant[i];
			break;
		}
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> p = { "mislav", "stanko", "mislav", "ana" };
	vector<string> c = { "stanko", "ana", "mislav" };
	string ret = solution(p, c);
	cout << ret;
}
