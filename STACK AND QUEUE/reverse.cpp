//Time : O(n^2)
//Space : O(1) Auxiliary Space
class Solution
{   
    public static void insertAtBottom(Stack<Integer> St, int element) {
        if (St.isEmpty()) {
            St.push(element);
            return;
        }

        int curTopElement = St.pop();
        insertAtBottom(St, element);
        St.push(curTopElement);
    }
    
    static void reverse(Stack<Integer> St) {
        if (St.isEmpty()) {
            return;
        }
        
        int top = St.pop();
        reverse(St);
        insertAtBottom(St, top);
    }
}
