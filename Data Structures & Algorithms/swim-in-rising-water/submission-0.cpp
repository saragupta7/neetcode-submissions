class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        // vector<vector<int>> dist(m,vector<int>(n,INT_MAX));

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        int t=grid[0][0];

        pq.push({t,{0,0}});

        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        while (!pq.empty()){
            auto elt=pq.top();
            int currTime=elt.first;
            int r=elt.second.first;
            int c=elt.second.second;
            pq.pop();
            if (r==m-1 && c==n-1) return currTime;

            // if (vis[r][c]==1) continue;

            // vis[r][c]=1;
            for (int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if (nr>=0 && nr<m && nc>=0 && nc<n  && !vis[nr][nc]){   
                    vis[nr][nc]=1; //CAN MARK HERE
                    pq.push({max(currTime,grid[nr][nc]),{nr,nc}});                 
                    // int bestTime=max(currTime,grid[nr][nc]);                 
                    // if (bestTime< dist[nr][nc]){
                    //     dist[nr][nc]=bestTime;
                    //     pq.push({bestTime,{nr,nc}});
                    // }
                }
            }
        }
        return -1;
    }
};
