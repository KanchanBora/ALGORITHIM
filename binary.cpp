/*
	Name: kanchan bora
	Copyright: 
	Author: 
	Date: 14-09-20 11:05
	Description:  A recursive binary search function. It returns  location of x in given array arr[l..r] is present, otherwise -1 
*/
#include<iostream>
#include<stdio.h>
using namespace std; 

int input(int *arr, int n)
{
	for(int i=0;i<n;i++)
	{
	cout<<"\n Enter the array of integers:";
	cin>>arr[i];
	}
		
}

int Duplicate(int arr[], int n) 
{

	for(int i=0;i<n;i++)
	 for(int j=i+1;j<n;j++)
				
		if (arr[i]==arr[j])
			cout<<"\n Repeating elements present in the array  :"<<arr[i]	<<"" ; 
		
} 	

int arraySortedOrNot(int arr[], int n)
{
    if (n == 1 || n == 0)
		 return 1;

    if (arr[n - 1] < arr[n - 2])
		 return 0;

    return arraySortedOrNot(arr, n - 1);
}

int binarySearch(int arr[], int l, int r, int x,int & c) 
{   
	if (r >= l) 

	{ 
	 int mid =(l + r ) / 2; 
		 c++;
	{
	 if (arr[mid] == x) 
     return mid; 
		
	 if (arr[mid] > x) 		 
	 return binarySearch(arr, l, mid - 1, x,c); 

	 if (arr[mid] < x) 
	 return binarySearch(arr, mid + 1, r, x,c); 
    } 
	}
    return -1; 
} 

int main() 
{ 	
	int x,n,c=0;
	int *arr= NULL;
	arr =new int[n];
	
	cout<<"\n Enter the max limit:";
	cin>>n; 
	input(arr,n);
	
	
	
int dup=Duplicate(arr,n) ;
{
if (dup==-1)
		input(arr,n);
else
		cout<<"..................";
			
}
		
cout<<"\n The array given by user is = ";
for(int i=0;i<n;i++)
cout<<"  "<<arr[i];
		
	
int sresult= arraySortedOrNot(arr, n);
if(sresult==1)
  	cout << "\n perform bsearch";

cout<<"\n  Enter the element you want to search:";
cin>>x;	
int result = binarySearch(arr, 0, n - 1, x,c);
if (result == -1)  
				cout << "\nElement is not present in the array"; 
else
			cout << "\nElement found at " << result<<" position and after "<<c<<"comparisons "; 
return 0; 
} 

	

