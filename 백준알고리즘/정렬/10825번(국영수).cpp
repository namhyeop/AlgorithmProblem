#include<bits/stdc++.h>

using namespace std;

int n;
vector<people> v;

struct people
{
	string name;
	int language;
	int english;
	int math;
};

bool cmp(people a, people b)
{
	if (a.language == b.language && a.english == b.english && a.math == b.math)
		return a.name < b.name;
	else if (a.language == b.language && a.english == b.english)
		return a.math > b.math;
	else if (a.language == b.language)
		return a.english < b.english;
	else
		return a.language > b.language;
}
int main(void)
{
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].name >> v[i].language >> v[i].english >> v[i].math;
	
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].name << "\n";
	
	return 0;
}
