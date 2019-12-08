#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int count=0;
	int N, TargetValue;
	int Array[10];
	cin >> N >>TargetValue;

	for (int i = 0; i < N; i++)
	{
		cin >> Array[i];
	}
	
		for (int j = N ; j > 0; j--)
		{
			if ((TargetValue / Array[j-1]) != 0)
			{
				count += TargetValue / Array[j-1];
				TargetValue = TargetValue % Array[j-1];

			}
			
		}
	
	cout << count << endl;
}
