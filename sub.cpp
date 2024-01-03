#include<bits/stdc++.h>
using namespace std;
bool flag=false;
void sub(int i,int n,int set[],int targetsum,vector<int>&sector){

    
    if(targetsum==0){
        flag=true;
        cout<<"[";
        for(int i=0;i<sector.size();i++){
            cout<<sector[i]<<" ";

        }
        cout<<"]"<<endl;
        return;
    }
      
    if(i==n){return;}
    sub(i+1,n,set,targetsum,sector);
    
    if(set[i]<=targetsum){
        sector.push_back(set[i]);
        sub(i+1,n,set,targetsum-set[i],sector);
        sector.pop_back();
    }
}

int main(){
    int n;
    cout << "Enter the number of elements in the set: ";
    cin>>n;
    int set[n];
     cout << "Enter the elements of the set: ";
    for(int i=0;i<n;i++){
        cin>>set[i];
    }
    int sum;
     cout << "Enter the target sum: ";
    cin>>sum;
    vector<int>sector;
    sub(0,n,set,sum,sector);
     if (!flag)

{ cout << "There is no such subset" << endl;

}
    return 0;
}