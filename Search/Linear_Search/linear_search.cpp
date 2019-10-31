#include<iostream>

using  namespace std;

int main(){
  int n, ele;
  cout << "Enter size of array" << endl;
  cin >> n;
  int a[n];
  cout << "Enter Array" << endl;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cout << "Enter element to be searched for" << endl;
  cin >> ele;
  for(int i = 0; i < n; i++){
    if(a[i] == ele){
      cout <<"Element "<< ele << " found at index: " << i << endl;
    break;
    }
  }
  return 0;
}
