#include<iostream>
#include<cstdlib>

using namespace std ;

// node struct

struct node {
	int data ;
	node *next ;
};

// noral insert after head

node* insertHead(node *head,int dt){
	node *ptr = head , *newnode = new node();
	newnode->data = dt ;
	newnode->next = NULL ;
	
	if(ptr == NULL ){
		head = newnode ;
	}
	else {
		while(ptr->next != NULL){
		ptr = ptr->next ;
		}
		ptr->next = newnode;
	}
	return head ;
}

// insert in sort order to maintain the ascending order in the linked list

void sortedInsert(node** head, int data)  
{  
	node* newnode = new node();
	newnode->data = data ;
	newnode->next = NULL ;

    node* current;  
    
    if (*head == NULL || (*head)->data >= newnode->data)  
    {  
        newnode->next = *head;  
        *head = newnode;  
    }  
    else
    {  
        current = *head;  
        while (current->next!=NULL && current->next->data < newnode->data)  
        {  
            current = current->next;  
        }  
        newnode->next = current->next;  
        current->next = newnode;  
    }  
}  

// Merging two linked lists

node *sortedMerge(node *head1, node *head2){
	node *result = NULL ;
	if(head1 == NULL ) 
		return head2 ;
	if(head2 == NULL)
		return head1 ;
	
	if(head1->data <= head2->data){
		result = head1 ;
		result->next = sortedMerge(head1->next,head2);
	}else {
		result = head2 ;
		result->next  = sortedMerge(head2->next,head1);
	}
	return result ;
}

// displaying the list

void displayList(node *head){
	node *ptr  ;
	for(ptr = head ; ptr!=NULL ; ptr=ptr->next){
		cout<<ptr->data<<"-->";
	}
	cout<<endl;
}

int main(){
	node *head1 = NULL , *head2 = NULL;
	
	// List 1
	sortedInsert(&head1,3);
	sortedInsert(&head1,4);
	sortedInsert(&head1,6);
	
	// list 2 
	sortedInsert(&head2,-8);
	sortedInsert(&head2,9);
	sortedInsert(&head2,50);
	
	// To use multiple more than 2 linked lists a 2d array with node* data structure is required to store the starting address of all linked lists.

	displayList(head1);
	displayList(head2);
	
	// final list
	node *head3 = sortedMerge(head1,head2);
	displayList(head3);
	return 0 ;
}