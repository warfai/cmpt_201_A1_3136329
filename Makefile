/*------------------------------------------
 Student’s Name: Idris Warfa
 Assignment #1 - Makefile
 Lab Section: X02L
 Lab Instructor’s Name: Salwa Abougamila
--------------------------------------------*/

# ---------------------------------------------
# Compiler and Flags
# ---------------------------------------------
CC = gcc
CFLAGS = -Wall -ansi
LDFLAGS = -lm

# ---------------------------------------------
# Targets: Build all programs
# ---------------------------------------------
all: cardinalSort countingCovid xTable squeeze

# ---------------------------------------------
# Build cardinalSort
# ---------------------------------------------
cardinalSort: cardinalSort.c
	$(CC) $(CFLAGS) cardinalSort.c -o cardinalSort

# ---------------------------------------------
# Build countingCovid
# ---------------------------------------------
countingCovid: countingCovid.c
	$(CC) $(CFLAGS) countingCovid.c -o countingCovid

# ---------------------------------------------
# Build xTable
# ---------------------------------------------
xTable: xTable.c
	$(CC) $(CFLAGS) xTable.c -o xTable $(LDFLAGS)

# ---------------------------------------------
# Build squeeze
# ---------------------------------------------
squeeze: squeeze.c
	$(CC) $(CFLAGS) squeeze.c -o squeeze

# ---------------------------------------------
# Testing Section
# ---------------------------------------------
.PHONY: testing

testing: testCardinalSort testCountingCovid testXTable testSqueeze

# ---------------------------------------------
# Individual Test Cases
# ---------------------------------------------
testCardinalSort:
	./cardinalSort < testing/testCardinalSortIn.txt > testing/testCardinalSortOut.txt
	diff testing/testCardinalSortOut.txt testing/correctCardinalSort.txt

testCountingCovid:
	./countingCovid < testing/covidData.csv > testing/testCountingCovidOut.txt
	diff testing/testCountingCovidOut.txt testing/correctCountingCovid.txt

testXTable:
	./xTable > testing/testXTableOut.txt
	diff testing/testXTableOut.txt testing/correctXTable.txt

testSqueeze:
	./squeeze < testing/testSqueezeIn.txt > testing/testSqueezeOut.txt
	diff testing/testSqueezeOut.txt testing/correctSqueeze.txt

# ---------------------------------------------
# Clean Section
# ---------------------------------------------
.PHONY: clean

clean:
	rm -f cardinalSort countingCovid xTable squeeze *.o testing/*.txt

# ---------------------------------------------
# Packaging Section
# ---------------------------------------------
.PHONY: tar

tar:
	tar -czvf A1.tar.gz A1/

# ---------------------------------------------
# End of Makefile
# ---------------------------------------------