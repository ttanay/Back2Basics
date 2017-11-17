#include<iostream>
#include<climits>

using namespace std;

int mcm(int* p, int n){
    int m[n][n]; 
    int i, j, k, L, q;
    for (i=1; i<n; i++)
        m[i][i] = 0;
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
  return m[1][n-1];
}

int main(){
  int n, min_cost;
  cout << "Enter size of p[]" << endl;
  cin >> n;
  int p[n];
  cout << "Enter p[]" << endl;
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }
  min_cost = mcm(p, n);
  cout << "Minimum cost of multiplication is: " << min_cost << endl;
  return 0;
}
