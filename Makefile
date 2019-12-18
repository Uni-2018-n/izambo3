SOURCE = main.cpp classes.cpp
ITEM = main

run : compile
	./$(ITEM)

debug : $(ITEM)
	gdb $(ITEM)

compile : $(SOURCE)
	g++ -std=c++11 -Wall -g3 -o $(ITEM) $(SOURCE)

clean :
	-rm $(ITEM)

compress: $(SOURCE)
	rm -r $(ITEM)
	mkdir final
	cp * final
