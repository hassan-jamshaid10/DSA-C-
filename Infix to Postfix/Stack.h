#pragma once
#include<iostream>
using namespace std;

template<class t>

class stack
{
protected:
	t* arr;
	int maxsize;
	int currentsize;
	int top;
public:
	stack(int s)
	{
		top = -1;
		currentsize = 0;
		arr = new t[s];
		maxsize = s;
	}
	bool isfull()
	{
		if (maxsize == currentsize)
		{
			return true;
		}
		return false;
	}
	bool isempty()
	{
		if (currentsize == 0)
		{
			return true;
		}
		return false;
	}
	void push(t value)
	{
		if (isfull())
		{
			cout << "Stack is full" << endl;
		}
		else
		{
			arr[currentsize] = value;
			currentsize++;
			top++;
		}
	}
	t pop()
	{
		if (isempty())
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			currentsize--;
			top--;
			return arr[currentsize];
		}
	}
	int Peak()
	{
		return arr[top];
	}
	int size()
	{
		return currentsize;
	}
	void display()
	{
		for (int i = 0; i < currentsize; i++)
		{
			cout << arr[i] << " ";
		}
	}
	int prec(char c)
	{
		if (c == '^')
		{
			return 3;
		}
		else if (c == '/' || c == '*')
		{
			return 2;
		}
		else if (c == '+' || c == '-')
		{
			return 1;
		}
		return 0;
	}
	void postfix(string a)
	{
		string result ;

		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
			{
				result += a[i];
			}
			else if (a[i] == '(')
			{
				push(a[i]);
			}
			else if (a[i] == ')')
			{
				while (!isempty() && top() != '(')
				{
					result += a[i];
					pop();
				}
				if (!isempty())
				{
					push(a[i]);
				}
			}
			else
			{
				while (!isempty() && prec(top()) > prec(a[i])
				{
					result += a[i];
					pop();
				}
				push(a[i]);
				while (!st.empty())
				{
					result += st.top();
					st.pop();
				}
			}
		}
		cout << "Result:" << result << endl;
	}
};
