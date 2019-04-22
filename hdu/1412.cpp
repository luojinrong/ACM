//#include<bits/stdc++.h>
//#define maxn 20005
//using namespace std;
//
//int m,n,arr[maxn];
//
//int main(){
//	while(cin>>m>>n){
//		for(int i=0;i<n+m;i++){
//			cin>>arr[i];
//		}
//		sort(arr,arr+m+n);
//		cout<<arr[0];
//		for(int i=1;i<n+m;i++){
//			if(arr[i]!=arr[i-1]){
//				cout<<" "<<arr[i];
//			}
//		}
//		cout<<endl;
//	}
//}


 #include <stdio.h>

int main()
{
	int m, n, i, t, s[20002], j, a, b;
	while (scanf("%d%d", &m, &n) != -1)
	{
		for (i = 0;i < m + n;i++)
		{
			scanf("%d", &s[i]);
		}
		for (i = 0;i < m + n;i++)
		{
			for (j = i,t=s[i],a=0;j < m + n;j++)
			{
				if (t >= s[j])
				{
					t = s[j];
					a = j;
				}

			}
			b = s[i];
			s[i] = t;
			s[a] = b;
		}
		
		for (i = 0;i < m + n - 1;i++)
		{
			if (i == 0)
				printf("%d", s[i]);
			else
				if (s[i] == s[i - 1])
				{
					continue;
				}
				else
					printf(" %d", s[i]);
		}
		if(s[n+m-1]!=s[n+m-2])
		printf(" %d", s[n + m - 1]);
		printf("\n");
	}
	return 0;
}
