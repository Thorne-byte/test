/************************************************************************
*���ܣ�1 ����Ԫ�ظ��������ڳ�ʼ���ö����ʱ��ָ��
*������2�����Զ�̬�����������Ԫ��
*����  3��ʹ�ø���ʱ�����ò��Ķ�̬�ڴ���䡢�ͷ�����
*     4���ܹ���ʹ������������ʹ�ö�̬��������������ͨ���±�������Ԫ�ء���
****************************************************************************/
#include<iostream>
#include<string.h>
using namespace std;

class  CArray{
	private:
       int size; //����Ԫ�ظ���
       int *ptr; //ָ��̬���������
	public:
	   CArray(int s = 0); 
	   CArray(CArray& a);
	   ~CArray();
	   void push_back(int v); //������β�����Ԫ��v
	   CArray & operator=(const CArray & a); //������������ĸ�ֵ	    
	   int length();  //��������Ԫ�ظ���
	   int& operator[](int i); //֧�ָ����±��������Ԫ��	    
};

CArray::CArray(int s):size(s){ 
 	if( s == 0)
	 	ptr = NULL;
	else	   
		ptr = new int[s]; 
}

//�������캯�����и��� 
CArray::CArray(CArray & a){
	if(!a.ptr) {
		ptr = NULL;
		size = 0;
		return;
	}
	ptr = new int[a.size];
	memcpy(ptr, a.ptr, sizeof(int ) * a.size);
	size = a.size;
}

//�������� 
CArray::~CArray(){  
	if(ptr)
		delete [] ptr;  
} 

//��������� = 
CArray & CArray::operator=(const CArray & a){ 
   if(ptr == a.ptr) //��ֹa=a�����ĸ�ֵ���³���
    	return * this;
   if(a.ptr == NULL) { //���a����������ǿյ�
     if(ptr)
		delete [] ptr;
	 ptr = NULL;
	 size = 0;
	 return * this;
   }
   
   if(size < a.size) {
	 if(ptr)         
		delete [] ptr;
	 ptr = new int[a.size];
	}
	memcpy(ptr, a.ptr, sizeof(int) * a.size);	
	size = a.size;
 	return * this;
} 

//�����������Ԫ��
void CArray::push_back(int v){
   if(ptr) { 
   	   int * tmpPtr = new int[size+1]; 
   	   memcpy(tmpPtr, ptr, sizeof(int) * size); 
   	   delete [] ptr; 
   	   ptr = tmpPtr; 
   }
   else
   	   ptr = new int[1];
   ptr[size++] = v; //�����µ�����Ԫ��
}

//������ĳ��� 
int CArray::length(){ 
	return size;
} 

//������������� 
int& CArray::operator[](int i){	
	return ptr[i]; 
} 

int main() { 
   CArray a; 
   for(int i = 0; i < 5; ++i)
		a.push_back(i);
   CArray a2,a3;
   a2 = a;
   for(int i = 0; i < a.length(); ++i)
   		cout << a2[i] << " " ;
   a2 = a3; 
   for(int i = 0; i < a2.length(); ++i) 
   		cout << a2[i] << " ";	   
   cout << endl;
   a[3] = 100;
   CArray a4(a);	
   for(int i = 0; i < a4.length(); ++i)
		cout << a4[i] << " ";	   
   return 0;
}
