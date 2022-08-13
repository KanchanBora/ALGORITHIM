#include<iostream>
#include<cstdlib>
using namespace std;
void swap(int *a, int *b)			
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}
 
int Partition(int a[], int l, int h,int & cp)				
{
int pivot, index, i;
index = l;
pivot = h;

for(i=l; i < h; i++)
{ cp++;
if(a[i] < a[pivot])
{
swap(&a[i], &a[index]);
index++;
}
}
swap(&a[pivot], &a[index]);
return index;
}
 
int RandomPivot(int a[], int l, int h,int &cp)		// Random selection of pivot.
{
int pt, n, temp;
n = rand();						
pt = l + n%(h-l+1);
swap(&a[h], &a[pt]);
 
return Partition(a, l, h,cp);
}
 
int QuickSort(int a[], int l, int h,int &cp)
{
int pt_index;
if(l < h)
{
pt_index = RandomPivot(a, l, h, cp);
QuickSort(a, l, pt_index-1,cp);
QuickSort(a, pt_index+1, h,cp);
}

return 0;
}
 
int main()
{
int n, i;
int cp=0;
cout<<"\n\t\t\t QUICK SORT \n";
cout<<"\n================================================\n\n";
cout<<"\nEnter the number of data element to be sorted: ";
cin>>n;
 
int arr[n];
cout<<"\n";
for(i = 0; i < n; i++)
{
cout<<"Enter element "<<i+1<<": ";
cin>>arr[i];
}
cout<<"\n================================================\n";
cout<<"\n The array is :\n\n";
for(i = 0; i < n; i++)
{
cout<<" "<<arr[i];
}

QuickSort(arr, 0, n-1,cp);
cout<<"\n================================================\n";
cout<<"\nSorted Data \n\n";
for (i = 0; i < n; i++)
cout<<"  "<<arr[i];
cout<<"\n================================================";
cout<<"\nCOMPARISIONS = "<<cp;
cout<<"\n================================================\n\n"; 
return 0;
} 

