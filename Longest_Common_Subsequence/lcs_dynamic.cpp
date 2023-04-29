#include<iostream>
#include<climits>

using namespace std;

struct matrix{
  int length, direction;
};

struct subsequence{
  int length;
  char* subseq_string;
};

int max(matrix a, matrix b){
  if(a.length > b.length)
    return -1;
  else
    return 1;
}

subsequence lcs(char* str1, int n1, char* str2, int n2){
  int k = 0, max_length = 0, n;
  n2 < n1 ? (n = n2): (n = n1);
  matrix cell[n1+1][n2+1];
  char *sq = new char[n];

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
      if(str1[i] == str2[j]){
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


  for(int i = n1, j = n2; cell[i][j].direction != 2;){
    //reproduce subseqence algorithm
    if(cell[i][j]. direction == 0){
      if(!max_length)
        max_length = cell[i][j].length+1;
      sq[k] = str1[i+1];
      k++;
      i--;
      j--;
    }
    else if(cell[i][j].direction == -1){
      j--;
    }
    else{
      i--;
    }
  }

  for(int i = 0; i <= n1; i++){
    for(int j = 0; j <= n2; j++){
      cout << cell[i][j].length << "\t";
    }
    cout << endl;
  }

  subsequence s;
  s.subseq_string = sq;
  s.length = max_length;

  return s;
}

int main(){
  int n1, n2;
  subsequence sq;
  cout << "Enter length of string 1" << endl;
  cin >> n1;
  cout << "Enter length of string 2" << endl;
  cin >> n2;
  char str1[n1], str2[n2];
  cout << "Enter string 1:" << endl;
  for(int i = 0; i < n1; i++){
    cin >> str1[i];
  }
  cout << "Enter string 2: " << endl;
  for(int i = 0; i < n2; i++){
    cin >> str2[i];
  }
  sq = lcs(str1, n1, str2, n2); // to store lcs in subsequence
  cout << "Subsequence is:" << endl;
  for(int i = 0; i <= sq.length; i++)
    cout << sq.subseq_string[i];
  return 0;
}
