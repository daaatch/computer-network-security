#include<stdio.h>
#include<stdlib.h>

int main(){
  FILE *sourceFile, *destFile;
  char sourcePath[100], destPath[100];
  char ch;
  char sub;
  
  printf("enter source file path: ");
  scanf("%s", sourcePath);
  
  sourceFile=fopen(sourcePath, "r");
  if(sourceFile==NULL){
    printf("Cannot open file %s\n", sourcePath);
    exit(EXIT_FAILURE);
  }
  
  printf("enter destination file path: ");
  scanf("%s", destPath);
  
  destFile=fopen(destPath, "w");
  if(destPath==NULL){
    printf("Cannot open file %s\n", destPath);
    fclose(sourceFile);
    exit(EXIT_FAILURE);
  }
  
  while((ch=fgetc(sourceFile))!=EOF){
    if(ch=='K') sub=' ';
    if(ch=='R') sub='E';
    if(ch=='J') sub='A';
    if(ch=='Q') sub='O';
    if(ch=='X') sub='N';
    if(ch=='Z') sub='T';
    if(ch=='M') sub='Y';
    if(ch=='A') sub='G';
    if(ch=='P') sub='B';
    if(ch=='I') sub='U';
    if(ch=='F') sub='D';
    if(ch=='\'') sub='L';
    if(ch=='V') sub='C';
    if(ch=='T') sub='W';
    if(ch=='O') sub='F';
    if(ch=='Y') sub='R';
    if(ch=='D') sub='M';
    if(ch=='G') sub='S';
    if(ch==' ') sub='K';
    if(ch=='N') sub='P';
    if(ch=='H') sub='H';
    if(ch=='S') sub='V';
    if(ch=='L') sub='I';
    fputc(sub, destFile);
  }
  
  fclose(sourceFile);
  fclose(destFile);
  return 0;
}
