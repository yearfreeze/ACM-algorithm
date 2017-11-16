/*一个极其优美的数据结构——线段树
能快速查询区间值*/ 

#include<iostream>
#include<algorithm>

#define PI 3.14
#define INF (2<<10)

using namespace std;


int a[10]={5,6,7,8,9,4,2,1,3,10};

int Line_tree[10];

void build(int root,int b,int e){
	if(b==e){
		Line_tree[root]=a[b];
		return ;
	}
	int m=(b+e)/2;
	build(root*2,b,m);
	build(root*2+1,m+1,e);
	Line_tree[root]=min(Line_tree[2*root],Line_tree[2*root+1]);
}
int find(int fb,int fe,int b,int e,int root){
	if(fb>e||fe<b)
		return INF;
	if(fb<=b&&fe>=e)
		return Line_tree[root];
	int mid=(b+e)/2;
	int fl=find(fb,fe,b,mid,root*2);
	int fr=find(fb,fe,mid+1,e,root*2+1);
	return min(fl,fr);
	
}

int main(){
	int length=sizeof(a)/sizeof(int);
	
	cout<<length;
	
	build(1,0,length-1);
	
	for(int i=0;i<length;i++)
		cout<<Line_tree[i]<<endl;
		
	cout<<"answer is "<<find(4,6,0,length-1,1);
	return 0;
}
