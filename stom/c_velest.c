#include "c_velest.h"
#include <stdio.h>
/* initialize the memory of the files used for 
   inecreasing python speed using later by fmemopen  ROR 03-21-2020*/


void c_velest(){
int i;
ftnlen r,t,x;
r=120;
t=120;
x=120;
lineb=0;
memclean(); 
load_infile_ic();
scaninput(v,t); 
velest_(s,r); 
/*printf("%s\n",outfile_bo); */
}

void scaninput(char * v,  ftnlen t){
cleanfilenames();
scaninput_(v,t);
}

void cleanfilenames(){
modelfile[0]='\0';
stationfile[0]='\0';
seismfile[0]='\0';
phasefile[0]='\0';
shotfile[0]='\0';
stafile[0]='\0';
veloutmod[0]='\0';
regnamfile[0]='\0';
regkoog[0]='\0';
topofile1[0]='\0';
topofile2[0]='\0';
}

void getoutput(char *pot){
strcpy(pot,outfile_bo);
}

int getsizeoutput(){
int sizeo;
sizeo=strlen(outfile_bo);
return sizeo;
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
 if(!(ic)) closefn(ic);
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


void adline_bm__(char *strin, ftnlen len){
sscanf(strin,"%s",modelfile);
printf("Modelfile = %s \n",modelfile); 
}
void adline_bt__(char *strin, ftnlen len){
sscanf(strin,"%s",stationfile);
printf("Stationfile = %s \n",stationfile); 
}
void adline_bs__(char *strin, ftnlen len){
sscanf(strin,"%s",seismfile);
printf("Seismfile = %s \n",seismfile); 
}
void adline_bp__(char *strin, ftnlen len){
sscanf(strin,"%s",phasefile);
printf("Phasefile = %s \n",phasefile); 
}
void adline_bf__(char *strin, ftnlen len){
sscanf(strin,"%s",shotfile);
printf("Shotfile = %s \n",shotfile); 
}
void adline_bi__(char *strin, ftnlen len){
sscanf(strin,"%s",stafile);
printf("STafile = %s \n",stafile); 
}
void adline_bv__(char *strin, ftnlen len){
sscanf(strin,"%s",veloutmod);
printf("Veloutmod = %s \n",veloutmod); 
}
void adline_br__(char *strin, ftnlen len){
sscanf(strin,"%s",regnamfile);
printf("Regnamfile = %s \n",regnamfile); 
}
void adline_bk__(char *strin, ftnlen len){
sscanf(strin,"%s",regkoog);
printf("Regkoog = %s \n",regkoog); 
}
void adline_bl__(char *strin, ftnlen len){
sscanf(strin,"%s",topofile1);
printf("Topofile1  = %s \n",topofile1); 
}
void adline_bz__(char *strin, ftnlen len){
sscanf(strin,"%s",topofile2);
printf("Topofile2 = %s \n",topofile2); 
}
