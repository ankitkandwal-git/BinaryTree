package BinaryTree.MaxPathSum;
import java.util.Scanner;
class Node {
    int data;
    Node left;
    Node right;
    
    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

public class Main {
    static Node insert(Node root, int val) {
        if(root == null) {
            return new Node(val);
        }
        if(val < root.data) {
            root.left = insert(root.left, val);
        } else {
            root.right = insert(root.right, val);
        }
        return root;
    }
    
    static int maxPathSum(Node root,int maxSum) {
        if(root == null) return 0;
        int leftSum = maxPathSum(root.left,maxSum);
        int rightSum = maxPathSum(root.right,maxSum);
        maxSum = Math.max(maxSum, leftSum+rightSum+root.data);
        return Math.max(leftSum, rightSum) + root.data;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            Node root = null;
            for(int i=0;i<n;i++){
                int val = sc.nextInt();
                root = insert(root,val);
            }
            int maxSum = Integer.MIN_VALUE;
            maxSum = maxPathSum(root,maxSum);
            System.out.println(maxSum);
        }
    }
}
