#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int Times, temp_input, temp_input_p, N, K, res_temp;
    vector<int> vec, res;
    while(cin>>Times){
    for(int num=0; num<Times; num++){
        cin>>N>>K;
        for(int i=0; i<N; i++){
            cin>>temp_input;
            vec.push_back(temp_input);
        }
        stable_sort(vec.begin(), vec.end());
        for(int i=0; i<K; i++){
            res.push_back(vec[i]);
        }
        for(int i=K-1; i>0; i--){
            cout<<res[i]<<" ";
        }
        cout<<res[0];
        cout<<"\n";
        vec.clear();
        res.clear();
    }
  }
}
