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

int lonely_integer(vector < int > a) {
    unordered_map<int, int> hashmap;
    for(int i = 0; i < a.size(); i++){
        hashmap[a[i]]++;
    }
    unordered_map<int, int> :: iterator it;
    for(it = hashmap.begin(); it!= hashmap.end(); it++){
        if(it->second == 1){
            return it->first;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    cout << lonely_integer(a) << endl;
    return 0;
}