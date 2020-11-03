#include <stdio.h> 
#include <stdlib.h> 
  
struct List { 
    int data; 
    struct List* next; 
}; 
  
// This function prints contents of linked list starting from 
// the given node 
void printList(struct List* n) 
{ 
    while (n != NULL) { 
        printf("%d\n", n->data); 
        n = n->next; 
    } 
} 

int checkIfDataExists(struct List* head, int x){
    while (head != NULL) { 
        //printf("%d\n", head->data); 
        
        if( head->data == x ){
            printf("Die Data: %d existiert schon!\n", x);
            return 1;
        }

        head = head->next; 
    }
    return 0;
}

void listeAdd(struct List* head, int data){
    struct List* new = (struct List*)malloc(sizeof(struct List)); 

    //finde das letzte Item
    struct List* tail;
    while( head->next != NULL ){
        //printf("%d\n", head->data); 
        head = head->next;
    }

    tail = head;

    //printf("ENDE: %d\n", tail->data);
    
    //Neues Item hinzufügen:
    new->data=data;
    new->next=NULL;
    tail->next=new;
}

void testListe(){
    struct List* head = (struct List*)malloc(sizeof(struct List)); 
    
    for(int i=0; i<10;i++){
        //erstelle den Anfang
        if(i==0){
            head->data=i;
            i++;
        }

        listeAdd(head, i);
    }

    printf("head->data: %d\n", head->data);
    //printf("head->next: %int\n", head->next);
    if( head->next == NULL ){
        printf("NULL! \n");
    }

    printf("====================\n");

    printList(head);
    checkIfDataExists(head,7);
}
  
int main() 
{ 
    //struct List* head = NULL; 
    //
    //struct List* second = NULL; 
    //struct List* third = NULL; 
    //struct List* four = NULL; 
  //
    //// allocate 3 nodes in the heap 
    //head = (struct List*)malloc(sizeof(struct List)); 
    //second = (struct List*)malloc(sizeof(struct List)); 
    //third = (struct List*)malloc(sizeof(struct List)); 
  //
    //head->data = 1; // assign data in first node 
    //head->next = second; // Link first node with second 
  //
    //second->data = 2; // assign data to second node 
    //second->next = third; 
  //
    //third->data = 3; // assign data to third node 
    //third->next = NULL; 
    //
    ////TEST
    //four = (struct List*)malloc(sizeof(struct List)); 
    //four->data = 4;
    //four->next = NULL;
    
    //listeAdd(head, four);
    //

    //printList(head);

    testListe(); 
  
    return 0; 
}