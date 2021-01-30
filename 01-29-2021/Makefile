all: class1 class2 class3 class4

class1: class1.o cat.o dog.o animal.o util.o
	g++ -o $@ $^

class1.o: class1.cpp cat.h dog.h animal.h
	g++ -c $<

class2: class2.cpp
	g++ -o $@ $<

class3: class3.cpp
	g++ -o $@ $<

class4: class4.cpp
	g++ -o $@ $<

cat.o: cat.cpp cat.h animal.h
	g++ -c $<

dog.o: dog.cpp dog.h animal.h
	g++ -c $<

animal.o: animal.cpp animal.h
	g++ -c $<

util.o: util.cpp util.h animal.h
	g++ -c $<

clean:
	rm -f pali? class? *.o