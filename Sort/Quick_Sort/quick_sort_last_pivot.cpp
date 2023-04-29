#include<iostream>

using namespace std;

void swap(int &a, int &b){
  cout << "swapping " << a << "&" << b << endl;
  int c = a;
  a = b;
  b = a;
}

int partition(int* arr, int left, int right){
  int pivot = arr[right], plus, minus;
  int i = left, j = right - 1;
  while(i <= j){
    while(arr[i] < pivot && i < right)
      i++;

    while(arr[j] > pivot && j >= left)
      j--;

    if(arr[i] > pivot && arr[j] < pivot ){
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
    cout << i << j << endl;
  }
  /*for(int j = left; j < right; j++){
    if(arr[j] <= pivot){
      q = j;

      //i++;
      //swap(arr[i], arr[j]);
    }
  }
  */
  if(arr[i+1] > arr[right])
    swap(arr[i+1], arr[right]);
  cout << i << endl;
  return i;
}

void quick_sort(int* arr, int left, int right){
   if(left < right){
    cout << "left: " << left << " right: " << right << endl;
    int index = partition(arr, left, right);

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
