#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "f2c.h"
#define MAXFINAL 100000000
#define MAXLINPUT 100000
#define READINPUT 1000

extern void velest_(char*, char*,ftnlen,ftnlen );
extern void adlineb_(char *, ftnlen);
extern void rdlinec_(char *, ftnlen);
char *sgets(char *, int , int * , char **) ;

char buffb[MAXFINAL];
char buffi[MAXLINPUT];
char rbufr[READINPUT];
char s[130];
char v[130];
int ilineb;

void velesta(){
int i,j,k;
float a,b,c;
ftnlen r,t;
long fsize;
FILE* fpin;
/*char *v, *s;
s=(char *) malloc(130);
v=(char *) malloc(130);
buffi=(char *) malloc(MAXLINPUT);
rbufr=(char *) malloc(READINPUT);*/
r=120;
t=120;
ilineb=0;
fpin=fopen("velest.cmn","rb");
fseek(fpin, 0, SEEK_END);
fsize = ftell(fpin);
fseek(fpin, 0, SEEK_SET);  /* same as rewind(f); */
fread(buffi, 1, fsize, fpin);
fclose(fpin);
velest_(s,v,r,t);
/*memset(buffb,0,MAXFINAL);
free(s);
free(v);
free(buffi);
free(rbufr);*/
/*printf("%s\n",buffb); */
}

void adlineb_(char* strinb, ftnlen lenb)
{
 strinb[119]='\n'; 
  if (ilineb==0){
strncpy(buffb,strinb,120);
}else{
strncat(buffb,strinb,120);
}
ilineb++;
}

void rdlinec_(char *outi, ftnlen leni){
static int j=1;
int i;
int outl;
char **p=&buffi;
 sgets(rbufr,120,&outl,p);
strncpy(outi,rbufr,outl);
leni=outl;
j++;
}

char *sgets(char *s, int n, int* out, char **strp) {
 if(**strp == '\0')return NULL;
  int i; 
  for(i=0;i<n-1;++i, ++(*strp)){
     s[i] = **strp;
     if(**strp == '\0') break; 
     if(**strp == '\n'){
         s[i+1]='\0';
          ++(*strp); 
          break;
       }
    }
   if(i==n-1) s[i] = '\0';
    *out=i;
    return s;
 }


