#include<stdio.h> 

int main() 
{
	int x,d,h,a,p,t,b,w=0,c,e; 
	scanf("%d,%d,%d",&x,&d,&h); 
  	a=x; 
  	b=d; 
  	for(p=2;p<=h;p++) 
  	{    
		x=a*p-b; 
  	        d=b*p; 
  	        c=x;e=d; 
  	        if(x>0) 
  	        { 
			for(t=p+1;t<=h;t++) 
			{ 
				x=c*t-e;d=e*t; 
				if((x>0)&&(x==1||d%x==0)&&((d/x)<=h)&&((d/x)>t)) 
				{ 
					w=w+1; 
					printf("%d/%d=1/%d+1/%d+1/%d\n",a,b,p,t,d/x); 
				} 
			} 
		} 
	} 
	if(w==0) printf("无分解式"); 
	return 0; 
}  
