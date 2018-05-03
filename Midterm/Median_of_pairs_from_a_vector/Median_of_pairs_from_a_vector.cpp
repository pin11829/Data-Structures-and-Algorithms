#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Data{
  long long int value;
}data;

bool comp(data* s1, data* s2) {
  return s1->value < s2->value;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int ID, n;
    data temp_input;
    int middle, count = 0;
    vector<Data> vec, b;
    vector<Data*> b1;
    while(cin>>ID){
      cin>>n;
      for(int i=0; i<n; i++){
        cin>>temp_input.value;
        vec.push_back(temp_input);
      }
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          temp_input.value = vec[i].value + vec[j].value;
          b.push_back(temp_input);
          b1.push_back(&b[count]);
          count++;
        }
      }
      stable_sort(b1.begin(), b1.end(), comp);
      middle = count/2;
      cout<<b1[middle]->value;
    }
}
