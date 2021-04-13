#include<bits/stdc++.h>
#include<unordered_map>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

map<string, int> maxGenres;
map<string, vector<pair<int,int>>> listGenres;
vector<pair<string, int>> maxGenresV;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

bool vcmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	for (int i = 0; i < genres.size(); i++)
	{
		maxGenres[genres[i]] += plays[i];
		listGenres[genres[i]].push_back({plays[i], i});
	}

	for (auto &k : listGenres)
	{
		sort(k.second.begin(), k.second.end(), cmp);
	}
	maxGenresV.assign(maxGenres.begin(), maxGenres.end());
	sort(maxGenresV.begin(), maxGenresV.end(), vcmp);
	
	for (int i = 0; i < maxGenresV.size(); i++)
	{
		string curGenre = maxGenresV[i].first;
		for (int j = 0; j < listGenres[curGenre].size(); j++)
		{
			if (j == 2)
				break;
			answer.push_back(listGenres[curGenre][j].second);
		}
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> v = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> i = { 500, 600, 150, 800, 2500 };
	vector<int> ret = (solution(v, i));

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}
