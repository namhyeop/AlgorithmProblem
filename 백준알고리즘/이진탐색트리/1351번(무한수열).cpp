#include<iostream>
#include<map>

using namespace std;

long long N, P, Q;
map<long long, long long> cache;

long long func(long long N)
{
	if (cache.count(N))
		return cache[N];
	else
		return cache[N] = func(N / P) + func(N / Q);
}

int main(int argc, char*argv[])
{
	cin >> N >> P >> Q;

	cache[0] = 1; //자료형 map의 cache에 key 0값은 1을 가진다.
	cout << func(N) << '\n';
	return 0;
}
