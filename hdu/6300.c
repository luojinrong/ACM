//!不存在三点共线
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
struct node{
    int x,y,pos;
} a[3005];
int n;

int comp(const void*a,const void*b){
	return ((struct node*)a)->x-((struct node*)b)->x;
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		for(int i=0;i<3*n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].pos=i+1;
		}
		qsort(a,3*n,sizeof(struct node),comp);
		for(int i=0;i<3*n;i+=3){
			printf("%d %d %d\n",a[i].pos,a[i+1].pos,a[i+2].pos);
		}
	}
    return 0;
}
