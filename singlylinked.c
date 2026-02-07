#include <stdio.h>
#include <stdlib.h>

struct node
 {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert() 
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Node inserted\n");
}

void delete() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;//next value becomes head n temp is left free
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
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
    int choice;
    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
			 break;
            case 2: delete(); 
			break;
            case 3: display();
			 break;
            case 4: printf("Exiting...\n"); 
			break;
            default: 
			printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

