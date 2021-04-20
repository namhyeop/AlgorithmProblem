#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(vector<string> lines)
{
	int answer = 0;
	vector<pair<double, double>> parsingTime;

	for (auto line : lines)
	{
		double endValue = stod(line.substr(11, 2)) * 3600 + stod(line.substr(14, 2)) * 60 + stod(line.substr(17, 6));
		string tmp = line.substr(24);
		double throughputValue = stod(tmp.substr(0, line.length() - 1));
		double startValue = endValue - throughputValue + 0.001;
		parsingTime.push_back({ startValue, endValue });
	}
	
	int cnt = 0;
	for (int i = 0; i < parsingTime.size(); i++)
	{
		double start = parsingTime[i].first;
		double end = parsingTime[i].second;
		cnt = 1;
		for (int j = i + 1; j < parsingTime.size(); j++)
		{
			if (start + 1 >= parsingTime[j].first || end + 1 > parsingTime[j].first)
			{
				cout << start << " " << end << " " << parsingTime[j].first << "\n";
				cnt++;
			}
		}
		answer = max(answer, cnt);
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<string> lines = {
		"2016-09-15 20:59:57.421 0.351s",
		"2016-09-15 20:59:58.233 1.181s",
		"2016-09-15 20:59:58.299 0.8s",
		"2016-09-15 20:59:58.688 1.041s",
		"2016-09-15 20:59:59.591 1.412s",
		"2016-09-15 21:00:00.464 1.466s",
		"2016-09-15 21:00:00.741 1.581s",
		"2016-09-15 21:00:00.748 2.31s",
		"2016-09-15 21:00:00.966 0.381s",
		"2016-09-15 21:00:02.066 2.62s" };
	
	cout << solution(lines) << "\n";
}
