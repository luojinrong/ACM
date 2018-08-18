#include <stdio.h>
typedef long long ll;
int x,y,n;
ll ans;
ll a[100005],c[100005];

void msort(int l,int r){
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	msort(l,mid);
	msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			c[k++]=a[i++];
		}
		else{
			c[k++]=a[j++];
			ans+=(mid-i+1);
		}
	}
	while(i<=mid){
		c[k++]=a[i++];
	}
	while(j<=r){
		c[k++]=a[j++];
	}
	for(i=l;i<=r;i++){
		a[i]=c[i];
	}
}

int main(){
	while(~scanf("%d%d%d",&n,&x,&y)){
		ans=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		msort(0,n-1);
		printf("%lld\n",x>y?ans*y:ans*x);
	}
}
