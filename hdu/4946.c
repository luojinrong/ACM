#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    int x,y,v,pos,val;
} a[505],p[505],in[505];
int top,n=0,cas=0,num;
double cross(node p0,node p1,node p2)//计算叉乘，注意p0,p1,p2的位置，这个决定了方向
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dis(node a,node b)//计算距离，这个用在了当两个点在一条直线上
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(node p1,node p2)//极角排序
{
    double z=cross(a[0],p1,p2);
    if(z>0||(z==0&&dis(a[0],p1)<dis(a[0],p2)))
        return 1;
    return 0;
}
void Graham()
{
    int k=0;
    for(int i=0; i<n; i++)
        if(a[i].y<a[k].y||(a[i].y==a[k].y&&a[i].x<a[k].x))
            k=i;
        swap(a[0],a[k]);//找p[0]
        sort(a+1,a+n,cmp);
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
    while(scanf("%d",&num),num)
    {
		int max=0;
		cas++;
        for(int i=0; i<num; i++)
        {
			in[i].pos=i;
			in[i].val=0;
            scanf("%d%d%d",&in[i].x,&in[i].y,&in[i].v);
			if(in[i].v>max)
			{
				max=in[i].v;
			}
        }
		for(int i=0;i<num;i++)
		{
			if(in[i].v==max)
			{
				p[n++]=in[i];
			}
		}
        Graham();
        for(int i=0; i<=top; i++)
        {
           in[p[i].pos].val=1; 
        }
		printf("Case #%d: ",cas);
		for(int i=0;i<num;i++)
		{
			printf("%d",in[i].val);
		}
		printf("\n");
    }
    return 0;
}
