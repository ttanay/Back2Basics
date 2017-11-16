#include<iostream>

using namespace std;

void merge(int* arr, int l, int m, int r){
  cout << "merge(l: " << l << "m: " << m << "r: " << r << ")" << endl;
  int temp[r-l+1], i, j, k;

  i = l;
  j = m+1;
  k = 0;

  while(i <= m && j <= r){
    if(arr[i] < arr[j]){
      temp[k] = arr[i];
      i++;
    }
    else{
      temp[k] = arr[j];
      j++;
    }
    k++;
  }

  while(i <= m){
    temp[k] = arr[i];
    k++;
    i++;
  }

  while(j <= r){
    temp[k] = arr[j];
    k++;
    j++;
  }

  for(i = l, k = 0; i <= r; i++, k++){
    arr[i] = temp[k];
  }
}

void merge_sort(int* arr, int l, int r){
  if(l < r){
    int  m = l + ((r - l) / 2);
    cout << "merge_sort(l: " << l << " m: " << m << " r: " <<r << " )" << endl;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
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
  merge_sort(arr, 0, n-1);
  cout << "Sorted array is :" << endl;
  for(int i = 0; i < n; i++){
    cout << arr[i] << endl;
  }
  return 0;
}
