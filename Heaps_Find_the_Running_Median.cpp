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




int main(){
    int n, value;
    vector<int> a;
    
    cin >> n;
    cout.precision(1);
    
for(int a_i = 0; a_i < n; a_i++){
    cin >> value;
    a.insert(lower_bound(a.begin(), a.end(), value), value);
    //a.push_back(value);
    //std::sort(a.begin(), a.end());
    if ((a_i % 2) == 0) {
        cout << fixed << (double)a[a_i / 2] << endl;
    } else {
        cout << fixed << (double)(a[a_i / 2] + a[a_i / 2 + 1]) / 2 << endl;
    }
}
    return 0;
}