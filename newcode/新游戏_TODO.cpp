#include<bits/stdc++.h>
using namespace std;
const int maxn(255);
set<int> v;
map<int,int> mp;
map<int,int>::iterator mit;
set<int>::iterator vi,vj;
int n,vis[maxn][maxn],mapp[maxn][maxn],visited,num,max_one,max_two;
void dfs_one(int x,int y){
    num++;
    vis[x][y]=1;
    visited++;
    if(!vis[x+1][y]&&mapp[x+1][y]==mapp[x][y]){
        dfs_one(x+1,y);
    }
    if(!vis[x-1][y]&&mapp[x-1][y]==mapp[x][y]){
        dfs_one(x-1,y);
    }
    if(!vis[x][y+1]&&mapp[x][y+1]==mapp[x][y]){
        dfs_one(x,y+1);
    }
    if(!vis[x][y-1]&&mapp[x][y-1]==mapp[x][y]){
        dfs_one(x,y-1);
    }
}
void dfs_two(int x,int y,int i,int j){
    num++;
    vis[x][y]=1;
    if(!vis[x+1][y]&&(mapp[x+1][y]==i||mapp[x+1][y]==j)){
        dfs_two(x+1,y,i,j);
    }
    if(!vis[x-1][y]&&(mapp[x-1][y]==i||mapp[x-1][y]==j)){
        dfs_two(x-1,y,i,j);
    }
    if(!vis[x][y+1]&&(mapp[x][y+1]==i||mapp[x][y+1]==j)){
        dfs_two(x,y+1,i,j);
    }
    if(!vis[x][y-1]&&(mapp[x][y-1]==i||mapp[x][y-1]==j)){
        dfs_two(x,y-1,i,j);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            mapp[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mapp[i][j];
            v.insert(mapp[i][j]);
            mit=mp.find(mapp[i][j]);
            if(mit!=mp.end()){
                mp[mapp[i][j]]++;
            }else{
                mp[mapp[i][j]]=1;
            }
        }
    }
    while(visited<n*n){
        for(int i=1;i<=n;i++){
            int flag=0;
            for(int j=1;j<=n;j++){
                if(!vis[i][j]){
                    flag=1;
                    num=0;
                    dfs_one(i,j);
                    if(num>max_one){
                        max_one=num;
                    }
                    break;
                }
            }
            if(flag){
                break;
            }
        }
    }
    for(vi=v.begin();vi!=v.end();vi++){
        for(vj=v.begin();vj!=v.end();vj++){
            if((*vi)!=(*vj)&&((mp[*vi]+mp[*vj])>max_one&&(mp[*vi]+mp[*vj])>max_two)){
                memset(vis,0,sizeof(vis));
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(!vis[i][j]&&(mapp[i][j]==*vi||mapp[i][j]==*vj)){
                            num=0;
                            dfs_two(i,j,*vi,*vj);
                            if(num>max_two){
                                max_two=num;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<max_one<<endl<<max_two<<endl;
}
