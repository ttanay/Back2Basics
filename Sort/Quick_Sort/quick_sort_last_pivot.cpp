#include<iostream>

using namespace std;

void swap(int &a, int &b){
  int c = a;
  a = b;
  b = a;
}

int partition(int* arr, int left, int right, int pivot){
  int i = left - 1;
  for(int j = left; j < right; j++){
    if(arr[j] <= pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[right]);
  return i+1;
}

void quick_sort(int* arr, int left, int right){
  cout << "left: " << left << " right: " << right << endl;
  if(left < right){
    int pivot = arr[right];
    int index = partition(arr, left, right, pivot);
    quick_sort(arr, left, index-1);
    quick_sort(arr, index+1, right);
  }
}

int main(){
  int n;
  cout << "Enter size of array to be sorted" << endl;
  cin >> n;
  int arr[n];
  cout << "Enter array to be sorted" << endl;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  quick_sort(arr, 0, n-1);
  cout << "Sorted Array is: " << endl;
  for(int i = 0; i < n; i++){
    cout << arr[i] << endl;
  }
  return 0;
}
