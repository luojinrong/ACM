#include<bits/stdc++.h>
using namespace std;
const int maxn(5e5+5);
int n,l,r;
char s[maxn];
string ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    l=0,r=n-1;
    while(l<=r){
        if(l==r){
            ans+=s[l];
            break;
        }
        if(s[l]>s[r]){
            ans+=s[r];
            r--;
        }else if(s[l]<s[r]){
            ans+=s[l];
            l++;
        }else{
            int i=l,j=r;
            while(s[i]==s[j]&&i<=j){
                i++,j--;
            }
            if(i>j){
                ans+=s[l];
                l++;
            }else{
                if(s[i]>s[j]){
                    ans+=s[r];
                    r--;
                }else{
                    ans+=s[l];
                    l++;
                }
            }
        }
    }
    for(int i=0;;i+=80){
        if(i+80<n){
            cout<<ans.substr(i,80)<<endl;
        }else{
            cout<<ans.substr(i)<<endl;
            break;
        }
    }
}
