#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;

    for(int val : arr){
        root = insert(root, val);
    }
    return root;
}

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(root->data > key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

Node* getInorderSuccessor(Node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int key) {
    if(root == NULL){
       return NULL;
    }

    if(key < root->data){
        root->left = delNode(root->left, key);
    }
    else if(key > root->data){
        root->right = delNode(root->right, key); 
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
        }
    }
    return root;
}

void inorderMerge(Node* root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    inorderMerge(root->left, arr);
    arr.push_back(root->data);
    inorderMerge(root->right, arr);
}

Node* buildBSTFromSorted(vector<int> arr, int st, int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end -st)/2;
    Node* root = new Node(arr[mid]);

    root->left = buildBSTFromSorted(arr, st, mid-1);
    root->right = buildBSTFromSorted(arr, mid+1, end);

    return root;
}

Node* merge2BST(Node* root1, Node* root2){
    vector<int> arr1;
    vector<int> arr2;
    inorderMerge(root1, arr1);
    inorderMerge(root2, arr2);

    vector<int> temp;

    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            temp.push_back(arr1[i++]);
        }
        else{
            temp.push_back(arr2[j++]);
        }
    }
    while(i < arr1.size()){
        temp.push_back(arr1[i++]);
    }
    while(j < arr2.size()){
        temp.push_back(arr2[j++]);
    }

    return buildBSTFromSorted(temp, 0, temp.size()-1);
}

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node* root = buildBST(arr);
    
    inorder(root);
    cout << endl;

    cout << search(root, 9) << endl;

    delNode(root, 5);

    inorder(root);
    cout << endl;

    return 0;
}