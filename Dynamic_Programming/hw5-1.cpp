#include <new>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int days, tmp;
  int max_time = 0;
  int max_cnt = 0;
  vector<int> f_num, len, cnt, pre, output_f;

  cin>>days;

  f_num.push_back(0);
  len.push_back(1);
  cnt.push_back(1);
  pre.push_back(0);

  for(int i=0; i<days; i++){
    cin>>tmp;
    f_num.push_back(tmp);
    len.push_back(1);
    cnt.push_back(1);
    pre.push_back(0);
  }

  for(int i=1; i<=days; i++){
    for(int j=1; j<i; j++){
      if(f_num[i] >= f_num[j]){
        if(len[i] < (len[j]+1)){
          cnt[i] = (cnt[j] % 1000000007);
          pre[i] = j;
        }
        else if(len[i] == (len[j]+1)){
          cnt[i] = (cnt[i] + cnt[j]) % 1000000007;
        }
        len[i] = max(len[i], (len[j]+1));
      }
    }
    if(len[i] > max_time){
      max_time = len[i];
    }
  }
  cout<<max_time<<'\n';
  for(int i=1; i<=days; i++){
    if(max_time == len[i]) max_cnt = (max_cnt + cnt[i]) % 1000000007;
  }
  cout<<max_cnt<<'\n';

  for(int i=1; i<=days; i++){
    if(max_time == len[i]){
      output_f.push_back(i);
      tmp = pre[i];
      while(tmp > 0){
        output_f.push_back(tmp);
        tmp = pre[tmp];
      }
      break;
    }
  }

  for(int i=(output_f.size()-1); i>0; i--){
    cout<<output_f[i]<<" ";
  }
  cout<<output_f.front();
}
