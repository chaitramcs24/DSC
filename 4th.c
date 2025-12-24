#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*head=NULL;

struct node * create(int value)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    return temp;
};
void insert_begin(int value)
{
    struct node*newnode;
    newnode=create(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void insert_end(int value)
{
    struct node*newnode,*temp;
    newnode=create(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }

}

int count()
{
    struct node*temp;
    int i=1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return(i);
}
void insert_pos(int value,int pos)
{

    struct node*newnode,*temp1,*temp2;
    int i,c=1;
    newnode=create(value);
    i=count();
    if(pos==1)
        insert_begin(value);
    else if(pos>i+1)
    {
        printf("insertion is not possible");
        return;
    }
    else{
        temp1=head;
        while(c<=pos-1&&temp1!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
            c++;

        }
        newnode->next=temp2->next;
        temp2->next=newnode;
    }
}




void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}




int main() {
    printf("NAME:CHAITRA M \n");
    printf("USN:1BM24CS078 \n");
    insert_begin(10);
    insert_end(20);
    insert_end(30);
    insert_pos(15, 2);
    display();

    printf("Total nodes: %d\n", count());
    return 0;
}

