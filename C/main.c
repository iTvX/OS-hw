/* Reference:
 * Passing multiple arguments to threaded function from pthread_create
 * https://stackoverflow.com/questions/16230542/passing-multiple-arguments-to-threaded-function-from-pthread-create
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// Since we only have 9 threads
int valid[9] = {0};

int source[9][9] = {
        {6, 2, 4, 5, 3, 9, 1, 8, 7},
        {5, 1, 9, 7, 2, 8, 6, 3, 4},
        {8, 3, 7, 6, 1, 4, 2, 9, 5},
        {1, 4, 3, 8, 6, 5, 7, 2, 9},
        {9, 5, 8, 2, 4, 7, 3, 6, 1},
        {7, 6, 2, 3, 9, 1, 4, 5, 8},
        {3, 7, 1, 9, 5, 6, 8, 4, 2},
        {4, 9, 6, 1, 8, 2, 5, 7, 3},
        {2, 8, 5, 4, 7, 3, 9, 1, 6}
};

// Set the struct so that pthread_create can call multiple argument
struct myParam{
    int row;
    int column;
};

void *validator(void *arg) {
    struct myParam *recv_para;
    recv_para = (struct myParam *) arg;
    int row = recv_para->row;
    int col = recv_para->column;
    //Set the sum of product and Add.
    int sumOfAdd = 0;
    int sumOfProduct = 1;

    int i, j;
    for (i = row; i < row + 3; i++) {
        for (j = col; j < col + 3; j++) {
            int num = source[i][j];
            sumOfAdd += num;
            sumOfProduct *= num;
        }
    }
    //45 and 362880 is given by the instruction (A2.pdf)
    if (sumOfAdd == 45 && sumOfProduct == 362880) {
        valid[row + col/3] = 1;
        pthread_exit(NULL);
    }
    return NULL;
}




int main() {
    pthread_t threads[9];
    int index = 0;
    int i,j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (i%3 == 0 && j%3 == 0) {
                struct myParam *data = (struct myParam *) malloc(sizeof(struct myParam));
                data->row = i;
                data->column = j;
                pthread_create(&threads[index++], NULL, validator, data);
            }
        }
    }

    for (i = 0; i < 9; i++) {
        pthread_join(threads[i], NULL);
    }


    for (i = 0; i < 9; i++) {
        if (valid[i] == 0) {
            printf("Invalid!\n");
            return -1;
        }
    }
    printf("Valid!\n");
    return 0;
}