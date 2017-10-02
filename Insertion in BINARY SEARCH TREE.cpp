#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *prev;
	node *next;
};
class bst
{
	public:
		node *newnode;
		node *start=NULL;
		node *temp;
		void createnode()
		{
			newnode=new node();
			cin>>newnode->data;
			newnode->next=NULL;
			newnode->prev=NULL;
		}
		void insert_bst()
		{
			cout<<"Enter root element";
			createnode();
			start=newnode;
			cout<<"Enter elements";
			temp=start;
			createnode();
			while(newnode->data!=-1)
			{
				int flag=0;
				temp=start;
				
				while(flag==0){
					if (newnode->data<temp->data)
					{
							if(temp->prev==NULL)
							{
								temp->prev=newnode;
								flag=1;
							}
							else
								temp=temp->prev;
					}
					else
					{
						if(temp->next==NULL)
						{
							temp->next=newnode;
							flag=1;
						}
						else
							temp=temp->next;
					}
				}
				createnode();
			}
		}
		void display_pre(node *temp)
		{
			//temp1=start;
			cout<<temp->data;
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
			cout<<temp->data;
		}
		void display_in(node *temp)
		{
			//temp3=start;
			if (temp->prev!=NULL)
				display_in(temp->prev);
			cout<<temp->data;
			if (temp->next!=NULL)
				display_in(temp->next);
		}
};
int main()
{
	bst b1;
	b1.insert_bst();
	cout<<"Post:";
	b1.display_post(b1.start);
	cout<<endl;
	cout<<"Pre:";
	b1.display_pre(b1.start);
	cout<<endl;
	cout<<"Inorder:";
	b1.display_in(b1.start);
}
