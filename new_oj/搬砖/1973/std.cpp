#include "stdio.h"  

int main()  
{ 
	int num1,num2,num3,num4,num5,num6,sum,x,y,y1,m,z,t;  
	while (scanf("%d %d %d %d %d %d",&num1,&num2,&num3,&num4,&num5,&num6)&&(num1+num2+num3+num4+num5+num6!=0))
	{
		sum=num1+4*num2+9*num3+16*num4+25*num5+36*num6;  
		m=num5+num6+num4+num3/4;  
		y=num3%4;  
		switch (y) 
		{ 
			case 0 :y1=0; 
				z=5*(num4+y)-num2;  
				break; 
			default:y1=1; 
		}  
		if(z>0) 
		{    
			m=m+y1;  
		}       
		else
			m=m+y1+z/10;  
		t=num1-36*m+sum;  
		if(t>0)  
		{ 
			m=m+t/37;  
		} 
		else
			m=m;  
		printf("%d\n",m);  	
	}	
}  
