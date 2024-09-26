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
	void insert(T x)
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
};
bool lessthan(int x,int y)
{
	return (x>y);
}
int main()
{
	Heap<int> tp(lessthan);
	tp.insert(10);
	cout<<tp.top()<<endl;;
	tp.insert(1);
	cout<<tp.top()<<endl;;
	tp.insert(100);
	cout<<tp.top()<<endl;;
	tp.insert(-100);
	tp.insert(-100);
	tp.insert(-100);
	tp.insert(-100);
	cout<<tp.top()<<endl;
	return 0;
}