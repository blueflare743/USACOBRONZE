#include <iostream>
#include <vector> 
#include <array> 
#include <algorithm> 

using namespace std;
int main() {
 array<array<int, 1000>, 1000> arr;
 int n; cin >> n;
 int a;
 for(int i = 0; i < n;i++){
   for(int j = 0; j < n;j++){
     cin >> a;
     arr[i][j] = a; 
   }
 }
  // search columns 
  int sum = 0;
  for(int i = 0; i  < n; i++){
    int sum1 = 0;
    int sum2 = 0;
    for(int j = 0, k = 1; j < n; j+=2,k +=2){
      sum1 += arr[j][i];
      sum2 += arr[k][i];
    }
    sum += max(sum1, sum2);
  }
  // search rows
int sum3 = 0;
  for(int i = 0; i < n; i++){
    int sum1 = 0;
    int sum2 = 0;
    for(int j = 0, k = 1; j < n; j+=2, k +=2){
      sum1 += arr[i][j];
      sum2 += arr[i][k];
    }
    sum3 += max(sum1, sum2);

}
    cout << max(sum, sum3);
  return 0;
  }
