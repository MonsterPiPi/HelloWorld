#include<cstdio>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
string a,b;
int loc1,loc2,ma=0;
vector<int>tag1(1,0);
vector<int>tag2(1,0);
int main() {
    getline(cin,a);
    getline(cin,b);
    vector<vector<int> >dp(a.size()+1,vector<int>(b.size()+1,0));
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            (a[i-1]==b[j-1])?dp[i][j]=dp[i-1][j-1]+1:dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(dp[i][j]>ma){
                ma=dp[i][j];
                loc1=i;
                loc2=j;
            }
        }
    }
    while(loc1>0&&loc2>0){
        if(dp[loc1-1][loc2]==dp[loc1][loc2])loc1--;
        else if(dp[loc1][loc2-1]==dp[loc1][loc2])loc2--;
        else{
            tag1.push_back(loc1);
            tag2.push_back(loc2);
            loc1--;
            loc2--;
        }
    }
    tag1.push_back(a.size());
    tag2.push_back(b.size());
    sort(tag1.begin(),tag1.end());
    sort(tag2.begin(),tag2.end());
    int total=0;
    for(int i=1;i<tag1.size();i++){
        total+=max(max(tag1[i]-tag1[i-1]-1,tag2[i]-tag2[i-1]-1),0);
    }
    printf("%d",total);
}
