#include<iostream>
#include<climits>

using namespace std;

struct matrix{
  int length, direction;
};

int max(matrix a, matrix b){
  if(a.length > b.length)
    return -1;
  else
    return 1;
}

void lcs(char* str1, int n1, char* str2, int n2, char* subsequence, int n){
  int k = 0;
  matrix cell[n1+1][n2+1], head;

  for(int i = 0; i <= n1; i++){
    cell[i][0].length = 0;
    cell[i][0].direction = 2;
  }

  for(int i = 0; i <= n2; i++){
    cell[0][i].length = 0;
    cell[0][i].direction = 2;
  }

  for(int i = 1; i <= n1; i++){
    for(int j = 1; j <= n2; j++){
      if(str1[i] == str[j]){
        cell[i][j].length = cell[i-1][j-1].length + 1;
        cell[i][j].direction = 0;
      }
      else{
        cell[i][j].direction = max(cell[i][j-1], cell[i-1][j]);
        if(cell[i][j].direction == 1)
          cell[i][j].length = cell[i-1][j].length;
        else
          cell[i][j].length = cell[i][j-1].length;
      }
    }
  }

  head = cell[n1][n2];
  while(head.direction != 2){
    //reproduc subseqence algorithm
  }

}

int main(){
  int n1, n2, n;
  cout << "Enter length of string 1" << endl;
  cin >> n1;
  cout << "Enter length of string 2" << endl;
  cin >> n2;
  (n1 > n2)? n = n2: n = n1;
  char str1[n1], str2[n2], subsequence[n];
  cout << "Enter string 1:" << endl;
  for(int i = 0; i < n1; i++){
    cin >> str1[i];
  }
  cout << "Enter string 2: " << endl;
  for(int i = 0; i < n2; i++){
    cin >> str2[i];
  }
  lcs(str1, n1, str2, n2, subsequence, n); // to store lcs in subsequence
  return 0;
}
