#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		node *prev;
};
class bst
{
	node *newnode;
	node *temp1;
	public:
		node *createnode(int ele)
		{
			newnode=new node();
			newnode->data=ele;
			newnode->prev=NULL;
			newnode->next=NULL;
			return newnode;
		}
		node *insert(node *root,int ele)
		{
			if (root==NULL)
				root=createnode(ele);
			else
			{
				if (ele<root->data)
					root->prev=insert(root->prev,ele);
				else
					root->next=insert(root->next,ele);
			}
			return root;
		}
		node *minvaluenode(node *temp1)
		{
			node *current=temp1;
			while(current->prev!=NULL)
			{
				current=current->prev;
			}
			return current;
		}
		node *deletion(node *root,int key)
		{
			node *temp1;
			if(root==NULL)
				return root;
			if (key<root->data)
				root->prev=deletion(root->prev,key);
			else if (key>root->data)
				root->next=deletion(root->next,key);
			else
			{
				if (root->prev==NULL)
				{
					temp1=root->next;
					return temp1;
				}
				else if (root->next==NULL)
				{
					temp1=root->prev;
					return temp1;
				}
				node *temp2=minvaluenode(root->next);
				root->data=temp2->data;
				root->next=deletion(root->next,temp2->data);
			}
			return root;
			
		}
		void display_pre(node *temp)
		{
			//temp1=start;
			cout<<temp->data<<" ";
			if (temp->prev!=NULL)
				display_pre(temp->prev);
			if (temp->next!=NULL)
				display_pre(temp->next);
		}
		void display_post(node *temp)
		{
			//temp2=start;
			if (temp->prev!=NULL)
				display_post(temp->prev);
			if (temp->next!=NULL)
				display_post(temp->next);
			cout<<temp->data<<" ";
		}
		void display_in(node *temp)
		{
			//temp3=start;
			if (temp->prev!=NULL)
				display_in(temp->prev);
			cout<<temp->data<<" ";
			if (temp->next!=NULL)
				display_in(temp->next);
		}
};
int main()
{
	bst b1;
	int ele;
	node *root=NULL;
	cout<<"Enter root element";
	cin>>ele;
	root=b1.insert(root,ele);
	cout<<"Enter elements or -1 to exit";
	cin>>ele;
	while(ele!=-1)
	{
		root=b1.insert(root,ele);
		cin>>ele;
	}
	root=b1.deletion(root,20);
	root=b1.deletion(root,30);
	root=b1.deletion(root,50);
	cout<<"Post:";
	b1.display_post(root);
	cout<<endl;
	cout<<"Pre:";
	b1.display_pre(root);
	cout<<endl;
	cout<<"Inorder:";
	b1.display_in(root);
}
