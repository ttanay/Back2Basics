#include<iostream>

using namespace std;

int find_min(int* arr, int beg, int end){
  int min = beg;
  for(int i = beg + 1; i < end; i++){
    if(arr[i] < arr[min])
      min = i;
  }
  return min;
}

void swap(int &a, int &b){
  int c = a;
  a = b;
  b = c;
}

void selection_sort(int* arr, int n){
  int index;
  for(int i = 0; i < n; i++){
    index = find_min(arr, i, n);
    swap(arr[i], arr[index]);
  }
}

int main(){
  int *arr, n;
  cout << "Enter size of array to sort" << endl;
  cin >> n;
  arr = new int[n];
  cout << "Enter array to sort" << endl;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  selection_sort(arr, n);
  cout << "Sorted array: " << endl;
  for(int i = 0; i < n; i++){
    cout << arr[i] << endl;
  }
  delete arr;
}
