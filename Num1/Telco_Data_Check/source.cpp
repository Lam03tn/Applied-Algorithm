#include<bits/stdc++.h>
using namespace std;

unordered_map<string, pair<int,int>> fnum_time;

int timeCount(string begin, string end){
    int hour_diff =  stoi(end.substr(0,2)) - stoi(begin.substr(0,2));
    int minute_diff = stoi(end.substr(3,2)) - stoi(begin.substr(3,2));
    int second_diff = stoi(end.substr(6,2)) - stoi(begin.substr(6,2));
    int timecall = hour_diff * 3600 + minute_diff * 60 + second_diff;
    return timecall;
}

int main(){
    
    string first;
    string from_number, to_number, date, from_time, to_time;
    
    int phoneCheck = 1;
    int total_call = 0;
    
    while(cin>>first && first != "#"){
        cin>>from_number>>to_number>>date>>from_time>>to_time;
        total_call ++;
        if(from_number.size() != 10 || to_number.size() != 10)  phoneCheck = 0;
        int timecall = timeCount(from_time, to_time);
        
        auto &v = fnum_time[from_number];
        v.first += timecall;
        v.second++;
    }
    
    string query;
    while(getline(cin, query)){
        if(query.find("?number_calls_from") == 0){
            int pos = query.find(' ');
            string from_number = query.substr(pos + 1);
            int call_count = 0;
            auto &it = fnum_time[from_number];
            cout<<it.second<<endl;
            continue;
        }
        
        if(query.find("?count_time_calls_from") == 0){
            int pos = query.find(' ');
            int timecall = 0;
            string from_number = query.substr(pos + 1);
            auto &it = fnum_time[from_number];
            cout<<it.first<<endl;
            continue;
        }
        if(query == "?check_phone_number"){
            cout<<phoneCheck<<endl;
            continue;
        }
        
        if(query == "?number_total_calls"){
            cout<<total_call<<endl;
        }
        
        
    }
    
}