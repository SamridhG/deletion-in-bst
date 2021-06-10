#include<iostream>
using namespace std;
class node{
	public:
		int val;
		node *right,*left;
		node (int val)
		{
			this->val=val;
			right=left=NULL;
		}
};
class tree{
	public:
	node *root;
	tree()
	{
		root=NULL;
	}
	void insert(int data)
	{
		if(root==NULL)
		{
			root=new node(data);
		}
		else
		{
			node *current=root;
			while(true)
			{
				if(current->val>data)
				{
					if(current->left==NULL)
					{
						current->left=new node(data);
						break;
					}
					else
					{
						current=current->left;
					}
				}
				else
				{
					if(current->right==NULL)
					{
						current->right=new node(data);
						break;
					}
					else
					{
						current=current->right;
					}	
				}
			}
		}
	}
	int max(node *rt)
	{
		if(rt->right==NULL)return rt->val;
		else
		{
			return max(rt->right);
		}
	}
	node* remove(node *rt,int data)
	{
		if(rt==NULL)return NULL;
		else if(rt->val==data)
		{
			if(rt->left==NULL || rt->right==NULL)
			{
				if(rt->left==NULL)
				{
					node *temp=rt->right;
					delete(rt->right);
					delete(rt);
					return temp;
				}
				else
				{
					node *temp=rt->right;
					delete(rt->left);
					delete(rt);
					return temp;
				}
			}
			else
			{
				int maxt=max(rt->left);
				rt->val=maxt;
				rt->left=remove(rt->left,maxt);
				return rt;
			}
		}
		else if(rt->val>data)
		{
			rt->left=remove(rt->left,data);
			return rt;
		}
		else
		{
			rt->right=remove(rt->right,data);
			return rt;
		}
	}
	void inorder(node *rt)
	{
		if(rt!=NULL)
		{
			inorder(rt->left);
			cout<<rt->val<<" ";
			inorder(rt->right);
		}
	}
};
int main()
{
	tree A;
	A.insert(10);
	A.insert(8);
	A.insert(9);
	A.insert(5);
	A.insert(35);
	A.insert(12);
	A.insert(46);
	A.inorder(A.root);
	A.root=A.remove(A.root,0);
	cout<<endl;
	A.inorder(A.root);
	
}
