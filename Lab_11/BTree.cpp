#include "BTree.h"
#include <iostream>

using namespace std;


/*
    Initializes the root, the binary tree is empty.
*/
BTree::BTree(){
    this->root = NULL;
}


/*
    Deletes the entire Binary Tree by calling destroy_tree().
*/
BTree::~BTree(){
    destroy_tree();
}


/*
    A public function that inserts a key into the tree. It creates a new
    node as root with key_value equals to key if the tree is empty, otherwise 
    it calls insert(key, root) to insert the key at the correct location.
*/
void BTree::insert(int key){
    if(this->root == NULL){ // If root is empty, create the root node
        this->root = new Node;
        this->root->key_value = key;
        this->root->left = NULL;
        this->root->right = NULL;
    }else // Otherwise find where to insert.
        insert(key, this->root);
}


/*
    A public function that starts the search of the input argument key
    from the root node. It returns the pointer to the node that has the 
    same key_value as key (you do not need to perform any comparison in 
    this function, only need to call search(int key, node *leaf) with 
    the correct input arguments to start the search).
*/
Node* BTree::search(int key){
    return search(key, this->root);
}


/*
    A public function that calls destroy_tree(node *leaf) with the
    correct input argument to destroy the whole tree.
*/
void BTree::destroy_tree(){
    destroy_tree(this->root);
}


/*
    Returns a pointer pointing to the root of the Binary Tree
*/
Node* BTree::BTree_root(){
    return this->root;
}


/*
    A recursive function that destroys a subtree with the input
    argument (leaf) as root. This function will check if leaf exists, 
    then recursively destroy its left and right child nodes.
*/
void BTree::destroy_tree(Node *leaf){
    if(leaf != NULL){
        if(leaf->left != NULL){
            destroy_tree(leaf->left); // Branch Left to delete
        }
        if(leaf->right != NULL){ // Branch right to delete
            destroy_tree(leaf->right);
        }
        delete leaf;
    }
}


/*
    A recursive function that compares the input argument
    key with the key_value of the other input argument leaf. 
    If key is less than key_value, the same function is called 
    with the left child node of leaf as the new input argument; 
    otherwise, the right child node of leaf will be used as the 
    new input argument. When the leaf node is empty (NULL), a new 
    node is created and its key_value is set to key.
*/
void BTree :: insert(int key, Node* leaf){
    if (key < leaf->key_value){ // Branch Left
        if(leaf->left != NULL){
            insert(key, leaf->left);    
        }else{ // Insert Left
            leaf->left = new Node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }else{
        if(leaf->right != NULL){ // Branch Right
            insert(key, leaf->right);    
        }else{ // Insert Right
            leaf->right = new Node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

/*
    A recursive function that compares the input argument
    key with the key_value of the other input argument leaf. 
    It returns the pointer to leaf if key = key_value. If 
    key < key_value, the same function is called with the left 
    child node of leaf as the new input argument; otherwise, the 
    right child node of leaf will be used as the new input argument. 
    It returns NULL if leaf is NULL (it reaches the end of the tree 
    but the key is not found).
*/
Node* BTree::search(int key, Node* leaf){
    if(leaf == NULL){ // Reaches end of the tree without finding the key.
        return NULL;
    }else if(leaf->key_value == key){ // Found key leaf
        return leaf;
    }else if(key < leaf->key_value){ // Branch Left
        return search(key, leaf->left);
    }else{ // Branch Right
        return search(key, leaf->right);
    }
}