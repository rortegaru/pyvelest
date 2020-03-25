/* veless.f -- translated by f2c (version 20100827).
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
    real rht[49598], res[3900000]	/* was [650][6000] */, rms[6000], b[
	    49598], s[49598], avres[6000], steplen;
    char smpline[80];
} a4_;

#define a4_1 a4_

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

struct {
    real aa, bb, bc, olat, olon;
} corect_;

#define corect_1 corect_

struct {
    real sint, cost, rotate;
} coords_;

#define coords_1 coords_

struct {
    doublereal rearth, ellip, rlatc, rad;
} origi_;

#define origi_1 origi_

struct {
    real olat, olon;
    doublereal rearth, ellip, rlatc, rad;
    real aa, bb, bc, sint, cost, rotate;
    integer icoordsystem;
} geo_coorsystem__;

#define geo_coorsystem__1 geo_coorsystem__

struct {
    integer indfe[730], lt50[111], lt25[421];
    char irname[24300];
    real xnrlon[14400];
} regioncom_;

#define regioncom_1 regioncom_

/* Table of constant values */

static integer c__1 = 1;
static integer c__9 = 9;
static integer c__2 = 2;
static integer c__100 = 100;
static integer c__3 = 3;
static integer c__180 = 180;
static integer c__4 = 4;
static integer c__6000 = 6000;
static integer c__50 = 50;
static integer c__650 = 650;
static integer c_n1 = -1;
static real c_b1794 = 360.f;
static real c_b2405 = 1.f;
static complex c_b3023 = {1.f,0.f};
static real c_b3046 = -1.f;

/* Subroutine */ int velest_(void)
{
    /* Format strings */
    static char fmt_59[] = "(\002 Final rms values: \002,10f5.2,/,(19x,10f5."
	    "2))";

    /* System generated locals */
    integer i__1, i__2;
    real r__1;
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_wsfe(cilist *), e_wsfe(void), s_wsle(cilist *), e_wsle(void), 
	    s_wsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsli(void), f_open(olist *), f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_rew(alist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer iresflag;
    extern /* Subroutine */ int cputimer_(real *), matrtran_(real *, integer *
	    , integer *, real *);
    static real cpmintot;
    extern /* Subroutine */ int matrmult_(real *, integer *, integer *, real *
	    , integer *, integer *, real *, integer *, integer *);
    static integer i__, j, k, l;
    static real d1, d2;
    extern /* Subroutine */ int timeclear_(integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), magnitude_(integer *, 
	    integer *);
    static integer istopflag;
    extern /* Subroutine */ int inputdata_(integer *), rmsdatvar_(void), 
	    openerror_(char *, char *, ftnlen, ftnlen);
    static integer ii;
    extern /* Subroutine */ int traveltime_(integer *, integer *, integer *), 
	    resolcovar_(real *), inputparam_(void), sdc_(real *, real *, real 
	    *, real *, integer *), statislout_(void);
    static integer ier;
    extern /* Subroutine */ int nittoutput_(real *), adjustmodel_(real *);
    static integer i4enabletest;
    static real damp, xlat, xlon;
    extern /* Subroutine */ int finalstaresi_(void);
    static char cline[80];
    extern /* Subroutine */ int setupmatrixg_(integer *, integer *), dampg_(
	    void);
    static char ctime[20];
    static real gtg_v__[16];
    static integer itime, nittc;
    extern /* Subroutine */ int checksolution_(integer *, logical *), 
	    finalhypocout_(void), backup_(void), ludecp_(real *, real *, 
	    integer *, real *, real *, integer *);
    static real ggti_v__[16];
    extern integer juliam_(integer *, integer *, integer *, integer *, 
	    integer *);
    static real cpusec;
    static logical better;
    extern /* Subroutine */ int region_(integer *, real *, real *, char *, 
	    integer *, char *, char *, ftnlen, ftnlen, ftnlen), 
	    statisticsout_(void), luelmp_(real *, real *, integer *, real *), 
	    storeg_(integer *, integer *), fixunt_(real *, integer *, integer 
	    *, integer *, integer *, real *, real *, integer *, integer *, 
	    integer *), setunt_(integer *, integer *, integer *, integer *, 
	    real *, real *, real *, real *, real *, real *), steplengthcalc_(
	    void), steplengthdamp_(real *), actualstations_(void), 
	    singularvalues_(integer *), detnofunknowns_(void);
    static integer iminold;
    extern /* Subroutine */ int matrinv_(integer *, real *, real *);

    /* Fortran I/O blocks */
    static icilist io___3 = { 0, form_1.headerline, 0, "(1x,'>>> Start of pr"
	    "ogram VELEST at ',a20,               ' <<<')", 80, 1 };
    static cilist io___5 = { 0, 6, 0, "(1x,'>>> Start of program VELEST at '"
	    ",a20,                       ' <<<')", 0 };
    static cilist io___6 = { 0, 6, 0, 0, 0 };
    static icilist io___7 = { 0, form_1.headerline+80, 0, 0, 80, 1 };
    static icilist io___8 = { 0, form_1.headerline+160, 0, 0, 80, 1 };
    static cilist io___11 = { 0, 16, 0, 0, 0 };
    static cilist io___13 = { 0, 16, 0, "(x,'>>>   End of program VELEST at "
	    "',a20,                     ' <<<',' [ CPU-sec : ',f7.1,']')", 0 };
    static cilist io___14 = { 0, 6, 0, "(x,'>>>   End of program VELEST at '"
	    ",a20,                      ' <<<',' [ CPU-sec : ',f7.1,']')", 0 };
    static cilist io___15 = { 0, 16, 0, 0, 0 };
    static cilist io___16 = { 0, 16, 0, 0, 0 };
    static cilist io___17 = { 0, 16, 0, 0, 0 };
    static cilist io___19 = { 0, 16, 0, 0, 0 };
    static cilist io___20 = { 0, 16, 0, "(/////)", 0 };
    static cilist io___21 = { 0, 16, 0, "('    I N P U T - D A T A  ',/)", 0 }
	    ;
    static cilist io___22 = { 0, 16, 0, "(1x,' eq    origin-time    latitude"
	    " longitude ',           'depth    x      y      z    mag ifxOBSt"
	    "ot obsP obsS')", 0 };
    static cilist io___23 = { 0, 16, 0, "(1x,' eq    origin-time    latitude"
	    " longitude ',                    'depth    x      y      z    ma"
	    "g ifxOBS')", 0 };
    static cilist io___27 = { 0, 16, 0, 0, 0 };
    static cilist io___28 = { 0, 16, 0, "(' knobs(i)=',i4,' nobswithw0=',i4,"
	    "                 ' nvar=',i2)", 0 };
    static cilist io___29 = { 0, 16, 0, 0, 0 };
    static cilist io___30 = { 0, 6, 0, 0, 0 };
    static cilist io___31 = { 0, 6, 0, "(' knobs(i)=',i4,' nobswithw0=',i4, "
	    "                    ' nvar=',i2)", 0 };
    static cilist io___32 = { 0, 6, 0, 0, 0 };
    static cilist io___33 = { 0, 16, 0, 0, 0 };
    static cilist io___34 = { 0, 16, 0, 0, 0 };
    static cilist io___35 = { 0, 16, 0, 0, 0 };
    static cilist io___37 = { 0, 16, 0, 0, 0 };
    static cilist io___38 = { 0, 16, 0, 0, 0 };
    static cilist io___39 = { 0, 6, 0, 0, 0 };
    static cilist io___40 = { 0, 16, 0, 0, 0 };
    static cilist io___42 = { 0, 6, 0, "(1x,' finished Iteration #',i3,'  at"
	    "',                         3x,a20,5x,'CPU-sec = ',f7.1)", 0 };
    static cilist io___44 = { 0, 16, 0, "(///,a,///)", 0 };
    static cilist io___45 = { 0, 16, 0, "(11x,'ITERATION no ',i2,/)", 0 };
    static cilist io___46 = { 0, 16, 0, 0, 0 };
    static cilist io___47 = { 0, 16, 0, 0, 0 };
    static cilist io___48 = { 0, 16, 0, 0, 0 };
    static cilist io___49 = { 0, 16, 0, "(1x,'  Othet=',f8.3,'   XYthet  =',"
	    "f8.3,                          '   Zthet=',f7.3)", 0 };
    static cilist io___50 = { 0, 16, 0, "(1x,'STAthet=',f8.3,'   Vthet   =',"
	    "f8.3,/)", 0 };
    static cilist io___51 = { 0, 16, 0, 0, 0 };
    static cilist io___52 = { 0, 16, 0, 0, 0 };
    static cilist io___56 = { 0, 16, 0, "(' WARNING: error in ludecp     ier"
	    "=',i5)", 0 };
    static cilist io___57 = { 0, 6, 0, "(' WARNING: error in ludecp     ier="
	    "',i5)", 0 };
    static cilist io___58 = { 0, 16, 0, 0, 0 };
    static cilist io___59 = { 0, 16, 0, 0, 0 };
    static cilist io___61 = { 0, 16, 0, 0, 0 };
    static cilist io___62 = { 0, 16, 0, 0, 0 };
    static cilist io___63 = { 0, 16, 0, 0, 0 };
    static cilist io___64 = { 0, 16, 0, 0, 0 };
    static cilist io___65 = { 0, 16, 0, 0, 0 };
    static cilist io___66 = { 0, 16, 0, 0, 0 };
    static cilist io___67 = { 0, 16, 0, 0, 0 };
    static cilist io___68 = { 0, 16, 0, 0, 0 };
    static cilist io___69 = { 0, 16, 0, 0, 0 };
    static cilist io___70 = { 0, 16, 0, 0, 0 };
    static cilist io___71 = { 0, 6, 0, 0, 0 };
    static cilist io___72 = { 0, 6, 0, 0, 0 };
    static cilist io___73 = { 0, 16, 0, 0, 0 };
    static cilist io___74 = { 0, 16, 0, 0, 0 };
    static cilist io___75 = { 0, 16, 0, 0, 0 };
    static cilist io___76 = { 0, 16, 0, 0, 0 };
    static cilist io___77 = { 0, 16, 0, 0, 0 };
    static cilist io___78 = { 0, 16, 0, 0, 0 };
    static cilist io___79 = { 0, 16, 0, "(' msqrd res increased',           "
	    "                              ' --> hypocenter and model backup."
	    "')", 0 };
    static cilist io___80 = { 0, 16, 0, 0, 0 };
    static cilist io___81 = { 0, 16, 0, 0, 0 };
    static cilist io___82 = { 0, 16, 0, 0, 0 };
    static cilist io___83 = { 0, 16, 0, 0, 0 };
    static cilist io___84 = { 0, 16, 0, 0, 0 };
    static cilist io___85 = { 0, 16, 0, 0, 0 };
    static cilist io___86 = { 0, 16, 0, 0, 0 };
    static cilist io___87 = { 0, 16, 0, 0, 0 };
    static cilist io___88 = { 0, 6, 0, "(1x,' finished Iteration #',i3,'  at"
	    "',                         3x,a20,5x,'CPU-sec = ',f7.1)", 0 };
    static cilist io___89 = { 0, 16, 0, 0, 0 };
    static cilist io___90 = { 0, 16, 0, 0, 0 };
    static cilist io___91 = { 0, 16, 0, 0, 0 };
    static cilist io___92 = { 0, 16, 0, 0, 0 };
    static cilist io___93 = { 0, 16, 0, "(a)", 0 };
    static cilist io___94 = { 0, 16, 0, 0, 0 };
    static cilist io___95 = { 0, 16, 0, 0, 0 };
    static cilist io___96 = { 0, 16, 0, "(' WARNING: error in ludecp     ier"
	    "=',i5)", 0 };
    static cilist io___97 = { 0, 6, 0, "(' WARNING: error in ludecp     ier="
	    "',i5)", 0 };
    static cilist io___98 = { 0, 16, 0, 0, 0 };
    static cilist io___101 = { 0, 16, 0, 0, 0 };
    static cilist io___102 = { 0, 16, 0, 0, 0 };
    static cilist io___103 = { 0, 16, 0, "(1x,'  Othet=',f8.3,'   XYthet  ='"
	    ",f8.3,                          '   Zthet=',f8.3)", 0 };
    static cilist io___104 = { 0, 16, 0, "(1x,'STAthet=',f8.3,'   Vthet   ='"
	    ",f8.3)", 0 };
    static cilist io___105 = { 0, 16, 0, 0, 0 };
    static cilist io___106 = { 0, 16, 0, 0, 0 };
    static cilist io___107 = { 0, 16, 0, 0, 0 };
    static cilist io___108 = { 0, 16, 0, fmt_59, 0 };
    static cilist io___109 = { 0, 16, 0, "(//)", 0 };
    static cilist io___112 = { 0, 16, 0, 0, 0 };
    static cilist io___113 = { 0, 16, 0, "(' Singular values:     ',4f10.4,5"
	    "x,'ALE =',f7.3)", 0 };
    static cilist io___114 = { 0, 16, 0, "(1x,'data variance = ',f10.6)", 0 };
    static cilist io___115 = { 0, 16, 0, 0, 0 };
    static cilist io___116 = { 0, 16, 0, 0, 0 };
    static cilist io___117 = { 0, 75, 0, "(2x,'ALE',3f10.4,'        .1')", 0 }
	    ;
    static cilist io___118 = { 0, 76, 0, "(2x,'DSP',3f10.4,'        .1')", 0 }
	    ;
    static cilist io___119 = { 0, 16, 0, 0, 0 };
    static cilist io___120 = { 0, 16, 0, 0, 0 };
    static cilist io___121 = { 0, 16, 0, 0, 0 };
    static cilist io___122 = { 0, 16, 0, 0, 0 };
    static cilist io___124 = { 0, 16, 0, "(1x,'TOTAL CPU-sec      ',3x,' =',"
	    "f7.1,5x,                     '(CPU-minutes:',f7.3,')')", 0 };
    static cilist io___125 = { 0, 16, 0, 0, 0 };
    static cilist io___126 = { 0, 16, 0, "(x,'>>>   End of program VELEST at"
	    " ',a20,                     ' <<<',' [ CPU-sec : ',f7.1,']')", 0 }
	    ;
    static cilist io___127 = { 0, 6, 0, "(1x,'>>>   End of program VELEST at"
	    " ',a20,                     ' <<<',' [ CPU-sec : ',f7.1,']')", 0 }
	    ;
    static cilist io___128 = { 0, 6, 0, "(1x,'GAP = ',i3,'   NITT = ',i2,   "
	    "                            '   D-Spread =',f5.2)", 0 };
    static cilist io___129 = { 0, 6, 0, 0, 0 };
    static cilist io___130 = { 0, 16, 0, 0, 0 };
    static cilist io___131 = { 0, 16, 0, 0, 0 };
    static cilist io___132 = { 0, 16, 0, 0, 0 };
    static cilist io___133 = { 0, 16, 0, 0, 0 };



/* seisan changes: */
/*   delaz renamed to delaz_velest, does not seem to be used */

/*     version 3.3  E.Kissling, Institute of Geophysics, ETH Zurich */

/*                  21. August 1998 */

/*  this version is running as: */

/*                               -  velest.f for SUN-Unix */
/*                               -  velestUNIXhp.f   for HP-Unix */


/*    the program is based on the version 3.0 HRM,UK,EK,and W.Ellsworth */
/*    of 28.oct93, and on version 3.1 EK 21April95. */
/*    (see PhD thesis by U.Kradolfer 1989, and by H.R. Maurer 1993 */
/*     at Institute of Gephysics, ETH Zurich, Switzerland) */

/* ********************************************************************* */

/*  This version of VELEST can be used to simultaneously invert a large */
/*  number of earthquake travel time data for hypocentral and velocity */
/*  model (P and S velocities) parameters. Alternatively (isingle=1) it */
/*  may also be used as a single event location program. */

/*  This version may read from input data file in the converted (*.cnv) */
/*  format (ised=0), in a velest-archive type (*arcvel) format (ised=1), */
/*  and in the new SED (Swiss Seismological Service) format (ised=2). */
/*  VELEST optionally writes output data files in converted and summary */
/*  card format and in singleevent mode writes a location file for */
/*  archive purposes (print output file). */


/* EK addition to 3.0: */
/*  9.nov93  version 3.01 added subr. inputarcvel (ised=1) */
/*  10.nov93              modified subr. inputparam for model file */
/*  10.nov93              modified  "        "      for print ouput in */
/*                                          single event location mode */
/*  15.nov93              modified in subr. traveltime no calls to */
/*                                 routines rejectobs and reviveobs */
/*  16. nov93             modified in subr. gapcalc to avoid division */
/*                        zero by zero for call to atan2 */
/*  23. nov93             modified subr inputcnv to recognize end of file */

/*  28. nov93             testing singleevent and multievent mode and */
/*                        corrections for print output in subr. inputparam */

/*  30. nov93             corrected error in inputparam for isingle and */
/*                        no of eqs .ne.0:  neqs and legs MUST be one */
/*                        for isingle=1 */

/* implemented dez 1994 EK:   read rotate angle of coordinate system */
/*                                        as in earlier versions */
/*                              subr. inputparam read neqs,nshots,rotate */

/*  also dez94 EK:          if ifx(i)=0 normally */
/*                                   =1 to inhibit adjustement of (rotated) */
/*                                      y coordinate (see subr. MATRIX) */
/*                                   (i.e. dtdr(2)=0.0 if ifx(i)=1) */


/* EK version 3.3 as of 21August1998:  implemented and improved display of */
/*                          P and S phase usage and station delays */

/* EK  still to be implemented:  flat Earth approximation */

/* EK */

/*   *vel.out file for STATIS written in subr. STATISLOUT */

/* ------------------------------------------------------------------------------ */
/* -----START OF SOURCE-CODE OF PROGRAM VELEST (MAIN PROGRAM) ------------------- */
/* ------------------------------------------------------------------------------ */



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


/*      integer errx,erry,errz */

/* -------------------------------------------- */

/*     reset internal cpu-timer: */

    cputimer_(&cpusec);

/* test to AVOID runs of velest with compilation-option   NOi4 */
    i4enabletest = 1234567890;
/* end of this 'mini-test' */

/*     save report of this VELEST-run (write it ev. to file16 in subr. INPUTPARAM */

/*     call DATETIMEX(ctime)  ! get date&time from system */
    s_wsfi(&io___3);
    do_fio(&c__1, ctime, (ftnlen)20);
    e_wsfi();
    s_wsfe(&io___5);
    do_fio(&c__1, ctime, (ftnlen)20);
    e_wsfe();
    s_wsle(&io___6);
    e_wsle();

    s_wsli(&io___7);
    do_lio(&c__9, &c__1, "::::::::::::::::::::::::::::::::::::::", (ftnlen)38)
	    ;
    e_wsli();
    s_wsli(&io___8);
    do_lio(&c__9, &c__1, " V E L E S T  - Version : January 3, 1995", (ftnlen)
	    41);
    e_wsli();

/*      reset... */

    form_1.nitt = 0;
/* number of iterations made */
    nittc = 0;
/*   "          "       for wich CPU is calculated */
    dimen_1.nvar = 0;
/* number of unknowns to solve for */
    istopflag = 0;

/*     input control-parameters, model and stations */

    inputparam_();
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___11);
	do_lio(&c__9, &c__1, "~~~ input parameters read.", (ftnlen)26);
	e_wsle();
    }

/*     if a file containing all the raypaths (ray-points) of all events */
/*     is desired, open the file (unit=13): */

    if (outputfiles_1.irayout == 1) {
	o__1.oerr = 0;
	o__1.ounit = 13;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.rayfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }
    if (outputfiles_1.idrvout == 1) {
	o__1.oerr = 0;
	o__1.ounit = 21;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.drvfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }

/*     file07 - final hypocenters and travel times ( *.CNV format, for next it.) */
/*     file11 - summary cards of final hypocenters (for plotting) */

    if (outputfiles_1.icnvout == 1) {
	o__1.oerr = 0;
	o__1.ounit = 7;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.cnvfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }
    if (outputfiles_1.ismpout == 1) {
	o__1.oerr = 0;
	o__1.ounit = 11;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.smpfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }
    if (coordsyst_1.isingle != 0) {
	o__1.oerr = 0;
	o__1.ounit = 2;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.velfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }
/*  statisL-compatible out */
    if (outputfiles_1.ialeout == 1) {
	o__1.oerr = 0;
	o__1.ounit = 75;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.alefile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }
/*  x,y, ALE of all events */
    if (outputfiles_1.idspout == 1) {
	o__1.oerr = 0;
	o__1.ounit = 76;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.dsprfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }
/*  x,y, DSPR of all event */
    if (outputfiles_1.irflout == 1) {
	o__1.oerr = 0;
	o__1.ounit = 77;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.rflfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }
/*  x,y, resid. of reflect */
    if (outputfiles_1.irfrout == 1) {
	o__1.oerr = 0;
	o__1.ounit = 78;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.rfrfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }
/*  x,y, resid. of refract */
    if (outputfiles_1.iresout == 1) {
	o__1.oerr = 0;
	o__1.ounit = 79;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.resfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
    }

/*  dist, residual of ray */
    k = 0;
/* cc      call getsymbol('zirvax')  ! not used in this version */

L1080:

/* START OF THE LOOP OVER  O N E   E V E N T FOR SINGL */
    if (k == -1) {
/* means: end of input-file detected !!! */
	cl__1.cerr = 0;
	cl__1.cunit = 2;
	cl__1.csta = 0;
	f_clos(&cl__1);
/* ek */
/*    no smp-file for single_event_mode since smp only in SED special format */
/*    use *.cnv file for plotting etc. */
/* ek */
	if (outputfiles_1.ismpout == 1 && coordsyst_1.isingle == 1) {
	    cl__1.cerr = 0;
	    cl__1.cunit = 11;
	    cl__1.csta = 0;
	    f_clos(&cl__1);
	}
/*        call DATETIMEX(ctime)  ! get date&time from system */
/*        call CPUTIMER(cpusec) */
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___13);
	    do_fio(&c__1, ctime, (ftnlen)20);
	    do_fio(&c__1, (char *)&cpusec, (ftnlen)sizeof(real));
	    e_wsfe();
	}
	s_wsfe(&io___14);
	do_fio(&c__1, ctime, (ftnlen)20);
	do_fio(&c__1, (char *)&cpusec, (ftnlen)sizeof(real));
	e_wsfe();
	s_stop("...end...(VELEST was running in SINGLE-EVENT-OPTION)", (
		ftnlen)52);
    }

/* ---------------------------------------------------------------------------- */

/*     do forward problem first: */

    form_1.nitt = 0;

/*     do scaling of damping-factors (and determine ICOUNT): */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___15);
	do_lio(&c__9, &c__1, "~~~ set units for first iteration ...", (ftnlen)
		37);
	e_wsle();
    }
/*                 1 --> so icount will not be 0 !!! */
    setunt_(&c__1, &param_1.invertratio, &dimen_1.nsinv, &dimen_1.icount, &
	    param_1.xythet, &param_1.stathet, &param_1.othet, &param_1.vthet, 
	    &param_1.zthet, fix1_1.scale);

/*     determine nr of unknowns NVAR & nr of equations LIP to be solved : */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___16);
	do_lio(&c__9, &c__1, "~~~ determine number of unknowns ...", (ftnlen)
		36);
	e_wsle();
    }
    detnofunknowns_();

/*     reset G-matrix and RHT-vector : */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___17);
	do_lio(&c__9, &c__1, "~~~ reset G and RHT ...", (ftnlen)23);
	e_wsle();
    }
    i__1 = dimen_1.kvar;
    for (j = 1; j <= i__1; ++j) {
	gmatrix_1.g[j - 1] = 0.f;
    }
    i__1 = dimen_1.nvar;
    for (k = 1; k <= i__1; ++k) {
	a4_1.rht[k - 1] = 0.f;
    }

/*     for each event do: reset avres&rms, input of the data, */
/*                        raytracing and accumulate normal equations */
/*                        ( = setup of matrix G and vector RHT ) : */

    if (outputfiles_1.irayout == 1) {
	al__1.aerr = 0;
	al__1.aunit = 13;
	f_rew(&al__1);
    }
/* rewind file (if desired) with raypat */
    if (outputfiles_1.idrvout == 1) {
	al__1.aerr = 0;
	al__1.aunit = 21;
	f_rew(&al__1);
    }
/* rewind file (if desired) with raypat */
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___19);
	do_lio(&c__9, &c__1, "~~~ input data, raytracing, setup G ...", (
		ftnlen)39);
	e_wsle();
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___20);
	e_wsfe();
	s_wsfe(&io___21);
	e_wsfe();
	if (modela_1.nsp == 2) {
	    s_wsfe(&io___22);
	    e_wsfe();
	} else {
	    s_wsfe(&io___23);
	    e_wsfe();
	}
    }
    i__1 = dimen_1.legs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	a4_1.avres[i__ - 1] = 0.f;
	a4_1.rms[i__ - 1] = 0.f;
/*        it's the starting: input trial hypocenter and phase-data */
	inputdata_(&i__);
	k = obb_1.knobs[i__ - 1];
	if (k == -1) {
	    goto L1080;
/* means: end of input-file (data) detected */
	}

/*        for each arrival do raytracing, residual-calc. and setup G & RHT : */

	i__2 = k;
	for (l = 1; l <= i__2; ++l) {
	    traveltime_(&i__, &l, &iresflag);
	    setupmatrixg_(&i__, &l);
	}
	if (coordsyst_1.isingle != 0) {
	    if (obb_1.knobs[i__ - 1] - obb_1.nobswithw0 < dimen_1.nvar) {
		form_1.iabort = 1;
		if (! coordsyst_1.single_turbo__) {
		    s_wsle(&io___27);
		    do_lio(&c__9, &c__1, "knobs(i)-nobswithw0 < nvar !!!", (
			    ftnlen)30);
		    e_wsle();
		    s_wsfe(&io___28);
		    do_fio(&c__1, (char *)&obb_1.knobs[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&obb_1.nobswithw0, (ftnlen)sizeof(
			    integer));
		    do_fio(&c__1, (char *)&dimen_1.nvar, (ftnlen)sizeof(
			    integer));
		    e_wsfe();
		    s_wsle(&io___29);
		    do_lio(&c__9, &c__1, "Event cannot be located!!!", (
			    ftnlen)26);
		    e_wsle();
		}
		s_wsle(&io___30);
		do_lio(&c__9, &c__1, "knobs(i)-nobswithw0 < nvar !!!", (
			ftnlen)30);
		e_wsle();
		s_wsfe(&io___31);
		do_fio(&c__1, (char *)&obb_1.knobs[i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&obb_1.nobswithw0, (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&dimen_1.nvar, (ftnlen)sizeof(integer));
		e_wsfe();
		s_wsle(&io___32);
		do_lio(&c__9, &c__1, "Event cannot be located!!!", (ftnlen)26)
			;
		e_wsle();
		goto L98989;
	    }
	    if (! coordsyst_1.single_turbo__) {
		s_wsle(&io___33);
		do_lio(&c__9, &c__1, "~~~ compute singular values of G ...", (
			ftnlen)36);
		e_wsle();
	    }
	    singularvalues_(&i__);
	}
    }

/*     now all the events are read-in; now check, how many stations */
/*     appear in the input-data (= nofstainput) */

    actualstations_();

/*     save selected columns of g for resolution calculations */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___34);
	e_wsle();
	s_wsle(&io___35);
	do_lio(&c__9, &c__1, "~~~ store parts of G ...", (ftnlen)24);
	e_wsle();
    }
    for (k = 1; k <= 4; ++k) {
	storeg_(&k, &k);
    }
    if (fix1_1.scale[5] != 0.f) {
	i__ = (dimen_1.neqs << 2) + dimen_1.nshot + 1;
	j = i__ + modela_1.nltot - 1;
	ii = 4;
	i__1 = j;
	for (k = i__; k <= i__1; ++k) {
	    ++ii;
	    storeg_(&k, &ii);
	}
    }

/*     all events: raytracing done, residuals calculated */
/*                 and normal equations accumulated */

/*     calculate rms & data variance for all events: */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___37);
	do_lio(&c__9, &c__1, "~~~ compute RMS and DATVAR ...", (ftnlen)30);
	e_wsle();
    }
    rmsdatvar_();

    if (param_1.ittmax == 0) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___38);
	    do_lio(&c__9, &c__1, "WARNING:  ITTmax=0  -->  no iteration is m"
		    "ade", (ftnlen)45);
	    e_wsle();
	}
	s_wsle(&io___39);
	do_lio(&c__9, &c__1, "WARNING:  ITTmax=0  -->  no iteration is made", 
		(ftnlen)45);
	e_wsle();
	goto L9999;
    }

/*     calculate GAP, average-residuals of ray-types and check, */
/*     whether variance/msqrd res have decreased (this is */
/*     always the case if NITT=0 !) or not (in the */
/*     latter case do hypocenter/model backup): */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___40);
	do_lio(&c__9, &c__1, "~~~ save initial datvar ...", (ftnlen)27);
	e_wsle();
    }
    checksolution_(&istopflag, &better);


L10:

/*     reset CPU-timer for this iteration */

/*     call DATETIMEX(ctime)  ! get date&time from system */
/*     call CPUTIMER(cpusec) */
/*  START OF THE LOOP FOR ONE   I T E R A T I O N */
    if (coordsyst_1.isingle == 0) {
	s_wsfe(&io___42);
	do_fio(&c__1, (char *)&nittc, (ftnlen)sizeof(integer));
	do_fio(&c__1, ctime, (ftnlen)20);
	do_fio(&c__1, (char *)&cpusec, (ftnlen)sizeof(real));
	e_wsfe();
    }
    ++nittc;


    ++form_1.nitt;

/*     print header of this iteration : */

    s_copy(cline, "---------------------------------------------------------"
	    "-----------------------", (ftnlen)80, (ftnlen)80);
    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___44);
	do_fio(&c__1, cline, (ftnlen)80);
	e_wsfe();
	s_wsfe(&io___45);
	do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
	e_wsfe();
    }

/*     do scaling of damping-factors (and determine ICOUNT) for this iteration: */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___46);
	do_lio(&c__9, &c__1, "~~~ set units for this iteration ...", (ftnlen)
		36);
	e_wsle();
    }
    setunt_(&form_1.nitt, &param_1.invertratio, &dimen_1.nsinv, &
	    dimen_1.icount, &param_1.xythet, &param_1.stathet, &param_1.othet,
	     &param_1.vthet, &param_1.zthet, fix1_1.scale);

/*     set nr of unknowns back to nr for this iteration */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___47);
	do_lio(&c__9, &c__1, "~~~ determine number of unknowns for this iter"
		". ...", (ftnlen)51);
	e_wsle();
    }
    detnofunknowns_();

/*     print out the damping-factors to be used in this iteration : */

    if (coordsyst_1.isingle == 0) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___48);
	    do_lio(&c__9, &c__1, "Damping factors to be used in this iterati"
		    "on:", (ftnlen)45);
	    e_wsle();
	    s_wsfe(&io___49);
	    do_fio(&c__1, (char *)&param_1.othet, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&param_1.xythet, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&param_1.zthet, (ftnlen)sizeof(real));
	    e_wsfe();
	    s_wsfe(&io___50);
	    do_fio(&c__1, (char *)&param_1.stathet, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&param_1.vthet, (ftnlen)sizeof(real));
	    e_wsfe();
	}
    }

/*     apply damping to diagonal elements of G-matrix : */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___51);
	do_lio(&c__9, &c__1, "~~~ damp G ...", (ftnlen)14);
	e_wsle();
    }
    dampg_();

/*     copy right-hand-side of normal equations (RHT=At*RES) to vector B : */

    i__1 = dimen_1.nvar;
    for (k = 1; k <= i__1; ++k) {
	a4_1.b[k - 1] = a4_1.rht[k - 1];
    }


/*     Cholesky-decomposition of matrix G : */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___52);
	do_lio(&c__9, &c__1, "~~~ solve G * b = RHT ...", (ftnlen)25);
	e_wsle();
    }
    ludecp_(gmatrix_1.g, gmatrix_1.g, &dimen_1.nvar, &d1, &d2, &ier);
    if (ier != 0) {
/* matrix not positive definit !!! */
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___56);
	    do_fio(&c__1, (char *)&ier, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	s_wsfe(&io___57);
	do_fio(&c__1, (char *)&ier, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("error in (damped) matrix G !!!", (ftnlen)30);
    }

/*     solve normal equations (simple elimination; G is now lower triangular) : */

    luelmp_(gmatrix_1.g, a4_1.b, &dimen_1.nvar, a4_1.b);

/*     put solution into proper units : */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___58);
	do_lio(&c__9, &c__1, "~~~ fix units ...", (ftnlen)17);
	e_wsle();
    }
    fixunt_(a4_1.b, &dimen_1.neqs, &dimen_1.nshot, &modela_1.nltot, &
	    dimen_1.ksta, fix1_1.scale, layvel_1.vdamp, &c__2, &c__100, 
	    modela_1.nplay);

/*     check velocity-change; */
/*     if large, apply step-length-damping to adjustment-vector ! */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___59);
	do_lio(&c__9, &c__1, "~~~ apply eventually step-length damping ...", (
		ftnlen)44);
	e_wsle();
    }
    steplengthdamp_(&damp);

/*     adjust hypocenters, velocities & stationcorrections : */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___61);
	do_lio(&c__9, &c__1, "~~~ adjust model (hypocenters, stacorr & veloc"
		".) ...", (ftnlen)52);
	e_wsle();
    }
    adjustmodel_(&damp);

/*     calculate total step-length of this iteration and print it out: */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___62);
	do_lio(&c__9, &c__1, "~~~ compute effective step-length ...", (ftnlen)
		37);
	e_wsle();
    }
    steplengthcalc_();


L1010:

/*     do forward problem for solution of iteration# NITT: */


/*     do scaling of damping-factors (and determine ICOUNT) for NEXT iteration: */

/* come here, if backup has been performed   ! */
    if (a3_1.ibackups < 4) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___63);
	    do_lio(&c__9, &c__1, "~~~ set units for next iteration ...", (
		    ftnlen)36);
	    e_wsle();
	}
	i__1 = form_1.nitt + 1;
	setunt_(&i__1, &param_1.invertratio, &dimen_1.nsinv, &dimen_1.icount, 
		&param_1.xythet, &param_1.stathet, &param_1.othet, &
		param_1.vthet, &param_1.zthet, fix1_1.scale);
    } else {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___64);
	    do_lio(&c__9, &c__1, "~~~ set units for this iteration ...", (
		    ftnlen)36);
	    e_wsle();
	}
	setunt_(&form_1.nitt, &param_1.invertratio, &dimen_1.nsinv, &
		dimen_1.icount, &param_1.xythet, &param_1.stathet, &
		param_1.othet, &param_1.vthet, &param_1.zthet, fix1_1.scale);
    }

/*     determine nr of unknowns NVAR & nr of equations LIP to be solved for NEXT: */

    if (! coordsyst_1.single_turbo__) {
	if (a3_1.ibackups < 4) {
	    s_wsle(&io___65);
	    do_lio(&c__9, &c__1, "~~~ determine number of unknowns for next "
		    "iter. ...", (ftnlen)51);
	    e_wsle();
	} else {
	    s_wsle(&io___66);
	    do_lio(&c__9, &c__1, "~~~ determine number of unknowns for this "
		    "iter. ...", (ftnlen)51);
	    e_wsle();
	}
    }
    detnofunknowns_();

/*     reset G-matrix and RHT-vector : */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___67);
	do_lio(&c__9, &c__1, "~~~ reset G and RHT ...", (ftnlen)23);
	e_wsle();
    }
    i__1 = dimen_1.kvar;
    for (j = 1; j <= i__1; ++j) {
	gmatrix_1.g[j - 1] = 0.f;
    }
    i__1 = dimen_1.nvar;
    for (k = 1; k <= i__1; ++k) {
	a4_1.rht[k - 1] = 0.f;
    }

/*     for each event do: reset avres&rms, input (if 1st iteration), */
/*                        raytracing and accumulate normal equations */
/*                        ( = setup of matrix G and vector RHT ) : */

    if (outputfiles_1.irayout == 1) {
	al__1.aerr = 0;
	al__1.aunit = 13;
	f_rew(&al__1);
    }
/* rewind file (if desired) with raypat */
    if (outputfiles_1.idrvout == 1) {
	al__1.aerr = 0;
	al__1.aunit = 21;
	f_rew(&al__1);
    }
/* rewind file (if desired) with raypat */
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___68);
	do_lio(&c__9, &c__1, "~~~ raytracing, setup G ...", (ftnlen)27);
	e_wsle();
    }
    i__1 = dimen_1.legs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	a4_1.avres[i__ - 1] = 0.f;
	a4_1.rms[i__ - 1] = 0.f;
	k = obb_1.knobs[i__ - 1];

/*        for each arrival do raytracing, residual-calc. and setup G & RHT : */

	i__2 = k;
	for (l = 1; l <= i__2; ++l) {
	    traveltime_(&i__, &l, &iresflag);
	    setupmatrixg_(&i__, &l);

/* hrm    Calculate the matrix G for the data resolution matrix */
	    if (coordsyst_1.isingle != 0) {
		dataresol_1.gg2[l - 1] = obb_1.w[l - 1];
		dataresol_1.gg2[l + 179] = dttx_1.dtdr[0] * obb_1.w[l - 1];
		dataresol_1.gg2[l + 359] = dttx_1.dtdr[1] * obb_1.w[l - 1];
		dataresol_1.gg2[l + 539] = dttx_1.dtdr[2] * obb_1.w[l - 1];
	    }
	}

	if (coordsyst_1.isingle != 0) {
	    if (obb_1.knobs[i__ - 1] - obb_1.nobswithw0 < dimen_1.nvar) {
		form_1.iabort = 1;
		if (! coordsyst_1.single_turbo__) {
		    s_wsle(&io___69);
		    do_lio(&c__9, &c__1, "knobs(i)-nobswithw0 < nvar !!!", (
			    ftnlen)30);
		    e_wsle();
		    s_wsle(&io___70);
		    do_lio(&c__9, &c__1, "Event cannot be located!!!", (
			    ftnlen)26);
		    e_wsle();
		}
		s_wsle(&io___71);
		do_lio(&c__9, &c__1, "knobs(i)-nobswithw0 < nvar !!!", (
			ftnlen)30);
		e_wsle();
		s_wsle(&io___72);
		do_lio(&c__9, &c__1, "Event cannot be located!!!", (ftnlen)26)
			;
		e_wsle();
		goto L98989;
	    }
	    if (! coordsyst_1.single_turbo__) {
		s_wsle(&io___73);
		do_lio(&c__9, &c__1, "~~~ compute singular values of G ...", (
			ftnlen)36);
		e_wsle();
	    }
	    singularvalues_(&i__);
	}
    }

/*     save selected columns of g for resolution calculations */

/*     Store parts of matrix G here (valid for next iteration), before SETUNT */
/*     for this iteration! */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___74);
	do_lio(&c__9, &c__1, "~~~ store parts of G ...", (ftnlen)24);
	e_wsle();
    }
    for (k = 1; k <= 4; ++k) {
	storeg_(&k, &k);
    }
    if (fix1_1.scale[5] != 0.f) {
	i__ = (dimen_1.neqs << 2) + dimen_1.nshot + 1;
	j = i__ + modela_1.nltot - 1;
	ii = 4;
	i__1 = j;
	for (k = i__; k <= i__1; ++k) {
	    ++ii;
	    storeg_(&k, &ii);
	}
    }

/*     do scaling of damping-factors (and determine ICOUNT) for CURRENT iter.: */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___75);
	do_lio(&c__9, &c__1, "~~~ set units back for current iteration ...", (
		ftnlen)44);
	e_wsle();
    }
    setunt_(&form_1.nitt, &param_1.invertratio, &dimen_1.nsinv, &
	    dimen_1.icount, &param_1.xythet, &param_1.stathet, &param_1.othet,
	     &param_1.vthet, &param_1.zthet, fix1_1.scale);

/*     set nr of unknowns back to nr for this iteration */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___76);
	do_lio(&c__9, &c__1, "~~~ determine number of unknowns for this iter"
		". ...", (ftnlen)51);
	e_wsle();
    }
    detnofunknowns_();

/*     all events: raytracing done, residuals calculated */
/*                 and normal equations accumulated */

/*     calculate rms & data variance for all events: */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___77);
	do_lio(&c__9, &c__1, "~~~ compute RMS and DATVAR ...", (ftnlen)30);
	e_wsle();
    }
    rmsdatvar_();

/*     calculate GAP, average-residuals of ray-types and check, */
/*     whether variance/msqrd res have decreased (this is */
/*     always the case if NITT=1 !) or not (in the */
/*     latter case do hypocenter/model backup): */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___78);
	do_lio(&c__9, &c__1, "~~~ check solution (better? worse?) ...", (
		ftnlen)39);
	e_wsle();
    }
    checksolution_(&istopflag, &better);

/* better=.false. if variance inc'd and residual inc'd, so do readjustments */
/* if backup was done, but less than 4 times, do forward problem again !! */

    if (a3_1.ibackups < 4) {
	if (better) {
	    if (a3_1.ibackups < 4) {
		a3_1.ibackups = 0;
	    }
	} else {
	    if (a3_1.ibackups == 0) {
		if (! coordsyst_1.single_turbo__) {
		    nittoutput_(&damp);
		}
	    }
	    if (a3_1.ibackups < 4) {
		if (! coordsyst_1.single_turbo__) {
		    s_wsfe(&io___79);
		    e_wsfe();
		    s_wsle(&io___80);
		    do_lio(&c__9, &c__1, "~~~ solution is worse --> backup ."
			    "..", (ftnlen)36);
		    e_wsle();
		}
		backup_();
		++a3_1.ibackups;
		steplengthcalc_();
		goto L1010;
	    }
	}
    } else {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___81);
	    do_lio(&c__9, &c__1, "4 times backup made!", (ftnlen)20);
	    e_wsle();
	}
    }

/*     come here, if no backup made or 4 backups made */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___82);
	do_lio(&c__9, &c__1, "~~~ iteration done; output results ...", (
		ftnlen)38);
	e_wsle();
    }
    if (! coordsyst_1.single_turbo__) {
	nittoutput_(&damp);
    }

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___83);
	do_lio(&c__9, &c__1, "~~~ another iteration? ...", (ftnlen)26);
	e_wsle();
    }

/*  IF 4 TIMES 'HALF ADJUSTMENTS MADE', SOLUTION IS FINAL --> STOP ITERATIONS */

    if (a3_1.ibackups == 4) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___84);
	    do_lio(&c__9, &c__1, "4 TIMES BACKUP MADE --> sTOP ITERATIONS.", (
		    ftnlen)40);
	    e_wsle();
	}
	goto L9999;
    }

/*     IF  STEP-LENGTH < DELMIN ( MINIMUM STEP-LENGTH ) --> STOP ITERATIONS : */

    if (a4_1.steplen > 0.f) {
/* otherwise we are during backups... */
	if (a4_1.steplen < param_1.delmin) {
	    if (! coordsyst_1.single_turbo__) {
		s_wsle(&io___85);
		do_lio(&c__9, &c__1, "STEP-LENGTH < DELMIN  --> stop iterati"
			"ons.", (ftnlen)42);
		e_wsle();
	    }
	    goto L9999;
	}
    }

/*     IF  #ITERATIONS = ITTMAX  --> STOP ITERATIONS : */

    if (form_1.nitt == param_1.ittmax) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___86);
	    do_lio(&c__9, &c__1, "NITT = ITTMAX  --> stop iterations.", (
		    ftnlen)35);
	    e_wsle();
	}
	goto L9999;
    }

/*     SINGLE-EVENT-MODE: IF CHANGES IN DATVAR < 1.E-6 --> STOP ITERATIONS : */

    if (coordsyst_1.isingle != 0 && istopflag == 1) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___87);
	    do_lio(&c__9, &c__1, "Changes in datvar < 1.e-6  --> stop iterat"
		    "ions.", (ftnlen)47);
	    e_wsle();
	}
	goto L9999;
    }

/*     DO NEXT ITERATION : */

    a3_1.ibackups = 0;
    goto L10;

/* ---------------------------------------------------------------------------- */

/*     FINAL solution reached!   output final solution of all events, */
/*                               all residuals and station-corrections: */

L9999:

    cputimer_(&cpusec);
    if (coordsyst_1.isingle == 0) {
	s_wsfe(&io___88);
	do_fio(&c__1, (char *)&nittc, (ftnlen)sizeof(integer));
	do_fio(&c__1, ctime, (ftnlen)20);
	do_fio(&c__1, (char *)&cpusec, (ftnlen)sizeof(real));
	e_wsfe();
    }
    ++nittc;

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___89);
	do_lio(&c__9, &c__1, "~~~ final solution reached ...", (ftnlen)30);
	e_wsle();
	s_wsle(&io___90);
	e_wsle();
	if (param_1.iresolcalc > 0) {
	} else {
	    s_wsle(&io___91);
	    do_lio(&c__9, &c__1, "~~~ damp G & Chol.-Decomp.: NOT made (swit"
		    "ch iresolcalc is NOT set !)", (ftnlen)69);
	    e_wsle();
	}
    }
    if (param_1.iresolcalc > 0) {

/*        G was calculated for next iteration, so compute nvar, kvar etc. for */
/*        next iteration as well: */
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___92);
	    do_lio(&c__9, &c__1, "~~~ set units for next iteration ...", (
		    ftnlen)36);
	    e_wsle();
	}
	i__1 = form_1.nitt + 1;
	setunt_(&i__1, &param_1.invertratio, &dimen_1.nsinv, &dimen_1.icount, 
		&param_1.xythet, &param_1.stathet, &param_1.othet, &
		param_1.vthet, &param_1.zthet, fix1_1.scale);
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___93);
	    do_fio(&c__1, " ~~~ determine number of unknowns for next iter. "
		    "...", (ftnlen)52);
	    e_wsfe();
	}
	detnofunknowns_();

	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___94);
	    do_lio(&c__9, &c__1, "~~~ damp G ...", (ftnlen)14);
	    e_wsle();
	}
	dampg_();
/* necessary for subr. RESOLCOVAR !!! */
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___95);
	    do_lio(&c__9, &c__1, "~~~ Cholesky decomposition of G ...", (
		    ftnlen)35);
	    e_wsle();
	}
	ludecp_(gmatrix_1.g, gmatrix_1.g, &dimen_1.nvar, &d1, &d2, &ier);
/* necessary for subr. RESOLCO */
	if (ier != 0) {
/* matrix not positive definit !!! */
	    if (! coordsyst_1.single_turbo__) {
		s_wsfe(&io___96);
		do_fio(&c__1, (char *)&ier, (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	    s_wsfe(&io___97);
	    do_fio(&c__1, (char *)&ier, (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_stop("error in (damped) matrix G !!!", (ftnlen)30);
	}
    }

    if (coordsyst_1.isingle != 0 && coordsyst_1.icoordsystem == 2) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___98);
	    do_lio(&c__9, &c__1, "~~~ compute magnitude ...", (ftnlen)25);
	    e_wsle();
	}
	i__1 = dimen_1.legs;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (event_1.iyr[i__ - 1] < 100) {
		i__2 = event_1.iyr[i__ - 1] + 1900;
		iminold = juliam_(&i__2, &event_1.imo[i__ - 1], &event_1.iday[
			i__ - 1], &event_1.ihr[i__ - 1], &event_1.imin[i__ - 
			1]);
	    } else {
		iminold = juliam_(&event_1.iyr[i__ - 1], &event_1.imo[i__ - 1]
			, &event_1.iday[i__ - 1], &event_1.ihr[i__ - 1], &
			event_1.imin[i__ - 1]);
	    }
	    timeclear_(&event_1.iyr[i__ - 1], &event_1.imo[i__ - 1], &
		    event_1.iday[i__ - 1], &event_1.ihr[i__ - 1], &
		    event_1.imin[i__ - 1], &event_1.e[(i__ << 2) - 4], &itime)
		    ;
	    i__2 = obb_1.knobs[i__ - 1];
	    for (j = 1; j <= i__2; ++j) {
		obb_1.pt[j + i__ * 650 - 651] += (iminold - itime) * 60.f;
	    }
	    magnitude_(&i__, &itime);
	    event_1.emag[i__ - 1] = event_1.xmagnitude;
/*       standard-deviation of emag(i)=sdxmagnitude */
/*       the magnitudes for each station are now stored on XMAGNI(1...nobs) */
	}
    }

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___101);
	e_wsle();
	if (coordsyst_1.isingle != 0) {
	    s_wsle(&io___102);
	    do_lio(&c__9, &c__1, "Damping factors to be used in this iterati"
		    "on:", (ftnlen)45);
	    e_wsle();
	    s_wsfe(&io___103);
	    do_fio(&c__1, (char *)&param_1.othet, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&param_1.xythet, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&param_1.zthet, (ftnlen)sizeof(real));
	    e_wsfe();
	    s_wsfe(&io___104);
	    do_fio(&c__1, (char *)&param_1.stathet, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&param_1.vthet, (ftnlen)sizeof(real));
	    e_wsfe();
	    s_wsle(&io___105);
	    e_wsle();
	    s_wsle(&io___106);
	    do_lio(&c__9, &c__1, "Final solution of event#", (ftnlen)24);
	    do_lio(&c__3, &c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(
		    integer));
	    e_wsle();
	    s_wsle(&io___107);
	    do_lio(&c__9, &c__1, "------------------------------------", (
		    ftnlen)36);
	    e_wsle();
	} else {
/*         print final rms-values of all the events */
	    s_wsfe(&io___108);
	    i__1 = dimen_1.legs;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&a4_1.rms[i__ - 1], (ftnlen)sizeof(real)
			);
	    }
	    e_wsfe();
	    s_wsfe(&io___109);
	    e_wsfe();
	}
    }

    if (coordsyst_1.isingle != 0) {
	if (coordsyst_1.icoordsystem == 2) {
	    r__1 = -event_1.e[1];
	    region_(&c__1, &r__1, &event_1.e[2], event_1.regionname, &
		    event_1.nreg, infiles_1.regnamfile, 
		    infiles_1.regkoordfile, (ftnlen)32, (ftnlen)80, (ftnlen)
		    80);
	} else {
	    sdc_(&event_1.e[1], &event_1.e[2], &xlat, &xlon, &c__1);
/* calc. LAT/LON */
	    r__1 = -xlon;
	    region_(&c__2, &xlat, &r__1, event_1.regionname, &event_1.nreg, 
		    infiles_1.regnamfile, infiles_1.regkoordfile, (ftnlen)32, 
		    (ftnlen)80, (ftnlen)80);
/* Subr. REGION nee */
	}
/* as input (E = po */
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___112);
	do_lio(&c__9, &c__1, "~~~ output final hypocenters ...", (ftnlen)32);
	e_wsle();
    }
    finalhypocout_();
    if (! coordsyst_1.single_turbo__) {
	if (coordsyst_1.isingle != 0) {
	    s_wsfe(&io___113);
	    for (j = 1; j <= 4; ++j) {
		do_fio(&c__1, (char *)&goodness_1.sv[j - 1], (ftnlen)sizeof(
			real));
	    }
	    do_fio(&c__1, (char *)&goodness_1.ale[0], (ftnlen)sizeof(real));
	    e_wsfe();
	    s_wsfe(&io___114);
	    do_fio(&c__1, (char *)&a3_1.davar1, (ftnlen)sizeof(real));
	    e_wsfe();
	}
    }

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___115);
	do_lio(&c__9, &c__1, "~~~ output final station residuals ...", (
		ftnlen)38);
	e_wsle();
	finalstaresi_();
    }
    if (param_1.iresolcalc > 0) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___116);
	    do_lio(&c__9, &c__1, "~~~ output resolution- & covariance matric"
		    "es ...", (ftnlen)48);
	    e_wsle();
	}
	resolcovar_(&a3_1.davar1);
    }
/*      if (s(2).gt.99.9) then */
/*         errx = 999 */
/*      else */
/*      endif */
/*     if (s(3).gt.99.9) then */
/*        erry = 999 */
/*      else */
/*        erry = nint(s(3)*10.) */
/*      endif */
/*      if (s(4).gt.99.9) then */
/*         errz = 999 */
/*      else */
/*         errz = nint(s(4)*10.) */
/*      endif */
/*      write(smpline(46:54),'(3i3)'),errx,erry,errz */
/* ek     if(isingle.eq.0) then */
/* ek         write(11,'(a80)') smpline */
/* ek      endif */
    if (outputfiles_1.ialeout == 1) {
	s_wsfe(&io___117);
	r__1 = -event_1.e[1];
	do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&event_1.e[2], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&goodness_1.ale[0], (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (outputfiles_1.idspout == 1) {
	s_wsfe(&io___118);
	r__1 = -event_1.e[1];
	do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&event_1.e[2], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&quality_1.spread, (ftnlen)sizeof(real));
	e_wsfe();
    }

/*     output all the statistics-stuff... */

    if (coordsyst_1.isingle == 0) {
	s_wsle(&io___119);
	do_lio(&c__9, &c__1, "~~~ output statistics ...", (ftnlen)25);
	e_wsle();
	statisticsout_();
    }

/*     close output-files: */

    if (coordsyst_1.iturbo == 0) {
	cl__1.cerr = 0;
	cl__1.cunit = 7;
	cl__1.csta = 0;
	f_clos(&cl__1);
/* ek         if(ismpout.eq.1.and.isingle.eq.0) close(11) */
    }
    if (outputfiles_1.irayout == 1) {
	cl__1.cerr = 0;
	cl__1.cunit = 13;
	cl__1.csta = 0;
	f_clos(&cl__1);
	cl__1.cerr = 0;
	cl__1.cunit = 21;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }

/*     output cpu-statistics for whole VELEST-run: */

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___120);
	e_wsle();
    }
    cputimer_(&cpusec);
    if (coordsyst_1.isingle == 0) {
	s_wsle(&io___121);
	do_lio(&c__9, &c__1, "CPU - statistics:", (ftnlen)17);
	e_wsle();
	s_wsle(&io___122);
	e_wsle();
    }
    if (! coordsyst_1.single_turbo__) {
	cpmintot = cpusec / 60.f;
	s_wsfe(&io___124);
	do_fio(&c__1, (char *)&cpusec, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&cpmintot, (ftnlen)sizeof(real));
	e_wsfe();
	s_wsle(&io___125);
	e_wsle();
    }

    if (coordsyst_1.isingle == 0) {
/*        call DATETIMEX(ctime)  ! get date&time from system */
	s_wsfe(&io___126);
	do_fio(&c__1, ctime, (ftnlen)20);
	do_fio(&c__1, (char *)&cpusec, (ftnlen)sizeof(real));
	e_wsfe();
	s_wsfe(&io___127);
	do_fio(&c__1, ctime, (ftnlen)20);
	do_fio(&c__1, (char *)&cpusec, (ftnlen)sizeof(real));
	e_wsfe();
    }


/*     in case of 'single-event-mode' output NITT, GAP, */
/*                      SPREAD of resolution and final hypocenter in */
/*                      statisL-compatible */

L98989:
/* return address for 'insufficient data' !!! */
    if (coordsyst_1.isingle > 0) {
/*        call DATETIMEX(ctime)  ! get date&time from system */
	if (form_1.iabort != 1) {
	    s_wsfe(&io___128);
	    do_fio(&c__1, (char *)&gap_1.igap[0], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&quality_1.spread, (ftnlen)sizeof(real));
	    e_wsfe();
	}
	s_wsle(&io___129);
	e_wsle();
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___130);
	    do_lio(&c__9, &c__1, "end of event# ", (ftnlen)14);
	    do_lio(&c__3, &c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(
		    integer));
	    e_wsle();
	    s_wsle(&io___131);
	    e_wsle();
	    s_wsle(&io___132);
	    e_wsle();
	}

/*        output statisL/SED-compatible summary in file02   ( *.VEL ) */

	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___133);
	    do_lio(&c__9, &c__1, "~~~ output solution in HYPO71-compatible f"
		    "ormat...", (ftnlen)50);
	    e_wsle();
	}

/* hrm     Calculation of the data resolution matrix */
/*        gg2 = Matrix G */
/*        ggt = G transposed */
/* 	 gtg = G * G transposed */
/* 	 ggti = Inverse of gtg */
/*        ggg = Generalized inverse */
/*        drm = data resolution matrix */

/* hrm     Setup ggt */

	matrtran_(dataresol_1.gg2, &c__180, &c__4, dataresol_1.ggt);

/* hrm     Setup gtg */

	matrmult_(dataresol_1.ggt, &c__4, &c__180, dataresol_1.gg2, &c__180, &
		c__4, dataresol_1.gtg, &c__4, &c__4);

/* hrm     Damping of gtg ... */

	dataresol_1.gtg[0] += param_1.othet;
	dataresol_1.gtg[5] += param_1.xythet;
	dataresol_1.gtg[10] += param_1.xythet;
	dataresol_1.gtg[15] += param_1.zthet;

/* hrm     Convert gtg to a vectorized form */

	for (i__ = 1; i__ <= 4; ++i__) {
	    for (k = 1; k <= 4; ++k) {
		gtg_v__[(i__ - 1 << 2) + k - 1] = dataresol_1.gtg[i__ + (k << 
			2) - 5];
	    }
	}
	matrinv_(&c__4, gtg_v__, ggti_v__);

/* hrm     Reconvert the vectorized matrix ggti_v to a 4 x 4 matrix */

	for (i__ = 1; i__ <= 4; ++i__) {
	    for (k = 1; k <= 4; ++k) {
		dataresol_1.ggti[i__ + (k << 2) - 5] = ggti_v__[(i__ - 1 << 2)
			 + k - 1];
	    }
	}

/* hrm     Calculate the generalized inverse */

	matrmult_(dataresol_1.ggti, &c__4, &c__4, dataresol_1.ggt, &c__4, &
		c__180, dataresol_1.ggg, &c__4, &c__180);

/* hrm     Calculate the data resolution matrix */

	matrmult_(dataresol_1.gg2, &c__180, &c__4, dataresol_1.ggg, &c__4, &
		c__180, dataresol_1.drm, &c__180, &c__180);

/* hrm     Data resolution matrix calculation finished! */

/* ek   print output *out.VEL for singleevent locations written by */
/*     subr. STATISLOUT: */

	statislout_();

/*        reset parameters... */

	form_1.iabort = 0;
	++coordsyst_1.isingle;
	form_1.nitt = 0;
	dimen_1.nvar = 0;
	dimen_1.icount = 0;
	istopflag = 0;
	iresflag = 0;
	nittc = 0;
	a3_1.ibackups = 0;
	goodness_1.ale[0] = 0.f;
	for (i__ = 1; i__ <= 3; ++i__) {
	    event_1.isconstrain[i__ - 1] = 0;
	}
	event_1.iconstrain[0] = 0;
	event_1.emag[0] = 0.f;
	event_1.nmag = 0;
	i__1 = obb_1.knobs[0];
	for (i__ = 1; i__ <= i__1; ++i__) {
	    event_1.xmagni[i__ - 1] = 0.f;
	    obb_1.amx[i__ - 1] = 0.f;
/* not necessary in this version; */
	    obb_1.prx[i__ - 1] = 0.f;
/* just in case, AMX&PRX will be used for *.CNV fi */
	    obb_1.istm[i__ - 1] = 0;
	}
	param_1.ifixsolution = 0;
	param_1.zmin = param_1.zmininput;
	goto L1080;
/* goto NEXT EVENT (SINGLE-EVENT-MODE !) */
    }

/*     come here if NOT 'single-event-mode' to terminate program... */

    cl__1.cerr = 0;
    cl__1.cunit = 8;
    cl__1.csta = 0;
    f_clos(&cl__1);

/* close data-input-file ( *.CNV ) */
    goto L99999;

/* L998: */
    openerror_("main program", "data-input-file FOR008", (ftnlen)12, (ftnlen)
	    22);

L99999:
    return 0;
} /* velest_ */


/* ********       E N D   O F   M A I N   P R O G R A M      **************** */

/* ek    begin of vel_io.f */

/* Subroutine */ int inputparam_(void)
{
    /* Format strings */
    static char fmt_7788[] = "(//,2x,\002attention nsp=3! >s-data used for p"
	    "-model too!\002,//)";
    static char fmt_17[] = "(1x,\002Velocity structure for model\002,i4,\002"
	    " :\002)";
    static char fmt_11[] = "(\002 \002,\002layer    vel   depth   vdamp  ref"
	    "lector\002)";
    static char fmt_1212[] = "(f5.2,5x,f7.2,2x,f7.3,3x,a1,1x,a40)";
    static char fmt_12[] = "(f5.2,5x,f7.2,2x,f7.3,3x,a1)";
    static char fmt_13[] = "(2x,i2,3x,2f7.2,1x,f7.2,1x,a1)";
    static char fmt_1[] = "(a80)";
    static char fmt_2[] = "(\002 \002,3x,\002 stn latitude longitude elev"
	    "\002,3x,\002x      y      z\002,5x,\002ptcor stcor model icc\002)"
	    ;
    static char fmt_27[] = "(1x,i3,1x,a4,f7.4,a1,f8.4,a1,1x,i5,3f7.2,1x,2f6."
	    "2,2i4)";
    static char fmt_19[] = "(3x,\002neqs=\002,i5,\002  nshot=\002,i5,\002  n"
	    "ltot=\002,i5,/)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1;
    olist o__1;
    cllist cl__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), e_rsfi(void), s_rsli(icilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_rsli(void), s_cmp(char *,
	     char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(void), s_wsle(
	    cilist *), e_wsle(void), s_wsli(icilist *), e_wsli(void), f_clos(
	    cllist *);

    /* Local variables */
    extern /* Subroutine */ int casefold_(char *, ftnlen);
    static integer i__, j, k, n;
    static real z__;
    static char titleline[80];
    extern /* Subroutine */ int openerror_(char *, char *, ftnlen, ftnlen);
    static integer ml;
    static real dx, dy, dz;
    static integer icc;
    extern /* Subroutine */ int sdc_(real *, real *, real *, real *, integer *
	    );
    static integer ifl;
    static char cew[1], cns[1], card[80];
    static integer ifil, mode;
    static char line[80*32];
    static real olat, olon;
    static char titl[40];
    extern /* Subroutine */ int geoko_(real *, real *, real *, real *, 
	    integer *);
    static real avelo;
    static integer jndex;
    extern /* Subroutine */ int maxii_(integer *, integer *, integer *, 
	    integer *);
    static char reflch[1];
    static real rotate;
    extern /* Subroutine */ int setorg_(real *, real *, real *, integer *);
    static logical lexist;
    extern integer trimlen_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___138 = { 0, 10, 1, "(a)", 0 };
    static icilist io___141 = { 0, line, 0, "(a)", 80, 1 };
    static icilist io___143 = { 0, line+80, 0, 0, 80, 1 };
    static icilist io___146 = { 0, line+160, 0, 0, 80, 1 };
    static icilist io___148 = { 0, line+240, 0, 0, 80, 1 };
    static icilist io___149 = { 0, line+320, 0, 0, 80, 1 };
    static icilist io___150 = { 0, line+400, 0, 0, 80, 1 };
    static icilist io___151 = { 0, line+480, 0, 0, 80, 1 };
    static icilist io___152 = { 0, line+560, 0, 0, 80, 1 };
    static icilist io___153 = { 0, line+640, 0, 0, 80, 1 };
    static icilist io___154 = { 0, line+720, 0, 0, 80, 1 };
    static icilist io___155 = { 0, line+800, 0, 0, 80, 1 };
    static icilist io___156 = { 0, line+880, 0, "(a)", 80, 1 };
    static icilist io___157 = { 0, line+960, 0, "(a)", 80, 1 };
    static icilist io___158 = { 0, line+1040, 0, "(a)", 80, 1 };
    static icilist io___159 = { 0, line+1120, 0, "(a)", 80, 1 };
    static icilist io___160 = { 0, line+1200, 0, "(a)", 80, 1 };
    static icilist io___161 = { 0, line+1280, 0, "(a)", 80, 1 };
    static icilist io___162 = { 0, line+1360, 0, "(a)", 80, 1 };
    static icilist io___163 = { 0, line+1440, 0, "(a)", 80, 1 };
    static icilist io___164 = { 0, line+1520, 0, "(a)", 80, 1 };
    static icilist io___165 = { 0, line+1600, 0, "(a)", 80, 1 };
    static icilist io___166 = { 0, line+1680, 0, "(a)", 80, 1 };
    static icilist io___167 = { 0, line+1760, 0, "(a)", 80, 1 };
    static icilist io___168 = { 0, line+1840, 0, "(a)", 80, 1 };
    static icilist io___169 = { 0, line+1920, 0, "(a)", 80, 1 };
    static icilist io___170 = { 0, line+2000, 0, "(a)", 80, 1 };
    static icilist io___171 = { 0, line+2080, 0, "(a)", 80, 1 };
    static icilist io___172 = { 0, line+2160, 0, "(a)", 80, 1 };
    static icilist io___173 = { 0, line+2240, 0, "(a)", 80, 1 };
    static icilist io___174 = { 0, line+2320, 0, "(a)", 80, 1 };
    static icilist io___175 = { 0, line+2400, 0, "(a)", 80, 1 };
    static icilist io___176 = { 0, line+2480, 0, "(a)", 80, 1 };
    static cilist io___177 = { 0, 16, 0, "(a)", 0 };
    static cilist io___178 = { 0, 16, 0, 0, 0 };
    static cilist io___179 = { 0, 16, 0, "(a)", 0 };
    static cilist io___180 = { 0, 16, 0, "(a)", 0 };
    static icilist io___181 = { 0, form_1.headerline+160, 0, 0, 80, 1 };
    static cilist io___182 = { 0, 16, 0, "(a)", 0 };
    static cilist io___183 = { 0, 16, 0, "(a)", 0 };
    static cilist io___184 = { 0, 16, 0, 0, 0 };
    static cilist io___185 = { 0, 16, 0, 0, 0 };
    static cilist io___186 = { 0, 16, 0, 0, 0 };
    static cilist io___187 = { 0, 16, 0, 0, 0 };
    static cilist io___189 = { 0, 16, 0, 0, 0 };
    static cilist io___190 = { 0, 16, 0, 0, 0 };
    static cilist io___191 = { 0, 16, 0, 0, 0 };
    static cilist io___192 = { 0, 16, 0, 0, 0 };
    static cilist io___193 = { 0, 16, 0, 0, 0 };
    static cilist io___194 = { 0, 16, 0, 0, 0 };
    static cilist io___195 = { 0, 16, 0, "(' Max. number of ',              "
	    "                               'EARTHQUAKES for simult. inversio"
	    "n IEQ = ',i3)", 0 };
    static cilist io___196 = { 0, 16, 0, "(' Max. number of ',              "
	    "                               'SHOTS for simult. inversion    I"
	    "NSHOT = ',i3)", 0 };
    static cilist io___197 = { 0, 16, 0, "(' Max. number of ',              "
	    "                               '(different) 1D-MODELS      ITOTM"
	    "ODELS = ',i3)", 0 };
    static cilist io___198 = { 0, 16, 0, "(' Max. number of ',              "
	    "                               'LAYERS per one 1D-model        I"
	    "NLTOT = ',i3)", 0 };
    static cilist io___199 = { 0, 16, 0, "(' Max. number of ',              "
	    "                               'STATIONS in stationlist         "
	    "  IST = ',i3)", 0 };
    static cilist io___200 = { 0, 16, 0, "(' Max. number of ',              "
	    "                               'OBSERVATIONS per event MAXOBSPER"
	    "EVENT = ',i3)", 0 };
    static cilist io___201 = { 0, 16, 0, 0, 0 };
    static cilist io___202 = { 0, 16, 0, 0, 0 };
    static cilist io___203 = { 0, 16, 0, "(///)", 0 };
    static cilist io___204 = { 0, 16, 0, 0, 0 };
    static cilist io___205 = { 0, 16, 0, "(//)", 0 };
    static cilist io___206 = { 0, 16, 0, "(a)", 0 };
    static cilist io___207 = { 0, 16, 0, "(a)", 0 };
    static cilist io___208 = { 0, 16, 0, "(1x,f10.6,f11.6,6x,i1,10x,f7.3,7x,"
	    "i1,3x,f6.2,6x,i1)", 0 };
    static cilist io___209 = { 0, 16, 0, "(a)", 0 };
    static cilist io___210 = { 0, 16, 0, "(a)", 0 };
    static cilist io___211 = { 0, 16, 0, "(1x,i6,1x,i6,3x,f6.1)", 0 };
    static cilist io___212 = { 0, 16, 0, "(a)", 0 };
    static cilist io___213 = { 0, 16, 0, "(a)", 0 };
    static cilist io___214 = { 0, 16, 0, "(7x,i1,10x,i1)", 0 };
    static cilist io___215 = { 0, 16, 0, "(a)", 0 };
    static cilist io___216 = { 0, 16, 0, "(a)", 0 };
    static cilist io___217 = { 0, 16, 0, "(2x,f7.2,5x,i1,4x,f6.2,6x,f5.2,3x,"
	    "f5.2,7x,i1)", 0 };
    static cilist io___218 = { 0, 16, 0, "(a)", 0 };
    static cilist io___219 = { 0, 16, 0, "(a)", 0 };
    static cilist io___220 = { 0, 16, 0, "(5x,i1,5x,f5.2,3x,f6.3,7x,i2)", 0 };
    static cilist io___221 = { 0, 16, 0, "(a)", 0 };
    static cilist io___222 = { 0, 16, 0, "(a)", 0 };
    static cilist io___223 = { 0, 16, 0, "(4x,5(f7.2,2x))", 0 };
    static cilist io___224 = { 0, 16, 0, "(a)", 0 };
    static cilist io___225 = { 0, 16, 0, "(a)", 0 };
    static cilist io___226 = { 0, 16, 0, "(7x,3(i1,7x),4x,i1,12x,i1)", 0 };
    static cilist io___227 = { 0, 16, 0, "(a)", 0 };
    static cilist io___228 = { 0, 16, 0, "(a)", 0 };
    static cilist io___229 = { 0, 16, 0, "(7x,i1,9x,i1,9x,i1,9x,i1)", 0 };
    static cilist io___230 = { 0, 16, 0, "(a)", 0 };
    static cilist io___231 = { 0, 16, 0, "(a)", 0 };
    static cilist io___232 = { 0, 16, 0, "(7x,i1,6(9x,i1))", 0 };
    static cilist io___233 = { 0, 16, 0, "(a)", 0 };
    static cilist io___234 = { 0, 16, 0, "(a)", 0 };
    static cilist io___235 = { 0, 16, 0, "(3x,f6.3,6x,i2,9x,i2)", 0 };
    static cilist io___236 = { 0, 16, 0, "(a)", 0 };
    static cilist io___237 = { 0, 16, 0, "(a)", 0 };
    static cilist io___238 = { 0, 16, 0, "(a)", 0 };
    static cilist io___239 = { 0, 16, 0, "(a)", 0 };
    static cilist io___240 = { 0, 16, 0, "(a)", 0 };
    static cilist io___241 = { 0, 16, 0, "(a)", 0 };
    static cilist io___242 = { 0, 16, 0, "(a)", 0 };
    static cilist io___243 = { 0, 16, 0, "(a)", 0 };
    static cilist io___244 = { 0, 16, 0, "(a)", 0 };
    static cilist io___245 = { 0, 16, 0, "(a)", 0 };
    static cilist io___246 = { 0, 16, 0, "(a)", 0 };
    static cilist io___247 = { 0, 16, 0, "(a)", 0 };
    static cilist io___248 = { 0, 16, 0, "(a)", 0 };
    static cilist io___249 = { 0, 16, 0, "(a)", 0 };
    static cilist io___250 = { 0, 16, 0, "(a)", 0 };
    static cilist io___251 = { 0, 16, 0, "(a)", 0 };
    static cilist io___252 = { 0, 16, 0, "(a)", 0 };
    static cilist io___253 = { 0, 16, 0, "(a)", 0 };
    static cilist io___254 = { 0, 16, 0, "(a)", 0 };
    static cilist io___255 = { 0, 16, 0, "(a)", 0 };
    static cilist io___256 = { 0, 16, 0, "(a)", 0 };
    static cilist io___257 = { 0, 16, 0, "(a)", 0 };
    static cilist io___258 = { 0, 16, 0, "(a)", 0 };
    static cilist io___259 = { 0, 16, 0, "(a)", 0 };
    static cilist io___260 = { 0, 16, 0, "(a)", 0 };
    static cilist io___261 = { 0, 16, 0, "(a)", 0 };
    static cilist io___262 = { 0, 16, 0, "(a)", 0 };
    static cilist io___263 = { 0, 16, 0, "(a)", 0 };
    static cilist io___264 = { 0, 16, 0, "(a)", 0 };
    static cilist io___265 = { 0, 16, 0, "(a)", 0 };
    static cilist io___266 = { 0, 16, 0, "(a)", 0 };
    static cilist io___267 = { 0, 16, 0, "(a)", 0 };
    static cilist io___268 = { 0, 16, 0, "(a)", 0 };
    static cilist io___269 = { 0, 16, 0, "(a)", 0 };
    static cilist io___270 = { 0, 16, 0, "(a)", 0 };
    static cilist io___271 = { 0, 16, 0, "(a)", 0 };
    static cilist io___272 = { 0, 16, 0, "(a)", 0 };
    static cilist io___273 = { 0, 16, 0, "(a)", 0 };
    static cilist io___274 = { 0, 16, 0, "(a)", 0 };
    static cilist io___275 = { 0, 16, 0, "(a)", 0 };
    static cilist io___276 = { 0, 16, 0, "(a)", 0 };
    static cilist io___277 = { 0, 16, 0, "(a)", 0 };
    static cilist io___278 = { 0, 16, 0, "(a)", 0 };
    static cilist io___279 = { 0, 16, 0, "(a)", 0 };
    static cilist io___280 = { 0, 16, 0, "(a)", 0 };
    static cilist io___281 = { 0, 16, 0, "(a)", 0 };
    static cilist io___282 = { 0, 16, 0, "(a)", 0 };
    static cilist io___283 = { 0, 16, 0, "(a)", 0 };
    static cilist io___284 = { 0, 16, 0, "(a)", 0 };
    static cilist io___285 = { 0, 16, 0, "(a)", 0 };
    static cilist io___286 = { 0, 16, 0, "(a)", 0 };
    static cilist io___287 = { 0, 16, 0, "(a)", 0 };
    static cilist io___288 = { 0, 16, 0, "(a)", 0 };
    static cilist io___289 = { 0, 16, 0, "(a)", 0 };
    static cilist io___290 = { 0, 16, 0, "(a)", 0 };
    static cilist io___291 = { 0, 16, 0, "(a)", 0 };
    static cilist io___292 = { 0, 16, 0, "(a)", 0 };
    static cilist io___293 = { 0, 16, 0, "(a)", 0 };
    static cilist io___294 = { 0, 16, 0, "(a)", 0 };
    static cilist io___295 = { 0, 16, 0, "(a)", 0 };
    static cilist io___296 = { 0, 16, 0, "(a)", 0 };
    static cilist io___297 = { 0, 16, 0, "(a)", 0 };
    static cilist io___298 = { 0, 16, 0, "(a)", 0 };
    static cilist io___299 = { 0, 16, 0, "(a)", 0 };
    static cilist io___300 = { 0, 16, 0, "(a)", 0 };
    static cilist io___301 = { 0, 16, 0, "(a)", 0 };
    static cilist io___302 = { 0, 16, 0, "(a)", 0 };
    static cilist io___303 = { 0, 16, 0, "(a)", 0 };
    static cilist io___304 = { 0, 16, 0, "(///)", 0 };
    static cilist io___305 = { 0, 16, 0, 0, 0 };
    static cilist io___306 = { 0, 16, 0, "(6x,f10.5,2hN ,f11.5,1hE)", 0 };
    static cilist io___307 = { 0, 16, 0, "(6x,f10.5,2hN ,f11.5,1hW)", 0 };
    static cilist io___308 = { 0, 16, 0, 0, 0 };
    static cilist io___309 = { 0, 16, 0, 0, 0 };
    static cilist io___310 = { 0, 16, 0, 0, 0 };
    static cilist io___311 = { 0, 16, 0, 0, 0 };
    static cilist io___312 = { 0, 16, 0, 0, 0 };
    static cilist io___313 = { 0, 16, 0, "(12x,7hrotate=,1x,f6.1,1x,5hdegr.)",
	     0 };
    static cilist io___314 = { 0, 16, 0, 0, 0 };
    static cilist io___315 = { 0, 16, 0, 0, 0 };
    static cilist io___316 = { 0, 16, 0, 0, 0 };
    static cilist io___317 = { 0, 16, 0, 0, 0 };
    static cilist io___318 = { 0, 16, 0, 0, 0 };
    static cilist io___319 = { 0, 16, 0, 0, 0 };
    static cilist io___320 = { 0, 16, 0, 0, 0 };
    static cilist io___321 = { 0, 16, 0, 0, 0 };
    static cilist io___322 = { 0, 16, 0, 0, 0 };
    static cilist io___323 = { 0, 16, 0, 0, 0 };
    static cilist io___324 = { 0, 16, 0, 0, 0 };
    static cilist io___325 = { 0, 16, 0, 0, 0 };
    static cilist io___326 = { 0, 16, 0, 0, 0 };
    static cilist io___328 = { 0, 16, 0, 0, 0 };
    static cilist io___329 = { 0, 16, 0, 0, 0 };
    static cilist io___330 = { 0, 16, 0, 0, 0 };
    static cilist io___331 = { 0, 16, 0, 0, 0 };
    static cilist io___332 = { 0, 16, 0, 0, 0 };
    static cilist io___333 = { 0, 16, 0, 0, 0 };
    static cilist io___334 = { 0, 16, 0, 0, 0 };
    static cilist io___335 = { 0, 16, 0, 0, 0 };
    static cilist io___336 = { 0, 16, 0, 0, 0 };
    static cilist io___337 = { 0, 16, 0, 0, 0 };
    static cilist io___338 = { 0, 16, 0, "(///)", 0 };
    static cilist io___339 = { 0, 16, 0, 0, 0 };
    static cilist io___340 = { 0, 16, 0, "(//)", 0 };
    static cilist io___341 = { 0, 16, 0, 0, 0 };
    static cilist io___342 = { 0, 16, 0, 0, 0 };
    static cilist io___343 = { 0, 16, 0, 0, 0 };
    static cilist io___344 = { 0, 16, 0, fmt_7788, 0 };
    static cilist io___345 = { 0, 10, 0, "(a40)", 0 };
    static cilist io___347 = { 0, 16, 0, "(a)", 0 };
    static cilist io___348 = { 0, 16, 0, fmt_17, 0 };
    static cilist io___349 = { 0, 16, 0, 0, 0 };
    static cilist io___350 = { 0, 16, 0, fmt_11, 0 };
    static cilist io___351 = { 0, 10, 0, "(i3)", 0 };
    static cilist io___353 = { 0, 10, 0, fmt_1212, 0 };
    static cilist io___355 = { 0, 10, 0, fmt_12, 0 };
    static cilist io___356 = { 0, 16, 0, 0, 0 };
    static cilist io___357 = { 0, 6, 0, 0, 0 };
    static cilist io___358 = { 0, 6, 0, 0, 0 };
    static cilist io___359 = { 0, 16, 0, 0, 0 };
    static cilist io___360 = { 0, 16, 0, 0, 0 };
    static cilist io___361 = { 0, 16, 0, 0, 0 };
    static cilist io___362 = { 0, 16, 0, 0, 0 };
    static cilist io___363 = { 0, 6, 0, 0, 0 };
    static cilist io___364 = { 0, 6, 0, 0, 0 };
    static cilist io___365 = { 0, 16, 0, "(2x,i2,3x,2f7.2,1x,f7.2,1x,a1,1x,a"
	    "40)", 0 };
    static cilist io___366 = { 0, 16, 0, fmt_13, 0 };
    static cilist io___367 = { 0, 6, 0, 0, 0 };
    static cilist io___368 = { 0, 6, 0, 0, 0 };
    static cilist io___369 = { 0, 6, 0, 0, 0 };
    static cilist io___370 = { 0, 16, 0, 0, 0 };
    static cilist io___371 = { 0, 16, 0, 0, 0 };
    static cilist io___373 = { 0, 16, 0, 0, 0 };
    static cilist io___374 = { 0, 16, 0, 0, 0 };
    static cilist io___376 = { 0, 16, 0, "(' z =',f6.2,' ...',f6.2,'    v = "
	    "',f4.2,                   '    AVEL = ',f4.2,' downto z = ',f6.2)"
	    , 0 };
    static cilist io___377 = { 0, 16, 0, 0, 0 };
    static cilist io___378 = { 0, 16, 0, 0, 0 };
    static cilist io___379 = { 0, 16, 0, 0, 0 };
    static cilist io___380 = { 0, 16, 0, "(' z =',f6.2,' ...',f6.2,'    v = "
	    "',f4.2,                   '    AVEL = ',f4.2,' downto z = ',f6.2)"
	    , 0 };
    static cilist io___381 = { 0, 16, 0, 0, 0 };
    static cilist io___382 = { 0, 16, 0, 0, 0 };
    static cilist io___383 = { 0, 16, 0, 0, 0 };
    static cilist io___384 = { 0, 16, 0, "(1x,'Phases in the input-phaselist"
	    " marked with a  ',            a1,/,' are treated as reflections "
	    "from the bottom ',            'of layer nr. ',i2)", 0 };
    static cilist io___385 = { 0, 16, 0, 0, 0 };
    static cilist io___386 = { 0, 16, 0, 0, 0 };
    static cilist io___387 = { 0, 16, 0, 0, 0 };
    static cilist io___388 = { 0, 6, 0, 0, 0 };
    static cilist io___389 = { 0, 6, 0, 0, 0 };
    static cilist io___390 = { 0, 6, 0, 0, 0 };
    static cilist io___391 = { 0, 16, 0, "(///)", 0 };
    static cilist io___392 = { 0, 16, 0, 0, 0 };
    static cilist io___393 = { 0, 16, 0, "(//)", 0 };
    static cilist io___394 = { 0, 16, 0, 0, 0 };
    static cilist io___395 = { 0, 16, 0, 0, 0 };
    static cilist io___396 = { 0, 16, 0, 0, 0 };
    static cilist io___397 = { 0, 10, 0, fmt_1, 0 };
    static cilist io___398 = { 0, 16, 0, 0, 0 };
    static cilist io___399 = { 0, 16, 0, fmt_2, 0 };
    static cilist io___400 = { 0, 10, 0, form_1.fm, 0 };
    static cilist io___409 = { 0, 16, 0, fmt_27, 0 };
    static cilist io___410 = { 0, 16, 0, 0, 0 };
    static cilist io___411 = { 0, 16, 0, 0, 0 };
    static cilist io___412 = { 0, 16, 0, 0, 0 };
    static cilist io___413 = { 0, 16, 0, 0, 0 };
    static cilist io___414 = { 0, 16, 0, 0, 0 };
    static cilist io___415 = { 0, 16, 0, 0, 0 };
    static cilist io___416 = { 0, 16, 0, 0, 0 };
    static cilist io___417 = { 0, 16, 0, 0, 0 };
    static cilist io___418 = { 0, 16, 0, 0, 0 };
    static cilist io___419 = { 0, 16, 0, 0, 0 };
    static cilist io___420 = { 0, 16, 0, 0, 0 };
    static cilist io___421 = { 0, 16, 0, 0, 0 };
    static cilist io___422 = { 0, 16, 0, 0, 0 };
    static cilist io___423 = { 0, 16, 0, 0, 0 };
    static cilist io___424 = { 0, 16, 0, 0, 0 };
    static cilist io___427 = { 0, 16, 0, 0, 0 };
    static cilist io___428 = { 0, 16, 0, fmt_19, 0 };


/*                           ! this subr. needs another input-format !! */

/*     reads in the control-file (type VELEST.CMN) which contains all the */
/*     control-parameters for a VELEST-run */

/* old name was: INPUT1 ; */
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


/*     Open control-inputfile: */

    ioin__1.inerr = 0;
    ioin__1.infilen = 10;
    ioin__1.infile = "velest.cmn";
    ioin__1.inex = &lexist;
    ioin__1.inopen = 0;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (! lexist) {
	s_stop("INPUTPARAM>>> control file `velest.cmn` not found!", (ftnlen)
		50);
    }
/* VMS      open(10,file='velest.cmn',status='old',err=9910,readonly) */
    o__1.oerr = 1;
    o__1.ounit = 10;
    o__1.ofnmlen = 10;
    o__1.ofnm = "velest.cmn";
    o__1.orl = 0;
    o__1.osta = "unknown";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L9910;
    }

/*     input center of coordinate system */

    i__ = 0;
L111:
    i__1 = s_rsfe(&io___138);
    if (i__1 != 0) {
	goto L222;
    }
    i__1 = do_fio(&c__1, card, (ftnlen)80);
    if (i__1 != 0) {
	goto L222;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L222;
    }
    if (*(unsigned char *)card == '*') {
	goto L111;
    }
    ++i__;
    if (i__ > 32) {
	s_stop("INPUTPARAM>>> control-file not correct!", (ftnlen)39);
    }
    s_copy(line + (i__ - 1) * 80, card, (ftnlen)80, (ftnlen)80);
    goto L111;
L222:
    if (! (i__ == 24 || (real) i__ == 32.f)) {
	s_stop("INPUTPARAM>>> control-file not correct!", (ftnlen)39);
    }
    s_rsfi(&io___141);
    do_fio(&c__1, titleline, (ftnlen)80);
    e_rsfi();
    s_rsli(&io___143);
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
    s_rsli(&io___146);
    do_lio(&c__3, &c__1, (char *)&dimen_1.neqs, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&dimen_1.nshot, (ftnlen)sizeof(integer));
    do_lio(&c__4, &c__1, (char *)&rotate, (ftnlen)sizeof(real));
    e_rsli();
    s_rsli(&io___148);
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer)
	    );
    do_lio(&c__3, &c__1, (char *)&param_1.iresolcalc, (ftnlen)sizeof(integer))
	    ;
    e_rsli();
    s_rsli(&io___149);
    do_lio(&c__4, &c__1, (char *)&param_1.dmax__, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.itopo, (ftnlen)sizeof(integer));
    do_lio(&c__4, &c__1, (char *)&param_1.zmininput, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.veladj, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.zadj, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.lowveloclay, (ftnlen)sizeof(
	    integer));
    e_rsli();
    s_rsli(&io___150);
    do_lio(&c__3, &c__1, (char *)&modela_1.nsp, (ftnlen)sizeof(integer));
    do_lio(&c__4, &c__1, (char *)&param_1.swtfac, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&layvel_1.vpvs, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&modela_1.nmod, (ftnlen)sizeof(integer));
    e_rsli();
    s_rsli(&io___151);
    do_lio(&c__4, &c__1, (char *)&param_1.othet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.xythet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.zthet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.vthet, (ftnlen)sizeof(real));
    do_lio(&c__4, &c__1, (char *)&param_1.stathet, (ftnlen)sizeof(real));
    e_rsli();
    s_rsli(&io___152);
    do_lio(&c__3, &c__1, (char *)&dimen_1.nsinv, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&dimen_1.nshcor, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&dimen_1.nshfix, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.iuseelev, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.iusestacorr, (ftnlen)sizeof(
	    integer));
    e_rsli();
    s_rsli(&io___153);
    do_lio(&c__3, &c__1, (char *)&coordsyst_1.iturbo, (ftnlen)sizeof(integer))
	    ;
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.icnvout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.istaout, (ftnlen)sizeof(
	    integer));
    do_lio(&c__3, &c__1, (char *)&outputfiles_1.ismpout, (ftnlen)sizeof(
	    integer));
    e_rsli();
    s_rsli(&io___154);
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
    s_rsli(&io___155);
    do_lio(&c__4, &c__1, (char *)&param_1.delmin, (ftnlen)sizeof(real));
    do_lio(&c__3, &c__1, (char *)&param_1.ittmax, (ftnlen)sizeof(integer));
    do_lio(&c__3, &c__1, (char *)&param_1.invertratio, (ftnlen)sizeof(integer)
	    );
    e_rsli();
    s_rsfi(&io___156);
    do_fio(&c__1, files_1.modelfilename, (ftnlen)80);
    e_rsfi();
    s_rsfi(&io___157);
    do_fio(&c__1, files_1.stationfilename, (ftnlen)80);
    e_rsfi();
    s_rsfi(&io___158);
    do_fio(&c__1, files_1.seismofilename, (ftnlen)80);
    e_rsfi();
    s_rsfi(&io___159);
    do_fio(&c__1, infiles_1.regnamfile, (ftnlen)80);
    e_rsfi();
    s_rsfi(&io___160);
    do_fio(&c__1, infiles_1.regkoordfile, (ftnlen)80);
    e_rsfi();
    s_rsfi(&io___161);
    do_fio(&c__1, infiles_1.topo1file, (ftnlen)80);
    e_rsfi();
    s_rsfi(&io___162);
    do_fio(&c__1, infiles_1.topo2file, (ftnlen)80);
    e_rsfi();
    s_rsfi(&io___163);
    do_fio(&c__1, infiles_1.phasefile, (ftnlen)80);
    e_rsfi();
    s_rsfi(&io___164);
    do_fio(&c__1, infiles_1.shotfile, (ftnlen)80);
    e_rsfi();
/*     Output files: */
    s_rsfi(&io___165);
    do_fio(&c__1, outfiles_1.outfile, (ftnlen)80);
    e_rsfi();
    if (s_cmp(outfiles_1.outfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	s_copy(outfiles_1.outfile, "vel.out", (ftnlen)80, (ftnlen)7);
    }
    s_rsfi(&io___166);
    do_fio(&c__1, outfiles_1.velfile, (ftnlen)80);
    e_rsfi();
    if (s_cmp(outfiles_1.velfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	s_copy(outfiles_1.velfile, "velout.vel", (ftnlen)80, (ftnlen)10);
    }
    s_rsfi(&io___167);
    do_fio(&c__1, outfiles_1.cnvfile, (ftnlen)80);
    e_rsfi();
    if (s_cmp(outfiles_1.cnvfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	s_copy(outfiles_1.cnvfile, "velout.cnv", (ftnlen)80, (ftnlen)10);
    }
    s_rsfi(&io___168);
    do_fio(&c__1, outfiles_1.stafile, (ftnlen)80);
    e_rsfi();
    if (s_cmp(outfiles_1.stafile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	s_copy(outfiles_1.stafile, "velout.sta", (ftnlen)80, (ftnlen)10);
    }

/*     the next few ouputfiles are not very often used, therefore */
/*     either all or none of them have to be specified in the controlfile: */

    if (i__ == 32) {
	s_rsfi(&io___169);
	do_fio(&c__1, outfiles_1.smpfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.smpfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.smpfile, "velout.smp", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___170);
	do_fio(&c__1, outfiles_1.rayfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.rayfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.rayfile, "velout.ray", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___171);
	do_fio(&c__1, outfiles_1.drvfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.drvfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.drvfile, "velout.drv", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___172);
	do_fio(&c__1, outfiles_1.alefile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.alefile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.alefile, "velout.ale", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___173);
	do_fio(&c__1, outfiles_1.dsprfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.dsprfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.dsprfile, "velout.dspr", (ftnlen)80, (ftnlen)11)
		    ;
	}
	s_rsfi(&io___174);
	do_fio(&c__1, outfiles_1.rflfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.rflfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.rflfile, "velout.rfl", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___175);
	do_fio(&c__1, outfiles_1.rfrfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.rfrfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.rfrfile, "velout.rfr", (ftnlen)80, (ftnlen)10);
	}
	s_rsfi(&io___176);
	do_fio(&c__1, outfiles_1.resfile, (ftnlen)80);
	e_rsfi();
	if (s_cmp(outfiles_1.resfile, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    s_copy(outfiles_1.resfile, "velout.res", (ftnlen)80, (ftnlen)10);
	}
    }

    coordsyst_1.single_turbo__ = FALSE_;
    if (coordsyst_1.isingle == 1 && coordsyst_1.iturbo == 1) {
	coordsyst_1.single_turbo__ = TRUE_;
    }

/*     open the main-output-file: */

    if (! coordsyst_1.single_turbo__) {
/* VMS         open(16,file=outfile,status='new',carriagecontrol='list') */
	o__1.oerr = 0;
	o__1.ounit = 16;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.outfile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
	s_wsfe(&io___177);
	do_fio(&c__1, form_1.headerline, (ftnlen)80);
	e_wsfe();
	s_wsle(&io___178);
	e_wsle();
	s_wsfe(&io___179);
	do_fio(&c__1, form_1.headerline + 80, (ftnlen)80);
	e_wsfe();
	s_wsfe(&io___180);
	do_fio(&c__1, form_1.headerline + 160, (ftnlen)80);
	e_wsfe();
	s_wsli(&io___181);
	do_lio(&c__9, &c__1, " (Authors: see source code)", (ftnlen)27);
	e_wsli();
	s_wsfe(&io___182);
	do_fio(&c__1, form_1.headerline + 160, (ftnlen)80);
	e_wsfe();
	s_wsfe(&io___183);
	do_fio(&c__1, form_1.headerline + 80, (ftnlen)80);
	e_wsfe();
	s_wsle(&io___184);
	e_wsle();
	s_wsle(&io___185);
	e_wsle();
	s_wsle(&io___186);
	do_lio(&c__9, &c__1, "Title of this VELEST run:", (ftnlen)25);
	e_wsle();
	s_wsle(&io___187);
	e_wsle();
	n = trimlen_(titleline, (ftnlen)80);
	s_wsle(&io___189);
	do_lio(&c__9, &c__1, titleline, n);
	e_wsle();
	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    *(unsigned char *)&titleline[i__ - 1] = '-';
	}
	s_wsle(&io___190);
	do_lio(&c__9, &c__1, titleline, n);
	e_wsle();
	s_wsle(&io___191);
	e_wsle();
	s_wsle(&io___192);
	e_wsle();
	s_wsle(&io___193);
	do_lio(&c__9, &c__1, "Current array-dimensions of program VELEST:", (
		ftnlen)43);
	e_wsle();
	s_wsle(&io___194);
	e_wsle();
	s_wsfe(&io___195);
	do_fio(&c__1, (char *)&c__6000, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___196);
	do_fio(&c__1, (char *)&c__50, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___197);
	do_fio(&c__1, (char *)&c__2, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___198);
	do_fio(&c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___199);
	do_fio(&c__1, (char *)&c__650, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___200);
	do_fio(&c__1, (char *)&c__180, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsle(&io___201);
	e_wsle();
	s_wsle(&io___202);
	e_wsle();
    }

/* ek 210495: check for reasonable switch combinations nmod,nsp */

    if (modela_1.nsp < 1) {
	modela_1.nsp = 1;
    }
    if (modela_1.nsp > 3) {
	modela_1.nsp = 3;
    }
/* nsp=1 P-model and p-data only */
/* nsp=2 P-model (+data) and S-model (+data) independently used */
/* nsp=3 P-model (+data) and S-model dependent on P-model (vpvs-factor used) */
    if (modela_1.nsp == 2) {
	modela_1.nmod = 2;
    } else {
	modela_1.nmod = 1;
    }

/* ek 210495 */

/*     print the input-parameters */

    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___203);
	e_wsfe();
	s_wsle(&io___204);
	do_lio(&c__9, &c__1, "   INPUT - P A R A M E T E R S :", (ftnlen)32);
	e_wsle();
	s_wsfe(&io___205);
	e_wsfe();
	s_wsfe(&io___206);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___207);
	do_fio(&c__1, "***  olat       olon   icoordsystem      zshift   itr"
		"ial ztrial    ised", (ftnlen)71);
	e_wsfe();
	s_wsfe(&io___208);
	do_fio(&c__1, (char *)&olat, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&olon, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&coordsyst_1.icoordsystem, (ftnlen)sizeof(
		integer));
	do_fio(&c__1, (char *)&corr_1.zshift, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&coordsyst_1.itrial, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&coordsyst_1.ztrial, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&coordsyst_1.ised, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___209);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___210);
	do_fio(&c__1, "*** neqs   nshot    rotate", (ftnlen)26);
	e_wsfe();
	s_wsfe(&io___211);
	do_fio(&c__1, (char *)&dimen_1.neqs, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&dimen_1.nshot, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&rotate, (ftnlen)sizeof(real));
	e_wsfe();
	s_wsfe(&io___212);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___213);
	do_fio(&c__1, "*** isingle   iresolcalc", (ftnlen)24);
	e_wsfe();
	s_wsfe(&io___214);
	do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&param_1.iresolcalc, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___215);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___216);
	do_fio(&c__1, "*** dmax    itopo    zmin     veladj    zadj   lowvel"
		"oclay", (ftnlen)58);
	e_wsfe();
	s_wsfe(&io___217);
	do_fio(&c__1, (char *)&param_1.dmax__, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&coordsyst_1.itopo, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&param_1.zmininput, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&param_1.veladj, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&param_1.zadj, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&coordsyst_1.lowveloclay, (ftnlen)sizeof(
		integer));
	e_wsfe();
	s_wsfe(&io___218);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___219);
	do_fio(&c__1, "*** nsp    swtfac   vpvs       nmod", (ftnlen)35);
	e_wsfe();
	s_wsfe(&io___220);
	do_fio(&c__1, (char *)&modela_1.nsp, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&param_1.swtfac, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&layvel_1.vpvs, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&modela_1.nmod, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___221);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___222);
	do_fio(&c__1, "***   othet   xythet    zthet    vthet   stathet", (
		ftnlen)48);
	e_wsfe();
	s_wsfe(&io___223);
	do_fio(&c__1, (char *)&param_1.othet, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&param_1.xythet, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&param_1.zthet, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&param_1.vthet, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&param_1.stathet, (ftnlen)sizeof(real));
	e_wsfe();
	s_wsfe(&io___224);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___225);
	do_fio(&c__1, "*** nsinv   nshcor   nshfix     iuseelev    iusestaco"
		"rr", (ftnlen)55);
	e_wsfe();
	s_wsfe(&io___226);
	do_fio(&c__1, (char *)&dimen_1.nsinv, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&dimen_1.nshcor, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&dimen_1.nshfix, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&coordsyst_1.iuseelev, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&coordsyst_1.iusestacorr, (ftnlen)sizeof(
		integer));
	e_wsfe();
	s_wsfe(&io___227);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___228);
	do_fio(&c__1, "*** iturbo    icnvout   istaout   ismpout", (ftnlen)41)
		;
	e_wsfe();
	s_wsfe(&io___229);
	do_fio(&c__1, (char *)&coordsyst_1.iturbo, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&outputfiles_1.icnvout, (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&outputfiles_1.istaout, (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&outputfiles_1.ismpout, (ftnlen)sizeof(integer))
		;
	e_wsfe();
	s_wsfe(&io___230);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___231);
	do_fio(&c__1, "*** irayout   idrvout   ialeout   idspout   irflout  "
		" irfrout   iresout", (ftnlen)71);
	e_wsfe();
	s_wsfe(&io___232);
	do_fio(&c__1, (char *)&outputfiles_1.irayout, (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&outputfiles_1.idrvout, (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&outputfiles_1.ialeout, (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&outputfiles_1.idspout, (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&outputfiles_1.irflout, (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&outputfiles_1.irfrout, (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&outputfiles_1.iresout, (ftnlen)sizeof(integer))
		;
	e_wsfe();
	s_wsfe(&io___233);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___234);
	do_fio(&c__1, "*** delmin   ittmax   invertratio", (ftnlen)33);
	e_wsfe();
	s_wsfe(&io___235);
	do_fio(&c__1, (char *)&param_1.delmin, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&param_1.ittmax, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&param_1.invertratio, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___236);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___237);
	do_fio(&c__1, "*** Modelfile:", (ftnlen)14);
	e_wsfe();
	s_wsfe(&io___238);
	do_fio(&c__1, files_1.modelfilename, trimlen_(files_1.modelfilename, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___239);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___240);
	do_fio(&c__1, "*** Stationfile:", (ftnlen)16);
	e_wsfe();
	s_wsfe(&io___241);
	do_fio(&c__1, files_1.stationfilename, trimlen_(
		files_1.stationfilename, (ftnlen)80));
	e_wsfe();
	s_wsfe(&io___242);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___243);
	do_fio(&c__1, "*** Seismofile:", (ftnlen)15);
	e_wsfe();
	s_wsfe(&io___244);
	do_fio(&c__1, files_1.seismofilename, trimlen_(files_1.seismofilename,
		 (ftnlen)80));
	e_wsfe();
	s_wsfe(&io___245);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___246);
	do_fio(&c__1, "*** File with region names:", (ftnlen)27);
	e_wsfe();
	s_wsfe(&io___247);
	do_fio(&c__1, infiles_1.regnamfile, trimlen_(infiles_1.regnamfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___248);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___249);
	do_fio(&c__1, "*** File with region coordinates:", (ftnlen)33);
	e_wsfe();
	s_wsfe(&io___250);
	do_fio(&c__1, infiles_1.regkoordfile, trimlen_(infiles_1.regkoordfile,
		 (ftnlen)80));
	e_wsfe();
	s_wsfe(&io___251);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___252);
	do_fio(&c__1, "*** File #1 with topo data:", (ftnlen)27);
	e_wsfe();
	s_wsfe(&io___253);
	do_fio(&c__1, infiles_1.topo1file, trimlen_(infiles_1.topo1file, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___254);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___255);
	do_fio(&c__1, "*** File #2 with topo data:", (ftnlen)27);
	e_wsfe();
	s_wsfe(&io___256);
	do_fio(&c__1, infiles_1.topo2file, trimlen_(infiles_1.topo2file, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___257);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___258);
	do_fio(&c__1, "*** DATA INPUT files:", (ftnlen)21);
	e_wsfe();
	s_wsfe(&io___259);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___260);
	do_fio(&c__1, "*** File with Earthquake data:", (ftnlen)30);
	e_wsfe();
	s_wsfe(&io___261);
	do_fio(&c__1, infiles_1.phasefile, trimlen_(infiles_1.phasefile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___262);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___263);
	do_fio(&c__1, "*** File with Shot data:", (ftnlen)24);
	e_wsfe();
	s_wsfe(&io___264);
	do_fio(&c__1, infiles_1.shotfile, trimlen_(infiles_1.shotfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___265);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___266);
	do_fio(&c__1, "*** OUTPUT files:", (ftnlen)17);
	e_wsfe();
	s_wsfe(&io___267);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___268);
	do_fio(&c__1, "*** Main print output file:", (ftnlen)27);
	e_wsfe();
	s_wsfe(&io___269);
	do_fio(&c__1, outfiles_1.outfile, trimlen_(outfiles_1.outfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___270);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___271);
	do_fio(&c__1, "*** File with single event locations:", (ftnlen)37);
	e_wsfe();
	s_wsfe(&io___272);
	do_fio(&c__1, outfiles_1.velfile, trimlen_(outfiles_1.velfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___273);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___274);
	do_fio(&c__1, "*** File with final hypocenters in *.cnv format:", (
		ftnlen)48);
	e_wsfe();
	s_wsfe(&io___275);
	do_fio(&c__1, outfiles_1.cnvfile, trimlen_(outfiles_1.cnvfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___276);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___277);
	do_fio(&c__1, "*** File with new station corrections:", (ftnlen)38);
	e_wsfe();
	s_wsfe(&io___278);
	do_fio(&c__1, outfiles_1.stafile, trimlen_(outfiles_1.stafile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___279);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___280);
	do_fio(&c__1, "*** File with summary cards (e.g. for plotting):", (
		ftnlen)48);
	e_wsfe();
	s_wsfe(&io___281);
	do_fio(&c__1, outfiles_1.smpfile, trimlen_(outfiles_1.smpfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___282);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___283);
	do_fio(&c__1, "*** File with raypoints:", (ftnlen)24);
	e_wsfe();
	s_wsfe(&io___284);
	do_fio(&c__1, outfiles_1.rayfile, trimlen_(outfiles_1.rayfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___285);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___286);
	do_fio(&c__1, "*** File with derivatives:", (ftnlen)26);
	e_wsfe();
	s_wsfe(&io___287);
	do_fio(&c__1, outfiles_1.drvfile, trimlen_(outfiles_1.drvfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___288);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___289);
	do_fio(&c__1, "*** File with ALEs:", (ftnlen)19);
	e_wsfe();
	s_wsfe(&io___290);
	do_fio(&c__1, outfiles_1.alefile, trimlen_(outfiles_1.alefile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___291);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___292);
	do_fio(&c__1, "*** File with Dirichlet spreads:", (ftnlen)32);
	e_wsfe();
	s_wsfe(&io___293);
	do_fio(&c__1, outfiles_1.dsprfile, trimlen_(outfiles_1.dsprfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___294);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___295);
	do_fio(&c__1, "*** File with reflection points:", (ftnlen)32);
	e_wsfe();
	s_wsfe(&io___296);
	do_fio(&c__1, outfiles_1.rflfile, trimlen_(outfiles_1.rflfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___297);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___298);
	do_fio(&c__1, "*** File with refraction points:", (ftnlen)32);
	e_wsfe();
	s_wsfe(&io___299);
	do_fio(&c__1, outfiles_1.rfrfile, trimlen_(outfiles_1.rfrfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___300);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___301);
	do_fio(&c__1, "*** File with residuals:", (ftnlen)24);
	e_wsfe();
	s_wsfe(&io___302);
	do_fio(&c__1, outfiles_1.resfile, trimlen_(outfiles_1.resfile, (
		ftnlen)80));
	e_wsfe();
	s_wsfe(&io___303);
	do_fio(&c__1, "***", (ftnlen)3);
	e_wsfe();
	s_wsfe(&io___304);
	e_wsfe();
    }

/*     remarks concerning OLAT & OLON: */
/*     Both olat and olon are input in decimal-degrees. */
/*     For LAT N(orth) and LON W(est) their values are positive. */
/*     For LAT S(outh) and LON E(ast) their values must be negative! */

/*     For more details see comments on top of this program-source! */

    param_1.zmin = param_1.zmininput;

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___305);
	do_lio(&c__9, &c__1, "Origin of cartesian coordinates:", (ftnlen)32);
	e_wsle();
	if (olon <= 0.f) {
	    s_wsfe(&io___306);
	    do_fio(&c__1, (char *)&olat, (ftnlen)sizeof(real));
	    r__1 = -olon;
	    do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	    e_wsfe();
	} else {
	    s_wsfe(&io___307);
	    do_fio(&c__1, (char *)&olat, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&olon, (ftnlen)sizeof(real));
	    e_wsfe();
	}
	if (olon == 0.f && olat == 0.f) {
	    s_wsle(&io___308);
	    do_lio(&c__9, &c__1, "Origin BERNE is taken!", (ftnlen)22);
	    e_wsle();
	    s_wsle(&io___309);
	    do_lio(&c__9, &c__1, "OLAT=46.95240 n OLON=7.439583 e", (ftnlen)
		    31);
	    e_wsle();
	}
	s_wsle(&io___310);
	e_wsle();
	s_wsle(&io___311);
	do_lio(&c__9, &c__1, " X,Y-AXES rotated clockwise from North", (
		ftnlen)38);
	e_wsle();
	s_wsle(&io___312);
	do_lio(&c__9, &c__1, "          Rotation angle (rotate):", (ftnlen)34)
		;
	e_wsle();
	s_wsfe(&io___313);
	do_fio(&c__1, (char *)&rotate, (ftnlen)sizeof(real));
	e_wsfe();
	s_wsle(&io___314);
	e_wsle();

	if (coordsyst_1.itrial > 0) {
	    s_wsle(&io___315);
	    e_wsle();
	    s_wsle(&io___316);
	    do_lio(&c__9, &c__1, " ========================================="
		    "===", (ftnlen)45);
	    e_wsle();
	    s_wsle(&io___317);
	    do_lio(&c__9, &c__1, " trial epicenter ~ earliest station", (
		    ftnlen)35);
	    e_wsle();
	    s_wsle(&io___318);
	    do_lio(&c__9, &c__1, " trial depth = ztrial = ", (ftnlen)24);
	    do_lio(&c__4, &c__1, (char *)&coordsyst_1.ztrial, (ftnlen)sizeof(
		    real));
	    e_wsle();
	    s_wsle(&io___319);
	    do_lio(&c__9, &c__1, " ========================================="
		    "===", (ftnlen)45);
	    e_wsle();
	    s_wsle(&io___320);
	    e_wsle();
	}

	if (coordsyst_1.icoordsystem == 2) {
	    s_wsle(&io___321);
	    do_lio(&c__9, &c__1, "SWISS COORDINATES will be used instead of "
		    "the", (ftnlen)45);
	    do_lio(&c__9, &c__1, " short distance conversion!", (ftnlen)27);
	    e_wsle();
	    s_wsle(&io___322);
	    do_lio(&c__9, &c__1, "origin BERNE: x=600.km, y=200.km", (ftnlen)
		    32);
	    e_wsle();
	    s_wsle(&io___323);
	    do_lio(&c__9, &c__1, "x is positive towards east,", (ftnlen)27);
	    do_lio(&c__9, &c__1, " y is positive towards north", (ftnlen)28);
	    e_wsle();
/* cc            write(16,*)'---> no rotation can be performed !!!' */
	} else {
	    s_wsle(&io___324);
	    do_lio(&c__9, &c__1, "icoordsystem = ", (ftnlen)15);
	    do_lio(&c__3, &c__1, (char *)&coordsyst_1.icoordsystem, (ftnlen)
		    sizeof(integer));
	    e_wsle();
	    s_wsle(&io___325);
	    do_lio(&c__9, &c__1, "normal SHORT DISTANCE CONVERSION will be m"
		    "ade", (ftnlen)45);
	    e_wsle();
	    s_wsle(&io___326);
	    do_lio(&c__9, &c__1, "x is positive towards west,", (ftnlen)27);
	    do_lio(&c__9, &c__1, " y is positive towards north", (ftnlen)28);
	    e_wsle();
	}
    }

/*     use setorg to set up coordinate system */

    ifil = 0;
    if (! coordsyst_1.single_turbo__) {
	ifil = 16;
    }

    if (coordsyst_1.icoordsystem != 2) {
	setorg_(&olat, &olon, &rotate, &ifil);
    }

/*  now origin is setup. */

/* L4: */

    if (param_1.dmax__ == 0.f) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___328);
	    do_lio(&c__9, &c__1, "WARNING: dmax was zero ! ... set to 150 km"
		    " !", (ftnlen)44);
	    e_wsle();
	}
	param_1.dmax__ = 150.f;
    }

    param_1.rmsmin = 0.f;
    if (param_1.invertratio <= 0) {
	param_1.invertratio = 999;
    }
/* do not invert for sta-corr */
    if (! coordsyst_1.single_turbo__) {
	if (coordsyst_1.iuseelev == 0) {
	    s_wsle(&io___329);
	    e_wsle();
	    s_wsle(&io___330);
	    do_lio(&c__9, &c__1, "Station-elevations internally set to ZERO !"
		    , (ftnlen)43);
	    e_wsle();
	    s_wsle(&io___331);
	    do_lio(&c__9, &c__1, "(but correctly printed in file12)", (ftnlen)
		    33);
	    e_wsle();
	    s_wsle(&io___332);
	    e_wsle();
	}
	if (coordsyst_1.iusestacorr == 0) {
	    s_wsle(&io___333);
	    e_wsle();
	    s_wsle(&io___334);
	    do_lio(&c__9, &c__1, "Station-corrections set to ZERO !", (ftnlen)
		    33);
	    e_wsle();
	    s_wsle(&io___335);
	    do_lio(&c__9, &c__1, "(if you do NOT invert for station-correcti"
		    "ons,", (ftnlen)46);
	    e_wsle();
	    s_wsle(&io___336);
	    do_lio(&c__9, &c__1, " then these 0.0-values are printed in file"
		    "12 !)", (ftnlen)47);
	    e_wsle();
	    s_wsle(&io___337);
	    e_wsle();
	}
    }
/* ***  nsinv=  0 no inversion for station corrections */
/* ***          1 inversion for station corrections */

/* ***  legs is the total number of shots and quakes */
/* ek */
/* ek   legs and neqs MUST be 1 in single_event mode */

    if (coordsyst_1.isingle != 1) {
	dimen_1.legs = dimen_1.neqs + dimen_1.nshot;
    } else {
	dimen_1.legs = 1;
	dimen_1.neqs = 1;
	dimen_1.nshot = 0;
    }

    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___338);
	e_wsfe();
	s_wsle(&io___339);
	do_lio(&c__9, &c__1, "   INPUT - M O D E L :", (ftnlen)22);
	e_wsle();
	s_wsfe(&io___340);
	e_wsfe();
	s_wsle(&io___341);
	do_lio(&c__9, &c__1, "Model(s) read from file :", (ftnlen)25);
	e_wsle();
	s_wsle(&io___342);
	do_lio(&c__9, &c__1, files_1.modelfilename, (ftnlen)80);
	e_wsle();
	s_wsle(&io___343);
	e_wsle();
    }
    cl__1.cerr = 0;
    cl__1.cunit = 10;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*   *********** */
/* NOW READ model file */
/*   *********** */

/* VMS      open(10,file=modelfilename,status='old',err=9911,readonly) */
    o__1.oerr = 1;
    o__1.ounit = 10;
    o__1.ofnmlen = 80;
    o__1.ofnm = files_1.modelfilename;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L9911;
    }

    layvel_1.ireflector = 0;
/* ek */
    if (modela_1.nsp == 3) {
	s_wsfe(&io___344);
	e_wsfe();
    }

/* ek  modifications for new model file */
    s_rsfe(&io___345);
    do_fio(&c__1, titl, (ftnlen)40);
    e_rsfe();
    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___347);
	do_fio(&c__1, " model file title: ", (ftnlen)19);
	do_fio(&c__1, titl, (ftnlen)40);
	e_wsfe();
    }
/* ek      read(10,*) (nplay(j),j=1,nmod) */
/* L8: */
    i__1 = modela_1.nmod;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___348);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_wsle(&io___349);
	    e_wsle();
	    s_wsfe(&io___350);
	    e_wsfe();
	}
	s_copy(titl, " ", (ftnlen)40, (ftnlen)1);
	s_rsfe(&io___351);
	do_fio(&c__1, (char *)&modela_1.nplay[i__ - 1], (ftnlen)sizeof(
		integer));
	e_rsfe();
	i__2 = modela_1.nplay[i__ - 1];
	for (j = 1; j <= i__2; ++j) {
	    if (j == 1) {
		s_rsfe(&io___353);
		do_fio(&c__1, (char *)&layvel_1.vp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.vdamp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, reflch, (ftnlen)1);
		do_fio(&c__1, titl, (ftnlen)40);
		e_rsfe();
	    } else {
		s_rsfe(&io___355);
		do_fio(&c__1, (char *)&layvel_1.vp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.vdamp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, reflch, (ftnlen)1);
		e_rsfe();
	    }
	    if (*(unsigned char *)reflch != ' ') {
		if (*(unsigned char *)reflch == 'm' || *(unsigned char *)
			reflch == 'M') {
		    *(unsigned char *)layvel_1.reflchar = *(unsigned char *)
			    reflch;
		    layvel_1.ireflector = j;
		    if (! coordsyst_1.single_turbo__) {
			if (layvel_1.vp[i__ + (layvel_1.ireflector << 1) - 3] 
				> 8.f) {
			    s_wsle(&io___356);
			    do_lio(&c__9, &c__1, "WARNING ::: velocity ABOVE"
				    " reflector is", (ftnlen)39);
			    do_lio(&c__9, &c__1, " greater than 8.0 km/s  .."
				    "...", (ftnlen)29);
			    e_wsle();
			    s_wsle(&io___357);
			    do_lio(&c__9, &c__1, "WARNING ::: velocity ABOVE"
				    " reflector is", (ftnlen)39);
			    do_lio(&c__9, &c__1, " greater than 8.0 km/s  .."
				    "...", (ftnlen)29);
			    e_wsle();
			    s_wsle(&io___358);
			    e_wsle();
			}
		    }
		} else {
		    if (! coordsyst_1.single_turbo__) {
			s_wsle(&io___359);
			do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
			e_wsle();
			s_wsle(&io___360);
			do_lio(&c__9, &c__1, "Reflector indicated in velocit"
				"y-model is", (ftnlen)40);
			do_lio(&c__9, &c__1, " marked with a : ", (ftnlen)17);
			do_lio(&c__9, &c__1, reflch, (ftnlen)1);
			e_wsle();
			s_wsle(&io___361);
			do_lio(&c__9, &c__1, "Only   m   or   M   are allowe"
				"d!", (ftnlen)32);
			e_wsle();
			s_wsle(&io___362);
			do_lio(&c__9, &c__1, "Reflected phases will be ignor"
				"ed (wrong mark)", (ftnlen)45);
			e_wsle();
			s_wsle(&io___363);
			do_lio(&c__9, &c__1, "Reflected phases will be ignor"
				"ed (wrong mark)", (ftnlen)45);
			e_wsle();
			s_wsle(&io___364);
			e_wsle();
		    }
		}
	    }
	    if (j == 1) {
		if (! coordsyst_1.single_turbo__) {
		    s_wsfe(&io___365);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&layvel_1.vp[i__ + (j << 1) - 3], (
			    ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j << 1) - 3], (
			    ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&layvel_1.vdamp[i__ + (j << 1) - 3],
			     (ftnlen)sizeof(real));
		    do_fio(&c__1, reflch, (ftnlen)1);
		    do_fio(&c__1, titl, (ftnlen)40);
		    e_wsfe();
		}
		s_copy(titl, " ", (ftnlen)40, (ftnlen)1);
	    } else {
		if (! coordsyst_1.single_turbo__) {
		    s_wsfe(&io___366);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&layvel_1.vp[i__ + (j << 1) - 3], (
			    ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j << 1) - 3], (
			    ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&layvel_1.vdamp[i__ + (j << 1) - 3],
			     (ftnlen)sizeof(real));
		    do_fio(&c__1, reflch, (ftnlen)1);
		    e_wsfe();
		}
	    }

	    if (j > 1 && layvel_1.hp[i__ + (j << 1) - 3] < 0.f) {
		s_wsle(&io___367);
		do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
		e_wsle();
		s_wsle(&io___368);
		do_lio(&c__9, &c__1, "Only top of the first layer can be neg"
			"ative !!", (ftnlen)46);
		e_wsle();
		s_wsle(&io___369);
		e_wsle();
		if (! coordsyst_1.single_turbo__) {
		    s_wsle(&io___370);
		    do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
		    e_wsle();
		    s_wsle(&io___371);
		    do_lio(&c__9, &c__1, "Only top of the first layer can be"
			    " negative !!", (ftnlen)46);
		    e_wsle();
		}
	    }

/* L9: */
	}

/*    calculate and print average velocities of the model i : */

	if (! coordsyst_1.single_turbo__) {
	    ifl = 1;
	    s_wsle(&io___373);
	    e_wsle();
	    s_wsle(&io___374);
	    do_lio(&c__9, &c__1, "Calculation of average velocity starts at "
		    "layer # ", (ftnlen)50);
	    do_lio(&c__3, &c__1, (char *)&ifl, (ftnlen)sizeof(integer));
	    e_wsle();
	    avelo = 0.f;
	    i__2 = modela_1.nplay[i__ - 1];
	    for (j = ifl + 1; j <= i__2; ++j) {
		avelo += (layvel_1.hp[i__ + (j << 1) - 3] - layvel_1.hp[i__ + 
			(j - 1 << 1) - 3]) * layvel_1.vp[i__ + (j - 1 << 1) - 
			3];
		s_wsfe(&io___376);
		do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j - 1 << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.vp[i__ + (j - 1 << 1) - 3], (
			ftnlen)sizeof(real));
		r__1 = avelo / (layvel_1.hp[i__ + (j << 1) - 3] - layvel_1.hp[
			i__ + (ifl << 1) - 3]);
		do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		e_wsfe();
	    }
	    s_wsle(&io___377);
	    e_wsle();

	    ifl = 2;
	    s_wsle(&io___378);
	    e_wsle();
	    s_wsle(&io___379);
	    do_lio(&c__9, &c__1, "Calculation of average velocity starts at "
		    "layer # ", (ftnlen)50);
	    do_lio(&c__3, &c__1, (char *)&ifl, (ftnlen)sizeof(integer));
	    e_wsle();
	    avelo = 0.f;
	    i__2 = modela_1.nplay[i__ - 1];
	    for (j = ifl + 1; j <= i__2; ++j) {
		avelo += (layvel_1.hp[i__ + (j << 1) - 3] - layvel_1.hp[i__ + 
			(j - 1 << 1) - 3]) * layvel_1.vp[i__ + (j - 1 << 1) - 
			3];
		s_wsfe(&io___380);
		do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j - 1 << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.vp[i__ + (j - 1 << 1) - 3], (
			ftnlen)sizeof(real));
		r__1 = avelo / (layvel_1.hp[i__ + (j << 1) - 3] - layvel_1.hp[
			i__ + (ifl << 1) - 3]);
		do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[i__ + (j << 1) - 3], (
			ftnlen)sizeof(real));
		e_wsfe();
	    }
	    s_wsle(&io___381);
	    e_wsle();
	    s_wsle(&io___382);
	    e_wsle();
	}

/* L14: */
    }
    if (layvel_1.ireflector != 0) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___383);
	    e_wsle();
	    s_wsfe(&io___384);
	    do_fio(&c__1, layvel_1.reflchar, (ftnlen)1);
	    do_fio(&c__1, (char *)&layvel_1.ireflector, (ftnlen)sizeof(
		    integer));
	    e_wsfe();
	    if (coordsyst_1.lowveloclay == 1) {
		s_wsle(&io___385);
		do_lio(&c__9, &c__1, "Switch LOWVELOCLAY is set to 1, but re"
			"flected phases are allowed to occur", (ftnlen)73);
		e_wsle();
		s_wsle(&io___386);
		do_lio(&c__9, &c__1, "This is improper (no low velocity-laye"
			"rs allowed for reflected waves!!)", (ftnlen)71);
		e_wsle();
		coordsyst_1.lowveloclay = 0;
		s_wsle(&io___387);
		do_lio(&c__9, &c__1, "LOWVELOCLAY now set to 0 ", (ftnlen)25);
		e_wsle();
		s_wsle(&io___388);
		do_lio(&c__9, &c__1, "Switch LOWVELOCLAY is set to 1, but re"
			"flected phases are allowed to occur", (ftnlen)73);
		e_wsle();
		s_wsle(&io___389);
		do_lio(&c__9, &c__1, "This is improper (no low velocity-laye"
			"rs allowed for reflected waves!!)", (ftnlen)71);
		e_wsle();
		s_wsle(&io___390);
		do_lio(&c__9, &c__1, "LOWVELOCLAY now set to 0 ", (ftnlen)25);
		e_wsle();
	    }
	}
    }


/*   *********** */
/* NOW READ station file */
/*   *********** */

/*    read in station data: */

    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___391);
	e_wsfe();
	s_wsle(&io___392);
	do_lio(&c__9, &c__1, "   INPUT - S T A T I O N S :", (ftnlen)28);
	e_wsle();
	s_wsfe(&io___393);
	e_wsfe();
	s_wsle(&io___394);
	do_lio(&c__9, &c__1, "Station-parameters read from file :", (ftnlen)
		35);
	e_wsle();
	s_wsle(&io___395);
	do_lio(&c__9, &c__1, files_1.stationfilename, (ftnlen)80);
	e_wsle();
	s_wsle(&io___396);
	e_wsle();
    }
    cl__1.cerr = 0;
    cl__1.cunit = 10;
    cl__1.csta = 0;
    f_clos(&cl__1);
/* VMS      open(10,file=stationfilename,status='old',err=9912,readonly) */
    o__1.oerr = 1;
    o__1.ounit = 10;
    o__1.ofnmlen = 80;
    o__1.ofnm = files_1.stationfilename;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L9912;
    }
    s_rsfe(&io___397);
    do_fio(&c__1, form_1.fm, (ftnlen)80);
    e_rsfe();
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___398);
	e_wsle();
	s_wsfe(&io___399);
	e_wsfe();
    }
    dimen_1.nsta = 0;

L10:
    ++dimen_1.nsta;
    s_rsfe(&io___400);
    do_fio(&c__1, charc_1.stn + (dimen_1.nsta - 1 << 2), (ftnlen)4);
    do_fio(&c__1, (char *)&stltln_1.xla[dimen_1.nsta - 1], (ftnlen)sizeof(
	    real));
    do_fio(&c__1, cns, (ftnlen)1);
    do_fio(&c__1, (char *)&stltln_1.xlo[dimen_1.nsta - 1], (ftnlen)sizeof(
	    real));
    do_fio(&c__1, cew, (ftnlen)1);
    do_fio(&c__1, (char *)&coordsyst_1.ielev[dimen_1.nsta - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&mode, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&icc, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&statn_1.ptcor[dimen_1.nsta - 1], (ftnlen)sizeof(
	    real));
    do_fio(&c__1, (char *)&statn_1.stcor[dimen_1.nsta - 1], (ftnlen)sizeof(
	    real));
    e_rsfe();
    casefold_(cns, (ftnlen)1);
    casefold_(cew, (ftnlen)1);
    if (*(unsigned char *)cns == 'S') {
	stltln_1.xla[dimen_1.nsta - 1] = -stltln_1.xla[dimen_1.nsta - 1];
    }
    if (*(unsigned char *)cew == 'E') {
	stltln_1.xlo[dimen_1.nsta - 1] = -stltln_1.xlo[dimen_1.nsta - 1];
    }

    if (s_cmp(charc_1.stn + (dimen_1.nsta - 1 << 2), " ", (ftnlen)4, (ftnlen)
	    1) == 0) {
	goto L41;
    }
/* ek      if(mode.eq.0) mode=1 */
    mode = 1;

    if (modela_1.nsp == 2) {
	statn_1.model[(dimen_1.nsta << 1) - 2] = mode;
	statn_1.model[(dimen_1.nsta << 1) - 1] = mode + 1;
    } else {
	statn_1.model[dimen_1.nsta - 1] = mode;
    }
    z__ = -coordsyst_1.ielev[dimen_1.nsta - 1] / 1e3f;
    if (coordsyst_1.icoordsystem == 2) {
	r__1 = -stltln_1.xlo[dimen_1.nsta - 1];
	geoko_(&dx, &dy, &stltln_1.xla[dimen_1.nsta - 1], &r__1, &c_n1);
/* calc. cart. coord. */
	dx = -dx;
    } else {
	sdc_(&dx, &dy, &stltln_1.xla[dimen_1.nsta - 1], &stltln_1.xlo[
		dimen_1.nsta - 1], &c_n1);
/* calc. cart. coord. */
    }
    dz = z__;
    statn_1.x[dimen_1.nsta - 1] = dx;
    statn_1.x[dimen_1.nsta + 649] = dy;
    if (coordsyst_1.iuseelev == 1) {
	statn_1.x[dimen_1.nsta + 1299] = dz;
    } else {
	statn_1.x[dimen_1.nsta + 1299] = 0.f;
/* station-elevation not used ! */
    }
    if (coordsyst_1.iusestacorr == 0) {
	statn_1.ptcor[dimen_1.nsta - 1] = 0.f;
/* initial (from input) station-corrections not */
	statn_1.stcor[dimen_1.nsta - 1] = 0.f;
/*   "          "               "            " */
    }
    if (! coordsyst_1.single_turbo__) {
	if (coordsyst_1.icoordsystem == 2) {
	    dx = -dx;
	}
	if (*(unsigned char *)cns == 'S') {
	    stltln_1.xla[dimen_1.nsta - 1] = -stltln_1.xla[dimen_1.nsta - 1];
	}
	if (*(unsigned char *)cew == 'E') {
	    stltln_1.xlo[dimen_1.nsta - 1] = -stltln_1.xlo[dimen_1.nsta - 1];
	}
	s_wsfe(&io___409);
	do_fio(&c__1, (char *)&dimen_1.nsta, (ftnlen)sizeof(integer));
	do_fio(&c__1, charc_1.stn + (dimen_1.nsta - 1 << 2), (ftnlen)4);
	do_fio(&c__1, (char *)&stltln_1.xla[dimen_1.nsta - 1], (ftnlen)sizeof(
		real));
	do_fio(&c__1, cns, (ftnlen)1);
	do_fio(&c__1, (char *)&stltln_1.xlo[dimen_1.nsta - 1], (ftnlen)sizeof(
		real));
	do_fio(&c__1, cew, (ftnlen)1);
	do_fio(&c__1, (char *)&coordsyst_1.ielev[dimen_1.nsta - 1], (ftnlen)
		sizeof(integer));
	do_fio(&c__1, (char *)&dx, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&dy, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&dz, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&statn_1.ptcor[dimen_1.nsta - 1], (ftnlen)
		sizeof(real));
	do_fio(&c__1, (char *)&statn_1.stcor[dimen_1.nsta - 1], (ftnlen)
		sizeof(real));
	do_fio(&c__1, (char *)&mode, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&icc, (ftnlen)sizeof(integer));
	e_wsfe();
	if (*(unsigned char *)cns == 'S') {
	    stltln_1.xla[dimen_1.nsta - 1] = -stltln_1.xla[dimen_1.nsta - 1];
	}
	if (*(unsigned char *)cew == 'E') {
	    stltln_1.xlo[dimen_1.nsta - 1] = -stltln_1.xlo[dimen_1.nsta - 1];
	}
    }

/*   an icc of 0 holds the station delay fixed. */
/*   the highest nonzero icc station has its p delay */
/*   held fixed but its s delay is allowed to float. */

    statn_1.map1[dimen_1.nsta - 1] = icc;
    goto L10;
L41:
    cl__1.cerr = 0;
    cl__1.cunit = 10;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*     read in seismo data (seismometer-specifications and so on): */

/* stationfile */
    if (! coordsyst_1.single_turbo__) {
	if (s_cmp(files_1.seismofilename, " ", (ftnlen)80, (ftnlen)1) != 0) {
	    s_wsle(&io___410);
	    e_wsle();
	    s_wsle(&io___411);
	    do_lio(&c__9, &c__1, "Seismo-parameters read from file :", (
		    ftnlen)34);
	    e_wsle();
	    s_wsle(&io___412);
	    do_lio(&c__9, &c__1, files_1.seismofilename, (ftnlen)80);
	    e_wsle();
	    s_wsle(&io___413);
	    e_wsle();
	    s_wsle(&io___414);
	    do_lio(&c__9, &c__1, "This file contains station-informations wh"
		    "ich", (ftnlen)45);
	    e_wsle();
	    s_wsle(&io___415);
	    do_lio(&c__9, &c__1, "are used for magnitude-determination", (
		    ftnlen)36);
	    e_wsle();
	    s_wsle(&io___416);
	    do_lio(&c__9, &c__1, "(seismometer-constant,filterparameters, et"
		    "c.)", (ftnlen)45);
	    e_wsle();
	    s_wsle(&io___417);
	    e_wsle();
	    s_wsle(&io___418);
	    e_wsle();
	} else {
	    s_wsle(&io___419);
	    e_wsle();
	    s_wsle(&io___420);
	    do_lio(&c__9, &c__1, "NO Seismo-parameter-file specified", (
		    ftnlen)34);
	    e_wsle();
	    s_wsle(&io___421);
	    do_lio(&c__9, &c__1, "--> NO magnitudes calculated!", (ftnlen)29);
	    e_wsle();
	    s_wsle(&io___422);
	    e_wsle();
	    s_wsle(&io___423);
	    e_wsle();
	    s_wsle(&io___424);
	    e_wsle();
	}
    }
    if (s_cmp(files_1.seismofilename, " ", (ftnlen)80, (ftnlen)1) != 0) {
	o__1.oerr = 1;
	o__1.ounit = 10;
	o__1.ofnmlen = 80;
	o__1.ofnm = files_1.seismofilename;
	o__1.orl = 0;
	o__1.osta = "old";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L9913;
	}
    }
/* VMS     &open(10,file=seismofilename,status='old',err=9913,readonly) */
/*     the seismo-parameters will be read in later; we must know the eventtime */
/*     before we can pick the time-dependent (!) seismo-parameters !!! */

/* ***  nsta is the number of stations read in */
    --dimen_1.nsta;

    maxii_(&dimen_1.nsta, statn_1.map1, &ml, &jndex);
/* ***  ksta is the number of total station corrections */
/* ***    to invert for */
/* determine MAX (=ml) of map1 (icc- */
    dimen_1.ksta = 0;
    if (dimen_1.nsinv != 0) {
/*                            the last station for p  will be held fixed. */
/*  invert for station corrections */
	dimen_1.ksta = ml - 1;
	if (modela_1.nsp == 2) {
	    dimen_1.ksta = (dimen_1.ksta << 1) + 1;
	}
    }

/*    find the total number of layers */

/* **  laysum(i) is an index for the location of the first */
/* ***  layer of model i */
    modela_1.laysum[0] = 1;
    modela_1.laysum[1] = modela_1.nplay[0] + 1;
    if (modela_1.nmod < 3) {
	goto L50;
    }
    i__1 = modela_1.nmod;
    for (i__ = 3; i__ <= i__1; ++i__) {
/* L42: */
	modela_1.laysum[i__ - 1] = modela_1.laysum[i__ - 2] + modela_1.nplay[
		i__ - 2];
    }
L50:
/* ***  nltot is the total number of velocity layers */
/* ***  to invert for */
    modela_1.nltot = 0;
    i__1 = modela_1.nmod;
    for (i__ = 1; i__ <= i__1; ++i__) {
	modela_1.nltot += modela_1.nplay[i__ - 1];
/* L18: */
    }

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___427);
	e_wsle();
	s_wsfe(&io___428);
	do_fio(&c__1, (char *)&dimen_1.neqs, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&dimen_1.nshot, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&modela_1.nltot, (ftnlen)sizeof(integer));
	e_wsfe();
    }
/* L1619: */

    for (i__ = 1; i__ <= 2; ++i__) {
/* max. number of 1D-models */
	for (j = 1; j <= 100; ++j) {
/* max. number of layers per model */
/* L25: */
	    layvel_1.thkp[i__ + (j << 1) - 3] = 0.f;
	}
    }
    i__1 = modela_1.nmod;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (modela_1.nplay[i__ - 1] == 1) {
	    goto L22;
	}
	k = modela_1.nplay[i__ - 1] - 1;
	i__2 = k;
	for (j = 1; j <= i__2; ++j) {
/* L23: */
	    layvel_1.thkp[i__ + (j << 1) - 3] = layvel_1.hp[i__ + (j + 1 << 1)
		     - 3] - layvel_1.hp[i__ + (j << 1) - 3];
	}
L22:
	;
    }
    return 0;

L9910:
    openerror_("inputparam", "control-input-file FOR010", (ftnlen)10, (ftnlen)
	    25);
    return 0;
L9911:
    openerror_("inputparam", "model-input-file (FOR010)", (ftnlen)10, (ftnlen)
	    25);
    return 0;
L9912:
    openerror_("inputparam", "station-input-file (FOR010)", (ftnlen)10, (
	    ftnlen)27);
    return 0;
L9913:
    openerror_("inputparam", "seismo-input-file (FOR010)", (ftnlen)10, (
	    ftnlen)26);
    return 0;

} /* inputparam_ */



/* of subr. inputparam */
/* Subroutine */ int inputdata_(integer *i__)
{
    /* Initialized data */

    static char sc[1] = "s";
    static char ss[1] = "S";

    /* Format strings */
    static char fmt_85[] = "(\002 ***** end of data encountered *****\002)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;
    olist o__1;

    /* Builtin functions */
    integer f_open(olist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_cmp(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer pow_ii(integer *, integer *);

    /* Local variables */
    static integer nobsread;
    extern /* Subroutine */ int inputcnv_(integer *, integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    char *, char *, char *, integer *, real *, real *, real *, real *,
	     real *, real *, real *, integer *, integer *, integer *, char *, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    static integer j, k, l;
    static real z__;
    static integer i1, i2, i3;
    extern /* Subroutine */ int openerror_(char *, char *, ftnlen, ftnlen);
    static char eventtype[1];
    static integer ie, jj, jk, ll;
    static real ss1;
    static integer icc;
    extern /* Subroutine */ int sdc_(real *, real *, real *, real *, integer *
	    );
    static real sec[180];
    static char cew[1];
    static integer iphaseteststopflag;
    static char cns[1], sta[4*180];
    static real xxx;
    static char rmk1[1*180], rmk2[1*180];
    extern /* Subroutine */ int inputarcvel_(integer *, integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    char *, char *, char *, integer *, real *, real *, real *, real *,
	     real *, real *, real *, integer *, integer *, integer *, char *, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    static integer nobs;
    static real xlat, xlon, alon;
    static integer ipwt[180];
    static real wsum;
    extern /* Subroutine */ int inputsed_new__(integer *, integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    char *, char *, char *, integer *, real *, real *, real *, real *,
	     real *, real *, real *, integer *, integer *, integer *, char *, 
	    integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    static real aalon, depth;
    extern /* Subroutine */ int geoko_(real *, real *, real *, real *, 
	    integer *);
    static integer jjmin, nobsp, ntobs, nobss, jshot, iunit, itest;
    static real xxlat;
    static integer jjmin1;
    static char cphase[1*180];

    /* Fortran I/O blocks */
    static cilist io___452 = { 0, 6, 0, "(1x,'Event #',i4)", 0 };
    static cilist io___453 = { 0, 6, 0, 0, 0 };
    static cilist io___454 = { 0, 2, 0, "('1 E V E N T   N R .   ',i6,      "
	    "                              '                 ',              "
	    "                              '           0                    0"
	    "')", 0 };
    static cilist io___455 = { 0, 6, 0, "(1x,'Event #',i6)", 0 };
    static cilist io___460 = { 0, 16, 0, 0, 0 };
    static cilist io___461 = { 0, 6, 0, 0, 0 };
    static cilist io___462 = { 0, 16, 0, 0, 0 };
    static cilist io___463 = { 0, 6, 0, 0, 0 };
    static cilist io___467 = { 0, 16, 0, 0, 0 };
    static cilist io___468 = { 0, 16, 0, 0, 0 };
    static cilist io___469 = { 0, 6, 0, 0, 0 };
    static cilist io___470 = { 0, 6, 0, 0, 0 };
    static cilist io___471 = { 0, 2, 0, "(' DELETED: ',a4,                  "
	    "                           ' unknown phase is: ',a1)", 0 };
    static cilist io___472 = { 0, 16, 0, 0, 0 };
    static cilist io___473 = { 0, 16, 0, 0, 0 };
    static cilist io___474 = { 0, 16, 0, 0, 0 };
    static cilist io___475 = { 0, 16, 0, 0, 0 };
    static cilist io___476 = { 0, 6, 0, 0, 0 };
    static cilist io___477 = { 0, 6, 0, 0, 0 };
    static cilist io___478 = { 0, 6, 0, 0, 0 };
    static cilist io___479 = { 0, 6, 0, 0, 0 };
    static cilist io___481 = { 0, 16, 0, 0, 0 };
    static cilist io___482 = { 0, 16, 0, 0, 0 };
    static cilist io___483 = { 0, 16, 0, "(' WARNING:  Station: >>>',a4,    "
	    "                               '<<< not found in stationlist!')", 
	    0 };
    static cilist io___484 = { 0, 16, 0, 0, 0 };
    static cilist io___485 = { 0, 6, 0, "(' WARNING:  Station: >>>',a4,     "
	    "                               '<<< not found in stationlist!')", 
	    0 };
    static cilist io___486 = { 0, 6, 0, 0, 0 };
    static cilist io___487 = { 0, 6, 0, 0, 0 };
    static cilist io___488 = { 0, 2, 0, "(' DELETED: ',a4,                  "
	    "                              ' not on station-list')", 0 };
    static cilist io___490 = { 0, 16, 0, 0, 0 };
    static cilist io___491 = { 0, 16, 0, "(' epicentral distance:',f6.1,    "
	    "                               ' > dmax (',f6.1,') ==> skipping "
	    "phase !')", 0 };
    static cilist io___492 = { 0, 6, 0, "(' epicentral distance:',f6.1,     "
	    "                               ' > dmax (',f6.1,') ==> skipping "
	    "phase !')", 0 };
    static cilist io___493 = { 0, 2, 0, "(' DELETED: ',a4,                  "
	    "                              ' epicentral-distance too large')", 
	    0 };
    static cilist io___497 = { 0, 16, 0, 0, 0 };
    static cilist io___498 = { 0, 16, 0, 0, 0 };
    static cilist io___499 = { 0, 16, 0, "(1x,'---> ',3i2.2,1x,2i2.2)", 0 };
    static cilist io___500 = { 0, 16, 0, 0, 0 };
    static cilist io___501 = { 0, 6, 0, 0, 0 };
    static cilist io___502 = { 0, 6, 0, "(1x,'---> ',3i2.2,1x,2i2.2)", 0 };
    static cilist io___503 = { 0, 6, 0, 0, 0 };
    static cilist io___504 = { 0, 6, 0, 0, 0 };
    static cilist io___505 = { 0, 16, 0, 0, 0 };
    static cilist io___506 = { 0, 16, 0, 0, 0 };
    static cilist io___508 = { 0, 16, 0, 0, 0 };
    static cilist io___509 = { 0, 16, 0, 0, 0 };
    static cilist io___518 = { 0, 16, 0, "(1x,i3,1x,3i2.2,1x,2i2.2,1x,f5.2,1"
	    "x,f7.4,a1,                     1x,f8.4,a1,1x,f6.2,3f7.2,f5.2,i2,"
	    "i4,3x,2i5)", 0 };
    static cilist io___519 = { 0, 16, 0, "(1x,i3,1x,3i2.2,1x,2i2.2,1x,f5.2,1"
	    "x,f7.4,a1,                       1x,f8.4,a1,1x,f6.2,3f7.2,f5.2,i"
	    "2,i4)", 0 };
    static cilist io___520 = { 0, 16, 0, "(1x,i3,1x,3i2.2,1x,2i2.2,1x,f5.2,1"
	    "x,f7.4,a1,                      1x,f8.4,a1,1x,f6.2,3f7.2,f5.2,i2"
	    ",i4)", 0 };
    static cilist io___521 = { 0, 16, 0, fmt_85, 0 };
    static cilist io___522 = { 0, 16, 0, 0, 0 };
    static cilist io___523 = { 0, 6, 0, 0, 0 };



/*     reads in the phaselists with the earthquake and/or shot data */

/* old name:  INPUT2 */

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


/* forget never that error was detected! */

/*     input phase list and set-up initial trial hypocenter */
    iunit = 8;
    if (*i__ == 1) {
	if (dimen_1.neqs > 0) {
	    o__1.oerr = 1;
	    o__1.ounit = iunit;
	    o__1.ofnmlen = 80;
	    o__1.ofnm = infiles_1.phasefile;
	    o__1.orl = 0;
	    o__1.osta = "old";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    i__1 = f_open(&o__1);
	    if (i__1 != 0) {
		goto L998;
	    }
	}
/* VMS     &                      status='old',err=998,readonly) */
	if (dimen_1.nshot > 0) {
	    o__1.oerr = 1;
	    o__1.ounit = 9;
	    o__1.ofnmlen = 80;
	    o__1.ofnm = infiles_1.shotfile;
	    o__1.orl = 0;
	    o__1.osta = "old";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    i__1 = f_open(&o__1);
	    if (i__1 != 0) {
		goto L999;
	    }
	}
/* VMS     &                       status='old',err=999,readonly) */
    }
/* ek */
/* ek      re-entry for reading next event if first event has less */
/* ek      than three observations */
L10001:
/* ek */
    nobs = 0;
    obb_1.nobswithw0 = 0;
    ntobs = 0;
    wsum = 0.f;

    if (*i__ <= dimen_1.neqs) {
	iunit = 8;
/* EQS */
    } else {
	iunit = 9;
/* SHOTS */
    }

    xlat = 0.f;
    xlon = 0.f;
    for (jj = 1; jj <= 180; ++jj) {
	*(unsigned char *)&cphase[jj - 1] = ' ';
    }

/* ek  i1-switch is dummy */
    i1 = 0;

/* ek     EQS:   i1=ifx(i)     ! no longer in use !!! */
/* ek     SHOTS: i1=icc */

    if (coordsyst_1.ised == 0) {
	inputcnv_(&iunit, &nobsread, sta, &event_1.iyr[*i__ - 1], &
		event_1.imo[*i__ - 1], &event_1.iday[*i__ - 1], &event_1.ihr[*
		i__ - 1], &event_1.imin[*i__ - 1], sec, rmk1, rmk2, cphase, 
		ipwt, obb_1.amx, obb_1.prx, &xlat, &alon, &event_1.emag[*i__ 
		- 1], &depth, &event_1.e[(*i__ << 2) - 4], &i1, &i2, &i3, 
		eventtype, (ftnlen)4, (ftnlen)1, (ftnlen)1, (ftnlen)1, (
		ftnlen)1);
    }
    if (coordsyst_1.ised == 1) {
	inputarcvel_(&iunit, &nobsread, sta, &event_1.iyr[*i__ - 1], &
		event_1.imo[*i__ - 1], &event_1.iday[*i__ - 1], &event_1.ihr[*
		i__ - 1], &event_1.imin[*i__ - 1], sec, rmk1, rmk2, cphase, 
		ipwt, obb_1.amx, obb_1.prx, &xlat, &alon, &event_1.emag[*i__ 
		- 1], &depth, &event_1.e[(*i__ << 2) - 4], &i1, &i2, &i3, 
		eventtype, (ftnlen)4, (ftnlen)1, (ftnlen)1, (ftnlen)1, (
		ftnlen)1);
    }
    if (coordsyst_1.ised == 2) {
	inputsed_new__(&iunit, &nobsread, sta, &event_1.iyr[*i__ - 1], &
		event_1.imo[*i__ - 1], &event_1.iday[*i__ - 1], &event_1.ihr[*
		i__ - 1], &event_1.imin[*i__ - 1], sec, rmk1, rmk2, cphase, 
		ipwt, obb_1.amx, obb_1.prx, &xlat, &alon, &event_1.emag[*i__ 
		- 1], &depth, &event_1.e[(*i__ << 2) - 4], &i1, &
		param_1.ifixsolution, &i3, eventtype, &coordsyst_1.itrial, (
		ftnlen)4, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
    }
    if (nobsread == -1) {
	obb_1.knobs[*i__ - 1] = -1;
/* means: end of input-file detected! */
	return 0;
    }
    if (! (coordsyst_1.ised == 0 || coordsyst_1.ised == 1 || coordsyst_1.ised 
	    == 2)) {
	s_stop("INPUTDATA: ised flag has no supported value!", (ftnlen)44);
    }
/* ek */
/* ek check for events with less than three observations */
/* ek */
    if (coordsyst_1.isingle != 0) {
	if (nobsread < 3) {
	    s_wsfe(&io___452);
	    do_fio(&c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_wsle(&io___453);
	    do_lio(&c__9, &c__1, " skipped because it has fewer than 3 obs.", 
		    (ftnlen)41);
	    e_wsle();
	    goto L10001;
	}
    }
    if (coordsyst_1.isingle != 0) {
	s_wsfe(&io___454);
	do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___455);
	do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer));
	e_wsfe();
    }

    if (*i__ <= dimen_1.neqs) {
/* EK Dez94  next statement put in effect (ek: i1 set to zero, see above) */
	event_1.ifx[*i__ - 1] = i1;
/* EK Dez94 next statement put out of use: */
/* EK         ifx(i)=0   ! NO ROTATION; do not set dtdr(2) to 0.0  UK87 */
    } else {
	icc = i1;
    }

/*     if ITRIAL = 1 take first station as trial epicenter and */
/*                   ztrial as trial depth */
/*     Do the same, if no hypocenter has been read from input !!! */

    if (coordsyst_1.itrial > 0 || xlat == 0.f && alon == 0.f) {

/*        find first station: */

	if (coordsyst_1.itrial > 0) {
	    jjmin1 = 1;
	    i__1 = nobsread;
	    for (jj = 1; jj <= i__1; ++jj) {
		if (ipwt[jj - 1] < 5) {
		    i__2 = dimen_1.nsta;
		    for (jk = 1; jk <= i__2; ++jk) {
			if (s_cmp(sta + (jj - 1 << 2), charc_1.stn + (jk - 1 
				<< 2), (ftnlen)4, (ftnlen)4) == 0) {
			    goto L22222;
			}
		    }
		    goto L2222;
/* jj-th station not on station-list !!! */
L22222:
		    jjmin1 = jj;
		    goto L222;
		}
L2222:
		;
	    }
L222:
	    jjmin = jjmin1;
/* first station in data which is on station-li */
	    i__1 = nobsread;
	    for (jj = jjmin1; jj <= i__1; ++jj) {
		if (ipwt[jj - 1] < 5) {
		    if (sec[jj - 1] < sec[jjmin1 - 1]) {
			jjmin = jj;
		    }
		}
	    }
/* c          write(16,'('' first station is '',a4)') sta(jjmin) */
	    jjmin1 = 0;
	    i__1 = dimen_1.nsta;
	    for (jj = 1; jj <= i__1; ++jj) {
		if (s_cmp(sta + (jjmin - 1 << 2), charc_1.stn + (jj - 1 << 2),
			 (ftnlen)4, (ftnlen)4) == 0) {
		    jjmin1 = jj;
		    goto L11111;
		}
	    }
	}
L11111:
/*        If no first station found, take 1st in station-list !! : */
/* uk         if(smn(jj,i).eq.' ') jj=1  ! is wrong!! */
/* jj is the first station */
	if (jjmin1 == 0) {
	    jj = 1;
	}
	if (param_1.ifixsolution != 9) {
	    xlat = stltln_1.xla[jj - 1] + .001f;
	    alon = stltln_1.xlo[jj - 1] + .001f;
	    if (param_1.ifixsolution != 1) {
		depth = coordsyst_1.ztrial;
	    } else {
		if (! coordsyst_1.single_turbo__) {
		    s_wsle(&io___460);
		    do_lio(&c__9, &c__1, "DEPTH fixed !!!", (ftnlen)15);
		    e_wsle();
		}
		s_wsle(&io___461);
		do_lio(&c__9, &c__1, "DEPTH fixed !", (ftnlen)13);
		e_wsle();
	    }
	} else {
	    if (! coordsyst_1.single_turbo__) {
		s_wsle(&io___462);
		do_lio(&c__9, &c__1, "HYPOCENTER fixed !!!", (ftnlen)20);
		e_wsle();
	    }
	    s_wsle(&io___463);
	    do_lio(&c__9, &c__1, "HYPOCENTER fixed !", (ftnlen)18);
	    e_wsle();
	    if (coordsyst_1.icoordsystem == 2 && alon > 0.f) {
		alon = -alon;
	    }
/* fixed LAT */
	}
/* was given in LON E */
    }

/*     in case the analyst has fixed the depth to less/equal 0.0, he probably */
/*     wanted to fix it at the surface... set depth to 3km above sea-level; */
/*     program VELEST will set it properly to the surface! */

    if (param_1.ifixsolution != 0 && coordsyst_1.itopo > 0 && depth <= 0.f) {
	depth = -3.f;
    }
    if (*i__ > dimen_1.neqs) {
	jshot = *i__ - dimen_1.neqs;
/* SHOTS */
	statn_1.map2[jshot - 1] = icc;
	z__ = depth;
    } else {
	z__ = depth + corr_1.zshift;
/* EQS */
    }

/*     now do transformation 'LAT/LON --> Xkm/Ykm' for trial hypocenter: */

    if (coordsyst_1.icoordsystem == 2) {
	r__1 = -alon;
	geoko_(&event_1.e[(*i__ << 2) - 3], &event_1.e[(*i__ << 2) - 2], &
		xlat, &r__1, &c_n1);
/* calc. cart. coord. */
	event_1.e[(*i__ << 2) - 3] = -event_1.e[(*i__ << 2) - 3];
    } else {
	sdc_(&event_1.e[(*i__ << 2) - 3], &event_1.e[(*i__ << 2) - 2], &xlat, 
		&alon, &c_n1);
/* calc. cart. coord. */
    }
    event_1.e[(*i__ << 2) - 1] = z__;
    obb_1.depthsofinput[*i__ - 1] = z__;

    i__1 = nobsread;
    for (j = 1; j <= i__1; ++j) {

	if (coordsyst_1.isingle == 0) {
	    if (ipwt[j - 1] >= 4) {
/* do not accept phase-weights >= 4  !! */
		goto L15;
	    }
	} else {
	    if (ipwt[j - 1] >= 6) {
/* do not accept phase-weights >= 6  !! */
		goto L15;
/* but take 4's & 5's for magnitude-cal */
	    }
/* and 4's also for residual-computatio */
	}
	if (modela_1.nsp == 1 && *(unsigned char *)&cphase[j - 1] == 's') {
	    goto L15;
	}
	if (modela_1.nsp == 1 && *(unsigned char *)&cphase[j - 1] == 'S') {
	    goto L15;
	}
	if (modela_1.nsp == 1 && *(unsigned char *)&cphase[j - 1] == '-') {
	    goto L15;
	}

/*     if cphase(j).ne. 's' or 'S', a P-phase is assumed, so it's not necessary */
/*     to check, whether it's a real P or a reflected P ( 'm' or 'M'). */
/*     But if no reflections should be assumed (e.g. ireflector.eq.0), */
/*     do NOT use any phases marked with 'm' or 'M' ! */
/* skip also s-p phases */
	if (*(unsigned char *)&cphase[j - 1] != 'p' && *(unsigned char *)&
		cphase[j - 1] != 'P' && ipwt[j - 1] < 5) {
	    if (*(unsigned char *)&cphase[j - 1] != 's' && *(unsigned char *)&
		    cphase[j - 1] != 'S') {
		if (*(unsigned char *)&cphase[j - 1] != '-') {
		    if (*(unsigned char *)&cphase[j - 1] != 'm' && *(unsigned 
			    char *)&cphase[j - 1] != 'M') {
			if (! coordsyst_1.single_turbo__) {
			    s_wsle(&io___467);
			    do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
			    e_wsle();
			    s_wsle(&io___468);
			    do_lio(&c__9, &c__1, "what phase is this ?  ", (
				    ftnlen)22);
			    do_lio(&c__9, &c__1, cphase + (j - 1), (ftnlen)1);
			    do_lio(&c__9, &c__1, " ???", (ftnlen)4);
			    e_wsle();
			}
			s_wsle(&io___469);
			do_lio(&c__9, &c__1, "what phase is this ?  ", (
				ftnlen)22);
			do_lio(&c__9, &c__1, cphase + (j - 1), (ftnlen)1);
			do_lio(&c__9, &c__1, " ???", (ftnlen)4);
			e_wsle();
			s_wsle(&io___470);
			e_wsle();
			if (coordsyst_1.isingle > 0) {
			    s_wsfe(&io___471);
			    do_fio(&c__1, sta + (j - 1 << 2), (ftnlen)4);
			    do_fio(&c__1, cphase + (j - 1), (ftnlen)1);
			    e_wsfe();
			    goto L15;
			}
/* if .ne. M */
		    } else {
/* here, if phase is a reflected one! */
			if (layvel_1.ireflector == 0) {
			    if (! coordsyst_1.single_turbo__) {
				s_wsle(&io___472);
				do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
				e_wsle();
				s_wsle(&io___473);
				do_lio(&c__9, &c__1, "subr. INPUTDATA >>> Ph"
					"ase is : ", (ftnlen)31);
				do_lio(&c__9, &c__1, cphase + (j - 1), (
					ftnlen)1);
				e_wsle();
				s_wsle(&io___474);
				do_lio(&c__9, &c__1, "but ireflector is: ", (
					ftnlen)19);
				do_lio(&c__3, &c__1, (char *)&
					layvel_1.ireflector, (ftnlen)sizeof(
					integer));
				e_wsle();
				s_wsle(&io___475);
				do_lio(&c__9, &c__1, "Phase therefore neglec"
					"ted !!", (ftnlen)28);
				e_wsle();
			    }
/* single_turbo */
			    s_wsle(&io___476);
			    do_lio(&c__9, &c__1, "subr. INPUTDATA >>> Phase "
				    "is : ", (ftnlen)31);
			    do_lio(&c__9, &c__1, cphase + (j - 1), (ftnlen)1);
			    e_wsle();
			    s_wsle(&io___477);
			    do_lio(&c__9, &c__1, "but ireflector is: ", (
				    ftnlen)19);
			    do_lio(&c__3, &c__1, (char *)&layvel_1.ireflector,
				     (ftnlen)sizeof(integer));
			    e_wsle();
			    s_wsle(&io___478);
			    do_lio(&c__9, &c__1, "Phase therefore neglected "
				    "!!", (ftnlen)28);
			    e_wsle();
			    s_wsle(&io___479);
			    e_wsle();
			    goto L15;
			}
/* if ireflector */
		    }
/* else */
		}
/* if s-p */
	    }
/* if s */
	}

/* if p */
	i__2 = dimen_1.nsta;
	for (k = 1; k <= i__2; ++k) {
	    if (s_cmp(sta + (j - 1 << 2), charc_1.stn + (k - 1 << 2), (ftnlen)
		    4, (ftnlen)4) == 0) {
		goto L17;
	    }
/* L16: */
	}
	if (! coordsyst_1.single_turbo__) {
	    if (coordsyst_1.isingle == 0) {
		s_wsle(&io___481);
		do_lio(&c__9, &c__1, "WARNING:     Event # ", (ftnlen)21);
		do_lio(&c__3, &c__1, (char *)&(*i__), (ftnlen)sizeof(integer))
			;
		e_wsle();
	    }
	    if (coordsyst_1.isingle > 0) {
		s_wsle(&io___482);
		do_lio(&c__9, &c__1, "WARNING:     Event # ", (ftnlen)21);
		do_lio(&c__3, &c__1, (char *)&coordsyst_1.isingle, (ftnlen)
			sizeof(integer));
		e_wsle();
	    }
	    s_wsfe(&io___483);
	    do_fio(&c__1, sta + (j - 1 << 2), (ftnlen)4);
	    e_wsfe();
	    s_wsle(&io___484);
	    do_lio(&c__9, &c__1, "Phase therefore skipped", (ftnlen)23);
	    e_wsle();
	}
/* c      write(6,*)'Event # ',i */
	s_wsfe(&io___485);
	do_fio(&c__1, sta + (j - 1 << 2), (ftnlen)4);
	e_wsfe();
	s_wsle(&io___486);
	do_lio(&c__9, &c__1, "Phase therefore skipped", (ftnlen)23);
	e_wsle();
	s_wsle(&io___487);
	e_wsle();
	if (coordsyst_1.isingle > 0) {
	    s_wsfe(&io___488);
	    do_fio(&c__1, sta + (j - 1 << 2), (ftnlen)4);
	    e_wsfe();
	}
	goto L15;
L17:
/* Computing 2nd power */
	r__1 = statn_1.x[k - 1] - event_1.e[(*i__ << 2) - 3];
/* Computing 2nd power */
	r__2 = statn_1.x[k + 649] - event_1.e[(*i__ << 2) - 2];
	ss1 = sqrt(r__1 * r__1 + r__2 * r__2);
	if (ss1 > param_1.dmax__) {
	    if (! coordsyst_1.single_turbo__) {
		s_wsle(&io___490);
		do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
		e_wsle();
		s_wsfe(&io___491);
		do_fio(&c__1, (char *)&ss1, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&param_1.dmax__, (ftnlen)sizeof(real));
		e_wsfe();
	    }
	    if (coordsyst_1.isingle != 0) {
		s_wsfe(&io___492);
		do_fio(&c__1, (char *)&ss1, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&param_1.dmax__, (ftnlen)sizeof(real));
		e_wsfe();
		s_wsfe(&io___493);
		do_fio(&c__1, sta + (j - 1 << 2), (ftnlen)4);
		e_wsfe();
	    }
	    goto L15;
	}

/*     test for only one p-reading of same station per event */

	if (ipwt[j - 1] == 5) {
	    goto L888;
	}

/* dont test for "weight 5" phases */
	i__2 = j - 1;
	for (ll = 1; ll <= i__2; ++ll) {
	    itest = 9;
	    if (modela_1.nsp == 1 && (*(unsigned char *)&cphase[j - 1] == 's' 
		    || *(unsigned char *)&cphase[j - 1] == 'S')) {
	    } else {
		if (k == obb_1.istm[ll + *i__ * 650 - 651] && ipwt[ll - 1] < 
			4) {
		    if (*(unsigned char *)&cphase[j - 1] == 'p') {
			itest = 0;
		    }
		    if (*(unsigned char *)&cphase[j - 1] == 'P') {
			itest = 0;
		    }
		    if (*(unsigned char *)&cphase[j - 1] == 's') {
			itest = 1;
		    }
		    if (*(unsigned char *)&cphase[j - 1] == 'S') {
			itest = 1;
		    }
		    if (*(unsigned char *)&cphase[j - 1] == 'm') {
			itest = -1;
		    }
		    if (*(unsigned char *)&cphase[j - 1] == 'M') {
			itest = -1;
		    }
		    if (*(unsigned char *)&cphase[j - 1] == '-') {
			itest = 2;
		    }
		    if (obb_1.sphase[ll + *i__ * 650 - 651] == (real) itest) {
/* twice the same phase in thi */
			if (coordsyst_1.isingle == 0) {
			    ie = *i__;
			}
			if (coordsyst_1.isingle > 0) {
			    ie = coordsyst_1.isingle;
			}
			if (! coordsyst_1.single_turbo__) {
			    s_wsle(&io___497);
			    do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
			    e_wsle();
			    s_wsle(&io___498);
			    do_lio(&c__9, &c__1, "PHASETEST: POSSIBLE ERROR "
				    "in phaselist !!", (ftnlen)41);
			    e_wsle();
			    s_wsfe(&io___499);
			    do_fio(&c__1, (char *)&event_1.iyr[*i__ - 1], (
				    ftnlen)sizeof(integer));
			    do_fio(&c__1, (char *)&event_1.imo[*i__ - 1], (
				    ftnlen)sizeof(integer));
			    do_fio(&c__1, (char *)&event_1.iday[*i__ - 1], (
				    ftnlen)sizeof(integer));
			    do_fio(&c__1, (char *)&event_1.ihr[*i__ - 1], (
				    ftnlen)sizeof(integer));
			    do_fio(&c__1, (char *)&event_1.imin[*i__ - 1], (
				    ftnlen)sizeof(integer));
			    e_wsfe();
			    s_wsle(&io___500);
			    do_lio(&c__9, &c__1, "Event=", (ftnlen)6);
			    do_lio(&c__3, &c__1, (char *)&ie, (ftnlen)sizeof(
				    integer));
			    do_lio(&c__9, &c__1, " Obs-nr. = ", (ftnlen)11);
			    do_lio(&c__3, &c__1, (char *)&j, (ftnlen)sizeof(
				    integer));
			    do_lio(&c__9, &c__1, " >>> Station ", (ftnlen)13);
			    do_lio(&c__9, &c__1, sta + (j - 1 << 2), (ftnlen)
				    4);
			    do_lio(&c__9, &c__1, " & Phase = ", (ftnlen)11);
			    do_lio(&c__9, &c__1, cphase + (j - 1), (ftnlen)1);
			    do_lio(&c__9, &c__1, " already occured!", (ftnlen)
				    17);
			    e_wsle();
			}
			s_wsle(&io___501);
			do_lio(&c__9, &c__1, "PHASETEST: POSSIBLE ERROR in p"
				"haselist !!", (ftnlen)41);
			e_wsle();
			s_wsfe(&io___502);
			do_fio(&c__1, (char *)&event_1.iyr[*i__ - 1], (ftnlen)
				sizeof(integer));
			do_fio(&c__1, (char *)&event_1.imo[*i__ - 1], (ftnlen)
				sizeof(integer));
			do_fio(&c__1, (char *)&event_1.iday[*i__ - 1], (
				ftnlen)sizeof(integer));
			do_fio(&c__1, (char *)&event_1.ihr[*i__ - 1], (ftnlen)
				sizeof(integer));
			do_fio(&c__1, (char *)&event_1.imin[*i__ - 1], (
				ftnlen)sizeof(integer));
			e_wsfe();
			s_wsle(&io___503);
			do_lio(&c__9, &c__1, "Event=", (ftnlen)6);
			do_lio(&c__3, &c__1, (char *)&ie, (ftnlen)sizeof(
				integer));
			do_lio(&c__9, &c__1, " Obs-nr. = ", (ftnlen)11);
			do_lio(&c__3, &c__1, (char *)&j, (ftnlen)sizeof(
				integer));
			do_lio(&c__9, &c__1, " >>> Station ", (ftnlen)13);
			do_lio(&c__9, &c__1, sta + (j - 1 << 2), (ftnlen)4);
			do_lio(&c__9, &c__1, " & Phase = ", (ftnlen)11);
			do_lio(&c__9, &c__1, cphase + (j - 1), (ftnlen)1);
			do_lio(&c__9, &c__1, " already occured!", (ftnlen)17);
			e_wsle();
			s_wsle(&io___504);
			e_wsle();
			if (coordsyst_1.isingle == 0) {
			    if (! coordsyst_1.single_turbo__) {
				s_wsle(&io___505);
				do_lio(&c__9, &c__1, "subr. INPUTDATA >>> pr"
					"ogram will stop", (ftnlen)37);
				e_wsle();
				s_wsle(&io___506);
				e_wsle();
			    }
			    iphaseteststopflag = 1;
			} else {
			    if (! coordsyst_1.single_turbo__) {
				s_wsle(&io___508);
				do_lio(&c__9, &c__1, "INPUTDATA>>> neverthel"
					"ess, program continues", (ftnlen)44);
				e_wsle();
				s_wsle(&io___509);
				e_wsle();
			    }
			}
/*              iphaseteststopflag is SAVED at beginning of subr. inputdata */
/*             ! forget never that error was detected! */
/*                 stop'PHASE-TEST: FATAL ERROR in phaselist !' */
		    }
		}
	    }
	}

/*     arrive here, if station on stationlist and phase is accepted by all tests: */

L888:
	++nobs;
	obb_1.amx[nobs - 1] = obb_1.amx[j - 1];
	obb_1.prx[nobs - 1] = obb_1.prx[j - 1];
/* added 18.9.91 / uk */
	if (coordsyst_1.isingle > 0) {
	    if (coordsyst_1.ised == 2) {
		*(unsigned char *)&obb_1.prmk[nobs - 1] = *(unsigned char *)&
			rmk1[j - 1];
		*(unsigned char *)&obb_1.prmk[nobs + 649] = *(unsigned char *)
			&rmk2[j - 1];
	    } else {
		*(unsigned char *)&obb_1.prmk[nobs - 1] = ' ';
		*(unsigned char *)&obb_1.prmk[nobs + 649] = ' ';
	    }
	}
	for (l = 1; l <= 3; ++l) {
/* L66: */
	    statn_1.d__[nobs + (l + *i__ * 3) * 650 - 2601] = statn_1.x[k + l 
		    * 650 - 651];
	}
	obb_1.pt[nobs + *i__ * 650 - 651] = sec[j - 1];
	obb_1.kpwt[nobs + *i__ * 650 - 651] = ipwt[j - 1];
	obb_1.istm[nobs + *i__ * 650 - 651] = k;
	s_copy(charc_1.smn + (nobs + *i__ * 650 - 651 << 2), sta + (j - 1 << 
		2), (ftnlen)4, (ftnlen)4);
/* ***    kpwt(nobs,i) - p or s weight for observation nobs, event i */
/* ***    istm(nobs,i) - station number for observation */
/* ***    smn(nobs,i) - station name for observation */
/* **    iphase(nobs,i) gives the model number for the observation */
	if (modela_1.nsp == 2) {
	    goto L21;
	}


	obb_1.iphase[nobs + *i__ * 650 - 651] = statn_1.model[0];

/* ***     sphase(nobs,i) is 0. for a p observation */
/* ***                       1. for an s observation */
/* uk*                      -1. for a reflected P observation */
/* hrm                       2. for a S-P phase */

	obb_1.sphase[nobs + *i__ * 650 - 651] = 0.f;
	if (*(unsigned char *)&cphase[j - 1] == *(unsigned char *)&sc[0] || *(
		unsigned char *)&cphase[j - 1] == *(unsigned char *)&ss[0]) {
	    obb_1.sphase[nobs + *i__ * 650 - 651] = 1.f;
	}
	if (*(unsigned char *)&cphase[j - 1] == 'm' || *(unsigned char *)&
		cphase[j - 1] == 'M') {
	    obb_1.sphase[nobs + *i__ * 650 - 651] = -1.f;
	}
	if (*(unsigned char *)&cphase[j - 1] == '-') {
	    obb_1.sphase[nobs + *i__ * 650 - 651] = 2.f;
	}

/* *** w(nobs,i) is an observation weighting factor : */

	i__2 = ipwt[j - 1] << 1;
	obb_1.w[nobs + *i__ * 650 - 651] = 1.f / pow_ii(&c__2, &i__2);

	if (*(unsigned char *)&cphase[j - 1] == *(unsigned char *)&sc[0] || *(
		unsigned char *)&cphase[j - 1] == *(unsigned char *)&ss[0] || 
		*(unsigned char *)&cphase[j - 1] == '-') {
	    obb_1.w[nobs + *i__ * 650 - 651] = param_1.swtfac * obb_1.w[nobs 
		    + *i__ * 650 - 651];
	}
	if (ipwt[j - 1] > 4) {
	    obb_1.w[nobs + *i__ * 650 - 651] = 0.f;
/* necessary for single-event-mode !!! */
	    ++obb_1.nobswithw0;
	}
	wsum += obb_1.w[nobs + *i__ * 650 - 651];
	goto L15;
L21:
/* nsp=2 */
	if (*(unsigned char *)&cphase[j - 1] == *(unsigned char *)&sc[0] || *(
		unsigned char *)&cphase[j - 1] == *(unsigned char *)&ss[0]) {
	    goto L22;
	}
/* s-phase */
	if (*(unsigned char *)&cphase[j - 1] == '-') {
	    goto L22;
	}
/* s-p phase */
	obb_1.sphase[nobs + *i__ * 650 - 651] = 0.f;
	if (*(unsigned char *)&cphase[j - 1] == 'm' || *(unsigned char *)&
		cphase[j - 1] == 'M') {
	    obb_1.sphase[nobs + *i__ * 650 - 651] = -1.f;
	}
/* ref */
	obb_1.iphase[nobs + *i__ * 650 - 651] = statn_1.model[0];
/*      iphase(nobs,i)=model(2*k-1) */
	i__2 = ipwt[j - 1] << 1;
	obb_1.w[nobs + *i__ * 650 - 651] = 1.f / pow_ii(&c__2, &i__2);
	if (ipwt[j - 1] >= 4) {
	    obb_1.w[nobs + *i__ * 650 - 651] = 0.f;
/* necessary for single-event-mode !!! */
	    ++obb_1.nobswithw0;
	}
	wsum += obb_1.w[nobs + *i__ * 650 - 651];
	goto L15;
L22:
	obb_1.sphase[nobs + *i__ * 650 - 651] = 1.f;
	if (*(unsigned char *)&cphase[j - 1] == '-') {
	    obb_1.sphase[nobs + *i__ * 650 - 651] = 2.f;
	}

/*     For s-p phases the model parameter is set to the s-wave model */


/* s-p phase */
	obb_1.iphase[nobs + *i__ * 650 - 651] = statn_1.model[1];
	i__2 = ipwt[j - 1] << 1;
	obb_1.w[nobs + *i__ * 650 - 651] = param_1.swtfac * 1.f / pow_ii(&
		c__2, &i__2);
	if (ipwt[j - 1] >= 4) {
	    obb_1.w[nobs + *i__ * 650 - 651] = 0.f;
/* necessary for single-event-mode !!! */
	    ++obb_1.nobswithw0;
	}
	wsum += obb_1.w[nobs + *i__ * 650 - 651];
L15:
	;
    }

/*     one event is read-in now : */

/* L14: */
    obb_1.knobs[*i__ - 1] = nobs;
/* ek list P and S obs separateley: */
    if (modela_1.nsp == 2) {
	nobsp = 0;
	nobss = 0;
	i__1 = nobs;
	for (j = 1; j <= i__1; ++j) {
	    if (obb_1.sphase[j + *i__ * 650 - 651] == 0.f) {
		++nobsp;
	    }
	    if (obb_1.sphase[j + *i__ * 650 - 651] == 1.f) {
		++nobss;
	    }
	}
    }
    if (! coordsyst_1.single_turbo__) {
	if (xlat < 0.f) {
	    *(unsigned char *)cns = 'S';
	    xxlat = -xlat;
	} else {
	    *(unsigned char *)cns = 'N';
	    xxlat = xlat;
	}
	if (alon < 0.f) {
	    *(unsigned char *)cew = 'E';
	    aalon = -alon;
	} else {
	    *(unsigned char *)cew = 'W';
	    aalon = alon;
	}
	if (coordsyst_1.icoordsystem == 2) {
	    xxx = -event_1.e[(*i__ << 2) - 3];
	} else {
	    xxx = event_1.e[(*i__ << 2) - 3];
	}
	if (*i__ <= dimen_1.neqs) {
/* ek print P and S number of obs */
	    if (modela_1.nsp == 2) {
		s_wsfe(&io___518);
		do_fio(&c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&event_1.iyr[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.imo[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.iday[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.ihr[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.imin[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.e[(*i__ << 2) - 4], (ftnlen)
			sizeof(real));
		do_fio(&c__1, (char *)&xxlat, (ftnlen)sizeof(real));
		do_fio(&c__1, cns, (ftnlen)1);
		do_fio(&c__1, (char *)&aalon, (ftnlen)sizeof(real));
		do_fio(&c__1, cew, (ftnlen)1);
		do_fio(&c__1, (char *)&depth, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&xxx, (ftnlen)sizeof(real));
		for (j = 3; j <= 4; ++j) {
		    do_fio(&c__1, (char *)&event_1.e[j + (*i__ << 2) - 5], (
			    ftnlen)sizeof(real));
		}
		do_fio(&c__1, (char *)&event_1.emag[*i__ - 1], (ftnlen)sizeof(
			real));
		do_fio(&c__1, (char *)&event_1.ifx[*i__ - 1], (ftnlen)sizeof(
			integer));
		i__1 = obb_1.knobs[*i__ - 1] - obb_1.nobswithw0;
		do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&nobsp, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&nobss, (ftnlen)sizeof(integer));
		e_wsfe();
	    } else {
		s_wsfe(&io___519);
		do_fio(&c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&event_1.iyr[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.imo[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.iday[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.ihr[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.imin[*i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&event_1.e[(*i__ << 2) - 4], (ftnlen)
			sizeof(real));
		do_fio(&c__1, (char *)&xxlat, (ftnlen)sizeof(real));
		do_fio(&c__1, cns, (ftnlen)1);
		do_fio(&c__1, (char *)&aalon, (ftnlen)sizeof(real));
		do_fio(&c__1, cew, (ftnlen)1);
		do_fio(&c__1, (char *)&depth, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&xxx, (ftnlen)sizeof(real));
		for (j = 3; j <= 4; ++j) {
		    do_fio(&c__1, (char *)&event_1.e[j + (*i__ << 2) - 5], (
			    ftnlen)sizeof(real));
		}
		do_fio(&c__1, (char *)&event_1.emag[*i__ - 1], (ftnlen)sizeof(
			real));
		do_fio(&c__1, (char *)&event_1.ifx[*i__ - 1], (ftnlen)sizeof(
			integer));
		i__1 = obb_1.knobs[*i__ - 1] - obb_1.nobswithw0;
		do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	}
	if (*i__ > dimen_1.neqs) {
/* shots */
	    s_wsfe(&io___520);
	    do_fio(&c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&event_1.iyr[*i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.imo[*i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.iday[*i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.ihr[*i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.imin[*i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.e[(*i__ << 2) - 4], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&xxlat, (ftnlen)sizeof(real));
	    do_fio(&c__1, cns, (ftnlen)1);
	    do_fio(&c__1, (char *)&aalon, (ftnlen)sizeof(real));
	    do_fio(&c__1, cew, (ftnlen)1);
	    do_fio(&c__1, (char *)&depth, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&xxx, (ftnlen)sizeof(real));
	    for (j = 3; j <= 4; ++j) {
		do_fio(&c__1, (char *)&event_1.e[j + (*i__ << 2) - 5], (
			ftnlen)sizeof(real));
	    }
	    do_fio(&c__1, (char *)&event_1.emag[*i__ - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&statn_1.map2[*i__ - dimen_1.neqs - 1], (
		    ftnlen)sizeof(integer));
	    i__1 = obb_1.knobs[*i__ - 1] - obb_1.nobswithw0;
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    }

/*      No more active (format 1607) */
/* 1607 format(1x,i3,1x,3i2.2,1x,2i2.2,1x,f5.2,1x,f7.4,a1,1x,f8.4,a1,1x, */
/*     &       f6.2,3f7.2,f5.2,i2,i4) */

/*     normalize weights: */

    if (coordsyst_1.isingle > 0) {
	if (obb_1.knobs[*i__ - 1] - obb_1.nobswithw0 < dimen_1.nvar) {
	    return 0;
	}
	if (wsum <= 0.f) {
	    return 0;
	}
    }
    i__1 = nobs;
    for (j = 1; j <= i__1; ++j) {
	obb_1.w[j + *i__ * 650 - 651] = obb_1.w[j + *i__ * 650 - 651] * (nobs 
		- obb_1.nobswithw0) / wsum;
    }

    if (iphaseteststopflag == 1 && *i__ == dimen_1.neqs + dimen_1.nshot) {
	s_stop("INPUTDATA >>> PHASE-TEST: FATAL ERROR in phaselist !", (
		ftnlen)52);
    }
    return 0;

/* L80: */
    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___521);
	e_wsfe();
/* ---- read past end of data */
	s_wsle(&io___522);
	do_lio(&c__9, &c__1, "WARNING:  subr. INPUTDATA >>> end of data enco"
		"untered", (ftnlen)53);
	e_wsle();
    }
    s_wsle(&io___523);
    do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
    e_wsle();
    s_stop("subr. INPUTDATA >>> error: end of data!", (ftnlen)39);

L998:
    openerror_("inputdata", "EQ-data-input-file FOR008", (ftnlen)9, (ftnlen)
	    25);
L999:
    openerror_("inputdata", "SHOT-data-input-file FOR009", (ftnlen)9, (ftnlen)
	    27);
    return 0;

} /* inputdata_ */


/* of subr. inputdata */
/* Subroutine */ int statisticsout_(void)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void), do_lio(integer *, integer *, char 
	    *, ftnlen), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe(void), i_nint(real *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer nobsmge6, depthnri[105], depthnrl[105], i__, i1, i2, i3, 
	    i4, ii, mag, nobslesseq1;
    static real tot, err;
    static integer mge6;
    static real res0, res1, res2, res3, res4;
    static integer nhit;
    static real rlen, mini;
    static integer ntot;
    static real maxi, xmag;
    static integer mge5i, mge5l, idepi, idepl, irefl, magnr[49], irefr, isour,
	     iavgap;
    static real depthi, depthl;
    static char cstari[51], cstarl[51];
    static integer itotal, nobsnr[49], lesseq1;

    /* Fortran I/O blocks */
    static cilist io___531 = { 0, 16, 0, 0, 0 };
    static cilist io___532 = { 0, 16, 0, 0, 0 };
    static cilist io___533 = { 0, 16, 0, 0, 0 };
    static cilist io___534 = { 0, 16, 0, 0, 0 };
    static cilist io___535 = { 0, 16, 0, 0, 0 };
    static cilist io___536 = { 0, 16, 0, 0, 0 };
    static cilist io___537 = { 0, 16, 0, 0, 0 };
    static cilist io___538 = { 0, 16, 0, 0, 0 };
    static cilist io___539 = { 0, 16, 0, 0, 0 };
    static cilist io___540 = { 0, 16, 0, 0, 0 };
    static cilist io___541 = { 0, 16, 0, 0, 0 };
    static cilist io___542 = { 0, 16, 0, 0, 0 };
    static cilist io___543 = { 0, 16, 0, 0, 0 };
    static cilist io___544 = { 0, 16, 0, 0, 0 };
    static cilist io___545 = { 0, 16, 0, 0, 0 };
    static cilist io___546 = { 0, 16, 0, 0, 0 };
    static cilist io___547 = { 0, 16, 0, "(a)", 0 };
    static cilist io___548 = { 0, 16, 0, 0, 0 };
    static cilist io___553 = { 0, 16, 0, "(2x,i2,3x,f6.2,'...',f6.2,' km   '"
	    ",                       f5.2,' km/s',2(1x,i4),1x,f5.1,1x,i5,2(1x"
	    ",f5.1),2x,i4)", 0 };
    static cilist io___554 = { 0, 16, 0, "(2x,i2,3x,f6.2,'...',5x,'  km   ',"
	    "                        f5.2,' km/s',2(1x,i4),1x,f5.1,1x,i5,2(1x"
	    ",f5.1))", 0 };
    static cilist io___555 = { 0, 16, 0, 0, 0 };
    static cilist io___556 = { 0, 16, 0, "(' Total nr of events was ',i4)", 0 
	    };
    static cilist io___557 = { 0, 16, 0, 0, 0 };
    static cilist io___558 = { 0, 16, 0, "(' Total nr of refracted rays = ',"
	    "i5)", 0 };
    static cilist io___559 = { 0, 16, 0, "(' Total nr of reflected rays = ',"
	    "i5)", 0 };
    static cilist io___560 = { 0, 16, 0, "(' Total nr of   other   rays = ',"
	    "i5)", 0 };
    static cilist io___562 = { 0, 16, 0, "('                              --"
	    "----')", 0 };
    static cilist io___563 = { 0, 16, 0, "(' Total nr of    all    rays = ',"
	    "i5)", 0 };
    static cilist io___564 = { 0, 16, 0, 0, 0 };
    static cilist io___565 = { 0, 16, 0, 0, 0 };
    static cilist io___567 = { 0, 16, 0, "(1x,' Straight and direct rays : '"
	    ",f7.2,' meters')", 0 };
    static cilist io___568 = { 0, 16, 0, "(1x,' Refracted           rays : '"
	    ",f7.2,' meters')", 0 };
    static cilist io___569 = { 0, 16, 0, "(1x,' Reflected           rays : '"
	    ",f7.2,' meters')", 0 };
    static cilist io___570 = { 0, 16, 0, 0, 0 };
    static cilist io___571 = { 0, 16, 0, 0, 0 };
    static cilist io___572 = { 0, 16, 0, 0, 0 };
    static cilist io___573 = { 0, 16, 0, "(1x,'Average horizontal ray length"
	    " = ',                          f6.1,' km   (Hypocenter --> Stati"
	    "on) ')", 0 };
    static cilist io___574 = { 0, 16, 0, "(1x,'Average  vertical  ray length"
	    " = ',                          f6.1,' km   (Deepest ray-point --"
	    "> Station)')", 0 };
    static cilist io___575 = { 0, 16, 0, 0, 0 };
    static cilist io___576 = { 0, 16, 0, 0, 0 };
    static cilist io___577 = { 0, 16, 0, 0, 0 };
    static cilist io___578 = { 0, 16, 0, 0, 0 };
    static cilist io___579 = { 0, 16, 0, 0, 0 };
    static cilist io___580 = { 0, 16, 0, 0, 0 };
    static cilist io___581 = { 0, 16, 0, 0, 0 };
    static cilist io___582 = { 0, 16, 0, "(5('  Event# -> GAP'))", 0 };
    static cilist io___583 = { 0, 16, 0, "(5(5x,i3,' -> ',i3))", 0 };
    static cilist io___584 = { 0, 16, 0, 0, 0 };
    static cilist io___588 = { 0, 16, 0, "(1x,'GAPs were between ',i3,' and "
	    "',i3)", 0 };
    static cilist io___589 = { 0, 16, 0, "('      (average GAP was ',i3,')')",
	     0 };
    static cilist io___590 = { 0, 16, 0, 0, 0 };
    static cilist io___591 = { 0, 16, 0, 0, 0 };
    static cilist io___592 = { 0, 16, 0, 0, 0 };
    static cilist io___593 = { 0, 16, 0, 0, 0 };
    static cilist io___594 = { 0, 16, 0, 0, 0 };
    static cilist io___595 = { 0, 16, 0, 0, 0 };
    static cilist io___596 = { 0, 16, 0, 0, 0 };
    static cilist io___603 = { 0, 16, 0, "(1x,'MAG<= 1.0 ','(',i3,') ',a)", 0 
	    };
    static cilist io___604 = { 0, 16, 0, "(1x,'MAG<= 1.0 ','(',i3,') ',a)", 0 
	    };
    static cilist io___606 = { 0, 16, 0, "(1x,'MAG = ',f3.1,' (',i3,') ',a)", 
	    0 };
    static cilist io___607 = { 0, 16, 0, "(1x,'MAG = ',f3.1,' (',i3,') ',a)", 
	    0 };
    static cilist io___608 = { 0, 16, 0, "(1x,'MAG>= 6.0 ','(',i3,') ',a)", 0 
	    };
    static cilist io___609 = { 0, 16, 0, "(1x,'MAG>= 6.0 ','(',i3,') ',a)", 0 
	    };
    static cilist io___610 = { 0, 16, 0, 0, 0 };
    static cilist io___611 = { 0, 16, 0, 0, 0 };
    static cilist io___612 = { 0, 16, 0, 0, 0 };
    static cilist io___613 = { 0, 16, 0, 0, 0 };
    static cilist io___614 = { 0, 16, 0, 0, 0 };
    static cilist io___615 = { 0, 16, 0, 0, 0 };
    static cilist io___616 = { 0, 16, 0, 0, 0 };
    static cilist io___617 = { 0, 16, 0, 0, 0 };
    static cilist io___618 = { 0, 16, 0, 0, 0 };
    static cilist io___619 = { 0, 16, 0, 0, 0 };
    static cilist io___627 = { 0, 16, 0, "(1x,'DEPTH ( input ) = ',f4.0,' km"
	    " :  ',a)", 0 };
    static cilist io___628 = { 0, 16, 0, "(1x,'DEPTH ( input ) = ',f4.0,' km"
	    " :  ',a)", 0 };
    static cilist io___629 = { 0, 16, 0, "(1x,'DEPTH (last_IT) = ',f4.0,' km"
	    " :  ',a)", 0 };
    static cilist io___630 = { 0, 16, 0, "(1x,'DEPTH (last_IT) = ',f4.0,' km"
	    " :  ',a)", 0 };
    static cilist io___631 = { 0, 16, 0, "(1x,'DEPTH ( input ) > 100. ','km "
	    ":  ',a)", 0 };
    static cilist io___632 = { 0, 16, 0, "(1x,'DEPTH ( input ) > 100. ','km "
	    ":  ',a)", 0 };
    static cilist io___633 = { 0, 16, 0, "(1x,'DEPTH (last_IT) > 100. ','km "
	    ":  ',a)", 0 };
    static cilist io___634 = { 0, 16, 0, "(1x,'DEPTH (last_IT) > 100. ','km "
	    ":  ',a)", 0 };
    static cilist io___635 = { 0, 16, 0, 0, 0 };
    static cilist io___636 = { 0, 16, 0, 0, 0 };
    static cilist io___637 = { 0, 16, 0, 0, 0 };
    static cilist io___638 = { 0, 16, 0, 0, 0 };
    static cilist io___639 = { 0, 16, 0, 0, 0 };
    static cilist io___640 = { 0, 16, 0, 0, 0 };
    static cilist io___641 = { 0, 16, 0, 0, 0 };
    static cilist io___642 = { 0, 16, 0, 0, 0 };
    static cilist io___643 = { 0, 16, 0, 0, 0 };
    static cilist io___644 = { 0, 16, 0, "(1x,'Stn#  Stn     RES          RE"
	    "S1        ',                   ' RES2         RES3         RES4')"
	    , 0 };
    static cilist io___656 = { 0, 16, 0, "(1x,i3,3x,a4,1x,5(f7.2,'(',i4,')'))"
	    , 0 };
    static cilist io___657 = { 0, 16, 0, "(1x,i3,3x,a4,1x,'-.-')", 0 };
    static cilist io___658 = { 0, 16, 0, 0, 0 };
    static cilist io___659 = { 0, 16, 0, 0, 0 };



/*     output the statistics done in this VELEST run */


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

    for (i__ = 1; i__ <= 105; ++i__) {
	depthnri[i__ - 1] = 0;
	depthnrl[i__ - 1] = 0;
    }
    for (i__ = 1; i__ <= 49; ++i__) {
	magnr[i__ - 1] = 0;
	nobsnr[i__ - 1] = 0;
    }

    i__1 = dimen_1.neqs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = modela_1.nltot - 1;
	for (ii = 1; ii <= i__2; ++ii) {
	    if (event_1.e[(i__ << 2) - 1] >= layer_1.h__[ii - 1] && event_1.e[
		    (i__ << 2) - 1] < layer_1.h__[ii]) {
		++hitl_1.ihypoclayer[ii - 1];
	    }
	}
	if (event_1.e[(i__ << 2) - 1] >= layer_1.h__[modela_1.nltot - 1]) {
	    ++hitl_1.ihypoclayer[modela_1.nltot - 1];
	}
    }
    rlen = 0.f;
    i__1 = modela_1.nltot;
    for (i__ = 1; i__ <= i__1; ++i__) {
	rlen += hitl_1.refraylen[i__ - 1];
/*  rlen  will be total refr.raylen */
    }
    i__1 = modela_1.nltot;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* hrm  The next if else statement seems to be neccessary to avoid */
/* hrm  floating point exceptions in case of rlen = 0 */
	if (rlen > 1e-5f) {
	    hitl_1.refraylen[i__ - 1] = hitl_1.refraylen[i__ - 1] * 100.f / 
		    rlen;
	} else {
	    hitl_1.refraylen[i__ - 1] = 0.f;
	}
	if (hitl_1.hitlay[i__ - 1] >= 1.f) {
	    hitl_1.hitlay[i__ + 99] /= hitl_1.hitlay[i__ - 1];
/*  average horiz. km in */
	    hitl_1.hitlay[i__ + 199] /= hitl_1.hitlay[i__ - 1];
/*  average verti. km in */
	}
    }
/* hitlay(i,1) = nofHITS of */
    s_wsle(&io___531);
    e_wsle();
    s_wsle(&io___532);
    e_wsle();
    s_wsle(&io___533);
    e_wsle();
    s_wsle(&io___534);
    e_wsle();
    s_wsle(&io___535);
    do_lio(&c__9, &c__1, "RAY-STATISTICS FOR  L A S T  ITERATION", (ftnlen)38)
	    ;
    e_wsle();
    s_wsle(&io___536);
    do_lio(&c__9, &c__1, "--------------------------------------", (ftnlen)38)
	    ;
    e_wsle();
    s_wsle(&io___537);
    e_wsle();
    s_wsle(&io___538);
    do_lio(&c__9, &c__1, "NHYP : nr of hypocenters in this layer", (ftnlen)38)
	    ;
    e_wsle();
    s_wsle(&io___539);
    do_lio(&c__9, &c__1, "NREF : nr of headwaves in this layer", (ftnlen)36);
    e_wsle();
    s_wsle(&io___540);
    do_lio(&c__9, &c__1, "%len : % of \"refracted km\" in this layer ", (
	    ftnlen)41);
    e_wsle();
    s_wsle(&io___541);
    do_lio(&c__9, &c__1, "       with respect to all refracted kilometers", (
	    ftnlen)47);
    e_wsle();
    s_wsle(&io___542);
    do_lio(&c__9, &c__1, "NHIT : nr of rays passed thru this layer", (ftnlen)
	    40);
    e_wsle();
    s_wsle(&io___543);
    do_lio(&c__9, &c__1, "xy-km: average horizontal ray length [km] in layer",
	     (ftnlen)50);
    e_wsle();
    s_wsle(&io___544);
    do_lio(&c__9, &c__1, "z-km : average  vertical  ray length [km] in layer",
	     (ftnlen)50);
    e_wsle();
    s_wsle(&io___545);
    do_lio(&c__9, &c__1, "RFLX : number of reflections at bottom of this lay"
	    "er", (ftnlen)52);
    e_wsle();
    s_wsle(&io___546);
    e_wsle();
    s_wsfe(&io___547);
    do_fio(&c__1, " nlay   top ..... bottom     velocity   NHYP NREF %len  N"
	    "HIT xy-km  z-km  RFLX", (ftnlen)78);
    e_wsfe();
    s_wsle(&io___548);
    e_wsle();
    irefr = 0;
    isour = 0;
    irefl = 0;
    i__1 = modela_1.nltot - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nhit = i_nint(&hitl_1.hitlay[i__ - 1]);
	s_wsfe(&io___553);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&layer_1.h__[i__ - 1], (ftnlen)sizeof(real));
	r__1 = layer_1.h__[i__ - 1] + layer_1.thk[i__ - 1];
	do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&layer_1.v[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&hitl_1.ihypoclayer[i__ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__1, (char *)&hitl_1.irefrlayer[i__ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__1, (char *)&hitl_1.refraylen[i__ - 1], (ftnlen)sizeof(real)
		);
	do_fio(&c__1, (char *)&nhit, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&hitl_1.hitlay[i__ + 99], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&hitl_1.hitlay[i__ + 199], (ftnlen)sizeof(real))
		;
	do_fio(&c__1, (char *)&hitl_1.irefllayer[i__ - 1], (ftnlen)sizeof(
		integer));
	e_wsfe();
	irefr += hitl_1.irefrlayer[i__ - 1];
	isour += hitl_1.ihypoclayer[i__ - 1];
	irefl += hitl_1.irefllayer[i__ - 1];
    }
    nhit = i_nint(&hitl_1.hitlay[modela_1.nltot - 1]);
    s_wsfe(&io___554);
    do_fio(&c__1, (char *)&modela_1.nltot, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&layer_1.h__[modela_1.nltot - 1], (ftnlen)sizeof(
	    real));
    do_fio(&c__1, (char *)&layer_1.v[modela_1.nltot - 1], (ftnlen)sizeof(real)
	    );
    do_fio(&c__1, (char *)&hitl_1.ihypoclayer[modela_1.nltot - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&hitl_1.irefrlayer[modela_1.nltot - 1], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&hitl_1.refraylen[modela_1.nltot - 1], (ftnlen)
	    sizeof(real));
    do_fio(&c__1, (char *)&nhit, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&hitl_1.hitlay[modela_1.nltot + 99], (ftnlen)sizeof(
	    real));
    do_fio(&c__1, (char *)&hitl_1.hitlay[modela_1.nltot + 199], (ftnlen)
	    sizeof(real));
    e_wsfe();
    irefr += hitl_1.irefrlayer[modela_1.nltot - 1];
    isour += hitl_1.ihypoclayer[modela_1.nltot - 1];
    irefl += hitl_1.irefllayer[modela_1.nltot - 1];

    s_wsle(&io___555);
    e_wsle();
    s_wsfe(&io___556);
    do_fio(&c__1, (char *)&isour, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsle(&io___557);
    e_wsle();
    s_wsfe(&io___558);
    do_fio(&c__1, (char *)&irefr, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___559);
    do_fio(&c__1, (char *)&irefl, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___560);
    do_fio(&c__1, (char *)&hitl_1.noheadwave, (ftnlen)sizeof(integer));
    e_wsfe();
    itotal = hitl_1.noheadwave + irefr + irefl;
    s_wsfe(&io___562);
    e_wsfe();
    s_wsfe(&io___563);
    do_fio(&c__1, (char *)&itotal, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsle(&io___564);
    e_wsle();
    s_wsle(&io___565);
    do_lio(&c__9, &c__1, "Average (absolute) error of the raytracers:", (
	    ftnlen)43);
    e_wsle();
    err = 0.f;
    if (hitl_1.noheadwave > 0) {
	err = (hitl_1.sterr + hitl_1.direrr) / hitl_1.noheadwave;
    }
    s_wsfe(&io___567);
    do_fio(&c__1, (char *)&err, (ftnlen)sizeof(real));
    e_wsfe();
    err = 0.f;
    if (irefr > 0) {
	err = hitl_1.refrerr / irefr;
    }
    s_wsfe(&io___568);
    do_fio(&c__1, (char *)&err, (ftnlen)sizeof(real));
    e_wsfe();
    err = 0.f;
    if (irefl > 0) {
	err = hitl_1.reflerr / irefl;
    }
    s_wsfe(&io___569);
    do_fio(&c__1, (char *)&err, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsle(&io___570);
    e_wsle();
    s_wsle(&io___571);
    e_wsle();
    hitl_1.avhraylen /= itotal;
    s_wsle(&io___572);
    do_lio(&c__9, &c__1, "ALL RAYS TOGETHER:", (ftnlen)18);
    e_wsle();
    s_wsfe(&io___573);
    do_fio(&c__1, (char *)&hitl_1.avhraylen, (ftnlen)sizeof(real));
    e_wsfe();
    hitl_1.avvraylen /= itotal;
    s_wsfe(&io___574);
    do_fio(&c__1, (char *)&hitl_1.avvraylen, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsle(&io___575);
    e_wsle();

    s_wsle(&io___576);
    e_wsle();
    s_wsle(&io___577);
    e_wsle();
    s_wsle(&io___578);
    do_lio(&c__9, &c__1, "... and some more STATISTICS ", (ftnlen)29);
    e_wsle();
    s_wsle(&io___579);
    do_lio(&c__9, &c__1, "---------------------------- ", (ftnlen)29);
    e_wsle();
    s_wsle(&io___580);
    do_lio(&c__9, &c__1, " GAP of final epicenters:", (ftnlen)25);
    e_wsle();
    s_wsle(&io___581);
    e_wsle();
    s_wsfe(&io___582);
    e_wsfe();
    s_wsfe(&io___583);
    i__1 = dimen_1.neqs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&gap_1.igap[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    s_wsle(&io___584);
    e_wsle();
    mini = 361.f;
    maxi = -1.f;
    iavgap = 0;
    i__1 = dimen_1.neqs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((real) gap_1.igap[i__ - 1] > maxi) {
	    maxi = (real) gap_1.igap[i__ - 1];
	}
	if ((real) gap_1.igap[i__ - 1] < mini) {
	    mini = (real) gap_1.igap[i__ - 1];
	}
	iavgap += gap_1.igap[i__ - 1];
    }
    r__1 = (real) iavgap / (real) dimen_1.neqs;
    iavgap = i_nint(&r__1);
    s_wsfe(&io___588);
    i__1 = i_nint(&mini);
    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
    i__2 = i_nint(&maxi);
    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___589);
    do_fio(&c__1, (char *)&iavgap, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsle(&io___590);
    e_wsle();

    s_wsle(&io___591);
    e_wsle();
    s_wsle(&io___592);
    e_wsle();
    s_wsle(&io___593);
    do_lio(&c__9, &c__1, " MAGNITUDES of INPUT-DATA:", (ftnlen)26);
    e_wsle();
    s_wsle(&io___594);
    e_wsle();
    s_wsle(&io___595);
    do_lio(&c__9, &c__1, "Magnitude (# of events)   ***average number of obs"
	    "***", (ftnlen)53);
    e_wsle();
    s_wsle(&io___596);
    e_wsle();
    lesseq1 = 0;
    mge6 = 0;
    nobslesseq1 = 0;
    nobsmge6 = 0;
    i__1 = dimen_1.neqs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	r__1 = event_1.emag[i__ - 1] * 10.f;
	mag = i_nint(&r__1);
	if (mag <= 10) {
	    nobslesseq1 += obb_1.knobs[i__ - 1];
	    ++lesseq1;
	}
	if (mag > 10 && mag < 60) {
	    ++magnr[mag - 11];
	    nobsnr[mag - 11] += obb_1.knobs[i__ - 1];
	}
	if (mag >= 60) {
	    ++mge6;
	    nobsmge6 += obb_1.knobs[i__ - 1];
	}
    }
    s_copy(cstari, "*********1*********2*********3*********4*********5>", (
	    ftnlen)51, (ftnlen)51);
    if (lesseq1 > 0) {
	r__1 = (real) nobslesseq1 / (real) lesseq1;
	nobslesseq1 = i_nint(&r__1);
    }
    if (nobslesseq1 > 50) {
	nobslesseq1 = 51;
    }
    if (nobslesseq1 > 0) {
	s_wsfe(&io___603);
	do_fio(&c__1, (char *)&lesseq1, (ftnlen)sizeof(integer));
	do_fio(&c__1, cstari, nobslesseq1);
	e_wsfe();
    } else {
	s_wsfe(&io___604);
	do_fio(&c__1, (char *)&lesseq1, (ftnlen)sizeof(integer));
	do_fio(&c__1, " ", (ftnlen)1);
	e_wsfe();
    }
    for (i__ = 1; i__ <= 49; ++i__) {
	xmag = (i__ + 10.f) / 10.f;
	if (magnr[i__ - 1] > 0) {
	    r__1 = (real) nobsnr[i__ - 1] / (real) magnr[i__ - 1];
	    nobsnr[i__ - 1] = i_nint(&r__1);
	}
	if (nobsnr[i__ - 1] > 50) {
	    nobsnr[i__ - 1] = 51;
	}
	if (nobsnr[i__ - 1] > 0) {
	    s_wsfe(&io___606);
	    do_fio(&c__1, (char *)&xmag, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&magnr[i__ - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, cstari, nobsnr[i__ - 1]);
	    e_wsfe();
	} else {
	    s_wsfe(&io___607);
	    do_fio(&c__1, (char *)&xmag, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&magnr[i__ - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, " ", (ftnlen)1);
	    e_wsfe();
	}
    }
    if (mge6 > 0) {
	r__1 = (real) nobsmge6 / (real) mge6;
	nobsmge6 = i_nint(&r__1);
    }
    if (nobsmge6 > 50) {
	nobsmge6 = 51;
    }
    if (nobsmge6 > 0) {
	s_wsfe(&io___608);
	do_fio(&c__1, (char *)&mge6, (ftnlen)sizeof(integer));
	do_fio(&c__1, cstari, nobsmge6);
	e_wsfe();
    } else {
	s_wsfe(&io___609);
	do_fio(&c__1, (char *)&mge6, (ftnlen)sizeof(integer));
	do_fio(&c__1, " ", (ftnlen)1);
	e_wsfe();
    }
    s_wsle(&io___610);
    e_wsle();
    s_wsle(&io___611);
    e_wsle();
    s_wsle(&io___612);
    e_wsle();

    s_wsle(&io___613);
    e_wsle();
    s_wsle(&io___614);
    e_wsle();
    s_wsle(&io___615);
    do_lio(&c__9, &c__1, " DEPTHs of INPUT-DATA and of LAST ITERATION:", (
	    ftnlen)44);
    e_wsle();
    s_wsle(&io___616);
    do_lio(&c__9, &c__1, " ===========================================", (
	    ftnlen)44);
    e_wsle();
    s_wsle(&io___617);
    e_wsle();
    s_wsle(&io___618);
    do_lio(&c__9, &c__1, "      Depth       # of events  ", (ftnlen)31);
    e_wsle();
    s_wsle(&io___619);
    e_wsle();
    lesseq1 = 0;
    mge6 = 0;
    mge5l = 0;
    mge5i = 0;
    i__1 = dimen_1.neqs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	idepi = i_nint(&obb_1.depthsofinput[i__ - 1]);
	if (idepi < 100) {
	    ++depthnri[idepi + 4];
	}
	if (idepi >= 100) {
	    ++mge5i;
	}
	idepl = i_nint(&event_1.e[(i__ << 2) - 1]);
	if (idepl < 100) {
	    ++depthnrl[idepl + 4];
	}
	if (idepl >= 100) {
	    ++mge5l;
	}
    }
    s_copy(cstari, ".........1.........2.........3.........4.........5>", (
	    ftnlen)51, (ftnlen)51);
    s_copy(cstarl, "*********1*********2*********3*********4*********5>", (
	    ftnlen)51, (ftnlen)51);
    for (i__ = 1; i__ <= 105; ++i__) {
	depthi = (real) (i__ - 5);
	depthl = (real) (i__ - 5);
	if (depthnri[i__ - 1] > 50) {
	    depthnri[i__ - 1] = 51;
	}
	if (depthnrl[i__ - 1] > 50) {
	    depthnrl[i__ - 1] = 51;
	}
	if (depthnri[i__ - 1] > 0) {
	    s_wsfe(&io___627);
	    do_fio(&c__1, (char *)&depthi, (ftnlen)sizeof(real));
	    do_fio(&c__1, cstari, depthnri[i__ - 1]);
	    e_wsfe();
	} else {
	    s_wsfe(&io___628);
	    do_fio(&c__1, (char *)&depthi, (ftnlen)sizeof(real));
	    do_fio(&c__1, " ", (ftnlen)1);
	    e_wsfe();
	}
	if (depthnrl[i__ - 1] > 0) {
	    s_wsfe(&io___629);
	    do_fio(&c__1, (char *)&depthl, (ftnlen)sizeof(real));
	    do_fio(&c__1, cstarl, depthnrl[i__ - 1]);
	    e_wsfe();
	} else {
	    s_wsfe(&io___630);
	    do_fio(&c__1, (char *)&depthl, (ftnlen)sizeof(real));
	    do_fio(&c__1, " ", (ftnlen)1);
	    e_wsfe();
	}
/* c         write(16,*) */
    }
    if (mge5i > 50) {
	mge5i = 51;
    }
    if (mge5l > 50) {
	mge5l = 51;
    }
    if (mge5i > 0) {
	s_wsfe(&io___631);
	do_fio(&c__1, cstari, mge5i);
	e_wsfe();
    } else {
	s_wsfe(&io___632);
	do_fio(&c__1, " ", (ftnlen)1);
	e_wsfe();
    }
    if (mge5l > 0) {
	s_wsfe(&io___633);
	do_fio(&c__1, cstarl, mge5l);
	e_wsfe();
    } else {
	s_wsfe(&io___634);
	do_fio(&c__1, " ", (ftnlen)1);
	e_wsfe();
    }
    s_wsle(&io___635);
    e_wsle();
    s_wsle(&io___636);
    e_wsle();

    s_wsle(&io___637);
    do_lio(&c__9, &c__1, "Residuals of the stations according to the azimuth:"
	    , (ftnlen)51);
    e_wsle();
    s_wsle(&io___638);
    do_lio(&c__9, &c__1, "(RES  = total average residual at station)", (
	    ftnlen)42);
    e_wsle();
    s_wsle(&io___639);
    do_lio(&c__9, &c__1, "(RES1 = average residual of rays from 1st quadrant)"
	    , (ftnlen)51);
    e_wsle();
    s_wsle(&io___640);
    do_lio(&c__9, &c__1, "(RES2 = average residual of rays from 2nd quadrant)"
	    , (ftnlen)51);
    e_wsle();
    s_wsle(&io___641);
    do_lio(&c__9, &c__1, "(RES3 = average residual of rays from 3rd quadrant)"
	    , (ftnlen)51);
    e_wsle();
    s_wsle(&io___642);
    do_lio(&c__9, &c__1, "(RES4 = average residual of rays from 4th quadrant)"
	    , (ftnlen)51);
    e_wsle();
    s_wsle(&io___643);
    e_wsle();
    s_wsfe(&io___644);
    e_wsfe();
    i__1 = dimen_1.nsta;
    for (i__ = 1; i__ <= i__1; ++i__) {
	res0 = 0.f;
	res1 = 0.f;
	res2 = 0.f;
	res3 = 0.f;
	res4 = 0.f;
	if (residuals_1.stnazires[i__ + 649] > 0.f) {
	    res1 = residuals_1.stnazires[i__ - 1] / residuals_1.stnazires[i__ 
		    + 649];
	}
	if (residuals_1.stnazires[i__ + 1949] > 0.f) {
	    res2 = residuals_1.stnazires[i__ + 1299] / residuals_1.stnazires[
		    i__ + 1949];
	}
	if (residuals_1.stnazires[i__ + 3249] > 0.f) {
	    res3 = residuals_1.stnazires[i__ + 2599] / residuals_1.stnazires[
		    i__ + 3249];
	}
	if (residuals_1.stnazires[i__ + 4549] > 0.f) {
	    res4 = residuals_1.stnazires[i__ + 3899] / residuals_1.stnazires[
		    i__ + 4549];
	}
	tot = residuals_1.stnazires[i__ + 649] + residuals_1.stnazires[i__ + 
		1949] + residuals_1.stnazires[i__ + 3249] + 
		residuals_1.stnazires[i__ + 4549];
	if (tot > 0.f) {
	    res0 = (residuals_1.stnazires[i__ + 649] * res1 + 
		    residuals_1.stnazires[i__ + 1949] * res2 + 
		    residuals_1.stnazires[i__ + 3249] * res3 + 
		    residuals_1.stnazires[i__ + 4549] * res4) / tot;
	}
	if (tot > 0.f) {
	    ntot = i_nint(&tot);
	    i1 = i_nint(&residuals_1.stnazires[i__ + 649]);
	    i2 = i_nint(&residuals_1.stnazires[i__ + 1949]);
	    i3 = i_nint(&residuals_1.stnazires[i__ + 3249]);
	    i4 = i_nint(&residuals_1.stnazires[i__ + 4549]);
	    s_wsfe(&io___656);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, charc_1.stn + (i__ - 1 << 2), (ftnlen)4);
	    do_fio(&c__1, (char *)&res0, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&ntot, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&res1, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&res2, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&i2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&res3, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&i3, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&res4, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&i4, (ftnlen)sizeof(integer));
	    e_wsfe();
	} else {
	    s_wsfe(&io___657);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, charc_1.stn + (i__ - 1 << 2), (ftnlen)4);
	    e_wsfe();
	}
    }
    s_wsle(&io___658);
    e_wsle();
    s_wsle(&io___659);
    e_wsle();

    return 0;
} /* statisticsout_ */


/* of subr. statisticsout */
/* Subroutine */ int statislout_(void)
{
    /* Initialized data */

    static char class__[1*4] = "A" "B" "C" "D";

    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), e_wsfe(void);
    double sqrt(doublereal);
    integer i_nint(real *), do_fio(integer *, char *, ftnlen);
    double atan2(doublereal, doublereal), r_mod(real *, real *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), e_wsfi(void), s_cmp(char *, char *, ftnlen, 
	    ftnlen);

    /* Local variables */
    static integer i__, k;
    static char q[1];
    static integer jd, in, kk;
    static char qd[1];
    static integer js, no;
    static char qs[1];
    static real aar, ofd, sec;
    extern /* Subroutine */ int sdc_(real *, real *, real *, real *, integer *
	    );
    static real tfd, erh;
    static integer jav;
    static real erx, ery, erz, azi;
    static integer nin;
    static char cns[1], cew[1], card[90];
    static real xlat, xlon, tobs;
    static integer iazi, iamx;
    static char clay[1];
    static real xhyp, yhyp, xstn, ystn;
    static char char1[1];
    static integer idmin;
    static char ctime[20];
    extern /* Subroutine */ int geoko_(real *, real *, real *, real *, 
	    integer *);
    static real tcorr;
    static integer knobs1, iprisecondcard;
    static real studres;

    /* Fortran I/O blocks */
    static cilist io___661 = { 0, 16, 0, 0, 0 };
    static cilist io___662 = { 0, 16, 0, 0, 0 };
    static cilist io___663 = { 0, 6, 0, 0, 0 };
    static cilist io___664 = { 0, 6, 0, 0, 0 };
    static cilist io___665 = { 0, 2, 0, "(' ERROR: insufficient data to loca"
	    "te the quake!')", 0 };
    static cilist io___666 = { 0, 2, 0, "('0 DATE  ORIGIN   TIME   LAT      "
	    "LON     DEPTH ',              ' MAG  NO  DM GAP  RMS   ALE D-SPR"
	    "')", 0 };
    static cilist io___667 = { 0, 2, 0, "('0 DATE  ORIGIN TIME   LAT       L"
	    "ON     *DEPTH*',              ' MAG  NO  DM GAP  RMS   ALE D-SPR"
	    "')", 0 };
    static cilist io___668 = { 0, 2, 0, "('0 DATE  ORIGIN TIME  *LAT*     *L"
	    "ON*    *DEPTH*',              ' MAG  NO  DM GAP  RMS   ALE D-SPR"
	    "')", 0 };
    static cilist io___678 = { 0, 2, 0, "(1x,3i2.2,1x,i2,':',i2,':',f6.3,1x "
	    "                            f7.4,a1,f8.4,a1,1x,f7.3,2x,         "
	    "                              f3.1,2x,i2,1x,i3,1x,i3,f5.2,f6.2, "
	    "                                1x,f5.2)", 0 };
    static cilist io___679 = { 0, 2, 0, "('0  ERX  ERY  ERZ Q SQD  ADJ  IN N"
	    "R  ',                         'AVR   AAR  NM AVXM  SDXM IT')", 0 }
	    ;
    static cilist io___696 = { 0, 2, 0, "(1x,f5.1,f5.1,f5.1,1x,a1,1x,a1,'/',"
	    "a1,f6.2,1x,                   i2,i3,2f6.2,                      "
	    "                                i3,2x,f3.1,2x,f3.1,1x,i3)", 0 };
    static cilist io___697 = { 0, 2, 0, "('0 L+T NR:',i4,1x,a32,'CH-COORD.:'"
	    ",                  f9.3,' /',f9.3, ' KM')", 0 };
    static cilist io___698 = { 0, 2, 0, "('0 F-E NR:',i4,1x,a32,'CH-COORD.:'"
	    ",                  f9.3,' /',f9.3, ' KM')", 0 };
    static cilist io___699 = { 0, 2, 0, "('0 F-E NR:',i4,1x,a32)", 0 };
    static cilist io___700 = { 0, 2, 0, "('0 STN  DIST AZM AIN PRMK HRMN  P-"
	    "SEC  TPOBS  TPCAL ',          ' -TSCOR  P-RES   P-WT IMP STURES')"
	    , 0 };
    static cilist io___701 = { 0, 2, 0, "('        AMX PRX     SRMK XMAG  S-"
	    "SEC  TSOBS  TSCAL ',          ' -TSCOR  S-RES   S-WT IMP STURES')"
	    , 0 };
    static icilist io___716 = { 0, card, 0, "(2X,A4,1x,2i4,I4,1X,3A1,I1,a1,2"
	    "I2,3F7.3,F7.3,1x,                   f7.3,1x,f6.2,1x,f6.4,f7.3)", 
	    90, 1 };
    static icilist io___717 = { 0, card+15, 0, "(i4)", 4, 1 };
    static cilist io___718 = { 0, 2, 0, "(a)", 0 };
    static cilist io___719 = { 0, 2, 0, "(a)", 0 };
    static icilist io___721 = { 0, card, 0, "(2x,4x,i5,f4.1)", 15, 1 };
    static icilist io___722 = { 0, card+25, 0, "(f3.1)", 3, 1 };
    static icilist io___723 = { 0, card+2, 0, "(a4)", 4, 1 };
    static icilist io___724 = { 0, card+20, 0, "(3a1,i1,a1)", 5, 1 };
    static icilist io___725 = { 0, card+29, 0, "(3F7.3,F7.3,1x,f7.3,1x,F6.2,"
	    "1x,f6.4,                               f7.3)", 61, 1 };
    static cilist io___726 = { 0, 2, 0, "(a)", 0 };
    static cilist io___727 = { 0, 2, 0, "('  $$$ ',2x,'VELEST-Version ETH-11"
	    "FEB92',                     ' located at: ',a20)", 0 };
    static cilist io___729 = { 0, 2, 0, 0, 0 };
    static cilist io___730 = { 0, 2, 0, 0, 0 };



/*     print location-output in file *.VEL , compatible for program STATISL */

/* ek     implemented print output of studentized residuals (studres) */
/* ek  29.3.95 implemented print output of station name for all phases */
/*             (incl. S) */

/*       principally studentized res = residual/(sigma * sqrt(1.-diagofhat)) */

/*       here we print out studres= residual/sqrt(1.-diag of hat matrix) */
/* ek  281093 */


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


    if (obb_1.knobs[0] - obb_1.nobswithw0 < dimen_1.nvar && form_1.iabort == 
	    0) {
	form_1.iabort = 1;
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___661);
	    do_lio(&c__9, &c__1, "knobs(i)-nobswithw0 < nvar !!!", (ftnlen)30)
		    ;
	    e_wsle();
	    s_wsle(&io___662);
	    do_lio(&c__9, &c__1, "Event cannot be located!!!", (ftnlen)26);
	    e_wsle();
	}
	s_wsle(&io___663);
	do_lio(&c__9, &c__1, "knobs(i)-nobswithw0 < nvar !!!", (ftnlen)30);
	e_wsle();
	s_wsle(&io___664);
	do_lio(&c__9, &c__1, "Event cannot be located!!!", (ftnlen)26);
	e_wsle();
    }
    if (form_1.iabort == 1) {
	s_wsfe(&io___665);
	e_wsfe();
	return 0;
    }

    if (param_1.ifixsolution == 0) {
	s_wsfe(&io___666);
	e_wsfe();
    }
    if (param_1.ifixsolution == 1) {
	s_wsfe(&io___667);
	e_wsfe();
    }
    if (param_1.ifixsolution == 9) {
	s_wsfe(&io___668);
	e_wsfe();
    }

    sec = event_1.e[0];
    nin = event_1.imin[0];
    if (sec < 0.f) {
	sec += 60.f;
	--nin;
    }
    if (sec > 60.f) {
	sec += -60.f;
	++nin;
    }
    if (nin < 0) {
/*  U.K. 3.Feb.87 */
	nin += 60;
	--event_1.ihr[0];
    }

/*     convert hypocenter into degrees: */

    if (coordsyst_1.icoordsystem == 2) {
	r__1 = -event_1.e[1];
	geoko_(&r__1, &event_1.e[2], &xlat, &xlon, &c__1);
/* calc. LAT/LON */
	xlon = -xlon;
    } else {
	sdc_(&event_1.e[1], &event_1.e[2], &xlat, &xlon, &c__1);
/* calc. LAT/LON */
    }
    if (xlat < 0.f) {
	*(unsigned char *)cns = 'S';
	xlat = -xlat;
    } else {
	*(unsigned char *)cns = 'N';
    }
    if (xlon < 0.f) {
	*(unsigned char *)cew = 'E';
	xlon = -xlon;
    } else {
	*(unsigned char *)cew = 'W';
    }

    idmin = 999;
/* minimum distance (epicenter --> receiver) */
    aar = 0.f;
/* absolute average weighted residual */
    i__1 = obb_1.knobs[0];
    for (k = 1; k <= i__1; ++k) {
/* Computing 2nd power */
	r__1 = event_1.e[1] - statn_1.d__[k - 1];
/* Computing 2nd power */
	r__2 = event_1.e[2] - statn_1.d__[k + 649];
	layer_1.delta = sqrt(r__1 * r__1 + r__2 * r__2);
	obb_1.idelta[k - 1] = i_nint(&layer_1.delta);
	if (obb_1.w[k - 1] > 0.f) {
	    if (obb_1.idelta[k - 1] < idmin) {
		idmin = obb_1.idelta[k - 1];
	    }
	    aar += (r__1 = a4_1.res[k - 1], dabs(r__1)) * obb_1.w[k - 1];
	}
    }
    aar /= obb_1.knobs[0] - obb_1.nobswithw0;

/* write first line of summary card: */

    s_wsfe(&io___678);
    do_fio(&c__1, (char *)&event_1.iyr[0], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&event_1.imo[0], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&event_1.iday[0], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&event_1.ihr[0], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nin, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&sec, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&xlat, (ftnlen)sizeof(real));
    do_fio(&c__1, cns, (ftnlen)1);
    do_fio(&c__1, (char *)&xlon, (ftnlen)sizeof(real));
    do_fio(&c__1, cew, (ftnlen)1);
    do_fio(&c__1, (char *)&event_1.e[3], (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&event_1.emag[0], (ftnlen)sizeof(real));
    i__1 = obb_1.knobs[0] - obb_1.nobswithw0;
    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&idmin, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&gap_1.igap[0], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a4_1.rms[0], (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&goodness_1.ale[0], (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&quality_1.spread, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsfe(&io___679);
    e_wsfe();

/*     standard deviations : */
/*     (square-root of diagonalelements of UNIT covariance matrix */

/* Computing 2nd power */
    r__1 = a4_1.s[1];
/* Computing 2nd power */
    r__2 = a4_1.s[2];
    erh = sqrt(r__1 * r__1 + r__2 * r__2);
    erx = a4_1.s[1];
    ery = a4_1.s[2];
    erz = a4_1.s[3];
    js = 4;
    if (a4_1.rms[0] < 1.f && erh <= 15.f) {
	js = 3;
    }
    if (a4_1.rms[0] < .6f && erh <= 8.f && erz <= 15.f) {
	js = 2;
    }
    if (a4_1.rms[0] < .3f && erh <= 2.f && erz <= 6.f) {
	js = 1;
    }
    jd = 4;
    no = obb_1.knobs[0] - obb_1.nobswithw0;
    ofd = event_1.e[3];
/* focal depth */
    tfd = event_1.e[3] * 2.f;
    if (ofd < 10.f) {
	ofd = 10.f;
    }
    if (tfd < 30.f) {
	tfd = 30.f;
    }
    if (gap_1.igap[0] <= 180 || no >= 4 && idmin <= 100) {
	jd = 3;
    }
    if (gap_1.igap[0] <= 135 || no >= 5 && (real) idmin <= tfd) {
	jd = 2;
    }
    if (gap_1.igap[0] <= 90 || no >= 6 && (real) idmin <= ofd) {
	jd = 1;
    }
    jav = (js + jd + 1) / 2;
    *(unsigned char *)q = *(unsigned char *)&class__[jav - 1];
    *(unsigned char *)qs = *(unsigned char *)&class__[js - 1];
    *(unsigned char *)qd = *(unsigned char *)&class__[jd - 1];
    knobs1 = 0;
    i__1 = obb_1.knobs[0];
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (obb_1.kpwt[i__ - 1] >= 5) {
	    ++knobs1;
	}
    }
    knobs1 = obb_1.knobs[0] - knobs1;
/* # of obs with weight less 5 !!! */
    in = 0;

/* write second line of summary card */

    s_wsfe(&io___696);
    do_fio(&c__1, (char *)&erx, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&ery, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&erz, (ftnlen)sizeof(real));
    do_fio(&c__1, q, (ftnlen)1);
    do_fio(&c__1, qs, (ftnlen)1);
    do_fio(&c__1, qd, (ftnlen)1);
    do_fio(&c__1, (char *)&a4_1.steplen, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&in, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&knobs1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a4_1.avres[0], (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&aar, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&event_1.nmag, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&event_1.xmagnitude, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&event_1.sdxmagnitude, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
    e_wsfe();
    if (coordsyst_1.icoordsystem == 2) {
	if (event_1.nreg >= 1000) {
	    s_wsfe(&io___697);
	    do_fio(&c__1, (char *)&event_1.nreg, (ftnlen)sizeof(integer));
	    do_fio(&c__1, event_1.regionname, (ftnlen)32);
	    r__1 = -event_1.e[1];
	    do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&event_1.e[2], (ftnlen)sizeof(real));
	    e_wsfe();
	} else {
	    s_wsfe(&io___698);
	    do_fio(&c__1, (char *)&event_1.nreg, (ftnlen)sizeof(integer));
	    do_fio(&c__1, event_1.regionname, (ftnlen)32);
	    r__1 = -event_1.e[1];
	    do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&event_1.e[2], (ftnlen)sizeof(real));
	    e_wsfe();
	}
    } else {
	s_wsfe(&io___699);
	do_fio(&c__1, (char *)&event_1.nreg, (ftnlen)sizeof(integer));
	do_fio(&c__1, event_1.regionname, (ftnlen)32);
	e_wsfe();
    }
    s_wsfe(&io___700);
    e_wsfe();
    s_wsfe(&io___701);
    e_wsfe();

    k = 0;

/*  DO LOOP for EACH OBSERVATION */

    i__1 = obb_1.knobs[0];
    for (kk = 1; kk <= i__1; ++kk) {
	++k;

/*     station# are stored in array  ISTM(iobs,ievent) */
/*     stn(stn#)   is the station-name (a4) */
/*     smn(iobs,iev)  is the station-name */
/*     sphase(nobs,iev) : 0 for P, 1 for S, -1 for reflected P (M-phase) */
/*     and 2 for an s-p phase */

	*(unsigned char *)clay = ' ';
	if (obb_1.sphase[k - 1] == 0.f) {
	    *(unsigned char *)char1 = 'P';
	}
	if (obb_1.sphase[k - 1] == 1.f) {
	    *(unsigned char *)char1 = 'S';
	}
	if (obb_1.sphase[k - 1] == 2.f) {
	    *(unsigned char *)char1 = '-';
	}
	if (obb_1.sphase[k - 1] == -1.f) {
	    *(unsigned char *)char1 = 'P';
	    *(unsigned char *)clay = 'M';
	}
/*        Azimuth (stn --> hypoc) = 57.296*ATAN2(xhyp-xstn,yhyp-ystn) */
	xstn = statn_1.d__[k - 1];
	ystn = statn_1.d__[k + 649];
	xhyp = event_1.e[1];
	yhyp = event_1.e[2];
	azi = atan2(xhyp - xstn, yhyp - ystn) * 57.296f;
	if (azi < 0.f) {
	    azi += 360.f;
	}
/*        Azimuth (hypoc --> stn) = Azimuth (stn --> hypoc) + 180 deg */
	azi += 180.f;
	azi = r_mod(&azi, &c_b1794);
	iazi = i_nint(&azi);

	tobs = obb_1.pt[k - 1] - event_1.e[0];
/* ek */
/* ek correct time for minuite change as previously done for origin time */
/* ek (see above) */
/* ek this correction added by ek 2.May1996 */

/*  P observed travel time */
	if (tobs < 0.f) {
	    obb_1.pt[k - 1] += 60.f;
	}
	if (tobs > 60.f) {
	    obb_1.pt[k - 1] += -60.f;
	}

	tobs = obb_1.pt[k - 1] - event_1.e[0];

/*  P observed travel time */
	if (obb_1.tcalc[k - 1] < 0.f) {
	    obb_1.tcalc[k - 1] += 60.f;
	}
	if (obb_1.tcalc[k - 1] > 60.f) {
	    obb_1.tcalc[k - 1] += -60.f;
	}

/* station corrections: */
	tcorr = statn_1.ptcor[obb_1.istm[k - 1] - 1];
	if (modela_1.nsp == 2 && obb_1.sphase[k - 1] == 1.f) {
	    tcorr = statn_1.stcor[obb_1.istm[k - 1] - 1];
	}
	if (modela_1.nsp == 3 && obb_1.sphase[k - 1] == 1.f) {
	    tcorr *= layvel_1.vpvs;
	}
	if (obb_1.sphase[k - 1] == 2.f) {
	    tcorr = 0.f;
	}

	s_copy(card, " ", (ftnlen)90, (ftnlen)1);
	studres = a4_1.res[k - 1] / sqrt(1.f - dataresol_1.drm[k + k * 180 - 
		181]);
	if (studres > 999.f) {
	    studres = 999.999f;
	}

/* ek print P card (or S-card if no P obs for this station available */

	iprisecondcard = 0;
	s_wsfi(&io___716);
	do_fio(&c__1, charc_1.smn + (k - 1 << 2), (ftnlen)4);
	do_fio(&c__1, (char *)&obb_1.idelta[k - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&iazi, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&obb_1.iain[k - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, obb_1.prmk + (k - 1), (ftnlen)1);
	do_fio(&c__1, char1, (ftnlen)1);
	do_fio(&c__1, obb_1.prmk + (k + 649), (ftnlen)1);
	do_fio(&c__1, (char *)&obb_1.kpwt[k - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, clay, (ftnlen)1);
	do_fio(&c__1, (char *)&event_1.ihr[0], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nin, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&obb_1.pt[k - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&tobs, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&obb_1.tcalc[k - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&tcorr, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&a4_1.res[k - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&obb_1.w[k - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&dataresol_1.drm[k + k * 180 - 181], (ftnlen)
		sizeof(real));
	do_fio(&c__1, (char *)&studres, (ftnlen)sizeof(real));
	e_wsfi();
/* ek      if(w(k,1).eq.0.0) write(card(61:61),'(''*'')') */
	if (obb_1.kpwt[k - 1] == 5) {
	    s_copy(card + 20, " ", (ftnlen)60, (ftnlen)1);
/* there is no P arrival! */
	    if (k < obb_1.knobs[0]) {
		if (s_cmp(charc_1.smn + (k << 2), charc_1.smn + (k - 1 << 2), 
			(ftnlen)4, (ftnlen)4) == 0) {
		    s_wsfi(&io___717);
		    do_fio(&c__1, (char *)&obb_1.iain[k], (ftnlen)sizeof(
			    integer));
		    e_wsfi();
/* angle of next phas */
		    s_wsfe(&io___718);
		    do_fio(&c__1, card, (ftnlen)90);
		    e_wsfe();
/* next card will be an S */
		}
	    } else {
		goto L99;
	    }
	} else {
	    s_wsfe(&io___719);
	    do_fio(&c__1, card, (ftnlen)90);
	    e_wsfe();
	}
	iamx = i_nint(&obb_1.amx[k - 1]);
	s_copy(card, " ", (ftnlen)90, (ftnlen)1);
	if (event_1.xmagni[k - 1] != -13.f) {
/* a magnitude was calculated for this o */
	    s_wsfi(&io___721);
	    do_fio(&c__1, (char *)&iamx, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&obb_1.prx[k - 1], (ftnlen)sizeof(real));
	    e_wsfi();
	    s_wsfi(&io___722);
	    do_fio(&c__1, (char *)&event_1.xmagni[k - 1], (ftnlen)sizeof(real)
		    );
	    e_wsfi();
	}
	if (k < obb_1.knobs[0]) {
/* hrm?   Must anything changed here for s-p phases? */

/*  NOW  PRINT  S-PHASE */

	    if (s_cmp(charc_1.smn + (k << 2), charc_1.smn + (k - 1 << 2), (
		    ftnlen)4, (ftnlen)4) == 0) {
		if (obb_1.sphase[k] == 1.f) {
		    iprisecondcard = 1;
		    ++k;

		    *(unsigned char *)char1 = 'S';
		    *(unsigned char *)clay = ' ';
		    tobs = obb_1.pt[k - 1] - event_1.e[0];
/* ek */
/* ek correct time for minuite change as previously done for origin time */
/* ek (see above) */
/* ek this correction added by ek 2.May1996 */

		    if (tobs < 0.f) {
			obb_1.pt[k - 1] += 60.f;
		    }
		    if (tobs > 60.f) {
			obb_1.pt[k - 1] += -60.f;
		    }

		    tobs = obb_1.pt[k - 1] - event_1.e[0];

/*  S observed travel time */
		    if (obb_1.tcalc[k - 1] < 0.f) {
			obb_1.tcalc[k - 1] += 60.f;
		    }
		    if (obb_1.tcalc[k - 1] > 60.f) {
			obb_1.tcalc[k - 1] += -60.f;
		    }

		    tcorr = statn_1.ptcor[obb_1.istm[k - 1] - 1];
		    if (modela_1.nsp == 2 && obb_1.sphase[k - 1] == 1.f) {
			tcorr = statn_1.stcor[obb_1.istm[k - 1] - 1];
		    }
		    if (modela_1.nsp == 3 && obb_1.sphase[k - 1] == 1.f) {
			tcorr *= layvel_1.vpvs;
		    }
/* ek       NOW write a following card (second phase) for same station */
/* ek  29.3.95 */
		    s_wsfi(&io___723);
		    do_fio(&c__1, charc_1.smn + (k - 2 << 2), (ftnlen)4);
		    e_wsfi();
/* write station name for */
		    s_wsfi(&io___724);
		    do_fio(&c__1, obb_1.prmk + (k - 1), (ftnlen)1);
		    do_fio(&c__1, char1, (ftnlen)1);
		    do_fio(&c__1, obb_1.prmk + (k + 649), (ftnlen)1);
		    do_fio(&c__1, (char *)&obb_1.kpwt[k - 1], (ftnlen)sizeof(
			    integer));
		    do_fio(&c__1, clay, (ftnlen)1);
		    e_wsfi();
		    studres = a4_1.res[k - 1] / sqrt(1.f - dataresol_1.drm[k 
			    + k * 180 - 181]);
		    if (studres > 999.f) {
			studres = 999.999f;
		    }
		    s_wsfi(&io___725);
		    do_fio(&c__1, (char *)&obb_1.pt[k - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&c__1, (char *)&tobs, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&obb_1.tcalc[k - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&c__1, (char *)&tcorr, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&a4_1.res[k - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&c__1, (char *)&obb_1.w[k - 1], (ftnlen)sizeof(
			    real));
		    do_fio(&c__1, (char *)&dataresol_1.drm[k + k * 180 - 181],
			     (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&studres, (ftnlen)sizeof(real));
		    e_wsfi();
/* ek              if(w(k,1).eq.0.0) write(card(61:61),'(''*'')') */
		}
	    }
	}
/* ek next statements may95 */
	if (iprisecondcard == 1) {
	    s_wsfe(&io___726);
	    do_fio(&c__1, card, (ftnlen)90);
	    e_wsfe();
	}
/* ek      if(kpwt(k,1).lt.5) write(2,'(a)') card */
/* L2022: */
	if (k == obb_1.knobs[0]) {
	    goto L99;
	}
    }

L99:
/*     call DATETIMEX(ctime)  ! get date&time from system */
    s_wsfe(&io___727);
    do_fio(&c__1, ctime, (ftnlen)20);
    e_wsfe();
    s_wsle(&io___729);
    e_wsle();
    s_wsle(&io___730);
    e_wsle();

    return 0;
} /* statislout_ */


/* of subr. statislout */
/* Subroutine */ int nittoutput_(real *damp)
{
    /* Format strings */
    static char fmt_37[] = "(1x,i4,3x,6f7.2,2x,4f7.3)";
    static char fmt_124[] = "(/,\002 Step length damping of \002,f7.5,\002 w"
	    "as applied.\002,/)";
    static char fmt_40[] = "(\002 Velocity adjustments:\002)";
    static char fmt_41[] = "(5x,\002vp    dvp      hp   reflector\002)";
    static char fmt_71[] = "(1x,\002Velocity model\002,i4)";
    static char fmt_63[] = "(1x,2f7.3,2x,f7.3,5x,a1)";
    static char fmt_48[] = "(2x,\002 stn  ptcor  dpcor  \002)";
    static char fmt_50[] = "(4(2x,a4,2f7.3))";
    static char fmt_73[] = "(2x,\002 stn  stcor  dscor  \002)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;

    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), e_wsfe(void), 
	    do_lio(integer *, integer *, char *, ftnlen), do_fio(integer *, 
	    char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, j2, j1, k2, k1;
    static real cc[650];
    static integer j11, j22, kj, kk1, ifl, jjj;
    static real avdt, avdx, avdy, avdz;
    static integer ksta1, ksta2;
    static real aavdt, aavdx, aavdy, aavdz, avelo;
    static char reflch[1];

    /* Fortran I/O blocks */
    static cilist io___739 = { 0, 16, 0, 0, 0 };
    static cilist io___740 = { 0, 16, 0, "(4h  eq, 7x, 2hot, 5x, 1hx, 6x, 1h"
	    "y, 6x, 1hz, 6x,3hrms,            4x,5havres,'   dot     dx     d"
	    "y     dz' )", 0 };
    static cilist io___742 = { 0, 16, 0, 0, 0 };
    static cilist io___743 = { 0, 16, 0, 0, 0 };
    static cilist io___744 = { 0, 16, 0, 0, 0 };
    static cilist io___745 = { 0, 16, 0, "(' ***** depth constrained for eve"
	    "nt ',i5)", 0 };
    static cilist io___748 = { 0, 16, 0, fmt_37, 0 };
    static cilist io___750 = { 0, 16, 0, fmt_37, 0 };
    static cilist io___751 = { 0, 16, 0, 0, 0 };
    static cilist io___752 = { 0, 16, 0, "(' A V E R A G E   of ADJUSTMENTS "
	    ":',19x,4f7.3)", 0 };
    static cilist io___753 = { 0, 16, 0, "(' A V E R A G E   of ABSOLUTE ADJ"
	    "USTMENTS :',10x,               4f7.3)", 0 };
    static cilist io___754 = { 0, 16, 0, 0, 0 };
    static cilist io___755 = { 0, 16, 0, fmt_124, 0 };
    static cilist io___756 = { 0, 16, 0, "(/,'NO step length damping applied"
	    "',/)", 0 };
    static cilist io___758 = { 0, 16, 0, 0, 0 };
    static cilist io___759 = { 0, 16, 0, fmt_40, 0 };
    static cilist io___760 = { 0, 16, 0, fmt_41, 0 };
    static cilist io___761 = { 0, 16, 0, fmt_71, 0 };
    static cilist io___768 = { 0, 16, 0, fmt_63, 0 };
    static cilist io___770 = { 0, 16, 0, 0, 0 };
    static cilist io___771 = { 0, 16, 0, 0, 0 };
    static cilist io___773 = { 0, 16, 0, "(' z =',f6.2,' ...',f6.2,'    v = "
	    "',f4.2,                   '    AVEL = ',f4.2,' downto z = ',f6.2)"
	    , 0 };
    static cilist io___774 = { 0, 16, 0, 0, 0 };
    static cilist io___775 = { 0, 16, 0, 0, 0 };
    static cilist io___776 = { 0, 16, 0, 0, 0 };
    static cilist io___777 = { 0, 16, 0, "(' z =',f6.2,' ...',f6.2,'    v = "
	    "',f4.2,                   '    AVEL = ',f4.2,' downto z = ',f6.2)"
	    , 0 };
    static cilist io___778 = { 0, 16, 0, 0, 0 };
    static cilist io___779 = { 0, 16, 0, 0, 0 };
    static cilist io___780 = { 0, 16, 0, 0, 0 };
    static cilist io___781 = { 0, 16, 0, "(' Adjusted station corrections:')",
	     0 };
    static cilist io___782 = { 0, 16, 0, fmt_48, 0 };
    static cilist io___787 = { 0, 16, 0, fmt_50, 0 };
    static cilist io___788 = { 0, 16, 0, "(' Adjusted station corrections:')",
	     0 };
    static cilist io___789 = { 0, 16, 0, fmt_73, 0 };
    static cilist io___791 = { 0, 16, 0, fmt_50, 0 };
    static cilist io___792 = { 0, 16, 0, 0, 0 };



/*     output the results of iteration NITT: */


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

/*     output hypocenters of this iteration: */

    avdt = 0.f;
    avdx = 0.f;
    avdy = 0.f;
    avdz = 0.f;
    aavdt = 0.f;
    aavdx = 0.f;
    aavdy = 0.f;
    aavdz = 0.f;
    s_wsle(&io___739);
    e_wsle();
    s_wsfe(&io___740);
    e_wsfe();

    i__1 = dimen_1.legs;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*     print constrain-info if necessary: */

	if (coordsyst_1.isingle != 0) {
	    if (event_1.isconstrain[0] == 1) {
		s_wsle(&io___742);
		do_lio(&c__9, &c__1, " *** nitt<2 --> ", (ftnlen)16);
		do_lio(&c__9, &c__1, "depth-adjustment := 0.0 for event ", (
			ftnlen)34);
		do_lio(&c__3, &c__1, (char *)&i__, (ftnlen)sizeof(integer));
		e_wsle();
	    }
	    if (event_1.isconstrain[1] == 1) {
		s_wsle(&io___743);
		do_lio(&c__9, &c__1, " *** igap>250 --> ", (ftnlen)18);
		do_lio(&c__9, &c__1, "depth-adjustment := 0.0 for event ", (
			ftnlen)34);
		do_lio(&c__3, &c__1, (char *)&i__, (ftnlen)sizeof(integer));
		e_wsle();
	    }
	    if (event_1.isconstrain[2] == 1) {
		s_wsle(&io___744);
		do_lio(&c__9, &c__1, " *** depth-adjustment constrained for "
			"event ", (ftnlen)44);
		do_lio(&c__3, &c__1, (char *)&i__, (ftnlen)sizeof(integer));
		e_wsle();
	    }
	}
	if (event_1.iconstrain[i__ - 1] == 1) {
	    s_wsfe(&io___745);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
	}

/*   output new hypocenter-results got in this iteration: */

	j2 = i__ << 2;
	j1 = j2 - 3;
	if (i__ > dimen_1.neqs) {
/* for shots */
	    j1 = dimen_1.neqs * 3 + i__;
	    j2 = j1;
	}
	if (coordsyst_1.icoordsystem == 2) {
	    s_wsfe(&io___748);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&event_1.e[(i__ << 2) - 4], (ftnlen)sizeof(
		    real));
	    r__1 = -event_1.e[(i__ << 2) - 3];
	    do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	    for (j = 3; j <= 4; ++j) {
		do_fio(&c__1, (char *)&event_1.e[j + (i__ << 2) - 5], (ftnlen)
			sizeof(real));
	    }
	    do_fio(&c__1, (char *)&a4_1.rms[i__ - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&a4_1.avres[i__ - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&a4_1.b[j1 - 1], (ftnlen)sizeof(real));
	    r__2 = -a4_1.b[j1];
	    do_fio(&c__1, (char *)&r__2, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&a4_1.b[j1 + 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&a4_1.b[j1 + 2], (ftnlen)sizeof(real));
	    e_wsfe();
/* dot  dx  dy */
	} else {
	    s_wsfe(&io___750);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    for (j = 1; j <= 4; ++j) {
		do_fio(&c__1, (char *)&event_1.e[j + (i__ << 2) - 5], (ftnlen)
			sizeof(real));
	    }
	    do_fio(&c__1, (char *)&a4_1.rms[i__ - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&a4_1.avres[i__ - 1], (ftnlen)sizeof(real));
	    i__2 = j2;
	    for (j = j1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&a4_1.b[j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* dot  dx  dy  dz */
	}
	avdt += a4_1.b[j1 - 1];
	avdx += a4_1.b[j1];
	avdy += a4_1.b[j1 + 1];
	avdz += a4_1.b[j1 + 2];
	aavdt += (r__1 = a4_1.b[j1 - 1], dabs(r__1));
	aavdx += (r__1 = a4_1.b[j1], dabs(r__1));
	aavdy += (r__1 = a4_1.b[j1 + 1], dabs(r__1));
	aavdz += (r__1 = a4_1.b[j1 + 2], dabs(r__1));

/* L29: */
    }

/* loop over all events (printout) */
    if (coordsyst_1.icoordsystem == 2) {
	avdx = -avdx;
    }
    avdt /= (real) dimen_1.legs;
    avdx /= (real) dimen_1.legs;
    avdy /= (real) dimen_1.legs;
    avdz /= (real) dimen_1.legs;
    aavdt /= (real) dimen_1.legs;
    aavdx /= (real) dimen_1.legs;
    aavdy /= (real) dimen_1.legs;
    aavdz /= (real) dimen_1.legs;
    s_wsle(&io___751);
    e_wsle();
    s_wsfe(&io___752);
    do_fio(&c__1, (char *)&avdt, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&avdx, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&avdy, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&avdz, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsfe(&io___753);
    do_fio(&c__1, (char *)&aavdt, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&aavdx, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&aavdy, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&aavdz, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsle(&io___754);
    e_wsle();

/*     all new hypocenters printed out now. */

    if (*damp != 1.f) {
	s_wsfe(&io___755);
	do_fio(&c__1, (char *)&(*damp), (ftnlen)sizeof(real));
	e_wsfe();
    } else {
	s_wsfe(&io___756);
	e_wsfe();
    }

/*     print velocity adjustments and velocity-model here: */

    if (fix1_1.scale[5] == 0.f) {
	goto L44;
    }
/* no velocity-adjustments... */
    j1 = (dimen_1.neqs << 2) + dimen_1.nshot + 1;
    j2 = j1 + modela_1.nltot - 1;
    k = 0;
    s_wsle(&io___758);
    e_wsle();
    s_wsfe(&io___759);
    e_wsfe();
    s_wsfe(&io___760);
    e_wsfe();

/*     do it for all velocity-models */

    i__1 = modela_1.nmod;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_wsfe(&io___761);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	k2 = modela_1.laysum[i__ - 1];
	j11 = j1 + k2 - 1;
	j22 = j11 + modela_1.nplay[i__ - 1] - 1;
	kj = 1;

/*        do it for all layers in this model ( = i ) */

	i__2 = j22;
	for (jjj = j11; jjj <= i__2; ++jjj) {
	    if (kj == layvel_1.ireflector) {
		*(unsigned char *)reflch = *(unsigned char *)
			layvel_1.reflchar;
	    }
	    if (kj != layvel_1.ireflector) {
		*(unsigned char *)reflch = ' ';
	    }
	    s_wsfe(&io___768);
	    do_fio(&c__1, (char *)&layvel_1.vp[i__ + (kj << 1) - 3], (ftnlen)
		    sizeof(real));
	    do_fio(&c__1, (char *)&a4_1.b[jjj - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&layvel_1.hp[i__ + (kj << 1) - 3], (ftnlen)
		    sizeof(real));
	    do_fio(&c__1, reflch, (ftnlen)1);
	    e_wsfe();
	    ++kj;
	}

/*        calculate and print average velocities of the model i : */

	ifl = 1;
	s_wsle(&io___770);
	e_wsle();
	s_wsle(&io___771);
	do_lio(&c__9, &c__1, "Calculation of average velocity starts at laye"
		"r #", (ftnlen)49);
	do_lio(&c__3, &c__1, (char *)&ifl, (ftnlen)sizeof(integer));
	e_wsle();
	avelo = 0.f;
	i__2 = modela_1.nplay[i__ - 1];
	for (kj = ifl + 1; kj <= i__2; ++kj) {
	    avelo += (layvel_1.hp[i__ + (kj << 1) - 3] - layvel_1.hp[i__ + (
		    kj - 1 << 1) - 3]) * layvel_1.vp[i__ + (kj - 1 << 1) - 3];
	    s_wsfe(&io___773);
	    do_fio(&c__1, (char *)&layvel_1.hp[i__ + (kj - 1 << 1) - 3], (
		    ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&layvel_1.hp[i__ + (kj << 1) - 3], (ftnlen)
		    sizeof(real));
	    do_fio(&c__1, (char *)&layvel_1.vp[i__ + (kj - 1 << 1) - 3], (
		    ftnlen)sizeof(real));
	    r__1 = avelo / (layvel_1.hp[i__ + (kj << 1) - 3] - layvel_1.hp[
		    i__ + (ifl << 1) - 3]);
	    do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&layvel_1.hp[i__ + (kj << 1) - 3], (ftnlen)
		    sizeof(real));
	    e_wsfe();
	}
	s_wsle(&io___774);
	e_wsle();

	ifl = 2;
	s_wsle(&io___775);
	e_wsle();
	s_wsle(&io___776);
	do_lio(&c__9, &c__1, "Calculation of average velocity starts at laye"
		"r #", (ftnlen)49);
	do_lio(&c__3, &c__1, (char *)&ifl, (ftnlen)sizeof(integer));
	e_wsle();
	avelo = 0.f;
	i__2 = modela_1.nplay[i__ - 1];
	for (kj = ifl + 1; kj <= i__2; ++kj) {
	    avelo += (layvel_1.hp[i__ + (kj << 1) - 3] - layvel_1.hp[i__ + (
		    kj - 1 << 1) - 3]) * layvel_1.vp[i__ + (kj - 1 << 1) - 3];
	    s_wsfe(&io___777);
	    do_fio(&c__1, (char *)&layvel_1.hp[i__ + (kj - 1 << 1) - 3], (
		    ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&layvel_1.hp[i__ + (kj << 1) - 3], (ftnlen)
		    sizeof(real));
	    do_fio(&c__1, (char *)&layvel_1.vp[i__ + (kj - 1 << 1) - 3], (
		    ftnlen)sizeof(real));
	    r__1 = avelo / (layvel_1.hp[i__ + (kj << 1) - 3] - layvel_1.hp[
		    i__ + (ifl << 1) - 3]);
	    do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&layvel_1.hp[i__ + (kj << 1) - 3], (ftnlen)
		    sizeof(real));
	    e_wsfe();
	}
	s_wsle(&io___778);
	e_wsle();
	s_wsle(&io___779);
	e_wsle();
    }

/*     each velocity-model and its changes printed out now. */

/*     print p- & s- station-corrections here: */

/* loop over all models */
L44:
    if (fix1_1.scale[4] == 0.f) {
	goto L72;
    }
/* no station-correction adjustments... */
    s_wsle(&io___780);
    e_wsle();
    s_wsfe(&io___781);
    e_wsfe();
    s_wsfe(&io___782);
    e_wsfe();
    k1 = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + 1;
    ksta1 = dimen_1.ksta;
    if (modela_1.nsp == 2) {
	ksta1 = dimen_1.ksta / 2;
    }
    k2 = k1 + ksta1 - 1;

/*     print p-correction for all stations: */

    i__1 = dimen_1.nsta;
    for (j = 1; j <= i__1; ++j) {
	cc[j - 1] = 0.f;
	if (statn_1.map1[j - 1] == 0) {
	    goto L49;
	}
	if (statn_1.map1[j - 1] > ksta1) {
	    goto L49;
	}
	kk1 = k1 - 1 + statn_1.map1[j - 1];
	cc[j - 1] = a4_1.b[kk1 - 1];
/* ccc         ptcor(j)=ptcor(j)+cc(j)  !  ADJUSTMENT !!! (p-correction) */
/*  STATION-CORRECTION- */
L49:
	;
    }
    s_wsfe(&io___787);
    i__1 = dimen_1.nsta;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, charc_1.stn + (j - 1 << 2), (ftnlen)4);
	do_fio(&c__1, (char *)&statn_1.ptcor[j - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&cc[j - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    if (modela_1.nsp != 2) {
	goto L72;
    }
    s_wsfe(&io___788);
    e_wsfe();
    s_wsfe(&io___789);
    e_wsfe();
    k1 = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + 1 + ksta1;
    ksta2 = dimen_1.ksta - ksta1;
    k2 = k1 + ksta2 - 1;

/*     print s-correction for all stations: */

    i__1 = dimen_1.nsta;
    for (j = 1; j <= i__1; ++j) {
	cc[j - 1] = 0.f;
	if (statn_1.map1[j - 1] == 0) {
	    goto L74;
	}
	if (statn_1.map1[j - 1] > ksta2) {
	    goto L74;
	}
	kk1 = k1 - 1 + statn_1.map1[j - 1];
	cc[j - 1] = a4_1.b[kk1 - 1];
/* cc         stcor(j)=stcor(j)+cc(j)   ! ADJUSTMENT !!! (s-correction) */
/* STATION-CORRECTION- */
L74:
	;
    }
    s_wsfe(&io___791);
    i__1 = dimen_1.nsta;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, charc_1.stn + (j - 1 << 2), (ftnlen)4);
	do_fio(&c__1, (char *)&statn_1.stcor[j - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&cc[j - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();

L72:
    s_wsle(&io___792);
    e_wsle();

    return 0;

} /* nittoutput_ */


/* of subr. nittoutput */
/* Subroutine */ int finalhypocout_(void)
{
    /* Format strings */
    static char fmt_1111[] = "(\002  date    origin   latitude longitud"
	    "e\002,\002  depth  mag  no  rms      x      y      z\002)";
    static char fmt_11[] = "(\002 \002,4x,\002 date    origin   latitude lon"
	    "gitude \002,\002 depth  mag  no  rms      x      y      z\002)";
    static char fmt_19[] = "(6(a4,a1,i1,f6.2))";

    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;

    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), e_wsfe(void), 
	    do_fio(integer *, char *, ftnlen), i_nint(real *);
    double sqrt(doublereal);
    integer s_wsfi(icilist *), e_wsfi(void);

    /* Local variables */
    static integer i__, j, aa;
    static real tt[650];
    extern /* Subroutine */ int sdc_(real *, real *, real *, real *, integer *
	    );
    static real sec;
    static char cew[1];
    static integer nin;
    static char cns[1];
    static real xxx;
    static integer mag10, dep10, sec10;
    static real dmin__, xlat, xlon, dist, xsta, ysta;
    static char phzz[1*650];
    static integer xout, yout, rms100, lat1000, lon1000, idmin;
    extern /* Subroutine */ int geoko_(real *, real *, real *, real *, 
	    integer *);
    static integer year19;
    extern /* Subroutine */ int gapcalc_(integer *);

    /* Fortran I/O blocks */
    static cilist io___793 = { 0, 16, 0, 0, 0 };
    static cilist io___794 = { 0, 16, 0, fmt_1111, 0 };
    static cilist io___795 = { 0, 6, 0, fmt_1111, 0 };
    static cilist io___796 = { 0, 16, 0, fmt_11, 0 };
    static cilist io___805 = { 0, 16, 0, "(1x,i3,1x,3i2.2,1x,2i2.2,f6.2,    "
	    "                                 1x,f7.4,a1,1x,f8.4,a1,1x       "
	    "                                   f6.2,f5.2,i4,f6.3,1x,3f7.2)", 
	    0 };
    static cilist io___807 = { 0, 6, 0, "(1x,3i2.2,1x,2i2.2,f6.2,           "
	    "                                 1x,f7.4,a1,1x,f8.4,a1,1x,      "
	    "                                   f6.2,f5.2,i4,f6.3,2f7.2,f6.2)",
	     0 };
    static icilist io___823 = { 0, a4_1.smpline, 0, "(i4,4i2.2,i3.3,i5.5,a1,"
	    "i6.6,a1,                               i3.3,i2.2,'Ml',i4.4,2i3,'"
	    "000000000SEDL',                      2i3,i4.4,i2)", 80, 1 };
    static cilist io___824 = { 0, 11, 0, "(a80)", 0 };
    static cilist io___825 = { 0, 16, 0, "(1x,'Event# ',i3,' GAP = ',i3)", 0 }
	    ;
    static cilist io___826 = { 0, 16, 0, "(1x,a32,'   L+T Nr.: ',i4)", 0 };
    static cilist io___827 = { 0, 6, 0, "(1x,a32,'   L+T Nr.: ',i4)", 0 };
    static cilist io___828 = { 0, 16, 0, "(1x,a32,'   F-E Nr.: ',i4)", 0 };
    static cilist io___829 = { 0, 6, 0, "(1x,a32,'   F-E Nr.: ',i4)", 0 };
    static cilist io___830 = { 0, 7, 0, "(3i2,1x,2i2,1x,f5.2,1x,f7.4,a1,1x,f"
	    "8.4,a1,2f7.2,                  4x,i3,5x,f5.2)", 0 };
    static cilist io___833 = { 0, 7, 0, fmt_19, 0 };
    static cilist io___834 = { 0, 7, 0, 0, 0 };
    static cilist io___835 = { 0, 16, 0, 0, 0 };



/*     output all the final hypocenters, print output simultaneous mode */
/*     and *cnv format */


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

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___793);
	e_wsle();
    }
    if (coordsyst_1.isingle != 0) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___794);
	    e_wsfe();
	}
	s_wsfe(&io___795);
	e_wsfe();
    } else {
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___796);
	    e_wsfe();
	}
    }
    i__1 = dimen_1.legs;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*     convert hypocenter into degrees: */

	if (coordsyst_1.icoordsystem == 2) {
	    r__1 = -event_1.e[(i__ << 2) - 3];
	    geoko_(&r__1, &event_1.e[(i__ << 2) - 2], &xlat, &xlon, &c__1);
/* calc. LAT/LON */
	    xlon = -xlon;
	    xxx = -event_1.e[(i__ << 2) - 3];
	} else {
	    sdc_(&event_1.e[(i__ << 2) - 3], &event_1.e[(i__ << 2) - 2], &
		    xlat, &xlon, &c__1);
/* calc. LAT/LON */
	    xxx = event_1.e[(i__ << 2) - 3];
	}
	if (xlat < 0.f) {
	    *(unsigned char *)cns = 'S';
	    xlat = -xlat;
	} else {
	    *(unsigned char *)cns = 'N';
	}
	if (xlon < 0.f) {
	    *(unsigned char *)cew = 'E';
	    xlon = -xlon;
	} else {
	    *(unsigned char *)cew = 'W';
	}

	sec = event_1.e[(i__ << 2) - 4];
	nin = event_1.imin[i__ - 1];
L23:
	if (sec < 0.f) {
	    goto L13;
	}
L15:
	if (sec < 60.f) {
	    goto L14;
	}
	sec += -60.f;
	++nin;
	goto L15;
L13:
	sec += 60.f;
	--nin;
	goto L23;
/* file016 */

/*     output summary information */

/* screen */
L14:
	if (nin < 0) {
/*  U.K. 3.Feb.87 */
	    nin += 60;
	    --event_1.ihr[i__ - 1];
	}

	gapcalc_(&i__);

	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___805);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&event_1.iyr[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.imo[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.iday[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.ihr[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&nin, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&sec, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&xlat, (ftnlen)sizeof(real));
	    do_fio(&c__1, cns, (ftnlen)1);
	    do_fio(&c__1, (char *)&xlon, (ftnlen)sizeof(real));
	    do_fio(&c__1, cew, (ftnlen)1);
	    do_fio(&c__1, (char *)&event_1.e[(i__ << 2) - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&event_1.emag[i__ - 1], (ftnlen)sizeof(real)
		    );
	    i__2 = obb_1.knobs[i__ - 1] - obb_1.nobswithw0;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&a4_1.rms[i__ - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&xxx, (ftnlen)sizeof(real));
	    for (j = 3; j <= 4; ++j) {
		do_fio(&c__1, (char *)&event_1.e[j + (i__ << 2) - 5], (ftnlen)
			sizeof(real));
	    }
	    e_wsfe();
	}

	if (coordsyst_1.isingle != 0) {
	    s_wsfe(&io___807);
	    do_fio(&c__1, (char *)&event_1.iyr[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.imo[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.iday[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.ihr[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&nin, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&sec, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&xlat, (ftnlen)sizeof(real));
	    do_fio(&c__1, cns, (ftnlen)1);
	    do_fio(&c__1, (char *)&xlon, (ftnlen)sizeof(real));
	    do_fio(&c__1, cew, (ftnlen)1);
	    do_fio(&c__1, (char *)&event_1.e[(i__ << 2) - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&event_1.emag[i__ - 1], (ftnlen)sizeof(real)
		    );
	    i__2 = obb_1.knobs[i__ - 1] - obb_1.nobswithw0;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&a4_1.rms[i__ - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&xxx, (ftnlen)sizeof(real));
	    for (j = 3; j <= 4; ++j) {
		do_fio(&c__1, (char *)&event_1.e[j + (i__ << 2) - 5], (ftnlen)
			sizeof(real));
	    }
	    e_wsfe();
	}

	if (outputfiles_1.ismpout == 1) {
	    year19 = event_1.iyr[i__ - 1] + 1900;
	    r__1 = sec * 10.f;
	    sec10 = i_nint(&r__1);
	    r__1 = xlat * 1e3f;
	    lat1000 = i_nint(&r__1);
	    r__1 = xlon * 1e3f;
	    lon1000 = i_nint(&r__1);
	    xout = i_nint(&xxx);
	    yout = i_nint(&event_1.e[(i__ << 2) - 2]);
	    dep10 = i_nint(&event_1.e[(i__ << 2) - 1]);
	    if ((real) dep10 < 0.f) {
		dep10 = 0.f;
	    }
	    r__1 = event_1.emag[0] * 10.f;
	    mag10 = i_nint(&r__1);
	    if ((real) mag10 < 0.f) {
		mag10 = 0.f;
	    }
	    r__1 = a4_1.rms[i__ - 1] * 100.f;
	    rms100 = i_nint(&r__1);

/*        Calculating dmin */

	    dmin__ = 9999.f;
	    i__2 = obb_1.knobs[i__ - 1];
	    for (aa = 1; aa <= i__2; ++aa) {
		if (obb_1.kpwt[i__ + aa * 650 - 651] < 4) {
		    xsta = -statn_1.x[obb_1.istm[aa + i__ * 650 - 651] - 1];
		    ysta = statn_1.x[obb_1.istm[aa + i__ * 650 - 651] + 649];
/* Computing 2nd power */
		    r__1 = xxx - xsta;
/* Computing 2nd power */
		    r__2 = event_1.e[(i__ << 2) - 2] - ysta;
		    dist = sqrt(r__1 * r__1 + r__2 * r__2);
		    if (dist < dmin__) {
			dmin__ = dist;
		    }
		}
	    }
	    idmin = i_nint(&dmin__);
	    s_wsfi(&io___823);
	    do_fio(&c__1, (char *)&year19, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&event_1.imo[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.iday[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.ihr[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&nin, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&sec10, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&lat1000, (ftnlen)sizeof(integer));
	    do_fio(&c__1, cns, (ftnlen)1);
	    do_fio(&c__1, (char *)&lon1000, (ftnlen)sizeof(integer));
	    do_fio(&c__1, cew, (ftnlen)1);
	    do_fio(&c__1, (char *)&dep10, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&mag10, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&event_1.nreg, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&xout, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&yout, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&rms100, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&gap_1.igap[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&idmin, (ftnlen)sizeof(integer));
	    i__2 = obb_1.knobs[i__ - 1] - obb_1.nobswithw0;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    e_wsfi();
	}

/* hrm  If running in single mode, the diagonal elements of the covariance matrix */
/* hrm  will also added to the smpline. In the simultaneous mode the line will be */
/* hrm  written to the file here. */

/* ek */
/* ek   this option turned off for single event mode since smp-file only in */
/* ek   SED special format */
/* ek */
	if (coordsyst_1.isingle == 0 && outputfiles_1.ismpout == 1) {
	    s_wsfe(&io___824);
	    do_fio(&c__1, a4_1.smpline, (ftnlen)80);
	    e_wsfe();
	}
/* cc      if(.not.single_turbo) write(16,*) */
	if (coordsyst_1.isingle != 0) {
	    if (! coordsyst_1.single_turbo__) {
		s_wsfe(&io___825);
		do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&gap_1.igap[i__ - 1], (ftnlen)sizeof(
			integer));
		e_wsfe();
	    }
	    if (coordsyst_1.icoordsystem == 2 && event_1.nreg >= 1000) {
		if (! coordsyst_1.single_turbo__) {
		    s_wsfe(&io___826);
		    do_fio(&c__1, event_1.regionname, (ftnlen)32);
		    do_fio(&c__1, (char *)&event_1.nreg, (ftnlen)sizeof(
			    integer));
		    e_wsfe();
		}
		s_wsfe(&io___827);
		do_fio(&c__1, event_1.regionname, (ftnlen)32);
		do_fio(&c__1, (char *)&event_1.nreg, (ftnlen)sizeof(integer));
		e_wsfe();
	    } else {
		if (! coordsyst_1.single_turbo__) {
		    s_wsfe(&io___828);
		    do_fio(&c__1, event_1.regionname, (ftnlen)32);
		    do_fio(&c__1, (char *)&event_1.nreg, (ftnlen)sizeof(
			    integer));
		    e_wsfe();
		}
		s_wsfe(&io___829);
		do_fio(&c__1, event_1.regionname, (ftnlen)32);
		do_fio(&c__1, (char *)&event_1.nreg, (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	}
	if (outputfiles_1.icnvout == 0) {
	    goto L12;
	}

/* ---- output final hypocenters and travel times to file07 */

/* ek     write(7,'(3i2,1x,2i2,1x,f5.2,1x,f7.4,a1,1x,f8.4,a1,2f7.2)') */
/* ek     &          iyr(i),imo(i),iday(i),ihr(i),nin,sec, */
/* ek     &          xlat,cns,xlon,cew, */
/* ek     &          e(4,i),emag(i) */
/* ek */
/* ek next statement changed by E.Kissling, 21.12.90: */
/* ek          added output of gap and rms of event to converted format */
/* ek */
/* do NOT write on file07 */
	s_wsfe(&io___830);
	do_fio(&c__1, (char *)&event_1.iyr[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&event_1.imo[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&event_1.iday[i__ - 1], (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&event_1.ihr[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nin, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&sec, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&xlat, (ftnlen)sizeof(real));
	do_fio(&c__1, cns, (ftnlen)1);
	do_fio(&c__1, (char *)&xlon, (ftnlen)sizeof(real));
	do_fio(&c__1, cew, (ftnlen)1);
	do_fio(&c__1, (char *)&event_1.e[(i__ << 2) - 1], (ftnlen)sizeof(real)
		);
	do_fio(&c__1, (char *)&event_1.emag[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&gap_1.igap[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&a4_1.rms[i__ - 1], (ftnlen)sizeof(real));
	e_wsfe();

	event_1.imin[i__ - 1] = nin;
	i__2 = obb_1.knobs[i__ - 1];
	for (j = 1; j <= i__2; ++j) {
/* L18: */
	    tt[j - 1] = obb_1.pt[j + i__ * 650 - 651] - event_1.e[(i__ << 2) 
		    - 4];
	}
	event_1.e[(i__ << 2) - 4] = sec;

	i__2 = obb_1.knobs[i__ - 1];
	for (j = 1; j <= i__2; ++j) {
	    *(unsigned char *)&phzz[j - 1] = 'P';
	    if (obb_1.sphase[j + i__ * 650 - 651] == 1.f) {
		*(unsigned char *)&phzz[j - 1] = 'S';
	    }
	    if (obb_1.sphase[j + i__ * 650 - 651] == -1.f) {
		*(unsigned char *)&phzz[j - 1] = 'M';
	    }
	    if (obb_1.sphase[j + i__ * 650 - 651] == 2.f) {
		*(unsigned char *)&phzz[j - 1] = '-';
	    }
	}
	s_wsfe(&io___833);
	i__2 = obb_1.knobs[i__ - 1];
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, charc_1.smn + (j + i__ * 650 - 651 << 2), (ftnlen)4)
		    ;
	    do_fio(&c__1, phzz + (j - 1), (ftnlen)1);
	    do_fio(&c__1, (char *)&obb_1.kpwt[j + i__ * 650 - 651], (ftnlen)
		    sizeof(integer));
	    do_fio(&c__1, (char *)&tt[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsle(&io___834);
	e_wsle();

L12:
	;
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___835);
	e_wsle();
    }

    return 0;
} /* finalhypocout_ */


/* of subr. finalhypocout */
/* Subroutine */ int openerror_(char *subr, char *char__, ftnlen subr_len, 
	ftnlen char_len)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___836 = { 0, 6, 0, 0, 0 };
    static cilist io___837 = { 0, 6, 0, 0, 0 };
    static cilist io___838 = { 0, 16, 0, 0, 0 };
    static cilist io___839 = { 0, 16, 0, 0, 0 };




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
    s_wsle(&io___836);
    do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
    e_wsle();
    s_wsle(&io___837);
    do_lio(&c__9, &c__1, "SUBROUTINE :", (ftnlen)12);
    do_lio(&c__9, &c__1, subr, subr_len);
    do_lio(&c__9, &c__1, "    ERROR OPENING FILE: ", (ftnlen)24);
    do_lio(&c__9, &c__1, char__, char_len);
    e_wsle();
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___838);
	do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
	e_wsle();
	s_wsle(&io___839);
	do_lio(&c__9, &c__1, "SUBROUTINE :", (ftnlen)12);
	do_lio(&c__9, &c__1, subr, subr_len);
	do_lio(&c__9, &c__1, "    ERROR OPENING FILE: ", (ftnlen)24);
	do_lio(&c__9, &c__1, char__, char_len);
	e_wsle();
    }
    s_stop("Openerror; program VELEST stopped !", (ftnlen)35);
    return 0;
} /* openerror_ */


/* of subr. openerror */
/* Subroutine */ int stinp_(integer *itime, char *stn, char *sfreq, integer *
	isper, integer *iscon, integer *isdmp, integer *isamp, real *scor, 
	integer *ier, ftnlen stn_len, ftnlen sfreq_len)
{
    /* Format strings */
    static char fmt_11[] = "(4x,2(i4,4i2,1x),a2,i2,2i3,i6,f6.2)";

    /* System generated locals */
    integer i__1;
    icilist ici__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsfi(icilist *), e_rsfi(void), s_cmp(char *, char *, ftnlen, 
	    ftnlen);

    /* Local variables */
    static integer maxstlin, ifirstcall;
    static char stn6[6];
    static integer ilin, ierr;
    static char snam6[6];
    static integer ishr1, ishr2, ismo1, isdy1, ismo2, isdy2, isyr1, isyr2, 
	    iscor;
    static char stlin[80*600];
    static integer ismin1, ismin2;
    extern integer juliam_(integer *, integer *, integer *, integer *, 
	    integer *);
    static integer istime1, istime2;

    /* Fortran I/O blocks */
    static cilist io___842 = { 0, 10, 1, "(a)", 0 };


/* tabelle fuer stationen im input file */
/* itime= eventtime in minuten */

/*      ifilt(l)= sfreq */
/*      iseis(l)= isper */
/*      sconst(l)=float(iscon)/10. */
/*      sdampf(l)= float(isdmp)/10. */
/*      voltgain(l)= isamp */
/*      cormag(l)= float(iscor)/1000. */


/* hrm      character*4 snam,stn */
/* NEW!!: */

/* file STLIST.DAT contains currently 60 */

/*     for the first time in this subr. --> read seismo-file into STLIN : */

    if (ifirstcall != 10000001) {
	ifirstcall = 10000001;
	maxstlin = 1;
L1000:
	i__1 = s_rsfe(&io___842);
	if (i__1 != 0) {
	    goto L2000;
	}
	i__1 = do_fio(&c__1, stlin + (maxstlin - 1) * 80, (ftnlen)80);
	if (i__1 != 0) {
	    goto L2000;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L2000;
	}
	++maxstlin;
	if (maxstlin == 600) {
	    s_stop("STINP>>> array stlin too small!!", (ftnlen)32);
	}
	goto L1000;
L2000:
	--maxstlin;
    }

    s_copy(stn6, stn, (ftnlen)6, (ftnlen)4);
    ilin = 0;
    ierr = 0;
L1:
    ++ilin;
    if (ilin > maxstlin) {
	goto L40;
    }
    ici__1.icierr = 0;
    ici__1.iciend = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = 80;
    ici__1.iciunit = stlin + (ilin - 1) * 80;
    ici__1.icifmt = "(a6)";
    s_rsfi(&ici__1);
    do_fio(&c__1, snam6, (ftnlen)6);
    e_rsfi();
/* !!!NEW */
    if (s_cmp(snam6, stn6, (ftnlen)4, (ftnlen)4) != 0) {
	goto L1;
    }
L20:
    ++ilin;
    if (ilin > maxstlin) {
	goto L40;
    }
    ici__1.icierr = 0;
    ici__1.iciend = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = 80;
    ici__1.iciunit = stlin + (ilin - 1) * 80;
    ici__1.icifmt = fmt_11;
    s_rsfi(&ici__1);
    do_fio(&c__1, (char *)&isyr1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ismo1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&isdy1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ishr1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ismin1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&isyr2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ismo2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&isdy2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ishr2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ismin2, (ftnlen)sizeof(integer));
    do_fio(&c__1, sfreq, (ftnlen)2);
    do_fio(&c__1, (char *)&(*isper), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*iscon), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*isdmp), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*isamp), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*scor), (ftnlen)sizeof(real));
    e_rsfi();
    if (isyr1 != 0) {
	istime1 = juliam_(&isyr1, &ismo1, &isdy1, &ishr1, &ismin1);
	istime2 = juliam_(&isyr2, &ismo2, &isdy2, &ishr2, &ismin2);
	if (*itime < istime1 || *itime > istime2) {
	    goto L20;
	} else {
L30:
	    ++ilin;
	    if (ilin > maxstlin) {
		goto L40;
	    }
	    ici__1.icierr = 0;
	    ici__1.iciend = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = 80;
	    ici__1.iciunit = stlin + (ilin - 1) * 80;
	    ici__1.icifmt = fmt_11;
	    s_rsfi(&ici__1);
	    do_fio(&c__1, (char *)&isyr1, (ftnlen)sizeof(integer));
	    e_rsfi();
	    if (isyr1 != 0) {
		goto L30;
	    }
	}
    }
    iscor = *scor * 1000;
    return 0;

/*     if station not found in stationfile with seismometer-parameters: */

L40:
    ierr = -6;
    return 0;
} /* stinp_ */


/* of subr. stinp */
/* Subroutine */ int inputcnv_(integer *iunit, integer *nobs, char *sta, 
	integer *iyr, integer *imo, integer *iday, integer *ihr, integer *
	imin, real *sec, char *rmk1, char *rmk2, char *cphase, integer *iwt, 
	real *amx, real *prx, real *xlat, real *xlon, real *xmagni, real *
	depth, real *origtime, integer *i1, integer *i2, integer *i3, char *
	eventtype, ftnlen sta_len, ftnlen rmk1_len, ftnlen rmk2_len, ftnlen 
	cphase_len, ftnlen eventtype_len)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi(
	    void), s_wsle(cilist *), do_lio(integer *, integer *, char *, 
	    ftnlen), e_wsle(void), s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer j;
    extern /* Subroutine */ int timeclear_(integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *);
    static integer j1, j2;
    static char cew[1], cns[1], cline[80];
    static integer itime;
    static real ttime[180];

    /* Fortran I/O blocks */
    static cilist io___862 = { 0, 0, 1, "(a)", 0 };
    static icilist io___864 = { 1, cline, 1, "(3i2,1x,2i2,1x,f5.2,1x,f7.4,a1"
	    ",1x,f8.4,a1,1x,f7.2,          2x,f5.2)", 80, 1 };
    static cilist io___869 = { 0, 0, 1, "(6(a4,a1,i1,f6.2))", 0 };
    static cilist io___872 = { 0, 6, 0, 0, 0 };
    static cilist io___873 = { 0, 6, 0, "(a)", 0 };



/*     on Output: */
/*     --------- */
/*     EQS:   i1=ifx(i) */
/*     SHOTS: i1=icc */




    /* Parameter adjustments */
    --prx;
    --amx;
    --iwt;
    --cphase;
    --rmk2;
    --rmk1;
    --sec;
    sta -= 4;

    /* Function Body */
L1:
    *(unsigned char *)eventtype = 'L';
    j2 = -1;
    *nobs = 0;

L2:
    io___862.ciunit = *iunit;
    i__1 = s_rsfe(&io___862);
    if (i__1 != 0) {
	goto L99;
    }
    i__1 = do_fio(&c__1, cline, (ftnlen)80);
    if (i__1 != 0) {
	goto L99;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L99;
    }
    if (s_cmp(cline, " ", (ftnlen)80, (ftnlen)1) == 0) {
	goto L2;
    }
/* ek search for end of *.cnv file, marked by 9999 */
    if (s_cmp(cline, "9999", (ftnlen)80, (ftnlen)4) == 0) {
	goto L999;
    }

/* ek   next line adjusted by EK 3.12.90 */
    i__1 = s_rsfi(&io___864);
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*iyr), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*imo), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*iday), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*ihr), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*imin), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*origtime), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*xlat), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, cns, (ftnlen)1);
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*xlon), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, cew, (ftnlen)1);
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*depth), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, (char *)&(*xmagni), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = e_rsfi();
L100001:
    if (i__1 < 0) {
	goto L999;
    }
    if (i__1 > 0) {
	goto L9999;
    }
/* =======================!   trial hypocenter !! */
/* ek  i1-switch is dummy */
/* i1 =ifx(i) */
    *i1 = 0;

/* ek     EQS:   i1=ifx(i)     ! no longer in use !!! */
/*     SHOTS: i1=icc */

    if (*(unsigned char *)cns == 'S') {
	*xlat = -(*xlat);
    }
    if (*(unsigned char *)cew == 'E') {
	*xlon = -(*xlon);
    }

    timeclear_(iyr, imo, iday, ihr, imin, origtime, &itime);

    j2 = 0;
L10:
    j1 = j2 + 1;
    j2 = j1 + 5;
    io___869.ciunit = *iunit;
    i__1 = s_rsfe(&io___869);
    if (i__1 != 0) {
	goto L999;
    }
    i__2 = j2;
    for (j = j1; j <= i__2; ++j) {
	i__1 = do_fio(&c__1, sta + (j << 2), (ftnlen)4);
	if (i__1 != 0) {
	    goto L999;
	}
	i__1 = do_fio(&c__1, cphase + j, (ftnlen)1);
	if (i__1 != 0) {
	    goto L999;
	}
	i__1 = do_fio(&c__1, (char *)&iwt[j], (ftnlen)sizeof(integer));
	if (i__1 != 0) {
	    goto L999;
	}
	i__1 = do_fio(&c__1, (char *)&ttime[j - 1], (ftnlen)sizeof(real));
	if (i__1 != 0) {
	    goto L999;
	}
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = j2;
    for (j = j1; j <= i__1; ++j) {
	if (s_cmp(sta + (j << 2), " ", (ftnlen)4, (ftnlen)1) == 0) {
	    if (j == 1 && j1 == 1) {
		goto L1;
	    }
/* blank-line read ! */
	    j2 = j - 1;
/* event is completely read-in */
	    goto L99;
	}
    }
    goto L10;

/* read next input-line */
L99:
    *nobs = j2;
    i__1 = *nobs;
    for (j = 1; j <= i__1; ++j) {
	sec[j] = *origtime + ttime[j - 1];
    }

    return 0;

L999:
    *nobs = -1;
    return 0;

L9999:
    s_wsle(&io___872);
    do_lio(&c__9, &c__1, "INPUTCNV>>> read-error! input-line is:", (ftnlen)38)
	    ;
    e_wsle();
    s_wsfe(&io___873);
    do_fio(&c__1, cline, (ftnlen)80);
    e_wsfe();
    s_stop("subr. INPUTCNV >>> error!", (ftnlen)25);

    return 0;
} /* inputcnv_ */


/* of subr. inputcnv */
/* Subroutine */ int inputarcvel_(integer *iunit, integer *nobs, char *sta, 
	integer *iyr, integer *imo, integer *iday, integer *ihr, integer *
	imin, real *sec, char *rmk1, char *rmk2, char *cphase, integer *iwt, 
	real *amx, real *prx, real *xlat, real *xlon, real *xmagni, real *
	depth, real *origtime, integer *i1, integer *i2, integer *i3, char *
	eventtype, ftnlen sta_len, ftnlen rmk1_len, ftnlen rmk2_len, ftnlen 
	cphase_len, ftnlen eventtype_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi(
	    void), s_wsle(cilist *), do_lio(integer *, integer *, char *, 
	    ftnlen), e_wsle(void), s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer j;
    extern /* Subroutine */ int timeclear_(integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *);
    static integer j1;
    static char cew[1], cns[1], cline[80];
    static integer itime;
    static real ttime[180];

    /* Fortran I/O blocks */
    static cilist io___874 = { 0, 0, 1, "(a)", 0 };
    static icilist io___876 = { 1, cline, 1, "(3i2,1x,2i2,1x,f5.2,1x,f7.4,a1"
	    ",1x,f8.4,a1,1x,f7.2,          2x,f5.2)", 80, 1 };
    static cilist io___882 = { 0, 0, 1, "(2x,a4,2x,a1,3x,i1,3x,f6.2)", 0 };
    static cilist io___884 = { 0, 6, 0, 0, 0 };
    static cilist io___885 = { 0, 6, 0, "(a)", 0 };



/*  implemented by EK 9.11.93 to read velest-archive type input */
/*  data for single event location mode , replacing older */
/*  input routine for SED-format. called by ised=1 */

/*     on Output: */
/*     --------- */
/*     EQS:   i1=ifx(i)   ! no longer in use !!! */
/*     SHOTS: i1=icc */




    /* Parameter adjustments */
    --prx;
    --amx;
    --iwt;
    --cphase;
    --rmk2;
    --rmk1;
    --sec;
    sta -= 4;

    /* Function Body */
/* L1: */
    *(unsigned char *)eventtype = 'L';
    *nobs = -1;

L2:
    io___874.ciunit = *iunit;
    i__1 = s_rsfe(&io___874);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_fio(&c__1, cline, (ftnlen)80);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L999;
    }
    if (s_cmp(cline, " ", (ftnlen)80, (ftnlen)1) == 0) {
	goto L2;
    }

    i__1 = s_rsfi(&io___876);
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*iyr), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*imo), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*iday), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*ihr), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*imin), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*origtime), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*xlat), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, cns, (ftnlen)1);
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*xlon), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, cew, (ftnlen)1);
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*depth), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, (char *)&(*xmagni), (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = e_rsfi();
L100002:
    if (i__1 < 0) {
	goto L999;
    }
    if (i__1 > 0) {
	goto L9999;
    }
/* =======================!   trial hypocenter !! */
/* ek  i1-switch is dummy */
/*  i1  =ifx(i) */
    *i1 = 0;

/* ek     EQS:   i1=ifx(i)     ! no longer in use !!! */
/*     SHOTS: i1=icc */

    if (*(unsigned char *)cns == 'S') {
	*xlat = -(*xlat);
    }
    if (*(unsigned char *)cew == 'E') {
	*xlon = -(*xlon);
    }

    timeclear_(iyr, imo, iday, ihr, imin, origtime, &itime);

    j1 = 1;
    for (j = 1; j <= 180; ++j) {
	io___882.ciunit = *iunit;
	i__1 = s_rsfe(&io___882);
	if (i__1 != 0) {
	    goto L99;
	}
	i__1 = do_fio(&c__1, sta + (j << 2), (ftnlen)4);
	if (i__1 != 0) {
	    goto L99;
	}
	i__1 = do_fio(&c__1, cphase + j, (ftnlen)1);
	if (i__1 != 0) {
	    goto L99;
	}
	i__1 = do_fio(&c__1, (char *)&iwt[j], (ftnlen)sizeof(integer));
	if (i__1 != 0) {
	    goto L99;
	}
	i__1 = do_fio(&c__1, (char *)&ttime[j - 1], (ftnlen)sizeof(real));
	if (i__1 != 0) {
	    goto L99;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L99;
	}
	if (s_cmp(sta + (j << 2), " ", (ftnlen)4, (ftnlen)1) == 0) {
/* ek     mistake:       j1=j1-1 ! event is completely read-in */
	    goto L99;
	}
	j1 = j;
    }

L99:
    *nobs = j1;

    i__1 = *nobs;
    for (j = 1; j <= i__1; ++j) {
	sec[j] = *origtime + ttime[j - 1];
    }

    return 0;

L999:
    *nobs = -1;
    return 0;

L9999:
    s_wsle(&io___884);
    do_lio(&c__9, &c__1, "INPUTARCVEL>>> read-error! input-line is:", (ftnlen)
	    41);
    e_wsle();
    s_wsfe(&io___885);
    do_fio(&c__1, cline, (ftnlen)80);
    e_wsfe();
    s_stop("subr. INPUTARCVEL >>> error!", (ftnlen)28);

    return 0;
} /* inputarcvel_ */



/* of subr. inputarcvel */
/* Subroutine */ int inputsed_(integer *iunit, integer *nobs, char *sta, 
	integer *iyr, integer *imo, integer *iday, integer *ihr, integer *
	imin, real *sec, char *rmk1, char *rmk2, char *cphase, integer *iwt, 
	real *amx, real *prx, real *xlat, real *xlon, real *xmagni, real *
	depth, real *origtime, integer *iswt, integer *ifixsolution, integer *
	ievnr, char *eventtype, ftnlen sta_len, ftnlen rmk1_len, ftnlen 
	rmk2_len, ftnlen cphase_len, ftnlen eventtype_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     i_indx(char *, char *, ftnlen, ftnlen), s_cmp(char *, char *, 
	    ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer j;
    extern /* Subroutine */ int timeclear_(integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *);
    static integer j1, ihr1[180], imo1[180], iyr1[180], iday1[180], kmin1[180]
	    ;
    static char cline[80];
    static integer itime;
    static char clayp[1];
    static integer jjmin;
    static char clays[1];
    static integer itime1[180], jjmin1;

    /* Fortran I/O blocks */
    static cilist io___887 = { 0, 0, 1, "(a)", 0 };
    static icilist io___889 = { 0, cline, 0, "(17x,i1,i1,f5.2,2f8.3)", 80, 1 }
	    ;
    static icilist io___890 = { 1, cline, 0, "(a4,a1,a1,a1,i1,a1,5i2,f5.2,7x"
	    ",                                   f5.2,2x,a1,i1,4x,f3.0,f3.1)", 
	    80, 1 };
    static icilist io___898 = { 0, cline+63, 0, "(a1)", 1, 1 };
    static icilist io___899 = { 0, cline+75, 0, "(i4)", 4, 1 };
    static cilist io___905 = { 0, 6, 0, 0, 0 };
    static cilist io___906 = { 0, 6, 0, "(a)", 0 };



/*     read inputfile (phase-list in *.SED format) */
/*     if NOBS=-1 ==> end of input-file detected! */




    /* Parameter adjustments */
    --prx;
    --amx;
    --iwt;
    --cphase;
    --rmk2;
    --rmk1;
    --sec;
    sta -= 4;

    /* Function Body */
    *ifixsolution = 0;
    *nobs = 0;
    j = 0;

L1:
    io___887.ciunit = *iunit;
    i__1 = s_rsfe(&io___887);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_fio(&c__1, cline, (ftnlen)80);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L999;
    }
    if (i_indx(cline, "INST", (ftnlen)80, (ftnlen)4) > 0) {
	goto L1;
    }
    if (i_indx(cline, "SED", (ftnlen)80, (ftnlen)3) > 0) {
	goto L1;
    }
    if (i_indx(cline, "BOL", (ftnlen)80, (ftnlen)3) > 0) {
	goto L1;
    }
    if (i_indx(cline, "EVENT", (ftnlen)80, (ftnlen)5) > 0) {
	goto L1;
    }

    ++j;
    if (s_cmp(cline, " ", (ftnlen)4, (ftnlen)1) == 0) {
	s_rsfi(&io___889);
	do_fio(&c__1, (char *)&(*iswt), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*ifixsolution), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*depth), (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&(*xlat), (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&(*xlon), (ftnlen)sizeof(real));
	e_rsfi();
	*nobs = j - 1;
	goto L99;
/* one event finished!!! */
    }
    i__1 = s_rsfi(&io___890);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, sta + (j << 2), (ftnlen)4);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, rmk1 + j, (ftnlen)1);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, cphase + j, (ftnlen)1);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, rmk2 + j, (ftnlen)1);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&iwt[j], (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, clayp, (ftnlen)1);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&iyr1[j - 1], (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&imo1[j - 1], (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&iday1[j - 1], (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&ihr1[j - 1], (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&kmin1[j - 1], (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&sec[j], (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&sec[j + 1], (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, clays, (ftnlen)1);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&iwt[j + 1], (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&amx[j], (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&prx[j], (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = e_rsfi();
    if (i__1 != 0) {
	goto L9999;
    }
    if (j == 1) {
	s_rsfi(&io___898);
	do_fio(&c__1, eventtype, (ftnlen)1);
	e_rsfi();
	s_rsfi(&io___899);
	do_fio(&c__1, (char *)&(*ievnr), (ftnlen)sizeof(integer));
	e_rsfi();
    }
    if (iwt[j] == 9) {
	--j;
	goto L1;
/* p-weight 9 not accepted !(means: only T(s-p) ) */
    }
    if (*(unsigned char *)clayp == 'm' || *(unsigned char *)clayp == 'M') {
	*(unsigned char *)&cphase[j] = 'M';
    }
    if (s_cmp(cline + 19, " ", (ftnlen)5, (ftnlen)1) == 0) {
	iwt[j] = 5;
    }
/* cc   VELEST cannot handle reflected S-phases; therefore skip them! */
/* NO P-arrival read ! */
    if (*(unsigned char *)clays != ' ') {
	s_copy(cline + 31, " ", (ftnlen)5, (ftnlen)1);
    }
/* <-- set NO S-data if REFLEC */
    if (s_cmp(cline + 31, " ", (ftnlen)5, (ftnlen)1) != 0) {
/* field with observed S-time in sec */
	*(unsigned char *)&cphase[j + 1] = 'S';
	s_copy(sta + (j + 1 << 2), sta + (j << 2), (ftnlen)4, (ftnlen)4);
	*(unsigned char *)&rmk1[j + 1] = ' ';
	*(unsigned char *)&rmk2[j + 1] = ' ';
	iyr1[j] = iyr1[j - 1];
	imo1[j] = imo1[j - 1];
	iday1[j] = iday1[j - 1];
	ihr1[j] = ihr1[j - 1];
	kmin1[j] = kmin1[j - 1];
	if (iwt[j] == 5) {
/* NO P arrival here; store amx&prx to S-arr */
	    amx[j + 1] = amx[j];
	    prx[j + 1] = prx[j];
	}
	++j;
/* increment J, because two phases have been */
	goto L1;
    } else {
	goto L1;
/* no S-phase-data: elements J+1 will be overwritten */
    }

L99:
    i__1 = *nobs;
    for (j = 1; j <= i__1; ++j) {
	if (iwt[j] < 5) {
	    jjmin1 = j;
	    goto L222;
	}
    }
L222:
    j = jjmin1;
    timeclear_(&iyr1[j - 1], &imo1[j - 1], &iday1[j - 1], &ihr1[j - 1], &
	    kmin1[j - 1], &sec[j], &itime1[j - 1]);
    itime = itime1[j - 1];
    jjmin = jjmin1;
    i__1 = *nobs;
    for (j = 1; j <= i__1; ++j) {
	if (iwt[j] < 5) {
	    timeclear_(&iyr1[j - 1], &imo1[j - 1], &iday1[j - 1], &ihr1[j - 1]
		    , &kmin1[j - 1], &sec[j], &itime1[j - 1]);
	    if (itime1[j - 1] < itime) {
		itime = itime1[j - 1];
		jjmin = j;
	    }
	}
    }

/*     itime is the earliest arrival-minute; */
/*     adjust all seconds according to this (earliest) minute */

/* L100: */
    i__1 = *nobs;
    for (j1 = 1; j1 <= i__1; ++j1) {
	if (iwt[j1] < 5) {
	    sec[j1] = (itime1[j1 - 1] - itime) * 60.f + sec[j1];
	}
    }
    *origtime = sec[jjmin];
    *iyr = iyr1[jjmin - 1];
    *imo = imo1[jjmin - 1];
    *iday = iday1[jjmin - 1];
    *ihr = ihr1[jjmin - 1];
    *imin = kmin1[jjmin - 1];

    return 0;

L999:
/* come here, if end-of-input-file detected ! */
    *nobs = -1;
    return 0;

L9999:
    s_wsle(&io___905);
    do_lio(&c__9, &c__1, "INPUTSED>>> read-error! input-line is:", (ftnlen)38)
	    ;
    e_wsle();
    s_wsfe(&io___906);
    do_fio(&c__1, cline, (ftnlen)80);
    e_wsfe();
    s_stop("subr. INPUTSED >>> error!", (ftnlen)25);

    return 0;
} /* inputsed_ */



/* of subr. inputsed */
/* Subroutine */ int inputsed_new__(integer *iunit, integer *nobs, char *sta, 
	integer *iyr, integer *imo, integer *iday, integer *ihr, integer *
	imin, real *sec, char *rmk1, char *rmk2, char *cphase, integer *iwt, 
	real *amx, real *prx, real *xlat, real *xlon, real *xmagni, real *
	depth, real *origtime, integer *iswt, integer *ifixsolution, integer *
	ievnr, char *eventtype, integer *itrial, ftnlen sta_len, ftnlen 
	rmk1_len, ftnlen rmk2_len, ftnlen cphase_len, ftnlen eventtype_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     i_indx(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), 
	    e_rsfi(void), s_rsli(icilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_rsli(void), s_cmp(char *, char *, ftnlen, 
	    ftnlen), s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), e_wsfe(
	    void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static char phase_id__[8];
    static integer amx_flag__;
    extern /* Subroutine */ int casefold_(char *, ftnlen);
    static integer use_flag__, ev_month__;
    static char amx_type__[8];
    static integer j;
    extern /* Subroutine */ int timeclear_(integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *);
    static integer j1, ihr1[180], imo1[180], iyr1[180], iday1[180], kmin1[180]
	    ;
    static char cline[80];
    static integer itime, jjmin, found, itime1[180], jjmin1, ev_day__, 
	    ev_min__, itime_o__, ev_year__, ev_hour__;

    /* Fortran I/O blocks */
    static cilist io___908 = { 0, 0, 1, "(a)", 0 };
    static icilist io___910 = { 0, cline, 0, "(29x,i2)", 80, 1 };
    static icilist io___911 = { 0, cline, 0, 0, 80, 1 };
    static cilist io___913 = { 0, 0, 1, "(a)", 0 };
    static icilist io___914 = { 0, cline, 0, "(2x,i2,1x,i2,1x,i2,1x,i2,1x,i2)"
	    , 80, 1 };
    static icilist io___920 = { 0, cline+54, 0, "(a1)", 1, 1 };
    static icilist io___921 = { 0, cline+70, 0, "(i8)", 8, 1 };
    static icilist io___922 = { 1, cline, 0, "(a4,4x,a8,a1,a1,f8.3,i2,f5.2,f"
	    "9.0,1x,a8,i3)", 80, 1 };
    static cilist io___938 = { 0, 6, 0, 0, 0 };
    static cilist io___939 = { 0, 6, 0, "(a)", 0 };



/*     read inputfile (phase-list in *.SED format) */
/*     if NOBS=-1 ==> end of input-file detected! */




    /* Parameter adjustments */
    --prx;
    --amx;
    --iwt;
    --cphase;
    --rmk2;
    --rmk1;
    --sec;
    sta -= 4;

    /* Function Body */
    *ifixsolution = 0;
    *nobs = 0;
    j = 0;

L1:
    io___908.ciunit = *iunit;
    i__1 = s_rsfe(&io___908);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_fio(&c__1, cline, (ftnlen)80);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L999;
    }

/*     The following cards will be skipped */

    if (i_indx(cline, "SED", (ftnlen)80, (ftnlen)3) > 0) {
	goto L1;
    }
    if (i_indx(cline, "BOL", (ftnlen)80, (ftnlen)3) > 0) {
	goto L1;
    }
    if (i_indx(cline, "EVENT", (ftnlen)80, (ftnlen)5) > 0) {
	goto L1;
    }

/*     The INST card will be partially read */

    if (i_indx(cline, "INST", (ftnlen)80, (ftnlen)4) > 0) {
	s_rsfi(&io___910);
	do_fio(&c__1, (char *)&(*iswt), (ftnlen)sizeof(integer));
	e_rsfi();
	goto L1;
    }

/* ccccccccccccccccccccccccccc */
/*     Hypon input section  c */
/* ccccccccccccccccccccccccccc */
/*      read(line,*,err=900) */
/*     +		latr,lonr,ztr,y0tr,motr,dytr,h0tr, */
/*     +		m0tr,s0tr,inst */
/* latr:	trial latitude */
/* lonr:	  "   longitude */
/* ztr:	  "   depth */
/* y0tr:	  "   origin year */
/* motr:	  "      "   month */
/* dytr:	  "      "   day */
/* h0tr:	  "      "   hour */
/* m0tr:	  "      "   minute */
/* s0tr:	  "      "   second */
/* inst: 0=  free solution */
/*       1=  fix depth */
/*       2=  fix lat/lon depth */
/*       3=  fix origin time */
/*       4=  fix all */
/* cccccccccccccccccccccccccccccccccccccccccc */

    if (i_indx(cline, "TRIAL", (ftnlen)80, (ftnlen)5) > 0) {
	s_rsli(&io___911);
	do_lio(&c__4, &c__1, (char *)&(*xlat), (ftnlen)sizeof(real));
	do_lio(&c__4, &c__1, (char *)&(*xlon), (ftnlen)sizeof(real));
	do_lio(&c__4, &c__1, (char *)&(*depth), (ftnlen)sizeof(real));
	do_lio(&c__3, &c__1, (char *)&(*iyr), (ftnlen)sizeof(integer));
	do_lio(&c__3, &c__1, (char *)&(*imo), (ftnlen)sizeof(integer));
	do_lio(&c__3, &c__1, (char *)&(*iday), (ftnlen)sizeof(integer));
	do_lio(&c__3, &c__1, (char *)&(*ihr), (ftnlen)sizeof(integer));
	do_lio(&c__3, &c__1, (char *)&(*imin), (ftnlen)sizeof(integer));
	do_lio(&c__4, &c__1, (char *)&(*origtime), (ftnlen)sizeof(real));
	do_lio(&c__3, &c__1, (char *)&(*ifixsolution), (ftnlen)sizeof(integer)
		);
	e_rsli();
	*xlon = -(*xlon);
	*iyr += -1900;
	if (*ifixsolution == 4) {
	    *ifixsolution = 9;
	}
	timeclear_(iyr, imo, iday, ihr, imin, origtime, &itime_o__);

/*        Reading the line after the TRIAL card */

	io___913.ciunit = *iunit;
	i__1 = s_rsfe(&io___913);
	if (i__1 != 0) {
	    goto L999;
	}
	i__1 = do_fio(&c__1, cline, (ftnlen)80);
	if (i__1 != 0) {
	    goto L999;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L999;
	}
	s_rsfi(&io___914);
	do_fio(&c__1, (char *)&ev_year__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ev_month__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ev_day__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ev_hour__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ev_min__, (ftnlen)sizeof(integer));
	e_rsfi();
	s_rsfi(&io___920);
	do_fio(&c__1, eventtype, (ftnlen)1);
	e_rsfi();
	s_rsfi(&io___921);
	do_fio(&c__1, (char *)&(*ievnr), (ftnlen)sizeof(integer));
	e_rsfi();
	goto L1;
    }

/*     If the SKIP card is reached, the input for one event is finished */

    if (i_indx(cline, "SKIP", (ftnlen)80, (ftnlen)4) > 0) {
	*nobs = j;
	goto L99;
/* one event finished!!! */
    }

/*     If here, a phase will be read */

    ++j;
    i__1 = s_rsfi(&io___922);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, sta + (j << 2), (ftnlen)4);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, phase_id__, (ftnlen)8);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, rmk1 + j, (ftnlen)1);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, rmk2 + j, (ftnlen)1);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&sec[j], (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&use_flag__, (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&prx[j], (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&amx[j], (ftnlen)sizeof(real));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, amx_type__, (ftnlen)8);
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = do_fio(&c__1, (char *)&amx_flag__, (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L9999;
    }
    i__1 = e_rsfi();
    if (i__1 != 0) {
	goto L9999;
    }
    casefold_(phase_id__, (ftnlen)8);
    casefold_(amx_type__, (ftnlen)8);
    casefold_(rmk1 + j, (ftnlen)1);
    casefold_(rmk2 + j, (ftnlen)1);

/*     Treat the supported phase types */

    found = 0;
    if (s_cmp(phase_id__, "P       ", (ftnlen)8, (ftnlen)8) == 0) {
	found = 1;
	*(unsigned char *)&cphase[j] = 'P';
    }
    if (s_cmp(phase_id__, "S       ", (ftnlen)8, (ftnlen)8) == 0) {
	found = 1;
	*(unsigned char *)&cphase[j] = 'S';
    }
    if (s_cmp(phase_id__, "PMP     ", (ftnlen)8, (ftnlen)8) == 0) {
	found = 1;
	*(unsigned char *)&cphase[j] = 'M';
    }
    if (s_cmp(phase_id__, "S-P     ", (ftnlen)8, (ftnlen)8) == 0) {
	found = 1;
	*(unsigned char *)&cphase[j] = '-';
    }

/*     If the read phase is not supported, it will be skipped */

    if (found == 0) {
	--j;
	goto L1;
    }

/*     Conversion of the weights */

    if (*(unsigned char *)&rmk1[j] == 'I') {
	iwt[j] = 0;
    }
    if (*(unsigned char *)&rmk1[j] == 'E') {
	iwt[j] = 1;
    }
    if (*(unsigned char *)&rmk1[j] == 'Q') {
	iwt[j] = 2;
    }
    if (*(unsigned char *)&rmk1[j] == ' ') {
/* Should never happen */
	iwt[j] = 5;
    }
/* hrm      if (use_flag.eq.0) then */
/* hrm         j=j-1 */
/* hrm	 goto 1 */
/* hrm      endif */
    if (use_flag__ == 0) {
	iwt[j] = 4;
    }

/*     Assigning year,month,day,hour,min to each phase */

    iyr1[j - 1] = ev_year__;
    imo1[j - 1] = ev_month__;
    iday1[j - 1] = ev_day__;
    ihr1[j - 1] = ev_hour__;
    kmin1[j - 1] = ev_min__;

/*     Read the next event */

    goto L1;

/*     If here, all phases of one event are read in */


L99:

/*     Searching for the first phase with weight less than 5 */

    i__1 = *nobs;
    for (j = 1; j <= i__1; ++j) {
	if (iwt[j] < 5) {
	    jjmin1 = j;
	    goto L222;
	}
    }
L222:
    j = jjmin1;
    timeclear_(&iyr1[j - 1], &imo1[j - 1], &iday1[j - 1], &ihr1[j - 1], &
	    kmin1[j - 1], &sec[j], &itime1[j - 1]);
    itime = itime1[j - 1];
    jjmin = jjmin1;
    i__1 = *nobs;
    for (j = 1; j <= i__1; ++j) {
	if (iwt[j] < 5) {
	    timeclear_(&iyr1[j - 1], &imo1[j - 1], &iday1[j - 1], &ihr1[j - 1]
		    , &kmin1[j - 1], &sec[j], &itime1[j - 1]);
	    if (itime1[j - 1] < itime) {
		itime = itime1[j - 1];
		jjmin = j;
	    }
	}
    }

/*     itime is the earliest arrival-minute; */
/*     adjust all seconds according to this (earliest) minute */

/* L100: */
    if (*itrial > 0) {
	i__1 = *nobs;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    if (iwt[j1] < 5) {
		sec[j1] = (itime1[j1 - 1] - itime) * 60.f + sec[j1];
	    }
/* hrm	    itime1(j1) = itime  ! Activate this, if you want to use itime1(j1) */
	}
	*origtime = sec[jjmin];
	*iyr = iyr1[jjmin - 1];
	*imo = imo1[jjmin - 1];
	*iday = iday1[jjmin - 1];
	*ihr = ihr1[jjmin - 1];
	*imin = kmin1[jjmin - 1];
    } else {
	i__1 = *nobs;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    if (iwt[j1] < 5) {
		sec[j1] = (itime1[j1 - 1] - itime_o__) * 60.f + sec[j1];
		if (sec[j1] < 0.f) {
		    sec[j1] = 0.f;
		}
	    }
/* hrm	    itime1(j1) = itime  ! Activate this, if you want to use itime1(j1) */
	}
    }

    return 0;

L999:
/* come here, if end-of-input-file detected ! */
    *nobs = -1;
    return 0;

L9999:
    s_wsle(&io___938);
    do_lio(&c__9, &c__1, "INPUTSED>>> read-error! input-line is:", (ftnlen)38)
	    ;
    e_wsle();
    s_wsfe(&io___939);
    do_fio(&c__1, cline, (ftnlen)80);
    e_wsfe();
    s_stop("subr. INPUTSED >>> error!", (ftnlen)25);

    return 0;
} /* inputsed_new__ */


/* ek    end of vel_io.f */

/* ek    begin of vel_kern.f */

/* of subr. inputsed_new */
/* Subroutine */ int setunt_(integer *nitt, integer *invertratio, integer *
	nsinv, integer *icount, real *xythet, real *stathet, real *othet, 
	real *vthet, real *zthet, real *scale)
{
    /* Builtin functions */
    double sqrt(doublereal);


/*     set scale factors */


/* ***  set damping so that velocities are adjusted every */
/* ***  "invertratio" iterations */
    /* Parameter adjustments */
    --scale;

    /* Function Body */
    *icount = *nitt % *invertratio;

/*     scale(1) : origin-time */
/*     scale(2) : x */
/*     scale(3) : y */
/*     scale(4) : z */
/*     scale(5) : stacorr */
/*     scale(6) : veloc.model */
/*     scale(7) : (not used) */

    scale[1] = 1.f;
    scale[7] = 1.f;
/* not used in this version!!! */
    scale[2] = sqrt(*othet / *xythet);
    scale[3] = scale[2];
    scale[4] = sqrt(*othet / *zthet);
    scale[5] = 0.f;
    if (*nsinv != 0 && *icount == 0) {
	scale[5] = sqrt(*othet / *stathet);
    }
    scale[6] = 0.f;
    if (*icount == 0) {
	scale[6] = sqrt(*othet / *vthet);
    }
    return 0;
} /* setunt_ */


/* of subr. setunt */
/* Subroutine */ int fixunt_(real *b, integer *neqs, integer *nshot, integer *
	nl, integer *ksta, real *scale, real *vdamp, integer *itotmodels, 
	integer *inltot, integer *nlfirst)
{
    /* System generated locals */
    integer vdamp_dim1, vdamp_offset, i__1;

    /* Local variables */
    static integer i__, j, k, l, m;


/* ---- restore solution to proper units */

    /* Parameter adjustments */
    --b;
    --scale;
    vdamp_dim1 = *itotmodels;
    vdamp_offset = 1 + vdamp_dim1;
    vdamp -= vdamp_offset;

    /* Function Body */
    i__ = 0;
    if (*neqs <= 0) {
	goto L10;
    }
    i__1 = *neqs;
    for (j = 1; j <= i__1; ++j) {
	for (k = 1; k <= 4; ++k) {
	    ++i__;
/* L1: */
	    b[i__] *= scale[k];
	}
    }
L10:
    if (*nshot <= 0) {
	goto L3;
    }
    i__1 = *nshot;
    for (j = 1; j <= i__1; ++j) {
	++i__;
/* L2: */
	b[i__] *= scale[7];
    }
L3:
    if (scale[6] == 0.f) {
	return 0;
    }
    l = 0;
    m = 1;
    i__1 = *nl;
    for (j = 1; j <= i__1; ++j) {
	++i__;
	++l;
	if (l > *nlfirst) {
	    ++m;
	    l = 1;
	}
/* hrm      write(6,*)m,'  ',l */
/* L5: */
	b[i__] = b[i__] * scale[6] / vdamp[m + l * vdamp_dim1];
    }
    if (*ksta == 0) {
	return 0;
    }
    i__1 = *ksta;
    for (j = 1; j <= i__1; ++j) {
	++i__;
/* L4: */
	b[i__] *= scale[5];
    }
    return 0;
} /* fixunt_ */


/* of subr. fixunt */
/* Subroutine */ int setupmatrixg_(integer *neq, integer *i__)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k, n, k1, k2, mg, ng, nf, mm, nl, nn, mf, is, kk1, is1, 
	    nni;
    extern /* Subroutine */ int accunormeqs_(real *, integer *, real *, real *
	    , real *, real *);
    static integer ksta1, ksta2;


/*     puts one row S(i) of the data kernel into the symmetric matrix G in */
/*     order to accumulate the normal equations. */

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

/* cc      real WK(8,2),bwk(1) */

    i__1 = dimen_1.nvar;
    for (j = 1; j <= i__1; ++j) {
/* L2: */
	a4_1.s[j - 1] = 0.f;
    }

/*     No trvdrv's for reseted obs: */

    if (coordsyst_1.isingle != 0 && obb_1.w[*i__ + *neq * 650 - 651] == 0.f) {
	goto L34;
    }

/* ---- calculate hypocenter indices */
/* ***   neq-- event number, i--observation number */
    nn = (*neq << 2) - 2;
    nni = nn - 1;
/* ***    nni- space for time term; nn thru mm -- 3 places for dtdr's */
    if (*neq > dimen_1.neqs) {
	nni = dimen_1.neqs * 3 + *neq;
    }
    mm = nn + 2;
    if (*neq > dimen_1.neqs) {
	mm = nni;
    }
    a4_1.s[nni - 1] = fix1_1.scale[0] * 1.f;
    if (obb_1.sphase[*i__ + *neq * 650 - 651] == 2.f) {
/* new: for s-p phases (hrm 30.3.92) */
	a4_1.s[nni - 1] = 0.f;
/* set derivative for orig. time to zero */
    }
    is1 = 0;
    if (*neq <= dimen_1.neqs) {
	goto L40;
    }
    a4_1.s[nni - 1] = fix1_1.scale[6] * 1.f;
    kk1 = statn_1.map2[*neq - dimen_1.neqs - 1];
    if (dimen_1.nshfix == 1 && kk1 != 0) {
	a4_1.s[nni - 1] = 0.f;
    }
    if (dimen_1.nshcor == 0) {
	goto L40;
    }
    if (kk1 <= 0 || kk1 > dimen_1.ksta) {
	goto L40;
    }
    if (fix1_1.scale[4] == 0.f) {
	goto L40;
    }

    if (modela_1.nsp == 3 && obb_1.sphase[*i__ + *neq * 650 - 651] == 1.f) {
	goto L40;
    }
    if (modela_1.nsp == 2 && obb_1.sphase[*i__ + *neq * 650 - 651] == 1.f) {
	goto L43;
    }
    ng = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + 1;
    mg = ng - 1 + dimen_1.ksta;
    ksta1 = dimen_1.ksta;
    if (kk1 > ksta1) {
	goto L40;
    }
    is1 = ng - 1 + kk1;
    goto L44;
L43:
    ng = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + dimen_1.ksta /
	     2 + 1;
    mg = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + dimen_1.ksta;
    ksta1 = dimen_1.ksta / 2;
    ksta2 = dimen_1.ksta - dimen_1.ksta / 2;
    if (kk1 > ksta2) {
	goto L40;
    }
    is1 = ng - 1 + kk1;
L44:
    a4_1.s[is1 - 1] = fix1_1.scale[4] * 1.f;
L40:
    k = 0;
    if (param_1.zadj == 0.f) {
	dttx_1.dtdr[2] = 0.f;
    }
/* c      if(isingle.ne.0.and.nitt.lt.3) dtdr(3)=0.0 */
/* c      if(isingle.ne.0.and.jgap.gt.250) dtdr(3)=0.0 */
    if (*neq > dimen_1.neqs) {
	goto L3;
    }

/* EK Dez. 1994  next statement again put in effect: */
    if (event_1.ifx[*neq - 1] == 1) {
	dttx_1.dtdr[1] = 0.f;
    }
/* no longer in use  U.K. 2.Oct.87 */
    i__1 = mm;
    for (j = nn; j <= i__1; ++j) {
	++k;
/* L4: */
	a4_1.s[j - 1] = dttx_1.dtdr[k - 1] * fix1_1.scale[k];
    }
L3:
/* ---- calculate velocity indices */
    if (fix1_1.scale[5] == 0.f) {
	goto L34;
    }
/* L15: */
    k2 = obb_1.iphase[*i__ + *neq * 650 - 651];
    nl = modela_1.nplay[k2 - 1];
    nf = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.laysum[k2 - 1];
    mf = nf + nl - 1;
    k = 0;
    i__1 = mf;
    for (n = nf; n <= i__1; ++n) {
	++k;
	if (param_1.veladj == 0.f) {
	    dttx_1.dtdv[k - 1] = 0.f;
	}
/* hrm    5 s(n)=dtdv(k)*scale(6) */
/* L5: */
	a4_1.s[n - 1] = dttx_1.dtdv[k - 1] * fix1_1.scale[5] / layvel_1.vdamp[
		k2 + (k << 1) - 3];
    }
/* ---- calculate indices for station terms */
    if (fix1_1.scale[4] == 0.f) {
	goto L34;
    }
    k1 = obb_1.istm[*i__ + *neq * 650 - 651];
    ksta1 = dimen_1.ksta;
    if (modela_1.nsp == 2) {
	ksta1 = dimen_1.ksta / 2;
    }
    if (modela_1.nsp == 2 && obb_1.sphase[*i__ + *neq * 650 - 651] == 1.f) {
	goto L16;
    }
    if (modela_1.nsp == 3 && obb_1.sphase[*i__ + *neq * 650 - 651] == 1.f) {
	goto L34;
    }
/* L18: */
    ng = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + 1;
    mg = ng - 1 + dimen_1.ksta;
    if (statn_1.map1[k1 - 1] == 0) {
	goto L34;
    }
    if (statn_1.map1[k1 - 1] > ksta1) {
	goto L34;
    }
    is = ng - 1 + statn_1.map1[k1 - 1];
    goto L17;
L16:
    ng = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + dimen_1.ksta /
	     2 + 1;
    ksta2 = dimen_1.ksta - dimen_1.ksta / 2;
    mg = ng - 1 + ksta2;
    if (statn_1.map1[k1 - 1] == 0) {
	goto L34;
    }
    if (statn_1.map1[k1 - 1] > ksta2) {
	goto L34;
    }
    is = ng - 1 + statn_1.map1[k1 - 1];
L17:
    a4_1.s[is - 1] = fix1_1.scale[4] * 1.f;
L34:
/* c */
/* c     store one line of G in GG: */
/* c */

/*      if(isingle.ne.0)then */
/*        do i1=1,4 */
/*            gg(i,i1)=s(i1) */
/*        enddo */
/* c         if(i.eq.knobs(1))then ! matrix GG is fully calculated */
/* c            call LSVDF(GG,100,knobs(1),4,BWK,1,0,SV,WK,ier) */
/* c            call ALESUBR(SV,4,ale(1)) */
/* cccccccc  test          ale(1)=-log10( sv(4) )   ! test test */
/* cccc            write(6,*) sv(1),sv(2),sv(3),sv(4), ale(1) */
/* c         endif */
/* c      endif */

/*     now accumulate normal equations (vector s contains the traveltime-derivs.) */

    accunormeqs_(a4_1.s, &dimen_1.nvar, &a4_1.res[*i__ + *neq * 650 - 651], &
	    obb_1.w[*i__ + *neq * 650 - 651], gmatrix_1.g, a4_1.rht);

    return 0;
} /* setupmatrixg_ */


/* of subr. setupmatrixg */
/* Subroutine */ int checksolution_(integer *istopflag, logical *better)
{
    /* Format strings */
    static char fmt_10[] = "(\002 DATVAR=\002,f12.6,\002 mean sqrd residua"
	    "l= \002,f12.6,\002  RMS RESIDUAL= \002,f12.6)";

    /* System generated locals */
    real r__1;

    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), do_fio(integer *
	    , char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal);
    integer do_lio(integer *, integer *, char *, ftnlen);

    /* Local variables */
    static integer decreasing;
    static real varat1, varat2;
    extern /* Subroutine */ int avresistatist_(void);
    static real datvar;
    extern /* Subroutine */ int gapcalc_(integer *);
    static real xmsqrs2;

    /* Fortran I/O blocks */
    static cilist io___966 = { 0, 16, 0, 0, 0 };
    static cilist io___967 = { 0, 16, 0, "(' Iteration nr ',i2,' obtained:')",
	     0 };
    static cilist io___968 = { 0, 16, 0, "('(Iteration nr ',i2,')   BACKUP n"
	    "r ',i1,                      ' obtained:')", 0 };
    static cilist io___969 = { 0, 16, 0, fmt_10, 0 };
    static cilist io___971 = { 0, 16, 0, 0, 0 };
    static cilist io___973 = { 0, 16, 0, "(' *** WARNING: the data variance "
	    "has increased.')", 0 };



/*     checks, whether the current solution is 'better' than the previous one. */
/*     'better' means here, that data variance has decreased. A warning is */
/*     output in case that although the data variance has decreased the RMS */
/*     didn't. */
/*     If datvar has decreased, the output-variable DECREASING is set to 1  . */


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


    decreasing = 0;
    *better = TRUE_;

    if (form_1.nitt == 0) {
	datvar = a3_1.davar1;
	xmsqrs2 = a3_1.xmsqrs1;
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___966);
	e_wsle();
	if (a3_1.ibackups == 0) {
	    s_wsfe(&io___967);
	    do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
	    e_wsfe();
	} else {
	    s_wsfe(&io___968);
	    do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&a3_1.ibackups, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	s_wsfe(&io___969);
	do_fio(&c__1, (char *)&a3_1.davar1, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&a3_1.xmsqrs1, (ftnlen)sizeof(real));
	r__1 = sqrt(a3_1.xmsqrs1);
	do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	e_wsfe();
    }

    if (coordsyst_1.isingle != 0) {
	gapcalc_(&c__1);
    }

    if (coordsyst_1.isingle == 0) {
	avresistatist_();
    }

/* ***  form ratio of old to new variance */
    varat1 = datvar / a3_1.davar1;

    if (coordsyst_1.isingle != 0) {
/* stop calc. for single event if changes get */
	if (form_1.nitt > 2 && (r__1 = datvar - a3_1.davar1, dabs(r__1)) < 
		1e-6f) {
	    *istopflag = 1;
	    if (! coordsyst_1.single_turbo__) {
		s_wsle(&io___971);
		do_lio(&c__9, &c__1, "Changes in datvar < 1e-6   : STOPPING."
			"..", (ftnlen)40);
		e_wsle();
	    }
	}
    }
/* *** form ratio of old to new mean sqrd residual */
    varat2 = xmsqrs2 / a3_1.xmsqrs1;
/* *** test to see if variance is increasing */
    if (varat1 >= .99f) {
	decreasing = 1;
	goto L1;
    }
/* *** test to see if mean sqrd residual is increasing */
    if (varat1 < .99f && varat2 >= .99f) {

/*       msqrd residual decreasing, but data variance increased: */

	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___973);
	    e_wsfe();
	}
	decreasing = 1;
	goto L1;
    }
    if (varat2 >= .99f) {
	decreasing = 1;
	goto L1;
    }

L1:
    if (decreasing == 1) {

/*        variance is decreasing: */

	datvar = a3_1.davar1;
	xmsqrs2 = a3_1.xmsqrs1;
    } else {

/*        variance increased so backup */

	*better = FALSE_;
    }

    return 0;

} /* checksolution_ */

/* of subr. checksolution */
/* Subroutine */ int traveltime_(integer *i__, integer *nobs, integer *
	iresflag)
{
    /* Format strings */
    static char fmt_1301[] = "(/,\002 event =\002,i5,\002 station \002,a4"
	    ",\002 num. raypoints= \002,i5)";
    static char fmt_1302[] = "(3(2x,3f7.2))";
    static char fmt_500[] = "(\002 ttt=\002,f10.5,\002 pobs= \002,f10.5,\002"
	    " res= \002,f10.5)";
    static char fmt_501[] = "(\002dtdr=\002,3f10.5)";
    static char fmt_502[] = "(\002dtdv=\002,7f10.5)";

    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3, r__4, r__5;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double asin(doublereal);
    integer i_nint(real *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle(void);

    /* Local variables */
    static real dtddrefl, dtdhrefl;
    extern /* Subroutine */ int layerhit_(real *, integer *, integer *, 
	    integer *, integer *), resisave_(integer *, integer *, real *, 
	    integer *, integer *, integer *, integer *);
    static integer nittdone, j;
    static real z__;
    static integer k1, k2;
    static real r1, r2, v1[100], x2[202], y2[202], z2[202];
    extern /* Subroutine */ int travderiv_(char *, integer *, integer *, real 
	    *, real *, real *, integer *, real *, real *, real *, real *, 
	    real *, real *, integer *, integer *, ftnlen);
    static integer ii, nl, ir;
    static real rp[606]	/* was [3][202] */, ss[202];
    static integer kk1, mll, nrp;
    static real tkh, ttt;
    static integer jzz;
    static real vsq1[100];
    extern /* Subroutine */ int resetstatis_(void);
    static integer do_s__, nrtn;
    static real ster, pobs;
    extern /* Subroutine */ int checkraypath_(real *, integer *);
    static real direr;
    extern /* Subroutine */ int chtop_(real *, real *, real *, char *, char *,
	     ftnlen, ftnlen);
    static real takeoff_angle__, ttt_s__;
    extern /* Subroutine */ int raypointcheck_(real *, integer *, char *, 
	    ftnlen);
    static real refler, dtdr_s__[3], refrer, dtdv_s__[100];
    static integer ifirst;
    static real extrat1, extrat2;
    extern /* Subroutine */ int bendray_(real *, integer *, char *, real *, 
	    real *, ftnlen);
    static integer nrpdeep;
    extern /* Subroutine */ int raypath_(integer *, integer *, integer *, 
	    real *, real *, real *, real *, integer *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *, real *, 
	    integer *, integer *, integer *, real *, integer *, real *, 
	    integer *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist io___999 = { 0, 13, 0, fmt_1301, 0 };
    static cilist io___1000 = { 0, 13, 0, fmt_1302, 0 };
    static cilist io___1002 = { 0, 13, 0, fmt_1302, 0 };
    static cilist io___1016 = { 0, 21, 0, 0, 0 };
    static cilist io___1017 = { 0, 21, 0, fmt_500, 0 };
    static cilist io___1018 = { 0, 21, 0, fmt_501, 0 };
    static cilist io___1020 = { 0, 21, 0, fmt_502, 0 };



/*     computes the forward problem: all the raytracing is done, traveltimes */
/*     AND traveltime-derivatives are calculated. Moreover, a whole bunch */
/*     of statistics is done here. */

/* cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc */
/*     Input parameter:                                            c */
/*                                                                 c */
/*     i          = ith event                                      c */
/*     nobs       = nr of obs for the ith event                    c */
/*     iresflag   = */
/* cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc */


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

/*     reset statistics-parameter if iteration is new */
/*     or if NITT is the same but all rays are shot again (e.g. after */
/*     model/hypocenter-backup) */

    if (coordsyst_1.isingle > 0) {
	if (obb_1.kpwt[*nobs + *i__ * 650 - 651] == 5) {
/* this is not a real phase!!! */
	    if (obb_1.w[*nobs + *i__ * 650 - 651] != 0.f) {
		s_stop("TRAVELTIME>>> error in obs-wt!", (ftnlen)30);
	    }
	    a4_1.res[*nobs + *i__ * 650 - 651] = 0.f;
	    for (ii = 1; ii <= 3; ++ii) {
		dttx_1.dtdr[ii - 1] = 0.f;
	    }
	    return 0;
	}
    }
    if (coordsyst_1.isingle == 0) {
	if (*i__ == 1 && *nobs == 1 && form_1.nitt > nittdone) {
	    ifirst = 1;
	}
/* 1st obs */
	if (*i__ == 1 && *nobs == 1 && form_1.nitt == nittdone) {
	    ifirst = 2;
	}
/* ifirst=1   --->  first of all the obs for the first time done in this iterat. */
/* ifirst=2   --->  first of all the obs for the 2nd time coming in this iterat. */
	if (form_1.nitt > nittdone || ifirst == 2) {
	    nittdone = form_1.nitt;
	    ifirst = 1;
	    resetstatis_();
	}
    }

/*     Reset s-p switch */

    do_s__ = 1;


/*    z -- event depth */
    z__ = event_1.e[(*i__ << 2) - 1];
/*    k2 -- velocity model number */
    k2 = obb_1.iphase[*nobs + *i__ * 650 - 651];
L10:
/*     nl -- number of layers for model k2 */
    nl = modela_1.nplay[k2 - 1];
/*    k1 -- station number */
    k1 = obb_1.istm[*nobs + *i__ * 650 - 651];
/*    v,vsq are the velocity and velocity squared */
/*     h(ii) is the depth to the top of layer ii */
/*     thk(ii) -- thickness of layer ii */

    i__1 = nl;
    for (ii = 1; ii <= i__1; ++ii) {
	layer_1.v[ii - 1] = layvel_1.vp[k2 + (ii << 1) - 3];
	v1[ii - 1] = layvel_1.vp[k2 + (ii << 1) - 3];
	if (modela_1.nsp == 3 && obb_1.sphase[*nobs + *i__ * 650 - 651] == 
		1.f) {
	    layer_1.v[ii - 1] = layvel_1.vp[k2 + (ii << 1) - 3] / 
		    layvel_1.vpvs;
	}
	if (modela_1.nsp == 3 && obb_1.sphase[*nobs + *i__ * 650 - 651] == 
		2.f) {
	    if (do_s__ == 1) {
		layer_1.v[ii - 1] = layvel_1.vp[k2 + (ii << 1) - 3] / 
			layvel_1.vpvs;
	    }
	}
/* Computing 2nd power */
	r__1 = layer_1.v[ii - 1];
	layer_1.vsq[ii - 1] = r__1 * r__1;
/* Computing 2nd power */
	r__1 = v1[ii - 1];
	vsq1[ii - 1] = r__1 * r__1;
	layer_1.h__[ii - 1] = layvel_1.hp[k2 + (ii << 1) - 3];
	layer_1.thk[ii - 1] = layvel_1.thkp[k2 + (ii << 1) - 3];
    }

/*     calculate tkh, r1,r2,delta : */

    ttt = 0.f;
    tkh = statn_1.x[k1 + 1299] - layer_1.h__[0];
/* distance from station up to top of model */
    r1 = event_1.e[(*i__ << 2) - 3] - statn_1.x[k1 - 1];
    r2 = event_1.e[(*i__ << 2) - 2] - statn_1.x[k1 + 649];
/* check if event too shallow */
    if (coordsyst_1.itopo > 0) {
	if (event_1.e[(*i__ << 2) - 1] < 0.f) {
/* depth above sea-level...so near surfac */
	    r__1 = -event_1.e[(*i__ << 2) - 3];
	    chtop_(&r__1, &event_1.e[(*i__ << 2) - 2], &param_1.zmin, 
		    infiles_1.topo1file, infiles_1.topo2file, (ftnlen)80, (
		    ftnlen)80);
/* zmin:==surface at this poi */
	} else {
	    param_1.zmin = param_1.zmininput;
/* depth below zero ... so zmin=zmininput */
	}
    }
    if (*i__ <= dimen_1.neqs) {
	if (event_1.e[(*i__ << 2) - 1] <= param_1.zmin) {
	    if (coordsyst_1.isingle == 0) {
		event_1.e[(*i__ << 2) - 1] = param_1.zmin + .1f;
	    }
/* earthquakes */
	    if (coordsyst_1.isingle != 0) {
		event_1.e[(*i__ << 2) - 1] = param_1.zmin + .011f;
	    }
/* earthquake, single ev */
	}
    } else {
	if (event_1.e[(*i__ << 2) - 1] <= param_1.zmin) {
	    event_1.e[(*i__ << 2) - 1] = param_1.zmin + .011f;
	}
/* shots */
    }
    if (param_1.ifixsolution > 0 && event_1.e[(*i__ << 2) - 1] <= 0.f) {
	event_1.e[(*i__ << 2) - 1] = param_1.zmin + .001f;
    }
/*                                                        !   min_depth allowed!! */
/* c      r3=(e(4,i)-x(k1,3)) */
/* fix de */
    layer_1.delta = sqrt(r1 * r1 + r2 * r2);

/*     set reflector-layer-boundary : */

    mll = 0;
    if (layvel_1.ireflector > 0) {
	if (obb_1.sphase[*nobs + *i__ * 650 - 651] == -1.f) {
	    mll = layvel_1.ireflector;
/* P is reflected at bottom of layer irefle */
	}
    }

/*     do the ray-tracing : */

    raypath_(&c__1, &c__1, &c__1, &c_b2405, &c_b2405, &c_b2405, &c_b2405, &nl,
	     layer_1.thk, layer_1.h__, layer_1.v, layer_1.vsq, &event_1.e[(*
	    i__ << 2) - 3], &event_1.e[(*i__ << 2) - 2], &event_1.e[(*i__ << 
	    2) - 1], &statn_1.x[k1 - 1], &statn_1.x[k1 + 649], &statn_1.x[k1 
	    + 1299], rp, &nrp, &nrtn, &layer_1.jl, &layer_1.tkj, &c__1, &ttt, 
	    &mll, &ster, &direr, &refrer, &refler, &dtddrefl, &dtdhrefl);

    checkraypath_(rp, &nrp);


/*     raypoints stored in RP [1st index: x,y,z; 2nd: raypt# (max. 2*nlay)] */
/*     nrp = nr of raypoints stored at moment in RP */

    if (coordsyst_1.itopo == 2) {
/* check each raypoint whether it is below surfac */
	raypointcheck_(rp, &nrp, charc_1.stn + (k1 - 1 << 2), (ftnlen)4);
    }

/*     if ray travels through the air, bend it below surface !!! */

    if (coordsyst_1.itopo == 3) {
	bendray_(rp, &nrp, charc_1.stn + (k1 - 1 << 2), layer_1.v, &ttt, (
		ftnlen)4);
    }

/*     sum raytracer-errors */


/*     For s-p phases the next statements should be done after the */
/*     p-wave calculation */

    if (obb_1.sphase[*nobs + *i__ * 650 - 651] != 2.f || do_s__ == 0) {
	if (coordsyst_1.isingle == 0) {
	    hitl_1.sterr += ster;
	    hitl_1.direrr += direr;
	    hitl_1.refrerr += refrer;
	    hitl_1.reflerr += refler;
	}

	if (coordsyst_1.isingle == 0) {
	    layerhit_(rp, &nrpdeep, &nl, &nrp, &mll);
	}

	if (outputfiles_1.irayout == 1) {
	    s_wsfe(&io___999);
	    do_fio(&c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
	    do_fio(&c__1, charc_1.stn + (k1 - 1 << 2), (ftnlen)4);
	    do_fio(&c__1, (char *)&nrp, (ftnlen)sizeof(integer));
	    e_wsfe();
	    if (coordsyst_1.icoordsystem == 2) {
		s_wsfe(&io___1000);
		i__1 = nrp;
		for (ir = 1; ir <= i__1; ++ir) {
		    r__1 = -rp[ir * 3 - 3];
		    do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&rp[ir * 3 - 2], (ftnlen)sizeof(
			    real));
		    do_fio(&c__1, (char *)&rp[ir * 3 - 1], (ftnlen)sizeof(
			    real));
		}
		e_wsfe();
	    } else {
		s_wsfe(&io___1002);
		i__1 = nrp;
		for (ir = 1; ir <= i__1; ++ir) {
		    do_fio(&c__1, (char *)&rp[ir * 3 - 3], (ftnlen)sizeof(
			    real));
		    do_fio(&c__1, (char *)&rp[ir * 3 - 2], (ftnlen)sizeof(
			    real));
		    do_fio(&c__1, (char *)&rp[ir * 3 - 1], (ftnlen)sizeof(
			    real));
		}
		e_wsfe();
	    }
	}
    }

/*     calculate traveltime-derivatives according to the raytype : */

/* if .NOT. ... */
    switch (nrtn) {
	case 1:  goto L5;
	case 2:  goto L5;
	case 3:  goto L6;
	case 4:  goto L6;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L5;
	case 8:  goto L8;
    }

/*   nrtn=8  if ray is reflected !! */
    s_stop("TRAVELTIME>>> illegal nrtn from raytracer!!!", (ftnlen)44);

L5:
    travderiv_("direct", &nl, &mll, v1, vsq1, rp, &nrp, x2, y2, z2, ss, &r1, &
	    r2, i__, nobs, (ftnlen)6);
    goto L40;
L6:
    travderiv_("refracted", &nl, &mll, v1, vsq1, rp, &nrp, x2, y2, z2, ss, &
	    r1, &r2, i__, nobs, (ftnlen)9);
    goto L40;
L8:
    travderiv_("reflected", &nl, &mll, v1, vsq1, rp, &nrp, x2, y2, z2, ss, &
	    r1, &r2, i__, nobs, (ftnlen)9);
L40:

/*     For s-p phases, the traveltime of the s-wave was calculated. Now */
/*     the p-wave calculation will be performed. */

    if (obb_1.sphase[*nobs + *i__ * 650 - 651] == 2.f && do_s__ == 1) {
	do_s__ = 0;
	ttt_s__ = ttt;
	for (ii = 1; ii <= 3; ++ii) {
	    dtdr_s__[ii - 1] = dttx_1.dtdr[ii - 1];
	}
	i__1 = nl;
	for (ii = 1; ii <= i__1; ++ii) {
	    dtdv_s__[ii - 1] = dttx_1.dtdv[ii - 1];
	}
	if (modela_1.nsp == 2) {
	    --k2;
	}
	goto L10;
    }
    if (obb_1.sphase[*nobs + *i__ * 650 - 651] == 2.f) {

/*        calculate the s-p traveltime derivative */

	for (ii = 1; ii <= 3; ++ii) {
	    dttx_1.dtdr[ii - 1] = dtdr_s__[ii - 1] - dttx_1.dtdr[ii - 1];
	}

/*        calculate the s-p time difference */

	ttt = ttt_s__ - ttt;
    }

/*     calculate residual by using appropriate station-corrections : */

    if (obb_1.sphase[*nobs + *i__ * 650 - 651] != 2.f) {
	pobs = obb_1.pt[*nobs + *i__ * 650 - 651] - event_1.e[(*i__ << 2) - 4]
		;
    } else {
	pobs = obb_1.pt[*nobs + *i__ * 650 - 651];
    }
    extrat1 = statn_1.ptcor[k1 - 1];
    extrat2 = 0.f;
    if (modela_1.nsp == 2 && obb_1.sphase[*nobs + *i__ * 650 - 651] == 1.f) {
	extrat1 = statn_1.stcor[k1 - 1];
    }
    if (modela_1.nsp == 2 && obb_1.sphase[*nobs + *i__ * 650 - 651] == 2.f) {
/* s-p phases */
	extrat1 = statn_1.stcor[k1 - 1] - statn_1.ptcor[k1 - 1];
    }
    if (modela_1.nsp == 3 && obb_1.sphase[*nobs + *i__ * 650 - 651] == 1.f) {
	extrat1 = statn_1.ptcor[k1 - 1] * layvel_1.vpvs;
    }
    if (modela_1.nsp == 3 && obb_1.sphase[*nobs + *i__ * 650 - 651] == 2.f) {
/* s-p phases */
	extrat1 = statn_1.ptcor[k1 - 1] * layvel_1.vpvs - statn_1.ptcor[k1 - 
		1];
    }
    if (dimen_1.nshcor == 0) {
	goto L600;
    }
    if (*i__ <= dimen_1.neqs) {
	goto L600;
    }
    kk1 = statn_1.map2[*i__ - dimen_1.neqs - 1];
    if (kk1 == 0) {
	goto L600;
    }
    i__1 = dimen_1.nsta;
    for (j = 1; j <= i__1; ++j) {
	if (kk1 == statn_1.map1[j - 1]) {
	    goto L602;
	}
/* L601: */
    }
    goto L600;

L602:
    extrat2 = statn_1.ptcor[j - 1];
    if (modela_1.nsp == 2 && obb_1.sphase[*nobs + *i__ * 650 - 651] == 1.f) {
	extrat2 = statn_1.stcor[j - 1];
    }
    if (modela_1.nsp == 3 && obb_1.sphase[*nobs + *i__ * 650 - 651] == 1.f) {
	extrat2 = statn_1.ptcor[j - 1] * layvel_1.vpvs;
    }
L600:
    a4_1.res[*nobs + *i__ * 650 - 651] = pobs - (ttt + extrat1 + extrat2);

    if (coordsyst_1.isingle != 0) {
	obb_1.tcalc[*nobs - 1] = ttt;
/* Computing 2nd power */
	r__1 = rp[3] - rp[0];
/* Computing 2nd power */
	r__2 = rp[4] - rp[1];
/* Computing 2nd power */
	r__3 = rp[3] - rp[0];
/* Computing 2nd power */
	r__4 = rp[4] - rp[1];
/* Computing 2nd power */
	r__5 = rp[5] - rp[2];
	takeoff_angle__ = sqrt(r__1 * r__1 + r__2 * r__2) / sqrt(r__3 * r__3 
		+ r__4 * r__4 + r__5 * r__5);
	takeoff_angle__ = asin(takeoff_angle__) * 57.296f;
	if (rp[5] - rp[2] < 0.f) {
	    takeoff_angle__ = 180.f - takeoff_angle__;
/* ray is going upwards */
	}
	obb_1.iain[*nobs - 1] = i_nint(&takeoff_angle__);
/* with respect to positive z; d */
    }

/* ---- save residual according to the ray-type: */

    if (coordsyst_1.isingle == 0) {
	resisave_(&nrp, &nrpdeep, rp, nobs, i__, &k1, &mll);
    }


/*     if VELEST is used in single-event-mode (isingle <> 0 ), */
/*     set weight to 0 if abs(residual) after 2nd iteration is still > 2. sec */
/*     ... and normalize the weights once more ! */
/*     --> if a reading with a reseted weight gets a residual which has */
/*         become small again, 'revive' it ! */

/* ek      if(isingle.ne.0)then */
/* ek         if(nitt.gt.2.and.abs(res(nobs,i)).gt.2.0 */
/* ek     &               .and.igap(i).lt.250)then */
/* ek            call REJECTOBS(i,nobs,iresflag) */
/* ek            call GAPCALC(1) */
/* ek         endif */
/* ek         if(nitt.gt.2.and.abs(res(nobs,i)).lt.1.0 */
/* ek     &               .and.igap(i).lt.250)then */
/* ek            if(w(nobs,i).eq.0.0)then */
/* ek               call REVIVEOBS(i,nobs,iresflag) */
/* ek               call GAPCALC(1) */
/* ek            endif */
/* ek         endif */
/* ek      endif */

    extra_1.tctime[*nobs + *i__ * 650 - 651] = ttt;
    layer_1.h__[0] = statn_1.x[k1 + 1299] - tkh;
/* reset h(1) after it has been altered in subr. r */
    layer_1.thk[0] += tkh;
    if (outputfiles_1.idrvout == 1) {
	s_wsle(&io___1016);
	do_lio(&c__9, &c__1, "i=", (ftnlen)2);
	do_lio(&c__3, &c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, "  nobs=", (ftnlen)7);
	do_lio(&c__3, &c__1, (char *)&(*nobs), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, "  nitt=", (ftnlen)7);
	do_lio(&c__3, &c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, "  nrtn=", (ftnlen)7);
	do_lio(&c__3, &c__1, (char *)&nrtn, (ftnlen)sizeof(integer));
	e_wsle();
	s_wsfe(&io___1017);
	do_fio(&c__1, (char *)&ttt, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&pobs, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (ftnlen)
		sizeof(real));
	e_wsfe();
	s_wsfe(&io___1018);
	for (jzz = 1; jzz <= 3; ++jzz) {
	    do_fio(&c__1, (char *)&dttx_1.dtdr[jzz - 1], (ftnlen)sizeof(real))
		    ;
	}
	e_wsfe();
	s_wsfe(&io___1020);
	i__1 = nl;
	for (jzz = 1; jzz <= i__1; ++jzz) {
	    do_fio(&c__1, (char *)&dttx_1.dtdv[jzz - 1], (ftnlen)sizeof(real))
		    ;
	}
	e_wsfe();
    }
/* L510: */
    return 0;
} /* traveltime_ */


/* of subr. traveltime */
/* Subroutine */ int resetstatis_(void)
{
    /* System generated locals */
    integer i__1;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *);

    /* Local variables */
    static integer ihitl, jhitl;


/*     called by subr. TRAVELTIME. The statistics-variables are reset here. */

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

    if (outputfiles_1.irflout == 1) {
	al__1.aerr = 0;
	al__1.aunit = 77;
	f_rew(&al__1);
    }
    if (outputfiles_1.irfrout == 1) {
	al__1.aerr = 0;
	al__1.aunit = 78;
	f_rew(&al__1);
    }
    if (outputfiles_1.iresout == 1) {
	al__1.aerr = 0;
	al__1.aunit = 79;
	f_rew(&al__1);
    }

    i__1 = modela_1.nltot;
    for (ihitl = 1; ihitl <= i__1; ++ihitl) {
	hitl_1.irefllayer[ihitl - 1] = 0;
	hitl_1.irefrlayer[ihitl - 1] = 0;
	hitl_1.refraylen[ihitl - 1] = 0.f;
	hitl_1.hitlay[ihitl - 1] = 0.f;
	hitl_1.hitlay[ihitl + 99] = 0.f;
	hitl_1.hitlay[ihitl + 199] = 0.f;
    }
    hitl_1.noheadwave = 0;
/* nr of straight & direct waves */
    hitl_1.avhraylen = 0.f;
/* average horiz. raylength */
    hitl_1.avvraylen = 0.f;
/*    "    vertic.    " */
    hitl_1.sterr = 0.f;
/* raytracer-errors */
    hitl_1.direrr = 0.f;
/*    " */
    hitl_1.refrerr = 0.f;
/*    " */
    hitl_1.reflerr = 0.f;
/*    " */
    residuals_1.avrefrres = 0.f;
/* average residual for this ray-type */
    residuals_1.avotheres = 0.f;
/*    " */
    residuals_1.avreflres = 0.f;
/*    " */
    residuals_1.abrefrres = 0.f;
/* average absolute residual for this ray type */
    residuals_1.abotheres = 0.f;
/*    " */
    residuals_1.abreflres = 0.f;
/*    " */
    residuals_1.nrrefrres = 0.f;
/* nr of residuals for this ray-type */
    residuals_1.nrotheres = 0.f;
/*    " */
    residuals_1.nrreflres = 0.f;
/*    " */
    i__1 = dimen_1.nsta;
    for (ihitl = 1; ihitl <= i__1; ++ihitl) {
	for (jhitl = 1; jhitl <= 8; ++jhitl) {
	    residuals_1.stnazires[ihitl + jhitl * 650 - 651] = 0.f;
	}
    }

    return 0;
} /* resetstatis_ */


/* of subr. resetstatis */
/* Subroutine */ int resisave_(integer *nrp, integer *nrpdeep, real *rp, 
	integer *nobs, integer *i__, integer *k1, integer *mll)
{
    /* System generated locals */
    real r__1, r__2, r__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double atan2(doublereal, doublereal), sqrt(doublereal);

    /* Local variables */
    static real azi, xxx, yyy, dist;
    static integer iazi;
    static real xhyp, yhyp, xstn, ystn;

    /* Fortran I/O blocks */
    static cilist io___1025 = { 0, 78, 0, "(2x,'RFR',3f10.3,'        .1')", 0 
	    };
    static cilist io___1026 = { 0, 78, 0, "(2x,'RFR',3f10.3,'        .1')", 0 
	    };
    static cilist io___1027 = { 0, 78, 0, "(2x,'RFR',3f10.3,'        .1')", 0 
	    };
    static cilist io___1028 = { 0, 77, 0, "(2x,'RFL',3f10.4,'        .1')", 0 
	    };
    static cilist io___1036 = { 0, 79, 0, "(1x,f6.2,2x,f7.3)", 0 };



/*     saves the residual according to the ray-type */


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

    /* Parameter adjustments */
    rp -= 4;

    /* Function Body */
    if (rp[*nrpdeep * 3 + 3] == rp[(*nrpdeep + 1) * 3 + 3]) {
/* ray is horizontal : ref */
	residuals_1.avrefrres += a4_1.res[*nobs + *i__ * 650 - 651];
/* refracted */
	residuals_1.abrefrres += (r__1 = a4_1.res[*nobs + *i__ * 650 - 651], 
		dabs(r__1));
/* refracted */
	++residuals_1.nrrefrres;

	if (layvel_1.lmax == 10) {
/* refractor is Moho... */
	    if (outputfiles_1.irfrout == 1) {

/*              write (x,y) of point A, where ray enters MOHO, */
/*              of point B, where ray leaves MOHO and of point between A and B */

		xxx = rp[*nrpdeep * 3 + 1];
		if (coordsyst_1.icoordsystem == 2) {
		    xxx = -xxx;
		}
		yyy = rp[*nrpdeep * 3 + 2];
		s_wsfe(&io___1025);
		do_fio(&c__1, (char *)&xxx, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&yyy, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (
			ftnlen)sizeof(real));
		e_wsfe();
		xxx = (rp[*nrpdeep * 3 + 1] + rp[(*nrpdeep + 1) * 3 + 1]) / 
			2.f;
		if (coordsyst_1.icoordsystem == 2) {
		    xxx = -xxx;
		}
		yyy = (rp[*nrpdeep * 3 + 2] + rp[(*nrpdeep + 1) * 3 + 2]) / 
			2.f;
		s_wsfe(&io___1026);
		do_fio(&c__1, (char *)&xxx, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&yyy, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (
			ftnlen)sizeof(real));
		e_wsfe();
		xxx = rp[(*nrpdeep + 1) * 3 + 1];
		if (coordsyst_1.icoordsystem == 2) {
		    xxx = -xxx;
		}
		yyy = rp[(*nrpdeep + 1) * 3 + 2];
		s_wsfe(&io___1027);
		do_fio(&c__1, (char *)&xxx, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&yyy, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (
			ftnlen)sizeof(real));
		e_wsfe();
	    }
	}

    } else {
	if (*mll == 0) {
	    residuals_1.avotheres += a4_1.res[*nobs + *i__ * 650 - 651];
/* straight or direct */
	    residuals_1.abotheres += (r__1 = a4_1.res[*nobs + *i__ * 650 - 
		    651], dabs(r__1));
/* straight or direct */
	    ++residuals_1.nrotheres;
	} else {
	    residuals_1.avreflres += a4_1.res[*nobs + *i__ * 650 - 651];
/* reflected */
	    residuals_1.abreflres += (r__1 = a4_1.res[*nobs + *i__ * 650 - 
		    651], dabs(r__1));
/* reflected */
	    ++residuals_1.nrreflres;

	    if (outputfiles_1.irflout == 1) {
		if (coordsyst_1.icoordsystem == 2) {
		    xxx = -rp[*nrpdeep * 3 + 1];
		} else {
		    xxx = rp[*nrpdeep * 3 + 1];
		}
		s_wsfe(&io___1028);
		r__1 = -rp[*nrpdeep * 3 + 1];
		do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&rp[*nrpdeep * 3 + 2], (ftnlen)sizeof(
			real));
		do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (
			ftnlen)sizeof(real));
		e_wsfe();
	    }
	}
    }

/*     save residual for station# k1 according to the azimuth: */

    xhyp = rp[4];
    yhyp = rp[5];
    xstn = rp[*nrp * 3 + 1];
    ystn = rp[*nrp * 3 + 2];
/*        Azimuth (stn --> hypoc) = 57.296*ATAN2(xhyp-xstn,yhyp-ystn) */
    azi = atan2(xhyp - xstn, yhyp - ystn) * 57.296f;
    if (azi < 0.f) {
	azi += 360.f;
    }
    iazi = 0;
    if (azi >= 0.f && azi < 90.f) {
	iazi = 1;
    }
    if (azi >= 90.f && azi < 180.f) {
	iazi = 2;
    }
    if (azi >= 180.f && azi < 270.f) {
	iazi = 3;
    }
    if (azi >= 270.f && azi <= 360.f) {
	iazi = 4;
    }
    residuals_1.stnazires[*k1 + ((iazi << 1) - 1) * 650 - 651] += a4_1.res[*
	    nobs + *i__ * 650 - 651];
    residuals_1.stnazires[*k1 + iazi * 1300 - 651] += 1.f;

/*     type residuals as a function of focus-receiver distance: */
    if (outputfiles_1.iresout == 1) {
/* Computing 2nd power */
	r__1 = rp[4] - rp[*nrp * 3 + 1];
/* Computing 2nd power */
	r__2 = rp[5] - rp[*nrp * 3 + 2];
/* Computing 2nd power */
	r__3 = rp[6] - rp[*nrp * 3 + 3];
	dist = r__1 * r__1 + r__2 * r__2 + r__3 * r__3;
	dist = sqrt(dist);
	s_wsfe(&io___1036);
	do_fio(&c__1, (char *)&dist, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (ftnlen)
		sizeof(real));
	e_wsfe();
    }

    return 0;
} /* resisave_ */


/* of subr. resisave */
/* Subroutine */ int adjustmodel_(real *damp)
{
    /* Format strings */
    static char fmt_40[] = "(\002 doing velocity adjustments now...\002)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), e_wsfe(void), 
	    do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, n;
    extern /* Subroutine */ int timeclear_(integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *);
    static integer j1, j2, k2, k1;
    static real cc[650];
    static integer j11, j22, jj, kj, kk1, jjj;
    static real dmin__;
    static integer ksta1, ksta2, itime;
    extern /* Subroutine */ int chtop_(real *, real *, real *, char *, char *,
	     ftnlen, ftnlen);
    extern integer juliam_(integer *, integer *, integer *, integer *, 
	    integer *);
    static integer iminold;

    /* Fortran I/O blocks */
    static cilist io___1047 = { 0, 16, 0, 0, 0 };
    static cilist io___1048 = { 0, 16, 0, fmt_40, 0 };
    static cilist io___1054 = { 0, 16, 0, "(1x,'WARNING: Tried to introduce "
	    "a ',                            'low-velocity-layer! (Layer ',i2"
	    ",')')", 0 };
    static cilist io___1055 = { 0, 16, 0, "(1x,'Setting DVP from ',f5.2,' to"
	    " 0.0 and',                    ' VP to vp(layer_above)+0.001')", 0 
	    };
    static cilist io___1056 = { 0, 6, 0, "(1x,'WARNING: Tried to introduce a"
	    " ',                             'low-velocity-layer! (Layer ',i2"
	    ",')')", 0 };
    static cilist io___1057 = { 0, 6, 0, "(1x,'Setting DVP from ',f5.2,' to "
	    "0.0 and',                     ' VP to vp(layer_above)+0.001')", 0 
	    };
    static cilist io___1058 = { 0, 6, 0, 0, 0 };
    static cilist io___1059 = { 0, 16, 0, 0, 0 };
    static cilist io___1060 = { 0, 16, 0, "(' doing station-correction adjus"
	    "tments...')", 0 };
    static cilist io___1061 = { 0, 16, 0, 0, 0 };



/*     adjust model-vector by the solution just obtained */


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

/*     adjust hypocenters of this iteration and output them: */

    jj = 0;

    i__1 = dimen_1.legs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	n = 4;
	if (i__ > dimen_1.neqs) {
	    n = 1;
	}
/* cc      call TIMECLEAR(iyr(i),imo(i),iday(i),ihr(i),imin(i),e(1,i),iminold) */
/* for shots adjust only the origin-time !!! */
	if (event_1.iyr[i__ - 1] < 100) {
	    i__2 = event_1.iyr[i__ - 1] + 1900;
	    iminold = juliam_(&i__2, &event_1.imo[i__ - 1], &event_1.iday[i__ 
		    - 1], &event_1.ihr[i__ - 1], &event_1.imin[i__ - 1]);
	} else {
	    iminold = juliam_(&event_1.iyr[i__ - 1], &event_1.imo[i__ - 1], &
		    event_1.iday[i__ - 1], &event_1.ihr[i__ - 1], &
		    event_1.imin[i__ - 1]);
	}
	i__2 = n;
	for (j = 1; j <= i__2; ++j) {
	    ++jj;
	    event_1.e[j + (i__ << 2) - 5] += a4_1.b[jj - 1];
	}
	if (event_1.e[(i__ << 2) - 4] < 0.f) {
/* change reference minute */
	    timeclear_(&event_1.iyr[i__ - 1], &event_1.imo[i__ - 1], &
		    event_1.iday[i__ - 1], &event_1.ihr[i__ - 1], &
		    event_1.imin[i__ - 1], &event_1.e[(i__ << 2) - 4], &itime)
		    ;
	    i__2 = obb_1.knobs[i__ - 1];
	    for (j = 1; j <= i__2; ++j) {
		obb_1.pt[j + i__ * 650 - 651] += (iminold - itime) * 60.f;
	    }
	}
	for (j = 1; j <= 3; ++j) {
	    event_1.isconstrain[j - 1] = 0;
	}
	event_1.iconstrain[i__ - 1] = 0;

/*     constrain focal depth if necessary */

	if (coordsyst_1.isingle != 0) {
	    if (form_1.nitt < 2) {
		event_1.isconstrain[0] = 1;
/*            write(16,*)' *** nitt<2 --> ', */
/*     &                 'depth-adjustment := 0.0 for event ',i */
		event_1.e[(i__ << 2) - 1] -= a4_1.b[3];
		a4_1.b[3] = 0.f;
	    }
	    if (gap_1.igap[0] > 250) {
		dmin__ = 999.9f;
/* minimum distance (epicenter --> receiver) */
		i__2 = obb_1.knobs[0];
		for (k = 1; k <= i__2; ++k) {
/* Computing 2nd power */
		    r__1 = event_1.e[1] - statn_1.d__[k - 1];
/* Computing 2nd power */
		    r__2 = event_1.e[2] - statn_1.d__[k + 649];
		    layer_1.delta = sqrt(r__1 * r__1 + r__2 * r__2);
		    if (layer_1.delta < dmin__) {
			dmin__ = layer_1.delta;
		    }
		}
		if (dmin__ > 15.f) {
		    event_1.isconstrain[1] = 1;
		    if (event_1.iconstrain[i__ - 1] == 1) {
			event_1.iconstrain[i__ - 1] = 3;
		    }
/*              write(16,*)' *** igap>250 --> ', */
/*     &                  'depth-adjustment := 0.0 for event ',i */
		    event_1.e[(i__ << 2) - 1] -= a4_1.b[3];
		    a4_1.b[3] = 0.f;
		}
	    }
	    if (dabs(a4_1.b[3]) > param_1.zadj) {
		event_1.isconstrain[2] = 1;
/*            write(16,*)' *** depth-adjustment constrained for event ',i */
		if (a4_1.b[3] > 0.f) {
		    event_1.e[(i__ << 2) - 1] = event_1.e[(i__ << 2) - 1] - 
			    a4_1.b[3] + param_1.zadj;
		    a4_1.b[3] = param_1.zadj;
		} else {
		    event_1.e[(i__ << 2) - 1] = event_1.e[(i__ << 2) - 1] - 
			    a4_1.b[3] - param_1.zadj;
		    a4_1.b[3] = -param_1.zadj;
		}
	    }
	} else {
/* simultanous inversion */
	    if (i__ <= dimen_1.neqs && (r__1 = a4_1.b[jj - 1], dabs(r__1)) > 
		    param_1.zadj) {
/* b(jj)=depth-adj. if */
		event_1.iconstrain[i__ - 1] = 1;
/*            write(16,*)' *** depth-adjustment constrained for event ',i */
		if (a4_1.b[jj - 1] > 0.f) {
		    event_1.e[(i__ << 2) - 1] = event_1.e[(i__ << 2) - 1] - 
			    a4_1.b[jj - 1] + param_1.zadj;
		    a4_1.b[jj - 1] = param_1.zadj;
		} else {
		    event_1.e[(i__ << 2) - 1] = event_1.e[(i__ << 2) - 1] - 
			    a4_1.b[jj - 1] - param_1.zadj;
		    a4_1.b[jj - 1] = -param_1.zadj;
		}
	    }
	}
/*      effdeltaz(i)=0.0 */
	if (coordsyst_1.itopo > 0) {
	    if (event_1.e[(i__ << 2) - 1] < 0.f) {
/* depth above sea-level...so near surfac */
		r__1 = -event_1.e[(i__ << 2) - 3];
		chtop_(&r__1, &event_1.e[(i__ << 2) - 2], &param_1.zmin, 
			infiles_1.topo1file, infiles_1.topo2file, (ftnlen)80, 
			(ftnlen)80);
/* zmin:==surface at this poi */
	    } else {
		param_1.zmin = 0.f;
/* depth below zero ... so zmin:==0.0 is sufficiant */
	    }
	}
	if (event_1.e[(i__ << 2) - 1] < param_1.zmin || param_1.ifixsolution 
		> 0 && event_1.e[(i__ << 2) - 1] <= 0.f) {
/*         effdeltaz(i)=b(jj)-(e(4,i)-zmin) */

/*        instead of calculating effdeltaz constrain adjustment-vector-element */
/*        b(jj) directly: */

	    a4_1.b[jj - 1] -= event_1.e[(i__ << 2) - 1] - param_1.zmin;

	    event_1.e[(i__ << 2) - 1] = param_1.zmin;
	    event_1.iconstrain[i__ - 1] = 1;
/*         write(16,'('' ***** depth constrained for event '',i5)') i */
	}

/* L29: */
    }

/*     all new hypocenters adjusted now. */


/*  do velocity adjustments here: */

/* loop over all events (adjust) */
    if (fix1_1.scale[5] == 0.f) {
	goto L44;
    }
/* no velocity-adjustments... */
    j1 = (dimen_1.neqs << 2) + dimen_1.nshot + 1;
    j2 = j1 + modela_1.nltot - 1;
    k = 0;
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1047);
	e_wsle();
	s_wsfe(&io___1048);
	e_wsfe();
    }

/*     do it for all velocity-models */

    i__1 = modela_1.nmod;
    for (i__ = 1; i__ <= i__1; ++i__) {
	k2 = modela_1.laysum[i__ - 1];
	j11 = j1 + k2 - 1;
	j22 = j11 + modela_1.nplay[i__ - 1] - 1;
	kj = 1;

/*     do it for all layers in this model ( = i ) */

	i__2 = j22;
	for (jjj = j11; jjj <= i__2; ++jjj) {
	    layvel_1.vp[i__ + (kj << 1) - 3] += a4_1.b[jjj - 1];

/*     If reflected phases are used, the velocity of the layer just above */
/*     the reflector is NOT allowed to have a lower velocity than any of */
/*     the above layers! */
/*     Because usually the reflector is almost at the bottom of the model, */
/*     namely the MOHO, we simplify the condition and don't allow any */
/*     low-velocity-layers at all in the whole model (of course  o n l y */
/*     if reflected phases are used in this VELEST-run !) */
/*   <<---- VELOCITY-ADJUSTMENT */
	    if (coordsyst_1.lowveloclay == 0) {
		if (kj > 1) {
		    if (layvel_1.vp[i__ + (kj << 1) - 3] < layvel_1.vp[i__ + (
			    kj - 1 << 1) - 3]) {
			if (! coordsyst_1.single_turbo__) {
			    s_wsfe(&io___1054);
			    do_fio(&c__1, (char *)&kj, (ftnlen)sizeof(integer)
				    );
			    e_wsfe();
			    s_wsfe(&io___1055);
			    do_fio(&c__1, (char *)&a4_1.b[jjj - 1], (ftnlen)
				    sizeof(real));
			    e_wsfe();
			}
			s_wsfe(&io___1056);
			do_fio(&c__1, (char *)&kj, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsfe(&io___1057);
			do_fio(&c__1, (char *)&a4_1.b[jjj - 1], (ftnlen)
				sizeof(real));
			e_wsfe();
			s_wsle(&io___1058);
			e_wsle();
			a4_1.b[jjj - 1] = 0.f;
			layvel_1.vp[i__ + (kj << 1) - 3] = layvel_1.vp[i__ + (
				kj - 1 << 1) - 3] + .001f;
		    }
		}
	    }

	    ++kj;
/* L42: */
	}

/* L4242: */
    }

/*     each velocity-model adjusted now. */

/*     adjust p- & s- station-corrections here: */

L44:
    if (fix1_1.scale[4] == 0.f) {
	goto L72;
    }
/* no station-correction adjustments... */
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1059);
	e_wsle();
	s_wsfe(&io___1060);
	e_wsfe();
	s_wsle(&io___1061);
	e_wsle();
    }
    k1 = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + 1;
    ksta1 = dimen_1.ksta;
    if (modela_1.nsp == 2) {
	ksta1 = dimen_1.ksta / 2;
    }
    k2 = k1 + ksta1 - 1;

/*     do p-correction for all stations: */

    i__1 = dimen_1.nsta;
    for (j = 1; j <= i__1; ++j) {
	cc[j - 1] = 0.f;
	if (statn_1.map1[j - 1] == 0) {
	    goto L49;
	}
	if (statn_1.map1[j - 1] > ksta1) {
	    goto L49;
	}
	kk1 = k1 - 1 + statn_1.map1[j - 1];
	cc[j - 1] = a4_1.b[kk1 - 1];
/*  STATION-CORRECTION- */
	statn_1.ptcor[j - 1] += cc[j - 1];
/*  ADJUSTMENT !!! (p-correction) */
L49:
	;
    }
    if (modela_1.nsp != 2) {
	goto L72;
    }
    k1 = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + 1 + ksta1;
    ksta2 = dimen_1.ksta - ksta1;
    k2 = k1 + ksta2 - 1;

/*     do s-correction for all stations: */

    i__1 = dimen_1.nsta;
    for (j = 1; j <= i__1; ++j) {
	cc[j - 1] = 0.f;
	if (statn_1.map1[j - 1] == 0) {
	    goto L74;
	}
	if (statn_1.map1[j - 1] > ksta2) {
	    goto L74;
	}
	kk1 = k1 - 1 + statn_1.map1[j - 1];
	cc[j - 1] = a4_1.b[kk1 - 1];
/* STATION-CORRECTION- */
	statn_1.stcor[j - 1] += cc[j - 1];
/* ADJUSTMENT !!! (s-correction) */
L74:
	;
    }

L72:

    return 0;

} /* adjustmodel_ */


/* of subr. adjustmodel */
/* Subroutine */ int rmsdatvar_(void)
{
    /* Format strings */
    static char fmt_310[] = "(/,\002 Total number of observations is: \002,i"
	    "5,/)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Local variables */
    static integer i__, j, j2, jj;
    static real tres;
    static integer knobst;

    /* Fortran I/O blocks */
    static cilist io___1073 = { 0, 16, 0, fmt_310, 0 };
    static cilist io___1074 = { 0, 16, 0, 0, 0 };
    static cilist io___1075 = { 0, 16, 0, 0, 0 };
    static cilist io___1076 = { 0, 16, 0, 0, 0 };
    static cilist io___1077 = { 0, 16, 0, 0, 0 };
    static cilist io___1078 = { 0, 16, 0, 0, 0 };
    static cilist io___1079 = { 0, 16, 0, 0, 0 };
    static cilist io___1080 = { 0, 16, 0, 0, 0 };
    static cilist io___1081 = { 0, 16, 0, "(' Event# ',i3,' >>> ',1x,3i2.2,1"
	    "x,2i2.2,                      '  AVRES =',f6.2,' NOBS =',i3)", 0 }
	    ;
    static cilist io___1082 = { 0, 16, 0, 0, 0 };
    static cilist io___1083 = { 0, 16, 0, 0, 0 };
    static cilist io___1084 = { 0, 16, 0, 0, 0 };
    static cilist io___1085 = { 0, 16, 0, 0, 0 };
    static cilist io___1086 = { 0, 16, 0, 0, 0 };



/*     compute RMS and DATVAR for all the events (EQs & shots) */

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


/*   now calculate rms for all events */

    jj = 0;
    a3_1.davar1 = 0.f;
    a3_1.xmsqrs1 = 0.f;
    tres = 0.f;
    knobst = 0;
    i__1 = dimen_1.legs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j2 = obb_1.knobs[i__ - 1];
	knobst += j2;
	i__2 = j2;
	for (j = 1; j <= i__2; ++j) {
	    if (obb_1.w[j + i__ * 650 - 651] <= 0.f) {
		goto L12;
	    }
	    a4_1.avres[i__ - 1] += a4_1.res[j + i__ * 650 - 651] * obb_1.w[j 
		    + i__ * 650 - 651];
/* ek  changed by ek to res*w*res*w::::> */
	    a4_1.rms[i__ - 1] += a4_1.res[j + i__ * 650 - 651] * a4_1.res[j + 
		    i__ * 650 - 651] * obb_1.w[j + i__ * 650 - 651] * obb_1.w[
		    j + i__ * 650 - 651];
L12:
	    ;
	}
	a3_1.davar1 += a4_1.rms[i__ - 1];
	tres += a4_1.avres[i__ - 1];
/* ek next statement */
	if (j2 - obb_1.nobswithw0 <= 1) {
	    goto L11;
	}
/* Computing 2nd power */
	r__1 = a4_1.avres[i__ - 1];
	a4_1.rms[i__ - 1] = sqrt((a4_1.rms[i__ - 1] - r__1 * r__1 / (j2 - 
		obb_1.nobswithw0)) / (j2 - obb_1.nobswithw0 - 1));
	a4_1.avres[i__ - 1] /= j2 - obb_1.nobswithw0;
L11:
	;
    }
    if (form_1.nitt == 0) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___1073);
	    do_fio(&c__1, (char *)&knobst, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    }
    if (form_1.nitt == 0 && coordsyst_1.isingle != 0) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___1074);
	    do_lio(&c__9, &c__1, "Number of observations with normalized wei"
		    "ght 0.0 :", (ftnlen)51);
	    do_lio(&c__3, &c__1, (char *)&obb_1.nobswithw0, (ftnlen)sizeof(
		    integer));
	    e_wsle();
	    s_wsle(&io___1075);
	    do_lio(&c__9, &c__1, "knobs(i)   = ", (ftnlen)13);
	    do_lio(&c__3, &c__1, (char *)&knobst, (ftnlen)sizeof(integer));
	    e_wsle();
	    s_wsle(&io___1076);
	    do_lio(&c__9, &c__1, "nobswithw0 = ", (ftnlen)13);
	    do_lio(&c__3, &c__1, (char *)&obb_1.nobswithw0, (ftnlen)sizeof(
		    integer));
	    e_wsle();
	}
    }

/*     calculate data variance: */

/*     NVAReff is the actual number of unknowns to solve for !!! */

    if (knobst - obb_1.nobswithw0 > dimen_1.nvareff) {
	a3_1.davar1 = (a3_1.davar1 - tres * tres / (knobst - obb_1.nobswithw0)
		) / (knobst - obb_1.nobswithw0 - dimen_1.nvareff);
	a3_1.xmsqrs1 = a3_1.davar1 * (knobst - obb_1.nobswithw0 - 
		dimen_1.nvareff) / (knobst - obb_1.nobswithw0);
    } else {
	a3_1.davar1 = 999.99f;
	a3_1.xmsqrs1 = 999.99f;
    }

    if (! coordsyst_1.single_turbo__) {
	if (coordsyst_1.isingle == 0) {
	    s_wsle(&io___1077);
	    e_wsle();
	    s_wsle(&io___1078);
	    do_lio(&c__9, &c__1, "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
		    "$$$$$$$", (ftnlen)49);
	    e_wsle();
	    s_wsle(&io___1079);
	    do_lio(&c__9, &c__1, "Events with  | AVRES | > 1.0 SEC are suspi"
		    "cious !", (ftnlen)49);
	    e_wsle();
	    s_wsle(&io___1080);
	    e_wsle();
	    j = 0;
	    i__1 = dimen_1.legs;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if ((r__1 = a4_1.avres[i__ - 1], dabs(r__1)) > 1.f) {
		    s_wsfe(&io___1081);
		    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&event_1.iyr[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&event_1.imo[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&event_1.iday[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&event_1.ihr[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&event_1.imin[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&a4_1.avres[i__ - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&c__1, (char *)&obb_1.knobs[i__ - 1], (ftnlen)
			    sizeof(integer));
		    e_wsfe();
		    ++j;
		}
	    }
	    if (j > 0) {
		s_wsle(&io___1082);
		e_wsle();
		s_wsle(&io___1083);
		do_lio(&c__9, &c__1, "^^^^^^^^^ C H E C K   these events abo"
			"ve ^^^^^^^^", (ftnlen)49);
		e_wsle();
		s_wsle(&io___1084);
		do_lio(&c__9, &c__1, "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
			"$$$$$$$$$$$", (ftnlen)49);
		e_wsle();
	    } else {
		s_wsle(&io___1085);
		do_lio(&c__9, &c__1, "ZERO events of this kind found! (lucky"
			" guy!!!)", (ftnlen)46);
		e_wsle();
	    }
	    s_wsle(&io___1086);
	    e_wsle();
	}
    }

    return 0;
} /* rmsdatvar_ */


/* of subr. rmsdatvar */
/* Subroutine */ int avresistatist_(void)
{
    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), do_fio(integer *
	    , char *, ftnlen), e_wsfe(void), do_lio(integer *, integer *, 
	    char *, ftnlen);

    /* Local variables */
    static real abtotres, avtotres;
    static integer nrtotres, ifirstrun;
    static real proz, oldres;

    /* Fortran I/O blocks */
    static cilist io___1087 = { 0, 16, 0, 0, 0 };
    static cilist io___1091 = { 0, 16, 0, "(1x,'After',i3,' iterations we go"
	    "t:')", 0 };
    static cilist io___1092 = { 0, 16, 0, 0, 0 };
    static cilist io___1093 = { 0, 16, 0, "(1x,i5,' straight and direct rays"
	    " =',f9.5,' [',f9.5,           ']')", 0 };
    static cilist io___1094 = { 0, 16, 0, "(1x,i5,' refracted           rays"
	    " =',f9.5,' [',f9.5,           ']')", 0 };
    static cilist io___1095 = { 0, 16, 0, "(1x,i5,' reflected           rays"
	    " =',f9.5,' [',f9.5,           ']')", 0 };
    static cilist io___1096 = { 0, 16, 0, 0, 0 };
    static cilist io___1100 = { 0, 16, 0, "(1x,i5,' ALL                 RAYS"
	    " =',f9.5,' [',f9.5,           ']',5x,f7.2,' %')", 0 };
    static cilist io___1101 = { 0, 16, 0, 0, 0 };



/*     compute average residual statistics for the iteration just finished */



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

    s_wsle(&io___1087);
    e_wsle();
    if (residuals_1.nrotheres > 0) {
	residuals_1.avotheres /= residuals_1.nrotheres;
    }
    if (residuals_1.nrotheres > 0) {
	residuals_1.abotheres /= residuals_1.nrotheres;
    }

    if (residuals_1.nrrefrres > 0) {
	residuals_1.avrefrres /= residuals_1.nrrefrres;
    }
    if (residuals_1.nrrefrres > 0) {
	residuals_1.abrefrres /= residuals_1.nrrefrres;
    }

    if (residuals_1.nrreflres > 0) {
	residuals_1.avreflres /= residuals_1.nrreflres;
    }
    if (residuals_1.nrreflres > 0) {
	residuals_1.abreflres /= residuals_1.nrreflres;
    }

    nrtotres = residuals_1.nrotheres + residuals_1.nrrefrres + 
	    residuals_1.nrreflres;

    if (nrtotres > 0) {
	abtotres = (residuals_1.abotheres * residuals_1.nrotheres + 
		residuals_1.abrefrres * residuals_1.nrrefrres + 
		residuals_1.abreflres * residuals_1.nrreflres) / nrtotres;
    }

    if (nrtotres > 0) {
	avtotres = (residuals_1.avotheres * residuals_1.nrotheres + 
		residuals_1.avrefrres * residuals_1.nrrefrres + 
		residuals_1.avreflres * residuals_1.nrreflres) / nrtotres;
    }

    s_wsfe(&io___1091);
    do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsle(&io___1092);
    do_lio(&c__9, &c__1, "Average absolute & unweighted [and mean] residual "
	    "of", (ftnlen)52);
    e_wsle();
    s_wsfe(&io___1093);
    do_fio(&c__1, (char *)&residuals_1.nrotheres, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&residuals_1.abotheres, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&residuals_1.avotheres, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsfe(&io___1094);
    do_fio(&c__1, (char *)&residuals_1.nrrefrres, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&residuals_1.abrefrres, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&residuals_1.avrefrres, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsfe(&io___1095);
    do_fio(&c__1, (char *)&residuals_1.nrreflres, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&residuals_1.abreflres, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&residuals_1.avreflres, (ftnlen)sizeof(real));
    e_wsfe();
    s_wsle(&io___1096);
    e_wsle();
    if (ifirstrun != 10000001) {
/* first run; no 'oldres' available.. */
	ifirstrun = 10000001;
	proz = 0.f;
    } else {
/* NOT the first time in this routine; proz may be calculated */
	if (dabs(oldres) > 1e-10f) {
	    proz = (abtotres - oldres) * 100.f / oldres;
	}
    }
    s_wsfe(&io___1100);
    do_fio(&c__1, (char *)&nrtotres, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&abtotres, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&avtotres, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&proz, (ftnlen)sizeof(real));
    e_wsfe();
    oldres = abtotres;
    s_wsle(&io___1101);
    e_wsle();

    return 0;
} /* avresistatist_ */


/* of subr. avresistatist */
/* Subroutine */ int gapcalc_(integer *i__)
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double atan2(doublereal, doublereal);

    /* Local variables */
    static real dxstnhyp, dystnhyp;
    static integer j, ig, iga[200];
    static real xhyp, yhyp, xstn, ystn;
    extern /* Subroutine */ int sorti_(integer *, integer *);
    static integer nofgaps;

    /* Fortran I/O blocks */
    static cilist io___1102 = { 0, 16, 0, 0, 0 };
    static cilist io___1103 = { 0, 16, 0, 0, 0 };
    static cilist io___1104 = { 0, 16, 0, 0, 0 };
    static cilist io___1105 = { 0, 16, 0, 0, 0 };
    static cilist io___1106 = { 0, 6, 0, 0, 0 };
    static cilist io___1107 = { 0, 6, 0, 0, 0 };
    static cilist io___1108 = { 0, 6, 0, 0, 0 };
    static cilist io___1118 = { 0, 6, 0, 0, 0 };
    static cilist io___1119 = { 0, 16, 0, 0, 0 };



/*     determine GAP for one event */

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


/*     event: i  knobs(i)  +/-e(2,i)=x    e(3,i)=y    x=+/-x(nsta,1)  y=...,2) */
/*     station# are stored in array  ISTM(iobs,ievent) */

/* ---- compute GAP for this event */
/*  max. 200 obs. for a single event */
    if (obb_1.knobs[*i__ - 1] > 200) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___1102);
	    do_lio(&c__9, &c__1, " WARNING:", (ftnlen)9);
	    e_wsle();
	    s_wsle(&io___1103);
	    do_lio(&c__9, &c__1, " Event# ", (ftnlen)8);
	    do_lio(&c__3, &c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, "   Nobs = ", (ftnlen)10);
	    do_lio(&c__3, &c__1, (char *)&obb_1.knobs[*i__ - 1], (ftnlen)
		    sizeof(integer));
	    do_lio(&c__9, &c__1, " > 200 !!!", (ftnlen)10);
	    e_wsle();
	    s_wsle(&io___1104);
	    do_lio(&c__9, &c__1, " Array IGA(100) is too small; redimension "
		    "it in", (ftnlen)47);
	    e_wsle();
	    s_wsle(&io___1105);
	    do_lio(&c__9, &c__1, " subr. GAPCALC", (ftnlen)14);
	    e_wsle();
	}
	s_wsle(&io___1106);
	do_lio(&c__9, &c__1, " Event# ", (ftnlen)8);
	do_lio(&c__3, &c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, "   Nobs = ", (ftnlen)10);
	do_lio(&c__3, &c__1, (char *)&obb_1.knobs[*i__ - 1], (ftnlen)sizeof(
		integer));
	do_lio(&c__9, &c__1, " > 200 !!!", (ftnlen)10);
	e_wsle();
	s_wsle(&io___1107);
	do_lio(&c__9, &c__1, " Array IGA(200) is too small; redimension it in"
		, (ftnlen)47);
	e_wsle();
	s_wsle(&io___1108);
	do_lio(&c__9, &c__1, " subr. GAPCALC", (ftnlen)14);
	e_wsle();
	s_stop("subr. GAPCALC >>> array IGA is too small !", (ftnlen)42);
    }
    nofgaps = 0;
    i__1 = obb_1.knobs[*i__ - 1];
    for (j = 1; j <= i__1; ++j) {
	if (obb_1.w[j + *i__ * 650 - 651] > 0.f) {
	    ++nofgaps;
	    xstn = statn_1.x[obb_1.istm[j + *i__ * 650 - 651] - 1];
	    ystn = statn_1.x[obb_1.istm[j + *i__ * 650 - 651] + 649];
	    xhyp = event_1.e[(*i__ << 2) - 3];
	    yhyp = event_1.e[(*i__ << 2) - 2];
/* ek    avoiding call to atan2(zero,zero) */
/* ek              write(6,*) ' Gapcalc: i,nofgaps,xstn,ystn,xhyp,yhyp' */
/* ek              write(6,'(1x,i4,2x,i3,2x,4f10.3)') i,nofgaps, */
/* ek     +                  xstn,ystn,xhyp,yhyp */
	    dxstnhyp = (r__1 = xstn - xhyp, dabs(r__1));
	    dystnhyp = (r__1 = ystn - yhyp, dabs(r__1));
	    if (dxstnhyp > 1e-4f || dystnhyp > 1e-4f) {
		iga[nofgaps - 1] = atan2(xstn - xhyp, ystn - yhyp) * 57.296f;
	    } else {
		iga[nofgaps - 1] = 359;
	    }
/* ek */
	    if (iga[nofgaps - 1] < 0) {
		iga[nofgaps - 1] += 360;
	    }
	}
    }
    if (nofgaps > 0) {
	sorti_(iga, &nofgaps);
    } else {
	s_wsle(&io___1118);
	do_lio(&c__9, &c__1, "WARNING: Event-# :", (ftnlen)18);
	do_lio(&c__3, &c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, "has zero observations!", (ftnlen)22);
	e_wsle();
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___1119);
	    do_lio(&c__9, &c__1, "WARNING: Event-# :", (ftnlen)18);
	    do_lio(&c__3, &c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, "has zero observations!", (ftnlen)22);
	    e_wsle();
	}
    }
    gap_1.igap[*i__ - 1] = 0;
    ig = iga[0] - iga[nofgaps - 1];
    if (ig < 0) {
	ig += 360;
    }
    if (ig > gap_1.igap[*i__ - 1]) {
	gap_1.igap[*i__ - 1] = ig;
    }
    i__1 = nofgaps;
    for (j = 2; j <= i__1; ++j) {
	ig = iga[j - 1] - iga[j - 2];
	if (ig < 0) {
	    ig += 360;
	}
	if (ig > gap_1.igap[*i__ - 1]) {
	    gap_1.igap[*i__ - 1] = ig;
	}
    }
/* ---- IGAP(i) is the gap of this event (nr. i) */

    return 0;
} /* gapcalc_ */


/* of subr. gapcalc */
/* Subroutine */ int backup_(void)
{
    /* Format strings */
    static char fmt_3[] = "(1x,\002Velocity readjustments:\002)";
    static char fmt_27[] = "(1x,\002Velocity model\002,i4)";
    static char fmt_5[] = "(1x,3f7.3,3x,a1)";
    static char fmt_8[] = "(5(2x,a4,2f7.3))";
    static char fmt_39[] = "(1x,\002S correction readjustments:\002)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Local variables */
    static integer i__, j, k, m, n, j1, k2, j2, k1;
    static real cc[650];
    static integer nl, kk1, ifl, jjj;
    static real zzz;
    static integer iccc, ksta1, ksta2;
    static real avelo;
    extern /* Subroutine */ int chtop_(real *, real *, real *, char *, char *,
	     ftnlen, ftnlen);
    static char reflch[1];

    /* Fortran I/O blocks */
    static cilist io___1131 = { 0, 16, 0, fmt_3, 0 };
    static cilist io___1132 = { 0, 16, 0, fmt_27, 0 };
    static cilist io___1133 = { 0, 16, 0, 0, 0 };
    static cilist io___1134 = { 0, 16, 0, "(1x,'WARNING: Tried to introduce "
	    "a ',                            'low-velocity-layer! (Layer ',i2"
	    ",')')", 0 };
    static cilist io___1135 = { 0, 16, 0, "(1x,'Setting DVP from ',f5.2,' to"
	    " 0.0 and',                    ' VP to vp(layer_above)+0.001')", 0 
	    };
    static cilist io___1136 = { 0, 6, 0, "(1x,'WARNING: Tried to introduce a"
	    " ',                             'low-velocity-layer! (Layer ',i2"
	    ",')')", 0 };
    static cilist io___1137 = { 0, 6, 0, "(1x,'Setting DVP from ',f5.2,' to "
	    "0.0 and',                     ' VP to vp(layer_above)+0.001')", 0 
	    };
    static cilist io___1138 = { 0, 6, 0, 0, 0 };
    static cilist io___1140 = { 0, 16, 0, fmt_5, 0 };
    static cilist io___1142 = { 0, 16, 0, 0, 0 };
    static cilist io___1143 = { 0, 16, 0, 0, 0 };
    static cilist io___1145 = { 0, 16, 0, "(' z =',f6.2,' ...',f6.2,'    v ="
	    " ',f4.2,                   '    AVEL = ',f4.2,' downto z = ',f6."
	    "2)", 0 };
    static cilist io___1146 = { 0, 16, 0, 0, 0 };
    static cilist io___1147 = { 0, 16, 0, 0, 0 };
    static cilist io___1148 = { 0, 16, 0, 0, 0 };
    static cilist io___1149 = { 0, 16, 0, "(' z =',f6.2,' ...',f6.2,'    v ="
	    " ',f4.2,                   '    AVEL = ',f4.2,' downto z = ',f6."
	    "2)", 0 };
    static cilist io___1150 = { 0, 16, 0, 0, 0 };
    static cilist io___1151 = { 0, 16, 0, 0, 0 };
    static cilist io___1157 = { 0, 16, 0, fmt_8, 0 };
    static cilist io___1159 = { 0, 16, 0, 0, 0 };
    static cilist io___1160 = { 0, 16, 0, 0, 0 };
    static cilist io___1162 = { 0, 16, 0, fmt_39, 0 };
    static cilist io___1163 = { 0, 16, 0, fmt_8, 0 };
    static cilist io___1164 = { 0, 16, 0, 0, 0 };
    static cilist io___1165 = { 0, 16, 0, 0, 0 };



/*     go back in direction of the previous solution by doing */
/*     only half of the adjustments calculated in the last iteration */

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


    jjj = 0;
    i__1 = dimen_1.legs;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* ---------- hypocenter backup */
	n = 4;

	if (i__ > dimen_1.neqs) {
	    n = 1;
	}
	i__2 = n;
	for (k = 1; k <= i__2; ++k) {
	    ++jjj;
	    a4_1.b[jjj - 1] /= 2.f;
	    if (k == 4) {

/*     concept of effdeltaz no longer in use! */

/*         if(effdeltaz(i).eq.0.0)then */
/* backup depth */
		event_1.e[k + (i__ << 2) - 5] -= a4_1.b[jjj - 1];
/*         else */
/*            effdeltaz(i)=effdeltaz(i)/2.0 */
/*            e(k,i)=e(k,i)-effdeltaz(i)           !  depth was constrained: */
/*         endif                                   ! go back only half of the */
/* depth not constrained */
		if (coordsyst_1.itopo > 0 && event_1.e[k + (i__ << 2) - 5] < 
			0.f) {
/*           depth above zero... is it also above surface? */
		    r__1 = -event_1.e[(i__ << 2) - 3];
		    chtop_(&r__1, &event_1.e[(i__ << 2) - 2], &zzz, 
			    infiles_1.topo1file, infiles_1.topo2file, (ftnlen)
			    80, (ftnlen)80);
		    if (event_1.e[k + (i__ << 2) - 5] < zzz) {
			event_1.e[k + (i__ << 2) - 5] = zzz;
		    }
/* set hypocenter down to surfa */
		    if (param_1.ifixsolution > 0) {
			event_1.e[k + (i__ << 2) - 5] = zzz;
		    }
/* fix depth to min_depth al */
		}
	    } else {
/* effective depth-chang */
		event_1.e[k + (i__ << 2) - 5] -= a4_1.b[jjj - 1];
	    }
/* L2: */
	}
    }
/* cc      iccc=mod((nitt-1),invertratio) */
    iccc = form_1.nitt % param_1.invertratio;
    if (iccc != 0) {
	goto L510;
    }
/* ---- velocity readjustments for each model */
    i__2 = modela_1.nmod;
    for (k2 = 1; k2 <= i__2; ++k2) {
	nl = modela_1.nplay[k2 - 1];
	j1 = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.laysum[k2 - 1];
	j2 = j1 - 1 + nl;
	k = 0;
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___1131);
	    e_wsfe();
	    s_wsfe(&io___1132);
	    do_fio(&c__1, (char *)&k2, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	i__1 = j2;
	for (jjj = j1; jjj <= i__1; ++jjj) {
	    ++k;
	    a4_1.b[jjj - 1] /= 2.f;
	    layvel_1.vp[k2 + (k << 1) - 3] -= a4_1.b[jjj - 1];
	    if (coordsyst_1.lowveloclay == 0) {
		if (k > 1) {
		    if (layvel_1.vp[k2 + (k << 1) - 3] < layvel_1.vp[k2 + (k 
			    - 1 << 1) - 3]) {
			if (! coordsyst_1.single_turbo__) {
			    s_wsle(&io___1133);
			    do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
			    e_wsle();
			    s_wsfe(&io___1134);
			    do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer))
				    ;
			    e_wsfe();
			    s_wsfe(&io___1135);
			    do_fio(&c__1, (char *)&a4_1.b[jjj - 1], (ftnlen)
				    sizeof(real));
			    e_wsfe();
			}
			s_wsfe(&io___1136);
			do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
			e_wsfe();
			s_wsfe(&io___1137);
			do_fio(&c__1, (char *)&a4_1.b[jjj - 1], (ftnlen)
				sizeof(real));
			e_wsfe();
			s_wsle(&io___1138);
			e_wsle();
			a4_1.b[jjj - 1] = 0.f;
			layvel_1.vp[k2 + (k << 1) - 3] = layvel_1.vp[k2 + (k 
				- 1 << 1) - 3] + .001f;
		    }
		}
	    }
/* L5: */
	    if (k == layvel_1.ireflector) {
		*(unsigned char *)reflch = *(unsigned char *)
			layvel_1.reflchar;
	    }
	    if (k != layvel_1.ireflector) {
		*(unsigned char *)reflch = ' ';
	    }
	    if (! coordsyst_1.single_turbo__) {
		s_wsfe(&io___1140);
		do_fio(&c__1, (char *)&layvel_1.vp[k2 + (k << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&a4_1.b[jjj - 1], (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[k2 + (k << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, reflch, (ftnlen)1);
		e_wsfe();
	    }
/* L4: */
	}

/*    calculate and print average velocities of the model k2 : */

	if (! coordsyst_1.single_turbo__) {
	    ifl = 1;
	    s_wsle(&io___1142);
	    e_wsle();
	    s_wsle(&io___1143);
	    do_lio(&c__9, &c__1, "Calculation of average velocity starts at "
		    "layer # ", (ftnlen)50);
	    do_lio(&c__3, &c__1, (char *)&ifl, (ftnlen)sizeof(integer));
	    e_wsle();
	    avelo = 0.f;
	    i__1 = modela_1.nplay[k2 - 1];
	    for (k = ifl + 1; k <= i__1; ++k) {
		avelo += (layvel_1.hp[k2 + (k << 1) - 3] - layvel_1.hp[k2 + (
			k - 1 << 1) - 3]) * layvel_1.vp[k2 + (k - 1 << 1) - 3]
			;
		s_wsfe(&io___1145);
		do_fio(&c__1, (char *)&layvel_1.hp[k2 + (k - 1 << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[k2 + (k << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.vp[k2 + (k - 1 << 1) - 3], (
			ftnlen)sizeof(real));
		r__1 = avelo / (layvel_1.hp[k2 + (k << 1) - 3] - layvel_1.hp[
			k2 + (ifl << 1) - 3]);
		do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[k2 + (k << 1) - 3], (
			ftnlen)sizeof(real));
		e_wsfe();
	    }
	    s_wsle(&io___1146);
	    e_wsle();

	    ifl = 2;
	    s_wsle(&io___1147);
	    e_wsle();
	    s_wsle(&io___1148);
	    do_lio(&c__9, &c__1, "Calculation of average velocity starts at "
		    "layer # ", (ftnlen)50);
	    do_lio(&c__3, &c__1, (char *)&ifl, (ftnlen)sizeof(integer));
	    e_wsle();
	    avelo = 0.f;
	    i__1 = modela_1.nplay[k2 - 1];
	    for (k = ifl + 1; k <= i__1; ++k) {
		avelo += (layvel_1.hp[k2 + (k << 1) - 3] - layvel_1.hp[k2 + (
			k - 1 << 1) - 3]) * layvel_1.vp[k2 + (k - 1 << 1) - 3]
			;
		s_wsfe(&io___1149);
		do_fio(&c__1, (char *)&layvel_1.hp[k2 + (k - 1 << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[k2 + (k << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.vp[k2 + (k - 1 << 1) - 3], (
			ftnlen)sizeof(real));
		r__1 = avelo / (layvel_1.hp[k2 + (k << 1) - 3] - layvel_1.hp[
			k2 + (ifl << 1) - 3]);
		do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[k2 + (k << 1) - 3], (
			ftnlen)sizeof(real));
		e_wsfe();
	    }
	    s_wsle(&io___1150);
	    e_wsle();
	    s_wsle(&io___1151);
	    e_wsle();
	}

/* L26: */
    }
L510:
    if (dimen_1.nsinv == 0) {
	goto L511;
    }
/* cc      if(mod((nitt-1),invertratio).ne.0) goto 511 */
    if (form_1.nitt % param_1.invertratio != 0) {
	goto L511;
    }
    k1 = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + 1;
    ksta1 = dimen_1.ksta;
    if (modela_1.nsp == 2) {
	ksta1 = dimen_1.ksta / 2;
    }
    k2 = k1 + ksta1 - 1;
    i__2 = k2;
    for (j = k1; j <= i__2; ++j) {
/* L60: */
	a4_1.b[j - 1] /= 2.f;
    }
    i__2 = dimen_1.nsta;
    for (j = 1; j <= i__2; ++j) {
	cc[j - 1] = 0.f;
	if (statn_1.map1[j - 1] == 0) {
	    goto L7;
	}
	if (statn_1.map1[j - 1] > ksta1) {
	    goto L7;
	}
	kk1 = k1 - 1 + statn_1.map1[j - 1];
	cc[j - 1] = a4_1.b[kk1 - 1];
	statn_1.ptcor[j - 1] -= cc[j - 1];
L7:
	;
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___1157);
	i__2 = dimen_1.nsta;
	for (m = 1; m <= i__2; ++m) {
	    do_fio(&c__1, charc_1.stn + (m - 1 << 2), (ftnlen)4);
	    do_fio(&c__1, (char *)&statn_1.ptcor[m - 1], (ftnlen)sizeof(real))
		    ;
	    do_fio(&c__1, (char *)&cc[m - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* L6: */
	s_wsle(&io___1159);
	e_wsle();
	s_wsle(&io___1160);
	do_lio(&c__9, &c__1, "Half adjustments made", (ftnlen)21);
	e_wsle();
    }
    if (modela_1.nsp != 2) {
	goto L29;
    }
    k1 = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + ksta1 + 1;
    ksta2 = dimen_1.ksta - ksta1;
    k2 = k1 + ksta2 - 1;
    i__2 = k2;
    for (j = k1; j <= i__2; ++j) {
/* L61: */
	a4_1.b[j - 1] /= 2.f;
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___1162);
	e_wsfe();
    }
    i__2 = dimen_1.nsta;
    for (j = 1; j <= i__2; ++j) {
	cc[j - 1] = 0.f;
	if (statn_1.map1[j - 1] == 0) {
	    goto L28;
	}
	if (statn_1.map1[j - 1] > ksta2) {
	    goto L28;
	}
	kk1 = k1 - 1 + statn_1.map1[j - 1];
	cc[j - 1] = a4_1.b[kk1 - 1];
	statn_1.stcor[j - 1] -= cc[j - 1];
L28:
	;
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___1163);
	i__2 = dimen_1.nsta;
	for (m = 1; m <= i__2; ++m) {
	    do_fio(&c__1, charc_1.stn + (m - 1 << 2), (ftnlen)4);
	    do_fio(&c__1, (char *)&statn_1.stcor[m - 1], (ftnlen)sizeof(real))
		    ;
	    do_fio(&c__1, (char *)&cc[m - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
    }
L511:
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1164);
	e_wsle();
	s_wsle(&io___1165);
	do_lio(&c__9, &c__1, "Half adjustments made", (ftnlen)21);
	e_wsle();
    }
L29:

    return 0;
} /* backup_ */


/* of subr. backup */
/* Subroutine */ int steplengthdamp_(real *damp)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Local variables */
    static integer i__, j11, j22, jjj;
    static real btemp;


/*     set step length damping to model-vector in case of LARGE VELOCITY CHANGE */
/*     (  | deltavelocity |   >   MAXveladjALLOWED  ) */

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

    *damp = 1.f;
    if (dimen_1.icount == 1) {
	goto L900;
    }
    if (fix1_1.scale[5] == 0.f) {
	goto L900;
    }
    i__1 = modela_1.nmod;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j11 = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.laysum[i__ - 1];
	j22 = j11 + modela_1.nplay[i__ - 1] - 1;
	i__2 = j22;
	for (jjj = j11; jjj <= i__2; ++jjj) {
	    if (param_1.veladj > (r__1 = a4_1.b[jjj - 1], dabs(r__1))) {
		goto L121;
	    }
	    btemp = param_1.veladj / (r__1 = a4_1.b[jjj - 1], dabs(r__1));
/* ABS[b(jjj)] > veladj --> damping */
	    if (btemp < *damp) {
		*damp = btemp;
	    }
/* eff. damping=smallest of all */
L121:
	    ;
	}
    }

/*     apply step length damping just calculated to ALL unknowns !!! : */

    i__1 = dimen_1.nvar;
    for (jjj = 1; jjj <= i__1; ++jjj) {
	a4_1.b[jjj - 1] *= *damp;
    }
L900:

    return 0;
} /* steplengthdamp_ */


/* of subr. steplengthdamp */
/* Subroutine */ int steplengthcalc_(void)
{
    /* Format strings */
    static char fmt_53[] = "(\002 (Applied) Step length = \002,f7.3/)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), do_fio(integer *
	    , char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__;

    /* Fortran I/O blocks */
    static cilist io___1172 = { 0, 16, 0, 0, 0 };
    static cilist io___1173 = { 0, 16, 0, fmt_53, 0 };



/*     compute the step-length STEPLEN actually applied; */
/*     STEPLEN is the euclidean length of the model-vector */

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

/* u      real csum(4,2) */

    a4_1.steplen = 0.f;
/* u      bsum=0 */
/* u      k=0 */
/* u      do j=1,4 */
/* u         csum(j,1)=0.0 */
/* u      enddo */
    i__1 = dimen_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* u        k=k+1 */
/* u        if(i.le.4*neqs) csum(k,1)=csum(k,1)+b(i) ! CSUM is never used...!!??!! */
/* u        if(nitt.eq.1) csum(k,2)=csum(k,1) */
/* u        if(k.eq.4) k=0 */
/* u        if(i.gt.4*neqs+nshot) bsum=bsum+b(i)  ! BSUM is never used... !!??!! */
	a4_1.steplen += a4_1.b[i__ - 1] * a4_1.b[i__ - 1];
    }
    a4_1.steplen = sqrt(a4_1.steplen);
    if (a3_1.ibackups > 0) {
	a4_1.steplen = -a4_1.steplen;
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1172);
	e_wsle();
	s_wsfe(&io___1173);
	do_fio(&c__1, (char *)&a4_1.steplen, (ftnlen)sizeof(real));
	e_wsfe();
    }

    return 0;
} /* steplengthcalc_ */


/* of subr. steplengthcalc */
/* Subroutine */ int resolcovar_(real *davari)
{
    /* Format strings */
    static char fmt_40[] = "(\002 Resolution and covariance calculations:"
	    "\002)";
    static char fmt_17[] = "(1x,\002resolution row\002,i3)";
    static char fmt_18[] = "(8f10.4)";
    static char fmt_20[] = "(1x,\002covariance row\002,i3)";
    static char fmt_21[] = "(\002 standard deviation of selected model param"
	    "eters:\002)";
    static char fmt_22[] = "(8f10.4)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), s_wsle(cilist *), do_lio(integer *
	    , integer *, char *, ftnlen), e_wsle(void), do_fio(integer *, 
	    char *, ftnlen), s_wsfi(icilist *), e_wsfi(void);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l, n1, n2, n3, mef, nef;
    static real size, rdiag[24799];
    static char pcard[80];
    static real scale1;
    extern /* Subroutine */ int luelmp_(real *, real *, integer *, real *), 
	    fixunt_(real *, integer *, integer *, integer *, integer *, real *
	    , real *, integer *, integer *, integer *);
    static real spread1, spread2;
    extern /* Subroutine */ int spreadb_(real *, integer *, real *), spreadd_(
	    real *, integer *, real *);
    static real avresol;

    /* Fortran I/O blocks */
    static cilist io___1174 = { 0, 16, 0, "(/////)", 0 };
    static cilist io___1175 = { 0, 16, 0, fmt_40, 0 };
    static cilist io___1176 = { 0, 16, 0, 0, 0 };
    static cilist io___1177 = { 0, 16, 0, 0, 0 };
    static cilist io___1183 = { 0, 80, 0, 0, 0 };
    static cilist io___1187 = { 0, 16, 0, fmt_17, 0 };
    static cilist io___1188 = { 0, 16, 0, fmt_18, 0 };
    static icilist io___1192 = { 0, pcard, 0, fmt_18, 80, 1 };
    static cilist io___1194 = { 0, 16, 0, fmt_20, 0 };
    static cilist io___1195 = { 0, 16, 0, fmt_18, 0 };
    static icilist io___1196 = { 0, pcard+40, 0, fmt_18, 40, 1 };
    static cilist io___1197 = { 0, 16, 0, 0, 0 };
    static cilist io___1198 = { 0, 16, 0, 0, 0 };
    static cilist io___1202 = { 0, 16, 0, "(1x,'D-Spread(R) = ',f6.3,       "
	    "                                   '   B-G Spread(R) = ',f6.3,  "
	    "                                '       Size (C) = ',f6.3       "
	    "                            )", 0 };
    static cilist io___1203 = { 0, 16, 0, 0, 0 };
    static cilist io___1204 = { 0, 16, 0, fmt_21, 0 };
    static cilist io___1206 = { 0, 16, 0, 0, 0 };
    static cilist io___1207 = { 0, 16, 0, 0, 0 };
    static cilist io___1208 = { 0, 6, 0, "(23x,'  OT (sec)   X (km)    Y (km"
	    ")    Z (km) ')", 0 };
    static cilist io___1209 = { 0, 6, 0, "(' Sigma (CHD):         ',4f10.4)", 
	    0 };
    static cilist io___1210 = { 0, 6, 0, "(' Resolution (CHD):    ',4f10.4,x"
	    ",                              'D-spread =',f6.3)", 0 };
    static cilist io___1211 = { 0, 6, 0, "(' Data Variance      = ',f10.4)", 
	    0 };
    static cilist io___1212 = { 0, 6, 0, "(' Singular values:     ',4f10.4,5"
	    "x,'ALE =',f7.3)", 0 };
    static cilist io___1213 = { 0, 16, 0, fmt_22, 0 };
    static cilist io___1214 = { 0, 16, 0, 0, 0 };
    static cilist io___1215 = { 0, 16, 0, 0, 0 };
    static cilist io___1216 = { 0, 16, 0, fmt_22, 0 };
    static cilist io___1217 = { 0, 16, 0, 0, 0 };
    static cilist io___1218 = { 0, 16, 0, 0, 0 };



/*     calculate resolution and covariance matrices. */


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


/* ---- resolution and covariance calculations */
    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___1174);
	e_wsfe();
	s_wsfe(&io___1175);
	e_wsfe();
	if (coordsyst_1.isingle != 0) {
/* c       write(16,*)'CHOLESKY-decomposition:' */
	    s_wsle(&io___1176);
	    do_lio(&c__9, &c__1, "    RESOLUTION-matrix                   ", (
		    ftnlen)40);
	    do_lio(&c__9, &c__1, "    COVARIANCE-matrix", (ftnlen)21);
	    e_wsle();
	    s_wsle(&io___1177);
	    e_wsle();
	}
    }
/* L25: */
    mef = (dimen_1.neqs << 2) + dimen_1.nshot - 4;
    nef = modela_1.nltot + 4;
    if (coordsyst_1.isingle != 0) {
	nef = 4;
    }
/* only first 4 rows and first 4 standar */
    n1 = dimen_1.neqs << 2;
    n2 = n1 + dimen_1.nshot;
    n3 = n2 + modela_1.nltot;
    if (param_1.iresolcalc == 2 && coordsyst_1.isingle == 1) {
	s_wsle(&io___1183);
	do_lio(&c__9, &c__1, "Covariance matrice", (ftnlen)18);
	e_wsle();
    }
    i__1 = nef;
    for (k = 1; k <= i__1; ++k) {
	i__2 = dimen_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L16: */
	    a4_1.rht[i__ - 1] = gsave_1.gcopy[k + i__ * 60 - 61];
	}
	l = k;
	if (k > 4) {
	    l = k + mef;
	}
	luelmp_(gmatrix_1.g, a4_1.rht, &dimen_1.nvar, a4_1.rht);
	if (coordsyst_1.isingle == 0) {
	    if (! coordsyst_1.single_turbo__) {
		s_wsfe(&io___1187);
		do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
		e_wsfe();
		s_wsfe(&io___1188);
		i__2 = dimen_1.nvar;
		for (j = 1; j <= i__2; ++j) {
		    do_fio(&c__1, (char *)&a4_1.rht[j - 1], (ftnlen)sizeof(
			    real));
		}
		e_wsfe();
	    }
	    rdiag[k - 1] = a4_1.rht[l - 1];
	} else {
	    s_wsfi(&io___1192);
	    i__2 = dimen_1.nvar;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&a4_1.rht[j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfi();
	    for (j = 1; j <= 4; ++j) {
		goodness_1.rc[l + (j << 2) - 5] = a4_1.rht[j - 1];
/*  resolution-matrix */
	    }
	}
	luelmp_(gmatrix_1.g, a4_1.rht, &dimen_1.nvar, a4_1.rht);
/* ---- put covariance into proper unit */
	j = l % 4;
	if (j == 0) {
	    j = 4;
	}
	scale1 = fix1_1.scale[j - 1];
	if (l > n1) {
	    scale1 = fix1_1.scale[0];
	}
	if (l > n2) {
	    scale1 = fix1_1.scale[5];
	}
	if (l > n3) {
	    scale1 = fix1_1.scale[4];
	}
	i__2 = dimen_1.nvar;
	for (j = 1; j <= i__2; ++j) {
/* cc   19 rht(j)=rht(j)*davari*scale1 */
/* L19: */
	    a4_1.rht[j - 1] *= scale1;
	}
/* <== UNIT covariance matrix !!! */
	fixunt_(a4_1.rht, &dimen_1.neqs, &dimen_1.nshot, &modela_1.nltot, &
		dimen_1.ksta, fix1_1.scale, layvel_1.vdamp, &c__2, &c__100, 
		modela_1.nplay);
	if (coordsyst_1.isingle == 0) {
	    if (! coordsyst_1.single_turbo__) {
		s_wsfe(&io___1194);
		do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
		e_wsfe();
		s_wsfe(&io___1195);
		i__2 = dimen_1.nvar;
		for (j = 1; j <= i__2; ++j) {
		    do_fio(&c__1, (char *)&a4_1.rht[j - 1], (ftnlen)sizeof(
			    real));
		}
		e_wsfe();
	    }
	} else {
	    s_wsfi(&io___1196);
	    i__2 = dimen_1.nvar;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&a4_1.rht[j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfi();
	    if (! coordsyst_1.single_turbo__) {
		s_wsle(&io___1197);
		do_lio(&c__9, &c__1, pcard, (ftnlen)80);
		e_wsle();
	    }
	    for (j = 1; j <= 4; ++j) {
		goodness_1.covc[l + (j << 2) - 5] = a4_1.rht[j - 1];
	    }
	}
/*      s(k)=sqrt(abs(rht(l)))  ! compiler produces warning with range checking */
	a4_1.s[k - 1] = (r__1 = a4_1.rht[l - 1], dabs(r__1));
	a4_1.s[k - 1] = sqrt(a4_1.s[k - 1]);
/* L15: */
    }

    if (coordsyst_1.isingle != 0) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___1198);
	    e_wsle();
	}
	spreadd_(goodness_1.rc, &c__4, &spread1);
	quality_1.spread = spread1;
	if (param_1.ifixsolution == 1) {
	    for (j = 1; j <= 3; ++j) {
		for (k = 1; k <= 3; ++k) {
		    goodness_1.r3[j + k * 3 - 4] = goodness_1.rc[j + (k << 2) 
			    - 5];
		}
	    }
	    spreadd_(goodness_1.r3, &c__3, &quality_1.spread);
	}
	if (param_1.ifixsolution == 9) {
	    spreadd_(goodness_1.rc, &c__1, &quality_1.spread);
	}
	spreadb_(goodness_1.rc, &c__4, &spread2);
	size = 0.f;
	for (j = 1; j <= 4; ++j) {
	    size += goodness_1.covc[j + (j << 2) - 5];
	}
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___1202);
	    do_fio(&c__1, (char *)&quality_1.spread, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&spread2, (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&size, (ftnlen)sizeof(real));
	    e_wsfe();
	}
    }

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1203);
	e_wsle();
	s_wsfe(&io___1204);
	e_wsfe();
    }
    if (coordsyst_1.isingle != 0) {
	avresol = 0.f;
	i__1 = nef;
	for (j = 1; j <= i__1; ++j) {
	    avresol += goodness_1.rc[j + (j << 2) - 5];
	}
	avresol /= (real) nef;
	if (! coordsyst_1.single_turbo__) {
	    s_wsle(&io___1206);
	    e_wsle();
	    s_wsle(&io___1207);
	    do_lio(&c__9, &c__1, "   OT (sec)   X (km)    Y (km)    Z (km) ", 
		    (ftnlen)41);
	    e_wsle();
	}
	s_wsfe(&io___1208);
	e_wsfe();
/*        write(6,'(1x,''CHOLESKY  (othet='',f5.3,'') :'')') othet */
	s_wsfe(&io___1209);
	i__1 = nef;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&a4_1.s[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___1210);
	i__1 = nef;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&goodness_1.rc[j + (j << 2) - 5], (ftnlen)
		    sizeof(real));
	}
	do_fio(&c__1, (char *)&quality_1.spread, (ftnlen)sizeof(real));
	e_wsfe();
	s_wsfe(&io___1211);
	do_fio(&c__1, (char *)&(*davari), (ftnlen)sizeof(real));
	e_wsfe();
/* cc        call SPREADd(Rs,4,spread3) */
/* cc        do j=1,4 */
/* cc           COVs(j)=SQRT(COVs(j))  !  <-- standard deviation */
/* cc        enddo */
	s_wsfe(&io___1212);
	i__1 = nef;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&goodness_1.sv[j - 1], (ftnlen)sizeof(real))
		    ;
	}
	do_fio(&c__1, (char *)&goodness_1.ale[0], (ftnlen)sizeof(real));
	e_wsfe();
/* cc        write(6,'('' Sigma (SVD):         '',4f10.4)') (COVs(j),j=1,nef) */
/* cc        write(6,'('' Resolution (SVD):    '',4f10.4,3x, */
/* cc     &            ''D-spread ='',f6.3)') (Rs(j,j),j=1,nef) , spread3 */
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsfe(&io___1213);
	i__1 = nef;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&a4_1.s[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1214);
	e_wsle();
	s_wsle(&io___1215);
	do_lio(&c__9, &c__1, "Rdiag of selected model parameters:", (ftnlen)
		35);
	e_wsle();
	s_wsfe(&io___1216);
	i__1 = nef;
	for (j = 1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&rdiag[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsle(&io___1217);
	e_wsle();
	s_wsle(&io___1218);
	e_wsle();
    }

    return 0;
} /* resolcovar_ */


/* of subr. resolcovar */
/* Subroutine */ int travderiv_(char *raytype, integer *nl, integer *mll, 
	real *v1, real *vsq1, real *rp, integer *nrp, real *x2, real *y2, 
	real *z2, real *ss, real *r1, real *r2, integer *ievent, integer *
	inobs, ftnlen raytype_len)
{
    /* Format strings */
    static char fmt_2000[] = "(//,2x,\002travderiv>>>, label 2000:  \002,"
	    "\002nrp greater than inrpmax:\002,/,5x,\002event nr=\002,i6,2x"
	    ",\002nr. of obs=\002,i4,5x,\002nrp=\002,i4,/,3x,\002program stop"
	    "s here\002,/)";

    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static real f[100];
    static integer i__, j, l, idownward, jb, ii, jx;
    static real dtdd, zmax;
    static integer jndex;
    extern /* Subroutine */ int maxri_(integer *, real *, real *, integer *);

    /* Fortran I/O blocks */
    static cilist io___1229 = { 0, 16, 0, fmt_2000, 0 };



/*     compute traveltime derivatives with respect to all the unknowns inverted */
/*     for ! */


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

    /* Parameter adjustments */
    --vsq1;
    --v1;
    rp -= 4;
    --ss;
    --z2;
    --y2;
    --x2;

    /* Function Body */
    if (coordsyst_1.isingle != 0 && coordsyst_1.iturbo == 1) {
    } else {
	i__1 = *nl;
	for (ii = 1; ii <= i__1; ++ii) {
/* L2: */
	    dttx_1.dtdv[ii - 1] = 0.f;
	}
    }
    for (ii = 1; ii <= 3; ++ii) {
/* L3: */
	dttx_1.dtdr[ii - 1] = 0.f;
    }

    if (param_1.ifixsolution == 9) {
	return 0;
    }

/*     No trvdrv's for reseted obs: */

/* hold LAT/LON/DEPTH fixed !!! */
    if (coordsyst_1.isingle != 0 && obb_1.w[*inobs + *ievent * 650 - 651] == 
	    0.f) {
	return 0;
    }

    if (s_cmp(raytype, "direct", raytype_len, (ftnlen)6) == 0) {
	goto L5;
    }
    if (s_cmp(raytype, "refracted", raytype_len, (ftnlen)9) == 0) {
	goto L6;
    }
    if (s_cmp(raytype, "reflected", raytype_len, (ftnlen)9) == 0) {
	goto L8;
    }
    s_stop("TRAVDERIV>>> illegal raytype!!!", (ftnlen)31);

/*   direct ray */

L5:
    i__1 = *nrp - 1;
    for (j = 1; j <= i__1; ++j) {
	jx = *nrp - j;
	x2[j] = rp[(j + 1) * 3 + 1] - rp[j * 3 + 1];
	y2[j] = rp[(j + 1) * 3 + 2] - rp[j * 3 + 2];
	z2[j] = rp[(j + 1) * 3 + 3] - rp[j * 3 + 3];
/* Computing 2nd power */
	r__1 = x2[j];
/* Computing 2nd power */
	r__2 = y2[j];
/* Computing 2nd power */
	r__3 = z2[j];
	ss[j] = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3);
	if (coordsyst_1.isingle != 0 && coordsyst_1.iturbo == 1) {
	} else {
	    dttx_1.dtdv[jx - 1] = -ss[j] / vsq1[jx];
	}
/* L9: */
    }
    dttx_1.dtdr[0] = -x2[1] / (layer_1.v[layer_1.jl - 1] * ss[1]);
    dttx_1.dtdr[1] = -y2[1] / (layer_1.v[layer_1.jl - 1] * ss[1]);
    dttx_1.dtdr[2] = -z2[1] / (layer_1.v[layer_1.jl - 1] * ss[1]);
    goto L40;

/*    refracted first path */

L6:
    i__1 = *nrp;
    for (j = 1; j <= i__1; ++j) {
	z2[j] = rp[j * 3 + 3];
/* L171: */
    }
    maxri_(nrp, &z2[1], &zmax, &jndex);
/*                                     path-lengths in each layer) */
/* determine MAX (=zmax) of z2 (verti */
    l = *nl;
L12:
    if (layer_1.h__[l - 1] <= zmax + .01f) {
	goto L11;
    }
    --l;
    goto L12;
L11:
    jb = l;

    dtdd = 1 / layer_1.v[jb - 1];
    dttx_1.dtdr[0] = *r1 / layer_1.delta * dtdd;
    dttx_1.dtdr[1] = *r2 / layer_1.delta * dtdd;
    dttx_1.dtdr[2] = -sqrt(layer_1.vsq[jb - 1] - layer_1.vsq[layer_1.jl - 1]) 
	    / (layer_1.v[jb - 1] * layer_1.v[layer_1.jl - 1]);

    if (coordsyst_1.isingle != 0 && coordsyst_1.iturbo == 1) {
	goto L40;
    }

/*     thk(j) -- thickness of layer j */
/*     jl -- event layer */
/*     jb -- bottomming layer */
/*     tkj -- depth of event within event layer */

/* do not calc. dt/dv  !! */
    i__1 = *nl;
    for (j = 1; j <= i__1; ++j) {
	f[j - 1] = 1.f;
	if (j >= layer_1.jl) {
	    f[j - 1] = 2.f;
	}
/* L201: */
	if (j > jb) {
	    f[j - 1] = 0.f;
	}
    }
    i__1 = jb - 1;
    for (j = 1; j <= i__1; ++j) {
	dttx_1.dtdv[jb - 1] += layer_1.thk[j - 1] * v1[j] * f[j - 1] / (vsq1[
		jb] * sqrt(vsq1[jb] - vsq1[j]));
	dttx_1.dtdv[j - 1] = -layer_1.thk[j - 1] * v1[jb] * f[j - 1] / (vsq1[
		j] * sqrt(vsq1[jb] - vsq1[j]));
/* L202: */
    }
    dttx_1.dtdv[layer_1.jl - 1] += layer_1.tkj * v1[jb] / (vsq1[layer_1.jl] * 
	    sqrt(vsq1[jb] - vsq1[layer_1.jl]));
    dttx_1.dtdv[jb - 1] = dttx_1.dtdv[jb - 1] - layer_1.tkj * v1[layer_1.jl] /
	     (vsq1[jb] * sqrt(vsq1[jb] - vsq1[layer_1.jl])) - layer_1.delta / 
	    vsq1[jb];

    goto L40;

/*     reflected phase */

L8:
/*  avoid hypocenter on layer-boundary: */
/* hrm      if(rp(1,1).eq.rp(1,2).and. */
/* hrm     &   rp(2,1).eq.rp(2,2).and. */
/* hrm     &   rp(3,1).eq.rp(3,2))then */
/* hrm            rp(3,1)=rp(3,1)-0.0001   ! move hypocenter 10 cm up */
/* hrm      endif */

/* test      dtdr(1)=DTDDrefl*(r1/delta)      ! valid for REFLECT */
/* test      dtdr(2)=DTDDrefl*(r2/delta) */
/* test      dtdr(3)=DTDHrefl */

    jx = 0;
    i__1 = *nrp - 1;
    for (j = 1; j <= i__1; ++j) {
	x2[j] = rp[(j + 1) * 3 + 1] - rp[j * 3 + 1];
	y2[j] = rp[(j + 1) * 3 + 2] - rp[j * 3 + 2];
	z2[j] = rp[(j + 1) * 3 + 3] - rp[j * 3 + 3];
/* Computing 2nd power */
	r__1 = x2[j];
/* Computing 2nd power */
	r__2 = y2[j];
/* Computing 2nd power */
	r__3 = z2[j];
	ss[j] = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3);
	if (j == 1) {
	    dttx_1.dtdr[0] = -x2[1] / (layer_1.v[layer_1.jl - 1] * ss[1]);
/* valid for REFLECT1 */
	    dttx_1.dtdr[1] = -y2[1] / (layer_1.v[layer_1.jl - 1] * ss[1]);
	    dttx_1.dtdr[2] = -z2[1] / (layer_1.v[layer_1.jl - 1] * ss[1]);
	}
	if (coordsyst_1.isingle != 0 && coordsyst_1.iturbo == 1) {
	    goto L40;
	}
/* do not calc. dt/dv */
	idownward = 0;
	if (z2[j] > 0.f) {
	    idownward = 1;
	}
	if (j == *nrp - 1 && idownward == 1) {
	    idownward = 0;
	}
	if (idownward == 1) {
/*  DOWNwards */
	    jx = layer_1.jl + j - 1;
/*            if(vsq1(jx).le.0)then */
/*               write(6,*)'jx=',jx,'jl=',jl,'tkj=',tkj */
/*               write(6,*)'j=',j,'vsq1(jx)=',vsq1(jx),'nrp=',nrp */
/*            endif */
	    dttx_1.dtdv[jx - 1] = -ss[j] / vsq1[jx];
	} else {
/*  UPward */
	    if (jx == *mll) {
		dttx_1.dtdv[*mll - 1] -= ss[j] / vsq1[*mll];
		--jx;
	    } else {
		dttx_1.dtdv[jx - 1] -= ss[j] / vsq1[jx];
		--jx;
	    }
	}
    }
    if (jx != 0) {
	s_stop("TRAVDERIV>>> did not reach the top...!", (ftnlen)38);
    }
    goto L40;


L40:

    if (param_1.ifixsolution == 1) {
	dttx_1.dtdr[2] = 0.f;
    }

/* ek   test if nrp gt. inrpmax:::> */
/* hold depth fixed !!! */
    if (*nrp > 202) {
	if (! coordsyst_1.single_turbo__) {
	    s_wsfe(&io___1229);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*inobs), (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&(*nrp), (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	s_stop("subr. TRAVDERIV >>> nrp > nrpmax", (ftnlen)32);
    }

    return 0;
} /* travderiv_ */


/* of subr. travderiv */
/* Subroutine */ int rejectobs_(integer *i__, integer *nobs, integer *
	iresflag)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer pow_ii(integer *, integer *), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle(void), s_wsfe(cilist *), 
	    do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer iii;
    static real wsum, xkndw;
    static integer knobst, iobswt;

    /* Fortran I/O blocks */
    static cilist io___1236 = { 0, 16, 0, 0, 0 };
    static cilist io___1237 = { 0, 16, 0, "(' Iteration# ',i3,' Event#',i4,'"
	    " Res#',i3,          ' =',f7.2,'; ABS > 2.0 ---> weight set to ze"
	    "ro !')", 0 };
    static cilist io___1238 = { 0, 6, 0, "(' Iteration# ',i3,' Event#',i4,' "
	    "Res#',i3,           ' =',f7.2,'; ABS > 2.0 ---> weight set to ze"
	    "ro !')", 0 };
    static cilist io___1239 = { 0, 16, 0, 0, 0 };
    static cilist io___1240 = { 0, 16, 0, 0, 0 };



/*     reject the current observation for further calculation in case the */
/*     reading (or the seismologist who read it...) seems to be nuts: */


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
    if (obb_1.w[*nobs + *i__ * 650 - 651] == 0.f) {
	return 0;
    }
    if (obb_1.knobs[*i__ - 1] - obb_1.nobswithw0 == dimen_1.nvar) {
	return 0;
    }

/* c         w(nobs,i)=0.0039  !  = 1./(2**(2*reading_weight)) = 1./256 */

/*     re-normalize weights of this event : */

    ++obb_1.nobswithw0;
    wsum = 0.f;
    knobst = obb_1.knobs[*i__ - 1];
    i__1 = knobst;
    for (iii = 1; iii <= i__1; ++iii) {
	iobswt = obb_1.kpwt[iii + *i__ * 650 - 651];
	if (iobswt < 4 && obb_1.w[iii + *i__ * 650 - 651] != 0.f) {
	    if (obb_1.sphase[iii + *i__ * 650 - 651] == 1.f || obb_1.sphase[
		    iii + *i__ * 650 - 651] == 2.f) {
		i__2 = iobswt << 1;
		obb_1.w[iii + *i__ * 650 - 651] = param_1.swtfac * 1.f / 
			pow_ii(&c__2, &i__2);
/* S-phase or s-p ph */
	    } else {
		i__2 = iobswt << 1;
		obb_1.w[iii + *i__ * 650 - 651] = 1.f / pow_ii(&c__2, &i__2);
/* P- or M-phase */
	    }
	} else {
	    obb_1.w[iii + *i__ * 650 - 651] = 0.f;
/* observation-weight 4 ==> don't use this arr */
	}
	if (iii == *nobs) {
	    obb_1.w[iii + *i__ * 650 - 651] = 0.f;
	}
	wsum += obb_1.w[iii + *i__ * 650 - 651];
    }
    xkndw = (real) (knobst - obb_1.nobswithw0) / wsum;
    i__1 = knobst;
    for (iii = 1; iii <= i__1; ++iii) {
	obb_1.w[iii + *i__ * 650 - 651] *= xkndw;
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1236);
	do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
	e_wsle();
	s_wsfe(&io___1237);
	do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*nobs), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (ftnlen)
		sizeof(real));
	e_wsfe();
    }
    s_wsfe(&io___1238);
    do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*nobs), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (ftnlen)sizeof(
	    real));
    e_wsfe();
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1239);
	do_lio(&c__9, &c__1, "knobs(i)   = ", (ftnlen)13);
	do_lio(&c__3, &c__1, (char *)&knobst, (ftnlen)sizeof(integer));
	e_wsle();
	s_wsle(&io___1240);
	do_lio(&c__9, &c__1, "nobswithw0 = ", (ftnlen)13);
	do_lio(&c__3, &c__1, (char *)&obb_1.nobswithw0, (ftnlen)sizeof(
		integer));
	e_wsle();
    }
/* c      write(6,*)'knobs(i)   = ',knobst */
/* c      write(6,*)'nobswithw0 = ',nobswithw0 */
/* c      write(6,*) */
    *iresflag = 1;
/* increased datvar; give location a second chance. */

/* inhibit a pre-stopping in subr. OUTPUT due to */
    return 0;
} /* rejectobs_ */


/* of subr. rejectobs */
/* Subroutine */ int reviveobs_(integer *i__, integer *nobs, integer *
	iresflag)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer pow_ii(integer *, integer *), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle(void), s_wsfe(cilist *), 
	    do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer iii;
    static real wsum, xkndw;
    static integer knobst, iobswt;

    /* Fortran I/O blocks */
    static cilist io___1246 = { 0, 16, 0, 0, 0 };
    static cilist io___1247 = { 0, 16, 0, "(' Iteration# ',i3,' Event#',i4,'"
	    " Res#',i3,                  ' =',f7.2,'; ABS < 1.0 ---> weight r"
	    "evived !')", 0 };
    static cilist io___1248 = { 0, 6, 0, "(' Iteration# ',i3,' Event#',i4,' "
	    "Res#',i3,                   ' =',f7.2,'; ABS < 1.0 ---> weight r"
	    "evived !')", 0 };
    static cilist io___1249 = { 0, 16, 0, 0, 0 };
    static cilist io___1250 = { 0, 16, 0, 0, 0 };



/*     If observationweight < 4 and weight=0.0 then set 'original' weight */
/*     if residual has become smaller since it has been reseted: */


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
    if (obb_1.w[*nobs + *i__ * 650 - 651] != 0.f) {
	return 0;
    }
    if (obb_1.kpwt[*nobs + *i__ * 650 - 651] == 4) {
	return 0;
    }

/* c         w(nobs,i)=0.0039  !  = 1./(2**(2*reading_weight)) = 1./256 */

/*     re-normalize weights of this event : */

    --obb_1.nobswithw0;
    wsum = 0.f;
    knobst = obb_1.knobs[*i__ - 1];
    i__1 = knobst;
    for (iii = 1; iii <= i__1; ++iii) {
	iobswt = obb_1.kpwt[iii + *i__ * 650 - 651];
	if (iii != *nobs && obb_1.w[iii + *i__ * 650 - 651] == 0.f) {
	    obb_1.w[iii + *i__ * 650 - 651] = 0.f;
/* keep zero-weights as they are !!! */
	} else {
	    if (iobswt < 4) {
		if (obb_1.sphase[iii + *i__ * 650 - 651] == 1.f || 
			obb_1.sphase[iii + *i__ * 650 - 651] == 2.f) {
		    i__2 = iobswt << 1;
		    obb_1.w[iii + *i__ * 650 - 651] = param_1.swtfac * 1.f / 
			    pow_ii(&c__2, &i__2);
/* S-phase */
		} else {
		    i__2 = iobswt << 1;
		    obb_1.w[iii + *i__ * 650 - 651] = 1.f / pow_ii(&c__2, &
			    i__2);
/* P- or M-phase */
		}
	    } else {
		obb_1.w[iii + *i__ * 650 - 651] = 0.f;
/* observation-weight 4 ==> don't use this */
	    }
	}
	wsum += obb_1.w[iii + *i__ * 650 - 651];
    }
    xkndw = (real) (knobst - obb_1.nobswithw0) / wsum;
    i__1 = knobst;
    for (iii = 1; iii <= i__1; ++iii) {
	obb_1.w[iii + *i__ * 650 - 651] *= xkndw;
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1246);
	do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
	e_wsle();
	s_wsfe(&io___1247);
	do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*nobs), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (ftnlen)
		sizeof(real));
	e_wsfe();
    }
    s_wsfe(&io___1248);
    do_fio(&c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*nobs), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a4_1.res[*nobs + *i__ * 650 - 651], (ftnlen)sizeof(
	    real));
    e_wsfe();
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1249);
	do_lio(&c__9, &c__1, "knobs(i)   = ", (ftnlen)13);
	do_lio(&c__3, &c__1, (char *)&knobst, (ftnlen)sizeof(integer));
	e_wsle();
	s_wsle(&io___1250);
	do_lio(&c__9, &c__1, "nobswithw0 = ", (ftnlen)13);
	do_lio(&c__3, &c__1, (char *)&obb_1.nobswithw0, (ftnlen)sizeof(
		integer));
	e_wsle();
    }
/* c      write(6,*)'knobs(i)   = ',knobst */
/* c      write(6,*)'nobswithw0 = ',nobswithw0 */
/* c      write(6,*) */
    *iresflag = 1;
/* increased datvar; give location a second chance. */

/* inhibit a pre-stopping in subr. OUTPUT due to */
    return 0;
} /* reviveobs_ */


/* of subr. reviveobs */
/* Subroutine */ int detnofunknowns_(void)
{
    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), do_fio(integer *
	    , char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer lipeff;

    /* Fortran I/O blocks */
    static cilist io___1252 = { 0, 16, 0, 0, 0 };
    static cilist io___1253 = { 0, 16, 0, "(' Number of unknowns (for array-"
	    "indexing): ',                   ' nvar = ',i4)", 0 };
    static cilist io___1254 = { 0, 16, 0, "(' Number of effective unknowns  "
	    "      : ',                      ' nvareff = ',i4)", 0 };
    static cilist io___1255 = { 0, 16, 0, "(' Number of elements on/below ma"
	    "in diagonal ',                  'of matrix G = At*A : kvar = ',i"
	    "7)", 0 };
    static cilist io___1256 = { 0, 16, 0, 0, 0 };



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

/*     determine the number of unknowns NVAR and */
/*     calculate the number of equations LIP to be solved : */

    if (dimen_1.icount != 0) {
	dimen_1.lip = (dimen_1.neqs << 2) + dimen_1.nshot + 1;
/* do NOT invert for velocity parameters */
	lipeff = dimen_1.lip;
    } else {
	dimen_1.lip = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + 
		dimen_1.ksta + 1;
/* invert for velocity para */
	lipeff = (dimen_1.neqs << 2) + dimen_1.nshot + modela_1.nltot + 
		obb_1.nstaeff + 1;
/* invert for vel. pa */
	if (dimen_1.nsinv == 0) {
	    dimen_1.lip = (dimen_1.neqs << 2) + dimen_1.nshot + 
		    modela_1.nltot + 1;
	}
/* do NOT inv. for */
    }
/*     NVAR is the number of unknowns to solve for : */
    dimen_1.nvar = dimen_1.lip - 1;
/*     NVAREFF is the REAL number of unknowns to solve for!!! */
    dimen_1.nvareff = lipeff - 1;
/*     KVAR is the number of elements on or above the main diagonal of G=(At(A)) */
    dimen_1.kvar = dimen_1.nvar * dimen_1.lip / 2;


/*  cuk !BELOW!! cuk */
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1252);
	e_wsle();
	s_wsfe(&io___1253);
	do_fio(&c__1, (char *)&dimen_1.nvar, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___1254);
	do_fio(&c__1, (char *)&dimen_1.nvareff, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___1255);
	do_fio(&c__1, (char *)&dimen_1.kvar, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsle(&io___1256);
	e_wsle();
    }

    return 0;
} /* detnofunknowns_ */


/* of subr. detnofunknowns */
/* Subroutine */ int actualstations_(void)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void), s_wsfe(cilist *), do_fio(integer *
	    , char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer nofreadp, nofreads, i__, k, nofreadings, nobsp[650], nobss[
	    650];

    /* Fortran I/O blocks */
    static cilist io___1262 = { 0, 16, 0, 0, 0 };
    static cilist io___1263 = { 0, 16, 0, "(' readings for station ',a4,' : "
	    "tot=',                      i4,'  P:',i4,'  S:',i4)", 0 };
    static cilist io___1264 = { 0, 16, 0, "(' readings for station ',a4,' :'"
	    ",i4)", 0 };
    static cilist io___1267 = { 0, 16, 0, 0, 0 };
    static cilist io___1268 = { 0, 16, 0, "(' Total number of stations with "
	    "readings:',i4)", 0 };
    static cilist io___1269 = { 0, 16, 0, 0, 0 };
    static cilist io___1270 = { 0, 16, 0, "(' Total number of readings: ',i7)"
	    , 0 };
    static cilist io___1271 = { 0, 16, 0, "(' Total number of P readings: ',"
	    "i7)", 0 };
    static cilist io___1272 = { 0, 16, 0, "(' Total number of S readings: ',"
	    "i7)", 0 };
    static cilist io___1273 = { 0, 16, 0, 0, 0 };



/* ek added separate report of P and S phases 20.8.98 */

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

    i__1 = dimen_1.nsta;
    for (i__ = 1; i__ <= i__1; ++i__) {
	obb_1.nactualsta[i__ - 1] = 0;
	nobsp[i__ - 1] = 0;
	nobss[i__ - 1] = 0;
    }
    obb_1.nstaeff = 0;
    nofreadings = 0;
    i__1 = dimen_1.legs;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* = neqs+nshot */
	i__2 = obb_1.knobs[i__ - 1];
	for (k = 1; k <= i__2; ++k) {
	    ++obb_1.nactualsta[obb_1.istm[k + i__ * 650 - 651] - 1];
	    if (modela_1.nsp == 2) {
		if (obb_1.sphase[k + i__ * 650 - 651] == 0.f) {
		    ++nobsp[obb_1.istm[k + i__ * 650 - 651] - 1];
		}
		if (obb_1.sphase[k + i__ * 650 - 651] == 1.f) {
		    ++nobss[obb_1.istm[k + i__ * 650 - 651] - 1];
		}
	    }
	    ++nofreadings;
	}
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1262);
	e_wsle();
    }
    i__1 = dimen_1.nsta;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (obb_1.nactualsta[i__ - 1] > 0) {
	    if (! coordsyst_1.single_turbo__) {
		if (modela_1.nsp == 2) {
		    s_wsfe(&io___1263);
		    do_fio(&c__1, charc_1.stn + (i__ - 1 << 2), (ftnlen)4);
		    do_fio(&c__1, (char *)&obb_1.nactualsta[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&nobsp[i__ - 1], (ftnlen)sizeof(
			    integer));
		    do_fio(&c__1, (char *)&nobss[i__ - 1], (ftnlen)sizeof(
			    integer));
		    e_wsfe();
		} else {
		    s_wsfe(&io___1264);
		    do_fio(&c__1, charc_1.stn + (i__ - 1 << 2), (ftnlen)4);
		    do_fio(&c__1, (char *)&obb_1.nactualsta[i__ - 1], (ftnlen)
			    sizeof(integer));
		    e_wsfe();
		}
	    }
	    ++obb_1.nstaeff;
	}
	nofreadp += nobsp[i__ - 1];
	nofreads += nobss[i__ - 1];
    }
    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1267);
	e_wsle();
	s_wsfe(&io___1268);
	do_fio(&c__1, (char *)&obb_1.nstaeff, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsle(&io___1269);
	e_wsle();
	s_wsfe(&io___1270);
	do_fio(&c__1, (char *)&nofreadings, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___1271);
	do_fio(&c__1, (char *)&nofreadp, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___1272);
	do_fio(&c__1, (char *)&nofreads, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsle(&io___1273);
	e_wsle();
    }

    return 0;
} /* actualstations_ */



/* of subr. actualstations */
/* Subroutine */ int finalstaresi_(void)
{
    /* Initialized data */

    static char phz[1*3] = "S" "P" "m";

    /* Format strings */
    static char fmt_1[] = "(\0021\002)";
    static char fmt_51[] = "(1x,2(\002sta ph wt  res   ttime delta\002,5x))";
    static char fmt_53[] = "(2(1x,a4,1x,a1,1x,i2,f7.3,2f6.2,4x))";
    static char fmt_7777[] = "(//,2x,\002 station statistics, remember nsp w"
	    "as set to:\002,i2,/)";
    static char fmt_7[] = "(/,1x,\002sta phase nobs avres  avwres    std    "
	    "wsum    \002,\002delay\002,/)";
    static char fmt_1201[] = "(a80)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1, r__2;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer s_wsle(cilist *), e_wsle(void), do_lio(integer *, integer *, char 
	    *, ftnlen), s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, 
	    char *, ftnlen);
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_open(olist *), s_wsfi(
	    icilist *), e_wsfi(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, j, k, m;
    static real aa[650], bb[650], dd[650], ee[650];
    static integer iz, icc[650];
    static real del[650], aas[650], bbs[650], dds[650], ees[650];
    static char cew[1], cns[1], sta[4];
    static integer iccs[650];
    static char phzz[1*650], cline[80];
    static integer iwarn;
    static real stcor1;

    /* Fortran I/O blocks */
    static cilist io___1275 = { 0, 16, 0, 0, 0 };
    static cilist io___1276 = { 0, 16, 0, 0, 0 };
    static cilist io___1277 = { 0, 16, 0, 0, 0 };
    static cilist io___1278 = { 0, 16, 0, 0, 0 };
    static cilist io___1279 = { 0, 16, 0, 0, 0 };
    static cilist io___1280 = { 0, 16, 0, 0, 0 };
    static cilist io___1281 = { 0, 16, 0, fmt_1, 0 };
    static cilist io___1283 = { 0, 16, 0, 0, 0 };
    static cilist io___1284 = { 0, 16, 0, "(1x,'Station residuals for event="
	    "',i4,                           3x,3i2.2,1x,2i2.2,1x,f5.2)", 0 };
    static cilist io___1285 = { 0, 16, 0, "(1x,'Station residuals for event="
	    "',i4,                           3x,3i2.2,1x,2i2.2,1x,f5.2)", 0 };
    static cilist io___1286 = { 0, 16, 0, fmt_51, 0 };
    static cilist io___1290 = { 0, 16, 0, fmt_53, 0 };
    static cilist io___1291 = { 0, 16, 0, 0, 0 };
    static cilist io___1292 = { 0, 16, 0, 0, 0 };
    static cilist io___1293 = { 0, 16, 0, 0, 0 };
    static cilist io___1294 = { 0, 16, 0, 0, 0 };
    static cilist io___1295 = { 0, 16, 0, 0, 0 };
    static cilist io___1296 = { 0, 16, 0, 0, 0 };
    static cilist io___1297 = { 0, 16, 0, 0, 0 };
    static cilist io___1298 = { 0, 16, 0, fmt_7777, 0 };
    static cilist io___1299 = { 0, 16, 0, fmt_7, 0 };
    static cilist io___1313 = { 0, 12, 0, fmt_1201, 0 };
    static icilist io___1318 = { 0, cline, 0, form_1.fm, 80, 1 };
    static cilist io___1319 = { 0, 12, 0, "(a)", 0 };
    static cilist io___1321 = { 0, 16, 0, "(5x,'WARNING: Station = ',a4,    "
	    "                          5x,'!!! Variance  bb(',i3,') = ',f7.3,"
	    "' < 0 !!')", 0 };
    static cilist io___1322 = { 0, 16, 0, "(1x,a4,3x,a1,i4,3f8.4,1x,2f8.4)", 
	    0 };
    static cilist io___1323 = { 0, 16, 0, "(5x,'WARNING: Station = ',a4,    "
	    "                        5x,'!!! Variance  bbs(',i3,') = ',f7.3,'"
	    " < 0 !!')", 0 };
    static cilist io___1325 = { 0, 16, 0, "(1x,a4,3x,a1,i4,3f8.4,1x,2f8.4)", 
	    0 };
    static cilist io___1326 = { 0, 16, 0, 0, 0 };
    static cilist io___1327 = { 0, 16, 0, 0, 0 };
    static cilist io___1328 = { 0, 12, 0, 0, 0 };
    static cilist io___1329 = { 0, 12, 0, 0, 0 };
    static cilist io___1330 = { 0, 12, 0, 0, 0 };
    static cilist io___1331 = { 0, 12, 0, "(f5.2,5x,f7.2,2x,f7.3,4x)", 0 };



/*     computes final station residuals for all stations used in this run. */


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
/* hrm      real phz(3) */

    if (coordsyst_1.isingle == 0) {
	if (coordsyst_1.iturbo == 0) {
	    s_wsle(&io___1275);
	    e_wsle();
	    s_wsle(&io___1276);
	    e_wsle();
	    s_wsle(&io___1277);
	    e_wsle();
	    s_wsle(&io___1278);
	    e_wsle();
	} else {
	    s_wsle(&io___1279);
	    do_lio(&c__9, &c__1, "TURBO-option is set; residuals are NOT pri"
		    "nted for each event!", (ftnlen)62);
	    e_wsle();
	}
    }
    s_wsle(&io___1280);
    e_wsle();
    if (coordsyst_1.isingle == 0) {
	if (coordsyst_1.iturbo == 0) {
	    s_wsfe(&io___1281);
	    e_wsfe();
	} else {
	    goto L8001;
/* do NOT output residuals for each event if TUR */
	}
    }

/*     output residuals for each event seperately: */

    i__1 = dimen_1.legs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_wsle(&io___1283);
	e_wsle();
	if (event_1.imin[i__ - 1] < 0) {
/*  U.K.  3.Feb.87 */
	    event_1.imin[i__ - 1] += 60;
	    --event_1.ihr[i__ - 1];
	}
	if (coordsyst_1.isingle == 0) {
	    s_wsfe(&io___1284);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&event_1.iyr[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.imo[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.iday[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.ihr[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.imin[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.e[(i__ << 2) - 4], (ftnlen)sizeof(
		    real));
	    e_wsfe();
	} else {
	    s_wsfe(&io___1285);
	    do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.iyr[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.imo[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.iday[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.ihr[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.imin[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&event_1.e[(i__ << 2) - 4], (ftnlen)sizeof(
		    real));
	    e_wsfe();
	}
/*        no more active */
/* 3       format(1h ,'Station residuals for event=',i4, */
/*    &               3x,3i2.2,1x,2i2.2,1x,f5.2) */
	s_wsfe(&io___1286);
	e_wsfe();
	i__2 = obb_1.knobs[i__ - 1];
	for (j = 1; j <= i__2; ++j) {
/* Computing 2nd power */
	    r__1 = event_1.e[(i__ << 2) - 3] - statn_1.d__[j + (i__ * 3 + 1) *
		     650 - 2601];
/* Computing 2nd power */
	    r__2 = event_1.e[(i__ << 2) - 2] - statn_1.d__[j + (i__ * 3 + 2) *
		     650 - 2601];
	    del[j - 1] = sqrt(r__1 * r__1 + r__2 * r__2);
	    *(unsigned char *)&phzz[j - 1] = 'p';
	    if (obb_1.sphase[j + i__ * 650 - 651] == 1.f) {
		*(unsigned char *)&phzz[j - 1] = 's';
	    }
	    if (obb_1.sphase[j + i__ * 650 - 651] == -1.f) {
		*(unsigned char *)&phzz[j - 1] = 'm';
	    }
/* L52: */
	}
	s_wsfe(&io___1290);
	i__2 = obb_1.knobs[i__ - 1];
	for (j = 1; j <= i__2; ++j) {
	    do_fio(&c__1, charc_1.smn + (j + i__ * 650 - 651 << 2), (ftnlen)4)
		    ;
	    do_fio(&c__1, phzz + (j - 1), (ftnlen)1);
	    do_fio(&c__1, (char *)&obb_1.kpwt[j + i__ * 650 - 651], (ftnlen)
		    sizeof(integer));
	    do_fio(&c__1, (char *)&a4_1.res[j + i__ * 650 - 651], (ftnlen)
		    sizeof(real));
	    do_fio(&c__1, (char *)&extra_1.tctime[j + i__ * 650 - 651], (
		    ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&del[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* L2: */
    }
    s_wsle(&io___1291);
    e_wsle();
    if (coordsyst_1.isingle != 0) {
	goto L8001;
    }
    s_wsle(&io___1292);
    e_wsle();
    s_wsle(&io___1293);
    e_wsle();
    s_wsle(&io___1294);
    e_wsle();
    s_wsle(&io___1295);
    e_wsle();
    s_wsle(&io___1296);
    e_wsle();
    s_wsle(&io___1297);
    e_wsle();
L8001:

/*     output station statistics (nobs, avres, ...) : */

    if (coordsyst_1.isingle == 0) {
	s_wsfe(&io___1298);
	do_fio(&c__1, (char *)&modela_1.nsp, (ftnlen)sizeof(integer));
	e_wsfe();
/* L7: */
	s_wsfe(&io___1299);
	e_wsfe();
    }
/* L48: */
    i__1 = dimen_1.nsta;
    for (m = 1; m <= i__1; ++m) {
	aa[m - 1] = 0.f;
	bb[m - 1] = 0.f;
	icc[m - 1] = 0;
	dd[m - 1] = 0.f;
	ee[m - 1] = 0.f;
	aas[m - 1] = 0.f;
	bbs[m - 1] = 0.f;
	iccs[m - 1] = 0;
	dds[m - 1] = 0.f;
	ees[m - 1] = 0.f;
    }
/* loop 9: collect residual data from all events */
    i__1 = dimen_1.nsta;
    for (m = 1; m <= i__1; ++m) {
	s_copy(sta, charc_1.stn + (m - 1 << 2), (ftnlen)4, (ftnlen)4);
	i__2 = dimen_1.legs;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    k = obb_1.knobs[i__ - 1];
	    i__3 = k;
	    for (j = 1; j <= i__3; ++j) {
		if (s_cmp(sta, charc_1.smn + (j + i__ * 650 - 651 << 2), (
			ftnlen)4, (ftnlen)4) == 0 && obb_1.sphase[j + i__ * 
			650 - 651] == 0.f) {
		    goto L12;
		}
/* P */
		if (s_cmp(sta, charc_1.smn + (j + i__ * 650 - 651 << 2), (
			ftnlen)4, (ftnlen)4) == 0 && obb_1.sphase[j + i__ * 
			650 - 651] == -1.f) {
		    goto L12;
		}
/* re */
/* L11: */
	    }
	    goto L110;
L12:
	    aa[m - 1] += a4_1.res[j + i__ * 650 - 651] * obb_1.w[j + i__ * 
		    650 - 651];
/* ek         res: *w(j,i) */
	    bb[m - 1] += a4_1.res[j + i__ * 650 - 651] * a4_1.res[j + i__ * 
		    650 - 651] * obb_1.w[j + i__ * 650 - 651] * obb_1.w[j + 
		    i__ * 650 - 651];
	    ee[m - 1] += a4_1.res[j + i__ * 650 - 651];
	    dd[m - 1] += obb_1.w[j + i__ * 650 - 651];
	    ++icc[m - 1];
L110:
	    if (modela_1.nsp == 1) {
		goto L10;
	    }

/* hrm        Doing S and S-P phases */

	    i__3 = k;
	    for (j = 1; j <= i__3; ++j) {
		if (s_cmp(sta, charc_1.smn + (j + i__ * 650 - 651 << 2), (
			ftnlen)4, (ftnlen)4) == 0 && obb_1.sphase[j + i__ * 
			650 - 651] == 1.f) {
		    goto L102;
		}
/* s-ph */
		if (s_cmp(sta, charc_1.smn + (j + i__ * 650 - 651 << 2), (
			ftnlen)4, (ftnlen)4) == 0 && obb_1.sphase[j + i__ * 
			650 - 651] == 2.f) {
		    goto L102;
		}
/* s-p */
/* L101: */
	    }
	    goto L10;
L102:
	    aas[m - 1] += a4_1.res[j + i__ * 650 - 651] * obb_1.w[j + i__ * 
		    650 - 651];
/*           res: *w(j,i) */
	    bbs[m - 1] += a4_1.res[j + i__ * 650 - 651] * a4_1.res[j + i__ * 
		    650 - 651] * obb_1.w[j + i__ * 650 - 651] * obb_1.w[j + 
		    i__ * 650 - 651];
	    ees[m - 1] += a4_1.res[j + i__ * 650 - 651];
	    dds[m - 1] += obb_1.w[j + i__ * 650 - 651];
	    ++iccs[m - 1];
L10:
	    ;
	}
/* L9: */
    }
/* end loop 9 */

/*     Station file output: */

    if (outputfiles_1.istaout > 0) {
	o__1.oerr = 0;
	o__1.ounit = 12;
	o__1.ofnmlen = 80;
	o__1.ofnm = outfiles_1.stafile;
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
	s_wsfe(&io___1313);
	do_fio(&c__1, form_1.fm, (ftnlen)80);
	e_wsfe();
    }

/* begin loop 13: print output */
    i__1 = dimen_1.nsta;
    for (m = 1; m <= i__1; ++m) {

/*                              write on file 12 */
	if (outputfiles_1.istaout > 0) {
	    iz = coordsyst_1.ielev[m - 1];
	    if (stltln_1.xla[m - 1] < 0.f) {
		*(unsigned char *)cns = 'S';
		stltln_1.xla[m - 1] = -stltln_1.xla[m - 1];
	    } else {
		*(unsigned char *)cns = 'N';
	    }
	    if (stltln_1.xlo[m - 1] < 0.f) {
		*(unsigned char *)cew = 'E';
		stltln_1.xlo[m - 1] = -stltln_1.xlo[m - 1];
	    } else {
		*(unsigned char *)cew = 'W';
	    }
	    s_wsfi(&io___1318);
	    do_fio(&c__1, charc_1.stn + (m - 1 << 2), (ftnlen)4);
	    do_fio(&c__1, (char *)&stltln_1.xla[m - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, cns, (ftnlen)1);
	    do_fio(&c__1, (char *)&stltln_1.xlo[m - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, cew, (ftnlen)1);
	    do_fio(&c__1, (char *)&iz, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&statn_1.model[m - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&statn_1.map1[m - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&statn_1.ptcor[m - 1], (ftnlen)sizeof(real))
		    ;
	    do_fio(&c__1, (char *)&statn_1.stcor[m - 1], (ftnlen)sizeof(real))
		    ;
	    e_wsfi();
	    if (*(unsigned char *)cns == 'S') {
		stltln_1.xla[m - 1] = -stltln_1.xla[m - 1];
	    }
	    if (*(unsigned char *)cew == 'E') {
		stltln_1.xlo[m - 1] = -stltln_1.xlo[m - 1];
	    }
	    if (m == 1) {
		s_copy(cline + 46, "       lon,z,model,icc,ptcor,stcor", (
			ftnlen)34, (ftnlen)34);
	    }
	    s_wsfe(&io___1319);
	    do_fio(&c__1, cline, (ftnlen)80);
	    e_wsfe();
	}
/*                            end writing on file 12 */

	if (dd[m - 1] == 0.f || icc[m - 1] < 2) {
	    goto L1013;
	}
/* Computing 2nd power */
	r__1 = aa[m - 1];
	bb[m - 1] = (bb[m - 1] - r__1 * r__1 / dd[m - 1]) * icc[m - 1] / (dd[
		m - 1] * (icc[m - 1] - 1));
	iwarn = 0;
	if (bb[m - 1] < -.1f) {
	    iwarn = 1;
	    s_wsfe(&io___1321);
	    do_fio(&c__1, charc_1.stn + (m - 1 << 2), (ftnlen)4);
	    do_fio(&c__1, (char *)&m, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&bb[m - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* ek           write(6,'(5x,''WARNING: Station = '',a4, */
/* ek     &         5x,''!!! Variance  bb('',i3,'') = '',f7.3,'' < 0 !!'')') */
/* ek     &         stn(m),m,bb(m) */
/* ek           write(6,*) */
	    bb[m - 1] = 0.f;
	} else {
	    bb[m - 1] = (r__1 = bb[m - 1], dabs(r__1));
	}
	if (iwarn == 0) {
	    bb[m - 1] = sqrt(bb[m - 1]);
	} else {
	}
	aa[m - 1] /= dd[m - 1];
	ee[m - 1] /= icc[m - 1];

/* ek  phz(2)=  P-phases */

/* ek         if(iwarn.eq.0)then */
	s_wsfe(&io___1322);
	do_fio(&c__1, charc_1.stn + (m - 1 << 2), (ftnlen)4);
	do_fio(&c__1, phz + 1, (ftnlen)1);
	do_fio(&c__1, (char *)&icc[m - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ee[m - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&aa[m - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&bb[m - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&dd[m - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&statn_1.ptcor[m - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* ek         else */
/* ek            write(16,'(1x,a4,3x,a1,i4,2f8.4,''   ?.?.?''1x,2f8.4, */
/* ek     &              '' <--- !!'')') */
/* ek     &             stn(m),phz(2),icc(m),ee(m),aa(m),dd(m),ptcor(m) */
/* ek            iwarn=0 */
/* ek         endif */
L1013:
	if (modela_1.nsp == 1) {
	    goto L39;
	}
/* ek         write(16,'(1x,a4,3x,a1,i4,25x,f8.4)') */
/* ek     &                         stn(m),phz(1),iccs(m),dds(m) */
/*  print output for S-wave data  (nsp=2 or 3): */
	if (dds[m - 1] == 0.f || iccs[m - 1] < 2) {
	    goto L13;
	}
/* Computing 2nd power */
	r__1 = aas[m - 1];
	bbs[m - 1] = (bbs[m - 1] - r__1 * r__1 / dds[m - 1]) * iccs[m - 1] / (
		dds[m - 1] * (iccs[m - 1] - 1));
	iwarn = 0;
	if (bbs[m - 1] < -.1f) {
	    iwarn = 1;
	    s_wsfe(&io___1323);
	    do_fio(&c__1, charc_1.stn + (m - 1 << 2), (ftnlen)4);
	    do_fio(&c__1, (char *)&m, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&bbs[m - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* ek           write(6,'(5x,''WARNING: Station = '',a4, */
/* ek     &         5x,''!!! Variance  bb('',i3,'') = '',f7.3,'' < 0 !!'')') */
/* ek     &         stn(m),m,bb(m) */
/* ek           write(6,*) */
	} else {
	    bbs[m - 1] = (r__1 = bbs[m - 1], dabs(r__1));
	}
	if (iwarn == 0) {
	    bbs[m - 1] = sqrt(bbs[m - 1]);
	} else {
	    bbs[m - 1] = 0.f;
	}
	aas[m - 1] /= dds[m - 1];
	ees[m - 1] /= iccs[m - 1];

/*   (nsp=3): */
	if (modela_1.nsp == 3) {
	    stcor1 = statn_1.ptcor[m - 1] * layvel_1.vpvs;
/*   (nsp=2): */
	} else {
	    stcor1 = statn_1.stcor[m - 1];
	}

/* ek  phz(1)=  S-phases */

/* ek         if(iwarn.eq.0)then */
	s_wsfe(&io___1325);
	do_fio(&c__1, charc_1.stn + (m - 1 << 2), (ftnlen)4);
	do_fio(&c__1, phz, (ftnlen)1);
	do_fio(&c__1, (char *)&iccs[m - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ees[m - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&aas[m - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&bbs[m - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&dds[m - 1], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&stcor1, (ftnlen)sizeof(real));
	e_wsfe();
/* ek         else */
/* ek            write(16,'(1x,a4,3x,a1,i4,2f8.4,''   ?.?.?''1x,2f8.4, */
/* ek     &              '' <--- !!'')') */
/* ek     &             stn(m),phz(1),iccs(m),ees(m),aas(m),dds(m),stcor1 */
/* ek            iwarn=0 */
/* ek         endif */

/* L14: */
L39:
L13:
	;
    }

/* end loop print one station */

    s_wsle(&io___1326);
    e_wsle();
    s_wsle(&io___1327);
    e_wsle();
    if (outputfiles_1.istaout > 0) {
	s_wsle(&io___1328);
	e_wsle();
	cl__1.cerr = 0;
	cl__1.cunit = 12;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }

/* hrm  Output of the final model */

    if (outputfiles_1.istaout == 2) {
	o__1.oerr = 0;
	o__1.ounit = 12;
	o__1.ofnmlen = 10;
	o__1.ofnm = "velout.mod";
	o__1.orl = 0;
	o__1.osta = "unknown";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
	s_wsle(&io___1329);
	do_lio(&c__9, &c__1, "Output model:", (ftnlen)13);
	e_wsle();
/* 	 write(12,*)(nplay(m),m=1,nmod) */
	i__1 = modela_1.nmod;
	for (m = 1; m <= i__1; ++m) {
	    s_wsle(&io___1330);
	    do_lio(&c__3, &c__1, (char *)&modela_1.nplay[m - 1], (ftnlen)
		    sizeof(integer));
	    e_wsle();
	    i__2 = modela_1.nplay[m - 1];
	    for (i__ = 1; i__ <= i__2; ++i__) {
		s_wsfe(&io___1331);
		do_fio(&c__1, (char *)&layvel_1.vp[m + (i__ << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.hp[m + (i__ << 1) - 3], (
			ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&layvel_1.vdamp[m + (i__ << 1) - 3], (
			ftnlen)sizeof(real));
		e_wsfe();
	    }
	}
	cl__1.cerr = 0;
	cl__1.cunit = 12;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    return 0;
} /* finalstaresi_ */


/* ek   end of vel_kern.f */

/* ek    begin of vel_mag.f */

/* of subr. finalstaresi */
/* Subroutine */ int magnitude_(integer *ievent, integer *itime)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static real voltgain;
    static integer i__, ier;
    extern /* Subroutine */ int muk_(real *, real *, char *, integer *, real *
	    , real *, real *, real *, real *, real *, real *, ftnlen);
    static real xmag;
    static integer isamp;
    static char ifilt[2];
    static integer iscon, iseis, isdmp;
    extern /* Subroutine */ int stinp_(integer *, char *, char *, integer *, 
	    integer *, integer *, integer *, real *, integer *, ftnlen, 
	    ftnlen);
    static real cormag, sdampf, sconst;
    static char staname[4];

    /* Fortran I/O blocks */
    static icilist io___1334 = { 0, staname, 0, "(a4)", 4, 1 };



/*     calculate magnitude for an event with depth Z and NRP observations */

/* Urs Kradolfer, July 1987 */

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

    event_1.nmag = 0;
    event_1.xmagnitude = 0.f;
    event_1.sdxmagnitude = 0.f;
    i__1 = obb_1.knobs[*ievent - 1];
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (obb_1.kpwt[i__ + *ievent * 650 - 651] > 4) {
	    goto L40;
	}
/*                              station# are stored in array  ISTM(iobs,ievent) */
/*                              smn(iobs,iev)  is the station-name */
/* weights > 4 are no readings!! */
	s_wsfi(&io___1334);
	do_fio(&c__1, charc_1.smn + (i__ + *ievent * 650 - 651 << 2), (ftnlen)
		4);
	e_wsfi();
	stinp_(itime, staname, ifilt, &iseis, &iscon, &isdmp, &isamp, &cormag,
		 &ier, (ftnlen)4, (ftnlen)2);
	if (ier < 0) {
	    goto L40;
	}
/* seismo-parameters of station not found */
	if (event_1.iyr[*ievent - 1] >= 1984 && s_cmp(ifilt, "DE", (ftnlen)2, 
		(ftnlen)2) == 0) {
	    s_copy(ifilt, "AD", (ftnlen)2, (ftnlen)2);
	}
	sconst = (real) iscon / 10.f;
	sdampf = (real) isdmp / 10.f;
	voltgain = (real) isamp;
/* Computing 2nd power */
	r__1 = event_1.e[(*ievent << 2) - 3] - statn_1.d__[i__ + (*ievent * 3 
		+ 1) * 650 - 2601];
/* Computing 2nd power */
	r__2 = event_1.e[(*ievent << 2) - 2] - statn_1.d__[i__ + (*ievent * 3 
		+ 2) * 650 - 2601];
	layer_1.delta = sqrt(r__1 * r__1 + r__2 * r__2);
	xmag = 0.f;
	muk_(&layer_1.delta, &event_1.e[(*ievent << 2) - 1], ifilt, &iseis, &
		sconst, &sdampf, &voltgain, &cormag, &obb_1.amx[i__ - 1], &
		obb_1.prx[i__ - 1], &event_1.xmagni[i__ - 1], (ftnlen)2);
	if (event_1.xmagni[i__ - 1] == -13.f) {
	    goto L40;
	}
	++event_1.nmag;
	xmag = event_1.xmagni[i__ - 1];
	event_1.xmagnitude += xmag;
/* Computing 2nd power */
	r__1 = xmag;
	event_1.sdxmagnitude += r__1 * r__1;
L40:
	;
    }
    if (event_1.nmag != 0) {
	if (event_1.nmag >= 2) {
	    event_1.sdxmagnitude = sqrt((event_1.nmag * event_1.sdxmagnitude 
		    - event_1.xmagnitude * event_1.xmagnitude) / (
		    event_1.nmag * (event_1.nmag - 1)));
	} else {
	    event_1.sdxmagnitude = 0.f;
	}
	event_1.xmagnitude /= event_1.nmag;
    } else {
	event_1.xmagnitude = 0.f;
    }

    return 0;

/* calculated magnitude is: AVXM +/- SDXM   and all xmagni(1 */
} /* magnitude_ */


/* of subr. magnitude */
/* Subroutine */ int muk_(real *epdist, real *depth, char *ifilter, integer *
	isecpendel, real *seismkonst, real *seismdamp, real *voltgain, real *
	stacor, real *devampl, real *period, real *xmag, ftnlen ifilter_len)
{
    /* Initialized data */

    static real rdelt[12] = { 4.f,6.f,13.f,16.f,28.f,87.f,114.f,120.f,134.f,
	    141.f,146.f,180.f };
    static real sigar[12] = { 6.2f,7.f,7.f,5.8f,6.6f,7.f,7.5f,7.5f,6.9f,7.1f,
	    6.9f,6.9f };

    /* System generated locals */
    real r__1, r__2;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double r_lg10(real *);

    /* Local variables */
    static real epdistkm, a, b;
    static integer i__, iampltype;
    static real ampl;
    extern /* Subroutine */ int mpdr2_(integer *, real *, real *, real *, 
	    real *, real *, integer *, real *);
    static real delta, sigma, boampl, waampl;
    extern /* Subroutine */ int ufwabo_(integer *, real *, real *, real *, 
	    real *, real *, integer *, real *, char *, ftnlen);


/* ------------------------------- Urs Kradolfer 1984 ------------------- */

/*     Berechnet die Magnitude Ml fuer Epizentraldistanz <=  700 km */
/*     Berechnet die Magnitude Mb fuer Epizentraldistanz > 2200 km */

/*     Input: */
/*             Epizentraldistanz         [km]       epdist  >=0.  {real} */
/*                    "                  [deg]      epdist  < 0.  {real} */
/*             Herdtiefe                 [km]       depth         {real} */
/*             filter-typ (z.b. DE, AD, PD)         filter-typ    {char} */
/*             Seismometer-Grenzperiode  [sec]      isecpendel    {integer} */
/*                  "     -Konstante     [V/(cm/s)] seismkonst    {real} */
/*                  "     -Daempfung     [1]        seismdamp     {real} */
/*             Verstaerkung (Elektronik) [1]        voltgain      {real} */
/*             Stationskorrektur         [Mag]      stacor        {real} */
/*             Max. Ablese-Amplitude     [mm]       devampl       {real} */
/*                 (Devco oder Plot) */
/*             dominierende Periode      [sec]      period        {real} */

/*     Output: Magnitude (Ml oder Mb)    [Mag]      xmag          {real} */

/*        >>   Falls die Magnitude nicht berechnet werden kann, erfolgt */
/*        >>   ein RETURN und der Output-Parameter xmag wird -13. gesetzt! */

/*     Zur Subr. muk gehoert ebenfalls die Subr. UFWABO und die */
/*     zur letzteren gehoerenden vier Complex-Functions. */
/* --------------------------------------------------------------------------- */


    if (*isecpendel <= 0 || *seismkonst <= 0.f || *seismdamp <= 0.f || *
	    voltgain <= 0.f || *devampl <= 0.f || *period <= 0.f) {
	*xmag = -13.f;
/* Magnitude kann nicht berechnet werden */
	return 0;
    }
    *xmag = -13.f;
/* falls xmag nicht anders berechnet wird !! */
    if (*epdist < 0.f) {
	epdistkm = -(*epdist) / 360.f * 40030;
/* epdist < 0. --> [epdist] = G */
    } else {
/* Computing 2nd power */
	r__1 = *epdist;
/* Computing 2nd power */
	r__2 = *depth;
	epdistkm = sqrt(r__1 * r__1 + r__2 * r__2);
    }
    if (epdistkm <= 2200.f) {
	iampltype = 1;
    }
/* Wood-Anderson --> Ml */
    if (epdistkm > 2200.f) {
	iampltype = 2;
    }
/* Bodenbewegung --> Mb */
    if (s_cmp(ifilter, "DE", (ftnlen)2, (ftnlen)2) == 0 || s_cmp(ifilter, 
	    "AD", (ftnlen)2, (ftnlen)2) == 0) {
	ufwabo_(isecpendel, seismkonst, seismdamp, voltgain, devampl, period, 
		&iampltype, &ampl, ifilter, (ftnlen)2);
    }
    if (s_cmp(ifilter, "PD", (ftnlen)2, (ftnlen)2) == 0) {
	mpdr2_(isecpendel, seismkonst, seismdamp, voltgain, devampl, period, &
		iampltype, &ampl);
    }
    if (ampl <= 1e-10f) {
	*xmag = -13.f;
/* avoid taking LOG of non-positive value !!! */
	return 0;
    }
    if (iampltype == 1) {
	waampl = ampl / 2.f;
    }
/* p-p-Ampl. --> 0-p-Ampl. */
    if (iampltype == 2) {
	boampl = ampl;
    }
    if (epdistkm > 2200.f) {
	delta = epdistkm / 40030.f * 360.f;
/* delta:=epdistkm in Grad */
	if (delta > 180.f) {
	    delta = 180.f;
	    sigma = sigar[11];
	    goto L2;
	}
	i__ = 0;
L1:
	++i__;
	if (delta > rdelt[i__ - 1]) {
	    goto L1;
	}
/* jetzt ist delta < rdelt(i)     --> Linearisieren */
/* y=a*x+b */
	a = (sigar[i__ - 1] - sigar[i__ - 2]) / (rdelt[i__ - 1] - rdelt[i__ - 
		2]);
	b = sigar[i__ - 1] - a * rdelt[i__ - 1];
	sigma = a * delta + b;
L2:
	r__1 = boampl / *period;
	*xmag = r_lg10(&r__1) + sigma + *stacor;
	return 0;
    }
    if (epdistkm > 0.f && epdistkm <= 60.f) {
	*xmag = r_lg10(&waampl) + epdistkm * .018f + 1.77f + .4f;
    }
    if (epdistkm > 60.f && epdistkm <= 700.f) {
	*xmag = r_lg10(&waampl) + epdistkm * .0038f + 2.62f + .4f;
    }
    if (epdistkm > 1100.f && epdistkm <= 1700.f) {
	*xmag = r_lg10(&waampl) + epdistkm * .0029f + 3.4f + .4f - 2.f;
/* EMPIRI */
    }
    if (*xmag == -13.f) {
	return 0;
    }
/* xmag konnte nicht berechnet werden */
    *xmag += *stacor;

/* Stationskorrektur Cs */
    return 0;
} /* muk_ */


/* Subroutine */ int mpdr2_(integer *isecpendel, real *seismkonst, real *
	seismdamp, real *voltgain, real *pdrampl, real *period, integer *
	iampltyp, real *ampl)
{
    /* Initialized data */

    static real zpi = 6.28319f;
    static complex j = {0.f,1.f};

    /* System generated locals */
    real r__1, r__2, r__3, r__4;
    doublereal d__1;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7, q__8;

    /* Builtin functions */
    void c_div(complex *, complex *, complex *);
    double c_abs(complex *);

    /* Local variables */
    static complex g;
    static real s, hs, om, hw, ts, om2;
    static complex ghp, jom;
    static real twa, vwa, omw, omg1;
    static complex glp2, glp3;
    static real omg2, omg3, omg4, omg5;
    static complex glp2a, gseis;


/* ------------------------------------ Kaspar G. Renggli 1984 --------------- */

/*     bodenamliptude fuer pdr2-stationen des nw-ch-netzes */
/*     parameter wie bei subr. muk, ausser pdrampl in [1/10 um/sec] */
/* --------------------------------------------------------------------------- */

    ts = (real) (*isecpendel);
    s = *seismkonst;
    hs = *seismdamp;
    om = zpi / *period;
    q__1.r = om * j.r, q__1.i = om * j.i;
    jom.r = q__1.r, jom.i = q__1.i;
/* Computing 2nd power */
    r__1 = om;
    om2 = r__1 * r__1;
/* -----Uebertragungsfunktionen fuer Seismometer und Filter des PDR-2-Systems--- */

/* ------------ Seismometer als Wegaufnehmer (nur Mechanik) ------------- */
    omg1 = zpi / ts;
    q__2.r = om2 * jom.r, q__2.i = om2 * jom.i;
/* Computing 2nd power */
    r__2 = omg1;
    r__1 = r__2 * r__2;
    d__1 = 2.;
    q__7.r = d__1 * jom.r, q__7.i = d__1 * jom.i;
    q__6.r = omg1 * q__7.r, q__6.i = omg1 * q__7.i;
    q__5.r = hs * q__6.r, q__5.i = hs * q__6.i;
    q__4.r = r__1 + q__5.r, q__4.i = q__5.i;
    q__3.r = q__4.r - om2, q__3.i = q__4.i;
    c_div(&q__1, &q__2, &q__3);
    gseis.r = q__1.r, gseis.i = q__1.i;
/* ------------- 2 Hochpaesse 1. Ordnung  =>  2. Ordnung, fc=0.3 Hz ----- */
    omg2 = zpi * .3f;
    d__1 = 2.;
    q__6.r = d__1 * j.r, q__6.i = d__1 * j.i;
    q__5.r = omg2 * q__6.r, q__5.i = omg2 * q__6.i;
    q__4.r = q__5.r / om, q__4.i = q__5.i / om;
    q__3.r = 1 - q__4.r, q__3.i = -q__4.i;
/* Computing 2nd power */
    r__2 = omg2;
    r__1 = r__2 * r__2 / om2;
    q__2.r = q__3.r - r__1, q__2.i = q__3.i;
    c_div(&q__1, &c_b3023, &q__2);
    ghp.r = q__1.r, ghp.i = q__1.i;
/* ------------- Butterworth Tiefpass 2. Ordnung, fc=30.Hz -------------- */
    omg3 = zpi * 30.f;
    q__6.r = j.r * 1.4142f, q__6.i = j.i * 1.4142f;
    q__5.r = om * q__6.r, q__5.i = om * q__6.i;
    q__4.r = q__5.r / omg3, q__4.i = q__5.i / omg3;
    q__3.r = q__4.r + 1, q__3.i = q__4.i;
/* Computing 2nd power */
    r__2 = omg3;
    r__1 = om2 / (r__2 * r__2);
    q__2.r = q__3.r - r__1, q__2.i = q__3.i;
    c_div(&q__1, &c_b3023, &q__2);
    glp2.r = q__1.r, glp2.i = q__1.i;
/* ----------- Butterworth Tiefpass 3.Ordnung, fc=25 Hz (Discriminator)---- */
    omg4 = zpi * 25.f;
    d__1 = 2.;
    q__6.r = d__1 * j.r, q__6.i = d__1 * j.i;
    q__5.r = q__6.r / omg4, q__5.i = q__6.i / omg4;
    q__4.r = q__5.r + 1, q__4.i = q__5.i;
/* Computing 2nd power */
    r__2 = omg4;
    r__1 = om2 * 2 / (r__2 * r__2);
    q__3.r = q__4.r - r__1, q__3.i = q__4.i;
    q__8.r = om2 * jom.r, q__8.i = om2 * jom.i;
/* Computing 3rd power */
    r__4 = omg4;
    r__3 = r__4 * (r__4 * r__4);
    q__7.r = q__8.r / r__3, q__7.i = q__8.i / r__3;
    q__2.r = q__3.r - q__7.r, q__2.i = q__3.i - q__7.i;
    c_div(&q__1, &c_b3023, &q__2);
    glp3.r = q__1.r, glp3.i = q__1.i;
/* ----------- Butterworth Tiefpass 2.Ordnung, fc=24 Hz (Antialiasing) ---- */
    omg5 = zpi * 24.f;
    q__5.r = jom.r * 1.4142f, q__5.i = jom.i * 1.4142f;
    q__4.r = q__5.r / omg5, q__4.i = q__5.i / omg5;
    q__3.r = q__4.r + 1, q__3.i = q__4.i;
/* Computing 2nd power */
    r__2 = omg5;
    r__1 = om2 / (r__2 * r__2);
    q__2.r = q__3.r - r__1, q__2.i = q__3.i;
    c_div(&q__1, &c_b3023, &q__2);
    glp2a.r = q__1.r, glp2a.i = q__1.i;
/* ----------- Uebertragungsfunktion des gesamten Systems ----------------- */
    q__4.r = gseis.r * ghp.r - gseis.i * ghp.i, q__4.i = gseis.r * ghp.i + 
	    gseis.i * ghp.r;
    q__3.r = q__4.r * glp2.r - q__4.i * glp2.i, q__3.i = q__4.r * glp2.i + 
	    q__4.i * glp2.r;
    q__2.r = q__3.r * glp3.r - q__3.i * glp3.i, q__2.i = q__3.r * glp3.i + 
	    q__3.i * glp3.r;
    q__1.r = q__2.r * glp2a.r - q__2.i * glp2a.i, q__1.i = q__2.r * glp2a.i + 
	    q__2.i * glp2a.r;
    g.r = q__1.r, g.i = q__1.i;
/* ---- Deconvolution mit der Uebertragungsfunktion eines Wood-Anderson-Seism. */
    twa = .8f;
    omw = zpi / twa;
    hw = .78f;
    vwa = 2800.f;
    r__1 = om2 * vwa;
    q__3.r = r__1, q__3.i = 0.f;
/* Computing 2nd power */
    r__3 = omw;
    r__2 = r__3 * r__3;
    d__1 = 2.;
    q__8.r = d__1 * jom.r, q__8.i = d__1 * jom.i;
    q__7.r = omw * q__8.r, q__7.i = omw * q__8.i;
    q__6.r = hw * q__7.r, q__6.i = hw * q__7.i;
    q__5.r = r__2 + q__6.r, q__5.i = q__6.i;
    q__4.r = q__5.r - om2, q__4.i = q__5.i;
    c_div(&q__2, &q__3, &q__4);
    c_div(&q__1, &q__2, &g);
    g.r = q__1.r, g.i = q__1.i;
    *ampl = c_abs(&g);
/* [sec] Amplitudengang = Betrag der kompl. Transferfk */
    *ampl = *ampl * *pdrampl / 1e4f;
/* [sec*1/10um/sec*1/1000=mm] */
    return 0;
} /* mpdr2_ */


/* Subroutine */ int ufwabo_(integer *isecpendel, real *seismkonst, real *
	seismdamp, real *voltgain, real *devampl, real *period, integer *
	iampltype, real *ampl, char *ifilter, ftnlen ifilter_len)
{
    /* Initialized data */

    static real zpi = 6.28319f;
    static complex j = {0.f,1.f};

    /* System generated locals */
    real r__1, r__2, r__3;
    doublereal d__1;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7, q__8;

    /* Builtin functions */
    void c_div(complex *, complex *, complex *), pow_ci(complex *, complex *, 
	    integer *);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double c_abs(complex *);

    /* Local variables */
    static real amplresp;
    static complex g;
    static integer i__;
    static real s;
    static complex g1, g2;
    extern /* Complex */ VOID b6_(complex *, real *);
    static real t01, t02, hs, om, hw, ts;
    extern /* Complex */ VOID hp1_(complex *, real *);
    static real om0, om2, o0w;
    extern /* Complex */ VOID dev_(complex *, real *);
    static complex jom;
    static real twa, vwa, omg1, omg2, tau1, tau2, gain;
    extern /* Complex */ VOID sts373_(complex *, real *);
    static integer iline;
    static complex gseismb;

/* ---- subr. UFWABO --------------------------------------------------- */

/*     Berechnet die komplexe Uebertragungsfunktion im Frequenzbereich */
/*     fuer das System 'Bodenbewegung --> Devco-Auswertetisch' bzw. */
/*     fuer das System 'Bodenbewegung --> ADC (Mini)' */

/*     Options: iampltype = 1  --> [ampl] = mm(Wood-Anderson)/mm(Devco) */
/*              iampltype = 2  --> [ampl] = Mikron(Bodenbewegung)/mm(Devco) */

/*              ifilter   = 'DE' --> devampl von Develocorder */
/*              ifilter   = 'AD' --> devampl von ADC */

/*     Zur Subr. UFWABO gehoeren ebenfalls die Complex-Functions: */
/*     HP1, STS373, DEV und B6. */
/* -------------------------------------------------------------------------- */


/* ---- Spezifikation der Hochpaesse auf der Gesamtuebertragung (PREampl. --> */
/* ---- ADC) wie mit Programm Calap berechnet (bzw. verifiziert) */

    iline = *isecpendel;
    if (iline == 1) {
	t02 = 11.9f;
/* 1-sec-Linie */
	t01 = 3.7f;
/*     '' */
    }
    if (iline == 2) {
	t02 = 12.7f;
/* 2-sec-Linie */
	t01 = 112.f;
/*     '' */
    }
    ts = (real) (*isecpendel);
    s = *seismkonst;
    hs = *seismdamp;

/* ---- Berechnung der Uebertragungsfunktion {Bodenbewegung --> ADC} --- */

    om = zpi / *period;
    q__1.r = om * j.r, q__1.i = om * j.i;
    jom.r = q__1.r, jom.i = q__1.i;
/* Computing 2nd power */
    r__1 = om;
    om2 = r__1 * r__1;

/* --------------------------- HP 2. Ordnung ---------------------------- */
/* --------------------------- zus.gesetzt aus 2 HP 1. Ordnung ---------- */
    omg2 = zpi * 1.f / t02;
    tau2 = 1.f / omg2;

    q__1.r = tau2 * jom.r, q__1.i = tau2 * jom.i;
    g2.r = q__1.r, g2.i = q__1.i;
    q__3.r = g2.r + 1.f, q__3.i = g2.i;
    c_div(&q__2, &g2, &q__3);
    pow_ci(&q__1, &q__2, &c__2);
    g2.r = q__1.r, g2.i = q__1.i;
/* --------------------------- HP 1. Ordnung ---------------------------- */
    omg1 = zpi * 1.f / t01;
    tau1 = 1.f / omg1;

    q__1.r = tau1 * jom.r, q__1.i = tau1 * jom.i;
    g1.r = q__1.r, g1.i = q__1.i;
    q__2.r = g1.r + 1.f, q__2.i = g1.i;
    c_div(&q__1, &g1, &q__2);
    g1.r = q__1.r, g1.i = q__1.i;
/* ----- Seismometer ---------------------------------------------------- */
/* L100: */
    om0 = zpi / ts;
/* fuer Bodenbewegung ------------------------------------------ */
    q__3.r = om2 * jom.r, q__3.i = om2 * jom.i;
    q__2.r = s * q__3.r, q__2.i = s * q__3.i;
/* Computing 2nd power */
    r__2 = om0;
    r__1 = r__2 * r__2;
    d__1 = 2.;
    q__8.r = d__1 * jom.r, q__8.i = d__1 * jom.i;
    q__7.r = om0 * q__8.r, q__7.i = om0 * q__8.i;
    q__6.r = hs * q__7.r, q__6.i = hs * q__7.i;
    q__5.r = r__1 + q__6.r, q__5.i = q__6.i;
    q__4.r = q__5.r - om2, q__4.i = q__5.i;
    c_div(&q__1, &q__2, &q__4);
    gseismb.r = q__1.r, gseismb.i = q__1.i;
/* ---------------------------------------------------------------------- */

/* ---- Die Uebertragungsfunktionen wurden urspruenglich via ADC berechnet */
/*     (WK Kradi ~1983) und demzufolge ist der anti-alias-Filter schon */
/*     in der Uebertragungsfunktion mit inbegriffen. Um die Uebertragungs- */
/*     funktionen nur bis zum Diskriminator zu berechnen, muss dieser */
/*     Filter rueckgaengig gemacht werden: */
/* ---- Inverse Uebertragung des DC-Unterdrueckungs-HP vor ADC */

/* [V/cm] */
    q__3.r = g1.r * g2.r - g1.i * g2.i, q__3.i = g1.r * g2.i + g1.i * g2.r;
    q__2.r = q__3.r * gseismb.r - q__3.i * gseismb.i, q__2.i = q__3.r * 
	    gseismb.i + q__3.i * gseismb.r;
    hp1_(&q__4, &om);
    c_div(&q__1, &q__2, &q__4);
    g.r = q__1.r, g.i = q__1.i;
/* ---- (damit sind wir beim Diskriminator) */

    if (s_cmp(ifilter, "DE", ifilter_len, (ftnlen)2) == 0) {

/*        Uebertragung {Diskriminator --> Vergroesserungsschirm} */

	sts373_(&q__3, &om);
	q__2.r = g.r * q__3.r - g.i * q__3.i, q__2.i = g.r * q__3.i + g.i * 
		q__3.r;
	dev_(&q__4, &om);
	q__1.r = q__2.r * q__4.r - q__2.i * q__4.i, q__1.i = q__2.r * q__4.i 
		+ q__2.i * q__4.r;
	g.r = q__1.r, g.i = q__1.i;
/* Bis jetzt [mm Devco/mm Bodenbew.] */

    }

    if (s_cmp(ifilter, "AD", ifilter_len, (ftnlen)2) == 0) {

/*        Uebertragung {Diskriminator --> ADC } */

	hp1_(&q__3, &om);
	q__2.r = g.r * q__3.r - g.i * q__3.i, q__2.i = g.r * q__3.i + g.i * 
		q__3.r;
	b6_(&q__4, &om);
	q__1.r = q__2.r * q__4.r - q__2.i * q__4.i, q__1.i = q__2.r * q__4.i 
		+ q__2.i * q__4.r;
	g.r = q__1.r, g.i = q__1.i;
/* Bis jetzt [volt/cm Bodenbewegung] */
	gain = 16.f;
/* [plot mm / volt]   (Ablesung ist so skaliert) */
	q__1.r = g.r / 10.f, q__1.i = g.i / 10.f;
	g.r = q__1.r, g.i = q__1.i;
/* [volt/mm Bodenbewegung] */
	q__1.r = gain * g.r, q__1.i = gain * g.i;
	g.r = q__1.r, g.i = q__1.i;

/* [mm plot/mm Bodenbewegung] */
    }

/* ---- Umrechnung in Mikron/Devco-Millimeter  bzw. */
/* ---- Deconvolution mit der Uebertragungsfunktion eines Wood-Anderson-Seism. */

    i__ = *iampltype;
/* !! Ablesung = devco oder plot */
    if (i__ == 2) {
	q__1.r = g.r / 1e3f, q__1.i = g.i / 1e3f;
	g.r = q__1.r, g.i = q__1.i;
/* jetzt: mm Ablesung/um Bodenbewegung */
	goto L999;
    }
    if (i__ == 1) {
	twa = .8f;
	o0w = zpi / twa;
	hw = .78f;
	vwa = 2800.f;
	r__1 = om2 * vwa;
	q__3.r = r__1, q__3.i = 0.f;
/* Computing 2nd power */
	r__3 = o0w;
	r__2 = r__3 * r__3;
	d__1 = 2.;
	q__8.r = d__1 * jom.r, q__8.i = d__1 * jom.i;
	q__7.r = o0w * q__8.r, q__7.i = o0w * q__8.i;
	q__6.r = hw * q__7.r, q__6.i = hw * q__7.i;
	q__5.r = r__2 + q__6.r, q__5.i = q__6.i;
	q__4.r = q__5.r - om2, q__4.i = q__5.i;
	c_div(&q__2, &q__3, &q__4);
	c_div(&q__1, &g, &q__2);
	g.r = q__1.r, g.i = q__1.i;
/*                                             ! [1]     nur Wegvergr. !! */
/* jetzt: mm Ablesung/mm Wood-Anderson ! */
	goto L999;
    }

L999:
    amplresp = c_abs(&g);

/* Amplitudengang := Betrag der kompl. Transferf */
    *ampl = *devampl / (*voltgain * amplresp);

/* fuer IAMPLTYPE =          1          |           2 */
/* dann [ampl]    = [mm Wood-Anderson]  |  [um Bodenbewegung] */

/* erst hier reziproke Einheit */
    return 0;
} /* ufwabo_ */



/* ------------------- B6: Bessel-Filter (TP) ------------------------------ */
/* Complex */ VOID b6_(complex * ret_val, real *om)
{
    /* Initialized data */

    static complex j = {0.f,1.f};
    static real zpi = 6.28319f;

    /* System generated locals */
    real r__1;
    complex q__1, q__2, q__3, q__4;

    /* Builtin functions */
    void c_div(complex *, complex *, complex *);

    /* Local variables */
    static real fg1;
    static complex gbn1, gbn2, gbn3;
    static real omg1;


    fg1 = 12.f;
/* Grenzfrequenz 12 Hz */
    omg1 = *om / (zpi * fg1);

    q__4.r = j.r * 1.2217f, q__4.i = j.i * 1.2217f;
    q__3.r = omg1 * q__4.r, q__3.i = omg1 * q__4.i;
    q__2.r = q__3.r + 1.f, q__2.i = q__3.i;
    r__1 = omg1 * .3887f * omg1;
    q__1.r = q__2.r - r__1, q__1.i = q__2.i;
    gbn1.r = q__1.r, gbn1.i = q__1.i;
    q__4.r = j.r * .9686f, q__4.i = j.i * .9686f;
    q__3.r = omg1 * q__4.r, q__3.i = omg1 * q__4.i;
    q__2.r = q__3.r + 1.f, q__2.i = q__3.i;
    r__1 = omg1 * .3505f * omg1;
    q__1.r = q__2.r - r__1, q__1.i = q__2.i;
    gbn2.r = q__1.r, gbn2.i = q__1.i;
    q__4.r = j.r * .5131f, q__4.i = j.i * .5131f;
    q__3.r = omg1 * q__4.r, q__3.i = omg1 * q__4.i;
    q__2.r = q__3.r + 1.f, q__2.i = q__3.i;
    r__1 = omg1 * .2756f * omg1;
    q__1.r = q__2.r - r__1, q__1.i = q__2.i;
    gbn3.r = q__1.r, gbn3.i = q__1.i;

    q__3.r = gbn1.r * gbn2.r - gbn1.i * gbn2.i, q__3.i = gbn1.r * gbn2.i + 
	    gbn1.i * gbn2.r;
    q__2.r = q__3.r * gbn3.r - q__3.i * gbn3.i, q__2.i = q__3.r * gbn3.i + 
	    q__3.i * gbn3.r;
    c_div(&q__1, &c_b3023, &q__2);
     ret_val->r = q__1.r,  ret_val->i = q__1.i;

} /* b6_ */


/* ------------------- HP 0.1 Hz 1. Ordnung (vor ADC) [DC-Unterdrueckung]- */
/* Complex */ VOID hp1_(complex * ret_val, real *om)
{
    /* Initialized data */

    static complex j = {0.f,1.f};
    static real zpi = 6.28319f;

    /* System generated locals */
    complex q__1, q__2;

    /* Builtin functions */
    void c_div(complex *, complex *, complex *);

    /* Local variables */
    static real fg, tau;

    fg = .1f;
/* [Hz]     Grenzfrequenz */
    tau = 1.f / (zpi * fg);

    q__2.r = *om * j.r, q__2.i = *om * j.i;
    q__1.r = tau * q__2.r, q__1.i = tau * q__2.i;
     ret_val->r = q__1.r,  ret_val->i = q__1.i;
    q__2.r =  ret_val->r + 1.f, q__2.i =  ret_val->i;
    c_div(&q__1,  ret_val, &q__2);
     ret_val->r = q__1.r,  ret_val->i = q__1.i;

    return ;
} /* hp1_ */


/* ------------------- TP STS-373 (Bessel 4. Ordnung, 5 Hz ) ---------- */
/* Complex */ VOID sts373_(complex * ret_val, real *om)
{
    /* Initialized data */

    static complex j = {0.f,1.f};
    static real zpi = 6.28319f;

    /* System generated locals */
    real r__1;
    complex q__1, q__2, q__3, q__4, q__5, q__6;

    /* Builtin functions */
    void pow_ci(complex *, complex *, integer *), c_div(complex *, complex *, 
	    complex *);

    /* Local variables */
    static complex o;
    static real fg1;
    static complex gbn1, gbn2;
    static real omg1;

/*      implicit InTeGeR*4 (i-n) */
    fg1 = 5.f;
    omg1 = zpi * fg1;
    r__1 = *om / omg1;
    o.r = r__1, o.i = 0.f;

    q__4.r = j.r * 1.3397f, q__4.i = j.i * 1.3397f;
    q__3.r = q__4.r * o.r - q__4.i * o.i, q__3.i = q__4.r * o.i + q__4.i * 
	    o.r;
    q__2.r = q__3.r + 1.f, q__2.i = q__3.i;
    pow_ci(&q__6, &o, &c__2);
    q__5.r = q__6.r * .4889f, q__5.i = q__6.i * .4889f;
    q__1.r = q__2.r - q__5.r, q__1.i = q__2.i - q__5.i;
    gbn1.r = q__1.r, gbn1.i = q__1.i;
    q__4.r = j.r * .7743f, q__4.i = j.i * .7743f;
    q__3.r = q__4.r * o.r - q__4.i * o.i, q__3.i = q__4.r * o.i + q__4.i * 
	    o.r;
    q__2.r = q__3.r + 1.f, q__2.i = q__3.i;
    pow_ci(&q__6, &o, &c__2);
    q__5.r = q__6.r * .389f, q__5.i = q__6.i * .389f;
    q__1.r = q__2.r - q__5.r, q__1.i = q__2.i - q__5.i;
    gbn2.r = q__1.r, gbn2.i = q__1.i;

    q__2.r = gbn1.r * gbn2.r - gbn1.i * gbn2.i, q__2.i = gbn1.r * gbn2.i + 
	    gbn1.i * gbn2.r;
    c_div(&q__1, &c_b3023, &q__2);
     ret_val->r = q__1.r,  ret_val->i = q__1.i;

    return ;
} /* sts373_ */


/* ------------------- Develocorder & 12-fache Schirmvergroesserung ----- */
/* Complex */ VOID dev_(complex * ret_val, real *om)
{
    /* Initialized data */

    static complex j = {0.f,1.f};
    static real zpi = 6.28319f;

    /* System generated locals */
    complex q__1, q__2, q__3, q__4, q__5, q__6;

    /* Builtin functions */
    void c_div(complex *, complex *, complex *), pow_ci(complex *, complex *, 
	    integer *);

    /* Local variables */
    static real fg, tau;

/* 1.6 cm/V MIT 12-f. Vergr. am Tisch !! */
    fg = 15.f;
/* [Hz]              ! Galvanometer      krit. Daempfung */
    tau = 1.f / (zpi * fg);

/* (TP)              2. Ordnung */
    q__6.r = *om * j.r, q__6.i = *om * j.i;
    q__5.r = tau * q__6.r, q__5.i = tau * q__6.i;
    q__4.r = q__5.r + 1.f, q__4.i = q__5.i;
    c_div(&q__3, &c_b3023, &q__4);
    pow_ci(&q__2, &q__3, &c__2);
    q__1.r = q__2.r * 1.6f, q__1.i = q__2.i * 1.6f;
     ret_val->r = q__1.r,  ret_val->i = q__1.i;

/* !!!!!!!! bei neuen functions diese in Haupt-Subroutine deklarieren  !!! */
/* [cm/V] */
    return ;
} /* dev_ */


/* ek   end of vel_mag.f */

/* ek   begin of vel_math.f */

/* Subroutine */ int storeg_(integer *k, integer *l)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, ii, jj;


/* ---- save column k of g in gcopy */

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

    ii = 0;
    jj = 0;
    i__1 = dimen_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++jj;
	    if (i__ != *k && j != *k) {
		goto L1;
	    }
	    ++ii;
	    gsave_1.gcopy[*l + ii * 60 - 61] = gmatrix_1.g[jj - 1];
L1:
	    ;
	}
    }
    return 0;
} /* storeg_ */


/* of subr. storeg */
/* Subroutine */ int singularvalues_(integer *i__)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen),
	     e_wsfe(void);

    /* Local variables */
    extern /* Subroutine */ int svdsoluk_(real *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *);
    static real a[16]	/* was [4][4] */;
    static integer j, k, i1, ii, jj;
    static real xsol[4];
    extern /* Subroutine */ int alesubr_(real *, integer *, real *);

    /* Fortran I/O blocks */
    static cilist io___1441 = { 0, 16, 0, 0, 0 };
    static cilist io___1442 = { 0, 16, 0, "(1x,4(2x,f10.6))", 0 };
    static cilist io___1443 = { 0, 16, 0, 0, 0 };



/*     compute the singular values (in this case: eigenvalues) of the */
/*     symmetric matrix G. */

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


    i__1 = dimen_1.nvar;
    for (k = 1; k <= i__1; ++k) {
	ii = 0;
	jj = 0;
	i__2 = dimen_1.nvar;
	for (i1 = 1; i1 <= i__2; ++i1) {
	    i__3 = i1;
	    for (j = 1; j <= i__3; ++j) {
		++jj;
		if (! (i1 != k && j != k)) {
		    ++ii;
		    a[k + (ii << 2) - 5] = gmatrix_1.g[jj - 1];
		}
	    }
	}
    }

    svdsoluk_(a, a4_1.rht, &dimen_1.nvar, &c_b3046, xsol, goodness_1.sv, &
	    goodness_1.ale[*i__ - 1], goodness_1.covs, goodness_1.rs);

    if (param_1.ifixsolution == 1) {
	alesubr_(goodness_1.sv, &c__3, &goodness_1.ale[*i__ - 1]);
    }
    if (param_1.ifixsolution == 9) {
	alesubr_(goodness_1.sv, &c__1, &goodness_1.ale[*i__ - 1]);
    }

    if (! coordsyst_1.single_turbo__) {
	s_wsle(&io___1441);
	do_lio(&c__9, &c__1, "Singular values; iteration #", (ftnlen)28);
	do_lio(&c__3, &c__1, (char *)&form_1.nitt, (ftnlen)sizeof(integer));
	e_wsle();
	s_wsfe(&io___1442);
	i__1 = dimen_1.nvar;
	for (jj = 1; jj <= i__1; ++jj) {
	    do_fio(&c__1, (char *)&goodness_1.sv[jj - 1], (ftnlen)sizeof(real)
		    );
	}
	e_wsfe();
	s_wsle(&io___1443);
	do_lio(&c__9, &c__1, "ALE = ", (ftnlen)6);
	do_lio(&c__4, &c__1, (char *)&goodness_1.ale[*i__ - 1], (ftnlen)
		sizeof(real));
	e_wsle();
    }

/* cc      write(16,*)'SVD-solution vector:' */
/* cc      write(16,'(1x,4(2x,f16.6))') (Xsol(jj),jj=1,nvar) */

    return 0;
} /* singularvalues_ */


/* of subr. singularvalues */
/* Subroutine */ int dampg_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k;


/*     apply damping to the diagonal elements of the symmetric matrix G */

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

/*     apply damping to diagonal elements of G-matrix : */

    j = 0;
    i__1 = dimen_1.nvar;
    for (k = 1; k <= i__1; ++k) {
/*   k = 1 2 3  4  5 ... */
	j += k;
/*   j = 1 3 6 10 15 ...   <== diagonal elemen */
	gmatrix_1.g[j - 1] += param_1.othet;
    }

    return 0;
} /* dampg_ */


/* of subr. dampg */
/* Subroutine */ int accunormeqs_(real *rowofa, integer *nvar, real *res, 
	real *w, real *g, real *rhs)
{
    extern /* Subroutine */ int rside_(real *, real *, integer *, real *, 
	    real *), outer_(real *, real *, integer *, real *);


/*     Urs Kradolfer, 22. 4. 1987 */

/*     accumulate normal equations, knowing only one row of A at a time; */
/*     subr. ACCUNORMEQS must be called nvar times (once for */
/*     each observation). */
/*     w is the (normalized ! ) weight of the observation. */

/*        A * x = res          INPUT: one row of A and one element of res */

/*     At*A * x = At*res */

/*       G  * x =  RHS         OUTPUT: G (nvar x nvar) and RHS (nvar) */

    /* Parameter adjustments */
    --rhs;
    --g;
    --rowofa;

    /* Function Body */
    outer_(&g[1], &rowofa[1], nvar, w);
    rside_(&rhs[1], &rowofa[1], nvar, res, w);

    return 0;
} /* accunormeqs_ */


/* of subr. accunormeqs */
/* Subroutine */ int outer_(real *g, real *s, integer *n, real *w)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static real a, b;
    static integer i__, j, nsym;


/*   this routine does an outer product of a vector */
/*   s with itself.  This is used in least squares */
/*   to accumulate (At)A knowing only one */
/*   row of A at a time.  (At)A is a symmetric */
/*   matrix which is n by n.  This matrix is stored */
/*   in the vector g in symmetric storage mode.  Thus, */
/*   given the ith row and jth column of the matrix, then */
/*            nsym=((i*(i-1))/2) + j */
/*   gives the index for the element nsym of g */
/*   for i.ge.j.  For j less than i, the */
/*   element ij is identical to the element ji. */

/*   input: */
/*    s(i) one row of the matrix (A) . */
/*    n - the length of s(i) */
/*    w - a weight for the least squares. */


    /* Parameter adjustments */
    --s;
    --g;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (s[i__] == 0.f) {
	    goto L1;
	}
	a = s[i__] * *w;

	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    if (s[j] == 0.f) {
		goto L2;
	    }
	    b = s[j] * a;

	    nsym = i__ * (i__ - 1) / 2 + j;
	    g[nsym] += b;
L2:
	    ;
	}

L1:
	;
    }
    return 0;
} /* outer_ */


/* of subr. outer */
/* Subroutine */ int rside_(real *rht, real *s, integer *n, real *res, real *
	w)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;


/*   this routine accumulates in rht the quantity (At)b */
/*   for the normal equations. */

/*   input: */
/*    s(i)-one column of the matrix (At) */
/*    n - the length of s(i) */
/*    res - one value of the vector b. */
/*    w  -  a weight for the weighted least sqs. */


    /* Parameter adjustments */
    --s;
    --rht;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (s[i__] == 0.f) {
	    goto L1;
	}
	rht[i__] = *res * *w * s[i__] + rht[i__];
L1:
	;
    }
    return 0;
} /* rside_ */


/* of subr. rside */
/* Subroutine */ int alesubr_(real *sv, integer *m, real *ale)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    double r_lg10(real *);

    /* Local variables */
    static integer i__, izero;
    static real alesum;


/*     Urs Kradolfer, June 1st, 1987 */

/*     Input : Array SV, containing the M singular values */
/*             m , dimension of SV */

/*     Output: ALE-value */

/*             ALE = - 1./(m-izero) * sum(i=1...m) log10( SV(i)/SV(1) ) */
/*                   + izero*10. */

/*             where izero = # zero-singular-values */



    /* Parameter adjustments */
    --sv;

    /* Function Body */
    if (*m == 0) {
	s_stop("ALEsubr>>> m was zero !!!", (ftnlen)25);
    }

    *ale = 0.f;
    alesum = 0.f;
    izero = 0;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*ale = sv[i__] / sv[1];
	if (*ale <= 0.f) {
	    ++izero;
	} else {
	    alesum += r_lg10(ale);
	}
    }
    *ale = -(alesum / (real) (*m - izero)) + izero * 10;

    return 0;
} /* alesubr_ */


/* of subr. alesubr */
/* Subroutine */ int lsvdf_(real *a, integer *ia, integer *m, integer *n, 
	real *b, integer *ib, integer *nb, real *s, real *wk, integer *ier)
{
    /* Initialized data */

    static real zero = 0.f;
    static real one = 1.f;

    /* Format strings */
    static char fmt_4501[] = "(2x,\002SUBR. LSVDF: AT END, IER=\002,i4,\002C"
	    "HECK SUBR. HEAD FOR\002,1x,\002MEANING\002)";

    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, wk_dim1, wk_offset, i__1, 
	    i__2, i__3, i__4;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static real f;
    static integer i__, j, k, l;
    static real t;
    static integer mm, nm, nn, ns, jp1, nnp1, nsp1;
    extern /* Subroutine */ int vhs12_(integer *, integer *, integer *, 
	    integer *, real *, integer *, real *, real *, integer *, integer *
	    , integer *), lsvdb_(real *, real *, integer *, real *, integer *,
	     integer *, real *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___1470 = { 0, 6, 0, fmt_4501, 0 };


/*     This is an IMSL-subroutine */

/*                                  SPECIFICATIONS FOR ARGUMENTS */
/*                                  SPECIFICATIONS FOR LOCAL VARIABLES */
    /* Parameter adjustments */
    wk_dim1 = *n;
    wk_offset = 1 + wk_dim1;
    wk -= wk_offset;
    --s;
    a_dim1 = *ia;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    b_dim1 = *ib;
    b_offset = 1 + b_dim1;
    b -= b_offset;

    /* Function Body */
/*                                  FIRST EXECUTABLE STATEMENT */
    *ier = 0;
/*                                  BEGIN SPECIAL FOR ZERO ROWS AND */
/*                                    COLS. PACK THE NONZERO COLS TO THE */
/*                                    LEFT */
    nn = *n;
    *ier = 34;
    if (nn <= 0 || *m <= 0) {
	goto L9000;
    }
    *ier = 0;
    j = nn;
L5:
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (a[i__ + j * a_dim1] != zero) {
	    goto L25;
	}
/* L10: */
    }
/*                                  COL J IS ZERO. EXCHANGE IT WITH COL */
/*                                    N */
    if (j == nn) {
	goto L20;
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L15: */
	a[i__ + j * a_dim1] = a[i__ + nn * a_dim1];
    }
L20:
    a[nn * a_dim1 + 1] = (real) j;
    --nn;
L25:
    --j;
    if (j >= 1) {
	goto L5;
    }
/*                                  IF N=0 THEN A IS ENTIRELY ZERO AND */
/*                                    SVD COMPUTATION CAN BE SKIPPED */
    ns = 0;
    if (nn == 0) {
	goto L120;
    }
/*                                  PACK NONZERO ROWS TO THE TOP QUIT */
/*                                    PACKING IF FIND N NONZERO ROWS */
    i__ = 1;
    mm = *m;
L30:
    if (i__ > *n || i__ >= mm) {
	goto L75;
    }
    if (a[i__ + i__ * a_dim1] != zero) {
	goto L40;
    }
    i__1 = nn;
    for (j = 1; j <= i__1; ++j) {
	if (a[i__ + j * a_dim1] != zero) {
	    goto L40;
	}
/* L35: */
    }
    goto L45;
L40:
    ++i__;
    goto L30;
/*                                  ROW I IS ZERO EXCHANGE ROWS I AND M */
L45:
    if (*nb <= 0) {
	goto L55;
    }
    i__1 = *nb;
    for (j = 1; j <= i__1; ++j) {
	t = b[i__ + j * b_dim1];
	b[i__ + j * b_dim1] = b[mm + j * b_dim1];
	b[mm + j * b_dim1] = t;
/* L50: */
    }
L55:
    i__1 = nn;
    for (j = 1; j <= i__1; ++j) {
/* L60: */
	a[i__ + j * a_dim1] = a[mm + j * a_dim1];
    }
    if (mm > nn) {
	goto L70;
    }
    i__1 = nn;
    for (j = 1; j <= i__1; ++j) {
/* L65: */
	a[mm + j * a_dim1] = zero;
    }
L70:
/*                                  EXCHANGE IS FINISHED */
    --mm;
    goto L30;

L75:
/*                                  END SPECIAL FOR ZERO ROWS AND */
/*                                    COLUMNS */
/*                                  BEGIN SVD ALGORITHM.. */
/*                                  (1) REDUCE THE MATRIX TO UPPER */
/*                                    BIDIAGONAL FORM WITH HOUSEHOLDER */
/*                                    TRANSFORMATIONS. */
/*                                    H(N)...H(1)AQ(1)...Q(N-2) = */
/*                                    (D**T,0)**T WHERE D IS UPPER */
/*                                    BIDIAGONAL. */
/*                                  (2) APPLY H(N)...H(1) TO B. HERE */
/*                                    H(N)...H(1)*B REPLACES B IN */
/*                                    STORAGE. */
/*                                  (3) THE MATRIX PRODUCT W= */
/*                                    Q(1)...Q(N-2) OVERWRITES THE FIRST */
/*                                    N ROWS OF A IN STORAGE. */
/*                                  (4) AN SVD FOR D IS COMPUTED. HERE K */
/*                                    ROTATIONS RI AND PI ARE COMPUTED */
/*                                    SO THAT RK...R1*D*P1**(T)...PK**(T) */
/*                                    = DIAG(S1,...,SM) TO WORKING */
/*                                    ACCURACY. THE SI ARE NONNEGATIVE */
/*                                    AND NONINCREASING. HERE RK...R1*B */
/*                                    OVERWRITES B IN STORAGE WHILE */
/*                                    A*P1**(T)...PK**(T) OVERWRITES A */
/*                                    IN STORAGE. */
/*                                  (5) IT FOLLOWS THAT,WITH THE PROPER */
/*                                    DEFINITIONS, U**(T)*B OVERWRITES */
/*                                    B, WHILE V OVERWRITES THE FIRST N */
/*                                    ROW AND COLUMNS OF A. */
    l = min(mm,nn);
/*                                  THE FOLLOWING LOOP REDUCES A TO */
/*                                    UPPER BIDIAGONAL AND ALSO APPLIES */
/*                                    THE PREMULTIPLYING TRANSFORMATIONS */
/*                                    TO B. */
    i__1 = l;
    for (j = 1; j <= i__1; ++j) {
	if (j >= mm) {
	    goto L80;
	}
/* Computing MIN */
	i__2 = j + 1;
	jp1 = min(i__2,nn);
	i__2 = j + 1;
	i__3 = nn - j;
	vhs12_(&c__1, &j, &i__2, &mm, &a[j * a_dim1 + 1], &c__1, &t, &a[jp1 * 
		a_dim1 + 1], &c__1, ia, &i__3);
	i__2 = j + 1;
	vhs12_(&c__2, &j, &i__2, &mm, &a[j * a_dim1 + 1], &c__1, &t, &b[
		b_offset], &c__1, ib, nb);
L80:
	if (j >= nn - 1) {
	    goto L85;
	}
	i__2 = j + 1;
	i__3 = j + 2;
	i__4 = mm - j;
	vhs12_(&c__1, &i__2, &i__3, &nn, &a[j + a_dim1], ia, &wk[j + (wk_dim1 
		<< 1)], &a[j + 1 + a_dim1], ia, &c__1, &i__4);
L85:
	;
    }
/*                                  COPY THE BIDIAGONAL MATRIX INTO THE */
/*                                    ARRAY S FOR LSVDB */
    if (l == 1) {
	goto L95;
    }
    i__1 = l;
    for (j = 2; j <= i__1; ++j) {
	s[j] = a[j + j * a_dim1];
	wk[j + wk_dim1] = a[j - 1 + j * a_dim1];
/* L90: */
    }
L95:
    s[1] = a[a_dim1 + 1];

    ns = nn;
    if (mm >= nn) {
	goto L100;
    }
    ns = mm + 1;
    s[ns] = zero;
    wk[ns + wk_dim1] = a[mm + (mm + 1) * a_dim1];
L100:
/*                                  CONSTRUCT THE EXPLICIT N BY N */
/*                                    PRODUCT MATRIX, W=Q1*Q2*...*QL*I */
/*                                    IN THE ARRAY A */
    i__1 = nn;
    for (k = 1; k <= i__1; ++k) {
	i__ = nn + 1 - k;
/* Computing MIN */
	i__2 = mm, i__3 = nn - 2;
	if (i__ > min(i__2,i__3)) {
	    goto L105;
	}
	i__2 = i__ + 1;
	i__3 = i__ + 2;
	i__4 = nn - i__;
	vhs12_(&c__2, &i__2, &i__3, &nn, &a[i__ + a_dim1], ia, &wk[i__ + (
		wk_dim1 << 1)], &a[(i__ + 1) * a_dim1 + 1], &c__1, ia, &i__4);
L105:
	i__2 = nn;
	for (j = 1; j <= i__2; ++j) {
/* L110: */
	    a[i__ + j * a_dim1] = zero;
	}
	a[i__ + i__ * a_dim1] = one;
/* L115: */
    }
/*                                  COMPUTE THE SVD OF THE BIDIAGONAL */
/*                                    MATRIX */

/*      LEVEL=1 */
/*      CALL UERSET(LEVEL,LEVOLD) */
    lsvdb_(&s[1], &wk[wk_dim1 + 1], &ns, &a[a_offset], ia, &nn, &b[b_offset], 
	    ib, nb, ier);
/*                                  TEST FOR IER=33 */

    if (*ier > 128) {
	goto L9000;
    }
/*      CALL UERSET(LEVOLD,LEVOLD) */
    if (*ier != 33) {
	goto L120;
    }
/* uk      WRITE(6,4500) IER */
/* L4500: */
    t = 0.f;
    nm = min(*m,*n);
    if (s[1] != zero) {
	t = s[nm] / s[1];
    }
    f = t + 100.f;
    if (f == 100.f) {
	goto L120;
    }
    *ier = 0;
L120:
    if (ns >= nn) {
	goto L130;
    }
    nsp1 = ns + 1;
    i__1 = nn;
    for (j = nsp1; j <= i__1; ++j) {
/* L125: */
	s[j] = zero;
    }
L130:
    if (nn == *n) {
	goto L155;
    }
    nnp1 = nn + 1;
/*                                  MOVE RECORD OF PERMUTATIONS AND */
/*                                    STORE ZEROS */
    i__1 = *n;
    for (j = nnp1; j <= i__1; ++j) {
	s[j] = a[j * a_dim1 + 1];
	if (nn < 1) {
	    goto L140;
	}
	i__2 = nn;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L135: */
	    a[i__ + j * a_dim1] = zero;
	}
L140:
	;
    }
/*                                  PERMUTE ROWS AND SET ZERO SINGULAR */
/*                                    VALUES */
    i__1 = *n;
    for (k = nnp1; k <= i__1; ++k) {
	i__ = s[k];
	s[k] = zero;
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    a[k + j * a_dim1] = a[i__ + j * a_dim1];
/* L145: */
	    a[i__ + j * a_dim1] = zero;
	}
	a[i__ + k * a_dim1] = one;
/* L150: */
    }
/*                                  END SPECIAL FOR ZERO ROWS AND */
/*                                    COLUMNS */
L155:
    if (*ier == 0) {
	goto L9005;
    }
L9000:
/*      CALL UERTST (IER,'LSVDF ') */
/* uk */
    if (*ier != 33) {
	s_wsfe(&io___1470);
	do_fio(&c__1, (char *)&(*ier), (ftnlen)sizeof(integer));
	e_wsfe();
    }
/* uk */
L9005:
    return 0;
} /* lsvdf_ */


/* Subroutine */ int lsvdb_(real *d__, real *e, integer *n, real *v, integer *
	iv, integer *nrv, real *c__, integer *ic, integer *ncc, integer *ier)
{
    /* Initialized data */

    static real zero = 0.f;
    static real one = 1.f;
    static real two = 2.f;

    /* Format strings */
    static char fmt_4500[] = "(2x,\002SUBR. LSVDB AT END: IER=\002,i4,\002 C"
	    "HECK HEADER FOR\002,\002 MEANING\002)";

    /* System generated locals */
    integer v_dim1, v_offset, c_dim1, c_offset, i__1, i__2, i__3;
    real r__1, r__2, r__3;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static real f, g, h__;
    static integer i__, j, k, l;
    static real t, x, y, z__;
    static integer n10, ii, kk;
    static real cs;
    static integer ll;
    static real sn;
    static integer lp1;
    static logical fail;
    static integer nqrs;
    static logical wntv;
    extern /* Subroutine */ int lsvg1_(real *, real *, real *, real *, real *)
	    , lsvg2_(real *, real *, real *, real *);
    static real dnorm;
    static logical havers;

    /* Fortran I/O blocks */
    static cilist io___1497 = { 0, 6, 0, fmt_4500, 0 };



/*   IMSL ROUTINE NAME   - LSVDB */

/* ----------------------------------------------------------------------- */

/*   COMPUTER            - HP1000/DOUBLE */

/*   LATEST REVISION     - JANUARY 1, 1978 */

/*   PURPOSE             - SINGULAR VALUE DECOMPOSITION OF A BIDIAGONAL */
/*                           MATRIX. */

/*   USAGE               - CALL LSVDB (D,E,N,V,IV,NRV,C,IC,NCC,IER) */

/*   ARGUMENTS    D      - VECTOR OF LENGTH N. (INPUT/OUTPUT) */
/*                         ON INPUT, D CONTAINS THE DIAGONAL ELEMENTS */
/*                           OF THE BIDIAGONAL MATRIX B. D(I)=B(I,I), */
/*                           I=1,...,N. */
/*                         ON OUTPUT, D CONTAINS THE N (NONNEGATIVE) */
/*                           SINGULAR VALUES OF B IN NONINCREASING */
/*                           ORDER. */
/*                E      - VECTOR OF LENGTH N. (INPUT/OUTPUT) */
/*                         ON INPUT, E CONTAINS THE SUPERDIAGONAL */
/*                           ELEMENTS OF B. E(1) IS ARBITRARY, */
/*                           E(I)=B(I-1,I), I=2,...,N. */
/*                         ON OUTPUT, THE CONTENTS OF E ARE MODIFIED */
/*                           BY THE SUBROUTINE. */
/*                N      - ORDER OF THE MATRIX B. (INPUT) */
/*                V      - NRV BY N MATRIX. (INPUT/OUTPUT) */
/*                           IF NRV.LE.0, V IS NOT USED. OTHERWISE, */
/*                           V IS REPLACED BY THE NRV BY N PRODUCT */
/*                           MATRIX V*VB. SEE REMARKS. */
/*                IV     - ROW DIMENSION OF MATRIX V EXACTLY AS */
/*                           SPECIFIED IN THE DIMENSION STATEMENT IN THE */
/*                           CALLING PROGRAM. (INPUT) */
/*                NRV    - NUMBER OF ROWS OF V. (INPUT) */
/*                C      - N BY NCC MATRIX. (INPUT/OUTPUT) */
/*                           IF NCC.LE.0 C IS NOT USED. OTHERWISE, C */
/*                           IS REPLACED BY THE N BY NCC PRODUCT */
/*                           MATRIX UB**(T) * C. SEE REMARKS. */
/*                IC     - ROW DIMENSION OF MATRIX C EXACTLY AS */
/*                           SPECIFIED IN THE DIMENSION STATEMENT IN THE */
/*                           CALLING PROGRAM. (INPUT) */
/*                NCC    - NUMBER OF COLUMNS IN C. (INPUT) */
/*                IER    - ERROR PARAMETER. (INPUT) */
/*                         WARNING ERROR */
/*                           IER=33 INDICATES THAT MATRIX B IS NOT FULL */
/*                             RANK OR VERY ILL-CONDITIONED. SMALL */
/*                             SINGULAR VALUES MAY NOT BE VERY ACCURATE. */
/*                         TERMINAL ERROR */
/*                           IER=129 INDICATES THAT CONVERGENCE WAS */
/*                             NOT ATTAINED AFTER 10*N QR SWEEPS. */
/*                             (CONVERGENCE USUALLY OCCURS IN ABOUT */
/*                             2*N SWEEPS). */

/*   PRECISION/HARDWARE  - SINGLE AND DOUBLE/H32 */
/*                       - SINGLE/H36,H48,H60 */

/*   REQD. IMSL ROUTINES - LSVG1,LSVG2,VHS12,UERTST,UGETIO */

/*   NOTATION            - INFORMATION ON SPECIAL NOTATION AND */
/*                           CONVENTIONS IS AVAILABLE IN THE MANUAL */
/*                           INTRODUCTION OR THROUGH IMSL ROUTINE UHELP */

/*   REMARKS      LSVDB COMPUTES THE SINGULAR VALUE DECOMPOSITION OF */
/*                AN N BY N BIDIAGONAL MATRIX */
/*                     B = UB * S * VB**(T)    WHERE */
/*                UB AND VB ARE N BY N ORTHOGONAL MATRICES AND */
/*                S IS DIAGONAL. */
/*                IF ARGUMENTS V AND C ARE N BY N IDENTITY MATRICES, */
/*                ON EXIT THEY ARE REPLACED BY VB AND UB**T, */
/*                RESPECTIVELY. */

/*   COPYRIGHT           - 1978 BY IMSL, INC. ALL RIGHTS RESERVED. */

/*   WARRANTY            - IMSL WARRANTS ONLY THAT IMSL TESTING HAS BEEN */
/*                           APPLIED TO THIS CODE. NO OTHER WARRANTY, */
/*                           EXPRESSED OR IMPLIED, IS APPLICABLE. */

/* ----------------------------------------------------------------------- */

/*                                  SPECIFICATIONS FOR ARGUMENTS */
/* uk      real    D(N),E(N),V(IV,1),C(IC,1) */
/*                                  SPECIFICATIONS FOR LOCAL VARIABLES */
    /* Parameter adjustments */
    --e;
    --d__;
    v_dim1 = *iv;
    v_offset = 1 + v_dim1;
    v -= v_offset;
    c_dim1 = *ic;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;

    /* Function Body */
/*                                  FIRST EXECUTABLE STATEMENT */
    *ier = 0;
    if (*n <= 0) {
	goto L9005;
    }
    n10 = *n * 10;
    wntv = *nrv > 0;
    havers = *ncc > 0;
    fail = FALSE_;
    nqrs = 0;
    e[1] = zero;
    dnorm = zero;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
/* L5: */
/* Computing MAX */
	r__3 = (r__1 = d__[j], dabs(r__1)) + (r__2 = e[j], dabs(r__2));
	dnorm = (real) ((integer) dmax(r__3,dnorm));
    }
    i__1 = *n;
    for (kk = 1; kk <= i__1; ++kk) {
	k = *n + 1 - kk;
/*                                  TEST FOR SPLITTING OR RANK */
/*                                    DEFICIENCIES FIRST MAKE TEST FOR */
/*                                    LAST DIAGONAL TERM, D(K), BEING */
/*                                    SMALL. */
L10:
	if (k == 1) {
	    goto L25;
	}
	t = dnorm + d__[k];
	if (t != dnorm) {
	    goto L25;
	}

/*                                  SINCE D(K) IS SMALL WE WILL MAKE A */
/*                                    SPECIAL PASS TO TRANSFORM E(K) TO */
/*                                    ZERO. */
	cs = zero;
	sn = -one;
	i__2 = k;
	for (ii = 2; ii <= i__2; ++ii) {
	    i__ = k + 1 - ii;
	    f = -sn * e[i__ + 1];
	    e[i__ + 1] = cs * e[i__ + 1];
	    t = d__[i__];
	    lsvg1_(&t, &f, &cs, &sn, &d__[i__]);
/*                                  TRANSFORMATION CONSTRUCTED TO ZERO */
/*                                    POSITION (I,K). */
	    if (! wntv) {
		goto L20;
	    }
	    i__3 = *nrv;
	    for (j = 1; j <= i__3; ++j) {
/* L15: */
		lsvg2_(&cs, &sn, &v[j + i__ * v_dim1], &v[j + k * v_dim1]);
	    }

/*                                  ACCUMULATE RT. TRANSFORMATIONS IN V. */
L20:
	    ;
	}
/*                                  THE MATRIX IS NOW BIDIAGONAL, AND OF */
/*                                    LOWER ORDER SINCE E(K) .EQ. ZERO */
L25:
	i__2 = k;
	for (ll = 1; ll <= i__2; ++ll) {
	    l = k + 1 - ll;
	    t = dnorm + e[l];
	    if (t == dnorm) {
		goto L50;
	    }
	    t = dnorm + d__[l - 1];
	    if (t == dnorm) {
		goto L35;
	    }
/* L30: */
	}
/*                                  THIS LOOP CANT COMPLETE SINCE E(1) = */
/*                                    ZERO. */
	goto L50;
/*                                  CANCELLATION OF E(L), L.GT.1. */
L35:
	cs = zero;
	sn = -one;
	i__2 = k;
	for (i__ = l; i__ <= i__2; ++i__) {
	    f = -sn * e[i__];
	    e[i__] = cs * e[i__];
	    t = dnorm + f;
	    if (t == dnorm) {
		goto L50;
	    }
	    t = d__[i__];
	    lsvg1_(&t, &f, &cs, &sn, &d__[i__]);
	    if (! havers) {
		goto L45;
	    }
	    i__3 = *ncc;
	    for (j = 1; j <= i__3; ++j) {
/* L40: */
		lsvg2_(&cs, &sn, &c__[i__ + j * c_dim1], &c__[l - 1 + j * 
			c_dim1]);
	    }
L45:
	    ;
	}
/*                                  TEST FOR CONVERGENCE */
L50:
	z__ = d__[k];
	if (l == k) {
	    goto L85;
	}
/*                                  SHIFT FROM BOTTOM 2 BY 2 MINOR OF */
/*                                    B**(T)*B. */
	x = d__[l];
	y = d__[k - 1];
	g = e[k - 1];
	h__ = e[k];
	f = ((y - z__) * (y + z__) + (g - h__) * (g + h__)) / (two * h__ * y);
/* Computing 2nd power */
	r__1 = f;
	g = sqrt(one + r__1 * r__1);
	if (f < zero) {
	    goto L55;
	}
	t = f + g;
	goto L60;
L55:
	t = f - g;
L60:
	f = ((x - z__) * (x + z__) + h__ * (y / t - h__)) / x;
/*                                  NEXT QR SWEEP */
	cs = one;
	sn = one;
	lp1 = l + 1;
	i__2 = k;
	for (i__ = lp1; i__ <= i__2; ++i__) {
	    g = e[i__];
	    y = d__[i__];
	    h__ = sn * g;
	    g = cs * g;
	    lsvg1_(&f, &h__, &cs, &sn, &e[i__ - 1]);
	    f = x * cs + g * sn;
	    g = -x * sn + g * cs;
	    h__ = y * sn;
	    y *= cs;
	    if (! wntv) {
		goto L70;
	    }
/*                                  ACCUMULATE ROTATIONS (FROM THE */
/*                                    RIGHT) IN V */
	    i__3 = *nrv;
	    for (j = 1; j <= i__3; ++j) {
/* L65: */
		lsvg2_(&cs, &sn, &v[j + (i__ - 1) * v_dim1], &v[j + i__ * 
			v_dim1]);
	    }
L70:
	    lsvg1_(&f, &h__, &cs, &sn, &d__[i__ - 1]);
	    f = cs * g + sn * y;
	    x = -sn * g + cs * y;
	    if (! havers) {
		goto L80;
	    }
	    i__3 = *ncc;
	    for (j = 1; j <= i__3; ++j) {
/* L75: */
		lsvg2_(&cs, &sn, &c__[i__ - 1 + j * c_dim1], &c__[i__ + j * 
			c_dim1]);
	    }

/*                                  APPLY ROTATIONS FROM THE LEFT TO */
/*                                    RIGHT HAND SIDES IN C */
L80:
	    ;
	}
	e[l] = zero;
	e[k] = f;
	d__[k] = x;
	++nqrs;
	if (nqrs <= n10) {
	    goto L10;
	}
/*                                  RETURN TO TEST FOR SPLITTING. */
	fail = TRUE_;
/*                                  CUTOFF FOR CONVERGENCE FAILURE. NQRS */
/*                                    WILL BE 2*N USUALLY. */
L85:
	if (z__ >= zero) {
	    goto L95;
	}
	d__[k] = -z__;
	if (! wntv) {
	    goto L95;
	}
	i__2 = *nrv;
	for (j = 1; j <= i__2; ++j) {
/* L90: */
	    v[j + k * v_dim1] = -v[j + k * v_dim1];
	}
L95:
/*                                  CONVERGENCE. D(K) IS MADE */
/*                                    NONNEGATIVE */
/* L100: */
	;
    }
    if (*n == 1) {
	goto L140;
    }
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (d__[i__] > d__[i__ - 1]) {
	    goto L110;
	}
/* L105: */
    }
    goto L140;
/*                                  EVERY SINGULAR VALUE IS IN ORDER */
L110:
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	t = d__[i__ - 1];
	k = i__ - 1;
	i__2 = *n;
	for (j = i__; j <= i__2; ++j) {
	    if (t >= d__[j]) {
		goto L115;
	    }
	    t = d__[j];
	    k = j;
L115:
	    ;
	}
	if (k == i__ - 1) {
	    goto L135;
	}
	d__[k] = d__[i__ - 1];
	d__[i__ - 1] = t;
	if (! havers) {
	    goto L125;
	}
	i__2 = *ncc;
	for (j = 1; j <= i__2; ++j) {
	    t = c__[i__ - 1 + j * c_dim1];
	    c__[i__ - 1 + j * c_dim1] = c__[k + j * c_dim1];
/* L120: */
	    c__[k + j * c_dim1] = t;
	}
L125:
	if (! wntv) {
	    goto L135;
	}
	i__2 = *nrv;
	for (j = 1; j <= i__2; ++j) {
	    t = v[j + (i__ - 1) * v_dim1];
	    v[j + (i__ - 1) * v_dim1] = v[j + k * v_dim1];
/* L130: */
	    v[j + k * v_dim1] = t;
	}
L135:
	;
    }
/*                                  END OF ORDERING ALGORITHM. */
L140:
    *ier = 129;
    if (fail) {
	goto L9000;
    }
/*                                  CHECK FOR POSSIBLE RANK DEFICIENCY */
    *ier = 33;
    t = 0.f;
    if (d__[1] != zero) {
	t = d__[*n] / d__[1];
    }
    f = t + 100.f;
    if (f == 100.f) {
	goto L9000;
    }
    *ier = 0;
    goto L9005;
L9000:
/*      CALL UERTST (IER,'LSVDB ') */
/* uk */
    if (*ier != 33) {
	s_wsfe(&io___1497);
	do_fio(&c__1, (char *)&(*ier), (ftnlen)sizeof(integer));
	e_wsfe();
    }
/* uk */
L9005:
    return 0;
} /* lsvdb_ */


/* Subroutine */ int lsvg1_(real *a, real *b, real *dcos, real *dsin, real *
	sig)
{
    /* System generated locals */
    real r__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal doubleaa;
    static real aa, bb;
    static doublereal doubleb, doubler;


/*   IMSL ROUTINE NAME   - LSVG1 */

/* ----------------------------------------------------------------------- */

/*   COMPUTER            - HP1000/DOUBLE */

/*   LATEST REVISION     - JANUARY 1, 1978 */

/*   PURPOSE             - NUCLEUS CALLED ONLY BY IMSL ROUTINE LSVDB */

/*   PRECISION/HARDWARE  - SINGLE AND DOUBLE/H32 */
/*                       - SINGLE/H36,H48,H60 */

/*   REQD. IMSL ROUTINES - NONE REQUIRED */

/*   NOTATION            - INFORMATION ON SPECIAL NOTATION AND */
/*                           CONVENTIONS IS AVAILABLE IN THE MANUAL */
/*                           INTRODUCTION OR THROUGH IMSL ROUTINE UHELP */

/*   COPYRIGHT           - 1978 BY IMSL, INC. ALL RIGHTS RESERVED. */

/*   WARRANTY            - IMSL WARRANTS ONLY THAT IMSL TESTING HAS BEEN */
/*                           APPLIED TO THIS CODE. NO OTHER WARRANTY, */
/*                           EXPRESSED OR IMPLIED, IS APPLICABLE. */

/* ----------------------------------------------------------------------- */

/*                                  SPECIFICATIONS FOR ARGUMENTS */
/*                                  SPECIFICATIONS FOR LOCAL VARIABLES */
/*                                  FIRST EXECUTABLE STATEMENT */
    if (dabs(*a) <= dabs(*b)) {
	goto L5;
    }
    aa = (r__1 = *a + *a, dabs(r__1));
/* uk   next statement caused an underflow! u.kradolfer, 16.7.81 */
/* uk      SIG=AA*SQRT(0.25e0+(B/AA)**2) */
/* uk   next statement produced a compiler warning with range checking option */
/* uk      SIG=AA*sngl( dSQRT(0.25d0+(dble(B)/dble(AA))**2) ) ! u.k. 7.2.92 */
    doubleb = (doublereal) (*b);
    doubleaa = (doublereal) aa;
/* Computing 2nd power */
    d__1 = doubleb / doubleaa;
    doubler = sqrt(d__1 * d__1 + .25);
    *sig = aa * (real) doubler;
    *dcos = *a / *sig;
    *dsin = *b / *sig;
    return 0;
L5:
    if (*b == 0.f) {
	goto L10;
    }
    bb = (r__1 = *b + *b, dabs(r__1));
/* Computing 2nd power */
    r__1 = *a / bb;
    *sig = bb * sqrt(r__1 * r__1 + .25f);
    *dcos = *a / *sig;
    *dsin = *b / *sig;
    return 0;
L10:
    *sig = 0.f;
    *dcos = 0.f;
    *dsin = 1.f;
    return 0;
} /* lsvg1_ */


/* Subroutine */ int lsvg2_(real *dcos, real *dsin, real *x, real *y)
{
    static real xr;


/*   IMSL ROUTINE NAME   - LSVG2 */

/* ----------------------------------------------------------------------- */

/*   COMPUTER            - HP1000/DOUBLE */

/*   LATEST REVISION     - JANUARY 1, 1978 */

/*   PURPOSE             - NUCLEUS CALLED ONLY BY IMSL ROUTINE LSVDB */

/*   PRECISION/HARDWARE  - SINGLE AND DOUBLE/H32 */
/*                       - SINGLE/H36,H48,H60 */

/*   REQD. IMSL ROUTINES - NONE REQUIRED */

/*   NOTATION            - INFORMATION ON SPECIAL NOTATION AND */
/*                           CONVENTIONS IS AVAILABLE IN THE MANUAL */
/*                           INTRODUCTION OR THROUGH IMSL ROUTINE UHELP */

/*   COPYRIGHT           - 1978 BY IMSL, INC. ALL RIGHTS RESERVED. */

/*   WARRANTY            - IMSL WARRANTS ONLY THAT IMSL TESTING HAS BEEN */
/*                           APPLIED TO THIS CODE. NO OTHER WARRANTY, */
/*                           EXPRESSED OR IMPLIED, IS APPLICABLE. */

/* ----------------------------------------------------------------------- */


/*                                  SPECIFICATIONS FOR ARGUMENTS */
/*                                  SPECIFICATIONS FOR LOCAL VARIABLES */
/*                                  FIRST EXECUTABLE STATEMENT */
    xr = *dcos * *x + *dsin * *y;
    *y = -(*dsin) * *x + *dcos * *y;
    *x = xr;
    return 0;
} /* lsvg2_ */


/* Subroutine */ int vhs12_(integer *mode, integer *lp, integer *l1, integer *
	m, real *u, integer *incu, real *up, real *c__, integer *incc, 
	integer *icv, integer *ncv)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1, r__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static real b;
    static integer j, i2, i3, i4;
    static real cl;
    static integer ij, im;
    static real sm;
    static integer il1;
    static real sm1, one;
    static integer ilp, incr;
    static real clinv;


/*                                  SPECIFICATIONS FOR ARGUMENTS */
/* uk      real               U(1),UP,C(1) */
/* uk      real               U(m+1),UP,C(ncv*m)  ! did NOT work... */
/*                                  SPECIFICATIONS FOR LOCAL VARIABLES */
/* in this case only!!! (sing */
/*                                  FIRST EXECUTABLE STATEMENT */
    /* Parameter adjustments */
    --c__;
    --u;

    /* Function Body */
    one = 1.f;

    if (0 >= *lp || *lp >= *l1 || *l1 > *m) {
	goto L9005;
    }
    ilp = (*lp - 1) * *incu + 1;
    il1 = (*l1 - 1) * *incu + 1;
    im = (*m - 1) * *incu + 1;
    cl = (r__1 = u[ilp], dabs(r__1));
    if (*mode == 2) {
	goto L15;
    }
/*                                  CONSTRUCT THE TRANSFORMATION. */
    i__1 = im;
    i__2 = *incu;
    for (ij = il1; i__2 < 0 ? ij >= i__1 : ij <= i__1; ij += i__2) {
/* L5: */
/* Computing MAX */
	r__2 = (r__1 = u[ij], dabs(r__1));
	cl = (real) ((integer) dmax(r__2,cl));
    }
    if (cl <= 0.f) {
	goto L9005;
    }
    clinv = one / cl;
/* Computing 2nd power */
    r__1 = u[ilp] * clinv;
    sm = r__1 * r__1;
    i__2 = im;
    i__1 = *incu;
    for (ij = il1; i__1 < 0 ? ij >= i__2 : ij <= i__2; ij += i__1) {
/* L10: */
/* Computing 2nd power */
	r__1 = u[ij] * clinv;
	sm += r__1 * r__1;
    }
/*                                  CONVERT DBLE. PREC. SM TO SNGL. */
/*                                    PREC. SM1 */
    sm1 = sm;
    cl *= sqrt(sm1);
    if (u[ilp] > 0.f) {
	cl = -cl;
    }
    *up = u[ilp] - cl;
    u[ilp] = cl;
    goto L20;
/*                                  APPLY THE TRANSFORMATION */
/*                                    I+U*(U**T)/B TO C. */
L15:
    if (cl <= 0.f) {
	goto L9005;
    }
L20:
    if (*ncv <= 0) {
	goto L9005;
    }
    b = *up * u[ilp];
/*                                  B MUST BE NONPOSITIVE HERE. IF B = */
/*                                    0., RETURN. */
    if (b >= 0.f) {
	goto L9005;
    }
    b = one / b;
    i2 = 1 - *icv + *incc * (*lp - 1);
    incr = *incc * (*l1 - *lp);
    i__1 = *ncv;
    for (j = 1; j <= i__1; ++j) {
	i2 += *icv;
	i3 = i2 + incr;
	i4 = i3;
	sm = c__[i2] * *up;
	i__2 = im;
	i__3 = *incu;
	for (ij = il1; i__3 < 0 ? ij >= i__2 : ij <= i__2; ij += i__3) {
	    sm += c__[i3] * u[ij];
	    i3 += *incc;
/* L25: */
	}
	if (sm == 0.f) {
	    goto L35;
	}
	sm *= b;
	c__[i2] += sm * *up;
	i__3 = im;
	i__2 = *incu;
	for (ij = il1; i__2 < 0 ? ij >= i__3 : ij <= i__3; ij += i__2) {
	    c__[i4] += sm * u[ij];
	    i4 += *incc;
/* L30: */
	}
L35:
	;
    }
L9005:
    return 0;
} /* vhs12_ */


/* Subroutine */ int ludecp_(real *a, real *ul, integer *n, real *d1, real *
	d2, integer *ier)
{
    /* Initialized data */

    static real zero = 0.f;
    static real one = 1.f;
    static real four = 4.f;
    static real sixtn = 16.f;
    static real sixth = .0625f;

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k;
    static real x;
    static integer ip, iq, ir;
    static real rn;
    static integer ip1;


/*     function:        - cholesky decomposition of a matrix A - */
/*     --------- */
/*     A   nxn pos. def. symm. matrix, stored in symm. storage mode */
/*     UL  nxn lower triangular matrix,  with UL * ULt = A */
/*     !!! diagonal elements of UL are stored in reziprocal form !!! */
/*     det(A) = D1*(2.**D2)      d1, d2 is output of LUDECP */
/*     IER=0  --> A is pos. def.;    everything o.k. */

    /* Parameter adjustments */
    --ul;
    --a;

    /* Function Body */

    *d1 = one;
    *d2 = zero;
    rn = one / (*n * sixtn);
    ip = 1;
    *ier = 0;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iq = ip;
	ir = 1;
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    x = a[ip];
	    if (j == 1) {
		goto L10;
	    }
	    i__3 = ip1;
	    for (k = iq; k <= i__3; ++k) {
		x -= ul[k] * ul[ir];
		++ir;
/* L5: */
	    }
L10:
	    if (i__ != j) {
		goto L30;
	    }
	    *d1 *= x;
	    if (a[ip] + x * rn <= a[ip]) {
		goto L50;
	    }
L15:
	    if (dabs(*d1) <= one) {
		goto L20;
	    }
	    *d1 *= sixth;
	    *d2 += four;
	    goto L15;
L20:
	    if (dabs(*d1) >= sixth) {
		goto L25;
	    }
	    *d1 *= sixtn;
	    *d2 -= four;
	    goto L20;
L25:
	    ul[ip] = one / sqrt(x);
	    goto L35;
L30:
	    ul[ip] = x * ul[ir];
L35:
	    ip1 = ip;
	    ++ip;
	    ++ir;
/* L40: */
	}
/* L45: */
    }
    goto L9005;
L50:
    *ier = 129;
/* L9000: */
L9005:
    return 0;
} /* ludecp_ */


/* of subr. ludecp */
/* Subroutine */ int luelmp_(real *a, real *b, integer *n, real *x)
{
    /* Initialized data */

    static real zero = 0.f;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, k;
    static real t;
    static integer n1, ii, kk, ip, iq, is, iw, im1;


/*     function:     - elimination part of the solution of Ax=b */
/*     --------- */
/*       A  (nxn) lower triangular matrix (outout of LUDECP) */
/*       !!! diagonal elements of A are stored in reziprocal form !!! */
/*       b  n-vector */
/*       x  n-vector (solution of equation Ax=b) */

    /* Parameter adjustments */
    --x;
    --b;
    --a;

    /* Function Body */
/*                              solution of ly = b */
    ip = 1;
    iw = 0;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	t = b[i__];
	im1 = i__ - 1;
	if (iw == 0) {
	    goto L9;
	}
	ip = ip + iw - 1;
	i__2 = im1;
	for (k = iw; k <= i__2; ++k) {
	    t -= a[ip] * x[k];
	    ++ip;
/* L5: */
	}
	goto L10;
L9:
	if (t != zero) {
	    iw = i__;
	}
	ip += im1;
L10:
	x[i__] = t * a[ip];
	++ip;
/* L15: */
    }
/*                                  solution of ux = y */
    n1 = *n + 1;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ii = n1 - i__;
	--ip;
	is = ip;
	iq = ii + 1;
	t = x[ii];
	if (*n < iq) {
	    goto L25;
	}
	kk = *n;
	i__2 = *n;
	for (k = iq; k <= i__2; ++k) {
	    t -= a[is] * x[kk];
	    --kk;
	    is -= kk;
/* L20: */
	}
L25:
	x[ii] = t * a[is];
/* L30: */
    }
    return 0;
} /* luelmp_ */


/* of subr. luelmp */
/* Subroutine */ int matrmult_(real *a, integer *m, integer *p, real *b, 
	integer *p1, integer *n, real *c__, integer *m1, integer *n1)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k;
    static real s;

/*     Urs Kradolfer, 28.3.1987 */
/*     input:  (mxp)-matrix A */
/*             (p1xn)-matrix B */
/*     output: (m1xn1)-matrix C = A*B */
    /* Parameter adjustments */
    a_dim1 = *m;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    b_dim1 = *p1;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    c_dim1 = *m1;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;

    /* Function Body */
    if (*m != *m1) {
	s_stop("Matrices cannot be multiplied !", (ftnlen)31);
    }
    if (*p != *p1) {
	s_stop("Matrices cannot be multiplied !", (ftnlen)31);
    }
    if (*n != *n1) {
	s_stop("Matrices cannot be multiplied !", (ftnlen)31);
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    s = 0.f;
	    i__3 = *p;
	    for (k = 1; k <= i__3; ++k) {
		s += a[i__ + k * a_dim1] * b[k + j * b_dim1];
	    }
	    c__[i__ + j * c_dim1] = s;
	}
    }
    return 0;
} /* matrmult_ */


/* of subr. matrmult */
/* Subroutine */ int matrtran_(real *a, integer *n, integer *m, real *at)
{
    /* System generated locals */
    integer a_dim1, a_offset, at_dim1, at_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j;

/*     Urs Kradolfer, 28.3.1987 */
/*     input:  (nxm)-matrix A */
/*     output: (mxn)-matrix AT ( = A transpose ) */
    /* Parameter adjustments */
    at_dim1 = *m;
    at_offset = 1 + at_dim1;
    at -= at_offset;
    a_dim1 = *n;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *m;
	for (j = 1; j <= i__2; ++j) {
	    at[j + i__ * at_dim1] = a[i__ + j * a_dim1];
	}
    }
    return 0;
} /* matrtran_ */


/* of subr. matrtran */
/* Subroutine */ int maxii_(integer *n, integer *nx, integer *imax, integer *
	jndex)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

/* determine maximum-value of an integer-array */
    /* Parameter adjustments */
    --nx;

    /* Function Body */
    *jndex = 1;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1: */
	if (nx[*jndex] <= nx[i__]) {
	    *jndex = i__;
	}
    }
    *imax = nx[*jndex];
    return 0;
} /* maxii_ */


/* of subr. maxni */
/* Subroutine */ int maxri_(integer *n, real *x, real *xmax, integer *jndex)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

/* determine maximum-value of a real-array */
    /* Parameter adjustments */
    --x;

    /* Function Body */
    *jndex = 1;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1: */
	if (x[*jndex] <= x[i__]) {
	    *jndex = i__;
	}
    }
    *xmax = x[*jndex];
    return 0;
} /* maxri_ */


/* of subr. maxri */
/* Subroutine */ int sorti_(integer *ix, integer *no)
{
    static integer i__, jo, ko, mo, itemp;


/*  SORTA sortiert einen Integer-Array iX so, dass iX(1) < iX(2) < ... < iX(N) */

/*  Aufruf: call SORTI(iX,N) */

/*  mit INTEGER iX(N) */
/*      INTEGER N       (Anzahl Elemente in X) */

/*  Array iX wird in SORTI veraendert !! */

/* Urs Kradolfer, Okt. 1986 (aus HYPOSUBR */

    /* Parameter adjustments */
    --ix;

    /* Function Body */
    if (*no == 0) {
	return 0;
    }
    mo = *no;
L2:
    if (mo - 15 <= 0) {
	goto L21;
    } else {
	goto L23;
    }
L21:
    if (mo - 1 <= 0) {
	goto L29;
    } else {
	goto L22;
    }
L22:
    mo = (mo / 4 << 1) + 1;
    goto L24;
L23:
    mo = (mo / 8 << 1) + 1;
L24:
    ko = *no - mo;
    jo = 1;
L25:
    i__ = jo;
L26:
    if (ix[i__] - ix[i__ + mo] <= 0) {
	goto L28;
    } else {
	goto L27;
    }
L27:
    itemp = ix[i__];
    ix[i__] = ix[i__ + mo];
    ix[i__ + mo] = itemp;
    i__ -= mo;
    if (i__ - 1 >= 0) {
	goto L26;
    } else {
	goto L28;
    }
L28:
    ++jo;
    if (jo - ko <= 0) {
	goto L25;
    } else {
	goto L2;
    }
L29:
    return 0;
} /* sorti_ */


/* of subr. sorti */
/* Subroutine */ int sortr_(real *x, integer *no)
{
    static integer i__, jo, ko, mo;
    static real temp;


/*  SORTR sortiert einen Real-Array X so, dass X(1) < X(2) < ... < X(N) */

/*  Aufruf: call SORTR(X,N) */

/*  mit REAL    X(N) */
/*      INTEGER N       (Anzahl Elemente in X) */

/*  Array X wird in SORTR veraendert !! */

/* Urs Kradolfer, Okt. 1986 (aus HYPOSUBR. */

    /* Parameter adjustments */
    --x;

    /* Function Body */
    mo = *no;
L2:
    if (mo - 15 <= 0) {
	goto L21;
    } else {
	goto L23;
    }
L21:
    if (mo - 1 <= 0) {
	goto L29;
    } else {
	goto L22;
    }
L22:
    mo = (mo / 4 << 1) + 1;
    goto L24;
L23:
    mo = (mo / 8 << 1) + 1;
L24:
    ko = *no - mo;
    jo = 1;
L25:
    i__ = jo;
L26:
    if (x[i__] - x[i__ + mo] <= 0.f) {
	goto L28;
    } else {
	goto L27;
    }
L27:
    temp = x[i__];
    x[i__] = x[i__ + mo];
    x[i__ + mo] = temp;
    i__ -= mo;
    if (i__ - 1 >= 0) {
	goto L26;
    } else {
	goto L28;
    }
L28:
    ++jo;
    if (jo - ko <= 0) {
	goto L25;
    } else {
	goto L2;
    }
L29:
    return 0;
} /* sortr_ */


/* of subr. sortr */
/* Subroutine */ int spreadd_(real *r__, integer *m, real *spread)
{
    /* System generated locals */
    integer r_dim1, r_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j;

/*     DIRICHLET SPREAD FUNCTION */
/*     measures the goodness of the resolution spread, based on the */
/*     L2 norm of the difference between the resolution matrix and the */
/*     identity matrix [ Dirichlet spread function ] */
/*     R = I   <==>  spread(R) = 0 */

/* Urs Kradolfer */

    /* Parameter adjustments */
    r_dim1 = *m;
    r_offset = 1 + r_dim1;
    r__ -= r_offset;

    /* Function Body */
    *spread = 0.f;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *m;
	for (j = 1; j <= i__2; ++j) {
	    if (i__ == j) {
		*spread += (r__[i__ + j * r_dim1] - 1) * (r__[i__ + j * 
			r_dim1] - 1);
	    }
	    if (i__ != j) {
		*spread += r__[i__ + j * r_dim1] * r__[i__ + j * r_dim1];
	    }
	}
    }
    return 0;
} /* spreadd_ */


/* of subr. SPREADd */
/* Subroutine */ int spreadb_(real *r__, integer *m, real *spread)
{
    /* System generated locals */
    integer r_dim1, r_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j;

/*     BACKUS-GILBERT SPREAD FUNCTION */
/*     measures the goodness of the resolution spread, based on the */
/*     L2 norm of the WEIGHTED difference between the resolution matrix and the */
/*     identity matrix [ Backus-Gilbert spread function ] */
/*     R = I   <==>  spread(R) = 0 */

/* Urs Kradolfer */

    /* Parameter adjustments */
    r_dim1 = *m;
    r_offset = 1 + r_dim1;
    r__ -= r_offset;

    /* Function Body */
    *spread = 0.f;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *m;
	for (j = 1; j <= i__2; ++j) {
	    *spread += (i__ - j) * (i__ - j) * r__[i__ + j * r_dim1] * r__[
		    i__ + j * r_dim1];
	}
    }
    return 0;
} /* spreadb_ */


/* of subr. spreadb */
/* Subroutine */ int svdsoluk_(real *ain, real *bin, integer *m, real *eigmin,
	 real *x, real *s, real *ale, real *cov, real *r__)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int matrtran_(real *, integer *, integer *, real *
	    ), matrmult_(real *, integer *, integer *, real *, integer *, 
	    integer *, real *, integer *, integer *);
    static real a[16]	/* was [4][4] */, b[4];
    static integer i__, j;
    static real at[16]	/* was [4][4] */, wk[16]	/* was [8][2] */;
    static integer ier;
    static real sum;
    static integer nfre;
    extern /* Subroutine */ int lsvdf_(real *, integer *, integer *, integer *
	    , real *, integer *, integer *, real *, real *, integer *);
    static integer izero;
    extern /* Subroutine */ int alesubr_(real *, integer *, real *);


/*     Urs Kradolfer, 24. April 1987 */

/*     solve NORMAL EQUATIONS  Gt*G * X = Gt*R */
/*                               A  * X  =  B    , so A is symmetric !!! */

/*     Input : left-hand-side A(mxm), right-hand-side  B(m), */
/*             eigmin : >=0  cutoff-value for solution */
/*                      = -1 only S (singular values) are returned */

/*     Output: solution-vector X(m), singular-(eigen-)values S(m), */
/*             diagonal elements of covariance-matrix COV(m), */
/*             resolution-matrix R(mxm) */
/*             Average Logarithmic Eigenvalue ALE : */

/*             ALE = 1./(m-izero) * sum(i=1...m) log10(S(i)) */

/*             where izero = # zero-singular-values */

/*             before, LGCN was used !!! */
/*             GCN = LOG10 [ average quotient of 1stEigenvalue to ithEigenvalue */
/*                           / average eigenvalue ] */


/* must be dimensioned to : 2m,2 */
    /* Parameter adjustments */
    r__ -= 5;
    --cov;
    --s;
    --x;
    --bin;
    ain -= 5;

    /* Function Body */
    if (*m > 4) {
	s_stop("SVDSOLUK>>> m.gt.4 ; redimension arrays !!!", (ftnlen)43);
    }

/*     copy input-matrix/-vector into local ones (so the input doesn't change) : */

    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *m;
	for (j = 1; j <= i__2; ++j) {
	    a[i__ + (j << 2) - 5] = ain[i__ + (j << 2)];
	}
	b[i__ - 1] = bin[i__];
	s[i__] = 0.f;
	cov[i__] = 0.f;
    }
    for (i__ = 1; i__ <= 8; ++i__) {
	for (j = 1; j <= 2; ++j) {
	    wk[i__ + (j << 3) - 9] = 0.f;
	}
    }

/*     do SVD (singular value decomposition) of matrix A = V * S * Vt   : */

    lsvdf_(a, m, m, m, b, m, &c__1, &s[1], wk, &ier);

/*     determine ALE  ( Average Logarithmic Eigenvalue ) */

/*      izero=0 */
/*      if(m.eq.1)then */
/*         GCN=1.0 */
/*      else */
/*         GCN=0.0 */
/*         sum=s(1) */
/*         do i=2,m */
/*            if(s(i).gt.0.0)then */
/*               GCN=GCN+s(1)/s(i) */
/*               sum=sum+s(i) */
/*            else */
/*               izero=izero+1 */
/*            endif */
/*         enddo */
/*      endif */
/*      sum=sum/m   ! average eigenvalue. */
/*      GCN=izero*100.+log10((GCN/float((m-1)-izero))/sum) */
/* c      ale=0.0 */
/* IMSL-routine */
    izero = 0;
/* c      do i=1,m */
/* c            ale=ale+log10((s(i)/s(1))) */
/* cc            ale=ale+log10((s(i)/s(1)) + 1e-10) */
/* c      enddo */
/* c      ale=-ale/float(m) */
    alesubr_(&s[1], m, ale);

    if (*eigmin < 0.f) {
	return 0;
    }

/*     determine degree of freedom (neglect sing. vals. < cutoff-value eigmin) : */

    nfre = 0;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x[i__] = 0.f;
	if (s[i__] > *eigmin) {
	    ++nfre;
	} else {
/* cc            write(6,*)'SVDSOLUK>>> skipping singular value = ',s(i) */
	    s[i__] = 0.f;
/* set eigenvalue to zero */
	    i__2 = *m;
	    for (j = 1; j <= i__2; ++j) {
		a[j + (i__ << 2) - 5] = 0.f;
/* set appr. COLUMN of V (=eigenvector!!!) to */
	    }
	}
    }

/*     calculate solution-vector X = V * inv(S) * Vt*B    : */
/*                            [  X = A * inv(S) *   B   ] */

    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = nfre;
	for (j = 1; j <= i__2; ++j) {
	    x[i__] += a[i__ + (j << 2) - 5] * b[j - 1] / s[j];
	}
    }

/*     calculate diagonal elements of UNSCALED covariance matrix : */

/*     C = datvar * V * inv(inv(S)) * Vt */

/*     C(i,j)= SUM(k=1...m)  V(i,k)*V(j,k)/(S(k,k)*S(k,k))  <-- for all elements */
/*     C(i,i)= SUM(k=1...m)  V(i,k)*V(i,k)/(S(k,k)*S(k,k))  <-- diag. elem. only */

    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum = 0.f;
	i__2 = nfre;
	for (j = 1; j <= i__2; ++j) {
/* cc            write(6,*)'i=',i,'j=',j,'V(i,j)=',a(i,j) */
	    sum += a[i__ + (j << 2) - 5] * a[i__ + (j << 2) - 5] / (s[j] * s[
		    j]);
	}
	cov[i__] = sum;
    }

/*     compute resolution-matrix:  R = V * Vt    : */
/*                               [ R = A * At ] */

    matrtran_(a, m, m, at);
    matrmult_(a, m, m, at, m, m, &r__[5], m, m);

    return 0;
} /* svdsoluk_ */


/* ek     end of vel_math.f */

/* ek     begin of vel_ray.f */

/* of subr. SVDSOLUK */
/* Subroutine */ int raypointcheck_(real *rp, integer *nrp, char *staname, 
	ftnlen staname_len)
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer j;
    static real zzz, dzzz;
    extern /* Subroutine */ int chtop_(real *, real *, real *, char *, char *,
	     ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___1580 = { 0, 6, 0, "(1x,'ray in the air... ! rp3=',f6."
	    "3,                   ' ZZ=',f6.3,' dz=',f6.3,' rp# =',i2,' nrp='"
	    ",i2,           ' STN=',a4,'i ',i4)", 0 };



/*     checks, whether all the raypoints with z<0 are below the actual */
/*     surface of the topography (of Switzerland). */


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

    /* Parameter adjustments */
    rp -= 4;

    /* Function Body */
    i__1 = *nrp;
    for (j = 1; j <= i__1; ++j) {
	if (rp[j * 3 + 3] < 0.f) {
	    r__1 = -rp[j * 3 + 1];
	    chtop_(&r__1, &rp[j * 3 + 2], &zzz, infiles_1.topo1file, 
		    infiles_1.topo2file, (ftnlen)80, (ftnlen)80);
	    dzzz = rp[j * 3 + 3] - zzz;
	    if (dzzz < 0.f) {
		s_wsfe(&io___1580);
		do_fio(&c__1, (char *)&rp[j * 3 + 3], (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&zzz, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&dzzz, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&(*nrp), (ftnlen)sizeof(integer));
		do_fio(&c__1, staname, (ftnlen)4);
		do_fio(&c__1, (char *)&coordsyst_1.isingle, (ftnlen)sizeof(
			integer));
		e_wsfe();
	    }
	}
    }

    return 0;
} /* raypointcheck_ */


/* of subr. raypointcheck */
/* Subroutine */ int layerhit_(real *rp, integer *nrpdeep, integer *nl, 
	integer *nrp, integer *mll)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer j;
    static real avraydepth;
    static integer jlay;
    static real rpmax;


/*     counts the number of hits in each layer. */


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


/*     find deepest layer hit by this ray (= refraction layer or eventlayer */
/*                                           for direct wave) */
    /* Parameter adjustments */
    rp -= 4;

    /* Function Body */
    rpmax = -999.f;
    i__1 = *nrp;
    for (j = 1; j <= i__1; ++j) {
	if (rp[j * 3 + 3] > rpmax) {
	    rpmax = rp[j * 3 + 3];
/* = max. depth of ray */
	    *nrpdeep = j;
/* index of deepest raypoint */
	}
    }
    rpmax += 1e-6f;
/* avoid raypoint on layer-boundary */
    layvel_1.lmax = 1;
    i__1 = *nl;
    for (j = 2; j <= i__1; ++j) {
	if (layer_1.h__[j - 1] > rpmax) {
/*  h(j)= top of layer j [km] */
	    layvel_1.lmax = j - 1;
/* lmax = layer number for depth rpmax */
	    goto L4000;
	}
    }
    layvel_1.lmax = *nl;
/* lowest layer */
L4000:
    if (rp[*nrpdeep * 3 + 3] == rp[(*nrpdeep + 1) * 3 + 3]) {
/* ray is horizontal */
	++hitl_1.irefrlayer[layvel_1.lmax - 1];
/* headwave in layer L */
/* Computing 2nd power */
	r__1 = rp[*nrpdeep * 3 + 1] - rp[(*nrpdeep + 1) * 3 + 1];
/* Computing 2nd power */
	r__2 = rp[*nrpdeep * 3 + 2] - rp[(*nrpdeep + 1) * 3 + 2];
	hitl_1.refraylen[layvel_1.lmax - 1] += sqrt(r__1 * r__1 + r__2 * r__2)
		;
    } else {
	if (*mll == 0) {
	    ++hitl_1.noheadwave;
	} else {
	    ++hitl_1.irefllayer[layvel_1.lmax - 2];
/*                                           ! -1 because of rpmax=rpmax+0.000001 */
	}
    }
/* Computing 2nd power */
    r__1 = rp[4] - rp[*nrp * 3 + 1];
/* Computing 2nd power */
    r__2 = rp[5] - rp[*nrp * 3 + 2];
    hitl_1.avhraylen += sqrt(r__1 * r__1 + r__2 * r__2);
    hitl_1.avvraylen += (r__1 = rp[*nrpdeep * 3 + 3] - rp[*nrp * 3 + 3], dabs(
	    r__1));

    i__1 = *nrp;
    for (j = 2; j <= i__1; ++j) {
	avraydepth = (rp[j * 3 + 3] + rp[(j - 1) * 3 + 3]) / 2.f;
	avraydepth += 1e-6f;
/* avoid raydepth on layer-bou */
	i__2 = *nl;
	for (jlay = 1; jlay <= i__2; ++jlay) {
	    if (avraydepth >= layer_1.h__[jlay - 1] && avraydepth < 
		    layer_1.h__[jlay - 1] + layer_1.thk[jlay - 1]) {
		hitl_1.hitlay[jlay - 1] += 1;
/* Computing 2nd power */
		r__1 = rp[j * 3 + 1] - rp[(j - 1) * 3 + 1];
/* Computing 2nd power */
		r__2 = rp[j * 3 + 2] - rp[(j - 1) * 3 + 2];
		hitl_1.hitlay[jlay + 99] += sqrt(r__1 * r__1 + r__2 * r__2);
		hitl_1.hitlay[jlay + 199] += (r__1 = rp[j * 3 + 3] - rp[(j - 
			1) * 3 + 3], dabs(r__1));
	    }
	}
    }
    return 0;
} /* layerhit_ */


/* of subr. layerhit */
/* Subroutine */ int checkraypath_(real *rp, integer *nrp)
{



/*     do not allow two identical raypoints ! */
/*     (first two raypoints may be identical; e.g. if hypocenter is on */
/*      layer-boundary) */

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

    /* Parameter adjustments */
    rp -= 4;

    /* Function Body */
    if (rp[4] == rp[7] && rp[5] == rp[8] && rp[6] == rp[9]) {
/* hrm         do j=1,nrp-1 */
/* hrm            rp(1,j)=rp(1,j+1)          ! delete first ray-point */
/* hrm            rp(2,j)=rp(2,j+1)          ! and move elements in array RP 'down' */
/* hrm            rp(3,j)=rp(3,j+1) */
/* hrm         enddo */
/* hrm         nrp=nrp-1                     ! nr_of_raypoints is now smaller by 1 !! */
/* hrm     move hypocenter 10 cm away from the layer boundary (upwards) */
	rp[6] += -1e-4f;
	return 0;
    }

    return 0;
} /* checkraypath_ */


/* of subr. checkraypath */
/* Subroutine */ int bendray_(real *rp, integer *nrp, char *staname, real *
	vtop, real *ttt, ftnlen staname_len)
{
    /* System generated locals */
    real r__1, r__2, r__3, r__4, r__5;

    /* Builtin functions */
    double sqrt(doublereal), asin(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static real dx1, dy1, dz1, dx2, dy2, dz2;
    static logical hypocintop;
    static real rpn[30]	/* was [3][10] */, zzz, xyz1, xyz2;
    static integer jnrp;
    static real arrive_angle__;
    static integer nrpm1;
    static real xyz1n, xyz2n;
    extern /* Subroutine */ int chtop_(real *, real *, real *, char *, char *,
	     ftnlen, ftnlen);
    static real takeoff_angle__;
    static integer jnrpm1;
    static real xydist, deltat1, deltat2, ttt1old, ttt2old, ttt1new, ttt2new;

    /* Fortran I/O blocks */
    static cilist io___1610 = { 0, 6, 0, "(1x,'BENDRAY>>> ray bended below s"
	    "urface!',                         ' Station: ',a4)", 0 };
    static cilist io___1611 = { 0, 6, 0, "(1x,'dt1=',f6.3,'   dt2=',f6.3)", 0 
	    };




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


    /* Parameter adjustments */
    rp -= 4;

    /* Function Body */
    if (coordsyst_1.icoordsystem != 2) {
	return 0;
    }

/* topo-array only for switzerland a */
/* Computing 2nd power */
    r__1 = rp[*nrp * 3 + 1] - rp[4];
/* Computing 2nd power */
    r__2 = rp[*nrp * 3 + 2] - rp[5];
    xydist = sqrt(r__1 * r__1 + r__2 * r__2);
    if (xydist > 10.f) {
	return 0;
    }

/* epicentral-distance too big for 'airy' */
/* Computing 2nd power */
    r__1 = rp[7] - rp[4];
/* Computing 2nd power */
    r__2 = rp[8] - rp[5];
/* Computing 2nd power */
    r__3 = rp[7] - rp[4];
/* Computing 2nd power */
    r__4 = rp[8] - rp[5];
/* Computing 2nd power */
    r__5 = rp[9] - rp[6];
    takeoff_angle__ = sqrt(r__1 * r__1 + r__2 * r__2) / sqrt(r__3 * r__3 + 
	    r__4 * r__4 + r__5 * r__5);
    takeoff_angle__ = asin(takeoff_angle__) * 57.296f;
    if (rp[9] - rp[6] < 0.f) {
	takeoff_angle__ = 180.f - takeoff_angle__;
/* ray is going upwards */
    }

/* Computing 2nd power */
    r__1 = rp[*nrp * 3 + 1] - rp[(*nrp - 1) * 3 + 1];
/* Computing 2nd power */
    r__2 = rp[*nrp * 3 + 2] - rp[(*nrp - 1) * 3 + 2];
/* Computing 2nd power */
    r__3 = rp[*nrp * 3 + 1] - rp[(*nrp - 1) * 3 + 1];
/* Computing 2nd power */
    r__4 = rp[*nrp * 3 + 2] - rp[(*nrp - 1) * 3 + 2];
/* Computing 2nd power */
    r__5 = rp[*nrp * 3 + 3] - rp[(*nrp - 1) * 3 + 3];
    arrive_angle__ = sqrt(r__1 * r__1 + r__2 * r__2) / sqrt(r__3 * r__3 + 
	    r__4 * r__4 + r__5 * r__5);
    arrive_angle__ = asin(arrive_angle__) * 57.296f;
    if (rp[9] - rp[6] < 0.f) {
	arrive_angle__ = 180.f - arrive_angle__;
/* ray is coming upwards */
    }

/*     write(6,'(1x,''takeoff_angle='',f6.1,''  arrive_angle='', */
/*    &          f6.1)') takeoff_angle, arrive_angle */

    deltat1 = 0.f;
    deltat2 = 0.f;
    hypocintop = FALSE_;
    if (rp[6] < 0.f) {
	hypocintop = TRUE_;
/*        compute XYZ1: the length between the first 2 raypoints */
	dx1 = rp[7] - rp[4];
	dy1 = rp[8] - rp[5];
	dz1 = rp[9] - rp[6];
/* Computing 2nd power */
	r__1 = dx1;
/* Computing 2nd power */
	r__2 = dy1;
/* Computing 2nd power */
	r__3 = dz1;
	xyz1 = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3);
    }

/*     if takeoff_angle at surface < 45  --> ray too steep to be 'airy' */

    if (hypocintop && takeoff_angle__ <= 45.f) {
	hypocintop = FALSE_;
    }
    if (hypocintop) {
/* stay here; ray-start could be in the air... */
    } else {
	if (arrive_angle__ >= 135.f) {
	    return 0;
	}
/* ray too steep to be 'airy' */
    }

    nrpm1 = *nrp - 1;
/*     compute XYZ2: the length between the last 2 raypoints */
    dx2 = rp[*nrp * 3 + 1] - rp[nrpm1 * 3 + 1];
    dy2 = rp[*nrp * 3 + 2] - rp[nrpm1 * 3 + 2];
    dz2 = rp[*nrp * 3 + 3] - rp[nrpm1 * 3 + 3];
/* Computing 2nd power */
    r__1 = dx2;
/* Computing 2nd power */
    r__2 = dy2;
/* Computing 2nd power */
    r__3 = dz2;
    xyz2 = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3);

/*     average (3D-)ray-length in the top-layer is about 2 kilometers; */
/*     now split ray in top-layer into 4 parts of about equal length: */
    if (hypocintop) {
	dx1 /= 4.f;
	dy1 /= 4.f;
	dz1 /= 4.f;
    }
    dx2 /= 4.f;
    dy2 /= 4.f;
    dz2 /= 4.f;
    if (hypocintop) {
	for (jnrp = 1; jnrp <= 4; ++jnrp) {
/* first raypoint = first old raypoint! */
	    rpn[jnrp * 3 - 3] = rp[4] + (jnrp - 1) * dx1;
	    rpn[jnrp * 3 - 2] = rp[5] + (jnrp - 1) * dy1;
	    rpn[jnrp * 3 - 1] = rp[6] + (jnrp - 1) * dz1;
	}
	jnrp = 5;
/* set last raypoint to second old raypoint to keep acc */
	rpn[jnrp * 3 - 3] = rp[7];
	rpn[jnrp * 3 - 2] = rp[8];
	rpn[jnrp * 3 - 1] = rp[9];
    }
    for (jnrp = 6; jnrp <= 9; ++jnrp) {
/* first raypoint = second-last old raypoint! */
	rpn[jnrp * 3 - 3] = rp[nrpm1 * 3 + 1] + (jnrp - 6) * dx2;
	rpn[jnrp * 3 - 2] = rp[nrpm1 * 3 + 2] + (jnrp - 6) * dy2;
	rpn[jnrp * 3 - 1] = rp[nrpm1 * 3 + 3] + (jnrp - 6) * dz2;
    }
    jnrp = 10;
/* set last raypoint to last old raypoint to keep accuracy! */
    rpn[jnrp * 3 - 3] = rp[*nrp * 3 + 1];
    rpn[jnrp * 3 - 2] = rp[*nrp * 3 + 2];
    rpn[jnrp * 3 - 1] = rp[*nrp * 3 + 3];

/*     now set raypoints min. 100meters below surface (if necessary): */

    if (hypocintop) {
	for (jnrp = 2; jnrp <= 5; ++jnrp) {
	    r__1 = -rpn[jnrp * 3 - 3];
	    chtop_(&r__1, &rpn[jnrp * 3 - 2], &zzz, infiles_1.topo1file, 
		    infiles_1.topo2file, (ftnlen)80, (ftnlen)80);
	    zzz += .1f;
/* 100meters below surface */
	    if (rpn[jnrp * 3 - 1] < zzz) {
		rpn[jnrp * 3 - 1] = zzz;
	    }
/* set hypoc. below s */
	}
    }
    for (jnrp = 6; jnrp <= 9; ++jnrp) {
	r__1 = -rpn[jnrp * 3 - 3];
	chtop_(&r__1, &rpn[jnrp * 3 - 2], &zzz, infiles_1.topo1file, 
		infiles_1.topo2file, (ftnlen)80, (ftnlen)80);
	zzz += .1f;
/* 100meters below surface */
	if (rpn[jnrp * 3 - 1] < zzz) {
	    rpn[jnrp * 3 - 1] = zzz;
	}
/* set hypoc. below sur */
    }

/*     calculate ray-length-difference and correct traveltime: */

    ttt1new = 0.f;
    if (hypocintop) {
	for (jnrp = 2; jnrp <= 5; ++jnrp) {
	    jnrpm1 = jnrp - 1;
/* Computing 2nd power */
	    r__1 = rpn[jnrp * 3 - 3] - rpn[jnrpm1 * 3 - 3];
/* Computing 2nd power */
	    r__2 = rpn[jnrp * 3 - 2] - rpn[jnrpm1 * 3 - 2];
/* Computing 2nd power */
	    r__3 = rpn[jnrp * 3 - 1] - rpn[jnrpm1 * 3 - 1];
	    xyz1n = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3);
	    ttt1new += xyz1n / *vtop;
	}
    }
    ttt2new = 0.f;
    for (jnrp = 7; jnrp <= 10; ++jnrp) {
	jnrpm1 = jnrp - 1;
/* Computing 2nd power */
	r__1 = rpn[jnrp * 3 - 3] - rpn[jnrpm1 * 3 - 3];
/* Computing 2nd power */
	r__2 = rpn[jnrp * 3 - 2] - rpn[jnrpm1 * 3 - 2];
/* Computing 2nd power */
	r__3 = rpn[jnrp * 3 - 1] - rpn[jnrpm1 * 3 - 1];
	xyz2n = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3);
	ttt2new += xyz2n / *vtop;
    }
    if (hypocintop) {
	ttt1old = xyz1 / *vtop;
	deltat1 = ttt1new - ttt1old;
    }
    ttt2old = xyz2 / *vtop;
    deltat2 = ttt2new - ttt2old;
    if (dabs(deltat1) > 1e-5f || dabs(deltat2) > 1e-5f) {
	s_wsfe(&io___1610);
	do_fio(&c__1, staname, (ftnlen)4);
	e_wsfe();
	s_wsfe(&io___1611);
	do_fio(&c__1, (char *)&deltat1, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&deltat2, (ftnlen)sizeof(real));
	e_wsfe();
    }
    *ttt = *ttt + deltat1 + deltat2;

    return 0;
} /* bendray_ */


/* of subr. bendray */
/* Subroutine */ int raypath_(integer *nx, integer *ny, integer *nz, real *x, 
	real *y, real *z__, real *vel, integer *nl, real *thk, real *d__, 
	real *v, real *vsq, real *xe, real *ye, real *ze, real *xr, real *yr, 
	real *zr, real *rp, integer *nrp, integer *nrtn, integer *jl, real *
	tkj, integer *itype, real *ttt, integer *mll, real *sterr, real *
	direrr, real *refrerr, real *reflerr, real *dtddrefl, real *dtdhrefl)
{
    /* System generated locals */
    integer vel_dim1, vel_dim2, vel_offset;
    real r__1, r__2;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Local variables */
    static integer l, kk;
    static real ain;
    extern /* Subroutine */ int reflectpath_(real *, real *, real *, real *, 
	    real *, real *, real *, integer *, real *, real *, real *, 
	    integer *, real *, real *, integer *, real *, integer *, real *);
    static real tref;
    static integer ierr;
    static real tdir, delta, deljl, depth, trefl, didjkk, salpha;
    extern /* Subroutine */ int layers_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, 
	    integer *, real *, real *), stpath_(real *, real *, real *, real *
	    , real *, real *, real *, integer *, real *, integer *, integer *,
	     real *, real *, real *, real *, real *);
    static real xovmax;
    extern /* Subroutine */ int direct1_(integer *, real *, real *, real *, 
	    integer *, real *, real *, real *, real *, real *, real *), 
	    refract_(integer *, real *, real *, real *, integer *, real *, 
	    real *, integer *, real *, real *, real *), refpath_(real *, real 
	    *, real *, real *, real *, real *, real *, integer *, real *, 
	    real *, real *, real *, integer *, integer *, real *, real *, 
	    integer *, real *), dirpath_(real *, real *, real *, real *, real 
	    *, real *, real *, integer *, real *, real *, real *, integer *, 
	    real *, real *, real *, real *, integer *, real *), reflect1_(
	    integer *, real *, real *, real *, integer *, real *, real *, 
	    real *, integer *, real *, real *, integer *, real *, real *);

    /* Fortran I/O blocks */
    static cilist io___1621 = { 0, 6, 0, 0, 0 };
    static cilist io___1622 = { 0, 16, 0, 0, 0 };



/*       raypath attempts to approximate the least time path for a */
/*  seismic ray traveling in a medium with velocities specified at */
/*  points on a 3-dimensional grid.  for very small delta a straight */
/*  line path is chosen.  for larger delta a layered velocity model */
/*  approximating the region between the event and the receiver is */
/*  constructed and the least time path in that layered model is chosen */
/*  both direct and refracted rays are considered and the possibility */
/*  of low velocity layers is allowed. */
/*       the 3 - dimensional grid should be specified by the */
/*  intersections of 3 sets of planes normal to the x,y and z coordinate */
/*  axes.  the intersection of the planes with the axes are specified */
/*  by x(i), y(j), and z(k), and the spacing of these may be */
/*  completely arbitrary. */
/*       subr. layers produces layer velocities from the */
/*  velocities of the 3 - dimensional model between the event and */
/*  the receiver, and because these will differ for every event - */
/*  receiver pair, layers must be called every time raypath is */
/*  called (unless delta is very small).  the number, thicknesses, */
/*  and depths of the layers should depend only on the array z(k), */
/*  and need only to be calculated once for a given velocity model. */
/*  this is why nl, thk(l), and d(l) are included as input parameters */
/*  for raypath.  when calling layers, the event and receiver must */
/*  be located within the horizontal confines of the grid, that is, */
/*  x(1) <= xe, xr <= x(nx) and y(1) <= ye, yr <= y(ny). */
/*       subrs. refract and direct determine refracted and direct */
/*  ray travel times and other parameters in a relatively standard */
/*  fashion, but are sufficiently general to account for low velocity */
/*  layers. */
/*       once the nature of the fastest ray  has been determined, the */
/*  calculation of a set of raypoints along the path is straightforward */
/*  and is performed by subr. strpath, refpath, or dirpath.  these */
/*  points consist of the event and receiver coordinates and, in the cases */
/*  of refpath and dirpath, every intermediate point at which the ray */
/*  crosses a boundary between layers. */
/*       because of the extensive branching in raypath, a parameter */
/*  to index the the 7 return statements in the main subr., */
/*  nrtn is included and takes on values from 1 to 7 (to 8 with extension */
/*  of reflected waves ! U.K. 11/1986). */

/*  input: */
/*           nx,ny,nz - number of grid planes in x,y,z directions */
/*     x(i),y(j),z(k) - gridpoint coordinates */
/*         vel(i,j,k) - velocity at grid point x(i),y(j),z(k) */

/*                 nl - number of layers (should equal nz) */
/*             thk(l) - thickness of layer l */
/*               d(l) - depth to top of layer l */

/*           xe,ye,ze - event coordinates */
/*           xr,yr,zr - receiver coordinates */

/*  output: */
/*              v(l) - velocity of layer l */
/*            vsq(l) = v(l) ** 2 */
/*               nrp - number of raypoints */
/*    rp(1,2,or 3,i) - coordinates of raypoint i */

/*  important internal arrays and variables: */

/*            delta - horizontal distance between source and receiver */
/*            depth - depth of event below receiver */
/*               jl - number of event layer */
/*              tkj - depth of event from top of event layer */

/*               kk - refracting layer for fastest refracted ray */
/*           didjkk - critical distance for refraction in layer kk */
/*             tref - refracted ray travel time */
/*           xovmax - an upper bound on delta for which the direct ray */
/*                       can be the first arrival */

/*           salpha - sine of the takeoff angle of the direct ray */
/*            deljl - horizontal travel distance of the */
/*                        direct ray in the event layer */
/*             tdir - direct ray travel time */
/*             nrtn - index to point of return from raypath */

/*  subrs. called: */

/*          layers      - constructs  averaged layered model */

/*          stpath      - straight raypath */
/*          strpath     - NOT USED !! straight raypath from event to receiver */

/*          direct      - for the direct ray: */
/*                          salpha, deljl, tdir */
/*          dirpath     - direct ray path */

/*          reflect1     - for reflected ray */
/*          reflect     - NOT USED !! for reflected ray */
/*          reflectpath - reflected ray path */

/*          refract     - for the fastest refracted ray: */
/*                         kk, didjkk, tref, xovmax */
/*          tiddid      - travel-time intercept & crit. distance for a ray */
/*          refpath     - refracted ray path */

/* ek max. nr of raypoints =50 */

    /* Parameter adjustments */
    --x;
    --y;
    vel_dim1 = *nx;
    vel_dim2 = *ny;
    vel_offset = 1 + vel_dim1 * (1 + vel_dim2);
    vel -= vel_offset;
    --z__;
    --vsq;
    --v;
    --d__;
    --thk;
    rp -= 4;

    /* Function Body */
L1313:

/* restart here in case of an error in REFLECT !! */
    *sterr = 0.f;
    *direrr = 0.f;
    *refrerr = 0.f;
    *reflerr = 0.f;

    if (*ze < d__[1]) {
	s_stop("RAYPATH>>> earthquake ABOVE model!", (ftnlen)34);
    }
    if (*zr < d__[1]) {
	s_stop("RAYPATH>>> station ABOVE model!", (ftnlen)31);
    }

    depth = *ze - *zr;
/* Computing 2nd power */
    r__1 = *xr - *xe;
/* Computing 2nd power */
    r__2 = *yr - *ye;
    delta = sqrt(r__1 * r__1 + r__2 * r__2);
    l = *nl;
L23107:
    if (! (d__[l] >= *ze)) {
	goto L23108;
    }

/*   determine event layer */

    --l;
    goto L23107;
L23108:
    *jl = l;
    d__[1] = *zr;
/*   adjust for nonzero depth of reciever */

    thk[1] = d__[2] - *zr;
    *tkj = *ze - d__[*jl];
    if (! (delta < .05f)) {
	goto L23105;
    }
    stpath_(xe, ye, ze, xr, yr, zr, &rp[4], nrp, ttt, nl, jl, tkj, &v[1], &
	    d__[1], &thk[1], sterr);

/*   if delta is small, set a straight path */

    *nrtn = 1;
    return 0;
L23105:

/*   assign averaged layer velocities */

    if (*itype == 1) {
	goto L1;
    }
    layers_(nx, ny, nz, &x[1], &y[1], &z__[1], &vel[vel_offset], xe, ye, xr, 
	    yr, nl, &v[1], &vsq[1]);
L1:
    if (! (*jl == *nl)) {
	goto L23109;
    }

/*   consider only the direct ray if the event is in the half space */

    direct1_(nl, &v[1], &vsq[1], &thk[1], jl, tkj, &delta, &depth, &tdir, &
	    salpha, &deljl);
    dirpath_(xe, ye, ze, xr, yr, zr, &delta, nl, &v[1], &vsq[1], &thk[1], jl, 
	    tkj, &salpha, &deljl, &rp[4], nrp, direrr);
    *nrtn = 2;
    *ttt = tdir;
    return 0;
L23109:


    if (*mll <= 0) {
	goto L23110;
    }
/*     MLL > 0  : a reflection layer is specified; ray MUST be reflected! */
/* test      call reflect(nl,v,vsq,thk,jl,tkj,delta,depth,mll,trefl,ain,ierr, */
/* test     &             DTDDrefl,DTDHrefl) */
    reflect1_(nl, &v[1], &vsq[1], &thk[1], jl, tkj, &delta, &depth, mll, &
	    trefl, &ain, &ierr, dtddrefl, dtdhrefl);
    if (ierr != 0) {
	s_wsle(&io___1621);
	do_lio(&c__9, &c__1, "trying another ray-type...", (ftnlen)26);
	e_wsle();
	s_wsle(&io___1622);
	do_lio(&c__9, &c__1, "trying another ray-type...", (ftnlen)26);
	e_wsle();
	*mll = 0;
/* maybe it works with another ray-type... */
	goto L1313;
/* retry */
    }
    reflectpath_(xe, ye, ze, xr, yr, zr, &delta, nl, &v[1], &vsq[1], &thk[1], 
	    jl, tkj, &ain, mll, &rp[4], nrp, reflerr);

    *ttt = trefl;
    *nrtn = 8;
/* reflected wave */
    return 0;
L23110:

/*   find the first refracted ray to arrive */

    refract_(nl, &v[1], &vsq[1], &thk[1], jl, tkj, &delta, &kk, &tref, &
	    didjkk, &xovmax);
    if (! (delta > xovmax)) {
	goto L23111;
    }
/*   for delta greater than xovmax */
/*   1st arrival is the refracted ray */

    refpath_(xe, ye, ze, xr, yr, zr, &delta, nl, &v[1], &vsq[1], &thk[1], tkj,
	     jl, &kk, &didjkk, &rp[4], nrp, refrerr);
    *nrtn = 3;
    *ttt = tref;
    return 0;
L23111:
    if (! (*jl == 1)) {
	goto L23113;
    }
/* Computing 2nd power */
    r__1 = *tkj;
/* Computing 2nd power */
    r__2 = delta;
    tdir = sqrt(r__1 * r__1 + r__2 * r__2) / v[1];
    if (! (tref < tdir)) {
	goto L23115;
    }

/*   if refracted ray is 1st arrival */

    refpath_(xe, ye, ze, xr, yr, zr, &delta, nl, &v[1], &vsq[1], &thk[1], tkj,
	     jl, &kk, &didjkk, &rp[4], nrp, refrerr);
    *nrtn = 4;
    *ttt = tref;
    return 0;
L23115:

/*   if direct ray is 1st arrival */

    stpath_(xe, ye, ze, xr, yr, zr, &rp[4], nrp, ttt, nl, jl, tkj, &v[1], &
	    d__[1], &thk[1], sterr);
    *nrtn = 5;
    *ttt = tdir;
    return 0;
L23113:

/*   for event below layer 1 */

    direct1_(nl, &v[1], &vsq[1], &thk[1], jl, tkj, &delta, &depth, &tdir, &
	    salpha, &deljl);
    if (! (tref < tdir)) {
	goto L23117;
    }

/*   if refracted ray is 1st arrival */

    refpath_(xe, ye, ze, xr, yr, zr, &delta, nl, &v[1], &vsq[1], &thk[1], tkj,
	     jl, &kk, &didjkk, &rp[4], nrp, refrerr);
    *ttt = tref;
    *nrtn = 6;
    return 0;
L23117:

/*   if direct ray is 1st arrival */

    dirpath_(xe, ye, ze, xr, yr, zr, &delta, nl, &v[1], &vsq[1], &thk[1], jl, 
	    tkj, &salpha, &deljl, &rp[4], nrp, direrr);
    *nrtn = 7;
    *ttt = tdir;
    return 0;
} /* raypath_ */


/* of subr. raypath */
/* Subroutine */ int layers_(integer *nx, integer *ny, integer *nz, real *x, 
	real *y, real *z__, real *vel, real *xe, real *ye, real *xr, real *yr,
	 integer *nl, real *v, real *vsq)
{
    /* System generated locals */
    integer vel_dim1, vel_dim2, vel_offset, i__1, i__2;
    real r__1;

    /* Local variables */
    static real a, b, c__, d__;
    static integer i__, j, l;
    static real u[100], w[4];
    static integer ie, je, ir, jr;
    static real vpt1, vpt2, vpt3, vpt4;
    static integer imin, jmin;
    static real xseg, yseg;
    static integer ipts;
    static real denom;
    static integer numseg, ipoint, jpoint;
    static real vpoint, xpoint, ypoint;
    static integer numpts;


/*  Subr. layers converts a 3 - dimensional velocity model to a */
/*  1 - dimensional layered model by averaging slownesses between */
/*  specified event and receiver positions.  the input */
/*  model must consist of velocities specified at grid */
/*  points at the intersections of 3 orthogonal grid planes. */
/*  slownesses are averaged along a segment joining the */
/*  horizontal event and receiver positions in each grid plane */
/*  specified by z(k). */

/*  input: */
/*           nx,ny,nz - numbers of grid planes */
/*     x(i),y(j),z(k) - grid point coordinates */
/*         vel(i,j,k) - velocity at point x(i),y(j),z(k) */
/*              xe,ye - horizontal event coordinates */
/*              xr,yr - horizontal receiver coordinates */
/*                 nl - number of layers (should equal nz) */

/*  output: */
/*           v(l) - velocity of layer l */
/*         vsq(l) = v(l) ** 2 */


/*   locate the event and the reciever within horizontal */
/*   grid rectangles */

    /* Parameter adjustments */
    --x;
    --y;
    vel_dim1 = *nx;
    vel_dim2 = *ny;
    vel_offset = 1 + vel_dim1 * (1 + vel_dim2);
    vel -= vel_offset;
    --z__;
    --vsq;
    --v;

    /* Function Body */
    i__ = 1;
L23119:
    if (! (x[i__] < *xe)) {
	goto L23120;
    }
    ++i__;
    goto L23119;
L23120:
    ie = i__ - 1;
    if (! (ie == 0)) {
	goto L23121;
    }
    ie = 1;
L23121:
    j = 1;
L23123:
    if (! (y[j] < *ye)) {
	goto L23124;
    }
    ++j;
    goto L23123;
L23124:
    je = j - 1;
    if (! (je == 0)) {
	goto L23125;
    }
    je = 1;
L23125:
    i__ = 1;
L23127:
    if (! (x[i__] < *xr)) {
	goto L23128;
    }
    ++i__;
    goto L23127;
L23128:
    ir = i__ - 1;
    if (! (ir == 0)) {
	goto L23129;
    }
    ir = 1;
L23129:
    j = 1;
L23131:
    if (! (y[j] < *yr)) {
	goto L23132;
    }
    ++j;
    goto L23131;
L23132:
    jr = j - 1;
    if (! (jr == 0)) {
	goto L23133;
    }
    jr = 1;
L23133:
    imin = min(ie,ir);
    jmin = min(je,jr);

/*   choose the number of points to use for averaging slownesses */
/*   and calculates x and y increments between points */

    numseg = (i__1 = ir - ie, abs(i__1)) + (i__2 = jr - je, abs(i__2)) + 1;
    numpts = numseg + 1;
    xseg = (*xr - *xe) / (numseg * 1.f);
    yseg = (*yr - *ye) / (numseg * 1.f);
    i__1 = *nl;
    for (l = 1; l <= i__1; ++l) {
	u[l - 1] = 0.f;
/* L23135: */
    }
/* L23136: */

/*   loop to sum slownesses in each layer, u(l), at points */
/*   between the event and the reciever */

    i__1 = numpts;
    for (ipts = 1; ipts <= i__1; ++ipts) {
	xpoint = *xe + (ipts - 1) * xseg;
	ypoint = *ye + (ipts - 1) * yseg;

/*   locate (xpoint,ypoint) within a grid rectangle */

	i__ = imin;
L23139:
	if (! (xpoint > x[i__])) {
	    goto L23140;
	}
	++i__;
	goto L23139;
L23140:
	ipoint = i__ - 1;
	if (! (ipoint == 0)) {
	    goto L23141;
	}
	ipoint = 1;
L23141:
	j = jmin;
L23143:
	if (! (ypoint > y[j])) {
	    goto L23144;
	}
	++j;
	goto L23143;
L23144:
	jpoint = j - 1;
	if (! (jpoint == 0)) {
	    goto L23145;
	}
	jpoint = 1;
L23145:

/*   choosing weighting factors for interpolation within */
/*   a horizontal rectangle on the velocity grid */

	a = xpoint - x[ipoint];
	b = x[ipoint + 1] - xpoint;
	c__ = ypoint - y[jpoint];
	d__ = y[jpoint + 1] - ypoint;
	denom = (a + b) * (c__ + d__);
	w[0] = b * d__ / denom;
	w[1] = a * d__ / denom;
	w[2] = b * c__ / denom;
	w[3] = a * c__ / denom;

/*   loop to interpolate for the velocity, vpoint, at */
/*   (xpoint,ypoint) in each layer and add its */
/*   reciprocal to the sum of the slownesses in that layer */

	i__2 = *nl;
	for (l = 1; l <= i__2; ++l) {
	    vpt1 = w[0] * vel[ipoint + (jpoint + l * vel_dim2) * vel_dim1];
	    vpt2 = w[1] * vel[ipoint + 1 + (jpoint + l * vel_dim2) * vel_dim1]
		    ;
	    vpt3 = w[2] * vel[ipoint + (jpoint + 1 + l * vel_dim2) * vel_dim1]
		    ;
	    vpt4 = w[3] * vel[ipoint + 1 + (jpoint + 1 + l * vel_dim2) * 
		    vel_dim1];
	    vpoint = vpt1 + vpt2 + vpt3 + vpt4;
	    u[l - 1] += 1 / vpoint;
/* L23147: */
	}
/* L23148: */
/* L23137: */
    }
/* L23138: */

/*   loop to calculate the velocity from the sum of the */
/*   slownesses for each layer */

    i__1 = *nl;
    for (l = 1; l <= i__1; ++l) {
	v[l] = numpts * 1.f / u[l - 1];
/* Computing 2nd power */
	r__1 = v[l];
	vsq[l] = r__1 * r__1;
/* L23149: */
    }
/* L23150: */
    return 0;
} /* layers_ */


/* of subr. layers */
/* Subroutine */ int stpath_(real *xe, real *ye, real *ze, real *xr, real *yr,
	 real *zr, real *rp, integer *nrp, real *tt, integer *nl, integer *jl,
	 real *tkj, real *v, real *d__, real *thk, real *sterr)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer j, j1, jb, jt, jl1;



    /* Parameter adjustments */
    rp -= 4;
    --thk;
    --d__;
    --v;

    /* Function Body */
    *nrp = *jl + 1;
/*  assign points along raypath */
    rp[4] = *xe;
    rp[5] = *ye;
    rp[6] = *ze;

    if (*nrp == 2) {
	goto L50;
    }

    jl1 = *jl - 1;
/* uk      do 25 j=1,jl1    ! calculate up to the top and then compute an error */
    i__1 = jl1 + 1;
    for (j = 1; j <= i__1; ++j) {
	j1 = j + 1;
	rp[j1 * 3 + 1] = *xe;
	rp[j1 * 3 + 2] = *ye;
	jb = *jl - j + 1;
	rp[j1 * 3 + 3] = d__[jb];
/* L25: */
    }

L50:
    if (*nrp > 2) {
/* Computing 2nd power */
	r__1 = rp[*nrp * 3 + 1] - *xr;
/* Computing 2nd power */
	r__2 = rp[*nrp * 3 + 2] - *yr;
/* Computing 2nd power */
	r__3 = rp[*nrp * 3 + 3] - *zr;
	*sterr = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3) * 1e3f;
    }
    rp[*nrp * 3 + 1] = *xr;
    rp[*nrp * 3 + 2] = *yr;
    rp[*nrp * 3 + 3] = *zr;

/*  compute travel time */
    *tt = *tkj / v[*jl];
    if (*nrp == 2) {
	return 0;
    }

    i__1 = jl1;
    for (j = 1; j <= i__1; ++j) {
	jt = *jl - j;
	*tt += thk[jt] / v[jt];
/* L75: */
    }
    return 0;
} /* stpath_ */


/* of subr. stpath */
/* Subroutine */ int strpath_(real *xe, real *ye, real *ze, real *xr, real *
	yr, real *zr, real *rp, integer *nrp)
{

/*       strpath assigns raypoint coordinates for a straight path */
/*  between the event and the receiver. */

/*  input:  (xe,ye,ze) - event coordinates */
/*          (xr,yr,zr) - receiver coordinates */

/*  output:   rp(1,2,or 3,i) - coordinates of raypoint i */
/*                       nrp - number of raypoints = 2 */

    /* Parameter adjustments */
    rp -= 4;

    /* Function Body */
    *nrp = 2;
    rp[4] = *xe;
    rp[5] = *ye;
    rp[6] = *ze;
    rp[7] = *xr;
    rp[8] = *yr;
    rp[9] = *zr;
    return 0;
} /* strpath_ */


/* of subr. strpath */
/* Subroutine */ int direct1_(integer *nl, real *v, real *vsq, real *thk, 
	integer *jl, real *tkj, real *delta, real *depth, real *tdir, real *u,
	 real *x)
{
    /* Format strings */
    static char fmt_1000[] = "(/,2x,\002subr. direct1: \002,3i4,2f10.4,f15.6"
	    ",3f10.5,/)";

    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen),
	     e_wsfe(void);

    /* Local variables */
    static integer l, j1;
    static real ua, ub, xa, xb, del, usq, dela, delb;
    static integer lmax;
    static real uasq, ubsq, ubdiv, vlmax;
    static integer kount;
    static real xtest, tklmax;

    /* Fortran I/O blocks */
    static cilist io___1677 = { 0, 16, 0, 0, 0 };
    static cilist io___1678 = { 0, 16, 0, fmt_1000, 0 };



/*       for the direct seismic ray from an event to a receiver in */
/*  a layered velocity structure, direct predicts the travel time, the */
/*  sine of the takeoff angle, and the horizontal distance of travel in */
/*  the event layer.  the receiver must be located at the top of layer */
/*  1 and the event must be located below layer 1.  low velocity */
/*  layers are permitted. */
/*       to find the takeoff angle of the ray, a numerical approach */
/*  is required.  the basic scheme adopted here is the method of false */
/*  position.  (see acton, 1970, 'numerical methods that work,' for */
/*  example.)  first, the characteristics of the fastest layer */
/*  between the event and the surface are determined.  these permit */
/*  placing definite lower and upper bounds, ua and ub, on the */
/*  sine of the takeoff angle.  in turn, lower and upper bounds, xa */
/*  and xb, on the horizontal travel distance in the event layer are */
/*  determined.  the total horizontal travel distance for a ray with */
/*  with horizontal travel distance x in the event layer is denoted */
/*  by del, and the zero of del - delta is obtained by using xa and */
/*  xb as initial guesses for x in the method of false position */
/*  from x and tkj, the depth of the event below the top of the event */
/*  layer, the sine of the takeoff angle, u , is calculated. */
/*       from u and x, tdir is found by summing the travel time in */
/*  each layer.  finally, a slight correction to tdir is made, based */
/*  on the misfit between the final del and delta. */

/*  input:     nl - number of layers */
/*           v(l) - velocity of layer l */
/*         vsq(l) = v(l) ** 2 */
/*         thk(l) - thickness of layer l */
/*             jl - event layer */
/*            tkj - depth of event from top of event layer */
/*          delta - horizontal distance between event and receiver */
/*          depth - depth of event */

/*  output:  tdir - direct ray travel time */
/*              u - sine of the takeoff angle */
/*              x - horizontal travel distance in the event layer */


/*  find the fastest layer, lmax, above and including jl */


    /* Parameter adjustments */
    --thk;
    --vsq;
    --v;

    /* Function Body */
    del = 0.f;

/* U.K. 28. Jan. 1987 */
    lmax = *jl;
    tklmax = *tkj;
    vlmax = v[*jl];
    j1 = *jl - 1;
    i__1 = j1;
    for (l = 1; l <= i__1; ++l) {
	if (! (v[l] > vlmax)) {
	    goto L23186;
	}
	lmax = l;
	tklmax = thk[l];
	vlmax = v[l];
L23186:
/* L23184: */
	;
    }
/* L23185: */
/* CHANGE BY E.KISSLING MARCH 1984 */
    if (tklmax <= .05f) {
	tklmax = .05f;
    }

/*   find initial bounds on the sine of the takeoff angle */

/* Computing 2nd power */
    r__1 = *delta;
/* Computing 2nd power */
    r__2 = *depth;
    ua = v[*jl] / vlmax * *delta / sqrt(r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
    r__1 = *delta;
/* Computing 2nd power */
    r__2 = tklmax;
    ub = v[*jl] / vlmax * *delta / sqrt(r__1 * r__1 + r__2 * r__2);

/*   calculate horizontal travel distances */

/* Computing 2nd power */
    r__1 = ua;
    uasq = r__1 * r__1;
/* Computing 2nd power */
    r__1 = ub;
    ubsq = r__1 * r__1;
/* CHANGE BY E.KISSLING MARCH 1984 */
    if (ubsq >= 1.f) {
	ubsq = .99999f;
    }
    if (uasq >= 1.f) {
	uasq = .99999f;
    }
    xa = *tkj * ua / sqrt(1.f - uasq);
    if (! (lmax == *jl)) {
	goto L23188;
    }
    xb = *delta;
    goto L23189;
L23188:
    xb = *tkj * ub / sqrt(1.f - ubsq);
L23189:
    dela = xa;
    delb = xb;
    i__1 = j1;
    for (l = 1; l <= i__1; ++l) {
	dela += thk[l] * ua / sqrt(vsq[*jl] / vsq[l] - uasq);
	ubdiv = sqrt(vsq[*jl] / vsq[l] - ubsq);
	if (ubdiv > 1e-20f) {
	    goto L1002;
	}
	s_wsle(&io___1677);
	do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
	e_wsle();
	s_wsfe(&io___1678);
	do_fio(&c__1, (char *)&(*jl), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&lmax, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&vsq[*jl], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&vsq[l], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&ubsq, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&(*delta), (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&tklmax, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&vlmax, (ftnlen)sizeof(real));
	e_wsfe();
	ubdiv = 1e-20f;
L1002:
	delb += thk[l] * ub / sqrt(vsq[*jl] / vsq[l] - ubsq);
/* L23190: */
    }
/* L23191: */

/*   loop to find the zero of del-delta by teh method of false position */

/*  NOT used... !!! */
    for (kount = 1; kount <= 25; ++kount) {
	if (! (delb - dela < .02f)) {
	    goto L23194;
	}
	*x = (xa + xb) * .5f;
/* Computing 2nd power */
	r__1 = *x;
/* Computing 2nd power */
	r__2 = *tkj;
	*u = *x / sqrt(r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
	r__1 = *u;
	usq = r__1 * r__1;
	goto L23193;
L23194:
	*x = xa + (*delta - dela) * (xb - xa) / (delb - dela);
/* Computing 2nd power */
	r__1 = *x;
/* Computing 2nd power */
	r__2 = *tkj;
	*u = *x / sqrt(r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
	r__1 = *u;
	usq = r__1 * r__1;
	del = *x;
	i__1 = j1;
	for (l = 1; l <= i__1; ++l) {
	    del += thk[l] * *u / sqrt(vsq[*jl] / vsq[l] - usq);
/* L23196: */
	}
/* L23197: */
	xtest = del - *delta;
	if (! (dabs(xtest) < .02f)) {
	    goto L23198;
	}
	goto L23193;
L23198:
	if (! (xtest < 0.f)) {
	    goto L23200;
	}
	xa = *x;
	dela = del;
	goto L23201;
L23200:
	xb = *x;
	delb = del;
L23201:
/* L23192: */
	;
    }
L23193:

/*   calculate direct ray travel time */


    if (del == 0.f) {
	del = *x;
    }

/* U.K. 28. Jan. 1987 */
/* Computing 2nd power */
    r__1 = *x;
/* Computing 2nd power */
    r__2 = *tkj;
    *tdir = sqrt(r__1 * r__1 + r__2 * r__2) / v[*jl];
    i__1 = j1;
    for (l = 1; l <= i__1; ++l) {
	*tdir += thk[l] * v[*jl] / (vsq[l] * sqrt(vsq[*jl] / vsq[l] - usq));
/* L23202: */
    }
/* L23203: */
    *tdir -= *u / v[*jl] * (del - *delta);
    return 0;
} /* direct1_ */


/* of subr. direct1 */
/* Subroutine */ int dirpath_(real *xe, real *ye, real *ze, real *xr, real *
	yr, real *zr, real *delta, integer *nl, real *v, real *vsq, real *thk,
	 integer *jl, real *tkj, real *salpha, real *deljl, real *rp, integer 
	*nrp, real *direrr)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, m;
    static real d1, d2, tng;
    static integer nrp1;


/*       dirpath assigns raypoints with coordinates rp(1,i),rp(2,i), */
/*  rp(3,i) along a direct seismic raypath in a flat layered earth. */

/*  input:  xe,ye,ze - event coordinates */
/*          xr,yr,zr - receiver coordinates */
/*             delta - horizontal distance between event and receiver */
/*                nl - total number of layers in model */
/*                     (used only to dimension v vsq and thk) */
/*              v(l) - velocity of layer l */
/*            vsq(l) = v(l) ** 2 */
/*            thk(l) - thickness of layer l */
/*                jl - event layer */
/*               tkj - depth of event from top of event layer */
/*            salpha - sine of takeoff angle */
/*             deljl - horizontal travel distance in event layer */

/*  output:  rp(1,2,or 3,i) - raypoint coordinates */
/*                      nrp - number of raypoints */

/* ek max. nr of raypoints =50 */
    /* Parameter adjustments */
    --thk;
    --vsq;
    --v;
    rp -= 4;

    /* Function Body */
    d1 = (*xr - *xe) / *delta;
    d2 = (*yr - *ye) / *delta;
    *nrp = *jl + 1;

/*   assign raypoint coordinates */

    rp[4] = *xe;
    rp[5] = *ye;
    rp[6] = *ze;
    rp[7] = rp[4] + *deljl * d1;
    rp[8] = rp[5] + *deljl * d2;
    rp[9] = rp[6] - *tkj;
/* uk      nrp1=nrp-1 */
    nrp1 = *nrp;
/* calculate up to the top and then compute an error ! */
    i__1 = nrp1;
    for (i__ = 3; i__ <= i__1; ++i__) {
	m = *nrp - (i__ - 1);

/*   m is the number of the layer below ray point i */

/* Computing 2nd power */
	r__1 = *salpha;
	tng = v[m] * *salpha / sqrt(vsq[*jl] - vsq[m] * (r__1 * r__1));

/*   tng is the tangent of the angle of incidence in layer m */

	rp[i__ * 3 + 1] = rp[(i__ - 1) * 3 + 1] + thk[m] * tng * d1;
	rp[i__ * 3 + 2] = rp[(i__ - 1) * 3 + 2] + thk[m] * tng * d2;
	rp[i__ * 3 + 3] = rp[(i__ - 1) * 3 + 3] - thk[m];
/* L23208: */
    }
/* L23209: */
/* Computing 2nd power */
    r__1 = rp[*nrp * 3 + 1] - *xr;
/* Computing 2nd power */
    r__2 = rp[*nrp * 3 + 2] - *yr;
/* Computing 2nd power */
    r__3 = rp[*nrp * 3 + 3] - *zr;
    *direrr = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3) * 1e3f;
    rp[*nrp * 3 + 1] = *xr;
    rp[*nrp * 3 + 2] = *yr;
    rp[*nrp * 3 + 3] = *zr;
    return 0;
} /* dirpath_ */


/* of subr. dirpath */
/* Subroutine */ int reflect1_(integer *nl, real *v, real *vsq, real *thk, 
	integer *jl, real *tkj, real *delta, real *z__, integer *mll, real *
	trefl, real *ain, integer *ierr, real *dtddrefl, real *dtdhrefl)
{
    /* Format strings */
    static char fmt_1000[] = "(/,2x,\002subr. reflect1: \002,3i4,2f10.4,f15."
	    "6,3f10.5,/)";

    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, l, m;
    static real u, x;
    static integer j1;
    static real ua, ub, xa, xb, fac, del, div[100], usq, dela, delb;
    static integer lmax;
    static real tdir, uasq, ubsq, depth, ubdiv, vlmax;
    static integer kount;
    static real xtest, tklmax;

    /* Fortran I/O blocks */
    static cilist io___1689 = { 0, 6, 0, 0, 0 };
    static cilist io___1690 = { 0, 6, 0, 0, 0 };
    static cilist io___1691 = { 0, 6, 0, 0, 0 };
    static cilist io___1692 = { 0, 6, 0, 0, 0 };
    static cilist io___1693 = { 0, 16, 0, 0, 0 };
    static cilist io___1694 = { 0, 16, 0, 0, 0 };
    static cilist io___1714 = { 0, 16, 0, 0, 0 };
    static cilist io___1715 = { 0, 16, 0, fmt_1000, 0 };



/*     Urs Kradolfer, Nov. 1986 */



/* hypocenter-layer */
/* reflection at bottom of layer MLL */
/* dimension = max. number of layers allowed */
/* auftauchwinkel in rad */
/* hypocenter-depth */
/* distance epicenter-receiver */

    /* Parameter adjustments */
    --thk;
    --vsq;
    --v;

    /* Function Body */
    *ierr = 0;
    *dtddrefl = 0.f;
    *dtdhrefl = 0.f;


    del = 0.f;

/* U.K. 28. Jan. 1987 */
    if (*jl > *mll) {
/*  hypocenter below reflector !!! */
	s_wsle(&io___1689);
	do_lio(&c__9, &c__1, "hypocenter-layer jl = ", (ftnlen)22);
	do_lio(&c__3, &c__1, (char *)&(*jl), (ftnlen)sizeof(integer));
	e_wsle();
	s_wsle(&io___1690);
	do_lio(&c__9, &c__1, "reflection at bottom of layer mll = ", (ftnlen)
		36);
	do_lio(&c__3, &c__1, (char *)&(*mll), (ftnlen)sizeof(integer));
	e_wsle();
	*ierr = -1;
	s_wsle(&io___1691);
	do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
	e_wsle();
	s_wsle(&io___1692);
	do_lio(&c__9, &c__1, "subr. REFLECT1 >>> hypocenter is below reflect"
		"or!", (ftnlen)49);
	e_wsle();
	s_wsle(&io___1693);
	do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
	e_wsle();
	s_wsle(&io___1694);
	do_lio(&c__9, &c__1, "subr. REFLECT1 >>> hypocenter is below reflect"
		"or!", (ftnlen)49);
	e_wsle();
/* cc         stop'subr. REFLECT1 >>> hypocenter below reflector!' */
    }
    if (*mll > *nl) {
	s_stop("subr. REFLECT1 >>> reflector-nr > number of layers !", (
		ftnlen)52);
    }

/*  determine out of real model (THK) transformed model (DIV) */

    i__1 = *mll;
    for (m = 1; m <= i__1; ++m) {
/* LAYER M IS PASSED ONLY ONCE: */
	fac = 1.f;
	if (*jl > m) {
	    goto L505;
	}
/* LAYER M IS PASSED TWICE */
	fac = 2.f;
	if (*jl < m) {
	    goto L505;
	}
/* LAYER M CONTAINS HYPOCENTER: */
	fac = (thk[m] * 2.f - *tkj) / thk[m];
L505:
	div[m - 1] = fac * thk[m];
    }
    depth = 0.f;
    i__1 = *mll;
    for (i__ = 1; i__ <= i__1; ++i__) {
	depth += div[i__ - 1];
    }


/*  now 'new' model is established; layer-thicknesses are stored in DIV(1...mll) */

    lmax = *mll;
    tklmax = div[*mll - 1];
    vlmax = v[*mll];
    j1 = *mll - 1;
    i__1 = j1;
    for (l = 1; l <= i__1; ++l) {
	if (! (v[l] > vlmax)) {
	    goto L23186;
	}
	lmax = l;
	tklmax = div[l - 1];
	vlmax = v[l];
L23186:
/* L23184: */
	;
    }
/* L23185: */
/* CHANGE BY E.KISSLING MARCH 1984 */
    if (tklmax <= .05f) {
	tklmax = .05f;
    }

/*   find initial bounds on the sine of the takeoff angle */

/* Computing 2nd power */
    r__1 = *delta;
/* Computing 2nd power */
    r__2 = depth;
    ua = v[*mll] / vlmax * *delta / sqrt(r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
    r__1 = *delta;
/* Computing 2nd power */
    r__2 = tklmax;
    ub = v[*mll] / vlmax * *delta / sqrt(r__1 * r__1 + r__2 * r__2);

/*   calculate horizontal travel distances */

/* Computing 2nd power */
    r__1 = ua;
    uasq = r__1 * r__1;
/* Computing 2nd power */
    r__1 = ub;
    ubsq = r__1 * r__1;
/* CHANGE BY E.KISSLING MARCH 1984 */
    if (ubsq >= 1.f) {
	ubsq = .99999f;
    }
    if (uasq >= 1.f) {
	uasq = .99999f;
    }
    xa = div[*mll - 1] * ua / sqrt(1.f - uasq);
    if (! (lmax == *mll)) {
	goto L23188;
    }
    xb = *delta;
    goto L23189;
L23188:
    xb = div[*mll - 1] * ub / sqrt(1.f - ubsq);
L23189:
    dela = xa;
    delb = xb;
    i__1 = j1;
    for (l = 1; l <= i__1; ++l) {
	dela += div[l - 1] * ua / sqrt(vsq[*mll] / vsq[l] - uasq);
	ubdiv = sqrt(vsq[*mll] / vsq[l] - ubsq);
	if (ubdiv > 1e-20f) {
	    goto L1002;
	}
	s_wsle(&io___1714);
	do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
	e_wsle();
	s_wsfe(&io___1715);
	do_fio(&c__1, (char *)&(*mll), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&lmax, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&vsq[*mll], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&vsq[l], (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&ubsq, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&(*delta), (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&tklmax, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&vlmax, (ftnlen)sizeof(real));
	e_wsfe();
	ubdiv = 1e-20f;
L1002:
	delb += div[l - 1] * ub / sqrt(vsq[*mll] / vsq[l] - ubsq);
/* L23190: */
    }
/* L23191: */

/*   loop to find the zero of del-delta by teh method of false position */

/*  NOT used... !!! */
    for (kount = 1; kount <= 25; ++kount) {
	if (! (delb - dela < .02f)) {
	    goto L23194;
	}
	x = (xa + xb) * .5f;
/* Computing 2nd power */
	r__1 = x;
/* Computing 2nd power */
	r__2 = div[*mll - 1];
	u = x / sqrt(r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
	r__1 = u;
	usq = r__1 * r__1;
	goto L23193;
L23194:
	x = xa + (*delta - dela) * (xb - xa) / (delb - dela);
/* Computing 2nd power */
	r__1 = x;
/* Computing 2nd power */
	r__2 = div[*mll - 1];
	u = x / sqrt(r__1 * r__1 + r__2 * r__2);
/* Computing 2nd power */
	r__1 = u;
	usq = r__1 * r__1;
	del = x;
	i__1 = j1;
	for (l = 1; l <= i__1; ++l) {
	    del += div[l - 1] * u / sqrt(vsq[*mll] / vsq[l] - usq);
/* L23196: */
	}
/* L23197: */
	xtest = del - *delta;
	if (! (dabs(xtest) < .02f)) {
	    goto L23198;
	}
	goto L23193;
L23198:
	if (! (xtest < 0.f)) {
	    goto L23200;
	}
	xa = x;
	dela = del;
	goto L23201;
L23200:
	xb = x;
	delb = del;
L23201:
/* L23192: */
	;
    }
L23193:

/*   calculate direct ray travel time */


    if (del == 0.f) {
	del = x;
    }

/* U.K. 28. Jan. 1987 */
/* Computing 2nd power */
    r__1 = x;
/* Computing 2nd power */
    r__2 = div[*mll - 1];
    tdir = sqrt(r__1 * r__1 + r__2 * r__2) / v[*mll];
    i__1 = j1;
    for (l = 1; l <= i__1; ++l) {
	tdir += div[l - 1] * v[*mll] / (vsq[l] * sqrt(vsq[*mll] / vsq[l] - 
		usq));
/* L23202: */
    }
/* L23203: */
    tdir -= u / v[*mll] * (del - *delta);

    *trefl = tdir;
/* ---- u is sine of the 'takeoff-angle' in */
/* ---- transformed model = emerging angle at reflector! */
/* ---- Find now takeoff-angle at source! */
    *ain = u;
    if (*mll > *jl) {
	i__1 = *jl;
	for (i__ = *mll - 1; i__ >= i__1; --i__) {
	    *ain = *ain * v[i__] / v[i__ + 1];
	}
    }

    return 0;
} /* reflect1_ */


/* of subr. reflect1 */
/* Subroutine */ int reflect_(integer *nl, real *v, real *vsq, real *thk, 
	integer *jl, real *tkj, real *delta, real *z__, integer *mll, real *
	trefl, real *ain, integer *ierr, real *dtddrefl, real *dtdhrefl)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double atan2(doublereal, doublereal), sin(doublereal), sqrt(doublereal), 
	    cos(doublereal);

    /* Local variables */
    static real a;
    static integer i__, m;
    static real da, ti, vi[100], tt, da2, fac, dti, div[100];
    static integer nit;
    static real sum, sqr, ddda, dtda, dtdd, dtdh, anin, sina, zbig, vsqu[100],
	     sina2, test4, dddas, dellit;

    /* Fortran I/O blocks */
    static cilist io___1726 = { 0, 6, 0, 0, 0 };
    static cilist io___1727 = { 0, 6, 0, 0, 0 };
    static cilist io___1728 = { 0, 16, 0, 0, 0 };
    static cilist io___1729 = { 0, 16, 0, 0, 0 };
    static cilist io___1742 = { 0, 16, 0, 0, 0 };
    static cilist io___1743 = { 0, 16, 0, 0, 0 };
    static cilist io___1744 = { 0, 16, 0, 0, 0 };
    static cilist io___1745 = { 0, 16, 0, 0, 0 };
    static cilist io___1746 = { 0, 16, 0, 0, 0 };
    static cilist io___1747 = { 0, 16, 0, 0, 0 };
    static cilist io___1748 = { 0, 16, 0, 0, 0 };
    static cilist io___1749 = { 0, 6, 0, 0, 0 };
    static cilist io___1750 = { 0, 6, 0, 0, 0 };
    static cilist io___1751 = { 0, 6, 0, 0, 0 };
    static cilist io___1752 = { 0, 6, 0, 0, 0 };
    static cilist io___1753 = { 0, 6, 0, 0, 0 };
    static cilist io___1754 = { 0, 6, 0, 0, 0 };
    static cilist io___1765 = { 0, 16, 0, 0, 0 };
    static cilist io___1766 = { 0, 16, 0, 0, 0 };
    static cilist io___1767 = { 0, 16, 0, 0, 0 };
    static cilist io___1768 = { 0, 6, 0, 0, 0 };
    static cilist io___1769 = { 0, 6, 0, 0, 0 };
    static cilist io___1770 = { 0, 6, 0, 0, 0 };
    static cilist io___1771 = { 0, 6, 0, 0, 0 };
    static cilist io___1772 = { 0, 6, 0, 0, 0 };



/*     Urs Kradolfer, Nov. 1986 */


/* hypocenter-layer */
/* reflection at bottom of layer MLL */
/* dimension = max. number of laye */
/* auftauchwinkel in rad */
/* iterate until hypoc-adjustments are less than (TEST */
/* hypocenter-depth */
/* distance epicenter-receiver */

    /* Parameter adjustments */
    --thk;
    --vsq;
    --v;

    /* Function Body */
    *ierr = 0;
    *dtddrefl = 0.f;
    *dtdhrefl = 0.f;

    test4 = .01f;
/*  see HYMD01.DAT */
    i__1 = *nl;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vi[i__ - 1] = 1.f / v[i__];
    }

/* ---- determine, which layer contains hypocenter */
L10:
    sum = 0.f;
    i__1 = *nl;
    for (*jl = 1; *jl <= i__1; ++(*jl)) {
	sum += thk[*jl];
	if (*z__ <= sum) {
	    goto L19;
	}
    }
/* ---- hypocenter is in the halfspace: */
    *jl = *nl;
    *tkj = *z__ - sum;
    if (*jl == 0) {
	goto L10;
    }
    goto L20;
L19:
    *tkj = *z__ - sum + thk[*jl];
    goto L20;
L20:
/*     hypocenter is TKJ [km] below top of hypoc-layer */
/*     JL is the hypocenter layer */

    if (*jl > *mll) {
/*  hypocenter below reflector !!! */
	*ierr = -1;
	s_wsle(&io___1726);
	do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
	e_wsle();
	s_wsle(&io___1727);
	do_lio(&c__9, &c__1, "subr. REFLECT >>> hypocenter is below reflecto"
		"r!", (ftnlen)48);
	e_wsle();
	s_wsle(&io___1728);
	do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
	e_wsle();
	s_wsle(&io___1729);
	do_lio(&c__9, &c__1, "subr. REFLECT >>> hypocenter is below reflecto"
		"r!", (ftnlen)48);
	e_wsle();
/* cc         stop'subr. REFLECT >>> hypocenter below reflector!' */
    }
    if (*mll > *nl) {
	s_stop("subr. REFLECT >>> reflector-nr > number of layers !", (ftnlen)
		51);
    }


/*  CALCULATE REFLECTED WAVES */

    nit = 0;
    zbig = *tkj;
    sum = 0.f;
    i__1 = *mll;
    for (m = 1; m <= i__1; ++m) {
/* LAYER M IS PASSED ONLY ONCE: */
	fac = 1.f;
	if (*jl > m) {
	    goto L505;
	}
/* LAYER M IS PASSED TWICE */
	fac = 2.f;
	if (*jl < m) {
	    goto L505;
	}
/* LAYER M CONTAINS HYPOCENTER: */
	fac = (thk[m] * 2.f - zbig) / thk[m];
L505:
	div[m - 1] = fac * thk[m];
	vsqu[m - 1] = vsq[*mll] / vsq[m];
	sum += div[m - 1];
    }
/* ITERATE TO FIND EMERGING ANGLE FOR THE GIVEN DISTANCE: */
    a = atan2(*delta, sum);
L515:
    sina = sin(a);
    if (sina == 1.f) {
	sina = .9999999f;
    }
    sina2 = sina * sina;
    dellit = 0.f;
    dddas = 0.f;
    i__1 = *mll;
    for (m = 1; m <= i__1; ++m) {
	sqr = vsqu[m - 1] - sina2;

	if (sqr <= 0.f) {
	    s_wsle(&io___1742);
	    do_lio(&c__9, &c__1, "WARNING:                  subr. REFLECT", (
		    ftnlen)39);
	    e_wsle();
	    s_wsle(&io___1743);
	    do_lio(&c__9, &c__1, "probably a low velocity layer detected!", (
		    ftnlen)39);
	    e_wsle();
	    s_wsle(&io___1744);
	    do_lio(&c__9, &c__1, "sina=", (ftnlen)5);
	    do_lio(&c__4, &c__1, (char *)&sina, (ftnlen)sizeof(real));
	    e_wsle();
	    s_wsle(&io___1745);
	    do_lio(&c__9, &c__1, "sina2=", (ftnlen)6);
	    do_lio(&c__4, &c__1, (char *)&sina2, (ftnlen)sizeof(real));
	    e_wsle();
	    s_wsle(&io___1746);
	    do_lio(&c__9, &c__1, "VSQU(M):  vsqu(", (ftnlen)15);
	    do_lio(&c__3, &c__1, (char *)&m, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")=", (ftnlen)2);
	    do_lio(&c__4, &c__1, (char *)&vsqu[m - 1], (ftnlen)sizeof(real));
	    e_wsle();
	    s_wsle(&io___1747);
	    do_lio(&c__9, &c__1, "MLL=", (ftnlen)4);
	    do_lio(&c__3, &c__1, (char *)&(*mll), (ftnlen)sizeof(integer));
	    e_wsle();
	    s_wsle(&io___1748);
	    do_lio(&c__9, &c__1, "JL=", (ftnlen)3);
	    do_lio(&c__3, &c__1, (char *)&(*jl), (ftnlen)sizeof(integer));
	    e_wsle();
	    s_wsle(&io___1749);
	    do_lio(&c__9, &c__1, "sina=", (ftnlen)5);
	    do_lio(&c__4, &c__1, (char *)&sina, (ftnlen)sizeof(real));
	    e_wsle();
	    s_wsle(&io___1750);
	    do_lio(&c__9, &c__1, "sina2=", (ftnlen)6);
	    do_lio(&c__4, &c__1, (char *)&sina2, (ftnlen)sizeof(real));
	    e_wsle();
	    s_wsle(&io___1751);
	    do_lio(&c__9, &c__1, "VSQU(M):  vsqu(", (ftnlen)15);
	    do_lio(&c__3, &c__1, (char *)&m, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, ")=", (ftnlen)2);
	    do_lio(&c__4, &c__1, (char *)&vsqu[m - 1], (ftnlen)sizeof(real));
	    e_wsle();
	    s_wsle(&io___1752);
	    do_lio(&c__9, &c__1, "MLL=", (ftnlen)4);
	    do_lio(&c__3, &c__1, (char *)&(*mll), (ftnlen)sizeof(integer));
	    e_wsle();
	    s_wsle(&io___1753);
	    do_lio(&c__9, &c__1, "JL=", (ftnlen)3);
	    do_lio(&c__3, &c__1, (char *)&(*jl), (ftnlen)sizeof(integer));
	    e_wsle();
	    s_wsle(&io___1754);
	    e_wsle();
	}

/* !!!!!         if(sqr.le.0.) goto 530   !auftauchwinkel gefunden */
/*   sina2 is always < 1 ; */
/*   vsqu is always > 1 if no velocity-layers are above the event-layer !! */
	ddda = div[m - 1] / sqrt(sqr);
	dellit += ddda;
	dddas += vsqu[m - 1] * ddda / sqr;
    }
    dellit *= sina;
    dddas *= cos(a);
    da = dellit - *delta;
    da2 = da * da;
    if (da2 <= test4) {
	goto L530;
    }
    ++nit;
/* uk      IF(NIT.LT.15) GOTO 525 */
    if (nit < 50) {
	goto L525;
    }
/*      WRITE(6,524) delta */
/*  524 FORMAT(' REFLECTED WAVE DID NOT CONVERGE WITHIN', */
/*     1' 50 ITERATIONS AT DISTANCE:',F8.1, */
/*     2' SET WEIGHT TO 0') */
    goto L27;
L525:
    a -= da / dddas;
    if (a >= 1.570796f) {
	a = 1.5f;
    }
/* 1.5 ~ 86 deg ;   a = never .gt.  pi/2. */
    goto L515;
/* ---- successful iteration: */
L530:
    tt = 0.f;
    dtda = 0.f;
    i__1 = *mll;
    for (m = 1; m <= i__1; ++m) {
	ti = div[m - 1] * vi[m - 1] / sqrt(1.f - sina2 / vsqu[m - 1]);
	dti = ti / (vsqu[m - 1] - sina2);
	tt += ti;
	dtda += dti;
    }
    dtda = dtda * sina * cos(a);
    dtdd = dtda / dddas;
    dtdh = -(1.f - v[*jl] * sina * dtdd) / (v[*jl] * sqrt(1.f - sina2));
    anin = sina;
    goto L260;
/* ------- IF NOT POSSIBLE, SET P + S WEIGHTS TO ZERO */
L27:
    s_wsle(&io___1765);
    do_lio(&c__9, &c__1, "WARNING:", (ftnlen)8);
    e_wsle();
    s_wsle(&io___1766);
    do_lio(&c__9, &c__1, "Reflected wave did not converge within 50 iteratio"
	    "ns!", (ftnlen)53);
    e_wsle();
    s_wsle(&io___1767);
    do_lio(&c__9, &c__1, "---> trying another ray-type ...", (ftnlen)32);
    e_wsle();
    s_wsle(&io___1768);
    do_lio(&c__9, &c__1, "Reflected wave did not converge within 50 iteratio"
	    "ns!", (ftnlen)53);
    e_wsle();
    s_wsle(&io___1769);
    do_lio(&c__9, &c__1, "sina=", (ftnlen)5);
    do_lio(&c__4, &c__1, (char *)&sina, (ftnlen)sizeof(real));
    do_lio(&c__9, &c__1, "  delta=", (ftnlen)8);
    do_lio(&c__4, &c__1, (char *)&(*delta), (ftnlen)sizeof(real));
    e_wsle();
    s_wsle(&io___1770);
    do_lio(&c__9, &c__1, "da=", (ftnlen)3);
    do_lio(&c__4, &c__1, (char *)&da, (ftnlen)sizeof(real));
    do_lio(&c__9, &c__1, "  da2=", (ftnlen)6);
    do_lio(&c__4, &c__1, (char *)&da2, (ftnlen)sizeof(real));
    do_lio(&c__9, &c__1, "  test4=", (ftnlen)8);
    do_lio(&c__4, &c__1, (char *)&test4, (ftnlen)sizeof(real));
    e_wsle();
    s_wsle(&io___1771);
    do_lio(&c__9, &c__1, "---> trying another ray-type ...", (ftnlen)32);
    e_wsle();
    s_wsle(&io___1772);
    e_wsle();
    *ierr = 50;
    return 0;
/* c      stop'STOP in subr. REFLECT >>> nit > 50' */

L260:
/* ---- anin is emerging angle at reflector; find now takeoff-angle at source! */
    *ain = anin;
    if (*mll > *jl) {
	i__1 = *jl;
	for (i__ = *mll - 1; i__ >= i__1; --i__) {
	    *ain = *ain * v[i__] / v[i__ + 1];
	}
    }
    *trefl = tt;
    *dtddrefl = dtdd;
    *dtdhrefl = dtdh;
/* c     wain=57.29578*asin(ain) */
/* c      write(6,*)'takeoff angle = ',wain */
    return 0;

} /* reflect_ */


/* of subr. reflect */
/* Subroutine */ int reflectpath_(real *xe, real *ye, real *ze, real *xr, 
	real *yr, real *zr, real *delta, integer *nl, real *v, real *vsq, 
	real *thk, integer *jl, real *tkj, real *ain, integer *mll, real *rp, 
	integer *nrp, real *reflerr)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3;

    /* Builtin functions */
    double asin(doublereal), tan(doublereal), sqrt(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, m;
    static real d1, d2;
    static integer ld;
    static real tng, deljl, salpha;


/*     Urs Kradolfer, Nov. 1986 */

/*       reflectpath assigns raypoints with coordinates rp(1,i),rp(2,i), */
/*  rp(3,i) along a reflected seismic raypath in a flat layered earth. */

/*  input:  xe,ye,ze - event coordinates */
/*          xr,yr,zr - receiver coordinates */
/*             delta - horizontal distance between event and receiver */
/*                nl - total number of layers in model */
/*                     (used only to dimension v vsq and thk) */
/*              v(l) - velocity of layer l */
/*            vsq(l) = v(l) ** 2 */
/*            thk(l) - thickness of layer l */
/*                jl - event layer */
/*               tkj - depth of event from top of event layer */
/*               ain - sine of takeoff angle (with respect to downward vertical) */
/*               mll - reflector is bottom of layer MLL */

/*  output:  rp(1,2,or 3,i) - raypoint coordinates */
/*                      nrp - number of raypoints */

/* max. nr of raypoints =50 */




    /* Parameter adjustments */
    --thk;
    --vsq;
    --v;
    rp -= 4;

    /* Function Body */
    d1 = (*xr - *xe) / *delta;
    d2 = (*yr - *ye) / *delta;
    *nrp = *jl + 1 + (*mll - *jl << 1) + 1;

    salpha = *ain;

/*   assign raypoint coordinates */

    rp[4] = *xe;
    rp[5] = *ye;
    rp[6] = *ze;
/*      tng=tan(asin(salpha))  ! compiler produces warning with range checking */
    tng = asin(salpha);
    tng = tan(tng);
/* must be defined here; in case ld is zero */
    deljl = tng * (thk[*jl] - *tkj);
/* horiz. travel distance in ev.layer */
    rp[7] = rp[4] + deljl * d1;
    rp[8] = rp[5] + deljl * d2;
    rp[9] = rp[6] + (thk[*jl] - *tkj);
/* ---- now arrived at bottom of event-layer */
    m = *jl;
    ld = *mll - *jl;
/* nr of layer to go down to reflector */
    j = 2;
    i__1 = ld;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++j;
	m = *jl + i__;
/* Computing 2nd power */
	r__1 = salpha;
	tng = v[m] * salpha / sqrt(vsq[*jl] - vsq[m] * (r__1 * r__1));
	rp[j * 3 + 1] = rp[(j - 1) * 3 + 1] + thk[m] * tng * d1;
	rp[j * 3 + 2] = rp[(j - 1) * 3 + 2] + thk[m] * tng * d2;
	rp[j * 3 + 3] = rp[(j - 1) * 3 + 3] + thk[m];
/* ray is going downward */
    }
/* ---- now arrived down at reflector; going upward from now on */
    if (m != *mll) {
	s_stop("subr. REFLECTPATH >>> Error in ray-path...", (ftnlen)42);
    }
    ++j;
    deljl = tng * thk[m];
/* horiz. travel-distance in lowest layer */
    rp[j * 3 + 1] = rp[(j - 1) * 3 + 1] + deljl * d1;
    rp[j * 3 + 2] = rp[(j - 1) * 3 + 2] + deljl * d2;
    rp[j * 3 + 3] = rp[(j - 1) * 3 + 3] - thk[m];
/* ---- now arrived at top of lowest layer */
/* ---- going up to top of model: */
/*     do i=j+1,nrp-1   if one would raytrace only to the second-last point */
/* in order to calculate an error, we calculate up to the receiver: */
    i__1 = *nrp;
    for (i__ = j + 1; i__ <= i__1; ++i__) {
	--m;

/*   m is the number of the layer below ray point i */

/* Computing 2nd power */
	r__1 = salpha;
	tng = v[m] * salpha / sqrt(vsq[*jl] - vsq[m] * (r__1 * r__1));

/*   tng is the tangent of the angle of incidence in layer m */

	rp[i__ * 3 + 1] = rp[(i__ - 1) * 3 + 1] + thk[m] * tng * d1;
	rp[i__ * 3 + 2] = rp[(i__ - 1) * 3 + 2] + thk[m] * tng * d2;
	rp[i__ * 3 + 3] = rp[(i__ - 1) * 3 + 3] - thk[m];
    }

/* Computing 2nd power */
    r__1 = rp[*nrp * 3 + 1] - *xr;
/* Computing 2nd power */
    r__2 = rp[*nrp * 3 + 2] - *yr;
/* Computing 2nd power */
    r__3 = rp[*nrp * 3 + 3] - *zr;
    *reflerr = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3) * 1e3f;
/* c      write(6,*)'REFLECTPATH: raytracer-error was : ',reflerr,' meter' */
/* ---- now assign the correct receiver-coordinates to the last raypoint: */
    rp[*nrp * 3 + 1] = *xr;
    rp[*nrp * 3 + 2] = *yr;
    rp[*nrp * 3 + 3] = *zr;
    return 0;
} /* reflectpath_ */


/* of subr. reflectpath */
/* Subroutine */ int refract_(integer *nl, real *v, real *vsq, real *thk, 
	integer *jl, real *tkj, real *delta, integer *kk, real *tref, real *
	didjkk, real *xovmax)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer l, m, j1, m1, jx, lx;
    static real tr[100], did[100], tid[100], tim, sqt, didj[100], tinj[100];
    extern /* Subroutine */ int tiddid_(integer *, integer *, real *, real *, 
	    real *, real *, real *);


/*       for refracted rays in a layered earth model, refract */
/*  determines the fastest travel time, tref, the layer */
/*  in which the fastest ray is refracted, kk, the */
/*  critical distance for refraction in that layer, */
/*  didjkk, and an upper bound on delta for which a */
/*  direct ray can be a first arrival, xovmax.  refract */
/*  allows for the possibility of low velocity layers. */
/*       note that there may not be a refracted ray, either because */
/*  all layers below the event layer are low velocity layers or */
/*  because for all layers below the event layer which are not low */
/*  velocity layers the critical distance exceeds delta.  in such */
/*  cases tref, didjkk, and xovmax are set very large, kk is set to */
/*  zero, and refract returns to the calling program. */

/*  input:  nl - number of layers */
/*        v(l) - velocity of layer l */
/*      vsq(l) - v(l) ** 2 */
/*      thk(l) - thickness of layer l */
/*          jl - event layer */
/*         tkj - depth of event in event layer */
/*       delta - horizontal distance between event and receiver */

/*  output:   kk - refracting layer for fastest refracted ray */
/*          tref - travel time of fastest refracted ray */
/*        didjkk - critical distance for refraction in layer kk */
/*        xovmax - an upper bound on delta for which the direct ray can */
/*                       be the first arrival */
/*  internal arrays: */

/*       tr(m) - travel time for refraction in layer m */
/*     tinj(m) - traveltime intercept */
/*      tid(m) - terms in travel time intercept which are */
/*                     independent of tkj */
/*     didj(m) - critical distance */
/*      did(m) - terms in critical distance which are */
/*                     independent of tkj */


/*  call subr. tiddid to evaluate tid(m) and */
/*  did(m), the terms in the travel time intercept and */
/*  critical distance for a ray refracted in layer m */
/*  which are independent of tkj. */


/*  determine tref, kk, didjkk */


    /* Parameter adjustments */
    --thk;
    --vsq;
    --v;

    /* Function Body */
    tiddid_(jl, nl, &v[1], &vsq[1], &thk[1], tid, did);
    *tref = 1e5f;
    j1 = *jl + 1;
    i__1 = *nl;
    for (m = j1; m <= i__1; ++m) {
	if (! (tid[m - 1] == 1e5f)) {
	    goto L23153;
	}
	tr[m - 1] = 1e5f;
	goto L23154;
L23153:
	sqt = sqrt(vsq[m] - vsq[*jl]);
	tinj[m - 1] = tid[m - 1] - *tkj * sqt / (v[m] * v[*jl]);
	didj[m - 1] = did[m - 1] - *tkj * v[*jl] / sqt;
	tr[m - 1] = tinj[m - 1] + *delta / v[m];
	if (! (didj[m - 1] > *delta)) {
	    goto L23155;
	}
	tr[m - 1] = 1e5f;
L23155:
L23154:
	if (! (tr[m - 1] < *tref)) {
	    goto L23157;
	}
	*tref = tr[m - 1];
	*kk = m;
	*didjkk = didj[*kk - 1];
L23157:
/* L23151: */
	;
    }
/* L23152: */

/*   if there is no refracted ray: */

    if (! (*tref == 1e5f)) {
	goto L23159;
    }
    *didjkk = 1e5f;
    *xovmax = 1e5f;
    *kk = 0;
    return 0;
L23159:

/*   if there is a refracted ray, determine xovmax: */
/*   find lx, the 1st layer below the event layer which */
/*   is not a low velocity layer */

    m = *jl + 1;
L23161:
    if (! (tid[m - 1] == 1e5f)) {
	goto L23162;
    }
    ++m;
    goto L23161;
L23162:
    lx = m;

/*   check whether the event is in the 1st layer */

    if (! (*jl == 1)) {
	goto L23163;
    }
    *xovmax = tinj[lx - 1] * v[lx] * v[1] / (v[lx] - v[1]);
    return 0;
L23163:
    m = *jl;

/*   find jx, the 1st layer above and including the event */
/*   layer which is not a low velocity layer */

L23165:
    tid[m - 1] = 0.f;
    m1 = m - 1;
    i__1 = m1;
    for (l = 1; l <= i__1; ++l) {
	if (! (vsq[m] <= vsq[l])) {
	    goto L23170;
	}
	tid[m - 1] = 1e5f;
	goto L23171;
L23170:
	sqt = sqrt(vsq[m] - vsq[l]);
	tim = thk[l] * sqt / (v[l] * v[m]);
	tid[m - 1] += tim;
L23171:
/* L23168: */
	;
    }
/* L23169: */
    --m;

/*  decide whether or not jx=1 and calculate xovmax */

/* L23166: */
    if (! (tid[m] < 1e5f || m == 1)) {
	goto L23165;
    }
/* L23167: */
    if (! (tid[m] < 1e5f)) {
	goto L23172;
    }
    jx = m + 1;
    *xovmax = (tinj[lx - 1] - tid[jx - 1]) * v[lx] * v[jx] / (v[lx] - v[jx]);
    goto L23173;
L23172:

/*   jx=1 */

    *xovmax = tinj[lx - 1] * v[lx] * v[1] / (v[lx] - v[1]);
L23173:
    return 0;
} /* refract_ */


/* of subr. refract */
/* Subroutine */ int tiddid_(integer *jl, integer *nl, real *v, real *vsq, 
	real *thk, real *tid, real *did)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer l, m, j1, m1;
    static real tim, sqt, did1, did2, tid1, tid2, dimm;


/*       tiddid determines the travel time intercept and critical */
/*  distance for a seismic ray in a layered earth model */
/*  originating at the top of layer jl, refracting in */
/*  layer m, and terminating at the top of layer 1. */

/*  input:       jl - event layer */
/*               nl - number of layers */
/*             v(l) - velocity of layer l */
/*           vsq(l) - velocity squared */
/*           thk(l) - thickness of layer l */
/*  output: */
/*           tid(m) - travel time intercept for */
/*                      refraction in layer m */
/*           did(m) - critical distance */



    /* Parameter adjustments */
    --thk;
    --vsq;
    --v;
    --tid;
    --did;

    /* Function Body */
    j1 = *jl + 1;
    i__1 = *nl;
    for (m = j1; m <= i__1; ++m) {
	tid[m] = 0.f;
	did[m] = 0.f;
	tid1 = 0.f;
	tid2 = 0.f;
	did1 = 0.f;
	did2 = 0.f;
	m1 = m - 1;
	i__2 = m1;
	for (l = 1; l <= i__2; ++l) {
	    if (! (vsq[m] <= vsq[l])) {
		goto L23178;
	    }

/*   if m is a low velocity layer, set tid and did to */
/*   very large values */

	    tid[m] = 1e5f;
	    did[m] = 1e5f;
	    goto L23179;
L23178:
	    sqt = sqrt(vsq[m] - vsq[l]);
	    tim = thk[l] * sqt / (v[l] * v[m]);
	    dimm = thk[l] * v[l] / sqt;
	    if (! (l < *jl)) {
		goto L23180;
	    }

/*   sum for layers above event layer */

	    tid1 += tim;
	    did1 += dimm;
	    goto L23181;
L23180:

/*   sum for layers below and including the event layer */

	    tid2 += tim;
	    did2 += dimm;
L23181:
L23179:
/* L23176: */
	    ;
	}
/* L23177: */
	if (! (tid[m] != 1e5f)) {
	    goto L23182;
	}

/*   calculate tid and did if m is not a low velocity layer */

	tid[m] = tid1 + tid2 * 2;
	did[m] = did1 + did2 * 2;
L23182:
/* L23174: */
	;
    }
/* L23175: */
    return 0;
} /* tiddid_ */


/* of subr. tiddid */
/* Subroutine */ int refpath_(real *xe, real *ye, real *ze, real *xr, real *
	yr, real *zr, real *delta, integer *nl, real *v, real *vsq, real *thk,
	 real *tkj, integer *jl, integer *kk, real *didjkk, real *rp, integer 
	*nrp, real *refrerr)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, m;
    static real d1, d2, tng;
    static integer nrp1, nrpd, nrpd2;
    static real thkjl;


/*       refpath assigns raypaths with coordinates rp(1,i), rp(2,i), */
/*  rp(3,i) along a refracted seismic raypath in a flat layered earth. */

/*  input:  xe,ye,ze - event coordinates */
/*          xr,yr,zr - receiver coordinates */
/*             delta - horizontal distance between the event */
/*                          and the receiver */
/*                nl - total number of layers in model */
/*                     (used only to dimension v, vsq, and thk) */
/*              v(l) - velocity of layer l */
/*            vsq(l) = v(l) ** 2 */
/*            thk(l) - thickness of layer l */
/*                jl - event layer */
/*               tkj - depth of event from top of event layer */
/*                kk - refracting layer */
/*            didjkk - critical distance for the refracted ray */

/*  output:  rp(1,2,or 3,i) - raypoint coordinates */
/*                      nrp - number of raypoints */

/* ek max. nr of raypoints =50 */



    /* Parameter adjustments */
    --thk;
    --vsq;
    --v;
    rp -= 4;

    /* Function Body */
    thkjl = thk[*jl];

/*   d1 and d2 are the x and y directions of the raypath */

    d1 = (*xr - *xe) / *delta;
    d2 = (*yr - *ye) / *delta;
    nrpd = *kk - *jl + 1;

/*   nrpd= number of raypoints in down-going part of ray path */

    *nrp = nrpd + *kk;

/*   down-going part of path */

    thk[*jl] = thkjl - *tkj;
    rp[4] = *xe;
    rp[5] = *ye;
    rp[6] = *ze;
/*   m is the number of the layer above raypoint i */

    i__1 = nrpd;
    for (i__ = 2; i__ <= i__1; ++i__) {
	m = *jl + i__ - 2;

/*   tng is the tangent of the incident angle in layer m */

	tng = v[m] / sqrt(vsq[*kk] - vsq[m]);
	rp[i__ * 3 + 1] = rp[(i__ - 1) * 3 + 1] + thk[m] * tng * d1;
	rp[i__ * 3 + 2] = rp[(i__ - 1) * 3 + 2] + thk[m] * tng * d2;
	rp[i__ * 3 + 3] = rp[(i__ - 1) * 3 + 3] + thk[m];
/* L23204: */
    }
/* L23205: */

/*   up-going part of path */

    rp[(nrpd + 1) * 3 + 1] = rp[nrpd * 3 + 1] + (*delta - *didjkk) * d1;
    rp[(nrpd + 1) * 3 + 2] = rp[nrpd * 3 + 2] + (*delta - *didjkk) * d2;
    rp[(nrpd + 1) * 3 + 3] = rp[nrpd * 3 + 3];
    thk[*jl] = thkjl;
    nrp1 = *nrp - 1;

/*   nrpd2 is the number of the raypoint at the */
/*   top of layer (kk-1) */

    nrpd2 = nrpd + 2;
/* uk      do 23206i=nrpd2,nrp1 */
    i__1 = nrp1 + 1;
    for (i__ = nrpd2; i__ <= i__1; ++i__) {

/*   m is the number of the layer below raypoint i */

/* calculate up to the top, then compute e */
	m = *kk - 1 - (i__ - nrpd2);

/*   tng is the tangent of the incidence angle in layer m */

	tng = v[m] / sqrt(vsq[*kk] - vsq[m]);
	rp[i__ * 3 + 1] = rp[(i__ - 1) * 3 + 1] + thk[m] * tng * d1;
	rp[i__ * 3 + 2] = rp[(i__ - 1) * 3 + 2] + thk[m] * tng * d2;
	rp[i__ * 3 + 3] = rp[(i__ - 1) * 3 + 3] - thk[m];
/* L23206: */
    }

/* Computing 2nd power */
    r__1 = rp[*nrp * 3 + 1] - *xr;
/* Computing 2nd power */
    r__2 = rp[*nrp * 3 + 2] - *yr;
/* Computing 2nd power */
    r__3 = rp[*nrp * 3 + 3] - *zr;
    *refrerr = sqrt(r__1 * r__1 + r__2 * r__2 + r__3 * r__3) * 1e3f;
    rp[*nrp * 3 + 1] = *xr;
    rp[*nrp * 3 + 2] = *yr;
    rp[*nrp * 3 + 3] = *zr;
    return 0;
} /* refpath_ */


/* ek    end of vel_ray.f */

/* ek    begin of vel_tools.f */

/* of subr. refpath */
/* Subroutine */ int casefold_(char *cn, ftnlen cn_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, ilen, ival;
    extern integer trimlen_(char *, ftnlen);


/* Input : character-string of any length */
/* Output: same character-string, but all letters are CAPITAL now */
/*         (other characters are not changed) */

/*   --> this subr. needs the function TRIMLEN ! */

/* Call  : call CASEFOLD(charstring) */

/* Urs Kradolfer, 20. Feb. 1990 */
    ilen = trimlen_(cn, cn_len);
    i__1 = ilen;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ival = *(unsigned char *)&cn[i__ - 1];
	if (ival >= 97 && ival <= 122) {
	    *(unsigned char *)&cn[i__ - 1] = (char) (ival - 32);
	}
    }
    return 0;
} /* casefold_ */



/* of subr. casefold */
/* Subroutine */ int delaz_velest__(real *alat, real *alon, real *blat, real *
	blon, real *del, real *dist, real *az)
{
    /* Initialized data */

    static doublereal pi2 = 1.570796;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double tan(doublereal), atan(doublereal), sin(doublereal), cos(doublereal)
	    , acos(doublereal), atan2(doublereal, doublereal);

    /* Local variables */
    static doublereal den, azr, top, geoa, geob, acol, bcol, tana, tanb, flat,
	     delr, colat, alatr, blatr, alonr, blonr, cosdel, diflon, radius;


/*      computes distance and azimuth from a to b */
/*      a and b are in decimal degrees and n-e coordinates */
/*      del -- delta in degrees */
/*      dist -- distance in km */
/*      az -- azimuth from a to b clockwise from north in degrees */


/*  neu */

/* c      double precision pi2,rad,flat */
/*  neu */
/* c      data rad/1.745329d-02/   ! defined in subr. SETORG */
/* alt      data flat/.993231d0/ */
/* test      data flat/.99330647d0/ ! neu wie in setorg */
/* cc      call setorg(orlat,orlon)  ! is called separately !! */
    flat = origi_1.rlatc;
/* -----convert to radians */
/* !! from subr. SETORG */
    alatr = *alat * origi_1.rad;
    alonr = *alon * origi_1.rad;
    blatr = *blat * origi_1.rad;
    blonr = *blon * origi_1.rad;
/* -----convert latitudes to geocentric colatitudes */
    tana = flat * tan(alatr);
    geoa = atan(tana);
    acol = pi2 - geoa;
    tanb = flat * tan(blatr);
    geob = atan(tanb);
    bcol = pi2 - geob;
/* -----calculate delta */
    diflon = blonr - alonr;
    cosdel = sin(acol) * sin(bcol) * cos(diflon) + cos(acol) * cos(bcol);
    delr = acos(cosdel);
/* -----calculate azimuth from a to b */
    top = sin(diflon);
    den = sin(acol) / tan(bcol) - cos(diflon) * cos(acol);
    azr = atan2(top, den);
/* ----- convert to degrees */
    *del = delr / origi_1.rad;
    *az = azr / origi_1.rad;
    if (*az < 0.f) {
	*az += 360.f;
    }
/* -----compute distance in kilometers */
    colat = pi2 - (alatr + blatr) / 2.;
/* old      radius=6371.277d0* */
/* old     & (1.d0+(3.37853d-3)*((1.d0/3.d0)-((dcos(colat))**2))) */
/* Computing 2nd power */
    d__1 = cos(colat);
    radius = ((.33333333333333331 - d__1 * d__1) * .00335278 + 1.) * 6378.163;
/*  neu wie in setorg */
/* neu wie in */
    *dist = delr * radius;
    return 0;

/*  1/298.26 = 0.0033527795   =  flattening   ( WGS72 ) */

} /* delaz_velest__ */


/* of subr. delaz */
/* Subroutine */ int geoko_(real *x, real *y, real *xlat, real *xlon, integer 
	*i__)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int ebell_(real *, real *, real *, real *, real *)
	    , elleb_(real *, real *, real *, real *);
    static real seichmy;

/*                         ->         1 */
/*                         <-        -1 */

/* Conversion of Swiss-coordinates X,Y [km] to LAT,LON [deg]    i = +1 */
/* Conversion of LAT,LON [deg] to Swiss-coordinates X,Y [km]    i = -1 */

/* Urs Kradolfer, 24.3.87 */
    if (! (*i__ == 1 || *i__ == -1)) {
	s_stop("GEOKO>>> specify conversion !!!", (ftnlen)31);
    }

    if (*i__ == 1) {
	ebell_(x, y, xlon, xlat, &seichmy);
    }
    if (*i__ == -1) {
	elleb_(xlon, xlat, x, y);
    }

    return 0;
} /* geoko_ */


/* Subroutine */ int elleb_(real *l, real *b, real *x, real *y)
{
    /* Initialized data */

    static doublereal bb = 169028.66;
    static doublereal bl = 26782.5;

    static doublereal a, c__, d__[5], e[5], f[5];
    static integer i__;
    static doublereal p, q, iw[5], rw[5];


/*  SCHWEIZ. PROJEKTIONSSYSTEM  FORMELN VON H. ODERMATT */
/*  TRANSFORMATION ELLIPSOID - EBENE */
/*  L,B  UNTERSCHIEDE IN LAENGE UND BREITE ZU BERN (SEXAG.SEK.) */
/*  Y,X LANDESKOORDINATEN IN METER ( BERN 0/0) */
/*  MY  MERIDIANKONVERGENZ ( SEXAG. SEK.) */

    a = *l * 3600.f - bl;
    c__ = *b * 3600.f - bb;
    d__[0] = .68382546262761f;
    e[0] = .02363591607471;
    d__[1] = -3.91798328045e-8;
    e[1] = 0.f;
    d__[2] = 1.4965410352e-15;
    e[2] = 4.527219881e-17;
    d__[3] = -8.039471422e-23;
    e[3] = -3.8908112e-24;
    d__[4] = 7.002139e-30;
    e[4] = 2.34077e-31;
    f[0] = 45.15344386039;
    f[1] = 1.17912305209e-4;
    f[2] = 5.8474201864e-10;
    f[3] = 2.73386187e-15;
    f[4] = 1.4308547e-20;

    p = a * 30.91849390613f;
    q = c__ * f[4];
    i__ = 5;
L1:
    --i__;
    q = c__ * (q + f[i__ - 1]);
    if (i__ > 1) {
	goto L1;
    }

    rw[0] = q;
    iw[0] = p;
    for (i__ = 2; i__ <= 5; ++i__) {
	rw[i__ - 1] = q * rw[i__ - 2] - p * iw[i__ - 2];
	iw[i__ - 1] = p * rw[i__ - 2] + q * iw[i__ - 2];
/* L2: */
    }

    *y = d__[4] * rw[4];
    *x = d__[4] * iw[4];
    i__ = 5;
L3:
    --i__;
    *y += d__[i__ - 1] * rw[i__ - 1];
    *x += d__[i__ - 1] * iw[i__ - 1];
    if (i__ > 1) {
	goto L3;
    }
    *y = *y / 1e3f + 200.f;
/*  output in kilometers */
    *x = *x / 1e3f + 600.f;

    return 0;
} /* elleb_ */


/* of subr. ELLEB */
/* Subroutine */ int ebell_(real *yl, real *xb, real *l, real *b, real *my)
{
    static doublereal a[8], c__[8];
    static integer i__;
    static doublereal p, q, x, y, bb[8], db, dl, qz[8], rz[8];


/*  SCHWEIZ. PROJEKTIONSSYSTEM FORMELN VON H. ODERMATT */
/*  TRANSFORMATION EBENE ELLIPSOID */
/*  YL,XB LANDESKOORDINATEN IN METER (BERN 600/200) */
/*  L,B LAENGE UND BREITE  (GRAD) */
/*  MY MERIDIEANKONVERGENZ (SEXAG.SEK.) */

/* ccc      dimension A(8),BB(8),C(8),RZ(8),QZ(8) */
/* ccc      real P,Q,X,Y,DB,DL */

    x = *xb * 1e3f - 2e5f;
    y = *yl * 1e3f - 6e5f;

    a[0] = 1.4623614572021f;
    bb[0] = .034564252673326;
    a[1] = 1.225255821052e-7;
    bb[1] = 2.89600437564e-9;
    a[2] = 1.3687923002e-14;
    bb[2] = 4.65104603e-16;
    a[3] = 1.971224191e-21;
    bb[3] = 6.43850954e-23;
    a[4] = 2.97898051e-28;
    bb[4] = 9.600412e-30;
    a[5] = 4.650273e-35;
    bb[5] = 1.50512e-36;
/*     A(7)=7.48203D-42 */
    a[6] = 0.;
/*     BB(7)=2.422D-43 */
    bb[6] = 0.;
/*     A(8)=1.229D-48 */
    a[7] = 0.;
    c__[0] = .022146704979846;
    c__[1] = -1.28081525373e-9;
    c__[2] = 7.4775676024e-18;
    c__[3] = 4.691943327e-24;
    c__[4] = -3.6550101e-31;
    c__[5] = 3.71615e-39;
/*     C(7)= 1.6901D-45 */
    c__[6] = 0.;
/*     C(8)= 1.96D-52 */
    c__[7] = 0.;
    rz[0] = x;
    qz[0] = y;
/* uk      DO 1 I=2,8   !  sufficiant to loop until 6 only */
    for (i__ = 2; i__ <= 6; ++i__) {
/*  otherwise VAX has an overflow... */
	rz[i__ - 1] = x * rz[i__ - 2] - y * qz[i__ - 2];
	qz[i__ - 1] = y * rz[i__ - 2] + x * qz[i__ - 2];
/* L1: */
    }
    i__ = 8;
    q = a[i__ - 1] * rz[i__ - 1];
    p = a[i__ - 1] * qz[i__ - 1];
    *my = 0.f;
L2:
    --i__;
    q += a[i__ - 1] * rz[i__ - 1];
    p += a[i__ - 1] * qz[i__ - 1];
    *my += bb[i__ - 1] * qz[i__ - 1];
    if (i__ > 1) {
	goto L2;
    }
    dl = p * .032343101932327;
    db = q * c__[7];
    i__ = 8;
L3:
    --i__;
    db = q * (db + c__[i__ - 1]);
    if (i__ > 1) {
	goto L3;
    }

/* c      write(6,*)'vor L= und B= in subr. ebell!' */
    *l = (dl + 26782.5) / 3600.f;
    *b = (db + 169028.66) / 3600.f;
    return 0;
} /* ebell_ */


/* of subr. EBELL */
/* Subroutine */ int sdc_(real *x, real *y, real *xlat, real *xlon, integer *
	i__)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int dist_(real *, real *, real *, real *), 
	    redist_(real *, real *, real *, real *);


/*     SDC needs subroutines SETORG, DIST and REDIST */


/* 7. Jan. 1988 */



/* c      call setorg()  ! is called separately !! */

    if (! (*i__ == -1 || *i__ == 1)) {
	s_stop("SDC>>> specify conversion !!!", (ftnlen)29);
    }

    if (*i__ == 1) {
	redist_(x, y, xlat, xlon);
    }
    if (*i__ == -1) {
	dist_(xlat, xlon, x, y);
    }

    return 0;
} /* sdc_ */


/* of subr. SDC */
/* Subroutine */ int dist_(real *xlat, real *xlon, real *xkm, real *ykm)
{
    /* Builtin functions */
    double tan(doublereal), atan(doublereal), cos(doublereal);

    /* Local variables */
    static real q, yp, xx;
    static doublereal lat1, lat2, lat3;


/* 7. Jan. 1988 */


/*     conversion of latitude and longitude to kilometers relative */
/*     to center of coordinates */

    q = *xlat * 60 - geo_coorsystem__1.olat;
    yp = q + geo_coorsystem__1.olat;
    lat1 = atan(geo_coorsystem__1.rlatc * tan(geo_coorsystem__1.rad * yp / 
	    60.f));
    lat2 = atan(geo_coorsystem__1.rlatc * tan(geo_coorsystem__1.rad * 
	    geo_coorsystem__1.olat / 60.f));
    lat3 = (lat2 + lat1) / 2.f;
    xx = *xlon * 60 - geo_coorsystem__1.olon;
    q *= geo_coorsystem__1.aa;
    xx = xx * geo_coorsystem__1.bb * cos(lat3);
/* c** rotate coordinate system clockwise */
    yp = geo_coorsystem__1.cost * q - geo_coorsystem__1.sint * xx;
    xx = geo_coorsystem__1.cost * xx + geo_coorsystem__1.sint * q;
    q = yp;

    *xkm = xx;
    *ykm = q;

    return 0;
} /* dist_ */


/* of subr. dist */
/* Subroutine */ int redist_(real *xkm, real *ykm, real *xlat, real *xlon)
{
    /* Format strings */
    static char fmt_1000[] = "(/,2x,\002 SUBR. REDISt: AA=\002,f10.5,2x,\002"
	    "BB=\002,f10.5,2x,\002COS(LAT1)=\002,f10.7,5x,\002DIVISION BY ZER"
	    "O, RUN STOPS HERE\002,/)";

    /* Builtin functions */
    double tan(doublereal), atan(doublereal), cos(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static real p, q, x, y, yp, xx, yy, bcl, lat, lon;
    static doublereal lat1, lat2, lat3, clat1;

    /* Fortran I/O blocks */
    static cilist io___1883 = { 0, 6, 0, fmt_1000, 0 };


/*   by Edi */
/* CALCULATES DISTANCE BETWEEN TWO POINTS,  INPUT IN RECTANGULAR XY-COOR. */
/*   OUTPUT IN LATITUDE/LONGITUDE */

/*     CONVERSION OF  KILOMETERS TO LATITUDE AND LONGITUDE */

/* 7. Jan. 1988 */




/* neu */
    xx = *xkm;
    yy = *ykm;
/* *****	Following code is commented-out */
/* 	and replaced by correct code to undo rotation */
/* 	WLE 1/3/95 */
/*      rphi=0.0   ! 5.4.91 u.k. */
/* c */
/*      SINT=DSIN(RPHI*RAD) */
/*      COST=DCOS(RPHI*RAD) */
/*      TANT=DTAN(RPHI*RAD) */
/* C---- ROTATE COORDINATES CLOCKWISE BACK BY RPHI */
/*      IF(RPHI.LT.0.1) GOTO 120 */
/*      Y=YY*COST-XX*SINT */
/*      X=XX/SINT+Y*TANT */
/*      GOTO 130 */
/*  120 X=XX */
/*      Y=YY */
/* 	rotate coordinate system into original orientation */
    x = xx * geo_coorsystem__1.cost - yy * geo_coorsystem__1.sint;
    y = yy * geo_coorsystem__1.cost + xx * geo_coorsystem__1.sint;
/* 	WLE 1/3/95 */
/* L130: */
    if (dabs(geo_coorsystem__1.aa) < 1e-7f) {
	goto L900;
    }
    q = y / geo_coorsystem__1.aa;
    lat = (q + geo_coorsystem__1.olat) / 60.f;
    *xlat = q + geo_coorsystem__1.olat - lat * 60.f;
    yp = lat * 60.f + *xlat;
    lat1 = atan(geo_coorsystem__1.rlatc * tan(yp * geo_coorsystem__1.rad / 
	    60.f));
    lat2 = atan(geo_coorsystem__1.rlatc * tan(geo_coorsystem__1.olat * 
	    geo_coorsystem__1.rad / 60.f));
    lat3 = (lat1 + lat2) / 2.f;
    clat1 = cos(lat3);
    bcl = geo_coorsystem__1.bb * clat1;
    if (dabs(bcl) < 1e-6f) {
	goto L900;
    }
    p = x / (geo_coorsystem__1.bb * clat1);
    lon = (p + geo_coorsystem__1.olon) / 60.f;
    *xlon = p + geo_coorsystem__1.olon - lon * 60.f;
    *xlat = lat + *xlat / 60.f;
    *xlon = lon + *xlon / 60.f;
    return 0;
L900:
    s_wsfe(&io___1883);
    do_fio(&c__1, (char *)&geo_coorsystem__1.aa, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&geo_coorsystem__1.bb, (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&clat1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_stop("REDIST>>> division by zero!!", (ftnlen)28);
    return 0;
} /* redist_ */


/* of subr. redist */
/* Subroutine */ int setorg_(real *orlat, real *orlon, real *rrotate, integer 
	*ifil)
{
    /* Format strings */
    static char fmt_4[] = "(10x,\002Short distance conversions:\002,/,10x"
	    ",\002one min lat ~ \002,f7.4,\002 km \002,/,10x,\002one min lon "
	    "~ \002,f7.4,\002 km \002,/)";

    /* System generated locals */
    real r__1, r__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sin(doublereal), tan(doublereal);
    integer s_wsle(cilist *), e_wsle(void), do_lio(integer *, integer *, char 
	    *, ftnlen), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe(void);
    double atan(doublereal), cos(doublereal), acos(doublereal);

    /* Local variables */
    static doublereal r__, phi, lat1, lat2, dela, delb, beta;

    /* Fortran I/O blocks */
    static cilist io___1886 = { 0, 0, 0, 0, 0 };
    static cilist io___1887 = { 0, 0, 0, 0, 0 };
    static cilist io___1888 = { 0, 0, 0, 0, 0 };
    static cilist io___1889 = { 0, 0, 0, 0, 0 };
    static cilist io___1890 = { 0, 0, 0, 0, 0 };
    static cilist io___1891 = { 0, 0, 0, "(' Radius at equator (REARTH)= ',f"
	    "10.5,                          '  km')", 0 };
    static cilist io___1892 = { 0, 0, 0, "('   1. / (ellipticity)      = ',f"
	    "10.3)", 0 };
    static cilist io___1893 = { 0, 0, 0, 0, 0 };
    static cilist io___1894 = { 0, 0, 0, 0, 0 };
    static cilist io___1895 = { 0, 0, 0, 0, 0 };
    static cilist io___1896 = { 0, 0, 0, "(1x,f12.7,' N',5x,f12.7,' W')", 0 };
    static cilist io___1897 = { 0, 0, 0, 0, 0 };
    static cilist io___1898 = { 0, 0, 0, 0, 0 };
    static cilist io___1899 = { 0, 0, 0, "('North  rotate= ',f6.1)", 0 };
    static cilist io___1900 = { 0, 0, 0, 0, 0 };
    static cilist io___1906 = { 0, 0, 0, "(' Radius of sphere at OLAT = ',f1"
	    "0.3,' km')", 0 };
    static cilist io___1907 = { 0, 0, 0, 0, 0 };
    static cilist io___1908 = { 0, 0, 0, 0, 0 };
    static cilist io___1909 = { 0, 0, 0, 0, 0 };
    static cilist io___1910 = { 0, 0, 0, "(1x,'RLATC = ',f12.8)", 0 };
    static cilist io___1911 = { 0, 0, 0, 0, 0 };
    static cilist io___1912 = { 0, 0, 0, fmt_4, 0 };
    static cilist io___1913 = { 0, 0, 0, 0, 0 };
    static cilist io___1914 = { 0, 0, 0, 0, 0 };







/*     O(r)LAT & O(r)LON : origin of cartesian coordinate system */
/*      north  w e s t */


/* EK Dez94      rotate=0.0  !...... */

    geo_coorsystem__1.rotate = *rrotate;
/* EK */
    if (*orlat == 0.f && *orlon == 0.f) {
	geo_coorsystem__1.olat = 46.9524f;
/* BERN North */
	geo_coorsystem__1.olon = -7.439583f;
/* BERN West */
    } else {
	geo_coorsystem__1.olat = *orlat;
	geo_coorsystem__1.olon = *orlon;
    }

    geo_coorsystem__1.olat *= 60.f;
/* minutes N */
    geo_coorsystem__1.olon *= 60.f;

/* minutes W */
    geo_coorsystem__1.rad = .017453292;

/*  OLD ELLIPSOID: */
/*      rlatc = 0.99330647d0 */
/*      data rearth /6378.163d0/, ellip /298.26d0/ */

/*  NEW ELLIPSOID FOR WHOLE EARTH:   WGS72 == WORLD GEODETIC SYSTEM 1972 */

/*  ALSO SET RLATC ACCORDING TO ORIGIN */

    geo_coorsystem__1.rearth = 6378.135;
    geo_coorsystem__1.ellip = 298.26f;

/* rlatc = tan(geocentric LAT) / TAN(GEOGRAPHIC LAT) */


/* CALCULATE RLATC:  CONVERSION FROM GEOGRAPHICAL LAT TO GEOCENTRICAL LAT */

/* (flattening) */
    phi = geo_coorsystem__1.olat * geo_coorsystem__1.rad / 60.f;
/*  phi=geogr. lat */
    beta = phi - sin(phi * 2.f) / geo_coorsystem__1.ellip;
/*  beta=geoc. lat */
    geo_coorsystem__1.rlatc = tan(beta) / tan(phi);


/* WRITE ELLIPSOIDE CONSTANTS */

    if (*ifil > 0) {
	io___1886.ciunit = *ifil;
	s_wsle(&io___1886);
	e_wsle();
	io___1887.ciunit = *ifil;
	s_wsle(&io___1887);
	e_wsle();
	io___1888.ciunit = *ifil;
	s_wsle(&io___1888);
	do_lio(&c__9, &c__1, "SHORT DISTANCE CONVERSION on ELLIPSOIDE of WOR"
		"LD GEODETIC SYSTEM 1972 (WGS72)", (ftnlen)77);
	e_wsle();
	io___1889.ciunit = *ifil;
	s_wsle(&io___1889);
	do_lio(&c__9, &c__1, "=============================================="
		"===============================", (ftnlen)77);
	e_wsle();
	io___1890.ciunit = *ifil;
	s_wsle(&io___1890);
	e_wsle();
	io___1891.ciunit = *ifil;
	s_wsfe(&io___1891);
	do_fio(&c__1, (char *)&geo_coorsystem__1.rearth, (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	io___1892.ciunit = *ifil;
	s_wsfe(&io___1892);
	do_fio(&c__1, (char *)&geo_coorsystem__1.ellip, (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	io___1893.ciunit = *ifil;
	s_wsle(&io___1893);
	e_wsle();
	io___1894.ciunit = *ifil;
	s_wsle(&io___1894);
	do_lio(&c__9, &c__1, "Origin of cartesian coordinates [degrees]:", (
		ftnlen)42);
	e_wsle();
	if (*orlat == 0.f && *orlon == 0.f) {
	    io___1895.ciunit = *ifil;
	    s_wsle(&io___1895);
	    do_lio(&c__9, &c__1, " (Origin = city of BERNE, Switzerland)", (
		    ftnlen)38);
	    e_wsle();
	}
	io___1896.ciunit = *ifil;
	s_wsfe(&io___1896);
	r__1 = geo_coorsystem__1.olat / 60.f;
	do_fio(&c__1, (char *)&r__1, (ftnlen)sizeof(real));
	r__2 = geo_coorsystem__1.olon / 60.f;
	do_fio(&c__1, (char *)&r__2, (ftnlen)sizeof(real));
	e_wsfe();
	io___1897.ciunit = *ifil;
	s_wsle(&io___1897);
	e_wsle();
	io___1898.ciunit = *ifil;
	s_wsle(&io___1898);
	do_lio(&c__9, &c__1, " Rotation angle (in degr.) clockwise from", (
		ftnlen)41);
	e_wsle();
	io___1899.ciunit = *ifil;
	s_wsfe(&io___1899);
	do_fio(&c__1, (char *)&geo_coorsystem__1.rotate, (ftnlen)sizeof(real))
		;
	e_wsfe();
	io___1900.ciunit = *ifil;
	s_wsle(&io___1900);
	e_wsle();
    }

/*   calculate aa &  bb */
/*   length of one minute of lat and lon in km */

    lat1 = atan(geo_coorsystem__1.rlatc * tan(geo_coorsystem__1.olat * 
	    geo_coorsystem__1.rad / 60.f));
/* geoc. lat for OLAT */
    lat2 = atan(geo_coorsystem__1.rlatc * tan((geo_coorsystem__1.olat + 1.f) *
	     geo_coorsystem__1.rad / 60.f));
/* geoc. lat for (OLAT+ */
    dela = lat2 - lat1;
/* Computing 2nd power */
    d__1 = sin(lat1);
    r__ = geo_coorsystem__1.rearth * (1.f - d__1 * d__1 / 
	    geo_coorsystem__1.ellip);
/* kugelradius fuer lat */
    geo_coorsystem__1.aa = r__ * dela;
/* aa = 1 min geogr. lat */
/* Computing 2nd power */
    d__1 = sin(lat1);
/* Computing 2nd power */
    d__2 = cos(lat1);
    delb = acos(d__1 * d__1 + cos(geo_coorsystem__1.rad / 60.f) * (d__2 * 
	    d__2));
    geo_coorsystem__1.bc = r__ * delb;
/* bc = 1 min geogr. lon */
    geo_coorsystem__1.bb = r__ * delb / cos(lat1);
    if (*ifil > 0) {
	io___1906.ciunit = *ifil;
	s_wsfe(&io___1906);
	do_fio(&c__1, (char *)&r__, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___1907.ciunit = *ifil;
	s_wsle(&io___1907);
	e_wsle();
	io___1908.ciunit = *ifil;
	s_wsle(&io___1908);
	do_lio(&c__9, &c__1, "Conversion of GEOGRAPHICAL LATITUDE to GEOCENT"
		"RICAL LATITUDE:", (ftnlen)61);
	e_wsle();
	io___1909.ciunit = *ifil;
	s_wsle(&io___1909);
	do_lio(&c__9, &c__1, "RLATC = TAN(GEOCENTR.LAT) / TAN(GEOGRAPH.LAT)", 
		(ftnlen)45);
	e_wsle();
	io___1910.ciunit = *ifil;
	s_wsfe(&io___1910);
	do_fio(&c__1, (char *)&geo_coorsystem__1.rlatc, (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	io___1911.ciunit = *ifil;
	s_wsle(&io___1911);
	e_wsle();
	io___1912.ciunit = *ifil;
	s_wsfe(&io___1912);
	do_fio(&c__1, (char *)&geo_coorsystem__1.aa, (ftnlen)sizeof(real));
	do_fio(&c__1, (char *)&geo_coorsystem__1.bc, (ftnlen)sizeof(real));
	e_wsfe();
	io___1913.ciunit = *ifil;
	s_wsle(&io___1913);
	e_wsle();
	io___1914.ciunit = *ifil;
	s_wsle(&io___1914);
	e_wsle();
    }

/* ***  convert coordinates with rotation cosines */
    geo_coorsystem__1.sint = sin(geo_coorsystem__1.rotate * 
	    geo_coorsystem__1.rad);
    geo_coorsystem__1.cost = cos(geo_coorsystem__1.rotate * 
	    geo_coorsystem__1.rad);
/* L31: */

    return 0;
} /* setorg_ */


/* of subr. setorg */
/* Subroutine */ int timeclear_(integer *iyr, integer *imo, integer *iday, 
	integer *ihr, integer *imin, real *sec, integer *itime)
{
    static real sec1;
    static integer iyr1;
    extern /* Subroutine */ int datum_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern integer juliam_(integer *, integer *, integer *, integer *, 
	    integer *);


/*     Urs Kradolfer, Winter 1987/88 */



    if (*iyr < 1900) {
	iyr1 = *iyr + 1900;
    } else {
	iyr1 = *iyr;
    }
    *itime = juliam_(&iyr1, imo, iday, ihr, imin);
L1:
    sec1 = *sec;
    if (*sec < 0.f) {
	*sec = sec1 + 60.f;
	--(*itime);
    }
    if (*sec > 60.f) {
	*sec = sec1 - 60.f;
	++(*itime);
    }
    if (*sec < 0.f || *sec > 60.f) {
	goto L1;
    }
    datum_(itime, &iyr1, imo, iday, ihr, imin);
    if (*iyr < 1900) {
	*iyr = iyr1 - 1900;
/* if input-year was of form  87  give it out s */
    } else {
	*iyr = iyr1;
    }

    return 0;

} /* timeclear_ */


/* of subr. timeclear */
integer juliam_(integer *iyr, integer *imo, integer *idy, integer *ihr, 
	integer *imn)
{
    /* Initialized data */

    static integer kmo[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
    static integer leap = 1;

    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer l, kd, kl, km, ky, ky0, ky1, ky4;

/* UMRECHNEN VON JAHR-MONAT-TAG-STUNDEN-MINUTEN IN MINUTEN: */
/*   (WENN IMN 4-BYTE INTEGER, DANN JAHR < 4000) */
    ky = *iyr;
    km = *imo;
    kd = *idy;
    if (km <= 0) {
	km = 1;
    }
/* L10: */
    ret_val = ky * 365;
    kd = kmo[km - 1] + kd;
    ky4 = ky / 4;
    ky1 = ky / 100;
    ky0 = ky / 1000;
    kl = leap * (ky4 - ky1 + ky0);
    l = 0;
    if (ky4 << 2 == ky && (ky1 * 100 != ky || ky0 * 1000 == ky)) {
	l = leap;
    }
    if (l != 0 && km < 3) {
	kl -= leap;
    }
    ret_val = ret_val + kd + kl;
    ret_val = ret_val * 24 + *ihr;
    ret_val = ret_val * 60 + *imn;
    return ret_val;
} /* juliam_ */


/* of integer function juliam */
/* Subroutine */ int datum_(integer *itf, integer *iyr, integer *imo, integer 
	*idy, integer *ihr, integer *imn)
{
    /* Initialized data */

    static integer kmo[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    static integer i__, k, l, id, ld, kh, iyr4, iyrh, iyrt;

/* UMRECHNEN DES DATUMS IN MINUTEN (CF. JULIAM) IN YR-MO-DY-HR-MI */
/*   (MIT IMN<2**31, JAHR < 4000 */


    k = *itf / 60;
    *imn = *itf - k * 60;
    kh = k / 24;
    *ihr = k - kh * 24;
    *iyr = kh / 365;
L5:
    id = kh - *iyr * 365;
    l = 0;
    iyr4 = *iyr / 4;
    iyrh = *iyr / 100;
    iyrt = *iyr / 1000;
    ld = iyr4 - iyrh + iyrt;
    if (iyr4 << 2 == *iyr && (iyrh * 100 != *iyr || iyrt * 1000 == *iyr)) {
	l = 1;
    }
    id = id - ld + l;
    if (id > 0) {
	goto L10;
    }
    if (id == 0 && *ihr == 0 && *imn == 0) {
	*idy = 0;
	*imo = 0;
	return 0;
    }
    --(*iyr);
    goto L5;
L10:
    kmo[1] = l + 28;
    for (i__ = 1; i__ <= 12; ++i__) {
	id -= kmo[i__ - 1];
	if (id <= 0) {
	    goto L30;
	}
/* L20: */
    }
    i__ = 12;
L30:
    *idy = id + kmo[i__ - 1];
    *imo = i__;
    return 0;
} /* datum_ */


/* of subr. datum */
integer trimlen_(char *t, ftnlen t_len)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer i_len(char *, ftnlen);


/*     Call:    nc=TRIMLEN(char) */

/*          --> nc says, how many characters the input-string has */
/*              (ignoring trailing blanks!). */

/* Urs Kradolfer, June 1986 */
    for (ret_val = i_len(t, t_len); ret_val >= 1; --ret_val) {
/* L1: */
	if (*(unsigned char *)&t[ret_val - 1] != ' ') {
	    return ret_val;
	}
    }
    ret_val = 1;
    return ret_val;
} /* trimlen_ */


/* of integer function trimlen */
/* Subroutine */ int freeunit_(integer *iunit)
{
    /* System generated locals */
    inlist ioin__1;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_inqu(inlist *);

    /* Local variables */
    static logical lopen;


/*     Purpose: Get a free FORTRAN-unit */

/*     Output: iunit  a free (file-)unit number */

/*     Urs Kradolfer, 16.7.90 */


    for (*iunit = 10; *iunit <= 999; ++(*iunit)) {
	if (*iunit == 999) {
	    s_stop("FREEUNIT>>> no free unit found!", (ftnlen)31);
	}
	ioin__1.inerr = 0;
	ioin__1.inunit = *iunit;
	ioin__1.infile = 0;
	ioin__1.inex = 0;
	ioin__1.inopen = &lopen;
	ioin__1.innum = 0;
	ioin__1.innamed = 0;
	ioin__1.inname = 0;
	ioin__1.inacc = 0;
	ioin__1.inseq = 0;
	ioin__1.indir = 0;
	ioin__1.infmt = 0;
	ioin__1.inform = 0;
	ioin__1.inunf = 0;
	ioin__1.inrecl = 0;
	ioin__1.innrec = 0;
	ioin__1.inblank = 0;
	f_inqu(&ioin__1);
	if (! lopen) {
	    return 0;
	}
    }

    return 0;

} /* freeunit_ */


/* ek    end of vel_tools.f */

/* ek    begin of vel_topo.f */

/* of subr. freeunit */
/* Subroutine */ int chtop_(real *xx, real *yy, real *zk, char *topo1file, 
	char *topo2file, ftnlen topo1file_len, ftnlen topo2file_len)
{
/* EK */
/*     this routine for a given pair of coordinates (xx,yy) provides */
/*     the elevation (zk in km) by reading it off from topo-arrays */
/* EK */
/*     If necessary, replace it with appropriate routine and */
/*     topo information */

/*  Dummy routine */


    *zk = 0.f;
    return 0;
} /* chtop_ */


/* Subroutine */ int region_(integer *ityp, real *x, real *y, char *cname, 
	integer *nreg, char *regnamfile, char *regkoordfile, ftnlen cname_len,
	 ftnlen regnamfile_len, ftnlen regkoordfile_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer iregread;
    extern /* Subroutine */ int regworld_(integer *, real *, real *, char *, 
	    integer *, ftnlen);
    static integer iii;
    static real xlat, xlon;
    static char place[32];
    extern /* Subroutine */ int regch_(real *, real *, char *, integer *, 
	    ftnlen), geoko_(real *, real *, real *, real *, integer *), 
	    regread_(char *, char *, ftnlen, ftnlen);


/*     originally from Manfred Baer */

/*     modified 6.7.87, 28.6.91 Urs Kradolfer */

/* Urs Kradolfer, 6.7.8 */



    if (iregread == 0) {
	regread_(regnamfile, regkoordfile, regnamfile_len, regkoordfile_len);
	iregread = 1;
    }

    *nreg = 0;

    if (*ityp == 1) {
	goto L1;
    }
    if (*ityp == 2 || *ityp == 3) {
	goto L2;
    }
    s_stop("REGION>>> illegal coordinate-type!", (ftnlen)34);
L1:
    s_copy(place, " ", (ftnlen)32, (ftnlen)1);
    regch_(x, y, place, nreg, (ftnlen)32);
    if (*nreg == 0) {
	geoko_(x, y, &xlat, &xlon, &c__1);
	goto L22;
    } else {
	s_copy(cname, place, (ftnlen)32, (ftnlen)32);
    }
    goto L999;

L2:
    xlat = *x;
    xlon = *y;
L22:
    s_copy(place, " ", (ftnlen)32, (ftnlen)1);
/*     call REGNU(0,xlat,xlon,GELAT,GELON,PLACE,NREG) */
    if (*ityp == 1) {
	iii = 0;
    }
    if (*ityp == 2) {
	iii = 0;
    }
    if (*ityp == 3) {
	iii = 1;
    }
    regworld_(&iii, &xlat, &xlon, place, nreg, (ftnlen)32);
    if (s_cmp(place, " ", (ftnlen)32, (ftnlen)1) == 0) {
	s_copy(cname, "*****", (ftnlen)32, (ftnlen)5);
    } else {
	s_copy(cname, place, (ftnlen)32, (ftnlen)32);
    }
    goto L999;

L999:
    return 0;
} /* region_ */


/* of subr. region */
/* Subroutine */ int regread_(char *regnamfile, char *regkoordfile, ftnlen 
	regnamfile_len, ftnlen regkoordfile_len)
{
    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void), s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer f_clos(cllist *);

    /* Local variables */
    extern /* Subroutine */ int freeunit_(integer *);
    static integer i__, j, k, nc, nr, iu1, iu2, nstart;
    static char cregion[40];
    extern integer trimlen_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___1946 = { 0, 0, 0, "(i5,2x,a)", 0 };
    static cilist io___1949 = { 0, 6, 0, "('sequence error at:',i5,a,i5)", 0 }
	    ;
    static cilist io___1951 = { 0, 0, 0, "(i5,2x,a)", 0 };
    static cilist io___1953 = { 0, 6, 0, "('sequence error at:',i5,a,i5)", 0 }
	    ;
    static cilist io___1954 = { 0, 0, 0, "(i5,2x,a)", 0 };
    static cilist io___1955 = { 0, 6, 0, "('sequence error at:',i5,a,i5)", 0 }
	    ;
    static cilist io___1958 = { 0, 0, 0, "(8f9.3)", 0 };



/* u      character*64 inputfile */

/* u      inputfile='/users/kradi/velest/regionsnamen.dat' */
    freeunit_(&iu1);
/* VMS      open(iu1,file=regnamfile,status='OLD',readonly) */
    o__1.oerr = 0;
    o__1.ounit = iu1;
    o__1.ofnmlen = regnamfile_len;
    o__1.ofnm = regnamfile;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    nstart = 0;
    for (i__ = 1; i__ <= 729; ++i__) {
	regioncom_1.indfe[i__ - 1] = nstart;
	io___1946.ciunit = iu1;
	s_rsfe(&io___1946);
	do_fio(&c__1, (char *)&nr, (ftnlen)sizeof(integer));
	do_fio(&c__1, cregion, (ftnlen)40);
	e_rsfe();
	if (nr != i__) {
	    s_wsfe(&io___1949);
	    do_fio(&c__1, (char *)&nr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, cregion, (ftnlen)40);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_stop("REGREAD>>> error reading file REGIONSNAMEN.DAT", (ftnlen)
		    46);
	}
	nc = trimlen_(cregion, (ftnlen)40);
	i__1 = nstart;
	s_copy(regioncom_1.irname + i__1, cregion, nstart + nc - i__1, nc);
	nstart += nc;
    }
    regioncom_1.indfe[729] = nstart;
    for (i__ = 1; i__ <= 420; ++i__) {
	regioncom_1.lt25[i__ - 1] = nstart;
	io___1951.ciunit = iu1;
	s_rsfe(&io___1951);
	do_fio(&c__1, (char *)&nr, (ftnlen)sizeof(integer));
	do_fio(&c__1, cregion, (ftnlen)40);
	e_rsfe();
	if (i__ <= 400) {
	    k = i__ + 999;
	} else {
	    k = (i__ - 401) * 20 + 1019;
	}
	if (k != nr) {
	    s_wsfe(&io___1953);
	    do_fio(&c__1, (char *)&nr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, cregion, (ftnlen)40);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_stop("REGREAD>>> error reading file REGIONSNAMEN.DAT", (ftnlen)
		    46);
	}
	nc = trimlen_(cregion, (ftnlen)40);
	i__1 = nstart;
	s_copy(regioncom_1.irname + i__1, cregion, nstart + nc - i__1, nc);
	nstart += nc;
    }
    regioncom_1.lt25[420] = nstart;
    for (i__ = 1; i__ <= 110; ++i__) {
	regioncom_1.lt50[i__ - 1] = nstart;
	io___1954.ciunit = iu1;
	s_rsfe(&io___1954);
	do_fio(&c__1, (char *)&nr, (ftnlen)sizeof(integer));
	do_fio(&c__1, cregion, (ftnlen)40);
	e_rsfe();
	if (i__ <= 100) {
	    k = i__ + 199;
	} else {
	    k = (i__ - 101) * 10 + 209;
	}
	if (k != nr) {
	    s_wsfe(&io___1955);
	    do_fio(&c__1, (char *)&nr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, cregion, (ftnlen)40);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_stop("REGREAD>>> error reading file REGIONSNAMEN.DAT", (ftnlen)
		    46);
	}
	nc = trimlen_(cregion, (ftnlen)40);
	i__1 = nstart;
	s_copy(regioncom_1.irname + i__1, cregion, nstart + nc - i__1, nc);
	nstart += nc;
    }
    regioncom_1.lt50[110] = nstart;
    cl__1.cerr = 0;
    cl__1.cunit = iu1;
    cl__1.csta = 0;
    f_clos(&cl__1);
/*      write(6,'(''anzahl worte fuer regions namen:'',i6)') nstart */
/*  jetzt: flinn-engdahl-regionen */
/* u      inputfile='/users/kradi/velest/regionskoord.dat' */
    freeunit_(&iu2);
/* VMS      open(iu2,file=regkoordfile,status='OLD',readonly) */
    o__1.oerr = 0;
    o__1.ounit = iu2;
    o__1.ofnmlen = regkoordfile_len;
    o__1.ofnm = regkoordfile;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    for (j = 1; j <= 14400; j += 8) {
	io___1958.ciunit = iu2;
	s_rsfe(&io___1958);
	i__1 = j + 7;
	for (i__ = j; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&regioncom_1.xnrlon[i__ - 1], (ftnlen)
		    sizeof(real));
	}
	e_rsfe();
    }
    cl__1.cerr = 0;
    cl__1.cunit = iu2;
    cl__1.csta = 0;
    f_clos(&cl__1);

    return 0;
} /* regread_ */


/* of subr. regread */
/* Subroutine */ int regch_(real *x, real *y, char *place, integer *nreg, 
	ftnlen place_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i1, i2;
    static real dx, dy;
    static integer nx, ny;
    static real xx, yy;
    static integer nrpu;


    *nreg = 0;
    if (*x < 480.f) {
	return 0;
    }
    if (*x >= 865.f) {
	return 0;
    }
    if (*y <= 62.f) {
	return 0;
    }
    if (*y > 302.f) {
	return 0;
    }
    dx = 17.5f;
    dy = 12.f;
    xx = *x - 480.f;
    yy = 302.f - *y;
    nx = xx / dx;
    ny = yy / dy;
    nrpu = ny * 20 + nx;
    *nreg = nrpu;
    if (nx >= 20) {
	nrpu = ny + 400;
	*nreg = ny * 20 + 19;
    }
    i1 = regioncom_1.lt25[nrpu] + 1;
    i2 = regioncom_1.lt25[nrpu + 1];
    *nreg += 1000;
    s_copy(place, regioncom_1.irname + (i1 - 1), (ftnlen)32, i2 - (i1 - 1));
    return 0;
} /* regch_ */


/* of subr. regch */
/* Subroutine */ int regworld_(integer *ityp, real *cord1, real *cord2, char *
	place, integer *nreg, ftnlen place_len)
{
    /* Initialized data */

    static real galat = 46.7706f;
    static real galon = 8.09428f;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), asin(doublereal), acos(
	    doublereal), r_sign(real *, real *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static real q;
    static integer i1, i2;
    static real ac, as;
    static integer in;
    static real pi, ck1, ck2, pi2, buf[40];
    static integer nlo, iuk;
    static real xdr;
    static integer num;
    static real alon;
    static integer nval, last;
    static real xreg, xlat, xlon, xazr, gelac, galar, gelat, pirad, galor, 
	    gelon;
    static integer latin;
    static real gelor, xlatr;
    static integer mhemis;

/*     PROGRAM TO COMPUTE REGION NUMBER AND NAME BASED ON THE INPUT */
/*        ITYP <=0         LATITUDE&LONGITUDE */
/*        ITYP > 0         DISTANCE & AZIMUTH */
/*    THE REGION NAMES ARE FROM FLINN & ENGDAHL#S TABLES */

    pi = 3.141593f;
    pirad = pi / 180.f;
    pi2 = pi * 2.f;
    last = 89;

/*     CONVERT ARRAY COORDINATES TO RADIANS */
    galor = galon * pirad;
    galar = galat * pirad;
    if (*ityp <= 0) {
	goto L850;
    } else {
	goto L860;
    }

L850:
    gelat = *cord1;
    gelon = *cord2;
    num = 1;
    goto L212;

L860:
    xazr = *cord2 * pirad;
    xdr = *cord1 * pirad;
    num = 1;

    q = sin(galar) * cos(xdr) + cos(galar) * sin(xdr) * cos(xazr);
    if (dabs(q) > 1.f) {
	goto L891;
    }
    as = asin(q);
    goto L890;

L891:
    gelon = 0.f;
    gelat = 0.f;
    --num;
    goto L212;

L890:
    gelac = as;
    xlatr = gelac;
    if (cos(gelac) != 0.f) {
	goto L45;
    } else {
	goto L46;
    }
L45:
    if (cos(galar) != 0.f) {
	goto L47;
    } else {
	goto L46;
    }
L46:
    gelor = 0.f;
    goto L34;

L47:
    ck1 = (cos(xdr) - sin(galar) * sin(xlatr)) / (cos(galar) * cos(xlatr));

    ck2 = sin(xazr) * sin(xdr) / cos(xlatr);
    if (ck1 >= 0.f) {
	goto L37;
    }
    if (ck2 >= 0.f) {
	goto L882;
    }

    in = 1;
    goto L881;

L882:
    in = 2;
    goto L883;

L37:
    if (ck2 >= 0.f) {
	goto L885;
    }

    in = 3;
    goto L881;

L885:
    in = 4;

L883:
    if (dabs(ck1) > 1.f) {
	goto L887;
    }
    ac = acos(ck1);
    goto L888;

L881:
    if (dabs(ck2) > 1.f) {
	goto L887;
    }
    as = asin(ck2);

L888:
    switch (in) {
	case 1:  goto L33;
	case 2:  goto L32;
	case 3:  goto L31;
	case 4:  goto L36;
    }

L33:
    gelor = galor - pi - as;
    goto L34;

L32:
    gelor = galor + ac;
    goto L34;

L31:
    gelor = galor + as;
    goto L34;

L36:
    gelor = galor + ac;
    goto L34;

L887:
    gelor = 0.f;

/*     CONVERT LONGITUDE AND LATITUDE FROM RADIANS TO DEGREES */
/*     AND REDUCE LONGITUDE TO A FORM LESS THAN 360 DEGREES */

L34:
    alon = dabs(gelor);
L506:
    if (alon < pi2) {
	goto L116;
    }
    alon -= pi2;
    goto L506;

L116:
    gelor = r_sign(&alon, &gelor);
    if (dabs(gelor) > pi) {
	gelor -= r_sign(&pi2, &gelor);
    }

/*  LONGITUDE IN DEGREES */

    gelon = gelor / pirad;

/*     LATITUDE IS CONVERTED FROM GEOCENTRIC TO GEODETIC COORDINATES */

    gelat = gelac / pirad;

L212:
    if (num == 1) {
	goto L5000;
    }
    s_copy(place, " ", (ftnlen)32, (ftnlen)1);
    goto L900;

L5000:

/*      CLEAR BUFFER */

/*     ASSIGN REGION NUMBER AND NAME */

    s_copy(place, " ", (ftnlen)32, (ftnlen)1);
/* L215: */
    xlat = gelat;
    xlon = gelon;
    if (xlon < 0.f) {
	xlon += 360.f;
    }

/*     DETERMINE EARTH QUADRANT */

    if (xlat < 0.f) {
	goto L4;
    }
    if (xlon > 180.f) {
	goto L6;
    }

/*     LATITUDE POSITIVE,LONGITUDE 0-180 */

    mhemis = 0;
    goto L9;

/*     LATITUDE POSITIVE,LONGITUDE 181-360 */

L6:
    mhemis = 3600;
    xlon = 360.f - xlon;
    goto L9;

L4:
    if (xlon > 180.f) {
	goto L8;
    }

/*     LATITUDE NEGATIVE,LONGITUDE 0-180 */

    mhemis = 7200;
    goto L9;

/*     LATITUDE NEGATIVE,LONGITUDE 181-360 */

L8:
    mhemis = 10800;
    xlon = 360.f - xlon;

L9:

/*     CHECK FOR ZERO LATITUDE */

    if (dabs(xlat) >= 1.f) {
	goto L13;
    }
    latin = 0;
    goto L17;

L13:
    latin = dabs(xlat);
    if (latin > last) {
	latin = last;
    }

L17:

    nlo = dabs(xlon);
    i__ = mhemis + latin * 40 + 1;
    for (iuk = 1; iuk <= 40; ++iuk) {
	buf[iuk - 1] = regioncom_1.xnrlon[i__ + iuk - 2];
    }
    nval = buf[0] * 1e3f + 1.1f;
    i__1 = nval;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (nlo < (integer) buf[i__ - 1]) {
	    goto L57;
	}
/* L56: */
    }
    i__ = nval + 1;
L57:
    *nreg = buf[i__ - 2];
    xreg = buf[i__ - 2] - *nreg;
    *nreg = xreg * 1e3f + .1f;
    i1 = regioncom_1.indfe[*nreg - 1] + 1;
    i2 = regioncom_1.indfe[*nreg];
    s_copy(place, regioncom_1.irname + (i1 - 1), (ftnlen)32, i2 - (i1 - 1));

L900:
    return 0;

} /* regworld_ */


/* ek    end of vel_topo.f */

/* ek    begin of matrinv.f */

/* of subr. regworld */
/* Subroutine */ int matrinv_(integer *n, real *a, real *b)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, m;
    static real ek;
    static integer ij, mi, jm, im, kn, mm, mj, nn;


/* MATRINV invertiert eine SYMMETRISCHE NxN-Matrix */

/* Aufruf: call MATRINV(N,A,B) */

/*         N = Anz. Zeilen/Kolonnen der Matrix */
/*         A = zu invertierende Matrix (Input) */
/*         B = inv(A)    (Output) */

    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
    b[1] = 1.f / a[1];
    if (*n - 1 <= 0) {
	goto L60;
    } else {
	goto L2;
    }
L2:
    nn = *n * *n;
    i__1 = nn;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L4: */
	b[i__] = 0.f;
    }
    mm = 1;
    kn = 0;
    i__1 = *n;
    for (m = 2; m <= i__1; ++m) {
	k = m - 1;
	mm = mm + *n + 1;
	kn += *n;
	ek = a[mm];
	mi = m - *n;
	i__2 = k;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    mi += *n;
	    ij = i__ - *n;
	    jm = kn;
	    i__3 = k;
	    for (j = 1; j <= i__3; ++j) {
		ij += *n;
		++jm;
/* L10: */
		ek -= a[mi] * b[ij] * a[jm];
	    }
	}
	b[mm] = 1.f / ek;
	mi = m - *n;
	im = kn;
	i__3 = k;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    ++im;
	    ij = i__ - *n;
	    jm = kn;
	    i__2 = k;
	    for (j = 1; j <= i__2; ++j) {
		ij += *n;
		++jm;
/* L20: */
		b[im] -= b[ij] * a[jm] * b[mm];
	    }
	    mi += *n;
/* L30: */
	    b[mi] = b[im];
	}
	im = kn;
	i__3 = k;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    ++im;
	    mj = m - *n;
	    ij = i__ - *n;
	    i__2 = k;
	    for (j = 1; j <= i__2; ++j) {
		mj += *n;
		ij += *n;
/* L40: */
		b[ij] += b[im] * b[mj] * ek;
	    }
	}
/* L50: */
    }
L60:
    return 0;
} /* matrinv_ */


/* ek    end of matrinv.f */

/* Subroutine */ int cputimer_(real *cpusec)
{
    static integer icpu;


/*     file: cputimer_unix.f */

/*     runs on:   HP-UX , UNIX System V (AT&T) */
/*      and on:   SunOS , BSD UNIX */

/*     first call:       start counting of CPU-time */
/*     subsequent calls: report elapsed CPU-time [sec] since first call */

/*     Call:   call CPUTIMER(cpusec)      where cpusec is a real variable */


/* Urs Kradolfer, 16.9.91 */
/*     external clock !$pragma C(clock) */

/*     icpu=clock() */
    *cpusec = (real) icpu / 1e6f;

    return 0;
} /* cputimer_ */

