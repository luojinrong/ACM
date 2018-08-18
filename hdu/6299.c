//qsort比较函数:0,-1交换，1不交换
//比较思路:左括号比右括号多在左，否则在右；若左括号均比右括号多，右括号少的在左；若左括号均比右括号少，左括号少的在右
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct kh{
    int l,r,contribution;
}p[100005];
int m,n=0,T,pos=0;
int comp(const void*a,const void*b){
    if (((struct kh*)a)->contribution > 0 && ((struct kh*)b)->contribution > 0) {
        return ((struct kh*)a)->r - ((struct kh*)b)->r;
    }
    else if (((struct kh*)a)->contribution > 0) {
        return -1;
    }
    else if (((struct kh*)b)->contribution > 0) {
        return 1;
    }
    else {
        return ((struct kh*)b)->l - ((struct kh*)a)->l;
    }
}
void patt1(char *s,int len){
    char stack[100005];
    int st_top=0,l=0,r=0;
    stack[0]=s[0];
	s[0]=='('?l++:r++;
    for(int i=1;i<len;i++){
        if(s[i]==')'&&stack[st_top]=='('){
            st_top--;
            l--;
            n++;
        }
        else{
            stack[++st_top]=s[i];
			s[i]=='('?l++:r++;
        }
    }
	p[pos].l=l;
	p[pos].r=r;
	p[pos++].contribution=l-r;
}
void patt2(int pos){
    if(p[0].l==p[pos].r){
        p[0].l=p[pos].l;
        n+=p[pos].r;
    }
    else if (p[0].l>p[pos].r){
        p[0].l=p[0].l-p[pos].r+p[pos].l;
        n+=p[pos].r;
    }    
    else{
        n+=p[0].l;
        p[0].r+=p[pos].r-p[0].l;
        p[0].l=p[pos].l;
    }
}

int main(){
    for(scanf("%d",&T);T;T--){
        n=pos=0;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            char str[100005];
            scanf("%s",str);
            patt1(str,strlen(str));
        }
        qsort(p,pos,sizeof(struct kh),comp);
        for(int i=1;i<pos;i++){
            patt2(i);
        }
        printf("%d\n",n*2);
    }
}
