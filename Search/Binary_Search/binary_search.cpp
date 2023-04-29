#include<iostream>

using namespace std;

int binarySearch(int* a, int ele,int n){
  int beg = 0, end = n -1, mid;
  do{
    mid = (beg + end) / 2;
    if(a[mid] == ele)
      return mid;
    else if(a[mid] > ele){
      end = mid;
    }
    else{
      beg = mid;
    }
  } while(beg <= end);
  return -1;
}

int main(){
  int *arr, n, ele;
  cout << "Enter size of array" << endl;
  cin >> n;
  arr = new int[n];
  cout << "Enter a sorted array" << endl;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cout << "Enter element to be searched for" << endl;
  cin >> ele;
  int index = binarySearch(arr, ele, n);
  cout << "Element " << ele << " was found at index " << index << endl;
  delete arr;
  return 0;
}
