class pair{
    int first,second;
    pair(int first,int second){
        this.first=first;
        this.second=second;
    }
}
class Solution {
    public int orangesRotting(int[][] grid) {
        if((grid.length==1&&grid[0].length==1&&grid[0][0]==1))return -1;
        if(grid == null || grid.length == 0||(grid.length==1&&grid[0].length==1)) return 0;
        int newct=0,n=grid.length,m=grid[0].length,zero=0;
        Queue<pair>q=new LinkedList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.offer(new pair(i,j));
                }
                else if(grid[i][j]==1){
                    newct++;
                }
                else zero++;
            }
        }
        if(zero==n*m)return 0;
        int delrow[]={1,0,-1,0},delcol[]={0,-1,0,1};
        int ct=0;
        while(!q.isEmpty()){
            ct++;
            int p=q.size();
            for(int i=0;i<p;i++){
                pair w=q.poll();
                int r=w.first,c=w.second;
                for(int j=0;j<4;j++){
                    int tr,tc;
                    tr=r+delrow[j];
                    tc=c+delcol[j];
                    if(tr>=0&&tc>=0&&tr<n&&tc<m&&grid[tr][tc]==1){
                        grid[tr][tc]=2;
                        q.offer(new pair(tr,tc));
                        newct--;
                    }
                }
            }

        }
        if(newct!=0)return -1;
        return ct-1;
    }
}
