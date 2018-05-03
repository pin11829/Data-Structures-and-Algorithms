#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <new>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct Data{
  string instr, date, currency, exchange;
  float low, high;
  long long int daily_caps;
}data;

bool cmp(data *data1, data *data2){
  if(data1->date != data2->date)
    return (data1->date < data2->date);
  else if(data1->currency != data2->currency)
    return (data1->currency < data2->currency);
  else if(data1->exchange != data2->exchange)
    return (data1->exchange < data2->exchange);
  else
    return 0;
}

bool cmp1(data *data1, data *data2){
  if(data1->date != data2->date)
    return (data1->date < data2->date);
  else if(data1->exchange != data2->exchange)
    return (data1->exchange < data2->exchange);
  else
    return 0;
}

bool cmp2(data *data1, data *data2){
  if(data1->date != data2->date)
    return (data1->date < data2->date);
  if(data1->currency != data2->currency)
    return (data1->currency < data2->currency);
  if(data1->exchange != data2->exchange)
    return (data1->exchange < data2->exchange);
  else
    return 0;
  }

bool cmp3(data *data1, data *data2){
  if(data1->date != data2->date)
    return (data1->date < data2->date);
  if(data1->currency != data2->currency)
    return (data1->currency < data2->currency);
  else
    return 0;
}

bool cmp4(data *data1, data *data2){
  if(data1->date != data2->date)
    return (data1->date < data2->date);
  if(data1->exchange != data2->exchange)
    return (data1->exchange < data2->exchange);
  else
    return 0;
}

int main(int argc, char *argv[]){
  ifstream input(argv[1]);
  int count = 0;
  data pub_data;
  vector<data> vec;
  vec.reserve(3000000);
  vector<Data*> vec1;
  vector<Data*> vec2;
  while(input>>pub_data.date){
    input>>pub_data.currency>>pub_data.exchange>>pub_data.low>>pub_data.high>>pub_data.daily_caps;
    vec.push_back(pub_data);
    vec1.push_back(&vec[count]);
    vec2.push_back(&vec[count]);
    count++;
  }
  count--;
  stable_sort(vec1.begin(), vec1.end(), cmp);
  stable_sort(vec2.begin(), vec2.end(), cmp1);

  float flmax, flmin;
  long long int cap = 0;
  string type;
  data data_q, data_p, data_c;
  vector<data> vec_q;
  vec_q.reserve(3000000);
  pair<vector<Data*>::iterator, vector<Data*>::iterator> bound;
  vector<Data*>::iterator iter;
  while(cin>>data_q.instr){
    if(data_q.instr == "query"){
      cin>>data_q.date>>data_q.currency>>data_q.exchange;
      bound = equal_range(vec1.begin(), vec1.end(), &data_q, cmp2);
      if(bound.first != bound.second){
        cout<<fixed<<setprecision(4)<<(*bound.first)->low<<" "<<(*bound.first)->high<<" "<<(*bound.first)->daily_caps<<"\n";
      }
      else{
        cout<<"none"<<"\n";
      }
    }
    else if(data_q.instr == "price"){
      cin>>type;
      cin>>data_p.date>>data_p.currency;
      bound = equal_range(vec1.begin(), vec1.end(), &data_p, cmp3);
      flmax = 0.0000;
      flmin = 0.0000;
      if(bound.first != bound.second){
        flmax = (*bound.first)->high;
        flmin = (*bound.first)->low;
        for(iter=bound.first; iter<bound.second; iter++){
          if(type == "max"){
            if(flmax<(*iter)->high){
              flmax = (*iter)->high;
            }
          }
          else{
            if(flmin>(*iter)->low){
              flmin = (*iter)->low;
            }
          }
        }
        if(type == "max"){
          cout<<fixed<<setprecision(4)<<flmax<<"\n";
        }
        else{
          cout<<fixed<<setprecision(4)<<flmin<<"\n";
        }
      }
      else{
        cout<<"none"<<"\n";
      }
    }
    else if(data_q.instr == "cap"){
      cap = 0;
      cin>>data_c.date>>data_c.exchange;
      bound = equal_range(vec2.begin(), vec2.end(), &data_c, cmp4);
      if(bound.first != bound.second){
        for(iter=bound.first; iter<bound.second; iter++){
          cap += (*iter)->daily_caps;
        }
        cout<<cap<<"\n";
      }
      else{
        cout<<"none"<<"\n";
      }
    }
    else if(data_q.instr == "end"){
      break;
    }
  }
  return 0;
}
