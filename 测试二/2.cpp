#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define mod 2021
long long n,m,u1=0xaf128e66,u2=0x3365b701;
typedef struct tr {
	int l, r;
	int tag;
	long long val[4];
}tr;

tr node[N<<4];
inline void pushdown(int i ){
	if( node[i].tag == 0 ){
		return;
	}
	for(int j = 0 ; j < 4 ; j ++){
		if( j < (j^node[i].tag))
			continue;
		swap(node[i<< 1].val[j], node[i<<1].val[node[i].tag^j]);
		swap(node[i<< 1|1].val[j], node[i<<1|1].val[node[i].tag^j]);
	}


	node[i << 1].tag ^= node[i].tag;
	node[i << 1 | 1].tag ^= node[i].tag;

	node[i].tag = 0;
}

inline void upadate( int t){
	//pushdown(t);pushdown(t << 1);pushdown(t<<1|1);
	for(int i = 0 ; i < 4 ; i ++){
		node[t].val[i] = node[ t << 1 ].val[i] + node[ t << 1 | 1].val[i] ;
	}
}

void build(int i, int l, int r){
	node[i].l = l; node[i].r= r; node[i].tag = 0;
	if( l == r){
		node[i].val[0] = l;
		node[i].val[1] = l ^ u1;
		node[i].val[2] = l ^ u2;
		node[i].val[3] = l ^ u1 ^ u2;
		for(int j = 0 ; j < 4 ; j ++){
			node[i].val[j] %= mod;
		}
		return;
	}
	int mid = (l + r )>> 1;
	build(i << 1, l , mid);
	build(i << 1 | 1 , mid+1, r);
	upadate(i);
}
void modify(int i, int l, int r , int tag){
	if( node[i].l > r || node[i].r < l)
		return ;
	pushdown(i);
	if( node[i].l >= l && node[i].r <= r){
		node[i].tag ^= tag;
		for(int j = 0 ; j < 4 ; j ++){
			if( j < (j^node[i].tag))
				continue;
			swap(node[i].val[j], node[i].val[node[i].tag^j]);
		}
		return ;
	}
	
	modify(i << 1, l, r, tag);
	modify(i << 1 | 1, l ,r ,tag);
	upadate(i);
}

long long  query(int i, int l, int r){
	if( node[i].l > r || node[i].r < l)
		return 0;
	
	if( node[i].l >= l && node[i].r <= r){
		return node[i].val[0];
	}
	pushdown(i);
	return query(i << 1, l , r)+ query(i << 1 | 1, l, r);
}
int main(){
	scanf("%d%d",&n,&m);
	build(1, 1, n);
	for(int i = 1 ; i <= m ; i ++){
		int l , r;
		scanf("%d%d",&l,&r);
		long long res = query(1, l, r);
		printf("%d\n",res);
		if( res & 1)
			modify(1, l, r, 2);
		else
			modify(1, l, r, 1);
	}
}