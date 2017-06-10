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

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    int times = k;
    if (k > n){
        times = k%n;
    }
    /*for (int i = 0 ; i < times; i++){
        int initial = a[0];
       // a[n-1] = a[0];
        for(int j = 0; j < n-1; j++){
            a[j] =a[j+1];
        }
        a[n-1]= initial;
    }
    return a;*/
    vector<int> result;
    for(int i = times; i < n; i++){
        result.push_back(a[i]);
    }
    for(int i =0; i < times; i++){
        result.push_back(a[i]);
    }
    return result;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}