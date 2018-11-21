#include<stdio.h>

char month[13][20]={"","January","February","March","April","May","June","July","August","September","October","November","December"};

int main(){
	int n;
	scanf("%d",&n);
	printf("%s\n",month[n]);
}