/*
 * University of Central Florida
 * CIS 3360 - Fall 2017
 * Author: J'lin Rose
 */

/*
 For this assignment, you will write a program that will attempt to recover a salted and hashed password using a file of candidate passwords.
 The file could be interpreted as either a list of easy passwords that a proactive password checker would wish to exclude,
 or possibly as a list of possible passwords that an attacker would wish to use for matching against a possibly stolen hashed password file.
 The inputs to the program will be a dictionary file of candidate passwords and a numerical hash value that you will need to examine.
 You will also know in advance the hash algorithm to use and how passwords are salted before they are hashed.
 */


/*This is my standard input.output,library,string library,athand ctype*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

long int conversion (char *password)
{
    long j;
    
    j = atol(password);
    
    return j;
    
}
//This is my main function
int main(int argc, char *argv[])
{
    
    char fName[40];//filename
    
    char in[7];//input
    
    char *pw;
    char *vASCII;
    char *cv;
    
    int len = 7;     // this is the password length
    int asciiLength = 12;
    int ent = 1000; // max #of entries
    int dec;//decimal
    
    int i;
    int counter = 0;
    int index = 1;
    long j;
    long hVal;
    
    FILE *ftp;
    
    //This is the header for the program and actaully the password recovery action
    printf("---------------------------------------------------");
    printf("\n");
    printf("CIS3360 Password Recovery by J'lin Rose \n\n");
    
    strcpy(fName, argv[1]);
    
    printf("   Dictionary file name       : %s \n",fName);
    
    hVal = atol(argv[2]);
    
    printf("   Salted password hash value : %d \n", hVal);
    
    printf("\n");
    
    printf("Index   Word   Unsalted ASCII equivalent \n");
    
    printf("\n");
    
   
    
    //checks if the file is a txt file or not
    if ((strcmp(fName,"txt"))== 0)
    {
        fName[strlen(fName)+5];
        
        strcat(fName, ".txt");
    }
    
    //If the file has an error opening or reading then you will see the error
    if ((ftp = fopen(fName, "r")) == NULL)
    {
        printf("Could not open file. \n");
        
        return 0;
    }
    //Open and read the file
    ftp = fopen(fName, "r");
    
    
    //The malloc is dynamically allocating the size of password
    pw = malloc(sizeof(*pw) * len);
    cv = malloc (sizeof(*cv) * 14);
    vASCII = malloc (sizeof(*vASCII) * 14);
    
    //This is a while loop thank will show and print the values
    
    while (fscanf(ftp, "%s", in) != EOF)
    {
        strcpy(pw, in);
        printf(("%4d :  %s "), index++, pw);
        
        for(i = 0; i < 6; i++)
        {
            dec = pw[i];
            printf("%d",dec);
        }
        
        printf("\n");
    }
    
    
  
    //This closes the file that I was reading
    
    fclose(ftp);
    
    //This is the end of the program
    return 0;
}
