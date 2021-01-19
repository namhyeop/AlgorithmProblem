#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int L;
int ret;
int pipe[1001];

int main(int argc, char *argv[])
{
	cin >> N >> L;

	vector<int> v(N,0);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int cur = v[i];
		if (!pipe[cur])
		{
			for (int j = cur; j < cur + L; j++)
			{
				if (j > 1000)
					break;
				pipe[j] = 1;
			}
			cnt++;
		}
	}

	cout << cnt << "\n";
	return 0;
}
