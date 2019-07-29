#include<bits/stdc++.h>
#define FIN freopen("./1006.in","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e5+5);
const double pi=acos(-1);
ll T;
__int128 ans,p,q;
void _print(__int128 x)
{
    if(x > 9) _print(x/10);
    putchar(x%10 + '0');
}
void scan(__int128 &x)//输入
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}
void print(__int128 x)  
{  
	if(x<0){
		x=-x;
		putchar('-');
	}
    if(!x)  
    {  
        puts("0");  
        return ;  
    }  
    string ret="";  
    while(x)  
    {  
        ret+=x%10+'0';  
        x/=10;  
    }  
    reverse(ret.begin(),ret.end());  
    cout<<ret<<endl;  
} 
//ll igcdex(ll a,ll b){
//	ll x_sign,y_sign,x=1,y=0,r=0,s=1,c,q;
//	if(a==0&&b==0){
//		return 0;
//	}
//	if(a==0){
//		return 0;
//	}
//	if(b==0){
//		return a/abs(a);
//	}
//	if(a<0){
//		a=-a,x_sign=-1;
//	}else{
//		x_sign=1;
//	}
//	if(b<0){
//		b=-b,y_sign=-1;
//	}else{
//		y_sign=1;
//	}
//	while(b){
//		c=a%b,q=a/b;
//		a=b,b=c,r=x-q*r,s=y-q*s,x=r,y=s;
//	}
//	return x*x_sign;
//}
ll exgcd(__int128 a,__int128 b,__int128 &x,__int128 &y){
	if(!b){
		y=0;x=1;return a;
	}
	ll d=exgcd(b,a%b,y,x);y-=a/b*x;return d;
}
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>T;
	getchar();
	while(T--){
		scan(q);
		for(ll i=q-2;i>=2;i-=2){
			ll flag=1;
			for(ll j=2;j<sqrt(i)+1;j++){
				if(i%j==0){
					flag=0;
					break;
				}
			}
			if(flag){
				p=i;
				break;
			}
		}
		ans=q-1;
		for(ll i=p+1;i<q;i++){
			__int128 x,y;
			exgcd(i,q,x,y);
			ans=(ans*(x%q+q))%q;
			//ans=(ans*igcdex(i,q))%q;
		}
		print(ans);
	}
}
/*
#include <bits/stdc++.h>
using namespace std;

void scan(__int128 &x)//输入
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}
void _print(__int128 x)
{
    if(x > 9) _print(x/10);
    putchar(x%10 + '0');
}
void print(__int128 x)//输出
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    _print(x);
}

int main()
{
    __int128 a, b;
    scan(a); scan(b);
    print(a + b);
    return 0;
}
*/
