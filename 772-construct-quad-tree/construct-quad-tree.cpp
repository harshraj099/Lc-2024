/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    bool allsame(int idx,int jdx,int n,vector<vector<int>>& grid){
        int val=grid[idx][jdx];

        for(int i=idx;i<idx+n;i++){
            for(int j=jdx;j<jdx+n;j++){
                if(val!=grid[i][j])return false;
            }
        }
        return 1;
    }

    Node * f(int i,int j,int n,vector<vector<int>>& grid){
        if(allsame(i,j,n,grid))return new Node(grid[i][j],1);

        Node* node=new Node(1,0);
        node->topLeft=f(i,j,n/2,grid);
        node->topRight=f(i,j+n/2,n/2,grid);
        node->bottomLeft=f(i+n/2,j,n/2,grid);
        node->bottomRight=f(i+n/2,j+n/2,n/2,grid);

        return node;
    }
    Node* construct(vector<vector<int>>& grid) {
        
        return f(0,0,grid.size(),grid);
    }
};