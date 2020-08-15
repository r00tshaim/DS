/* 
Largest BST

Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
Return the height of largest BST.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2

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
	public static class Triplet{
        boolean isbst;
        int maximum;
        int minimum;
        int height;
        
    }
    public static Triplet largestbst(BinaryTreeNode<Integer>root){
        if(root == null){
            Triplet ans = new Triplet();
            ans.isbst = true;
            ans.maximum = Integer.MIN_VALUE;
            ans.height=0;
            ans.minimum = Integer.MAX_VALUE;
            return ans;
        }
        Triplet left = largestbst(root.left);
        Triplet right = largestbst(root.right);
        Triplet ans = new Triplet();
        if(left.isbst && root.data > left.maximum&& root.data <= right.minimum){
            ans.isbst = true;
        }
        else{
            ans.isbst = false;
        }
        ans.maximum = Math.max(root.data,right.maximum);
        ans.minimum = Math.min(root.data,left.minimum);
        if(ans.isbst==true)
        {
            ans.height=Math.max(left.height,right.height)+1 ;    
        }
    else {
        ans.height=Math.max(left.height,right.height);
    }
        return ans;
    }
	public static int largestBSTSubtree(BinaryTreeNode<Integer> root) {
		// Write your code here
		Triplet s = new Triplet();
        s = largestbst(root);
        return s.height;
	}
}