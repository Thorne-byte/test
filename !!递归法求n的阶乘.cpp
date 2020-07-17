/*递归法求n的阶乘*/
#include <iostream>
using namespace std;
int fac(int n)
{
	int t=1;
	if(n==1)
	   return t;
	else
	   t = n*fac(n-1);
	return t;
}

int main()
{
	int n;
	cin >> n;
	cout << fac(n) << endl;
}
