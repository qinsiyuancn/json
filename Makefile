CC := g++

json:utils.o read.o jsonobj.o jsonarray.o dataadapter.o
	$(CC) -o $@ $^

utils.o:utils.h
jsonobj.o:json.h utils.h
jsonarray.o:json.h utils.h
dataadapter.o:json.h
read.o: json.h

.PHONY : clean
clean:
	rm json utils.o read.o jsonobj.o jsonarray.o dataadapter.o -f
