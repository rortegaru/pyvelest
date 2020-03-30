      subroutine scaninput(ip)
      character*(*) ip
      implicit none
      integer io
      include 'vel_com2.f'
      real olat,olon,avelo,z,dx,dy,dz,rotate
      integer ifil,j,ifl,mode,icc,ml,jndex,k
c
      integer trimlen, i,n
      character*40 titl
      character*80 card,line(32), titleline
      logical lexist

      i=0
111   continue
      call rdline_ic(ip)
      read(ip,'(a)') card
      if(card(1:1).eq.'*') goto 111
      if(card(1:1).eq.'@') goto 222
      i=i+1
      line(i)=card
      goto 111
 222  continue
      if(.NOT.(i.eq.24.or.i.eq.32.)) then
      write(6,*)'Valor de i =',i
      write(6,*) card
      stop'INPUTPARAM>>> control-file not correct!'
      end if
c     i=1
      read(line(1),'(a)') titleline
      write(6,'(a)') titleline
      read(line(2),*) olat,olon,icoordsystem,zshift,itrial,ztrial,ised
      write(6,*) olat,olon,icoordsystem,zshift,itrial,ztrial,ised
      read(line(3),*) neqs,nshot,rotate
      write(6,*) neqs,nshot,rotate
      read(line(4),*) isingle, iresolcalc
      write(6,*) isingle, iresolcalc
      read(line(5),*) dmax,itopo,zmininput,veladj,zadj,lowveloclay
      write(6,*) dmax,itopo,zmininput,veladj,zadj,lowveloclay
      read(line(6),*) nsp, swtfac,vpvs, nmod
      write(6,*) nsp, swtfac,vpvs, nmod
      read(line(7),*) othet,xythet,zthet,vthet,stathet
      write(6,*) othet,xythet,zthet,vthet,stathet
      read(line(8),*) nsinv,nshcor,nshfix, iuseelev,iusestacorr
      write(6,*) nsinv,nshcor,nshfix, iuseelev,iusestacorr
      read(line(9),*) iturbo, icnvout,istaout,ismpout
      write(6,*) iturbo, icnvout,istaout,ismpout
      read(line(10),*) irayout,idrvout,ialeout,idspout,
     &                irflout,irfrout,iresout
      write(6,*) irayout,idrvout,ialeout,idspout,
     &                irflout,irfrout,iresout
      read(line(11),*) delmin,ittmax,invertratio
      write(6,*) delmin,ittmax,invertratio
      read(line(12),'(a)') modelfilename
      write(ip,'(a)')modelfilename
      call adline_bm(ip)
      write(6,'(a)') modelfilename
      read(line(13),'(a)') stationfilename
      write(ip,'(a)')stationfilename
      call adline_bt(ip)
      write(6,'(a)') stationfilename
      read(line(14),'(a)') seismofilename
      write(ip,'(a)')seismofilename
      call adline_bs(ip)
      write(6,'(a)') seismofilename
      read(line(15),'(a)') regnamfile
      write(ip,'(a)')regnamfile
      call adline_br(ip)
      write(6,'(a)') regnamfile
      read(line(16),'(a)') regkoordfile
      write(ip,'(a)')regkoordfile
      call adline_bk(ip)
      write(6,'(a)') regkoordfile
      read(line(17),'(a)') topo1file
      write(ip,'(a)')topo1file
      call adline_bl(ip)
      write(6,'(a)') topo1file
      read(line(18),'(a)') topo2file
      write(ip,'(a)')topo2file
      call adline_bz(ip)
      write(6,'(a)') topo2file
      read(line(19),'(a)') phasefile
      write(ip,'(a)')phasefile
      call adline_bp(ip)
      write(6,'(a)') phasefile
      read(line(20),'(a)') shotfile
      write(ip,'(a)')shotfile
      call adline_bf(ip)
      write(6,'(a)') shotfile
c     Output files:
      read(line(21),'(a)') outfile
      write(6,'(a)') outfile
      if(outfile.eq.' ') outfile='vel.out'
      read(line(22),'(a)') velfile
      write(6,'(a)') velfile
      if(velfile.eq.' ') velfile='velout.vel'
      read(line(23),'(a)') cnvfile
      write(6,'(a)') cnvfile
      if(cnvfile.eq.' ') cnvfile='velout.cnv'
      read(line(24),'(a)') stafile
      write(6,'(a)') stafile
      if(stafile.eq.' ') stafile='velout.sta'
c
c     the next few ouputfiles are not very often used, therefore
c     either all or none of them have to be specified in the controlfile:
      if(i.eq.32)then
      read(line(25),'(a)') smpfile
      if(smpfile.eq.' ') smpfile='velout.smp'
      read(line(26),'(a)') rayfile
      if(rayfile.eq.' ') rayfile='velout.ray'
      read(line(27),'(a)') drvfile
      if(drvfile.eq.' ') drvfile='velout.drv'
      read(line(28),'(a)') alefile
      if(alefile.eq.' ') alefile='velout.ale'
      read(line(29),'(a)') dsprfile
      if(dsprfile.eq.' ') dsprfile='velout.dspr'
      read(line(30),'(a)') rflfile
      if(rflfile.eq.' ') rflfile='velout.rfl'
      read(line(31),'(a)') rfrfile
      if(rfrfile.eq.' ') rfrfile='velout.rfr'
      read(line(32),'(a)') resfile
      if(resfile.eq.' ') resfile='velout.res'
      endif
      end

