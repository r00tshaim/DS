/* LCA of BST

Given a binary search tree and two nodes, find LCA(Lowest Common Ancestor) of the given two nodes in the BST. Read about LCA if you are having doubts about the definition.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.

Constraints :
1 <= N <= 1000

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 10
Sample Output 1:
8
Sample Input 2:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12 78
Sample Output 3:
-1
*/

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

BinaryTreeNode <int>* findLCA(BinaryTreeNode <int>* root, int n1, int n2) 
{ 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report 
    // the presence by returning root (Note that if a key is 
    // ancestor of other, then the ancestor key becomes LCA 
    if (root->data == n1 || root->data == n2) 
        return root; 
  
    // Look for keys in left and right subtrees 
    BinaryTreeNode <int>* left_lca  = findLCA(root->left, n1, n2); 
    BinaryTreeNode <int>* right_lca = findLCA(root->right, n1, n2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return (left_lca != NULL)? left_lca: right_lca; 
} 

int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    BinaryTreeNode<int>* temp = findLCA(root,val1,val2);
    return temp->data;

}
