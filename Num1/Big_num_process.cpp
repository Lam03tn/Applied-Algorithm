#include<bits/stdc++.h>
using namespace std;

string sum(string a, string b){
    int len_a = a.size();
    int len_b = b.size();
    int max = (len_a > len_b) ? len_a : len_b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = len_a; i < max; i++) a.append("0");
    for(int i = len_b; i < max; i++) b.append("0");
    int c_out = 0, i = 0;
    string sum;
    while(i < max){
        int sum_i = a[i] + b[i] - '0' - '0';
        if(c_out > 0){
            sum_i += c_out;
            c_out = 0;
        }
        if(sum_i > 9){
            c_out += sum_i / 10;
            sum_i = sum_i % 10;
        }
        sum.append(to_string(sum_i));
        i++;
    }
    if(c_out == 1) sum.append("1");
    reverse(sum.begin(), sum.end());
    return sum;

}

int main(){
    string a,b;     cin>>a>>b;
    cout<<sum(a,b)<<endl;
}