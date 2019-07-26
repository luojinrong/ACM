#include<bits/stdc++.h>
#define FIN freopen("./data/1013/02","r",stdin)
#define debug(x) cout<<#x"=["<<x<<"]"<<endl
using namespace std;
typedef long long ll;
const ll maxn(1e2+5);
const double pi=acos(-1);
ll T,n,n1,n2,top1,top2;
struct node{
	double x,y;
}a1[maxn],p1[maxn],a2[maxn],p2[maxn];
double cross(struct node p0,struct node p1,struct node p2){//计算叉乘，注意p0,p1,p2的位置，这个决定了方向
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}

double dis(struct node a,struct node b){//计算距离，这个用在了当两个点在一条直线上
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int cmp1(const void* p1,const void* p2){//极角排序
    double z=cross(a1[0],*((struct node*)p1),*((struct node*)p2));
    if(z>0||(z==0&&dis(a1[0],*((struct node*)p1))<dis(a1[0],*((struct node*)p2)))){
        return -1;
	}
    return 1;
}

int cmp2(const void* p1,const void* p2){//极角排序
    double z=cross(a2[0],*((struct node*)p1),*((struct node*)p2));
    if(z>0||(z==0&&dis(a2[0],*((struct node*)p1))<dis(a2[0],*((struct node*)p2)))){
        return -1;
	}
    return 1;
}

void swap_node(struct node*a,struct node*b){
	struct node tmp=*a;
	*a=*b;
	*b=tmp;
}
void Graham1(){
	if(n1==0){
		return;
	}
    ll k=0;
    for(ll i=0; i<n1; i++){
        if(a1[i].y<a1[k].y||(a1[i].y==a1[k].y&&a1[i].x<a1[k].x)){
            k=i;
		}
	}
    swap_node(&a1[0],&a1[k]);//找p[0]
    qsort(a1+1,n1-1,sizeof(struct node),cmp1);
    top1=1;
    p1[0]=a1[0];
    p1[1]=a1[1];
    for(ll i=2; i<n1; i++){//控制进栈出栈
        while(cross(p1[top1-1],p1[top1],a1[i])<0&&top1){
            top1--;
		}
        top1++;
        p1[top1]=a1[i];
    }
}

void Graham2(){
	if(n2==0){
		return;
	}
    ll k=0;
    for(ll i=0; i<n2; i++){
        if(a2[i].y<a2[k].y||(a2[i].y==a2[k].y&&a2[i].x<a2[k].x)){
            k=i;
		}
	}
    swap_node(&a2[0],&a2[k]);//找p[0]
    qsort(a2+1,n2-1,sizeof(struct node),cmp2);
    top2=1;
    p2[0]=a2[0];
    p2[1]=a2[1];
    for(ll i=2; i<n2; i++){//控制进栈出栈
        while(cross(p2[top2-1],p2[top2],a2[i])<0&&top2){
            top2--;
		}
        top2++;
        p2[top2]=a2[i];
    }
}

bool judge(node a,node b,node c,node d) {//线段相交
	//快速排斥
	if(min(a.y,b.y)>max(c.y,d.y)|| max(a.x,b.x)<min(c.x,d.x) || min(c.y,d.y)>max(a.y,b.y) || max(c.x,d.x)<min(a.x,b.x))
		return false;
	//跨立实验
	double u = (a.x-c.x)*(d.y-c.y)-(a.y-c.y)*(d.x-c.x);
	double v = (b.x-c.x)*(d.y-c.y)-(d.x-c.x)*(b.y-c.y);
	double w = (c.x-b.x)*(a.y-b.y)-(a.x-b.x)*(c.y-b.y);
	double z = (d.x-b.x)*(a.y-b.y)-(a.x-b.x)*(d.y-b.y);
	if(u*v<=0.0000001 && w*z<=0.0000001)
		return true;
	return false;
}

bool check(){
	if(n1==0||n2==0){
		return true;
	}
	if(n1==1){
		top1=0;
	}
	if(n2==1){
		top2=0;
	}
	bool flag=true;
	for(ll i=0;i<=top1;i++){
		for(ll j=0;j<=top2;j++){
			if(judge(p1[(i)%(top1+1)],p1[(i+1)%(top1+1)],p2[(j)%(top2+1)],p2[(j+1)%(top2+1)])){
				flag=false;
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	if(flag){
		flag=false;
        if(a1[0].y<a2[0].y||(a1[0].y==a2[0].y&&a1[0].x<a2[0].x)){
			for(ll i=0;i<n1;i++){
				a2[n2].x=a1[i].x;
				a2[n2].y=a1[i].y;
				n2++;
			}
			Graham2();
			if(top1==top2){
				for(ll i=0;i<=top1;i++){
					if(p1[i].x!=p2[i].x||p1[i].y!=p2[i].y){
						flag=true;
					}
				}
			}else{
				flag=true;
			}
		}else{
			for(ll i=0;i<n2;i++){
				a1[n1].x=a2[i].x;
				a1[n1].y=a2[i].y;
				n1++;
			}
			Graham1();
			if(top1==top2){
				for(ll i=0;i<=top1;i++){
					if(p1[i].x!=p2[i].x||p1[i].y!=p2[i].y){
						flag=true;
					}
				}
			}else{
				flag=true;
			}
		}
	}
	return flag;
}

int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		n1=n2=0;
		cin>>n;
		ll t_x,t_y,num;
		for(ll i=1;i<=n;i++){
			cin>>t_x>>t_y>>num;
			if(num==1){
				a1[n1].x=t_x;
				a1[n1].y=t_y;
				n1++;
			}else{
				a2[n2].x=t_x;
				a2[n2].y=t_y;
				n2++;
			}
		}
		Graham1();
		Graham2();
		if(check()){
			cout<<"Successful!"<<endl;
		}else{
			cout<<"Infinite loop!"<<endl;
		}
	}
}
