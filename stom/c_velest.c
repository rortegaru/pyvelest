#include "c_velest.h"
#include <stdio.h>

/* initialize the memory of the files used for 
   inecreasing python speed using later by fmemopen  ROR 03-21-2020*/

enum filesrd{ modelf, stationf, seismf, phasef, shotf, staf, veloutm, regnamf, regk, topof1, topof2 };

struct fileshandrd {
char* mainbuffer;
char* filenam;
int  isused;
};
typedef struct fileshandrd fileshandrd_t;

fileshandrd_t  filrd[11];

void c_velest(){
int i;
ftnlen r,t,x;
r=120;
t=120;
x=120;
lineb=0;
initstruct();
memclean(); 
load_infile_ic();
cleanfilenames();
printfiles();
scaninput(v,t); 
printfiles();
load_infile_bm();
load_infile_bp(); 
printbm(); 
velest_(s,r); 
/*printf("%s\n",outfile_bo); */
}

void printbm(){
enum filesrd filer;
filer=phasef;
printf("%s \n",filrd[filer].mainbuffer);
}

void printfiles(){
enum filesrd filer;
for(filer=modelf;filer<=topof2;filer++){
printf("FIlename %d = %s \n",filer,filrd[filer].filenam);
}
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

void load_infile_bm(){
FILE* fpin;
long fsize;
char ch[20];
int nok;
enum filesrd filer;
filer=modelf;
/*printf("FIlename %d = %s \n",filer,filrd[filer].filenam); */
fpin=fopen(filrd[filer].filenam,"rt");
fseek(fpin, 0L, SEEK_END);
fsize = ftell(fpin);
rewind(fpin);
fread(filrd[filer].mainbuffer, fsize+1,1, fpin);
modelfile_bm[fsize+1]='\0';
fclose(fpin);
bm=fbufopen(filrd[filer].mainbuffer,strlen(filrd[filer].mainbuffer),"r");
}

void load_infile_bp(){
FILE* fpin;
long fsize;
char ch[20];
int nok;
enum filesrd filer;
filer=phasef;
fpin=fopen(filrd[filer].filenam,"rt");
fseek(fpin, 0L, SEEK_END);
fsize = ftell(fpin);
rewind(fpin);
fread(phasefile_bp, fsize+1,1, fpin);
phasefile_bp[fsize+1]='\0';
fclose(fpin);
bs=fbufopen(phasefile_bp,strlen(phasefile_bp),"r");
} 

void memclean()
{ 
 char c[]="\0";
/* closefn(ic);*/
 if(!(ic)) closefn(ic);
 if(!(bm)) closefn(bm);
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

void rdline_bm__(char *strin, ftnlen leni){
char buffbm[120];
int len;
len=nextchfn(bm,'\n');
if (readfn(bm,buffbm,len) != 0) {
strncpy(strin,buffbm,len);
leni=80;
}
else{
strncpy(strin,"@",1);
leni=80;
seekfn(bm,0,SEEK_SET);
}
strin[len]='\0';
printf(" Linea leida =%s \n",strin);
}


void adline_bm__(char *strin, ftnlen len){
enum filesrd filer;
filer=modelf;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Modelfile = %s \n",modelfile); 
}
void adline_bt__(char *strin, ftnlen len){
enum filesrd filer;
filer=stationf;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Stationfile = %s \n",stationfile); 
}
void adline_bs__(char *strin, ftnlen len){
enum filesrd filer;
filer=seismf;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Seismfile = %s \n",seismfile); 
}
void adline_bp__(char *strin, ftnlen len){
enum filesrd filer;
filer=phasef;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Phasefile = %s \n",phasefile); 
}
void adline_bf__(char *strin, ftnlen len){
enum filesrd filer;
filer=shotf;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Shotfile = %s \n",shotfile); 
}
void adline_bi__(char *strin, ftnlen len){
enum filesrd filer;
filer=staf;
sscanf(strin,"%s",filrd[filer].filenam);
printf("STafile = %s \n",stafile); 
}
void adline_bv__(char *strin, ftnlen len){
enum filesrd filer;
filer=veloutm;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Veloutmod = %s \n",veloutmod); 
}
void adline_br__(char *strin, ftnlen len){
enum filesrd filer;
filer=regnamf;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Regnamfile = %s \n",regnamfile); 
}
void adline_bk__(char *strin, ftnlen len){
enum filesrd filer;
filer=regk;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Regkoog = %s \n",regkoog); 
}
void adline_bl__(char *strin, ftnlen len){
enum filesrd filer;
filer=topof1;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Topofile1  = %s \n",topofile1); 
}
void adline_bz__(char *strin, ftnlen len){
enum filesrd filer;
filer=topof2;
sscanf(strin,"%s",filrd[filer].filenam);
printf("Topofile2 = %s \n",topofile2); 
}

void initstruct(){
enum filesrd filer;
for(filer=modelf;filer<=topof2;filer++){
switch (filer){
   case(modelf):
   filrd[filer].mainbuffer=modelfile_bm;
   filrd[filer].filenam=modelfile;
   break;
   case(stationf):
   filrd[filer].mainbuffer=stationfile_bt;
   filrd[filer].filenam=stationfile;
   break;
   case(seismf):
   filrd[filer].mainbuffer=seismfile_bs;
   filrd[filer].filenam=seismfile;
   break;
   case(phasef):
   filrd[filer].mainbuffer=phasefile_bp;
   filrd[filer].filenam=phasefile;
   break;
   case(shotf):
   filrd[filer].mainbuffer=shotfile_bf;
   filrd[filer].filenam=shotfile;
   break;
   case(staf):
   filrd[filer].mainbuffer=stafile_bi;
   filrd[filer].filenam=stafile;
   break;
   case(veloutm):
   filrd[filer].mainbuffer=veloutmod_bv;
   filrd[filer].filenam=veloutmod;
   break;
   case(regnamf):
   filrd[filer].mainbuffer=regnamfile_br;
   filrd[filer].filenam=regnamfile;
   break;
   case(regk):
   filrd[filer].mainbuffer=regkoog_bk;
   filrd[filer].filenam=regkoog;
   break;
   case(topof1):
   filrd[filer].mainbuffer=topofile1_bl;
   filrd[filer].filenam=topofile1;
   break;
   case(topof2):
   filrd[filer].mainbuffer=topofile2_bz;
   filrd[filer].filenam=topofile2;
   break;
    }
  }
}

