#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int rows = 3;
const int cols = 3;
int testsGenerated = 0;

int checkMagicSquare(int arr[rows][cols]){
    int diagonalSum = 0;
    int diagonalSum2 = 0;
    for(int i = 0; i < rows; i++){
        int rowSum = 0;
        int colSum = 0;
        for(int j = 0; j < cols; j++){
            //check sum of rows 1, 2, and 3.
            rowSum += arr[i][j];
            //check sum of cols 1, 2, and 3.
            colSum += arr[j][i];
        }
        diagonalSum += arr[i][i];
        diagonalSum2 += arr[abs(i - 2)][i];
        if(rowSum == 15 && colSum == 15)
            continue;
        else{
            return 0;
        }
    }
    if (diagonalSum == 15 && diagonalSum2 == 15){
        return 1; //if all checks out then return 1
    }
    return 0;
}

int findMagicSquare(int arr[rows][cols]){
    int counter = 0;
    int repeat = 1;
    int tempArr[9];
    int k, temp;

    //copy over 2d array into a 1d array
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            tempArr[counter] = arr[i][j];
            counter++;
        }
    }

    //randomize the 1d array
    for(int i = 0; i < 9; i++)
    {
        k = (rand() % 8) + 1;
        temp = tempArr[i];
        tempArr[i] = tempArr[k];
        tempArr[k] = temp;
    }

    //copy over 1d array over to 2d array
    k = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = tempArr[k++];
        }
    }

    testsGenerated++;
    if(checkMagicSquare(arr) == 1){
        //Print total # of squares generated and how many times randomized.
        printf("Squares Generated: %d\nCount of Randomization: %d\n", testsGenerated * 9, testsGenerated);
        //Print Lo Shu Magic Square in a specific format.
        for(int i = 0; i < rows; i++){
            printf("[");
            for(int j = 0; j < cols; j++){
                printf("%d", arr[i][j]);
                if(j != 2)
                    printf(" ");
            }
            printf("]\n");
        }
        return 1;
    }

    return 0;
}

int main(void){
    time_t t;
    srand((unsigned) time(&t));

    int arr[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };
    int arr2[3][3] = {
        {4, 1, 2},
        {3, 5, 7},
        {8, 9, 6}
    };

    if(checkMagicSquare(arr) == 1)
        printf("A Lo Shu Magic Square!\n");
    else
        printf("Not a Lo Shu Magic Square. :(\n");

    if(checkMagicSquare(arr2) == 1)
        printf("A Lo Shu Magic Square!\n");
    else
        printf("Not a Lo Shu Magic Square. :(\n");

    while(findMagicSquare(arr) == 0){
        findMagicSquare(arr);
    }
    
    return EXIT_SUCCESS;
}