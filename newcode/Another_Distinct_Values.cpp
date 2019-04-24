/* 上三角全是1 下三角全是-1 对角线01平分
 * 当n==2时
 * 1 0
 * 1 -1
 * 当n==4时
 * 1 1 1 0
 * 1 1 0 -1
 * 1 1 -1 -1
 * 1 -1 -1 -1
 */
#include<iostream>
using namespace std;
int m[205][205],n;
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(!(n%2)){
			cout<<"possible"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<n-i-1;j++){
					m[i][j]=1;
				}
				for(int j=n-i;j<n;j++){
					m[i][j]=-1;
				}
				if(i<n/2){
					m[i][n-i-1]=0;
				}
				else{
					m[i][n-i-1]=1;
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout<<m[i][j]<<" \n"[j==n-1];
				}
			}
			
		}
		else{
			cout<<"impossible"<<endl;
		}
	}
}
