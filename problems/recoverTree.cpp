#include <stack>
#include <iostream>

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	void recoverTree(TreeNode * root){
		if(!root)	return;
		TreeNode * n1 = NULL, * n2 = NULL;
		TreeNode * node = root, pre = NULL;
		stack<TreeNode*>	s;
		while(!s.empty() || node){
			if(node){
				s.push(node);
				node = node->left;	
			}
			else{
				
			}
		}
	}
};



