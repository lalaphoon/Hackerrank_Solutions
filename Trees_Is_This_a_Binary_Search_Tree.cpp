/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
#include <vector>

void addingNumber(Node* root, vector <int>& result){
    if (root==NULL){
        return;
    }else if (root->left == NULL && root->right == NULL){
         result.push_back(root->data); 
         return;
    } else {
        addingNumber(root->left, result);
        result.push_back(root->data);
        addingNumber(root->right,result);
    }
    
}
bool checking(vector<int> result){
    for (int i = 0; i  < result.size()-1; i++){
        if (result[i]>= result[i+1]){
            return false;
        }
    }
    return true;
}
bool checkBST(Node* root) {
      vector<int> result;
      addingNumber(root, result);
      return checking(result);
     
}

