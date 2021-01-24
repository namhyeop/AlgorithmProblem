#include<iostream>
#include<string>

using namespace std;

int main(int argc, char *argv[])
{
	unsigned int N;
	int start = 666;
	int count = 0;
	cin >> N;

	while (1)
	{
		string s = to_string(start);

		if (s.find("666") != -1)
		{
			count++;
		}

		if (count == N)
			break;
		start++;
	}

	cout << start << "\n";

	return 0;
}
