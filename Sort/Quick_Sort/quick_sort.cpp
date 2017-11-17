#include <iostream>

using namespace std;

void swap(int &a, int &b){
  int c = a;
  a = b;
  b = c;
}

int partition(int* arr, int left, int right, int pivot){
  while(left <= right){
    while(arr[left] < pivot)
      left++;
    while(arr[right] > pivot)
      right--;
    if(left <= right){
      swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }
  return left;
}

void quick_sort(int* arr, int left, int right){
  if(left <= right){
    cout << "left: " << left << " right: " << right << endl;
    int pivot = arr[left + ((right - left)/2)];
    int index = partition(arr, left, right, pivot);
    if((index <= right) && (left != right)){
      quick_sort(arr, left, index-1);
      quick_sort(arr, index, right);
    }
  }
}

int main(){
  int n;
  cout << "Enter size of array" << endl;
  cin >> n;
  int arr[n];
  cout << "Enter array to be sorted" << endl;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  quick_sort(arr, 0, n-1);
  cout << "Sorted array is: " << endl;
  for(int i = 0; i < n; i++){
    cout << arr[i] << endl;
  }
  return 0;
}
