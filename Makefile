#Makefile to create the code in python

GCMP=gcc -c 
FCMP=gfortran -O2 -c -fPIC

all:  libs  new

libs: libvelest.a

new:    
	python setup.py develop  

libvelest.a: seei.o velestc4.o  
	ar r libvelest.a seei.o velestc4.o
	ranlib libvelest.a
	cp libvelest.a stom/

.c.o:
	$(GCMP) -c $<
.f.o:
	$(FCMP)  $<

clean:
	rm -r build/  dist/  stom.egg-info/  stom/*.so   fin_hyp.cnv  invers.out *.o  *.a stom/*.a  stom/*.o
