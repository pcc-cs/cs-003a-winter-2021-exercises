all: template1 template2 template4 lambda1

template1: template1.cpp
	g++ -o $@ $<

template2: template2.cpp
	g++ -o $@ $<

# This will NOT link because util.o contains no symbols
template3: template3.o util.o
	g++ -o $@ $^

template4: template4.cpp stack.h
	g++ -o $@ $<

lambda1: lambda1.cpp
	g++ -o $@ $<

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o template? lambda?