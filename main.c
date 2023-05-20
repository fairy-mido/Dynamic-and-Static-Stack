#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(void)
{
    int choice = 1, alloc_choice = 1;
    while(alloc_choice)
    {
        choice = 1;
        printf("-------------------------------------\n");
        printf("1. Stack Static Memory Allocation 2. Stack Dynamic Memory Allocation\n");
        printf("0. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter Which you need to use!\n");
        scanf("%d", &alloc_choice);
        printf("-------------------------------------\n");
        if (alloc_choice)
        {
            while (choice)
            {
                printf("1- Push 2- Pop 3- Display 4- Peek 0- Exit\n");
                printf("-------------------------------------\n");
                printf("Enter Number Preceeding the operation Needed!\n");
                scanf("%d", &choice);
                printf("-------------------------------------\n");

                if(choice == Push)
                {
                    push(alloc_choice);
                }
                else if(choice == Pop)
                {
                    pop(alloc_choice);
                }
                else if(choice == Display)
                {
                    display(alloc_choice);
                }
                else if(choice == Peek)
                {
                    peek(alloc_choice);
                }
                
            }
        }
    }
    printf("End of Code :>\n");
    return 0;
}