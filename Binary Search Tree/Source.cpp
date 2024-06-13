#include<iostream>
using namespace std;


struct node
{
	int data;
	node* left;
	node* right;
public:
	node(int d)
	{
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST
{
	node* root;
	
	node* in(node* n, int k)
	{
		if (n == NULL)
		{
			return new node(k);
		}
		if (k < n->data)
		{
			n->left = in(n->left, k);
		}
		else
		{
			n->right = in(n->right, k);
		}
		return n;
	}
	void IOR(node* n)
	{
		if (n != NULL)
		{
			IOR(n->left);
			cout << n->data << " ";
			IOR(n->right);
		}
	}
	void PRE(node* n)
	{
		if (n != NULL)
		{
			cout << n->data << " ";
			PRE(n->left);
			PRE(n->right);
		}
	}
	void POS(node* n)
	{
		if (n != NULL)
		{
			POS(n->left);
			POS(n->right);
			cout << n->data << " ";
		}
	}
	void ip(node* &n)
	{
		int data;
		cout << "Enter Root:" << endl;
		cin >> data;
		cout << "Enter Data in Tree:" << endl;
		while (data != -1)
		{
			n = in(n, data);
			cin >> data;
		}
	}
	bool search(node* n, int k)
	{
		if (n == NULL)
		{
			return false;
		}
		if (n->data == k)
		{
			return true;
		}
		else if (k < n->data)
		{
			return search(n->left,k);
		}
		else
		{
			return search(n->right, k);
		}
	}
public:
	BST()
	{
		root = NULL;
	}
	void insert(int d)
	{
		root = in(root, d);
	}
	void inorder()
	{
		IOR(root);
	}
	void input()
	{
		ip(root);
	}
	void preorder()
	{
		PRE(root);
	}
	void postorder()
	{
		POS(root);
	}
	bool searchBST(int d)
	{
		return search(root, d);
	}
};

int main()
{
	BST b;
	b.input();
	cout << "IN ORDER:" << endl;
	b.inorder();
	cout << endl;
	cout << "PRE ORDER:" << endl;
	b.preorder();
	cout << endl;
	cout << "POST ORDER:" << endl;
	b.postorder();
	cout << endl;
	int x;
	cout << "Enter Number u want to search:" << endl;
	cin >> x;
	if (b.searchBST(x))
	{
		cout << "Number Searched" << endl;
	}
	else
	{
		cout << "Not Searched" << endl;
	}
}