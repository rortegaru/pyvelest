#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "f2c.h"
#include "buffsizes.h"
#include "fbufopen.h"

extern void velest_(char*, char*,ftnlen,ftnlen );
extern void adline_(char *, ftnlen);
extern void rdline_ic__(char *, ftnlen);
extern void rdline_bm_(char *, ftnlen);
extern void rdline_bt_(char *, ftnlen);
extern void rdline_bs_(char *, ftnlen);
extern void rdline_bp_(char *, ftnlen);
extern void rdline_bf_(char *, ftnlen);
extern void rdline_bi_(char *, ftnlen);
extern void rdline_bi_(char *, ftnlen);
extern void rdline_bv_(char *, ftnlen);
extern void rdline_br_(char *, ftnlen);
extern void rdline_bk_(char *, ftnlen);
void load_infile_ic();
char *mygetline(char *, int, int *, FILE *);
void memclean();
int nextchfn(void *handler, int ch );
void getoutput(char *);
int getsizeoutput();

char rayfile_ra[SIZE_RAYFILE]; /*unit 13*/
char drvfile_rd[SIZE_DRVFILE]; /*unit 21*/
char cnvfile_rc[SIZE_CNVFILE]; /*unit 7*/
char smpfile_rs[SIZE_SMPFILE]; /*unit 11*/
char velfile_rs[SIZE_VELFILE]; /*unit 2*/
char alefile_re[SIZE_ALEFILE]; /*unit 75*/
char dsprfile_rp[SIZE_DSPRFILE]; /*unit 76*/
char rflfile_rl[SIZE_RFLFILE]; /*unit 77*/
char rfrfile_rr[SIZE_RFRFILE]; /*unit 78*/
char resfile_rf[SIZE_RESFILE]; /*unit 79*/
char infile_ic[SIZE_INFILE]; /*unit 10*/
char outfile_bo[SIZE_OUTFILE]; /*unit 16*/
char modelfile_bm[SIZE_MODELFILE]; /*unit 10*/
char stationfile_bt[SIZE_STATIONFILE]; /*unit 10*/
char seismfile_bs[SIZE_SEISMFILE]; /*unit 10*/
char phasefile_bp[SIZE_PHASEFILE]; /*unit 10*/
char shotfile_bf[SIZE_SHOTFILE]; /*unit 8_iunit*/
char stafile_bi[SIZE_STAFILE]; /*unit 9*/
char veloutmod_bv[SIZE_VELOUTMOD]; /*unit 12*/
char regnamfile_br[SIZE_REGNAMFILE]; /*unit iu1*/
char regkoog_bk[SIZE_REGKOOG]; /*unit iu2*/
char s[130];
char v[130];

/*FILE *bo,*ra,*rd,*rc,*rs,*rv,*re,*rp,*rl,*rr,*rf;  Virtual memory buffer files for writing*/
fbuf_t *ic,*bm,*bt,*bs,*bp,*bf,*bi,*bv,*br,*bk;  /*Virtual memory buffer for reading-writing*/

int lineb;
