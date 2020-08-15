/* 
Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number k.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : k

Output format : Print each path in new line, elements separated by space

Sample Input 1 :
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
Sample Output 1 :
5 6 2
5 7 1

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
#include <bits/stdc++.h> 

// This function prints all paths that have sum k 
void printVector(const vector<int>& v, int i) 
{ 
    for (int j=i; j<v.size(); j++) 
        cout << v[j] << " "; 
    cout << endl; 
} 

void printKPathUtil(BinaryTreeNode<int>* root, vector<int>& path, 
                                           int k) 
{ 
    // empty node 
    if (!root) 
        return; 
  
    // add current node to the path 
    path.push_back(root->data); 
  
    // check if there's any k sum path 
    // in the left sub-tree. 
    printKPathUtil(root->left, path, k); 
  
    // check if there's any k sum path 
    // in the right sub-tree. 
    printKPathUtil(root->right, path, k); 
  
    // check if there's any k sum path that 
    // terminates at this node 
    // Traverse the entire path as 
    // there can be negative elements too 
    int f = 0; 
    for (int j=path.size()-1; j>=0; j--) 
    { 
        f += path[j]; 
  
        // If path sum is k, print the path 
        if (f == k) 
            printVector(path, j); 
    } 
  
    // Remove the current element from the path 
    path.pop_back(); 
} 

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
	vector<int> path; 
    printKPathUtil(root, path, k);
}
