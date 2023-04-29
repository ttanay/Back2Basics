#include<iostream>

using  namespace std;

int main(){
  int *arr, n, ele;
  cout << "Enter size of array" << endl;
  cin >> n;
  arr = new int[n];
  cout << "Enter Array" << endl;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cout << "Enter element to be searched for" << endl;
  cin >> ele;
  for(int i = 0; i < n; i++){
    if(arr[i] == ele)
      cout <<"Element "<< ele << " found at index: " << i << endl;
    break;
    }
  }
  delete arr;
  return 0;
}
