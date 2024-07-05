#pragma once
#include<iostream>
using namespace std;

struct Treenode
{
public:
	int data;
	Treenode* left;
	Treenode* right;
	int Height;

	Treenode(int d)
	{
		this->data = d;
		this->left = NULL;
		this->right = NULL;
		this->Height = 1;
	}
};



