#include <stdio.h> 
#include <string.h> 



int main() 
{ 
	char a[100];
	int i;	
	while (scanf("%s",a)!=EOF) 
	{ 
		int len=strlen(a);
		for (i=0;i<len;i++) 
		{ 
			if (a[i]=='M') 
			{ 
				printf("Monday\n"); 
				continue; 
			} 
			else if (a[i]=='T') 
			{ 
				if (a[i+1]=='u') 
				{ 
					printf("Tuesday\n"); 
					i++; 
					continue; 
				} 
				else if (a[i+1]=='h') 
				{ 
					printf("Thursday\n"); 
					i++; 
					continue; 
				} 
				else
				{ 
					printf("Wrong data\n"); 
					continue; 
				} 
			} 
			else if (a[i]=='W') 
			{ 
				printf("Wednesday\n"); 
				continue; 
			} 
			else if (a[i]=='F') 
			{ 
				printf("Friday\n"); 
				continue; 
			} 
			else if (a[i]=='S') 
			{ 
				if (a[i+1]=='a') 
				{ 
					printf("Saturday\n"); 
					i++; 
					continue; 
				} 
				else if (a[i+1]=='u') 
				{ 
					printf("Sunday\n"); 
					i++; 
					continue; 
				} 
				else
				{ 
					printf("Wrong data\n"); 
					continue; 
				} 
  
			} 
			else if (a[i]=='Y') 
				break; 
			else
			{ 
				printf("Wrong data\n"); 
				continue; 
			} 
		} 
	} 
	return 0; 
}
