/*�ж϶�����Ƿ�Ϊ����*/ 
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
			cout << "��������" << endl;
			break;  //�˳������ѭ�� 
		}
		else
		{
		    int i;
		    for(i=2;i<n;i++)
		    {
                if(n%i == 0) 
                {
 				    cout << "��������" << endl;
				    break;				                  	
				}
		    }
		    if(i == n)
			{
			   cout << n << "������" << endl;
			   break;	
			}	 		    	
	    }
	}  
	return 0;	
}
