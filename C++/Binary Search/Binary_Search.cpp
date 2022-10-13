#include<iostream>
using namespace std;

struct Array
{
	int A[10];
	int size;
	int length;
};

void Display(struct Array arr)
{
	cout<<endl;
	cout<<"Elements are:"<<endl;
	for(int i=0;i<arr.length;i++)
	{
		cout<<" "<<arr.A[i];
	}
}

int BinarySearch(struct Array arr, int key)
{
	int mid,l=0,h;
	h=arr.length-1;
	
	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr.A[mid])
		{
			return mid;
		}
		
		else if(key>arr.A[mid])
		
			l=mid+1;
			
			else
			h=mid-1;
	}
	
	return -1;
}

int main()
{
 struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
 cout<<BinarySearch(arr1,16);
 Display(arr1);
 return 0;
}






