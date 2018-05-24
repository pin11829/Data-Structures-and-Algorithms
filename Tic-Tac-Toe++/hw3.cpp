#include <new>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long int Input(long long int board_int, vector<int> *position_empty, int *round_){
  int plot = 0;
  char temp_char;
  long long int temp_int = 0;
  for(int i=0; i<25; i++){
    cin>>temp_char;
      if(temp_char == 'X'){
        temp_int = 1;
        board_int |= (temp_int<<(2*i));
        plot++;
      }
      else if(temp_char == 'O'){
        temp_int = 2;
        board_int |= (temp_int<<(2*i));
        plot++;
      }
      else{
        position_empty->push_back(i);
      }
  }
  *round_ = (plot/2);
  return board_int;
}

long long int Play(int x, int y, long long int board_int, int round_){
  long long int temp_int = 0;
  auto Valid = [](int z){return z >= 0 && z < 25;};
  if (!(Valid(x) && Valid(y)) ||
      ((board_int>>(2*x)) & 3) != 0 || ((board_int>>(2*y)) & 3) != 0) return 0;
  if(round_ & 1){//O
    temp_int = 2;
    board_int |= (temp_int<<(2*x));
    board_int |= (temp_int<<(2*y));
  }
  else{
    temp_int = 1;
    board_int |= (temp_int<<(2*x));
    board_int |= (temp_int<<(2*y));
  }
  return board_int;
}

vector<int> new_empty(int i, int j, vector<int> position_empty){
  position_empty.erase(position_empty.begin()+i);
  position_empty.erase(position_empty.begin()+(j-1));
  return position_empty;
}

long long int Finish(long long int board_int){
  long long int temp_int = 0;
  for (int i = 0; i < 25; i++){
    temp_int = 3;
    if(((temp_int<<(2*i)) & board_int) == 0){
      temp_int = 1;
      board_int |= (temp_int<<(2*i));
    }
  }
  return board_int;
}

int Evaluate(long long int board_int){
  char a[12], b[12];
  int sO = 0, sX = 0;
  memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
  for (int i = 0; i < 25; i++) {
    if (((board_int>>(2*i)) & 3) == 0) continue;
    char* z = ((board_int>>(2*i)) & 2) == 2 ? a : b; //to cauculate if there is a line or not
    z[(i%5) + 1]++; z[(i/5) + 7]++;
    if ((i/5) == (i%5)) z[0]++;
    if ((i/5) == 4 - (i%5)) z[6]++;
  }
  for (int i = 0; i < 12; i++) {
    if (a[i] >= 4) sO++;
    else if (b[i] >= 4) sX++;
  }
  return sO >= sX ? sO > sX : -1;
}

void Record(long long int board_int, unordered_map<long long int, int> &map){
  long long int temp_int;
  temp_int = board_int|(1ll<<(2*25));
  map[temp_int] = -2;
  temp_int = board_int|(2ll<<(2*25));
  map[temp_int] = -2;
  temp_int = board_int|(3ll<<(2*25));
  map[temp_int] = -2;
}

int PlayGame(long long int board_int, int round_, vector<int> position_empty, unordered_map<long long int, int> &map, int alpha, int beta){
  unordered_map<long long int, int>::iterator it;
  it = map.find(board_int);
  int v;
  if (it != map.end() && it->second != -2) return it->second;
  else Record(board_int, map);
  long long int temp_int, temp_ab = 0;
  vector<int> temp_empty;
  if(round_ == 11){
    temp_int = Finish(board_int);
    v = Evaluate(temp_int);
    map[board_int] = v;
    return v;
  }
  else{
    if((round_++) & 1){//X, round+1
      v = 1;//O win
      for(int i=0; i<position_empty.size(); i++){
        for(int j=i+1; j<position_empty.size(); j++){
          temp_int = Play(position_empty[i], position_empty[j], board_int, round_);
          temp_empty = new_empty(i, j, position_empty);
          if(alpha == -1 && beta == 0) temp_ab = 1;
          else if(alpha == -1 && beta == 1) temp_ab = 2;
          else if(alpha == 0 && beta == 1) temp_ab = 3;
          temp_int |= (temp_ab<<(2*25));
          v = min(v, PlayGame(temp_int, round_, temp_empty, map, alpha, beta));
          if (v < beta) beta = v;
          if(beta<=alpha){
            map[board_int] = v;
            return v;
          }
        }
      }
      map[board_int] = v;
      return v;
    }
    else{
      v = -1;//X win
      for(int i=0; i<position_empty.size(); i++){
        for(int j=i+1; j<position_empty.size(); j++){
          temp_int = Play(position_empty[i], position_empty[j], board_int, round_);
          temp_empty = new_empty(i, j, position_empty);
          if(alpha == -1 && beta == 0) temp_ab = 1;
          else if(alpha == -1 && beta == 1) temp_ab = 2;
          else if(alpha == 0 && beta == 1) temp_ab = 3;
          temp_int |= (temp_ab<<(2*25));
          v = max(v, PlayGame(temp_int, round_, temp_empty, map, alpha, beta));
          if (v > alpha) alpha = v;
          if(beta<=alpha){
            map[board_int] = v;
            return v;
          }
        }
      }
      map[board_int] = v;
      return v;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int round_, Times, res, alpha, beta;
  long long int board_int, temp_ab;
  vector<int> position_empty;
  unordered_map<long long int, int> map;
  alpha = -1;
  beta = 1;
  while(cin>>Times){
    for(int num=0; num<Times; num++){
      board_int = 0;
      position_empty.clear();
      board_int = Input(board_int, &position_empty, &round_);
      if(round_ == 11){
        board_int = Finish(board_int);
        res = Evaluate(board_int);
        cout<<(res ? res > 0 ? "O win" : "X win" : "Draw")<<"\n";
      }
      else{
        temp_ab = 2;
        board_int |= (temp_ab<<(2*25));
        res = PlayGame(board_int, round_, position_empty, map, alpha, beta);
        cout<<(res ? res > 0 ? "O win" : "X win" : "Draw")<<"\n";
      }
    }
  }
}
