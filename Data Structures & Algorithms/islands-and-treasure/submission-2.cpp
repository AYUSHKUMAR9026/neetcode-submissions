class Solution {
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

public:
    void islandsAndTreasure(vector<vector<int>>& grid){
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int r=x+dirs[i][0];
                int c=y+dirs[i][1];

                if(r<0 || r>=row || c<0 ||
                   c>=col || grid[r][c]!=INT_MAX){
                    continue;
                }

                grid[r][c]=grid[x][y]+1;
                q.push({r,c});
            }
        }
    }
};