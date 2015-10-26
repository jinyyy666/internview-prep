#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <assert.h>

using namespace std;

struct TreeNode{
  TreeNode * left;
  TreeNode * right;
  int val;
  TreeNode(int v):val(v),left(NULL),right(NULL){}
};


// my version of converting array to binary search tree:
class Solution{
public:
  // convert a sorted array to binary search tree:
  TreeNode * sortedArrToBST(int arr[], int start, int end){
    // do this to avoid overflow:
    if(start > end)
      return NULL;
    int mid = start + (end-start)/2;
    TreeNode * node = new TreeNode(arr[mid]);
    node->left = sortedArrToBST(arr, start, mid -1);
    node->right = sortedArrToBST(arr, mid+1, end);
    return node;
  }
  
  // the function to be called to convert the sorted array to BST 
  TreeNode * sortedArrToBST(int arr[], int n){
    sortedArrToBST(arr, 0, n-1);
  }

  void inorderTraversal(TreeNode * node){
    if(!node)
      return;
    inorderTraversal(node->left);
    cout<<"\t"<<node->val;
    inorderTraversal(node->right);

  }
  
  void preorderTraversal(TreeNode * node){
    if(!node)
      return;
    cout<<"\t"<<node->val;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
  }

  void postorderTraversal(TreeNode * node){
    if(!node)
      return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout<<"\t"<<node->val;
  
  }


  // print the numbers in the BST in order:
  void print(TreeNode * root){
    cout<<"Inorder traversal: "<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<"Preorder traversal: "<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<"Postorder traversal: "<<endl;
    postorderTraversal(root);
    cout<<endl;
  }

  // verify the BST:
  // postorder!
  bool verify(TreeNode * root){
    if(!root)
      return true;
    bool ret = verify(root->left);
    ret &= verify(root->right);
    if(root->left && root->right)
      return ret&(root->left->val < root->val &&  root->val <= root->right->val ? true : false);
    else if(!root->left && root->right)
      return ret&(root->right->val >= root->val ? true : false);
    else if(root->left && !root->right)
      return ret&(root->left->val < root->val ? true : false);
    else
      return ret&true;
  }
  // biggest number:
  // postorder!
  int maxNum(TreeNode * root){
    if(!root)
      return INT_MIN;
    int max = maxNum(root->left);
    max = max > maxNum(root->right) ? max : maxNum(root->right);
    return max > root->val ? max : root->val;
  }
  // find the right most child of a BST:
  int getMax(TreeNode * root){
    TreeNode * cur = root;
    if(!cur) return INT_MIN;
    while(cur->right){
      cur = cur->right;
    }
    return cur->val;
  }

  // find the second max in the BST:
  int getSecondMax(TreeNode * root){
    // 1. first the max first:
    TreeNode * cur = root;
    if(!cur) return INT_MIN;
    // if the right child of the root is NULL
    // then you need to find the right most child of the left node of the root:
    
    if(root->right != NULL){
      // if the right child of the root exists:
      return getSecondMaxFromRight(root->right, root);
    }
    else if(root->left != NULL){
      // if the right child of the root does not exist
      // then you know the root is the maximum and the second max is on the right most node of that path on left 
      return getMax(root->left);
    }
    else
      // if we need have one root and no other stuff:
      return INT_MIN;    
  }
  int getSecondMaxFromRight(TreeNode * root, TreeNode * parent){
    // 1. find the first max and keep track of the parent:
    TreeNode * cur = root;
    while(cur->right){
      parent = cur;
      cur = cur->right;
    }
    // 2. find the second maximum:
    // if the max number has no left nodes:
    if(!cur->left)
      return parent->val;
    else{
      return getMax(cur->left);
    }
  }

  
  
  // find the lowest common ancestor given two nodes:
  TreeNode * LCA(TreeNode* root, TreeNode * node1, TreeNode* node2){
    if(!root)
      return NULL;
    
    // if the number we are looking at right now is less than both n1 and n2, then look from the right:
    if(root->val < node1->val && root->val < node2->val)
      return LCA(root->right, node1, node2);

    // if the number we are looking at is larger than both n1 and n2, then look from the right:
    if(root->val > node1->val && root->val > node2->val)
      return LCA(root->left, node1, node2);
    
    return root;
  }
  
  // if given two numbers (they might not be in the list), find out the lowest common ancestor:
  TreeNode * LCA(TreeNode * root, int n1, int n2){
    TreeNode * node1 = new TreeNode(n1);
    TreeNode * node2 = new TreeNode(n2);

    TreeNode * ancestor = LCA(root, node1, node2);
    if(checkExistence(ancestor, n1) && checkExistence(ancestor, n2))
      return ancestor;
    else
      return NULL;
  }

  // check if the given number is in the BST:
  bool checkExistence(TreeNode * root, int val){
    if(!root)
      return false;
    // check the left and right :
    bool ret = checkExistence(root->left, val) || checkExistence(root->right, val);
    if(root->val == val)
      return ret || true;
    else
      return ret || false;
  }
};

int main(int argc, char** argv){
  Solution S;
  
  int* arr = (int *)malloc(sizeof(int)* (argc -1));
  for(int i = 1; i < argc; i ++){
     arr[i-1] = atoi(argv[i]);
  }
  
  //int arr [] = { 12 ,123, 12312, 42112, 13421, 1234,312, 314};
  //int n = sizeof(arr)/sizeof(int);
 
  TreeNode * root = S.sortedArrToBST(arr, argc -1);
  S.print(root);

  cout<<"Verify the BST: "<<S.verify(root)<<endl;

  //cout<<"Maximum number of the BST: "<<S.maxNum(root)<<endl;

  cout<<"Get the maximum number of the BST: "<<S.getMax(root)<<endl;

  cout<<"The second maximum number of the BST: "<<S.getSecondMax(root)<<endl;

  cout<<"Print type in two nums in the BST: "<<endl;
  
  int n1, n2;
  cin>>n1>>n2;
  
  TreeNode * ans = S.LCA(root, n1, n2);
  cout<<"You are typing in : "<<n1<<" "<<n2<<endl;
  if(ans == NULL)
    cout<<"No lowest common ancestor for those two nodes !"<<endl;
  else
    cout<<"Lowest common ancestor for those two nodes is: "<<ans->val<<endl;
  
  free(arr);
  return 0;

}
