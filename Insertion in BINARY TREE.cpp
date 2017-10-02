#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *prev;
	node *next;
};
class binarytree
{
	public:
	node *start=NULL;
	node *newnode;
	node *temp1,*temp2,*temp3;
	int N;
		void createnode()
		{
			newnode=new node();
			cin>>newnode->data;
			newnode->prev=NULL;
			newnode->next=NULL;
		}
		void insert_root()
		{
			cout<<"Enter root element : ";
			createnode();
			start=newnode;
		}
		void insertion()
		{
			cout<<"Enter size";
			cin>>N;
			insert_root();
			char position[N];
			for (int j=0;j<N;j++)
			{
				cin>>position;
				node *temp=start;
				for (int i=0;position[i]!='\0';i++)
				{
					if (position[i]=='r')
					{
						if(temp->next==NULL)
						{
							createnode();
							temp->next=newnode;
						}
					temp=temp->next;
					}
					else
					{
						if(temp->prev==NULL)
						{
							createnode();
							temp->prev=newnode;
						}
					temp=temp->prev;
					}
				}
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
	binarytree b;
	b.insertion();
	cout<<"Post:";
	b.display_post(b.start);
	cout<<endl;
	cout<<"Pre:";
	b.display_pre(b.start);
	cout<<endl;
	cout<<"Inorder:";
	b.display_in(b.start);
	
}
