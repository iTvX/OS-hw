/* Program Author: Zijie Yu
 * Date: 02/02/2020
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

//set the global variable. Each row for the table is 8 and and each column is 2.
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




//function group
void trans_ES(char userInput[], char *ES[][tableColumn]) {
    int i = 0;
    while (i < tableRow) {
        if (strcmp(ES[i][0], userInput) == 0) {
            printf("%s is an English word that translate as %s in Spanish.\n", userInput, ES[i][1]);
            return;
        }
        i++;
    }
    printf("%s is an English word that has no Spanish translation present in dictionary\n", userInput);
}

void trans_SE(char userInput[], char *ES[][tableColumn]) {
    int i=0;
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

    char userInput[100];
    char sourceLang[100];
    char destinationLang[100];
    char redo;
    while (1) {

        printf("Please enter a word to translate: ");
        scanf("%s", userInput);

        printf("Please enter the source language: ");
        scanf("%s", sourceLang);

        printf("Please enter the destination language: ");
        scanf("%s", destinationLang);

        //Extra credit part 1: implement to program case insensitive, user can use either capital letter or lower case letter.
        int i;
        for(i = 0; i < sizeof(userInput); i++)
            userInput[i] = tolower(userInput[i]);


        for(i = 0; i < sizeof(userInput); i++)
            sourceLang[i] = tolower(sourceLang[i]);


        for(i = 0; i < sizeof(userInput); i++)
            destinationLang[i] = tolower(destinationLang[i]);


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
        scanf(" %c", &redo);
        //extra credit part 2: "Handling misspellings or words that are not in the dictionary".
        while (redo != 'y' && redo != 'Y' && redo != 'n' && redo != 'N') {
            printf("Sorry, we don't understand you, please only enter one word. y(means yes) or n(means no). ");
            scanf(" %c", &redo);
        }
        if (redo == 'n' || redo == 'N') {
            break;
        }
    }
    return 0;
}