/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node_t;

node_t *head = NULL;

node_t* getNewnode(int x)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = x;
    printf("Address of the newNode(%d) 0x%x\n",x,newNode);
   return newNode;
}

void insertNodeAtend(int x)
{
    node_t * trav = head;
    node_t *newNode = getNewnode(x);
    if (trav == NULL)
    {
        //this is the empty node location
        head = newNode;        
    }
    else
    {
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = newNode;
        newNode->prev = trav;
    }
}
void InsertAtFirst(int x)
{
    node_t *newNode = getNewnode(x);
    newNode->next = head;
    head = newNode;
}

void deleteEndNode(void)
{
    node_t * trav = head;
    if (trav == NULL)
    {
        //this is the empty node location
        printf("DLL is empty");
    }
    else
    {
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->prev->next = NULL;
        free(trav);
    }
}

void deleteStartNode(void)
{
    node_t * trav = head;
    if (trav == NULL)
    printf("DLL is empty");
    else
    {
        head = head->next;
        free(trav);
    }
}
void AddDeleteAtPosition(int x, unsigned pos, _Bool Isdelete)
{
    node_t  * trav  = head;
    unsigned localPostion = 0;
    if (trav == NULL)
    {
        printf("DLL is empty");
    }
    else if ( pos > 0)
    {
        // if not null means this is the first node
        while (trav->next != NULL)
        {
            localPostion++;
            if (localPostion == pos)
            {
                if (Isdelete == 1)
                {
                    // delete the current node
                    trav->prev->next = trav->next;
                    trav->next->prev = trav->prev;
                    free(trav);
                }
                else
                {
                    //add new node at this position
                    node_t *newNode = getNewnode(x);
                    node_t *copyNext = trav->next;
                    newNode->prev = trav;
                    trav->next = newNode;
                    newNode->next = copyNext;
                }
                break;
            }
            trav = trav->next;
        }
    }
    else
    {
        printf("Invalid postion");
    }
}

void printAllNode()
{
    node_t * node = head;
    if (node == NULL)
    printf("DLL empty");
    else
    {
        //printf("node->data %d\n",start->data);
        while(node->next != NULL)
        {
            printf("node->data=%d node->prev=0x%x node->next=0x%x\n",node->data, node->prev, node->next );
            node = node->next;
        }
        // print the data of the last node
        printf("node->data=%d node->prev=0x%x node->next=0x%x\n",node->data, node->prev, node->next );
    }
}
int main()
{
    InsertAtFirst(1);
    insertNodeAtend(2);
    insertNodeAtend(3);
    insertNodeAtend(4);
    printAllNode();
    AddDeleteAtPosition(12,3,0);
    printAllNode();
    AddDeleteAtPosition(12,3,1);
    printAllNode();
    return 0;
}



//Console Output:

//Address of the newNode(1) 0x13d1010                                                                                     
//Address of the newNode(2) 0x13d1030                                                                                     
//Address of the newNode(3) 0x13d1050                                                                                     
//Address of the newNode(4) 0x13d1070                                                                                     
//node->data=1 node->prev=0x0 node->next=0x13d1030                                                                        
//node->data=2 node->prev=0x13d1010 node->next=0x13d1050                                                                  
//node->data=3 node->prev=0x13d1030 node->next=0x13d1070                                                                  
//node->data=4 node->prev=0x13d1050 node->next=0x0                                                                        
//Address of the newNode(12) 0x13d1090                                                                                    
//node->data=1 node->prev=0x0 node->next=0x13d1030                                                                        
//node->data=2 node->prev=0x13d1010 node->next=0x13d1050                                                                  
//node->data=3 node->prev=0x13d1030 node->next=0x13d1090                                                                  
//node->data=12 node->prev=0x13d1050 node->next=0x13d1070                                                                 
//node->data=4 node->prev=0x13d1050 node->next=0x0                                                                        
//node->data=1 node->prev=0x0 node->next=0x13d1030                                                                        
//node->data=2 node->prev=0x13d1010 node->next=0x13d1090                                                                  
//node->data=12 node->prev=0x13d1030 node->next=0x13d1070                                                                 
//node->data=4 node->prev=0x13d1050 node->next=0x0 
