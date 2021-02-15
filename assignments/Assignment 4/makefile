src = $(wildcard ./*.cpp)
obj = $(patsubst %.cpp, %.o,$(src))
target = $(patsubst %.cpp, %, $(src))

.PHONY: all
all: $(target)

.PHONY: clean  
clean:
	rm -rf $(obj) $(target)