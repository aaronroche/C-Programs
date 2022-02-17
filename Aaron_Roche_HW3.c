/*
 ============================================================================
 Name        : Aaron_Roche_HW3.c
 Author      : Aaron Roche
 Version     : 1
 Description : C program that creates an array and randomly switches the
               pointers of the array and returns a random element.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Invalid number of arguments");
        return 1;
    }

    int nRow = (int) strtol(argv[1], NULL, 10);
    int nCol = (int) strtol(argv[2], NULL, 10);

    int* board = (int*) malloc (nRow * nCol * sizeof(int));

    for (int r = 0; r < nRow; r++)
    {
        for (int c = 0; c < nCol; c++)
        {
            int* whereOnBoard = board + (r * nCol) + c;
			*whereOnBoard = (3 * r) + (5 * c);
        }
    }

    printf("Original\n");
    for(int r = 0; r < nRow; r++)
    {
        for(int c = 0; c < nCol; c++)
        {
            printf("%d ", *(board + (r * nCol) + c));
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < (nRow * nCol); i++)
    {
        int randRow = rand() % nRow;
        int randCol = rand() % nCol;

        int* swapA = board + (randRow * nCol) + randCol;
        int* swapB = board + (((randRow + 1) % nRow) * nCol) + ((randCol - 1) % nCol);

        int temp = *swapA;
        *swapA = *swapB;
        *swapB = temp;
    }


    printf("Swapped\n");
    for(int r = 0; r < nRow; r++)
    {
        for(int c = 0; c < nCol; c++)
        {
            printf("%d ", *(board + (r * nCol) + c));
        }
        printf("\n");
    }
    printf("\n");

    int randRow = rand() % nRow;
    int randCol = rand() % nCol;

    int* val = board + (randRow * nCol) + randCol;

    printf("Array value at row %i and column %i: %i\n", randRow, randCol, *val);
}

