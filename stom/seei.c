/* seei.f -- translated by f2c (version 20181026).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer nvar, nvareff, kvar, nsta, ksta, legs, lip, neqs, nshot, nsinv, 
	    nshcor, nshfix, icount;
} dimen_;

#define dimen_1 dimen_

struct {
    real zmin, zmininput;
    integer ittmax;
    real delmin, veladj, swtfac, xythet;
    integer invertratio, iresolcalc;
    real zadj, vthet, othet, zthet, stathet, rmsmin, dmax__;
    integer ifixsolution;
} param_;

#define param_1 param_

struct {
    integer icnvout, istaout, ismpout, irayout, idrvout, ialeout, idspout, 
	    irflout, irfrout, iresout;
} outputfiles_;

#define outputfiles_1 outputfiles_

struct {
    real zshift;
} corr_;

#define corr_1 corr_

struct {
    integer icoordsystem, itrial;
    real ztrial;
    integer ised, isingle, itopo, iturbo, lowveloclay;
    logical single_turbo__;
    integer ielev[650], iuseelev, iusestacorr;
} coordsyst_;

#define coordsyst_1 coordsyst_

struct {
    integer nmod, nsp, nltot, nplay[100], laysum[100];
} modela_;

#define modela_1 modela_

struct {
    real v[100], vsq[100], h__[100], thk[100];
    integer jl;
    real tkj, delta;
} layer_;

#define layer_1 layer_

struct {
    real vp[200]	/* was [2][100] */, hp[200]	/* was [2][100] */, 
	    vdamp[200]	/* was [2][100] */, thkp[200]	/* was [2][100] */, 
	    vpvs;
    integer ireflector, lmax;
    char reflchar[1];
} layvel_;

#define layvel_1 layvel_

struct {
    real ptcor[650], stcor[650], d__[11700000]	/* was [650][3][6000] */;
    integer model[1300];
    real x[1950]	/* was [650][3] */;
    integer map1[650], map2[650];
} statn_;

#define statn_1 statn_

struct {
    real xla[650], xlo[650];
} stltln_;

#define stltln_1 stltln_

struct {
    real pt[3900000]	/* was [650][6000] */;
    integer kpwt[3900000]	/* was [650][6000] */, istm[3900000]	/* 
	    was [650][6000] */;
    real w[3900000]	/* was [650][6000] */;
    integer iphase[3900000]	/* was [650][6000] */;
    real sphase[3900000]	/* was [650][6000] */;
    integer knobs[6000];
    real depthsofinput[6000], tcalc[650];
    integer iain[650], nobswithw0;
    real amx[650], prx[650];
    integer idelta[650];
    char prmk[1300]	/* was [650][2] */;
    integer nactualsta[650], nstaeff;
} obb_;

#define obb_1 obb_

struct {
    real tctime[3900000]	/* was [650][6000] */;
} extra_;

#define extra_1 extra_

struct {
    char smn[15600000]	/* was [650][6000] */, stn[2600], blank[4], blank0[4];
} charc_;

#define charc_1 charc_

struct {
    integer iyr[6000], imo[6000], iday[6000], ihr[6000], imin[6000];
    real e[24000]	/* was [4][6000] */, emag[6000];
    integer ifx[6000];
    real xmagni[650];
    integer nmag;
    real xmagnitude, sdxmagnitude;
    char regionname[32];
    integer nreg, isconstrain[3], iconstrain[6000];
} event_;

#define event_1 event_

struct {
    integer igap[6000];
} gap_;

#define gap_1 gap_

struct {
    real scale[7];
} fix1_;

#define fix1_1 fix1_

struct {
    real g[615015200];
} gmatrix_;

#define gmatrix_1 gmatrix_

struct {
    real gcopy[2975880]	/* was [60][49598] */;
} gsave_;

#define gsave_1 gsave_

struct {
    real dtdv[100], dtdr[3];
} dttx_;

