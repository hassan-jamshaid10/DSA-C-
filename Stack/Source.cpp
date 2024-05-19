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
		arr = new t[s];
		maxsize = s;
		currentsize = 0;
		top = -1;
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
	void push(t v)
	{
		if (isfull())
		{
			cout << "Stack overflow" << endl;
		}
		else
		{
			arr[currentsize] = v;
			currentsize++;
			top++;
		}
	}
	t pop()
	{
		if (isempty())
		{
			cout << "Stack underflow" << endl;
		}
		else
		{
			top--;
			currentsize--;
			return arr[currentsize];
		}
	}
	t peak()
	{
		return arr[top];
	}
	int size()
	{
		return currentsize;
	}
};
int main()
{
	stack<int>s(5);
	s.push(1);
	s.push(2);
	s.pop();
	

}