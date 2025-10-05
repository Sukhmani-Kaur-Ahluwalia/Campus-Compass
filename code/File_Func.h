#ifndef FILE_FUNC_H_INCLUDED
#define FILE_FUNC_H_INCLUDED

void writeInt(int a, char fname[]);
void writeString(char a[], char fname[]);
void writeChar(char c, char fname[]);
void readInt(FILE *f, int *a, int *eof);
int readString(FILE *f, char a[], int *eof);
int readStringAllChar(FILE *f, char a[], int *eof);
void readChar(FILE *f, char *a, int *eof);
void writeBlock(char fname[], int start_id, int end_id, int weight);
int readNBlocks(char fname[], int* start_id, int* end_id, int* weight, int *eof);


#endif // FILE_FUNC_H_INCLUDED
