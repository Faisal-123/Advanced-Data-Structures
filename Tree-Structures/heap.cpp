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
	Heap(function<bool(T,T)> tp)
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
		swap(hep[1],hep[i]);
		p=i;
		while((p<<1)<i)
		{
			int lc=(p<<1),rc=lc|1;
			if(rc<i and fun(hep[lc],hep[rc]))
			{
				swap(hep[p],hep[rc]);
				p=rc;
			}
			else
			{
				swap(hep[p],hep[lc]);
				p=lc;
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
	Heap<int> tp(lessthan);
	tp.push(1);
	cout<<tp.top()<<endl;;
	tp.push(10);
	cout<<tp.top()<<endl;;
	tp.push(100);
	cout<<tp.top()<<endl;;
	tp.pop();
	cout<<tp.top()<<endl;
	tp.pop();
	cout<<tp.top()<<endl;
	tp.pop();
	return 0;
}