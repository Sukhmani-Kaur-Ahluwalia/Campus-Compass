#include <iostream>
#include <cstdio.h>
#include <cstdlib.h>
#include "File_Func.h"
void writeInt(int a, char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
    printf("Error opening the file.\n");
    else
    fprintf(f, "%d\n", a);
    fclose(f);
    //f=NULL;
}

void writeString(char a[], char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
    printf("Error opening the file.\n");
    else
    fprintf(f, "%s\n", a);
    fclose(f);
  // f=NULL;
}

void writeStringQues(char a[], char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
    printf("Error opening the file.\n");
    else
    fprintf(f, "%s\n", a);
    fclose(f);
  // f=NULL;
}

void writeChar(char c, char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL) printf("Error opening the file.\n");
    else
    {
        fprintf(f, "%c", c);
    }
   fclose(f);
   //f=NULL;
}

void readInt(FILE *f, int *a, int *eof)
{
    if (fscanf(f, "%d", a) == 1)
    {
        *eof = 0; // Integer read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
    }
}

int readStringName(FILE *f, char a[], int *eof)
{
    if (fscanf(f, " %s[^\n]", a) == 1)
    {
        fgetc(f);
        return 1; // String read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
        return 0;
    }
}

int readString(FILE *f, char a[], int *eof)
{
    if (fscanf(f, " %s[^\n]", a) == 1)
    {
        return 1; // String read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
        return 0;
    }
}

int readStringAllChar(FILE *f, char a[], int *eof)
{
    if (fscanf(f, " %[^\n]", a) == 1)
    {
        return 1; // String read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
        return 0;
    }
}

void readChar(FILE *f, char *a, int *eof)
{
    if (fscanf(f, " %c", a) == 1)
    {
        *eof = 0; // Character read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
    }
}
void writeBlock(char fname[], int start_id, int end_id, int weight)
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
        printf("Error opening the file.\n");
    else
    {
        fprintf(f, "%d %d %d\n", start_id, end_id, weight);
    }
    fclose(f);
}

int readNBlocks(char fname[], int* start_id, int* end_id, int* weight, int *eof)
{
    static FILE *f = NULL;
    if (f == NULL)
    {
        f = fopen(fname, "r");
        if (f == NULL)
        {
            printf("Error opening the file for reading blocks.\n");
            *eof = 1;
            return 0;
        }
    }
    int i,j;
    for (i = 0; i < 1; i++) // Reading one block of information at a time
    {
        if (fscanf(f, "%d %d %d", start_id, end_id, weight) == EOF)
        {
            *eof = 1;
            fclose(f);
            f = NULL;
            return i;
        }
        for(j=0;p[i].name[j]!='\0';j++)
        {
            if(p[i].name[j]=='$')
            p[i].name[j]=' ';
        }
    }
    return 1;
}
