#Makefile to create the code in python

GCMP=gcc -g
FCMP=f2c

all: stom

stom:   velesm.c 
	python setup.py develop

velesm.c: velestc2.c  
	 cat inicio.c velestc2.c > stom/velesm.c
	 cat inicio.c velestc2.c > velesm.c

.c.o:
	$(GCMP) -c $<
.f.c:
	$(FCMP)  $<
