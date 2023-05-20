#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/* This Code uses
      1. Static Memory Allocation (Array)
      2. Dynamic Memory Allocation (Linked List) Using DLL

    -> First Top is where the last Element Exists..
    -> Concept of Stack: Last In First Out (LIFO) Or First In Last Out (FILO) :>
*/

// Static Defintions
int Stack[Stack_Limit];
int top = -1;

// Dynamic Defintions
Dyn_Stack *bot, *top_ptr, *temp, *current, *previous;
int elements_number = 0;

void push(int choice_allocation)
{

    if (choice_allocation == Choice_Static)
    {
        int data;
        printf("Enter Data To be Stored\n");
        scanf("%d", &data);
        printf("-------------------------------------\n");
        if (top == (Stack_Limit - 1))
        {
            printf("OverFlow, Stack is Full!\n");
            printf("-------------------------------------\n");
        }
        else
        {
            top++;
            Stack[top] = data;
        }
    }
    else if (choice_allocation == Choice_Dynamic)
    {
        Dyn_Stack data_entered;
        if (elements_number > Stack_Limit)
        {
            printf("OverFlow! Stack is Full\n");
            printf("-------------------------------------\n");
        }
        else
        {
            printf("Enter Data to be Stored\n");
            scanf("%d", &data_entered.data);
            printf("-------------------------------------\n");
            if (bot == NULL) // Bot is the first to create the DLL using Stack
            {
                // No element in the stack
                current = (Dyn_Stack *)malloc(sizeof(Dyn_Stack));
                current->data = data_entered.data;
                current->next = NULL;
                current->prev = NULL;
                bot = top_ptr = current;
                elements_number++;
            }
            else
            {
                current = (Dyn_Stack *)malloc(sizeof(Dyn_Stack));
                current->data = data_entered.data;
                previous = top_ptr;
                // while (previous->next != NULL)
                // {
                //     previous = previous->next;
                // }
                // previous->next = current;
                // current->prev = previous;
                current->next = previous;
                previous->prev = current;
                current->prev = NULL;
                top_ptr = current;
                elements_number++;
            }
        }
    }
}

void pop(int choice_allocation)
{
    int data_popped;
    if (choice_allocation == Choice_Static)
    {
        if (top == -1)
        {
            printf("Stack is Empty\n");
            printf("-------------------------------------\n");
        }
        else
        {
            data_popped = Stack[top];
            top--;
            printf("Popped Data %d\n", data_popped);
            printf("-------------------------------------\n");
        }
    }
    else if (choice_allocation == Choice_Dynamic)
    {
        if (top_ptr == NULL)
        {
            printf("Stack is Empty!\n");
            printf("-------------------------------------\n");
        }
        else
        {
            temp = top_ptr;
            top_ptr = top_ptr->next;
            temp->next = NULL;
            printf("Data Popped is %d\n", temp->data);
            printf("-------------------------------------\n");
            free(temp);
            temp = NULL;
            elements_number--;
        }
    }
}

void display(int choice_allocation)
{
    int i, data_display;
    if (choice_allocation == Choice_Static)
    {
        if (top == -1)
        {
            printf("Stack is Empty!\n");
            printf("-------------------------------------\n");
        }
        else
        {
            for (i = top; i > -1; i--)
            {
                data_display = Stack[i];
                printf("Data No.%d is %d\n", (i + 1), data_display);
                printf("-------------------------------------\n");
            }
        }
    }
    else if (choice_allocation == Choice_Dynamic)
    {
        temp = top_ptr;
        // printf("skfjdsljdslk\n");
        // printf("%d %d \n",temp,bot);
        int i, k;
        i = elements_number;
        if (temp == NULL)
        {
            printf("Stack is Empty!\n");
            printf("-------------------------------------\n");
        }
        else
        {
            while ((temp) != NULL)
            {
                printf("Data No.%d is %d\n", i--, temp->data);
                printf("-------------------------------------\n");
                // printf("-----------------------\n");
                temp = temp->next;
            }
        }
    }
}

void peek(int choice_allocation)
{
    if (choice_allocation == Choice_Static)
    {
        if (top == -1)
        {
            printf("Stack is Empty!\n");
            printf("-------------------------------------\n");
        }
        else
        {
            printf("Top Data is %d\n", Stack[top]);
            printf("-------------------------------------\n");
        }
    }
    else if (choice_allocation == Choice_Dynamic)
    {
        if (top_ptr == NULL)
        {
            printf("Stack is Empty!\n");
            printf("-------------------------------------\n");
        }
        else
        {
            printf("Peek Value is %d\n", top_ptr->data);
            printf("-------------------------------------\n");
        }
    }
}
