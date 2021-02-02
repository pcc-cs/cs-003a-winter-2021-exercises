all: except1 except2 except3 except4

except1: except1.cpp
	g++ -o $@ $<

except2: except2.cpp
	g++ -o $@ $<

except3: except3.cpp
	g++ -o $@ $<

# Note the "-g" flag to store symbols to enable debugging
except4: except4.cpp
	g++ -g -o $@ $<

clean:
	rm -f except?