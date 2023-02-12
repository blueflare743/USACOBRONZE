#include <iostream>
#include <vector>
#include <array> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <fstream> 
using namespace std;

ofstream fout("balancing.out");
ifstream fin("balancing.in");

int main() {
  int n; fin >> n;
  vector<pair<int,int>> coords;
  vector<pair<int, int>> coords1;
  int a, b;
  for(int i = 0; i < n; i++){
    fin >> a;
    fin >> b;
    coords.push_back({a, b});
    coords1.push_back({b, a});
  }
  sort(coords.begin(), coords.end());
  sort(coords1.begin(), coords1.end());
  int solution = 1e6;
  int m;
  int xAxis; 
  int yAxis;
  int q1{}, q2{}, q3{}, q4;
  q4 = coords.size();
  for(int i = 0; i < n; i++){
    int quad4 = q4;
    int quard3 = q3;
    q1 = 0;
    q2 = 0;
    xAxis = coords[i].first - 1;
    for(int j = n - 1; j>=0; j--){
      yAxis = coords1[j].first+1;
      if(quard3 != 0 && coords1[j].first < yAxis && coords1[j].second < xAxis){
        quard3--;
        q1++;
      }
      if(quad4 !=0 && coords1[j].first < yAxis && coords1[j].second  > xAxis){
        quad4--;
        q2++;
      }
      //cout << q1 <<  q2 << q3 << q4 << endl;
      int min1 = max(q1, q2);
      int min2 = max(quard3, quad4);
      int min3 = max(min1, min2);
      solution = min(solution, min3);
    }
    q4--;
    q3++;
  }
  fout << solution << endl;
}