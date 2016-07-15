CXX= g++ -std=c++11
CXXFLAGS = -Wall -O -g `pkg-config gtkmm-3.0 gmodule-2.0 --cflags`
LDFLAGS=`pkg-config gtkmm-3.0 gmodule-2.0 --libs`
OBJS = main.o
EXEC = main

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(EXEC)

clean:
	rm $(EXEC) $(OBJS)
