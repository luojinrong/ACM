#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
struct node
{
    int x,y;
} a[105],p[105];
int top,n;
double cross(struct node p0,struct node p1,struct node p2)//计算叉乘，注意p0,p1,p2的位置，这个决定了方向
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dis(struct node a,struct node b)//计算距离，这个用在了当两个点在一条直线上
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp(const void* p1,const void* p2)//极角排序
{
    double z=cross(a[0],*((struct node*)p1),*((struct node*)p2));
    if(z>0||(z==0&&dis(a[0],*((struct node*)p1))<dis(a[0],*((struct node*)p2))))
        return -1;
    return 1;
}
void swap_node(struct node*a,struct node*b){
	struct node tmp=*a;
	*a=*b;
	*b=tmp;
}
void Graham()
{
    int k=0;
    for(int i=0; i<n; i++){
        if(a[i].y<a[k].y||(a[i].y==a[k].y&&a[i].x<a[k].x)){
            k=i;
		}
	}
    swap_node(&a[0],&a[k]);//找p[0]
    qsort(a+1,n-1,sizeof(struct node),cmp);
    top=1;
    p[0]=a[0];
    p[1]=a[1];
    for(int i=2; i<n; i++)//控制进栈出栈
    {
        while(cross(p[top-1],p[top],a[i])<0&&top)
            top--;
        top++;
        p[top]=a[i];
    }
}
int main()
{
        while(scanf("%d",&n),n){
            for(int i=0; i<n; i++)
            {
                scanf("%d%d",&a[i].x,&a[i].y);
            }
            Graham();
			if(n==1){
				printf("0.00\n");
			}
			else if(n==2){
				printf("%.2f\n",dis(p[0],p[1]));
			}
			else{
				double len=0;
				len+=dis(p[top],p[0]);
				for(int i=1;i<=top;i++){
					len+=dis(p[i-1],p[i]);
				}
				printf("%.2f\n",len);
			}
		}
    return 0;
}
