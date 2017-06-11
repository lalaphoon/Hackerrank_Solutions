#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

struct Player {
    string name;
    int score;
}; 

vector<Player> comparator(vector<Player> players) {
    stack<Player> oneContainer;
    stack<Player> finalResult;
    for (int i = 0; i < players.size(); i++){
        if(!oneContainer.empty()){
            while(!oneContainer.empty() && ((oneContainer.top().score < players[i].score))){
                finalResult.push(oneContainer.top());
                oneContainer.pop();
                
            }
            while(!oneContainer.empty() && (oneContainer.top().score == players[i].score) &&(strcmp(oneContainer.top().name.c_str(), players[i].name.c_str()) > 0)){
                finalResult.push(oneContainer.top());
                oneContainer.pop();
            }
        }
        if (!finalResult.empty()){
            Player theLastOne = finalResult.top();
            while (theLastOne.score > players[i].score ) {
                oneContainer.push(theLastOne);
                finalResult.pop();
                if (finalResult.empty()){
                    break;
                }
                theLastOne = finalResult.top();
                
            }
            while((theLastOne.score == players[i].score) && (strcmp(theLastOne.name.c_str(), players[i].name.c_str()) < 0)){
                oneContainer.push(theLastOne);
                finalResult.pop();
                if(finalResult.empty()){
                    break;
                }
                theLastOne = finalResult.top();
                
            }
        }
        finalResult.push(players[i]);
    }             
    
    if (!oneContainer.empty()){
        while (!oneContainer.empty()){
            finalResult.push(oneContainer.top());
            oneContainer.pop();
        }
    }
    vector<Player> result;
                 
    while (!finalResult.empty()){
        Player tmp = finalResult.top();
        result.push_back(tmp);
        finalResult.pop();
    }
    return result;
    

}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}