#define dttx_1 dttx_

struct {
    real gg2[720]	/* was [180][4] */, ggt[720]	/* was [4][180] */, 
	    ggg[720]	/* was [4][180] */, gtg[16]	/* was [4][4] */, 
	    ggti[16]	/* was [4][4] */, drm[32400]	/* was [180][180] */;
} dataresol_;

#define dataresol_1 dataresol_

struct {
    real rc[16]	/* was [4][4] */, rs[16]	/* was [4][4] */, sv[4], covc[
	    16]	/* was [4][4] */, covs[4], ale[6000], r3[9]	/* was [3][3] 
	    */, gg[10000]	/* was [100][100] */;
} goodness_;

#define goodness_1 goodness_

struct {
    integer irefrlayer[100], ihypoclayer[100], noheadwave;
    real refraylen[100], avhraylen, avvraylen, hitlay[300]	/* was [100][
	    3] */;
    integer irefllayer[100];
    real sterr, direrr, refrerr, reflerr;
} hitl_;

#define hitl_1 hitl_

struct {
    real avrefrres, avotheres, avreflres, abrefrres, abotheres, abreflres;
    integer nrrefrres, nrotheres, nrreflres;
    real stnazires[5200]	/* was [650][8] */;
} residuals_;

#define residuals_1 residuals_

struct {
    integer ibackups;
    real davar1, xmsqrs1;
} a3_;

#define a3_1 a3_

struct {
    real spread;
} quality_;

#define quality_1 quality_

struct {
    char modelfilename[80], stationfilename[80], seismofilename[80], 
	    scratchfilename[80];
} files_;

#define files_1 files_

struct {
    char phasefile[80], shotfile[80], topo1file[80], topo2file[80], 
	    regnamfile[80], regkoordfile[80];
} infiles_;

#define infiles_1 infiles_

struct {
    char velfile[80], cnvfile[80], rayfile[80], outfile[80], smpfile[80], 
	    stafile[80], drvfile[80], alefile[80], dsprfile[80], rflfile[80], 
	    rfrfile[80], resfile[80];
} outfiles_;

#define outfiles_1 outfiles_

struct {
    char fm[80];
    integer iabort, nitt;
    char headerline[240];
} form_;

#define form_1 form_

/* Table of constant values */

static integer c__1 = 1;
static integer c__9 = 9;
static integer c__3 = 3;
static integer c__4 = 4;

