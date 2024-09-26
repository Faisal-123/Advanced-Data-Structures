#include <iostream>
#include <chrono>
#include <random>
using namespace std;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
static int cals=0;
template<typename T>
struct node
{
	T value;
	long long priority;
    node<T> *lc,*rc,*par;
    node(T x,node<T>* papa)
    {
    	value=x;
    	priority=RNG();
    	par=papa;
    	lc=rc=NULL;
    }
};
template<typename T>
struct Treap
{
	node<T> *root=NULL,*tmp=NULL,*tmp1=NULL,*tmp2=NULL;
	int sz=0;
	Treap()
	{
		sz=0;
		root=NULL;
	}
	void bubble_up(node<T>* cur)
	{
		while(cur->par!=NULL and cur!=NULL and cur->par->priority<cur->priority)
		{
			if(cur->par->lc==cur)
			{
				AVLRight(cur->par);
			}
			else
			{
				AVLLeft(cur->par);
			}
		}
		if(cur->par==NULL)
			root=cur;
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
					bubble_up(tmp->lc);
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
					bubble_up(tmp->rc);
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
			tmp->rc->par=tmp->par;
			if(tmp->par==NULL)
				root=tmp->rc;
			else if(tmp==tmp->par->lc)
				tmp->par->lc=tmp->rc;
			else
				tmp->par->rc=tmp->rc;
		}
		else if(tmp->lc != NULL)
		{
			tmp->lc->par=tmp->par;
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
			tmp->rc=tmp->par;
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
	void print(node<T>* cur)
	{
		if(cur==NULL)return;
		cals++;
		if(cals>20)
		{
			exit(0);
		}
		cout<<"At "<<cur->value<<' '<<cur->priority<<endl;
		cout<<"left of "<<cur->value<<endl;
		print(cur->lc);
		cout<<"right of "<<cur->value<<endl;
		print(cur->rc);
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
	void AVLRight(node<T>* b)
	{
		node<T> *a,*y,*p;
		a=b->lc;
		y=a->rc;
		p=b->par;
		if(p!=NULL and p->rc==b)
		{
			p->rc=a;
		}
		else if(p!=NULL and p->rc==b)
		{
			p->rc=a;
		}
		b->lc=y;
		a->rc=b;

		b->par=a;
		if(a!=NULL)
			a->par=p;
		if(y!=NULL)
			y->par=b;
	}
	void AVLLeft(node<T>* a)
	{
		node<T> *b,*y,*p;
		b=a->rc;
		y=b->lc;
		p=a->par;
		if(p!=NULL and p->rc==a)
		{
			p->rc=b;
		}
		else if(p!=NULL and p->rc==a)
		{
			p->rc=b;
		}
		a->rc=y;
		b->lc=a;

		a->par=b;
		if(b!=NULL)
			b->par=p;
		if(y!=NULL)
			y->par=a;
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
	Treap<int> cur;

	cur.insert(1);
	cur.insert(2);
	cur.insert(3);
	cur.insert(4);
	cur.insert(5);
	cur.insert(6);
	cur.insert(7);
	cout<<cur.find(10)<<endl;
	cout<<cur.find(3)<<endl;
	cout<<cur.find(4)<<endl;
	return 0;
}