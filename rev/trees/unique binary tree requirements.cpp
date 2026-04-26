https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1


//Intution-->No inorder → No unique tree
class Solution {
  public:
    bool isPossible(int a, int b) {
        if ((a == 1 && b == 2) || 
            (a == 2 && b == 1) || 
            (a == 2 && b == 3) || 
            (a == 3 && b == 2))
            return true;
        return false;
    }
};
