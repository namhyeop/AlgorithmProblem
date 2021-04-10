#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

bool isValid(string cur, string cmpStr)
{
	int cnt = 0;
	//모든 단어 길이는 같다.
	for (int i = 0; i < cur.size(); i++)
	{
		if (cur[i] != cmpStr[i])
			cnt++;
	}

	if (cnt == 1)
		return true;
	else
		return false;
}

int solution(string begin, string target, vector<string> words)
{
	int answer = 0;

	queue<pair<string, int>> q;	
	q.push({ begin, 0});

	while (!q.empty())
	{
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == target)
		{
			answer = cnt;
			break;
		}
		for (int i = 0; i < words.size(); i++)
		{
			if (isValid(cur, words[i]))
			{
				q.push({ words[i], cnt + 1 });
			}
		}
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	
	cout << solution(begin, target, words) << "\n";
}
