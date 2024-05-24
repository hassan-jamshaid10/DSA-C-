#include<iostream>
using namespace std;

int sum(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n+sum(n - 1);
	}
}
int main()
{
	int n;
	cout << "Input:" << endl;
	cin >> n;

	cout << "Sum of Natural Number is:" << sum(n) << endl;
}