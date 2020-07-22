/*判断多个数是否为素数*/ 
#include <iostream>
using namespace std;

int main()
{
	int n;
	
	while(1)
	{
		cin >> n;
		if(n==1)
		{
			cout << "不是素数" << endl;
			break;  //退出最外层循环 
		}
		else
		{
		    int i;
		    for(i=2;i<n;i++)
		    {
                if(n%i == 0) 
                {
 				    cout << "不是素数" << endl;
				    break;				                  	
				}
		    }
		    if(i == n)
			{
			   cout << n << "是素数" << endl;
			   break;	
			}	 		    	
	    }
	}  
	return 0;	
}
