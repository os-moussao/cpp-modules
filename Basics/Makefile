all:

%: %.cpp
	@make $@.out

%.out: %.cpp
	g++ --std=c++11 $< -o $@

clean:
	rm *.out

cl: clean
