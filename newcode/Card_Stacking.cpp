#include<bits/stdc++.h>
using namespace std;
const int maxn(1e5+5);
int n,k,p,ans[maxn],sum,card[maxn],all;
int main(){
    cin>>n>>k>>p;
    all=k;
    while(all){
        for(int i=0;i<k;i++){
            if(!card[i]){
                sum++;
                if((sum-1)%(p+1)==0){
                    card[i]=1;
                    all--;
					if((k-all)%n==0){
	               	    ans[i]=1;
	               	}
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        if(ans[i]){
            cout<<i+1<<endl;
        }
    }
}
