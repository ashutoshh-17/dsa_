/* 8A)
Implement Binary Search Tree and perform following operations:
   a) Insert b) Display tree (Traversal) c) Display Height of the Tree d) Search */
   
  #include <iostream>
#include <queue>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;
};
class BST
{
	Node* root;
	Node* mirror;
	public:
		BST()
		{root = NULL;
	         mirror = NULL;
                }
		Node* getroot()
		{  return root; }  
		Node* getmirror()
		{  return mirror;}
		void insert();
		void search(int);
		void display(Node *);
		int height_tree(Node*);
};
void BST::insert()
{
	Node* temp, *newNode;
	char ch = 'y';

	while(ch == 'y' || ch == 'Y')
	{
		newNode = new Node();
		cout<<"\nEnter data for new Node: ";
		cin>>newNode->data;
		newNode->left = newNode->right = NULL;

		if(root == NULL)
			root = newNode;
		else
		{
			temp = root;
			check:
			if(newNode->data < temp->data)
			{
				if(temp->left != NULL)
				{
					temp = temp->left;
					goto check;
				}
				else
				{
					temp->left = newNode;
				}
			}
			else if(newNode->data > temp->data)
			{
				if(temp->right != NULL)
				{
					temp = temp->right;
					goto check;
                	}
				else
				{
					temp->right = newNode;
				}
            	}
        }
        cout<<"\nEnter y or Y to add more Nodes: ";
        cin>>ch;
    }
}
void BST::display(Node *root)
{
	if(root == NULL)
		return;
	else
	{
		display(root->left);
		cout<<" "<<root->data<<" ";
		display(root->right);
	}
}
void BST::search(int no)
{
	Node *temp;
	temp = root;
	check:
	if(no == temp->data)
	{
		cout<<"\nData found!";
		return;
	}
	if(no < temp->data)
	{
		if(temp->left != NULL)
		{
			temp = temp->left;
			goto check;
		}
		else
		{
			cout<<"\nData doesnt exist.";
			return;
		}
	}
	else if(no > temp->data)
	{
		if(temp->right != NULL)
		{
			temp = temp->right;
			goto check;
		}
		else
		{
			cout<<"\nData doesnt exist.";
			return;
		}
	}
}
int BST::height_tree(Node *t)
{
	int hlt, hrt;
	if(t == NULL)
		return 0;
	else
	{
		hlt = height_tree(t->left) + 1;
		hrt = height_tree(t->right) + 1;
	}
	if(hlt > hrt)
		return hlt;
	return hrt;
}
int main()
{
	BST tree;
	int x, choice;
	char ch = 'y';
    	while(1)
	{
		cout<<"\n\nBinary Search Tree Operations ";
		cout<<"\n1. Insert.";
		cout<<"\n2. Search.";
		cout<<"\n3. Display.";
		cout<<"\n4. Height of the tree.";
		cout<<"\n5. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
				tree.insert();
			break;
			case 2: 
				cout<<"\nEnter number to search: ";
				cin>>x;
				tree.search(x);
				break;
			case 3: 
				cout<<"\nInorder traversal of tree: ";
				tree.display(tree.getroot());
				break;
			case 4: 
				cout<<"\nHeight of the tree: "<<tree.height_tree(tree.getroot());
				break;
			case 5: 
				return 0;
		}
	}
	return 0;
}

/*Algorithm :
**Algorithm for Binary Search Tree Operations:**

**1. Insert Operation:**
   - Create a new node.
   - If the tree is empty, set the new node as the root.
   - Otherwise, start from the root and traverse the tree:
      - If the new node's data is less than the current node's data, move to the left subtree.
      - If the new node's data is greater than the current node's data, move to the right subtree.
      - Repeat this process until an appropriate spot is found, then insert the new node.

**2. Search Operation:**
   - Start at the root of the tree.
   - Compare the target value with the current node's data.
   - If the target is equal to the current node's data, the data is found.
   - If the target is less than the current node's data, move to the left subtree.
   - If the target is greater than the current node's data, move to the right subtree.
   - Repeat this process until the target is found or the tree is exhausted.

**3. Display Operation (Inorder Traversal):**
   - Recursively traverse the left subtree.
   - Print the data of the current node.
   - Recursively traverse the right subtree.

**4. Height of the Tree Operation:**
   - Recursively calculate the height of the left subtree.
   - Recursively calculate the height of the right subtree.
   - Return the maximum height of the left and right subtrees plus 1.

**5. Main Program:**
   - Create an instance of the Binary Search Tree (BST) class.
   - Enter a loop to repeatedly prompt the user for operations.
   - Display a menu of options:
      - Insert a new node.
      - Search for a value.
      - Display the tree using inorder traversal.
      - Display the height of the tree.
      - Exit the program.
   - Based on the user's choice, call the corresponding method of the BST class.
   - Continue the loop until the user chooses to exit.

*/
