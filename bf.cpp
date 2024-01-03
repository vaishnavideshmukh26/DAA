#include<iostream>
#include<vector>
using namespace std;
struct graph
{
    int u;
    int v;
    int d;
};

void bf(int v,int e,graph g[],vector<int>&disk){
    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
            if(disk[g[j].u]!=INT_MAX && (disk[g[j].v] > disk[g[j].u] + g[j].d)){
                      disk[g[j].v] = disk[g[j].u] + g[j].d;
            }
        }
    }

    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
            if(disk[g[j].u]!=INT_MAX && (disk[g[j].v] > disk[g[j].u] + g[j].d)){
                      cout<<"this negative cycla";
                      break;;
            }
        }
    }

}
int main(){
    int v,e;
    cin>>v;
    cin>>e;

    graph g[e];
    for(int i=0;i<e;i++){
        cin>>g[i].u>>g[i].v>>g[i].d;
    }
     
    vector<int>disk(v,INT_MAX);
     disk[0]=0;
    bf(v,e,g,disk);
    
    cout<<"shortest distance is "<<endl;
    for(int i=0;i<v;i++){
        cout<<disk[i]<<" ";
    }

}