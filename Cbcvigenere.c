//
//
// Cbcvigenere.c
//
// University of Central Florida
// CIS3360 - Fall 2017
// Program Author: J'lin Rose
//
//  Created by J'lin Andreaz Rose on 10/7/17.
//  Copyright © 2017 J'lin Rose. All rights reserved.
//
//Include my standard library,input/output,definition and string
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


const int size = 4991;


 //This plaintext function will change all of the uppercase letters to lowercase and convert it to plaintext
char *plainT(char *textData)
{

    //alocating space for the data being stored in
    char *temp = (char *)malloc(size);
    int i = 0;
    int j = 0;

    //
    for(i = 0; i < strlen(textData); i++)
    {
        if(textData[i] >= 'A' && textData[i] <= 'Z')
        {
            textData[i] = textData[i] - 'A' + 'a';
        }


        if (textData[i] >= 'a' && textData[i] <= 'z')
        {
            temp[j++] = textData[i];
        }
    }
    temp[j] = 0;

    return temp;
}

/*Function encrypts plaintext into ciphetext.
 Char vector is actually the IV(initialization vector)*/
 //This is the encryption funcion which will encrypt the plaintext into cophetext
int encryption(char *textData, char *key, char *iv, int j , int*q){

    //len of inputs from user
    int length = strlen(key);
    int datalen = strlen(textData);
    char *encrypt = (char *)malloc(length);
    int i = 0;
    int new=0;
    q=new;

    for(i = j; i < j + length; i++)
    {

        if(i >= datalen){//used for padding the last block

        textData[i] = 'x';

        //This is statement is added to keep count of how much paddin is added by incrementing the counter each tme an x appears
        if(textData[i] = 'x'){
        new++;
        }
        else
        textData[i] = ((textData[i] - 'a' + key[i - j] - 'a' + iv[i - j]- 'a') % 26) + 'a';//formula for encryption
    }

    return i >= datalen ? 0:1;
}
}
//This the main function
int main(int argc,char **argv){

    int i = 0;
    int pad;
    int *p;
    int a = 0;
    int **q;

    //This program needs 4 command arguments
    if(argc == 4)
    {

        //This is what will open my text file and attempt to read it
        FILE *txt = fopen(argv[1], "r");
        //If the text is null then file didn't open properly or there were not enough comman line arguments
        if(txt == NULL)

        printf("Need more Argumens");
        //If this else statement works,then the file was read and there are enough arguments
        else if(txt != NULL)
        {

            printf("CBC Vigenere by J'lin Rose\n");

            //This will display the file name that was entered for the command line
            printf("Plaintext file name: %s\n", argv[1]);
            //Print keyword from argument 2
            printf("Viginere keyword: %s\n", argv[2]);
            //Prints out initialazion vector from argument 3
            printf("Initialization vector: %s", argv[3]);
            //Allocating siz for textData
            char *textData = (char *)malloc(size);

            //fread reads my plaintext for data
            fread(textData, sizeof(char), size, txt);
            textData = plainT(textData);

            printf("\n\nClean Plaintext:\n\n%s", textData);

            //This if and while statement will go through the encription and get the cyphertext
            if(encryption(textData, argv[2], argv[3], i , q ))
            {
                i += 6;
                while(encryption(textData, argv[2], textData + (i - 6), i , q))
                i += 6;
            }
            //displays cipher data
            printf("\n\nCiphertext:\n\n%s\n\n", textData);
            //Print number of character from plaintext recieved from i
            printf("Number of characters in clean plaintext file: %d\n", i);


        }
        //Blocksize is the length of argument two
        printf("Block size: %d\n", strlen(argv[2]));

       //here the number of padding should equal the counter retrived from encryption function
        printf("Number of pad characters added: %d \n ",  p);
        //closes the text file
        fclose(txt);
}
//end of program
    return 0;
}


