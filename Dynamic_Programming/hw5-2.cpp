#include <new>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

static vector<pair<int, int>> pig_vec;
static double a;

bool CompareFloat(double x, double y){
  return (fabs(x-y) <= 0.0000001);
}

bool negative_slop(int i, int j){
  double x1 = pig_vec.at(i).first;
  double y1 = pig_vec.at(i).second;
  double x2 = pig_vec.at(j).first;
  double y2 = pig_vec.at(j).second;
  if(x1*x1*x2 != x1*x2*x2){
    a = (y1*x2 - y2*x1) / (x1*x1*x2 - x1*x2*x2);
    return (a<0);
  }
  return false;
}

bool on_curve(int i, int j, int k){
  double x1 = pig_vec.at(i).first;
  double y1 = pig_vec.at(i).second;
  double x2 = pig_vec.at(j).first;
  double y2 = pig_vec.at(j).second;
  double x = pig_vec.at(k).first;
  double y = pig_vec.at(k).second;
  if(x1*x1*x2 != x1*x2*x2){
    double b = (x2*x2*y1 - x1*x1*y2) / (x1*x2*x2 - x1*x1*x2);
    return (CompareFloat(y, (a*x*x + b*x)));
  }
  return false;
}

int count_bit(unsigned long long n){
  int count = 0;
  for(; n; n>>=1){
    if(n&1){
      count++;
    }
  }
  return count;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int times, num_pig, tmp, xi, yi;
  unsigned long long pigset;
  vector<int> DP;

  cin>>times;

  for(int num=0; num<times; num++){
    cin>>num_pig;

    for(int i=0; i<num_pig; i++){
      cin>>xi>>yi;
      pig_vec.push_back(make_pair(xi, yi));
    }
    pigset = (1<<num_pig) - 1;
    for(unsigned long long i=0; i<=pigset; i++){
      DP.push_back(count_bit(i));
    }

    unsigned long long para[num_pig][num_pig];
    for(unsigned long long i=0; i<num_pig; i++){
      for(unsigned long long j=i+1; j<num_pig; j++){
        para[i][j] = (1<<i);
        if(negative_slop(i, j)){
          para[i][j] += (1<<j);
          for(int k=(j+1); k<num_pig; k++){
            if(on_curve(i, j, k)) para[i][j] += (1<<k);
          }
        }
      }
    }

    for(unsigned long long i=0; i<=pigset; i++){
      for(int j=0; j<num_pig; j++){
        if(((1<<j) & i) == 0) continue;
        for(unsigned long long k=(j+1); k<num_pig; k++){
          if(((1<<k) & i) == 0) continue;
          DP[i] = min(DP[i], (DP[(i & (~para[j][k]))]+1));
        }
        break;
      }
    }
    if(num != (times-1)){
      cout<<DP.back()<<'\n';
      pig_vec.clear();
      DP.clear();
    }
    else cout<<DP.back();
  }
}