/* Subroutine */ int scaninput_(char *ip, ftnlen ip_len)
{
    /* System generated locals */
    icilist ici__1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(void)
	    ;
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void), s_rsli(icilist *), e_rsli(void), 
	    s_wsfi(icilist *), e_wsfi(void), s_cmp(char *, char *, ftnlen, 
	    ftnlen);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int adline_bf__(char *, ftnlen), adline_bm__(char 
	    *, ftnlen), adline_bk__(char *, ftnlen), adline_bl__(char *, 
	    ftnlen), adline_bp__(char *, ftnlen), adline_br__(char *, ftnlen),
	     adline_bs__(char *, ftnlen), adline_bt__(char *, ftnlen), 
	    adline_bz__(char *, ftnlen), rdline_ic__(char *, ftnlen);
    static char titleline[80], card[80], line[80*32];
    static real olat, olon, rotate;

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, 0, 0 };
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static icilist io___6 = { 0, line, 0, "(a)", 80, 1 };
    static cilist io___8 = { 0, 6, 0, "(a)", 0 };
    static icilist io___9 = { 0, line+80, 0, 0, 80, 1 };
    static cilist io___12 = { 0, 6, 0, 0, 0 };
    static icilist io___13 = { 0, line+160, 0, 0, 80, 1 };
    static cilist io___15 = { 0, 6, 0, 0, 0 };
    static icilist io___16 = { 0, line+240, 0, 0, 80, 1 };
    static cilist io___17 = { 0, 6, 0, 0, 0 };
    static icilist io___18 = { 0, line+320, 0, 0, 80, 1 };
    static cilist io___19 = { 0, 6, 0, 0, 0 };
    static icilist io___20 = { 0, line+400, 0, 0, 80, 1 };
    static cilist io___21 = { 0, 6, 0, 0, 0 };
    static icilist io___22 = { 0, line+480, 0, 0, 80, 1 };
    static cilist io___23 = { 0, 6, 0, 0, 0 };
    static icilist io___24 = { 0, line+560, 0, 0, 80, 1 };
    static cilist io___25 = { 0, 6, 0, 0, 0 };
    static icilist io___26 = { 0, line+640, 0, 0, 80, 1 };
    static cilist io___27 = { 0, 6, 0, 0, 0 };
    static icilist io___28 = { 0, line+720, 0, 0, 80, 1 };
    static cilist io___29 = { 0, 6, 0, 0, 0 };
    static icilist io___30 = { 0, line+800, 0, 0, 80, 1 };
    static cilist io___31 = { 0, 6, 0, 0, 0 };
    static icilist io___32 = { 0, line+880, 0, "(a)", 80, 1 };
    static cilist io___33 = { 0, 6, 0, "(a)", 0 };
    static icilist io___34 = { 0, line+960, 0, "(a)", 80, 1 };
    static cilist io___35 = { 0, 6, 0, "(a)", 0 };
    static icilist io___36 = { 0, line+1040, 0, "(a)", 80, 1 };
    static cilist io___37 = { 0, 6, 0, "(a)", 0 };
    static icilist io___38 = { 0, line+1120, 0, "(a)", 80, 1 };
    static cilist io___39 = { 0, 6, 0, "(a)", 0 };
    static icilist io___40 = { 0, line+1200, 0, "(a)", 80, 1 };
    static cilist io___41 = { 0, 6, 0, "(a)", 0 };
    static icilist io___42 = { 0, line+1280, 0, "(a)", 80, 1 };
    static cilist io___43 = { 0, 6, 0, "(a)", 0 };
    static icilist io___44 = { 0, line+1360, 0, "(a)", 80, 1 };
    static cilist io___45 = { 0, 6, 0, "(a)", 0 };
    static icilist io___46 = { 0, line+1440, 0, "(a)", 80, 1 };
    static cilist io___47 = { 0, 6, 0, "(a)", 0 };
    static icilist io___48 = { 0, line+1520, 0, "(a)", 80, 1 };
    static cilist io___49 = { 0, 6, 0, "(a)", 0 };
    static icilist io___50 = { 0, line+1600, 0, "(a)", 80, 1 };
    static cilist io___51 = { 0, 6, 0, "(a)", 0 };
    static icilist io___52 = { 0, line+1680, 0, "(a)", 80, 1 };
    static cilist io___53 = { 0, 6, 0, "(a)", 0 };
    static icilist io___54 = { 0, line+1760, 0, "(a)", 80, 1 };
    static cilist io___55 = { 0, 6, 0, "(a)", 0 };
    static icilist io___56 = { 0, line+1840, 0, "(a)", 80, 1 };
    static cilist io___57 = { 0, 6, 0, "(a)", 0 };
    static icilist io___58 = { 0, line+1920, 0, "(a)", 80, 1 };
    static icilist io___59 = { 0, line+2000, 0, "(a)", 80, 1 };
    static icilist io___60 = { 0, line+2080, 0, "(a)", 80, 1 };
    static icilist io___61 = { 0, line+2160, 0, "(a)", 80, 1 };
    static icilist io___62 = { 0, line+2240, 0, "(a)", 80, 1 };
    static icilist io___63 = { 0, line+2320, 0, "(a)", 80, 1 };
    static icilist io___64 = { 0, line+2400, 0, "(a)", 80, 1 };
    static icilist io___65 = { 0, line+2480, 0, "(a)", 80, 1 };


