#include <stdio.h>
int a,b,c,hang;

int max(int a,int b){
	return (a>b?b:a);
}

int main(){
	int T;
	for(scanf("%d",&T);T;T--){
		scanf("%d%d%d",&a,&b,&c);
		hang=(b+c)*2+1;
		for(int i=0;i<hang;i++){
			for(int j=0;j<2*b-i;j++){
				printf(".");
			}
			if(!(i%2)){
				for(int j=0;j<a;j++){
					printf("+-");
				}
				if(i/2<max(b,c)){
					for(int j=0;j<i/2;j++){
						printf("+.");
					}
				}
				else if((hang-i)/2<max(b,c)){
					for(int j=0;j<(hang-i)/2;j++){
						printf("+.");
					}
				}
				else{
					for(int j=0;j<max(b,c);j++){
						printf("+.");
					}
				}
				printf("+");
			}
			else{
				if(i/2<b){
					for(int j=0;j<a;j++){
						printf("/.");
					}
				}
				else{
					for(int j=0;j<a;j++){
						printf("|.");
					}
					printf("|");
				}
				if((i+1)/2<=max(b,c)){
					for(int j=0;j<(i+1)/2;j++){
						printf("/|");
					}
				}
				else if((hang-i)/2-1<max(b,c)){
					for(int j=0;j<(hang-i)/2-1;j++){
						printf("/|");
					}
					printf("/");
				}
				else{
					for(int j=0;j<max(b,c);j++){
						printf("/|");
					}
					if(i<b*2){
						printf("/");
					}
				}
			}
			if(hang-i<=2*b){
				for(int j=0;j<(2*b)-(hang-i-1);j++){
					printf(".");
				}
			}
			printf("\n");
		}
//		for(int i=0;i<2*b;i++){
//			for(int j=0;j<2*b-i;j++){
//				printf(".");
//			}
//			if(!(i%2)){
//				for(int j=0;j<a;j++){
//					printf("+-");
//				}
//				printf("+");
//				for(int j=0;j<i/2;j++){
//					printf(".+");
//				}
//			}
//			else{
//				for(int j=0;j<a;j++){
//					printf("/.");
//				}
//				for(int j=0;j<i/2+1;j++){
//					printf("/|");
//				}
//			}
//			printf("\n");
//		}
//		for(int i=0;i<(c-b)*2;i++){
//			if(!(i%2)){
//				for(int j=0;j<a;j++){
//					printf("+-");
//				}
//				printf("+");
//				for(int j=0;j<b;j++){
//					printf(".+");
//				}
//			}
//			else{
//				for(int j=0;j<a;j++){
//					printf("|.");
//				}
//				printf("|");
//				for(int j=0;j<b;j++){
//					printf("/|");
//				}
//			}
//			printf("\n");
//		}
//		for(int i=0;i<2*b;i++){
//			if(!(i%2)){
//				for(int j=0;j<a;j++){
//					printf("+-");
//				}
//				printf("+");
//				for(int j=0;j<(2*b-i)/2;j++){
//					printf(".+");
//				}
//				for(int j=(2*b-i)/2;j<b;j++){
//					printf("..");
//				}
//			}
//			else{
//				for(int j=0;j<a;j++){
//					printf("|.");
//				}
//				for(int j=0;j<(2*b-i)/2+1;j++){
//					printf("|/");
//				}
//				for(int j=(2*b-i)/2+1;j<b;j++){
//					printf("..");
//				}
//				printf(".");
//			}
//			printf("\n");
//		}
//		for(int i=0;i<a;i++){
//			printf("+-");
//		}
//		printf("+");
//		for(int i=0;i<b;i++){
//			printf("..");
//		}
//		printf("\n");
	}
}
