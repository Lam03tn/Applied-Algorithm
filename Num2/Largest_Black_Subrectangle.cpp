#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n){
    stack<int> s;
    int max_area = 0;
    int tp = 0;
    int area_with_top = 0;
    int i = 0;
    while(i < n){
        
        if(s.empty() || hist[s.top()] <= hist[i]){
            s.push(i++);
        }
        else{
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] *(s.empty() ? i : i - s.top() - 1);
        }
        
        if(max_area < area_with_top)
            max_area = area_with_top;
    }
    
    while(!s.empty()){
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] *(s.empty() ? i : i - s.top() - 1);
        if(max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}


int main(){
    int m,n;
    cin>>m>>n; int A[m][n];
    for(int i =0; i < m; i++){
        for(int j =0; j<n; j ++){
            cin>>A[i][j];
        }
    }
    
    int hist[m][n] = {};
    for(int j =0; j< n; j++){
        if(A[0][j] == 1){
            hist[0][j] =1;
        }
    }
    
    for(int i =1; i < m; i ++){
        for(int j =0; j<n; j ++){
            if(A[i][j] == 1){
                hist[i][j] = hist[i - 1][j] + 1;
            }
            else{
                hist[i][j] = 0;
            }
        }
    }
    
    int max_area[m];
    
    for(int i = 0; i<m;i++){
        max_area[i] = getMaxArea(hist[i],n);
    }
        
    
    printf("%d", *max_element(max_area, max_area + m));
}