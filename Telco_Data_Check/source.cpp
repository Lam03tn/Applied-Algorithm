#include<bits/stdc++.h>
using namespace std;

vector<string> fnum;
vector<string> tnum;
vector<int> total_times;

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
    
    while(cin>>first){
        if(first == "#") break;
        cin>>from_number>>to_number>>date>>from_time>>to_time;
        total_call ++;
        if(from_number.size() != 10 || to_number.size() != 10)  phoneCheck = 0;
        fnum.push_back(from_number);
        tnum.push_back(to_number);
        total_times.push_back(timeCount(from_time, to_time));
        
    }
    
    
    string query;
    while(getline(cin, query)){
        if(query == "?check_phone_number"){
            cout<<phoneCheck<<endl;
        }
        
        if(query == "?number_total_calls"){
            cout<<total_call<<endl;
        }
        
        if(query.find("?number_calls_from") == 0){
            int pos = query.find(' ');
            string from_number = query.substr(pos + 1);
        }
        
        if(query.find("?count_time_calls_from") == 0){
            int pos = query.find(' ');
            int timecall = 0;
            string from_number = query.substr(pos + 1);
            for(int i = 0; i < fnum.size(); i ++){
                
                if(fnum.at(i).compare(from_number)){
                    timecall += total_times.at(i);
                }
            }
            cout<<timecall<<endl;
        }
    }
    
}
