/* Program Author: Zijie Yu
 * Date: 02/02/2020
 *
 * 2 Extra credit part (5%) finished.
 *
 * Reference:
 * https://stackoverflow.com/questions/8004237/how-do-i-properly-compare-strings
 *For the reference above, I found how do I properly compare strings. So, in my code, I used strcmp() function to compare each word.
 * https://www.programiz.com/c-programming/library-function/string.h/strcmp
 *For this reference, I found how to use strcmp() function.
 */

#include <stdio.h>
#include<string.h>
#include <ctype.h>

//After I checked the given table, each row for the table is 8 and and each column is 2.
#define tableRow 8
#define tableColumn 2


//store vocabulary
char *esTable[tableRow][tableColumn] = {
        {"cat",    "gato"},
        {"dog",    "perro"},
        {"bird",   "pajaro"},
        {"mouse",  "raton"},
        {"cow",    "vaca"},
        {"tiger",  "tigre"},
        {"horse",  "caballo"},
        {"monkey", "mono"}
};

char *efTable[tableRow][tableColumn] = {
        {"cat",    "chat"},
        {"dog",    "chian"},
        {"bird",   "oiseau"},
        {"mouse",  "souris"},
        {"cow",    "vache"},
        {"tiger",  "tigre"},
        {"horse",  "cheval"},
        {"monkey", "singe"}
};

//Crate Translation function.
void trans_ES(char userInput[], char *ES[][tableColumn]) {
    int i = 0;
    while (i < tableRow) {
        //check the first column if can find user's input
        if (strcmp(ES[i][0], userInput) == 0) {
            printf("%s is an English word that translate as %s in Spanish.\n", userInput, ES[i][1]);
            return;
        }
        i++;
    }
    printf("%s is an English word that has no Spanish translation present in dictionary\n", userInput);
}

//same, but check the second column.
void trans_SE(char userInput[], char *ES[][tableColumn]) {
    int i = 0;
    while (i < tableRow) {
        if (strcmp(ES[i][1], userInput) == 0) {
            printf("%s is an Spanish word that translate as %s in English.\n", userInput, ES[i][0]);
            return;
        }
        i++;
    }
    printf("%s is an Spanish word that has no English translation present in dictionary\n", userInput);
}

void trans_EF(char userInput[], char *EF[][tableColumn]) {
    int i = 0;
    while (i < tableRow) {
        if (strcmp(EF[i][0], userInput) == 0) {
            printf("%s is an English word that translate as %s in French.\n", userInput, EF[i][1]);
            return;
        }
        i++;
    }
    printf("%s is an English word that has no French translation present in dictionary\n", userInput);
}

void trans_FE(char userInput[], char *EF[][tableColumn]) {
    int i = 0;
    while (i < tableRow) {
        if (strcmp(EF[i][1], userInput) == 0) {
            printf("%s is an French word that translate as %s in English.\n", userInput, EF[i][0]);
            return;
        }
        i++;
    }
    printf("%s is an French word that has no English translation present in dictionary\n", userInput);
}

//main function begin
int main() {
//create user input char
    char userInput[100];
    char sourceLang[100];
    char destinationLang[100];
    char redo[100];
    //Since I found C language doesn't have "true", so I use "1".
    while (1) {

        printf("Please enter a word to translate: ");
        scanf("%s", userInput);

        printf("Please enter the source language: ");
        scanf("%s", sourceLang);

        printf("Please enter the destination language: ");
        scanf("%s", destinationLang);

        //Extra credit part 1: implement to program case insensitive, user can use either capital letter or lower case letter.
        int i;
        for (i = 0; i < sizeof(userInput); i++)
            userInput[i] = tolower(userInput[i]);


        for (i = 0; i < sizeof(userInput); i++)
            sourceLang[i] = tolower(sourceLang[i]);


        for (i = 0; i < sizeof(userInput); i++)
            destinationLang[i] = tolower(destinationLang[i]);



//check user's input to find use which language translation and table.
        if (strcmp(sourceLang, "english") == 0 && strcmp(destinationLang, "spanish") == 0) {
            trans_ES(userInput, esTable);
        } else if (strcmp(sourceLang, "spanish") == 0 && strcmp(destinationLang, "english") == 0) {
            trans_SE(userInput, esTable);
        } else if (strcmp(sourceLang, "english") == 0 && strcmp(destinationLang, "french") == 0) {
            trans_EF(userInput, efTable);
        } else if (strcmp(sourceLang, "french") == 0 && strcmp(destinationLang, "english") == 0) {
            trans_FE(userInput, efTable);
        }

            //extra credit part 2: "Handling misspellings or words that are not in the dictionary".
        else {
            printf("I'm sorry! We have no %s to %s translation at this moment\n", sourceLang, destinationLang);
        }


        //user redo operation:
        printf("Do you want to translate a new word?(Y/N, only enter one word): ");
        scanf(" %s", redo);
        //change all char to the lowercase.
        for (i = 0; i < sizeof(redo); i++)
            redo[i] = tolower(redo[i]);
        //extra credit part 2: "Handling misspellings or words that are not in the dictionary".
        //if user input is y or n, the program will continue. If user input is not  y or n or more than 1 char,
        //the program will show the error message.
        while (redo[0] != 'y' && redo[0] != 'n' && redo[1] != '\0') {
            printf("Sorry, we don't understand you, please only enter one word. y(means yes) or n(means no): ");
            scanf(" %s", redo);
        }
        //if user input is N or n, the program would break.
        if (redo[0] == 'n') {
            break;
        }
    }
    return 0;
}