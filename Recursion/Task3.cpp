#include<iostream>
#include<string>
using namespace std;

void r(char* n,int s,int e)
{
	if (s >= e)
	{
		return ;
	}
	char temp = n[s];
	n[s] = n[e];
	n[e] = temp;

	r(n, s + 1, e - 1);
}

int rev(char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}
int main()
{
	char n[50];
	cout << "Input:" << endl;
	cin.getline(n,100);
	int l = rev(n);
	r(n, 0, l - 1);
	cout << "Reversr of string is:" << n << endl;
}