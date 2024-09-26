#include <iostream>
using namespace std;
template<typename T>
struct node
{
	T value;
    node<T> *lc,*rc,*par;
    node(T x,node<T>* papa)
    {
    	value=x;
    	par=papa;
    	lc=rc=NULL;
    }
};
template<typename T>
struct BST
{
	node<T> *root=NULL,*tmp=NULL,*tmp1=NULL;
	int sz=0;
	BST()
	{
		sz=0;
		root=NULL;
	}
	void insert(T x)
	{
		sz++;
		if(sz==1)
		{
			root=new node<T>(x,NULL);
			return;
		}
		tmp=root;
		while(tmp!=NULL)
		{
			if(x<=tmp->value)
			{
				if(tmp->lc==NULL)
				{
					tmp->lc=new node<T>(x,tmp);
					break;
				}
				else
				{
					tmp=tmp->lc;
				}
			}
			else
			{
				if(tmp->rc==NULL)
				{
					tmp->rc=new node<T>(x,tmp);
					break;
				}
				else
				{
					tmp=tmp->rc;
				}
			}
		}
	}
	void erase(T x)
	{
		tmp=findNode(x);
		if(tmp==NULL)
			return;
		if(tmp->lc==NULL and tmp->rc==NULL)
		{
			if(tmp->par==NULL)
				root=NULL;
			else if(tmp==tmp->par->lc)
				tmp->par->lc=NULL;
			else
				tmp->par->rc=NULL;
		}
		else if(tmp->rc != NULL)
		{
			if(tmp->par==NULL)
				root=tmp->rc;
			else if(tmp==tmp->par->lc)
				tmp->par->lc=tmp->rc;
			else
				tmp->par->rc=tmp->rc;
		}
		else if(tmp->lc != NULL)
		{
			if(tmp->par==NULL)
				root=tmp->lc;
			else if(tmp==tmp->par->lc)
				tmp->par->lc=tmp->lc;
			else
				tmp->par->rc=tmp->lc;			
		}
		else
		{
			tmp1=tmp;
			tmp=successor(tmp);
			if(tmp==tmp->par->lc)
				tmp->par->lc=tmp->rc;
			else
				tmp->par->rc=tmp->rc;
			tmp1->value=tmp->value;

		}
	}
	node<T>* findNode(T x)
	{
		tmp=root;
		while(tmp!=NULL)
		{
			if(x==tmp->value)
				return tmp;
			if(x<tmp->value)
			{
				tmp=tmp->lc;
			}
			else
			{
				tmp=tmp->rc;
			}
		}
		return NULL;
	}
	bool find(T x)
	{
		tmp=root;
		while(tmp!=NULL)
		{
			if(x==tmp->value)
				return 1;
			if(x<tmp->value)
			{
				tmp=tmp->lc;
			}
			else
			{
				tmp=tmp->rc;
			}
		}
		return 0;
	}
	node<T>* successor(node<T>* u)
	{
		tmp=u;
		if(tmp->rc!=NULL)
		{
			tmp=tmp->rc;
			while(tmp->lc!=NULL)tmp=tmp->lc;
			return tmp;
		}
		else
		{
			while(tmp->par!=NULL)
			{
				if(tmp==tmp->par->lc)
					return tmp->par;
				else
					tmp=tmp->par;
			}
			return tmp;
		}
	}
	void clear(){
		root = NULL;
	    sz = 0;
	}
	bool empty()
	{
		return (sz==0);
	}
};
int main()
{
	BST<int> cur;
	cur.insert(1);
	cur.insert(5);
	cur.insert(100);
	cout<<cur.find(1)<<endl;
	cout<<cur.find(5)<<endl;
	cout<<cur.find(100)<<endl;
	cur.erase(1);
	cout<<cur.find(1)<<endl;
	cout<<cur.find(5)<<endl;
	cout<<cur.find(100)<<endl;
	cur.erase(5);
	cout<<cur.find(1)<<endl;
	cout<<cur.find(5)<<endl;
	cout<<cur.find(100)<<endl;
	return 0;
}