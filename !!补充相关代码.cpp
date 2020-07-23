/************************************************************************
*功能：1 数组元素个数可以在初始化该对象的时候指定
*　　　2：可以动态玩数组中添加元素
*　　  3：使用该类时，不用操心动态内存分配、释放问题
*     4：能够像使用数组那样来使用动态数组类对象，如可以通过下标来访问元素。　
****************************************************************************/
#include<iostream>
#include<string.h>
using namespace std;

class  CArray{
	private:
       int size; //数组元素个数
       int *ptr; //指向动态分配的数组
	public:
	   CArray(int s = 0); 
	   CArray(CArray& a);
	   ~CArray();
	   void push_back(int v); //在数组尾部添加元素v
	   CArray & operator=(const CArray & a); //用于数组对象间的赋值	    
	   int length();  //返回数组元素个数
	   int& operator[](int i); //支持根据下标访问数组元素	    
};

CArray::CArray(int s):size(s){ 
 	if( s == 0)
	 	ptr = NULL;
	else	   
		ptr = new int[s]; 
}

//拷贝构造函数进行复制 
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

//析构函数 
CArray::~CArray(){  
	if(ptr)
		delete [] ptr;  
} 

//重载运算符 = 
CArray & CArray::operator=(const CArray & a){ 
   if(ptr == a.ptr) //防止a=a这样的赋值导致出错
    	return * this;
   if(a.ptr == NULL) { //如果a里面的数组是空的
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

//往数组中添加元素
void CArray::push_back(int v){
   if(ptr) { 
   	   int * tmpPtr = new int[size+1]; 
   	   memcpy(tmpPtr, ptr, sizeof(int) * size); 
   	   delete [] ptr; 
   	   ptr = tmpPtr; 
   }
   else
   	   ptr = new int[1];
   ptr[size++] = v; //加入新的数组元素
}

//求数组的长度 
int CArray::length(){ 
	return size;
} 

//重载运算符【】 
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
