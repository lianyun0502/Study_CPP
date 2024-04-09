#include<iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode * left = nullptr;
    TreeNode * right = nullptr;
};


void DFS(TreeNode &node){

    cout << "value:" << node.value <<endl;

    if (node.left != NULL){
        DFS(*node.left);
    }
    
    if (node.right != NULL){
        DFS(*node.right);
    }


}

void BFS(TreeNode &node){

}

void preorderTraversal(TreeNode (&node)){
    cout << "value:" << node.value <<endl;

    if (node.left != NULL){
        preorderTraversal(*node.left);
    }
    
    if (node.right != NULL){
        preorderTraversal(*node.right);
    }


}

void inorderTraversal(TreeNode (&node)){
    if (node.left != NULL){
        inorderTraversal(*node.left);
    }
    cout << "value:" << node.value <<endl;

    if (node.right != NULL){
        inorderTraversal(*node.right);
    }

}

void postorderTraversal(TreeNode (&node)){
        

    if (node.left != NULL){
        postorderTraversal(*node.left);
    }
    
    if (node.right != NULL){
        postorderTraversal(*node.right);
    }

    cout << "value:" << node.value <<endl;
}

int main(){
    TreeNode root = {0};
    TreeNode node1 = {1};
    TreeNode node2 = {2};
    TreeNode node3 = {3};
    TreeNode node4 = {4};
    TreeNode node5 = {5};
    TreeNode node6 = {6};
    TreeNode node7 = {7};
    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.left = &node5;
    node2.right = &node6;
    node3.left = &node7;
    cout << "Preorder:"<<endl;
    preorderTraversal(root);
    cout << "Inorder:"<<endl;
    inorderTraversal(root);
    cout << "Postorder:"<<endl;
    postorderTraversal(root);
    

}