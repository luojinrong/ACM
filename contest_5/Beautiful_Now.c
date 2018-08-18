#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)
int k,len,inde[10];
char n[10],n_max[10],n_min[10];

struct front{
	int index;
	char num;
}f[10];

int cmp2(const void*a,const void*b){//升序
	return (((struct front*)a)->num-((struct front*)b)->num);
}

int cmp1(const void*a,const void*b){//降序
	return (((struct front*)b)->num-((struct front*)a)->num);
}

void swap(char *a,char *b){
	char tmp=*a;
	*a=*b;
	*b=tmp;
}

void find_max(){
	int k_left=k;
	for(int i=9;i>=0;i--){
		int find=-1,fr=-1;
		for(int j=len-1;j>=0;j--){
			if(n_max[j]==(i+'0')){
				inde[++find]=j;
				if(fr==-1){
					for(int z=0;z<len;z++){
						if(n_max[z]<(i+'0')){
							f[++fr].index=z;
							f[fr].num=n_max[z];
							break;
						}
					}
				}
				else{
					for(int z=f[fr].index+1;z<len;z++){
						if(n_max[z]<(i+'0')){
							f[++fr].index=z;
							f[fr].num=n_max[z];
							break;
						}
					}
				}
				if(find>fr||f[fr].index>inde[find]){
					find--;
					break;
				}
				if(k_left==(find+1)){
					break;
				}
			}
		}
		if(find>0){
			qsort(f,find+1,sizeof(struct front),cmp2);
		}
		for(int j=0;j<(find+1)&&k_left>0;j++,k_left--){
			swap(&n_max[inde[j]],&n_max[f[j].index]);	
		}
		if(k_left==0){
			break;
		}
	}
	printf("%s\n",n_max);
}

void find_min(){
	int k_left=k,fir=-1,zero=0;
	char fir_=0;
	for(int i=0;i<len;i++){
		if(n_min[i]=='0'){
			zero++;
		}
	}
	if(zero+1>=k_left){
		for(int i=len-1;i>0;i--){
			if(n_min[i]<n_min[0]&&(fir==-1||n_min[i]<fir_)&&n_min[i]!='0'){
				fir=i;
				fir_=n_min[i];
			}
		}
		if(fir!=-1){
			swap(&n_min[0],&n_min[fir]);
			k_left--;
		}
	}
	if(k_left){//0
		int find=-1,fr=-1;
		for(int i=len-1;i>=0;i--){
			if(n_min[i]=='0'){
				inde[++find]=i;
				if(fr==-1){
					for(int j=1;j<len;j++){
						if(n_min[j]>'0'){
							f[++fr].index=j;
							f[fr].num=n_min[j];
							break;
						}
					}
				}
				else{
					for(int j=f[fr].index+1;j<len;j++){
						if(n_min[j]>'0'){
							f[++fr].index=j;
							f[fr].num=n_min[j];
							break;
						}
					}
				}
				if(find>fr||f[fr].index>inde[find]){
					find--;
					break;
				}
				if(k_left==(find+1)){
					break;
				}
			}
		}
		if(find>0){
			qsort(f,find+1,sizeof(struct front),cmp1);
		}
		for(int i=0;i<(find+1)&&k_left>0;i++,k_left--){
			swap(&n_min[inde[i]],&n_min[f[i].index]);
		}
	}
	if(k_left){
		for(int i=1;i<=9;i++){
			int find=-1,fr=-1;
			for(int j=len-1;j>=0;j--){
				if(n_min[j]==(i+'0')){
					inde[++find]=j;
					if(fr==-1){
						for(int z=0;z<len;z++){
							if(n_min[z]>(i+'0')){
								f[++fr].index=z;
								f[fr].num=n_min[z];
								break;
							}
						}
					}
					else{
						for(int z=f[fr].index+1;z<len;z++){
							if(n_min[z]>(i+'0')){
								f[++fr].index=z;
								f[fr].num=n_min[z];
								break;
							}
						}
					}
					if(find>fr||f[fr].index>inde[find]){
						find--;
						break;
					}
					if(k_left==(find+1)){
						break;
					}
				}
			}
			if(find>0){
				qsort(f,find+1,sizeof(struct front),cmp1);
			}
			for(int j=0;j<(find+1)&&k_left>0;j++,k_left--){
				swap(&n_min[inde[j]],&n_min[f[j].index]);
			}
			if(k_left==0){
				break;
			}
		}
	}
	printf("%s ",n_min);
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%s%d",n,&k);
		len=strlen(n);
		strcpy(n_max,n);
		strcpy(n_min,n);
		find_min();
		find_max();
	}
}
