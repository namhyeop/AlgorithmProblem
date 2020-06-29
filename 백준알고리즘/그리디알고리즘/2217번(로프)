#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	int N;
	int max = 0;
	cin >> N ;
	
	vector<int>t(N);
	for (int i = 0; i < N; i++)
	{
		cin >> t[i];
	}

	sort(t.begin(), t.end(), less<int>());

	for (int i = 0; i < N; i++)
	{
		if (max < (t[i] * (N - i)))
		{
			max = (t[i] * (N - i));
		}
	}

	cout << max << endl;
		

}
