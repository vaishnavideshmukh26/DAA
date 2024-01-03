#include<bits\stdc++.h>
using namespace std;

struct knasp
{
    int wit;
    int pro;
};

int main(){
    int n;
    cin>>n;
    int cap;
    cin>>cap;

    vector<knasp>container(n);
    for(int i=0;i<n;i++){
        
        cin>>container[i].wit;
        cin>>container[i].pro;
    }

    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
    vector<int>selection;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=cap; j++){
            int non_take=dp[i-1][j];
            int take=INT_MIN;
            if(j >= container[i-1].wit){
                take=container[i-1].pro + dp[i-1][j-container[i-1].wit];
            }
            dp[i][j]=max(take, non_take);
        }
    }

/*for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){
            int non_take=dp[i-1][j];
            int take=INT_MAX;
            if(j>=contener[i-1].wit){
                take=contener[i-1].pro+dp[i-1][j-contener[i-1].wit];
            }
            dp[i][j]=max(take,non_take);
        }
    }*/
     for(int i=0; i<=n; i++){
        for(int j=0; j<=cap; j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }

    int k=cap;
    for(int i=n;i>0;i--){
        if(dp[i-1][k]!=dp[i][k]){
            selection.push_back(i);
            k-=container[i-1].wit;
        }
    }

    for(int i=0;i<selection.size();i++){
        cout<<selection[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
