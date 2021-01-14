src = $(wildcard ./*.cpp)
obj = $(patsubst %.cpp, %.o,$(src))
target = $(patsubst %.cpp, %, $(src))
CXX = g++

$(obj): $(src)
	$(CXX) -c $< -o $@

$(target): $(obj)
	$(CXX) -o $@ $^

.PHONY: all
all: $(target)

.PHONY: clean  
clean:
	rm -rf $(obj) $(target)