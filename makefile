.PHONY: clean all
all: qsort mergesort rand

qsort: qsort.cpp
	g++ qsort.cpp -O2 -o qsort

mergesort: mergesort.cpp
	g++ mergesort.cpp -O2 -o mergesort

rand: rand.cpp
	g++ rand.cpp -O2 -o rand

clean:
	rm rand qsort mergesort
