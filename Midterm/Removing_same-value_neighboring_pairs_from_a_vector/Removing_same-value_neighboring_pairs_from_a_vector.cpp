#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int size, temp_input, temp_input_p, ifzero;
    temp_input_p = 500;
    cin>>size;
    vector<int> input_array;
    for(int i=0; i<size; i++){
        cin>>temp_input;
        if(temp_input_p == temp_input){
            input_array.pop_back();
            temp_input_p = input_array.back();
        }
        else{
            input_array.push_back(temp_input);
            temp_input_p = temp_input;
        }
    }

    ifzero = input_array.size();
    if(input_array.empty()){
        cout<<"Meow";
    }
    else{
        for(int i=0; i<input_array.size()-1; i++){
            cout<<input_array[i]<<" ";
        }
        cout<<input_array.back();
    }

}
