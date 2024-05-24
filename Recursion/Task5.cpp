#include<iostream>
using namespace std;

int sumofdigit(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return (n % 10)+sumofdigit(n / 10);

	}
}
int main()
{
	int n;
	cout << "Input:" << endl;
	cin >> n;

	cout << "Sum of Natural Number is:" << sumofdigit(n) << endl;
}