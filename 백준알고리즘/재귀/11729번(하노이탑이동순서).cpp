#include<bits/stdc++.h>

using namespace std;

void hanoi_tower(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << " " << b << "\n";
		return;
	}
	hanoi_tower(a, 6 - a - b, n - 1);
	cout << a << " " << b << "\n";
	hanoi_tower(6 - a - b, b, n - 1);

}
int main(int argc, char *argv[])
{
	int k;
	cin >> k;

	cout << (1 << k) - 1 << "\n";

	hanoi_tower(1, 3, k);
	
	return 0;
}
