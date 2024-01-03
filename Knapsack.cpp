#include<bits/stdc++.h>
#define vp vector<pair<int,int>>
#define pro first
#define wit second

using namespace std;

bool compar(pair<int,int>p1,pair<int,int>p2){
    return (p1.pro/p1.wit) > (p2.pro/p2.wit);
}
int main(){
    int n=5;
    vp vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].pro;
        cin>>vec[i].wit;
    }

    sort(vec.begin(),vec.end(),compar);

    cout<<"ITEM"<<"|";
    for(int i=0;i<n;i++){
        cout<<i+1<<" ";
    }
    cout<<"\n";

    cout<<"PROFIT"<<"|";
    for(int i=0;i<n;i++){
        cout<<vec[i].pro<<" ";
    }
    cout<<"\n";

    cout<<"WEIGHT"<<"|";
    for(int i=0;i<n;i++){
        cout<<vec[i].wit<<" ";
    }
    cout<<"\n";
     vector<double>finish(n,0);
    int w=20;
    int ans=0;
    for(int i=0;i<n;i++){
        if(w>=vec[i].wit){
            finish[i]=1;
            ans += vec[i].pro;
            w -=vec[i].wit;
            continue;
        }
        finish[i]=w/(double)vec[i].wit;
        ans+=w*(vec[i].pro/vec[i].wit);
        w=0;
        break;
    }
    

    cout<<"\n";
    cout<<"Total profit is "<<ans<<endl;

    cout<<"Main path is "<<endl;
    for(int i=0;i<n;i++){
        cout<<finish[i]<<" |";
    }
    return 0;
}