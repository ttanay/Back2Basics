#include<iostream>

using namespace std;

void swap(int &a, int &b){
  int c = a;
  a = b;
  b = c;
}

void insertion_sort(int* arr, int n){
  for(int i = 0; i < n; i++){
    for(int j = i; j >= 0; j--){
      if(arr[j] < arr[j-1])
        swap(arr[j], arr[j-1]);
    }
  }
}

int main(){
  int *arr, n;
  cout << "Enter size of array" << endl;
  cin >> n;
  arr = new int[n];
  cout << "Enter array to be sorted" << endl;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  insertion_sort(arr, n);
  cout << "Sorted array is : " << endl;
  for(int i = 0; i < n; i++){
    cout << arr[i] << endl;
  }
  delete arr;
}
