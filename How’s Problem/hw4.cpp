#include <new>
#include <vector>
#include <deque>
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const unsigned Prime_base = 29;
const unsigned Prime_MOD = 1000000007;

long long Rolling_hash_Ti(const string sentence){
  long long ret = 0;
  for(int i=0; i<sentence.size(); i++){
    ret = ret * Prime_base + (sentence[i] - 'a' + 1);
    ret %= Prime_MOD;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string input, Ti, c;
  deque<int> sentence;
  int Time, type;
  int count = 0;
  unordered_map<long long, int> map;
  unordered_map<long long, int>::iterator it;
  long long hash_Ti, power;
  long long hash_substr = 0;
  long long temp = 0;
  long long power_x[20];
  power_x[0] = 1;
  for(int i=1; i<20; i++){
    power_x[i] = (power_x[i-1] * Prime_base) % Prime_MOD;
  }
  while(cin>>input){
    for(int i=0; i<input.size(); i++){
      sentence.push_back(input[i]-'a'+1);
    }
    cin>>Time;
    for(int i=0; i<Time; i++){
      cin>>type;
      if(type == 1){
        cin>>c;
        sentence.push_front(c[0]-'a'+1);
        temp = 0;
        for(int i=0; i<sentence.size() && i<20; i++){
          temp = temp * Prime_base + sentence[i];
          temp %= Prime_MOD;
          it = map.find(temp);
          if (it != map.end()) it->second += 1;
        }
      }
      else if(type == 2){
        cin>>c;
        sentence.push_back(c[0]-'a'+1);
        for(int i=0; i<20 && i<sentence.size(); i++){
          temp = 0;
          for(int j=0; j<=i; j++){
            temp += (sentence[sentence.size()-1-j] * power_x[j]) % Prime_MOD;
          }
          temp %= Prime_MOD;
          it = map.find(temp);
          if (it != map.end()) it->second += 1;
        }
      }
      else{
        cin>>Ti;
        count = 0;
        power = 1;
        long long hash_str[sentence.size()];
        hash_Ti = Rolling_hash_Ti(Ti);
        if(Ti.size()>sentence.size()){
          count = 0;
        }
        else if(Ti.size()<=20){
          it = map.find(hash_Ti);
          if (it != map.end())
          {
            count = it->second;
            cout<<count<<endl;
            continue;
          }
          for(int i=0; i<Ti.size(); i++){
            power = (power * Prime_base) % Prime_MOD;
          }
          for(int i=0; i<sentence.size(); i++){
            if(i==0) hash_str[i] = sentence[i] % Prime_MOD;
            else hash_str[i] = (hash_str[i-1] * Prime_base + sentence[i]) % Prime_MOD;
          }
          for(int i=0; i<(sentence.size()-Ti.size()+1); i++){
            if(i==0) hash_substr = (hash_str[i+Ti.size()-1] + Prime_MOD) % Prime_MOD;
            else hash_substr = (hash_str[i+Ti.size()-1] - hash_str[i-1] * power % Prime_MOD + Prime_MOD) % Prime_MOD;
            if(hash_substr == hash_Ti){
              count++;
            }
          }
          map[hash_Ti] = count;
        }
        else{
          for(int i=0; i<Ti.size(); i++){
            power = (power * Prime_base) % Prime_MOD;
          }
          for(int i=0; i<sentence.size(); i++){
            if(i==0) hash_str[i] = sentence[i] % Prime_MOD;
            else hash_str[i] = (hash_str[i-1] * Prime_base + sentence[i]) % Prime_MOD;
          }
          for(int i=0; i<(sentence.size()-Ti.size()+1); i++){
            if(i==0) hash_substr = (hash_str[i+Ti.size()-1] + Prime_MOD) % Prime_MOD;
            else hash_substr = (hash_str[i+Ti.size()-1] - hash_str[i-1] * power % Prime_MOD + Prime_MOD) % Prime_MOD;
            if(hash_substr == hash_Ti){
              count++;
            }
          }
          map[hash_Ti] = count;
        }
        cout<<count<<'\n';
      }
    }
  }
}
