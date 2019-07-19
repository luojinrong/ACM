#include<bits/stdc++.h>
using namespace std;
int T;
const double PI=acos(-1);
double r,h,x,y,z,vx,vy,vz,tt,tx,ty,tz,ans;
int main(){
	cin>>T;
	for(int t=1;t<=T;t++){
		ans=1e5;
		cin>>r>>h>>x>>y>>z>>vx>>vy>>vz;
		double a,b,c;
		a=h*h*vx*vx+h*h*vy*vy-r*r*vz*vz;
		b=2*(x*vx*h*h+y*vy*h*h+r*r*vz*(h-z));
		c=h*h*(x*x+y*y)-(h-z)*(h-z)*r*r;
		double t1=(-b+sqrt(b*b-4*a*c))/(2*a);
		double t2=(-b-sqrt(b*b-4*a*c))/(2*a);
		if(t1>0){
			tz=z+vz*t1;
			if(tz>=0&&tz<=h){
				ans=min(ans,t1);
			}
		}
		if(t2>0){
			tz=z+vz*t2;
			if(tz>=0&&tz<=h){
				ans=min(ans,t2);
			}
		}
		cout<<"Case "<<t<<": "<<fixed<<setprecision(10)<<ans<<endl;
	}
}
