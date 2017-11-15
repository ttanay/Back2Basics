#include<iostream>

using namespace std;

void swap(int &a, int &b){
  int c = a;
  a = b;
  b = c;
}

void bubble_sort(int* arr, int n){
  for(int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
      if(arr[j] < arr[j-1]){
        swap(arr[j], arr[j-1]);
      }
    }
  }
}

int main(){
  int arr[100], n;
  cout << "Enter size of array" << endl;
  cin >> n;
  cout << "Enter array to be sorted" << endl;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  bubble_sort(arr, n);
  cout << "Sorted array is:" << endl;
  for(int i = 0; i < n; i++){
    cout << arr[i] << endl;
  }
  return 0;
}
