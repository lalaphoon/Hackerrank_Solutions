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
struct Node {
    int count;
    Node* next;
    Node(): count(0), next(nullptr){};
    ~Node(){
        delete[] next;
    }
    
};
void add(string contact, Node* root){
    Node* crawler = root;
    int len =  contact.size();
    for(int i = 0; i < len; i++){
        char c = contact[i];
        int index = c - 'a';
        
        crawler[index].count++;
        
        if(i != len-1){
            if (crawler[index].next == nullptr){
                crawler[index].next = new Node[26];
            }
            crawler = crawler[index].next;
        }
    }
}
int find(string contact, Node* root){
    Node* crawler = root;
    int len = contact.size();
    int count = 0;
    if (root == NULL){return count;}
    for (int i = 0; i < len; i++){
        char c = contact[i];
        int index = c - 'a';
        if (crawler == NULL ){return 0;}
        if (!crawler[index].count){
            return 0;
        }
        if (i == len - 1){
            count = crawler[index].count;
        }
        crawler = crawler[index].next;
    }
    return count;
}
/*
class ContactBook {
    private:
        vector<string> theNameBook;
    public:
        void add(string);
        int find(string);
};
void ContactBook::add(string name){
    theNameBook.push_back(name);
}
int ContactBook::find(string n){
    int count = 0;
    for (int i = 0; i < theNameBook.size(); i++){
        string tmps = theNameBook[i];
        std::size_t found = tmps.find(n);
        if (found != std::string::npos && found == 0){
            count ++;
        }
    }
    return count;
}
*/
int main(){
    int n;
    cin >> n;
    //ContactBook cb = ContactBook();
    string adding = "add";
    string finding = "find";
    Node * root = new Node[26];
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add"){
            add(contact,root);
        } else {
            cout << find(contact,root) << endl;;
        }
        
    }
    delete[] root;
    return 0;
}

