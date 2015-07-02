package leetcode;
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class ConvertSortedListToBinarySearchTree {
    static ListNode q;
    
    public TreeNode sortedListToBST(ListNode head) {
        if(head == null)
           return null;
        q = head;
        int lens = getLength(head);
        return sortedListToBST(0,lens - 1);
    }
    
    public int getLength(ListNode head)
    {
        int lens = 0;
        ListNode p = head;
        if(head == null)
            return  0;
        while(p != null)
        {
            ++lens;
            p = p.next;
        }
        return lens;
    }
    
     public TreeNode sortedListToBST(int start,int end)
    {
        if(start > end)
            return null;
            
        int mid = (start + end) / 2 ;
        
        TreeNode left = sortedListToBST(start,mid - 1);
        TreeNode root = new TreeNode(q.val);
        q = q.next;
        TreeNode right = sortedListToBST(mid+1,end);
        root.left = left;
        root.right = right;
        
        return root;
    }

}
