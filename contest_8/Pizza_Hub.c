#include <stdio.h>
#include <math.h>
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)>(b)?(b):(a)
#define eps 1e-6
struct point{
	double x,y;
}p[3];
struct edge{
	struct point p1,p2;
	double dis;
}edges[3];
const double pi=3.14159265358979323846264338327950288;
double w,s,f_s,min,s_l,f_l;//s为三角形面积，f_s为最长边与次长边夹角,s_l为次长边与最短边夹角,f_l为最长边与最短边夹角
double dis(struct point*p1,struct point*p2){
	return sqrt(pow(p2->x-p1->x,2)+pow(p2->y-p1->y,2));
}

void swap_d(double *a,double *b){
	double c=*a;
	*a=*b;
	*b=c;
}
void swap_p(struct point*p1,struct point*p2){
	swap_d(&p1->x,&p2->x);
	swap_d(&p1->y,&p2->y);
}
void swap_e(struct edge*e1,struct edge*e2){
	swap_p(&e1->p1,&e2->p1);
	swap_p(&e1->p2,&e2->p2);
	swap_d(&e1->dis,&e2->dis);
}
void e(){//预处理 求出三边并按降序排列
	int t=0;
	for(int i=0;i<2;i++){
		for(int j=i+1;j<3;j++){
			edges[t].p1.x=p[i].x;
			edges[t].p1.y=p[i].y;
			edges[t].p2.x=p[j].x;
			edges[t].p2.y=p[j].y;
			edges[t++].dis=dis(&p[i],&p[j]);
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2-i;j++){
			if(edges[j].dis<edges[j+1].dis){
				swap_e(&edges[j],&edges[j+1]);
			}
		}
	}
}

void S(){
	f_s=acos((pow(edges[0].dis,2)+pow(edges[1].dis,2)-pow(edges[2].dis,2))/(2*edges[0].dis*edges[1].dis));
	s_l=acos((pow(edges[1].dis,2)+pow(edges[2].dis,2)-pow(edges[0].dis,2))/(2*edges[1].dis*edges[2].dis));
	f_l=acos((pow(edges[0].dis,2)+pow(edges[2].dis,2)-pow(edges[1].dis,2))/(2*edges[0].dis*edges[2].dis));
	s=(edges[0].dis*edges[1].dis*sin(f_s))/2;
}

void update_min(double tmp){//更新最小值
	if(min==-1||min>tmp){
		min=tmp;
	}
}
void solve(int e){
	if(e==0){//最长边为底
		if(w>=edges[e].dis){
			update_min(s*2/edges[e].dis);
		}
		else{
			double sita=acos(w/edges[e].dis);
	//		if((f_s-sita-pi/2<eps&&f_l+sita-pi/2<eps)||(f_l-sita-pi/2<eps&&f_s+sita-pi/2<eps)){
	//			update_min(min(max(edges[e].dis*sin(sita),edges[1].dis*sin(sita+f_s)),max(edges[e].dis*sin(sita),edges[2].dis*sin(sita+f_l))));
	//		}
			if(f_s-sita-pi/2<eps&&f_l+sita-pi/2<eps){
				update_min(max(edges[0].dis*sin(sita),edges[2].dis*sin(sita+f_l)));
			}
			if(f_l-sita-pi/2<eps&&f_s+sita-pi/2<eps){
				update_min(max(edges[0].dis*sin(sita),edges[1].dis*sin(sita+f_s)));
			}
		}
	}
	else if(e==1){//次长边为底
		double pf;//三角形底与x轴平行时所需最小宽度
		pf=edges[e].dis;
		if(s_l-pi/2>eps){//钝角三角形
			pf-=edges[2].dis*cos(s_l);
		}
		if(w>=pf){
			update_min(s*2/edges[e].dis);
		}
		if(w<edges[e].dis){
			double sita=acos(w/edges[e].dis);
			if(s_l-sita-pi/2<eps&&f_s+sita-pi/2<eps){
				update_min(max(edges[1].dis*sin(sita),edges[0].dis*sin(sita+f_s)));
			}
			if(f_s-sita-pi/2<eps&&s_l+sita-pi/2<eps){
				update_min(max(edges[1].dis*sin(sita),edges[2].dis*sin(sita+s_l)));
			}
		}
	}
	else{
		double pf;
		pf=edges[e].dis;
		if(s_l-pi/2>eps){
			pf-=edges[1].dis*cos(s_l);
		}
		if(w>=pf){
			update_min(s*2/edges[e].dis);
		}
		if(w<edges[e].dis){
			double sita=acos(w/edges[e].dis);
			if(s_l-sita-pi/2<eps&&f_l+sita-pi/2<eps){
				update_min(max(edges[2].dis*sin(sita),edges[0].dis*sin(sita+f_l)));
			}
			if(f_l-sita-pi/2<eps&&s_l+sita-pi/2<eps){
				update_min(max(edges[2].dis*sin(sita),edges[1].dis*sin(sita+s_l)));
			}
		}
	}
}

int main(){
	//freopen("./data/b.in","r",stdin);
	//freopen("P.out","w",stdout);
	int T;
	for(scanf("%d",&T);T;T--){
		min=-1;
		for(int i=0;i<3;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		scanf("%lf",&w);
		e();
		S();
		for(int i=0;i<3;i++){
			solve(i);
		}
		if(min==-1){
			puts("impossible");
		}
		else{
			printf("%.9lf\n",min);
		}
	}
}
