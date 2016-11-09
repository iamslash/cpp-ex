# 
CC  = c99
CXX = g++
CXXFLAGS = -std=c++11 # -g
# g++ -std=c++11 -g -c a.cpp
# objdump -d -M intel -S a.o

all: TAGS a.out

a.dump: a.o
	objdump -d -M intel -S $< > $@
a.exe: a.o
	$(CXX) $^ $(LDFLAGS) -o $@
a.out: a.o
	$(CXX) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX)  -c $(CXXFLAGS) -o $@ $< -MMD
%.o: %.c
	$(CC)  -c $(CFLAGS) -o $@ $< 

TAGS:
	-@gtags
clean:
	-rm -f *.o *.dump *.exe *.out *.d
	-rm -f core GPATH GRTAGS GSYMS GTAGS

-include $(wildcard *.d)
