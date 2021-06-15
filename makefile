OBJS = main.o
CXX = g++
CPPFLAGS = -Wall -std=c++11
LDLIBS = -lsfm-graphics -lsfml-window -lsfml-system

game: $(OBJS)
	$(CXX) -o game $(OBJS) $(LDLIBS)

clean:
	$(RM) game $(OBJS)