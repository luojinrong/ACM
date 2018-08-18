#include <stdio.h>
#include <stdlib.h>
#define maxn 150005
typedef long long ll;

ll N,Q;
struct node{
	ll val;
	struct node*next;
	struct node*pre;
};

struct queue{
	ll size;
	struct node*head;
	struct node*tail;
}q[maxn];

void push_back(ll val,struct queue *que){
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	if(que->size==0){
		que->head=que->tail=tmp;
		que->head->pre=NULL;
	}
	else{
		que->tail->next=tmp;
		tmp->pre=que->tail;
		que->tail=que->tail->next;
	}
	que->tail->next=NULL;
	que->tail->val=val;
	que->size++;
}

void push_front(ll val,struct queue *que){
	struct node *tmp=(struct node*)malloc(sizeof(struct node));
	if(que->size==0){
		que->head=que->tail=tmp;
		que->tail->next=NULL;
	}
	else{
		tmp->next=que->head;
		que->head->pre=tmp;
		que->head=tmp;
	}
	que->head->pre=NULL;
	que->head->val=val;
	que->size++;
}

ll pop_front(struct queue *que){
	if(que->size==0){
		return -1;
	}
	else{
		struct node *tmp=que->head;
		ll val=que->head->val;
		que->head=que->head->next;
		if(que->head){
			que->head->pre=NULL;
		}
		free(tmp);
		que->size--;
		return val;
	}
}

ll pop_back(struct queue *que){
	if(que->size==0){
		return -1;
	}
	else{
		struct node *tmp=que->tail;
		ll val=que->tail->val;
		que->tail=que->tail->pre;
		if(que->tail){
			que->tail->next=NULL;
		}
		free(tmp);
		que->size--;
		return val;
	}
}

void cat(struct queue *fro,struct queue *back){
	if(!fro->size){
		fro->head=back->head;
		fro->tail=back->tail;
	}
	else if(!back->size){
		;
	}
	else{
		fro->tail->next=back->head;
		back->head->pre=fro->tail;
		fro->tail=back->tail;
	}
	fro->size+=back->size;
	back->head=back->tail=NULL;
	back->size=0;
}

void reverse(struct queue *que){
	struct node *tmp_s=que->head,*tmp_e=que->tail;
	while(tmp_s!=tmp_e&&tmp_e->next!=tmp_s){
		ll tmp=tmp_s->val;
		tmp_s->val=tmp_e->val;
		tmp_e->val=tmp;
		tmp_s=tmp_s->next;
		tmp_e=tmp_e->pre;
	}
}

void op_1(ll u,ll w,ll val){
	if(w){
		push_back(val,&q[u]);
	}
	else{
		push_front(val,&q[u]);
	}
}

void op_2(ll u,ll w){
	ll val;
	if(w){
		val=pop_back(&q[u]);
	}
	else{
		val=pop_front(&q[u]);
	}
	printf("%lld\n",val);
}

void op_3(ll u,ll v,ll w){
	if(w){
		reverse(&q[v]);
	}
	cat(&q[u],&q[v]);
}

int main(){
	while(~scanf("%lld%lld",&N,&Q)){
		while(Q--){
			ll op,u,v,w,val;
			scanf("%lld",&op);
			if(op==1){
				scanf("%lld%lld%lld",&u,&w,&val);
				op_1(u,w,val);
			}
			else if(op==2){
				scanf("%lld%lld",&u,&w);
				op_2(u,w);
			}
			else{
				scanf("%lld%lld%lld",&u,&v,&w);
				op_3(u,v,w);
			}
		}
	}
}
