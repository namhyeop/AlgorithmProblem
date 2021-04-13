#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++)
	{
		int start = commands[i][0];
		int end = commands[i][1];
		vector<int> v;
		v.clear();
		for (int i = start - 1; i <= end - 1; i++)
			v.push_back(array[i]);
		
		sort(v.begin(), v.end());

		answer.push_back(v[commands[i][2] -1]);
	}
	return answer;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> v2 = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };
	vector<int> ret = solution(v, v2);

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}
