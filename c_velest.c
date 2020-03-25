#include "c_velest.h"
#include <stdio.h>
/* initialize the memory of the files used for 
   inecreasing python speed using later by fmemopen  ROR 03-21-2020*/

void c_velest(){
int i;
ftnlen r,t;
r=120;
t=120;
lineb=0;
load_infile_ic();
velest_(s,v,r,t); 
memclean(); 
}

void load_infile_ic(){
FILE* fpin;
long fsize;
char ch[20];
int nok;
fpin=fopen("velest.cmn","rt");
fseek(fpin, 0L, SEEK_END);
fsize = ftell(fpin);
rewind(fpin);
fread(infile_ic, fsize+1,1, fpin);
fclose(fpin);
ic=fbufopen(infile_ic, strlen(infile_ic),"r");
}

void memclean()
{ 
 char c[]="\0";
/* closefn(ic);*/
 closefn(ic);
 *infile_ic=0;
 *outfile_bo=0;
/* memcpy(infile_ic,c,SIZE_INFILE-1); */ 
/* memcpy(outfile_bo,c,SIZE_OUTFILE); */ 
}

void adlineb_(char* strinb, ftnlen lenb)
{
strinb[119]='\n'; 
strncat(outfile_bo,strinb,120);
}

void rdline_ic__(char *strin, ftnlen leni){
char buffic[120];
int len;
len=nextchfn(ic,'\n');
if (readfn(ic,buffic,len) != 0) {
strncpy(strin,buffic,len);
leni=80;
}
else{
strncpy(strin,"@",1);
leni=80;
seekfn(ic,0,SEEK_SET);
}
/* IN the case that I didnt read anything, I need to tell fortran that
EOF is found, there is no documentation on how to raise that flag, so
an option is to send an "@" in the very first character. IN the fortran code 
I need to do a comparison". ROR, 22 March 2020.*/
}


