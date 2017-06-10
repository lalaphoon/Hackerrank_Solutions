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
string primality(int n){
    if (n == 1){
        return "Not prime";
    }
    for (int i = 1; i <= 1000; i++){
        if(i==1||i==n){
            continue;
        }
        else if (n%i==0){
            return "Not prime";
        }
    }
    return  "Prime";
}

int main(){
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;
        cout << primality(n)<<endl;
    }
    return 0;
}