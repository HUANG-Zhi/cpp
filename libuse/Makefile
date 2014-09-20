CPP=g++
CPPFLAGS=-c

aaa.o:aaa.cpp
	$(CPP) $(CPPFLAGS) aaa.cpp -o aaa.o
bbb.o:bbb.cpp
	$(CPP) $(CPPFLAGS) bbb.cpp -o bbb.o

LD=ld
SLIB = libaaa.so
so:aaa.o
	$(LD) -shared -o $(SLIB) aaa.o

ALIB = libaaa.a
AR=ar
a:aaa.o
	$(AR) -r $(ALIB) aaa.o

ab:a bbb.o
	$(CPP) -o bbb bbb.o -L. -l aaa 

sb:so bbb.o
	$(CPP) -o bbb bbb.o -L. -l aaa 