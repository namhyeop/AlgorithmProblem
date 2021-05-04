#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

set<int> s;
int len;

bool check[8];

void DFS(vector<string> &user_id, vector<string> &banned_id, int i, int num)
{
	if (len == i)
	{
		s.emplace(num);
		return;
	}

	for (int j = 0; j < user_id.size(); j++)
	{
		int z;

		if (sz(user_id[j]) != sz(banned_id[i]))
			continue;

		if (check[j] == true)
			continue;

		for (z = 0; z < sz(user_id[j]); z++)
		{
			if (banned_id[i][z] == '*')
				continue;

			if (user_id[j][z] != banned_id[i][z])
				break;
		}

		if (z == banned_id[i].size()) //
		{
			check[j] = true;
			DFS(user_id, banned_id, i + 1, num | (1 << j));
			check[j] = false;
		}
	}
}
int solution(vector<string> user_id, vector<string> banned_id)
{
	len = banned_id.size();
	DFS(user_id, banned_id, 0 ,0);
	return s.size();
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
	vector<string> banned_id = {"fr*d*", "*rodo", "******", "******"};

	cout << solution(user_id, banned_id);
}
