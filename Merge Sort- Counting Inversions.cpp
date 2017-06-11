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
vector <int> mergeTwoSortedList(vector<int> a, vector <int> b, long long & counter ){
    vector<int> result;
    long a_pointer = 0;
    long b_pointer = 0;
    for (int i = 0; i < a.size() + b.size(); i++){
        if ((b_pointer >= b.size())||(a[a_pointer] <= b[b_pointer] && a_pointer < a.size()) ){
            result.push_back(a[a_pointer]);
            
            if(a_pointer < a.size())
            {
                a_pointer++;
            }
           
        } else if  ((a_pointer >= a.size())||(a[a_pointer]>b[b_pointer] && b_pointer < b.size()) ) {
            result.push_back(b[b_pointer]);
            
            if(a_pointer < a.size()){
                counter += (b_pointer+a.size() - i);
               // cout <<"adding "<< a.size()-i <<endl;
            }
            
            
            if(b_pointer < b.size())
            {
                b_pointer++;
            }
            
        }
    }
 
    return result;
}
vector<int> mergeSort(long first, long last, vector<int> a, long long & counter){
    vector<int> result;
    if (first >= last) {
        result.push_back(a[first]);
        return result;
    }
    if (first +1 == last){
        if (a[first]>a[last]){
            result.push_back(a[last]);
            result.push_back(a[first]);
            counter++;
            return result;
        } else {
            result.push_back(a[first]);
            result.push_back(a[last]);
            return result;
        }
    }
    long mid = (first + last)/2;
    vector<int> first_part = mergeSort(first, mid, a, counter);
    vector<int> second_part = mergeSort(mid+1,last,a, counter);
    result = mergeTwoSortedList(first_part, second_part, counter);
    return result;
}
long long count_inversions(vector<int> a) {
   long long counter = 0;
   vector <int> result = mergeSort(0, a.size()-1,a, counter) ;
   return counter;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
        
       
        
        
        
    }
    return 0;
}