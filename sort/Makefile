SIZE ?= 200
squ:generatesqu.c
	gcc -o generatesqu generatesqu.c	

squ$(SIZE):squ
	./generatesqu $(SIZE) squ$(SIZE)

sort:sort.c
	gcc -o sort -g sort.c

test:squ$(SIZE) sort
	echo >> report
	echo "--------------Size:$(SIZE)--------------" >> report
	date >> report
	./sort $(SIZE) < squ$(SIZE) >> report
	tail -9 report
clean:
	rm sort generatesqu squ$(SIZE)