/*     file VELESTCOMMON.FOR                        Version ETH-19SEP91 */
/* ****************************************** */
/*     common-blocks of program VELEST     *  by Urs Kradolfer */
/* ****************************************** */


/* ----------------------------------------------------------------------------- */

/*     IN THIS SECTION YOU CAN CHANGE THE ARRAY-SIZES: */

/*      parameter(ieq=800)      ! number of earthquakes (Simultaneous mode) */
/* s      parameter(ieq=1)        ! number of earthquakes (single event mode ONLY) */
/* number of earthquakes (Simultaneous mod */


/* ----------------------------------------------------------------------------- */

/* max. number of shots (for simultaneous m */
/* max. number of velocity models */
/* max. number of layers per velocity mode */
/* max. number of stations in stationlist */
/* max. number of observations per ev */

/*     Control-parameters: */


/*     Model-parameters: */


/*     Station-parameters: */

/* lmax added 5.4.91 */
/* to be verified !!! (hrm */
/* ccc      character*1 cns,cew */
/* 89      character*4 smn,stn,blank,blank0 */
/* 89      data blank,blank0 /'    ','0   '/ */

/*     Event-parameters: */

/* cc     &             , effdeltaz(ieq) */

/*     'Normal-equations-parameters': */

/* max. ieq events */


/*     Statistics-parameters: */


/*     Files: */


/*     Various other parameters: */


/* **************   end of VELESTCOMMON.FOR  ******************************* */

    i__ = 0;
L111:
    rdline_ic__(ip, ip_len);
    ici__1.icierr = 0;
    ici__1.iciend = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_rsfi(&ici__1);
    do_fio(&c__1, card, (ftnlen)80);
    e_rsfi();
    if (*(unsigned char *)card == '*') {
	goto L111;
    }
    if (*(unsigned char *)card == '@') {
	goto L222;
    }
    ++i__;
    s_copy(line + (i__ - 1) * 80, card, (ftnlen)80, (ftnlen)80);
    goto L111;
