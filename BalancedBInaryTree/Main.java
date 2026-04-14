package BinaryTree.BalancedBInaryTree; 
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class Node{
    int data;
    Node left;
    Node right;
    Node(int val){
        data = val;
        left = null;
        right = null;
    }
};
class Main{
    static int BalancedBT(Node root){
        if(root ==null) return 0;
        int left = BalancedBT(root.left);
        int right = BalancedBT(root.right);
        int diff = Math.abs(left - right);
        if(diff > 1) return -1;
        return Math.max(left, right) + 1;
    }
    public boolean isBalanced(Node root){
        return BalancedBT(root)!= -1;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the number of nodes in the binary tree:");
            int n = sc.nextInt();
            Queue<Node> q = new LinkedList<>();
            System.out.println("Enter the value of the root node:");
            for(int i=0;i<n;i++){
                int val = sc.nextInt();
                Node newNode = new Node(val);
                if(i==0){
                    q.add(newNode);
                }else{
                    Node parent = q.peek();
                    if(parent.left == null){
                        parent.left = newNode;
                    }else{
                        parent.right = newNode;
                        q.poll();
                    }
                    q.add(newNode);
                }
            }
            System.out.println("Is the binary tree balanced? " + new Main().isBalanced(q.peek()));
        }
    }
}