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

void listeRemove(struct List* head, int data){
    struct List* delete = (struct List*)malloc(sizeof(struct List));

    //erstes Element löschen
    if( head->data == data ){
        printf("Gefunden 1: %d\n", data);
        head = head->next;
        //free(head);
    }

    //mehrere Elemente
    while( head->next != NULL ){
        printf("head: %d\n", head->data);
        
        //zu löschendes Item hat einen Nachfolger und Vorgänger
        if( head->next->data == data ){
            printf("Gefunden 2: %d\n", data);

            //Item aus der Liste entfernen
            //Nachfolger ermitteln
            delete = head->next;
            printf("Löschen: %d\n", delete->data);
            
            //Nachfolger neu verlinken
            head->next = delete->next;

            //Speicher frei geben:
            free(delete);
            return;
        }

        //zu löschendes Item hat keinen Nachfolger
        //else if( head->next->data == data && head->next == NULL ){
        //    printf("Gefunden else if: %d\n", data);
        //    
        //    //Item aus der Liste entfernen
        //    //Nachfolger ermitteln
        //    delete = head->next;
        //    printf("Löschen: %d\n", delete->data);
        //    
        //    //Speicher frei geben:
        //    free(delete);
        //    return;
        //}
        
        
        head = head->next;
        
    }


    
}

void testListe(){
    struct List* head = (struct List*)malloc(sizeof(struct List)); 
    
    for(int i=1; i<5;i++){
        //erstelle den Anfang
        if(i==1){
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
    
    printf("====================\n");

    listeRemove(head,1);
    listeRemove(head,2);
    listeRemove(head,3);
    listeRemove(head,4);
    
    printf("====================\n");
    printList(head);
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