L222:
    if (! (i__ == 24 || (real) i__ == 32.f)) {
	s_wsle(&io___4);
	do_lio(&c__9, &c__1, "Valor de i =", (ftnlen)12);
	do_lio(&c__3, &c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsle();
	s_wsle(&io___5);
	do_lio(&c__9, &c__1, card, (ftnlen)80);
	e_wsle();
	s_stop("INPUTPARAM>>> control-file not correct!", (ftnlen)39);
    }
/*     i=1 */
    s_rsfi(&io___6);
    do_fio(&c__1, titleline, (ftnlen)80);
    e_rsfi();
    s_wsfe(&io___8);
    do_fio(&c__1, titleline, (ftnlen)80);
    e_wsfe();
    s_rsli(&io___9);
    do_lio(&c__4, &c__1, (char *)&olat, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&olon, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.icoordsystem, (ftnlen)sizeof(
	    integer));
    do_lio(&c__4, &c__1, (char *)&corr_1.zshift, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.itrial, (ftnlen)sizeof(integer))
	    ;
    do_lio(&c__4, &c__1, (char *)&coordsyst_1.ztrial, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.ised, (ftnlen)sizeof(integer));
    e_rsli();
    s_wsle(&io___12);
    do_lio(&c__4, &c__1, (char *)&olat, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&olon, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.icoordsystem, (ftnlen)sizeof(
	    integer));
    do_lio(&c__4, &c__1, (char *)&corr_1.zshift, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.itrial, (ftnlen)sizeof(integer))
	    ;
    do_lio(&c__4, &c__1, (char *)&coordsyst_1.ztrial, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.ised, (ftnlen)sizeof(integer));
    e_wsle();
    s_rsli(&io___13);
    do_lio(&c__3, &c__1, (char *)&dimen_1.neqs, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&dimen_1.nshot, (ftnlen)sizeof(integer));
    do_lio(&c__4, &c__1, (char *)&rotate, (ftnlen)sizeof(real));
    e_rsli();
    s_wsle(&io___15);
    do_lio(&c__3, &c__1, (char *)&dimen_1.neqs, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&dimen_1.nshot, (ftnlen)sizeof(integer));
    do_lio(&c__4, &c__1, (char *)&rotate, (ftnlen)sizeof(real));
    e_wsle();
    s_rsli(&io___16);
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer)
	    );
    do_lio(&c__3, &c__1, (char *)&param_1.iresolcalc, (ftnlen)sizeof(integer))
	    ;
    e_rsli();
    s_wsle(&io___17);
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer)
	    );
    do_lio(&c__3, &c__1, (char *)&param_1.iresolcalc, (ftnlen)sizeof(integer))
	    ;
    e_wsle();
    s_rsli(&io___18);
    do_lio(&c__4, &c__1, (char *)&param_1.dmax__, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.itopo, (ftnlen)sizeof(integer));
    do_lio(&c__4, &c__1, (char *)&param_1.zmininput, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.veladj, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.zadj, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.lowveloclay, (ftnlen)sizeof(
	    integer));
    e_rsli();
    s_wsle(&io___19);
    do_lio(&c__4, &c__1, (char *)&param_1.dmax__, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.itopo, (ftnlen)sizeof(integer));
    do_lio(&c__4, &c__1, (char *)&param_1.zmininput, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.veladj, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.zadj, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.lowveloclay, (ftnlen)sizeof(
	    integer));
    e_wsle();
    s_rsli(&io___20);
    do_lio(&c__3, &c__1, (char *)&modela_1.nsp, (ftnlen)sizeof(integer));
    do_lio(&c__4, &c__1, (char *)&param_1.swtfac, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&layvel_1.vpvs, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&modela_1.nmod, (ftnlen)sizeof(integer));
    e_rsli();
    s_wsle(&io___21);
    do_lio(&c__3, &c__1, (char *)&modela_1.nsp, (ftnlen)sizeof(integer));
    do_lio(&c__4, &c__1, (char *)&param_1.swtfac, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&layvel_1.vpvs, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&modela_1.nmod, (ftnlen)sizeof(integer));
    e_wsle();
    s_rsli(&io___22);
    do_lio(&c__4, &c__1, (char *)&param_1.othet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.xythet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.zthet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.vthet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.stathet, (ftnlen)sizeof(real));
    e_rsli();
    s_wsle(&io___23);
    do_lio(&c__4, &c__1, (char *)&param_1.othet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.xythet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.zthet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.vthet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.stathet, (ftnlen)sizeof(real));
    e_wsle();
    s_rsli(&io___24);
    do_lio(&c__3, &c__1, (char *)&dimen_1.nsinv, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&dimen_1.nshcor, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&dimen_1.nshfix, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.iuseelev, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.iusestacorr, (ftnlen)sizeof(
	    integer));
    e_rsli();
    s_wsle(&io___25);
    do_lio(&c__3, &c__1, (char *)&dimen_1.nsinv, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&dimen_1.nshcor, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&dimen_1.nshfix, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.iuseelev, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.iusestacorr, (ftnlen)sizeof(
	    integer));
    e_wsle();
    s_rsli(&io___26);
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.iturbo, (ftnlen)sizeof(integer))
	    ;
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.icnvout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.istaout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.ismpout, (ftnlen)sizeof(
	    integer));
    e_rsli();
    s_wsle(&io___27);
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.iturbo, (ftnlen)sizeof(integer))
	    ;
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.icnvout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.istaout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.ismpout, (ftnlen)sizeof(
	    integer));
    e_wsle();
    s_rsli(&io___28);
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.irayout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.idrvout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.ialeout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.idspout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.irflout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.irfrout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.iresout, (ftnlen)sizeof(
	    integer));
    e_rsli();
    s_wsle(&io___29);
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.irayout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.idrvout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.ialeout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.idspout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.irflout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.irfrout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.iresout, (ftnlen)sizeof(
	    integer));
    e_wsle();
    s_rsli(&io___30);
    do_lio(&c__4, &c__1, (char *)&param_1.delmin, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&param_1.ittmax, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&param_1.invertratio, (ftnlen)sizeof(integer)
	    );
    e_rsli();
    s_wsle(&io___31);
    do_lio(&c__4, &c__1, (char *)&param_1.delmin, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&param_1.ittmax, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&param_1.invertratio, (ftnlen)sizeof(integer)
	    );
    e_wsle();
    s_rsfi(&io___32);
    do_fio(&c__1, files_1.modelfilename, (ftnlen)80);
    e_rsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_wsfi(&ici__1);
    do_fio(&c__1, files_1.modelfilename, (ftnlen)80);
    e_wsfi();
    adline_bm__(ip, ip_len);
    s_wsfe(&io___33);
    do_fio(&c__1, files_1.modelfilename, (ftnlen)80);
    e_wsfe();
    s_rsfi(&io___34);
    do_fio(&c__1, files_1.stationfilename, (ftnlen)80);
    e_rsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_wsfi(&ici__1);
    do_fio(&c__1, files_1.stationfilename, (ftnlen)80);
    e_wsfi();
    adline_bt__(ip, ip_len);
    s_wsfe(&io___35);
    do_fio(&c__1, files_1.stationfilename, (ftnlen)80);
    e_wsfe();
    s_rsfi(&io___36);
    do_fio(&c__1, files_1.seismofilename, (ftnlen)80);
    e_rsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_wsfi(&ici__1);
    do_fio(&c__1, files_1.seismofilename, (ftnlen)80);
    e_wsfi();
    adline_bs__(ip, ip_len);
    s_wsfe(&io___37);
    do_fio(&c__1, files_1.seismofilename, (ftnlen)80);
    e_wsfe();
    s_rsfi(&io___38);
    do_fio(&c__1, infiles_1.regnamfile, (ftnlen)80);
    e_rsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_wsfi(&ici__1);
    do_fio(&c__1, infiles_1.regnamfile, (ftnlen)80);
    e_wsfi();
    adline_br__(ip, ip_len);
    s_wsfe(&io___39);
    do_fio(&c__1, infiles_1.regnamfile, (ftnlen)80);
    e_wsfe();
    s_rsfi(&io___40);
    do_fio(&c__1, infiles_1.regkoordfile, (ftnlen)80);
    e_rsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_wsfi(&ici__1);
    do_fio(&c__1, infiles_1.regkoordfile, (ftnlen)80);
    e_wsfi();
    adline_bk__(ip, ip_len);
    s_wsfe(&io___41);
    do_fio(&c__1, infiles_1.regkoordfile, (ftnlen)80);
    e_wsfe();
    s_rsfi(&io___42);
    do_fio(&c__1, infiles_1.topo1file, (ftnlen)80);
    e_rsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_wsfi(&ici__1);
    do_fio(&c__1, infiles_1.topo1file, (ftnlen)80);
    e_wsfi();
    adline_bl__(ip, ip_len);
    s_wsfe(&io___43);
    do_fio(&c__1, infiles_1.topo1file, (ftnlen)80);
    e_wsfe();
    s_rsfi(&io___44);
    do_fio(&c__1, infiles_1.topo2file, (ftnlen)80);
    e_rsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_wsfi(&ici__1);
    do_fio(&c__1, infiles_1.topo2file, (ftnlen)80);
    e_wsfi();
    adline_bz__(ip, ip_len);
    s_wsfe(&io___45);
    do_fio(&c__1, infiles_1.topo2file, (ftnlen)80);
    e_wsfe();
    s_rsfi(&io___46);
    do_fio(&c__1, infiles_1.phasefile, (ftnlen)80);
    e_rsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_wsfi(&ici__1);
    do_fio(&c__1, infiles_1.phasefile, (ftnlen)80);
    e_wsfi();
    adline_bp__(ip, ip_len);
    s_wsfe(&io___47);
    do_fio(&c__1, infiles_1.phasefile, (ftnlen)80);
    e_wsfe();
    s_rsfi(&io___48);
    do_fio(&c__1, infiles_1.shotfile, (ftnlen)80);
    e_rsfi();
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = ip_len;
    ici__1.iciunit = ip;
    ici__1.icifmt = "(a)";
    s_wsfi(&ici__1);
    do_fio(&c__1, infiles_1.shotfile, (ftnlen)80);
    e_wsfi();
    adline_bf__(ip, ip_len);
    s_wsfe(&io___49);
    do_fio(&c__1, infiles_1.shotfile, (ftnlen)80);
    e_wsfe();
