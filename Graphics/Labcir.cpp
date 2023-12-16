#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r = 4; // radius of Circle
    int xc = 7, yc = 6; // Coordinates of Center of Circle
    int x = 0, y = r;
    int d = 3-2*r; // Decision Parameter
    
    vector<vector<int>> coord;
    while(x<=y){
        // 8 Way Symmetry
        coord.push_back({x, y});
        coord.push_back({y, x});
        coord.push_back({x, -y});
        coord.push_back({-y, x});
        coord.push_back({-x, y});
        coord.push_back({y, -x});
        coord.push_back({-x,-y});
        coord.push_back({-y, -x});
        
        if(d<0){ // For decision parameter < 0
            x++;
            d+=(4*x+6);
        }    
        else{ // For decision parameter > 0 or = 0
            x++;
            y--;
            d+=(4*x - 4*y + 6);
        }
    }
    coord.push_back({x, y});
    coord.push_back({y, x});
    coord.push_back({x, -y});
    coord.push_back({-y, x});
    coord.push_back({-x, y});
    coord.push_back({y, -x});
    coord.push_back({-x,-y});
    coord.push_back({-y, -x});
    
    // Printing Points 
    for(int i = 0; i<coord.size();i++){
        cout<<"("<<coord[i][0] + xc<<", "<<coord[i][1] + yc<< ")";
        if(i%8 == 7) cout<<endl;
    }
    return 0;
}