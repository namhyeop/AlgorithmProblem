#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int MAX = 360000;
int ad[MAX];

string secToStr(int n)
{
	string ret;
	int h, m, s;

	s = n % 60, n /= 60;
	m = n % 60, n /= 60;
	h = n;

	if (h < 10)
		ret += "0";
	ret += to_string(h);
	ret += ":";

	if (m < 10)
		ret += "0";
	ret += to_string(m);
	ret += ":";

	if (s < 10)
		ret += "0";
	ret += to_string(s);
	
	return ret;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
	string answer = "";

	ll maxValue = 0;

	int allTime = stoi(play_time.substr(0, 2)) * 3600 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));
	int adTime = stoi(adv_time.substr(0, 2)) * 3600 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));

	for (int i = 0; i < logs.size(); i++)
	{
		int start = stoi(logs[i].substr(0, 2)) * 3600 + stoi(logs[i].substr(3, 2)) * 60 + stoi(logs[i].substr(6, 2));
		int end = stoi(logs[i].substr(9, 2)) * 3600 + stoi(logs[i].substr(12, 2)) * 60 + stoi(logs[i].substr(15, 2));

		for (int i = start; i < end; i++)
			ad[i]++;
	}

	int idx = 0;
	ll tmpSum = 0;

	queue<int> q;
	for (int i = 0; i < adTime; i++)
	{
		tmpSum += ad[i];
		q.push(ad[i]);
	}
	maxValue = tmpSum; //00:00::00 부터 광고시작 시간의 합계, 지금은 초기값이다. 밑의 과정을 통해 최대 시청시간을 산출한다.

	for (int i = adTime; i < allTime; i++)
	{
		tmpSum += ad[i];
		q.push(ad[i]);
		tmpSum -= q.front();
		q.pop();

		if (tmpSum > maxValue)
		{
			idx = i - adTime + 1;
			maxValue = tmpSum;
		}
	}

	answer = secToStr(idx);

	return answer;
}

int main()
{
	string playTime = "99:59:59";
	string adv_time = "25:00:00";
	vector<string> logs = { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" };
	
	cout << solution(playTime, adv_time, logs) << "\n";
}
