#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL, *last = NULL, *temp;

struct node* getnode(int x) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    return new;
}

void insertbeg(int x) {
    struct node *new = getnode(x);
    if (head == NULL) {
        head = last = new;
    } else {
        new->next = head;
        head = new;
    }
}

void insertend(int x) {
    struct node *new = getnode(x);
    if (head == NULL) {
        head = last = new;
    } else {
        last->next = new;
        last = new;
    }
}

void insertmid(int x, int key) {
    struct node *new = getnode(x);
    if (head == NULL) {
        printf("%d element is absent so insertion not possible\n", key);
        return;
    }
    temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d element is absent so insertion not possible\n", key);
    } else if (temp == last) {
        insertend(x);
    } else {
        new->next = temp->next;
        temp->next = new;
    }
}
void delete(int key) {
    if (head == NULL) {
        printf("Deletion not possible since no elements\n");
        return;
    }
    struct node *temp1 = head, *temp2 = NULL;
    while (temp1 != NULL && temp1->data != key) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp1 == NULL) {
        printf("Element not found\n");
        return;
    }
    if (temp2 == NULL) { // deleting head
        head = head->next;
        if (temp1 == last) last = NULL;
        free(temp1);
    } else {
        temp2->next = temp1->next;
        if (temp1 == last) last = temp2;
        free(temp1);
    }
}
void count()
{
    if(head==NULL)
    printf("no elements");
    else
    {
        int count;
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        printf("count: %d",count);
    }
}
int main() {
    insertbeg(12);
    display();
    insertend(23);
    display();
    insertmid(23, 12);
    display();
    delete(12);
    display();
    delete(23);
    display();
    insertbeg(45);
    display();
    insertend(46);
    display();
    count();
    delete(23);
    display();
    count();
    return 0;
}
