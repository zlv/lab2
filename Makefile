SOURCEOBJS = main.cpp itern.cpp gauss.cpp inverse.cpp
main :
	g++ -o lab2 $(SOURCEOBJS)
main-debug :
	g++ -g -O1 -o lab2 $(SOURCEOBJS)
