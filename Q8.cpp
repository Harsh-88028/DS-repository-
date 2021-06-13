8. Write a Program to implement binary search using recursion.
  
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int num, int beg, int end)
{
 int mid;
 
 if (beg > end){
  
  cout << "Number is not found";
  return 0;
  
 } else {
  
  mid = (beg + end) / 2;
  
  if(arr[mid] == num){
   
   cout << "Number is found at " << mid << " index \n";
   return 0;
  
  } else if (num > arr[mid]) {
   
   BinarySearch (arr, num, mid+1, end);
   
  } else if (num < arr[mid]) {
   
   BinarySearch (arr, num, beg , mid-1);
  }
 }
 
 
}
 
int main() {
 
 int arr[100], num, i, n, beg, end;
 
 cout <<"Enter the size of an array (Max 100) \n";
 cin >> n;
 
 cout <<"Enter the sorted values \n";
 
 for(i=0; i<n; i++) {
  
  cin >> arr[i];
 }
 
 cout <<"Enter a value to be search \n";
 cin >> num;
 
 beg = 0;
 end = n-1;
 
 BinarySearch (arr, num, beg, end);
 
 return 0;
}

Output -

Enter the size of an array (Max 100) : 6
Enter the sorted values :  2   4   6   7   8   9
Enter a value to be search :  7
Number is found at 3 index 
