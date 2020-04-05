#Makefile to create the code in python

GCMP=gcc -c A
FCMP=gfortran -O2 -c -fPIC

all:  libvelest.a  new


new:    velesm.c 
	python setup.py develop  

libvelest.a: seei.o velestc4.o  
	rm libvelest.a
	ar r libvelest.a seei.o velestc4.o
	ranlib libvelest.a
	cp libvelest.a stom/

.c.o:
	$(GCMP) -c $<
.f.o:
	$(FCMP)  $<

clean:
	rm -r build/  dist/  stom.egg-info/  stom/*.so   fin_hyp.cnv  invers.out *.o  *.a stom/*.a  stom/*.o
