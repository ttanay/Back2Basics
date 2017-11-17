#include<iostream>

using namespace std;

int min(int* values){
  int n = sizeof(values) / sizeof(values[0]), min = values[0];

  for(int i = 0; i < n; i++){
    if(values[i] < min)
      min = values[i];
  }
  return min;
}

int mcm(int*p, int i, int j){
  if(i == j)
    return 0;
  int value_list[j-i];
  for(int k = i; k < j; k++){
    value_list[k-i] = (mcm(p, i, k) + mcm(p, k+1, j) + (p[i-1] * p[k] * p[j]));
  }
  return min(value_list);
}

int main(){
  int *p, n, min_cost;
  cout << "Enter size of p[]" << endl;
  cin >> n;
  p = new int[n];
  cout << "Enter dimensions of matrices(p[]) " << endl;
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }
  min_cost = mcm(p, 1, n-1);
  cout << "Minimum cost of matrix multiplication is: " << min_cost << endl;
  delete p;
  return 0;
}
