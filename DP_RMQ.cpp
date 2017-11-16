/*这个文件的目的是实现sparse table算法思想下的 RMQ问题*/ 
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define log2(x) (log(x)/log(2))

int data[10]={7,9,8,5,6,4,2,1,3,10};

int dp[10][10]={0};			//状态(i,j)表示从i开始2^j长度的序列，dp(i,j)=min(dp(i,j-1),dp(i)) 
int pos[10][10]={0};

void ST(int len){
	int k=(int)log2(len);
	for(int i=0;i<len;i++)
		dp[i][0]=data[i];
		
	for(int j=1;j<=k;j++){
		for(int i=0;i+pow(2,j-1)<len;i++)
			dp[i][j]=min(dp[i][j-1],dp[i+(int)pow(2,j-1)][j-1]);
	}
}

int find(int b,int e){
	int k=(int)log2(e-b+1);
	return min(dp[b][k],dp[e-(int)pow(2,k)+1][k]);

}

int main(){

	ST(10);
	
		
	cout<<find(2,6);
	return 0;
}
