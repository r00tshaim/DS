/*Given a Binary Tree with N number of nodes, for each node create a new duplicate node, and insert that duplicate as left child of the original node.

Constraints :
1 <= N <= 1000

Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output :
8 
8 10 
5 10 
5 6 
2 6 7 
2 7
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

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
	BinaryTreeNode<int>* oldLeft;  
      
    if (root == NULL) return;  
      
    /* do the subtrees */
    insertDuplicateNode(root->left);  
    insertDuplicateNode(root->right);  
      
    /* duplicate this node to its left */
    oldLeft = root->left;  
    root->left = new BinaryTreeNode<int>(root->data);  
    root->left->left = oldLeft; 
}
