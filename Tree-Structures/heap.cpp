#include <iostream>
#include <functional>
using namespace std;
const int CAP=1e5;
template<typename T>
struct Heap
{
	T hep[CAP];
	int i=1,p;
	function<bool(T,T)> fun;
	Heap(function<bool(T,T)> tp = less<T>())
	{
		fun=tp;
	}
	void push(T x)
	{
		hep[i]=x;
		p=i;
		while(p>1)
		{
			if(fun(hep[p/2],hep[p]))
			{
				swap(hep[p/2],hep[p]);
				p/=2;
			}
			else
				break;
		}
		i++;
	}
	T top()
	{
		return hep[1];		
	}
	void pop()
	{
		i--;
		p=1;
		swap(hep[p],hep[i]);
		while((p<<1)<i)
		{
			int lc=(p<<1),rc=lc+1;
			if(rc<i and fun(hep[lc],hep[rc]))
			{
				if(fun(hep[p],hep[rc]))
				{
					swap(hep[p],hep[rc]);
					p=rc;
				}
				else
				{
					return;
				}
			}
			else
			{
				if(fun(hep[p],hep[lc]))
				{
					swap(hep[p],hep[lc]);
					p=lc;
				}
				else
				{
					return;
				}
			}
		}
	}
};
bool lessthan(int x,int y)
{
	return (x<y);
}
int main()
{
	Heap<int> tp;
	tp.push(1);
	tp.push(10);
	tp.push(100);
	cout<<tp.top()<<endl;
	tp.pop();
	cout<<tp.top()<<endl;
	tp.pop();
	cout<<tp.top()<<endl;
	return 0;
}