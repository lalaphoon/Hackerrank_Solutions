#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;

class IceCream {
    
    public: 
        int flavor; 
        int index;

        IceCream(int flavor, int index) {
            this->flavor = flavor;
            this->index = index;
       }
};
    
int binarySearch(int first, int last, vector<IceCream> arr, int search) {
   
   if (arr.size() == 0){return -1;}
   if (arr.size() == 1 && arr[0].flavor == search){return arr[0].index;}
   if (first == last && arr[first].flavor == search) {return arr[first].index;}
   else if(first == last && arr[first].flavor != search) {return -1;}
   int median =  (int)(first + last)/2;
   if(arr[median].flavor < search){
      return  binarySearch(median+1, last, arr, search);
   } else {
      return  binarySearch(first, median, arr,search);
   }
    
 
}
/*vector<int> addsToTarget(vector <IceCream> & numbers, int target){
    vector<IceCream> :: iterator it;
    unordered_map <int, int> hashmap;
    vector <int> result(2);
    for (int i = 0; i < numbers.size(); i++){
        hashmap[numbers[i].flavor] = numbers[i].index;
        if(hashmap.count(target-numbers[i].flavor)){
            result[0] = hashmap[target - numbers[i].flavor];
            result[1]= hashmap[numbers[i].flavor] ;
            //return result;
            break;
        }
    }
    return result;
}*/
bool compare(IceCream a, IceCream b){
    return a.flavor < b.flavor;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }
       
        sort(arr.begin(), arr.end(), compare);
        int firstIndex = 100000, secondIndex = 100000;
        
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;

                }
            }
        }
        
        

    }

}