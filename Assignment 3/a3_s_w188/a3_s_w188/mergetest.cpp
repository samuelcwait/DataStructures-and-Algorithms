#include <iostream>
#include "listnode.h"

using namespace std; 

Node* MergeLists(Node* head1, Node* head2) {
    //if statements below check if the next node is NULL in either linked list as base case,
    //returns the other head node if true.
    
    if(!head1){return head2;}
    if(!head2){return head1;}
    
    //if-else statement contains recursive calls based on which value of the current
    //two nodes is higher and passes the next node of the respective linked list
    //to the next recursive layer, therefore proceeding to each layer in the
    //peroper order. Once the next node is NULL, the base case has
    //been reached and the function will return the other list's node,
    //merging the nodes in the proper order as ascending each recrusive layer
    
    if(head1->value < head2->value){
        head1->next = MergeLists(head1->next, head2);
        return head1;
    }
    else{
        head2->next = MergeLists(head1,head2->next);
        return head2;
    }
}

int main() {
   // Create two sorted lists
   ListNode list1;
   ListNode list2;

   int val; 
   
   // Prompt the user to populate the lists 
   cout << "Type in an integer to insert to list1, e.g., 1,2,3,... (-1 to quit): "; 
   do {
      cin >> val; 
      if (val != -1) {
         list1.AddNode(val);
      }
   } 
   while(val != -1);

   cout << "Type in an integer to insert to list2, e.g., 1,2,3,... (-1 to quit): "; 
   do {
      cin >> val; 
      if (val != -1) {
         list2.AddNode(val); 
      }
   }
   while(val != -1); 
  

   // Display the lists 
   cout << "List 1: ";
   list1.Display(); 
   cout << "List 2: "; 
   list2.Display(); 

   // Merge two lists
   Node* merge_list  = MergeLists(list1.GetHeadNode(), list2.GetHeadNode()); 

   // Display the merged list 
   Node *current = merge_list; 
   cout << "Merge List: "; 
   while (current != nullptr) {
      cout << current->value << " "; 
      current = current->next; 
   }
    cout << endl;
   return 0;
}
