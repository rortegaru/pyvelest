#Makefile to create the code in python

GCMP=gcc -g
FCMP=f2c

all: cfunc seei.c  new

cfunc:
	cd stom
	make c_func

new:    velesm.c 
	python setup.py develop  

velesm.c: velestc2.c  
	 cat velestc2.c > stom/velesm.c
	 cat velestc2.c > velesm.c

.c.o:
	$(GCMP) -c $<
.f.c:
	$(FCMP)  $<
	cp $@ stom/

clean:
	rm -r build/  dist/  stom.egg-info/  stom/stom.so  stom/velest.cpython-38-darwin.so fin_hyp.cnv  invers.out
