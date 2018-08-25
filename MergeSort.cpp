/*

 πÈ≤¢≈≈–Ú 

*/
#include<iostream>
using namespace std;

int array[]={7,9,8,5,4,6,1,2,3};

int s[10];

void swap(int p,int q){
	int temp;
	temp=array[p];
	array[p]=array[q];
	array[q]=temp;
}

void Merge(int low,int mid,int high){
	int i=low;
	int j=mid+1;
	int count=0;
	while(i<mid+1 && j<high+1){
		if(array[i]<array[j]){
			s[count]=array[i];
			i++;
		}
		else{
			s[count]=array[j];
			j++;
		}
		count++;
	}
	while(i<mid+1){
		s[count++]=array[i];
		i++;
	}
	while(j<high+1){
		s[count++]=array[j];
		j++;
	}
	for(int k=0;k<count;k++){
		array[low]=s[k];
		low++;
	}
}

void sort(int low,int high){
	if(low<high){
		int m=(low+high)/2;
		sort(low,m);
		sort(m+1,high);
		Merge(low,m,high);
	}
}

int main(){
	
	sort(0,8);
	for(int i=0;i<9;i++)
		cout<<array[i]<<endl;
	return 0;
}
