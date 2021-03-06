/* 
Print nodes at distance k from node
Send Feedback
Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : Node

Line 3 : K

Output format : Answer nodes in different line

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3
1
Sample Output :
9
6
*/

public class Solution {

/*	Binary Tree Node class
 * 
 * class BinaryTreeNode<T> {
		T data;
		BinaryTreeNode<T> left;
		BinaryTreeNode<T> right;
		
		public BinaryTreeNode(T data) {
			this.data = data;
		}
	}
	*/
	public static void printNodes(BinaryTreeNode<Integer> node, int k){
        if(node == null)
            return;
        if(k==0){
            System.out.println(node.data+" ");
            return;
        } else {
            printNodes(node.left, k-1);
            printNodes(node.right, k-1);
            
        }
    }
	public static int AtDistanceK(BinaryTreeNode<Integer> root, int data, int k) {
        if(root==null){
            return -1;
        }
        if(root.data.equals(data)){
            printNodes(root,k);
            return k-1;
        }
        int left = AtDistanceK(root.left,data,k);
        int right = AtDistanceK(root.right,data,k);
        if(left != -1){
            if(left == 0){
                System.out.println(root.data);
                return -1;
            } else {
                printNodes(root.right,left -1);
                return left-1;
            }
            } else if(right != -1){
                if(right ==0){
                    System.out.println(root.data);
                    return -1;
                } else {
                    printNodes(root.left,right-1);
                    return right-1;
                }
            }
            return -1;
        
    }
    
	public static void nodesAtDistanceK(BinaryTreeNode<Integer> root, int node, int k) {
		// Write your code here
		int a = AtDistanceK(root,node,k);
	}
}