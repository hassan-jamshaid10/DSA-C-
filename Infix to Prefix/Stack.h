#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

template<class t>

class Stack
{
protected:
	t* arr;
	int maxsize;
	int currentsize;
	int tp;
public:
	Stack(int s)
	{
		tp = -1;
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
			tp++;
		}
	}
	t pop()
	{
		if (isempty())
		{
			cout << "Stack is empty" << endl;
		}
			currentsize--;
			tp--;
			return arr[currentsize];
		
	}
	t top()
	{
		if (isempty())
		{
			cout << "Stack is Empty, returning ZERO" << endl;
			return 0;
		}

		return arr[tp];
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
	void postfix(string value)
	{
		reverse(value.begin(), value.end());
		std::string n;
		cout << "Expression to Evaluate is : " << endl;
		for (int i = 0; i< value.length(); i++)
		{
			cout << value[i];
		}
		cout << endl;
		for (int i = 0; i < value.length(); i++)
		{
			if ((value[i] >= '0' && value[i] <= '9') || (value[i] >= 'a' && value[i] <= 'z') || (value[i] >= 'A' && value[i] <= 'Z'))
			{
				n += value[i];

			}
			else if (value[i] == ')')
				push(value[i]);
			else if (value[i] == '(')
			{
				n += ' ';
				while (!isempty() && top() != ')')
				{
					n += top();
					pop();
				}
				if (!isempty())
				{
					pop();
				}
			}
			else if (value[i] == '+' || value[i] == '-' || value[i] == '*' || value[i] == '/')
			{
				n += ' ';
				while (!isempty() && prec(top()) >= prec(value[i]))
				{
					n += top();
					pop();
				}
				push(value[i]);
			}

		}
		while (!isempty())
		{
			n += ' ';
			n += top();
			pop();
		}
		cout << endl;
		reverse(n.begin(), n.end());
		cout << endl;
		cout << "Result: " << n << endl;

	}
};

