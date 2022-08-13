#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class graph;
class Sllist;
class Snode
{		
		int val;
		Snode* next;
	public:
		Snode(int a,Snode*ptr);
		friend class Sllist ;
		friend class graph;
};

Snode::Snode(int a=0,Snode*ptr=0)
{
	val= a;
	next=ptr;
}

class Sllist
{
	private:
	    Snode* head;
	public:
		Sllist();
		~Sllist();
		void addfront(int v);
		void print();
		Snode* r_head();
		friend class graph;	
};

Sllist::Sllist()
{
	head= NULL;
}

void Sllist::addfront(int v)
{
	 head= new Snode(v,head);
	 return;
}

Snode*Sllist::r_head()
{
	return head;
}

class graph
{
		Sllist * adj_lst;
		int n;
		int* in_deg;
		int* order;
	public:
		graph(int V);
		void input();
		void display();
		void topological();
};

graph::graph(int V)
{	
	adj_lst =new Sllist[n];  
	n=V; 
	in_deg= new int[n];
	order= new int[n];
}

void graph::input()
{
int u,v,a=0;
for(int i=0;i<n;i++)
    {	
        cout<<"\n Enter number of elements connected with "<<i+1<<" node : ";
        cin>>v;
        cout<<"\n Enter elements : ";
        for(int j=0;j<v;j++)
        {
            cin>>u;
            adj_lst[i].addfront(u);
        }
        adj_lst[i].addfront(++a);
    }	
}

void Sllist::print()
{	if(head)
	{
	Snode*current=head;
     for (; current->next ; current=current->next)  
    {
		 	cout<<current->val<< "-->";
    }
    cout<<current->val<<"\n";
	}
    return;
}

void graph::display()
{  
	cout<<"\n \n .....Adjaceny list.....\n";
	for(int i=0;i<n;i++)
	{
	adj_lst[i].print();
	cout<<endl;
	}
  
}

void graph::topological()
{	int i;
		in_deg[i]=0;
		order[i]=0;

	for(int i=0;i<n;i++)
	{
		Snode*tmp= adj_lst[i].r_head();
		tmp= tmp->next;
		while(tmp!=0)
		{
			int x= tmp->val;
			in_deg[x-1]++;
			tmp= tmp->next;
		}
	}
	int flag=0;
	for(int j=0;j<n;j++)
	{
			for(int k=0;k<n;k++)
			{
				if (in_deg[k]==0)
				{
					order[j]=k+1;
					Snode* current =adj_lst[k].r_head();
					current=current->next;
					while(current!=0)
					{
						int m= current->val;
						in_deg[m-1]--;
						current=current->next;
					}
				in_deg[k]=-1;
				flag=1;
				break;
				}
			}
			if(flag==0)
			break;
		}	
		{
		cout<<"\n TOPOLOGICAL ORDERING : \n";
		for(int i=0;i<n;i++)
		cout<<order[i]<<" ";
		}
	
}

int main()
{
	int n;
	cout<<"\n Enter the no of vertices :";
	cin>>n;
	graph t(n);
	t.input();
	t.display();
	cout<<"\n =====================================================\n";
    cout << "Following is a Topological Sort of the given graph \n";
    t.topological();
    	cout<<"\n =====================================================\n";
    return 0;
} 

