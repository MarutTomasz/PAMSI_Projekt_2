TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++17 -iquote inc


__START__: ${OBJ} ${OBJ}/main.o ${OBJ}/Element.o ${OBJ}/MergeSort.o ${OBJ}/QuickSort.o ${OBJ}/Kubel.o ${OBJ}/BucketSort.o
	g++ -o ${TRGDIR}/sortowanie ${OBJ}/main.o ${OBJ}/Element.o ${OBJ}/MergeSort.o ${OBJ}/QuickSort.o ${OBJ}/Kubel.o ${OBJ}/BucketSort.o

${OBJ}:	
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/Element.hh inc/MergeSort.hh inc/QuickSort.hh inc/Kubel.hh inc/BucketSort.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Element.o:inc/Element.hh src/Element.cpp
	g++ -c ${FLAGS} -o ${OBJ}/Element.o src/Element.cpp

${OBJ}/MergeSort.o:inc/MergeSort.hh inc/Element.hh src/MergeSort.cpp
	g++ -c ${FLAGS} -o ${OBJ}/MergeSort.o src/MergeSort.cpp

${OBJ}/QuickSort.o:inc/QuickSort.hh inc/Element.hh src/QuickSort.cpp
	g++ -c ${FLAGS} -o ${OBJ}/QuickSort.o src/QuickSort.cpp

${OBJ}/Kubel.o:inc/Kubel.hh src/Kubel.cpp inc/Element.hh
	g++ -c ${FLAGS} -o ${OBJ}/Kubel.o src/Kubel.cpp

${OBJ}/BucketSort.o:inc/BucketSort.hh inc/Kubel.hh src/BucketSort.cpp
	g++ -c ${FLAGS} -o ${OBJ}/BucketSort.o src/BucketSort.cpp
