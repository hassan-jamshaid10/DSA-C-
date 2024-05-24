#include<iostream>
using namespace std;

int g(int j,int k)
{
	if ( k==0)
	{
		return j;
	}
	
		return g(k, j%k);

	
}
int lcm(int j,int  k)
{
	if (j< 0)
		j = -j;
	
	if (k < 0)
		k = -k;

	return (j / g(j, k)) * k;
}
int main()
{
	int n,l;
	cout << "Input:" << endl;
	cin >> n;
	cout << "Input 2:" << endl;
	cin >> l;
	int a = lcm(n, l);
	cout << "LCM is:" <<a << endl;
}