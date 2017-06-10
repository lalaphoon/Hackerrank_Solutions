#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
void DFS(vector<vector<int>> & grid, int x, int y, int & counter){
    grid[x][y] = 0;
    counter++;
    if(x>0 && grid[x-1][y] == 1){
        DFS(grid, x-1, y, counter);
       
    }
    if((x>0 )&&(y > 0 && grid[x-1][y-1]==1)){
        DFS(grid, x-1, y-1, counter);
    }
    if((x>0 )&&(y <  grid[0].size()-1 && grid[x-1][y+1]==1)){
        DFS(grid,x-1,y+1, counter);
    }
    if(x<grid.size()-1 && grid[x+1][y] == 1){
        DFS(grid, x+1, y, counter);
        
    }
    if((x<grid.size()-1)&&(y > 0 && grid[x+1][y-1]==1)){
        DFS(grid, x+1, y-1, counter);
    }
    if((x<grid.size()-1)&&(y <  grid[0].size()-1 && grid[x+1][y+1]==1)){
        DFS(grid,x+1,y+1, counter);
    }
    if (y > 0 && grid[x][y-1]== 1){
        DFS(grid, x, y-1, counter);
    }
    if(y <  grid[0].size()-1 && grid[x][y+1]==1){
        DFS(grid,x,y+1, counter);
    }
    
}
int get_biggest_region(vector< vector<int> > grid) {
    if (grid.size() == 0|| grid[0].size() == 0){
        return 0;
    }
    int max = 0;
    int counter =0;
    for (int i = 0; i < grid.size(); ++ i){
        for (int j = 0; j < grid[i].size(); ++j){
            if(grid[i][j]==1){
                counter = 0;
                DFS(grid, i, j, counter);
                if(counter >  max){
                    max = counter;
                }
            }
        }
    }
    return max;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}