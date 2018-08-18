#include<stdio.h>
long long a[100005],c[100005],ans;
int n,x,y;
void msort(int l,int r){
	int mid=(l+r)>>1,i=l,j=mid+1,k=l;
	if(l==r){
		return;
	}
	msort(l,mid);
	msort(mid+1,r);
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){//  =
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
	while(scanf("%d%d%d",&n,&x,&y)!=EOF){
		int i;
		ans=0;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		msort(0,n-1);
		/*for(i=0;i<n;i++){
			printf("%d ",a[i]);
		}*/
		printf("%lld\n",(x>y?ans*y:ans*x));
	}
}
