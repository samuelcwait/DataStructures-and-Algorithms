#include <iostream>

using namespace std;

struct TreeNode {
   int value;
   TreeNode* left;
   TreeNode* right;
};

class MyBST {
public:
   MyBST () { root = NULL; }
   ~MyBST ();
   bool Find(int x);   
   void Insert(int x);
   void PreorderTraversal();
   void PostorderTraversal();
   void InorderTraversal();

private:
   TreeNode* root;
   
   void FreeHelper(TreeNode* node);
   bool FindHelper(TreeNode* node, int x);
   //void InsertHelper(TreeNode* node, int x);  // use this one if you want to implement InsertHelper without passing a pointer by reference. 
   void InsertHelper(TreeNode*& node, int x);
   void Preorder(TreeNode* node);
   void Postorder(TreeNode* node);
   void Inorder(TreeNode* node);
}; 

MyBST::~MyBST() {
   FreeHelper(root);
}

void MyBST::FreeHelper(TreeNode* node) {
   if (node != NULL) {
      FreeHelper(node->left);
      FreeHelper(node->right);
      delete node;
   }
}

bool MyBST::FindHelper(TreeNode* node, int x) {
    //If the current node is null and the value has not been found,
    //it does not exists in the BST. Return false.
    if(node == NULL){
        return false;
    }
    //if the current node's value is equal to the value being searched for,
    //it exists in the BST. Return true.
    else if(node->value == x){
        return true;
    }
    //if the current node's value is less than the value being searched for,
    //then we need to check the right child node, so return the value from a recursive
    //call to the right child node with the value being searched for
    else if(node->value < x){
        return FindHelper(node->right, x);
    }
    //if the current node's value is not less than the value being searched for,
    //then we need to check the left child node, so return the value from a recursive
    //call to the left child node with the value being searched for
    else{
        return FindHelper(node->left, x);
    }
}


bool MyBST::Find(int x) {
   return FindHelper(root, x);
}

//void MyBST::InsertHelper(TreeNode* node, int x) {  // use this one if you want to implement InsertHelper without passing a pointer by reference. 
void MyBST::InsertHelper(TreeNode*& node, int x) {
    //If the node does not exist, create a new node in the place of the
    //nonexistent node with the value of x to maintain BST property
    if(node == NULL){
        TreeNode *newNode = new TreeNode;
        newNode->value = x;
        newNode->right = NULL;
        newNode->left = NULL;
        node = newNode;
    }
    //If x > the current node's value, then go to the
    //current node's right child node in a recursive call
    else if(x > node->value){
        InsertHelper(node->right, x);
    }
    //If x < the current node's value, then go to the
    //current node's left child node in a recursive call
    else if(x < node->value){
        InsertHelper(node->left, x);
    }
    //If x is equal to the current node's value,
    //then the node already exists and a message is output
    else if (x == node->value){
        cout << x << " already exists. No new node has been inserted.\n";
    }
}

// use this one if you want to implement InsertHelper without passing a pointer by reference. 
/*
void MyBST::Insert(int x) {
   if (root != NULL) {
      InsertHelper(root, x);
   } else {
      root = new TreeNode;
	  root->value = x;
	  root->right = NULL;
	  root->left = NULL;
   }
}
*/

void MyBST::Insert(int x) {
   InsertHelper(root, x);
}


void MyBST::Preorder(TreeNode* node){
    //if the current node is not null, then output the node's value
    //recurively call the left child node and do the same. When that call is complete,
    //recursively call the right child node and do the same.
    if(node != NULL){
        cout << " " << node->value << " ";
        Preorder(node->left);
        Preorder(node->right);
    }
}

void MyBST::PreorderTraversal() {
   Preorder(root);
   cout << endl;
}


void MyBST::Postorder(TreeNode* node) {
    //if the current node is not null, recusrively call the left child node. When
    //that call is comeplete, recursively call the right child node. When that call
    //is complete, output the current node's value.
    if(node != NULL){
        Postorder(node->left);
        Postorder(node->right);
        cout << " " << node->value << " ";
    }
}

void MyBST::PostorderTraversal() {
   Postorder(root);
   cout << endl;
}


void MyBST::Inorder(TreeNode* node) {
    //if the current node is not null, recursively call the left child node. When
    //that call is complete, output the current node's value. Then recursively call
    //the right child node.
    if(node != NULL){
        Inorder(node->left);
        cout << " " << node->value << " ";
        Inorder(node->right);
    }
}

void MyBST::InorderTraversal() {
   Inorder(root);
   cout << endl;
}


int main() 
{ 
   MyBST test_tree;
   
   int user_input = 0;
	
   while (user_input != -1) {
      cout << "Inserting a new node...." << endl;
      cout << "Please enter an integer between 0 and 99 as a value to insert, ";
      cout << "or enter -1 to stop inserting and see the resulting tree: ";
      cin >> user_input;
      if (user_input >= 0 && user_input <= 99)
         test_tree.Insert(user_input);
      else if (user_input != -1)
         cout << "Invalid input value (" << user_input << ") !" << endl;
   }

   cout << "Preorder Traversal: ";
   test_tree.PreorderTraversal();
   cout << "Postorder Traversal: ";
   test_tree.PostorderTraversal();
   cout << "Inorder Traversal: ";
   test_tree.InorderTraversal();

   user_input = 0;
	
   while (user_input != -1) {
      cout << "Searching a value...." << endl;
      cout << "Please enter an integer between 0 and 99 as a value to search, ";
      cout << "or enter -1 to stop searching: ";
      cin >> user_input;

      if (user_input >= 0 && user_input <= 99) {
         if(test_tree.Find(user_input))
            cout << user_input << " is in this BST." << endl;
         else {
            cout << user_input << " is not in this BST." << endl;
         }
      }
      else if (user_input != -1)
         cout << "Invalid input value (" << user_input << ") !" << endl;
   }
   return 0;
}  
