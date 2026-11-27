class Solution {
    int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int dfs(vector<vector<int>>& grid,int r,int c,int area){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0){
            return 0;
        }
      
            area++;
        
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            area+=dfs(grid,r+directions[i][0],c+directions[i][1],0);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int maxArea=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    int area=dfs(grid,i,j,0);
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
        
    }
};

