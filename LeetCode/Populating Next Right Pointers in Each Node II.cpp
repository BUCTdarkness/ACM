/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {    
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeLinkNode *node;
        if(root){
            if(root->right){
                node=root->next;
                while(node&&!root->right->next){
                    root->right->next=node->left;
                    if(!node->left){
                        root->right->next=node->right;
                    }
                    node=node->next;
                }
            }
            if(root->left){
                root->left->next=root->right;
                if(!root->right){
                    node=root->next;
                    while(node&&!root->left->next){
                        root->left->next=node->left;
                        if(!node->left){
                            root->left->next=node->right;
                        }
                        node=node->next;
                    }
                }
            }

            connect(root->right);
            connect(root->left);
        }
    }
};