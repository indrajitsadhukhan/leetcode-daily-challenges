/*
My Notes:
1. This can be implemented using queue. (BFS)
2. add 1 to the queue and mark visited[n-1][0]=1;
Formula to convert the number in board to board[i][j]
Build this formula by taking few examples.
1 => (n-1,0)
2 => (n-1,1)
6 => (n-1,n-1)
7 => (n-2,n-1)
12 => (n-2,0)
13 =>(n-3,0)

pair<int,int> findCoordinates(x,n)
{
x--;
int row=n-1-x/n;
int col=x%n;;
if((x/n)&1)
{
col=n-1-col;
}
return {row,col};
}

3. let size=q.size(). Pop the front element of the queue (let pos=1)
4. then iterate through dice=(1 to 6) and add (let x=pos+dice)
let k=findCoordinates(x,n);
push (board[k.first][k.second]) into queue if -1 then push (pos+dice). 

5. Do this until size is 0. 
6. if size==0 then ans++;
Repeat from step 3 until q is empty.

Return ans;
*/
class Solution {
public:
pair<int,int> findCoordinates(int x,int n) {
    x--;
    int row=n-1-x/n;
    int col=x%n;
//     If row is odd then the numbers are reverse in order.
    if((x/n)&1)
    {
    col=n-1-col;
    }
    return {row,col};
}
    int snakesAndLadders(vector<vector<int>>& board) {
//         It is a nxn board.
        int n=board.size();
//        Initialize visited array and push 1 to the queue.
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        visited[n-1][0]=1;
        queue<int> q;
        q.push(1);
        int ans=0;
//     Start BFS.
        while(!q.empty())
        {
            int size=q.size();

//             If all numbers in queue is used then we have taken one step so ans++
            while(size>0)
            {
                size--;
                int curr=q.front();
                q.pop();
                for(int dice=1;dice<=6;dice++)
                {
//                     For all dice 1 to 6 find the co-ordinate on board.
                    pair<int,int> k = findCoordinates(dice+curr,n);
                    
//                     Check if the co-ordinate is already visited.
                    if(visited[k.first][k.second]==1)
                        continue;
                    visited[k.first][k.second]=1;
                    
//                     If we reach at the end return ans+1.
                    if(board[k.first][k.second]==n*n || dice+curr==n*n)
                        return ans+1;
                    
                    if(board[k.first][k.second]==-1)
                    {
//                      There is no ladder/snake.
                        q.push(dice+curr);
                    }
                    else{
//                       Go to the end point of ladder/snake.
                     q.push(board[k.first][k.second]);   
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};