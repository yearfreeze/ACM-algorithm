#include<iostream>
using namespace std;
const int n=20;
int root[n]={0};	//ธ๙สýื้
int find(int i){
/*	if(i==root[i])
		return i;
	else
		return find(root[i]);*/
		return i==root[i]?i:find(root[i]);
}

void unions(int i,int j){
	int ii=find(i);
	int jj=find(j);
	root[jj]=ii;
}
int main(){
	int num;
	cin>>num;

	/*initliztion*/
	for(int i=0;i<num;i++)
		root[i]=i; 
	
	cout<<find(5)<<endl;
	unions(1,5);
	cout<<find(5);
	
	return 0;
}
