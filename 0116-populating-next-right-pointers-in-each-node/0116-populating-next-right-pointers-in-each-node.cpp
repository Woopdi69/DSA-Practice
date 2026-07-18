/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    vector<vector<Node* >> lvl;
    void level_order(Node* root, int l){
        if(root == nullptr){
            return;
        }

        if(l == lvl.size()){
            lvl.push_back(vector<Node* >());
        }

        lvl[l].push_back(root);
        level_order(root->left, l+1);
        level_order(root->right, l+1);
    }

public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        if(root->left == nullptr && root->right == nullptr) return root;

        level_order(root, 0);
        for(auto v : lvl){
            for(int i = 0; i < v.size(); i++){
                if(i == v.size()-1){
                    v[i]->next = nullptr;
                    break;
                }

                v[i]->next = v[i+1];
            }
        }
        
        return root;
    }
};