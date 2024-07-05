#include<iostream>
#include"TreeNode.h"
#include"AVL.h"
using namespace std;


int main()
{
	//Treenode* root = NULL;
	AVLBST h;
	int in = 0;
	cout << "\t\t\t\t<-----Welcome to AVL Tree Implemetation----->" << endl;
	while (true)
	{
		cout << endl;
		cout << "Please select from Following options:" << endl;
		cout << endl;
		cout << "1) Insertion " << endl;
		cout << "2) Deletion " << endl;
		cout << "3) Traversals " << endl;
		cout << "4) Search " << endl;
		cout << "5) Minimum And Maximum " << endl;
		cout << "6) Height of Tree " << endl;
		cout << "7) Balance Factor Calculation " << endl;
		cout << "8) Predecessor and Sucessor " << endl;
		cout << "9) Diameter Calculation " << endl;
		cout << "10) Exit " << endl;
		cout << endl << endl;
		int x, a;
		cout << "Enter your Choice (1-10) :" << endl;
		cin >> x;


		switch (x)
		{
		case 1://<---------------INSERTION-------------------------->//
			int data;
			cout << "Enter Data in Tree or press -1 to Terminate insertion:" << endl;
			cin >> data;
			while (data != -1)
			{
				h.root = h.insert(h.root, data);
			input: cin >> data;
				if (h.search(h.root, data))
				{
					cout << "\nNumber already present in the tree \n";
					goto input;
				}
			}

			break;
		case 2://<-------------------DELETETION------------------->//
			int y;
		del:cout << "Enter Value which u want to delete:" << endl;
			cin >> y;
			if (!h.search(h.root, y))
			{
				cout << "Value Does not exists" << endl;
				goto del;
			}

			h.deletetion(h.root, y);
			break;
		case 3: //<-------------------TRAVERSALS-------------------->//
			int t;
			cout << "1) In Order Traversal" << endl;
			cout << "2) Pre Order Traversal" << endl;
			cout << "3) Post Order Traversal" << endl;
			cout << "4) ALl Traversals" << endl;
			cout << endl << endl;
			cout << "Enter Your choice :" << endl;
			cin >> t;
			cout << endl;
			switch (t)
			{
			case 1:
				cout << "In Order Traversal" << endl;
				h.inorder(h.root);
				break;
			case 2:
				cout << "Pre Order Traversal" << endl;
				h.Preorder(h.root);
				break;
			case 3:
				cout << "Post Order Traversal" << endl;
				h.Postorder(h.root);
				break;
			case 4:
				cout << "In Order Traversal" << endl;
				h.inorder(h.root);
				cout << endl;
				cout << "Pre Order Traversal" << endl;
				h.Preorder(h.root);
				cout << endl;
				cout << "Post Order Traversal" << endl;
				h.Postorder(h.root);
				break;
			default:
				cout << "Invalid Option" << endl;
			}
			break;
		case 4://<-------------------SEARCH---------------->//
			int k;
			cout << "Enter Value u want to search:" << endl;
			cin >> k;
			if (h.search(h.root, k))
			{
				cout << "Number Searched" << endl;
			}
			else
			{
				cout << "Not Searched" << endl;
			}
			break;
		case 5://<--------------MAX MIN--------------------------->//
			cout << "Maximum Value In AVL Tree:" << h.Maximum() << endl;
			cout << "Minimum Value In AVL Tree:" << h.Minimum() << endl;
			break;
		case 6: //<------------------HEIGHT-------------------->//
			cout << "Height of Tree is :" << h.height(h.root) << endl;
			break;
		case 7://<----------------------BALANCE FACTOR------------------>//
			cout << "Balance Factor of Current Tree :" << h.getbalance(h.root) << endl;
			break;
		case 8://<------------------SUCESSOR/PREDECESSOR---------------->//
			int n;
			cout << "Enter Value:" << endl;
			cin >> n;
			cout << "Sucessor of the node:" << h.successor(n) << endl;
			cout << "Predecessor of the node:" << h.predecessor(n) << endl;
			break;
		case 9://<-----------------DIAMETER-------------------------->//
			cout << "Diameter of current AVL Tree:" << h.diamter() << endl;
			break;
		case 10://<-------------------EXIT------------------------>//
			goto a;
			break;
		default:
			cout << "Invalid Choice" << endl;
		}
	}
a:
	cout << endl;
	cout << "Program Exited successfully !!!" << endl;
	return 0;
}