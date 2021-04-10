#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#include <unordered_map>

using namespace std;
const int MAX = 10001;
bool visited[MAX];
bool flag = false;

void DFS(vector<vector<string>> &tickets, vector<string> &answer, vector<string> &temp)
{
	if (temp.size() == tickets.size() + 1 && flag == false) 
	{
		answer = temp;
		flag = true;
		return;
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		if (!visited[i] && temp.back() == tickets[i][0])
		{
			temp.push_back(tickets[i][1]);
			visited[i] = true;
			DFS(tickets, answer, temp);
			temp.pop_back();
			visited[i] = false;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets)
{
	vector<string> answer,temp;
	temp.push_back("ICN");
	sort(tickets.begin(), tickets.end());
	DFS(tickets, answer, temp);
	
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//vector<vector<string>> tickets = { { "ICN", "JFK" }, { "HND", "IAD" }, { "JFK", "HND" } };
	vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
	vector<string> ret = solution(tickets);

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}
