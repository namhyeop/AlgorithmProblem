#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

map<string, int> m;

vector<int> solution(vector<string> gems)
{
	int left = 0;
	int right = 0;
	int gems_cnt;
	int gems_len = gems.size();
	
	vector<string>gems_list = gems;
	sort(gems_list.begin(), gems_list.end());
	gems_list.resize(unique(gems_list.begin(), gems_list.end()) - gems_list.begin());

	gems_cnt = gems_list.size();
	vector<int> answer(2);
	answer[0] = 0;
	answer[1] = gems_len - 1;

	m[gems[0]]++;
	while (1)
	{
		if (m.size() == gems_cnt)
		{
			if (answer[1] - answer[0] > right - left)
			{
				answer[1] = right;
				answer[0] = left;
			}
			if (left == right)
				break;
			else
			{
				m[gems[left]]--;
				if (m[gems[left]] == 0)
					m.erase(gems[left]);
				left++;
			}
		}
		else if (m.size() < gems_cnt)
		{
			if (right + 1 >= gems_len)
				break;
			else
			{
				
				m[gems[right]]++;
				right++;
			}
		}
	}

	answer[0]++;
	answer[1]++;

	return answer;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> s = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
	vector<int> ret = solution(s);
	
	cout << ret[0]<< " " << ret[1] << "\n";
}
