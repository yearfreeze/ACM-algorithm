#include<iostream>
using namespace std;
int a[10]={1,2,3,4,5,6,7,8,9,10};
int b[20];
void intervel_tree(int root,int l,int h){
	if(l==h){
		b[root]=a[l-1];
	}
	else{
		intervel_tree(root*2,l,(l+h)/2);
		intervel_tree(root*2+1,(l+h)/2+1,h);
		b[root]=b[2*root]+b[2*root+1];
	}
}

int main(){

	
	intervel_tree(1,1,10);
	for(int i=0;i<20;i++)
	 cout<<"i:"<<i<<" "<<b[i]<<endl;
	
	return 0;
}
