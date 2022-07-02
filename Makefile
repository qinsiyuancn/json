CC := g++

json:utils.o read.o jsonobj.o jsonarray.o
	$(CC) -o $@ $^

utils.o:utils.h
read.o: jsonobj.h jsonarray.h
jsonobj.o:jsonobj.h dataadapter.h utils.h
jsonarray.o:jsonarray.h dataadapter.h utils.h

.PHONY : clean
clean:
	rm json utils.o read.o jsonobj.o jsonarray.o -r
