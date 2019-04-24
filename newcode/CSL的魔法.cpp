#include<iostream>

using namespace std;

const int maxn=100005;
typedef long long ll;
ll t_a[maxn],t_b[maxn];
ll n,a[maxn],c[maxn],ans,min_ans;

void msort_greater(int l,int r){//逆序对
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	msort_greater(l,mid);
	msort_greater(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			c[k++]=a[j++];
		}
		else{
			c[k++]=a[j++];
			ans+=(mid-i+1);
		}
	}
	while(j<=mid){
		c[k++]=a[i++];
	}
	while(j<=r){
		c[k++]=a[j++];
	}
	for(i=l;i<=r;i++){
		a[i]=c[i];
	}
}

void msort_less(int l,int r){//顺序
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	msort_less(l,mid);
	msort_less(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]>=a[j]){
			c[k++]=a[j++];
		}
		else{
			c[k++]=a[j++];
			ans+=(mid-i+1);
		}
	}
	while(j<=mid){
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
	int n;
	while(cin>>n){
		ans=0;
		for(int i=0;i<n;i++){
			cin>>t_a[i];
			a[i]=t_a[i];
		}
		for(int i=0;i<n;i++){
			cin>>t_b[i];
		}
		msort_greater(0,n-1);
		for(int i=0;i<n;i++){
			a[i]=t_b[n-i-1];
		}
		msort_greater(0,n-1);
		min_ans=ans;
		ans=0;
		for(int i=0;i<n;i++){
			a[i]=t_a[n-i-1];
		}
		msort_greater(0,n-1);
		for(int i=0;i<n;i++){
			a[i]=t_b[i];
		}
		msort_greater(0,n-1);
		if(ans<min_ans){
			min_ans=ans;
		}
		cout<<min_ans<<endl;
	}	
}