/*     Output files: */
    s_rsfi(&io___50);
    do_fio(&c__1, outfiles_1.outfile, (ftnlen)80);
    e_rsfi();
    s_wsfe(&io___51);
    do_fio(&c__1, outfiles_1.outfile, (ftnlen)80);
    e_wsfe();
    if (s_cmp(outfiles_1.outfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	s_copy(outfiles_1.outfile, "vel.out", (ftnlen)80, (ftnlen)7);
    }
    s_rsfi(&io___52);
    do_fio(&c__1, outfiles_1.velfile, (ftnlen)80);
    e_rsfi();
    s_wsfe(&io___53);
    do_fio(&c__1, outfiles_1.velfile, (ftnlen)80);
    e_wsfe();
    if (s_cmp(outfiles_1.velfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	s_copy(outfiles_1.velfile, "velout.vel", (ftnlen)80, (ftnlen)10);
    }
    s_rsfi(&io___54);
    do_fio(&c__1, outfiles_1.cnvfile, (ftnlen)80);
    e_rsfi();
    s_wsfe(&io___55);
    do_fio(&c__1, outfiles_1.cnvfile, (ftnlen)80);
    e_wsfe();
    if (s_cmp(outfiles_1.cnvfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	s_copy(outfiles_1.cnvfile, "velout.cnv", (ftnlen)80, (ftnlen)10);
    }
    s_rsfi(&io___56);
    do_fio(&c__1, outfiles_1.stafile, (ftnlen)80);
    e_rsfi();
    s_wsfe(&io___57);
    do_fio(&c__1, outfiles_1.stafile, (ftnlen)80);
    e_wsfe();
    if (s_cmp(outfiles_1.stafile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	s_copy(outfiles_1.stafile, "velout.sta", (ftnlen)80, (ftnlen)10);
    }

/*     the next few ouputfiles are not very often used, therefore */
/*     either all or none of them have to be specified in the controlfile: */
    if (i__ == 32) {
	s_rsfi(&io___58);
	do_fio(&c__1, outfiles_1.smpfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.smpfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.smpfile, "velout.smp", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___59);
	do_fio(&c__1, outfiles_1.rayfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.rayfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.rayfile, "velout.ray", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___60);
	do_fio(&c__1, outfiles_1.drvfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.drvfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.drvfile, "velout.drv", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___61);
	do_fio(&c__1, outfiles_1.alefile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.alefile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.alefile, "velout.ale", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___62);
	do_fio(&c__1, outfiles_1.dsprfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.dsprfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.dsprfile, "velout.dspr", (ftnlen)80, (ftnlen)11)
		    ;
	}
	s_rsfi(&io___63);
	do_fio(&c__1, outfiles_1.rflfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.rflfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.rflfile, "velout.rfl", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___64);
	do_fio(&c__1, outfiles_1.rfrfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.rfrfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.rfrfile, "velout.rfr", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___65);
	do_fio(&c__1, outfiles_1.resfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.resfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.resfile, "velout.res", (ftnlen)80, (ftnlen)10);
	}
    }
    return 0;
} /* scaninput_ */

