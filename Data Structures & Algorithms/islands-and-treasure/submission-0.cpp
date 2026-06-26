class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int, int>> q;

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0) q.push({i,j});
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        int lev=0;

        while (!q.empty()){
            int s=q.size();
            lev++;
            for (int i=0;i<s;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for (int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==INT_MAX){
                        grid[nr][nc]=lev;
                        q.push({nr,nc});
                    }
                }
            }
        } 
    }
};
