#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "f2c.h"
#include "buffsizes.h"
#include "fbufopen.h"

extern void velest_(char*,ftnlen);
extern void adline_(char *, ftnlen);
extern void scaninput_(char *, ftnlen);
extern void rdline_ic__(char *, ftnlen);
extern void adline_bm__(char *, ftnlen);
extern void adline_bt__(char *, ftnlen);
extern void adline_bs__(char *, ftnlen);
extern void adline_bp__(char *, ftnlen);
extern void adline_bf__(char *, ftnlen);
extern void adline_bi__(char *, ftnlen);
extern void adline_bv__(char *, ftnlen);
extern void adline_br__(char *, ftnlen);
extern void adline_bk__(char *, ftnlen);
extern void adline_bl__(char *, ftnlen);
extern void adline_bz__(char *, ftnlen);
extern void acaninicio_(char*, ftnlen);
void load_infile_ic();
char *mygetline(char *, int, int *, FILE *);
void memclean();
int nextchfn(void *handler, int ch );
void getoutput(char *);
int getsizeoutput();
void scaninput(char *,  ftnlen);
void cleanfilenames();

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
char topofile1_bl[SIZE_REGKOOG]; /*unit iu2*/
char topofile2_bz[SIZE_REGKOOG]; /*unit iu2*/
char s[130]; /* string for bo */
char v[130]; /*string for ic */
char p[130]; /*string for files */
char modelfile[24];
char stationfile[24];
char seismfile[24];
char phasefile[24];
char shotfile[24];
char stafile[24];
char veloutmod[24];
char regnamfile[24];
char regkoog[24];
char topofile1[24];
char topofile2[24];

/*FILE *bo,*ra,*rd,*rc,*rs,*rv,*re,*rp,*rl,*rr,*rf;  Virtual memory buffer files for writing*/
fbuf_t *ic,*bm,*bt,*bs,*bp,*bf,*bi,*bv,*br,*bk;  /*Virtual memory buffer for reading-writing*/

int lineb;
