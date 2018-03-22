#include<iostream>
using namespace std;
class BSTnode{
	public:
		BSTnode *left;
		BSTnode *right;
		
		BSTnode(int n,BSTnode *l=0,BSTnode *r=0){
			num=n;
			left=l;
			right=r;
		}
		int get(){
			return num;
		}
		void set(int n){
			num=n;
		}
	private:
		int num;
};
class binary_search_tree{
	public:
		binary_search_tree(int base_num){
			root=new BSTnode(base_num);
		}
		//digonose 'num' paramater if in this BStree
		BSTnode* search(int num,BSTnode *root){
			if(num<root->get())
				return search(num,root->left);
			else if(num>root->get())
				return search(num,root->right);
			else{
				if(num==root->get())
					return root;
				else
					return NULL;
			}
		}
		
		BSTnode *Add(int num,BSTnode *r){
			if(r==NULL){
				r=new BSTnode(num);
			}
			if(num<r->get())
				r->left=Add(num,r->left);
			else if(num>r->get())
				r->right=Add(num,r->right);
			
			return r;
		}
		int min(BSTnode *r){
			while(r->left!=0){
				r=r->left;
			}
			return r->get();
		}
		BSTnode* deletenode(int num,BSTnode *root){
			if(num<root->get())
				root->left=deletenode(num,root->left);
			else if(num>root->get())
				root->right=deletenode(num,root->right);
			else if(root->left!=0&&root->right!=0){ //has two sons
				int temp=min(root->right);
				root->set(temp);
				deletenode(temp,root->right);
			}
			else{//one or zero son
				if(root->left==0&&root->right==0)
					return NULL;
				else{
					BSTnode *temp=new BSTnode(0);
					temp=root->left!=0?root->left:root->right;
					root->set(temp->get());
					root->left=root->right=0;
				}

			}
			return root;
		}
	public:
		BSTnode *root;
};



int main(){
	binary_search_tree *t=new binary_search_tree(5);
	//t.Add(6,root);
	cout<<t->root->get()<<endl;
	
	int a[8]={7,9,8,6,4,2,1,3};
	for(int i=0;i<8;i++){
		t->Add(a[i],t->root);
	}
	BSTnode *n=t->search(1,t->root);
	cout<<n->get();

	t->deletenode(7,t->root);

	t->Add(11,t->root);
	return 0;
	
}