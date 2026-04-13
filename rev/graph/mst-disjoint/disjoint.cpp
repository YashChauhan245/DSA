https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1

class Solution {
  public:
    // Function to find ultimate parent of a node (with path compression)
    int find(int par[], int x) {
        if (x == par[x]) {
            return x;
        }
        return par[x] = find(par, par[x]);
    }

    // Function to unite two sets (union by rank)
    void unionSet(int par[], int rank[], int x, int z) {
        int x_parent = find(par, x);
        int z_parent = find(par, z);

        if (x_parent != z_parent) {
            if (rank[x_parent] < rank[z_parent]) {
                par[x_parent] = z_parent;
            }
            else if (rank[x_parent] > rank[z_parent]) {
                par[z_parent] = x_parent;
            }
            else {
                par[z_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }
};
