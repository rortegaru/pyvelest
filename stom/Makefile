#Makefile to create the code in python

GCMP=gcc -g
FCMP=f2c

all: stom

stom: fbufopen.c velesm.c c_velest.c
	cd ../
	python setup.py develop

velesm.c: velestf.c  
	 cat inicio.c velestf.c > velesm.c

.c.o:
	$(GCMP) -c $<
.f.c:
	$(FCMP)  $<
