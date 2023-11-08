#include <iostream>
#include "listnode.h"

using namespace std; 

Node* MergeLists(Node* head1, Node* head2) {
   // TODO 
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
   
   return 0;
}