#Makefile to create the code in python

GCMP=gcc -g
FCMP=f2c

all: cfunc  new

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

clean:
	rm -r build/
	rm -r dist/
	rm -r stom.egg-info/
	rm stom/stom.so

