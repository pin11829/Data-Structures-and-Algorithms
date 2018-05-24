#include <new>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define NO_OF_CHARS 256
using namespace std;

int max(int a, int b){
  return (a>b) ? a : b;
}

void suffix(string pattern, int M, int* suff){
  int k, j;
  suff[M - 1] = M;
  for(int i=(M-2); i>=0; i--){
    j = i;
    while(j>=0 && pattern[j] == pattern[M - 1 - i + j]) j--;
    suff[i] = i - j;
  }
}

void badCharHeuristic(string pattern, int M, int* badchar){
  // Initialize all occurrences as -1
  for(int i=0; i<NO_OF_CHARS; i++) badchar[i] = M;
  // Fill the actual value of last occurrence of a character
  for(int i=0; i<(M-1); i++) badchar[pattern[i]] = M - 1 - i;
}

void goodCharHeuristic(string pattern, int M, int* goodchar, int* suff){
  suffix(pattern, M, suff);
  //Initialize all occurences as -1
  //Include case 3
  for(int i=0; i<M; i++) goodchar[i] = M;
  //case 2
  for(int i=(M-1); i>=0; i--){
    if(suff[i] == i+1){//Match the same part
      for(int j=0; j<(M-1-i); j++){
        if(goodchar[j] == M) goodchar[j] = M - 1 - i;
      }
    }
  }
  //case 1
  for(int i=0; i<=M-2; i++) goodchar[M - 1 - suff[i]] = M - i - 1;
}

int BoyerMooreSearch(string text, string pattern){
  int M = pattern.size();
  int N = text.size();
  int badchar[NO_OF_CHARS];
  int goodchar[M];
  int suff[M];
  badCharHeuristic(pattern, M, badchar);
  goodCharHeuristic(pattern, M, goodchar, suff);
  int shift = 0;
  int skip = 0;
  int count = 0;
  while(shift <= (N-M)){
    int j = M-1;
    while(j >= 0 && pattern[j] == text[shift + j]){
      j--;
    }
    if(j < 0){
      shift += (shift + M < N) ? badchar[text[shift + M]] : 1;
      count++;
    }
    else{
      shift += max(badchar[text[shift + j]] - M + 1 + j, goodchar[j]);
      //shift += max(1, skip);
    }
  }
  return count;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string sentence, c, pattern;
  int Time, type;
  string::size_type pos=0;
  int count = 0;
  while(cin>>sentence){
    cin>>Time;
    for(int i=0; i<Time; i++){
      cin>>type;
      if(type == 1){
        cin>>c;
        sentence = c + sentence;
      }
      else if(type == 2){
        cin>>c;
        sentence = sentence + c;
      }
      else{
        cin>>pattern;
        count = BoyerMooreSearch(sentence, pattern);
        cout<<count<<'\n';
      }
    }
  }
}
