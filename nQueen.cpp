#include<bits/stdc++.h>
using namespace std;
bool isplace(int q,int c,int col[]){
    int j=0;
    while(j<=q){
        if(col[j]==c || abs(col[j]-c)==abs(j-q)){
            return false;
        }
        j++;
    }
    return true;
}
void print(int n,int col[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(col[i]==j){
                cout<<i+1<<" ";
            }
            else{
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
bool nqueen(int q,int n,int col[]){
 int fl=0;
 for(int i=0;i<n;i++){
    if(isplace(q,i,col)){
        col[q]=i;
        cout<<"placed qeen is "<<q+1<<endl;
        print(n,col);
        if(q==n-1){
            return true;
        }
        if(nqueen(q+1,n,col)){
            return true;
        }
        col[q]=-1;
        cout<<"backtracing "<<q+1<<endl;
        print(n,col);
        fl=1;

    }
 }
 if(!fl){
    cout<<"unable to place "<<q+1<<endl;
 }
 return false;
}
int main(){
    int n;
    cin>>n;
    if(n<=3){
        cout<<"n should be greater";
        return 0;
    }

    int col[n];
    for(int i=0;i<n;i++){
        col[i]=-1;
    }
    nqueen(0,n,col);
    return 0;

}