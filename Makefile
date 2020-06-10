all: myk

myk:
	g++ -c main.cpp -std=c++11 -o main.o
	g++ -c Circle.cpp -std=c++11 -o Circle.o
	g++ -c Rectangle.cpp -std=c++11 -o Rectangle.o
	g++ -c Triangle.cpp -std=c++11 -o Triangle.o
	g++ -c ComposedShape.cpp -std=c++11 -o ComposedShape.o
	g++ -c Polygon.cpp -std=c++11 -o Polygon.o
	g++ -c PolygonVect.cpp -std=c++11 -o PolygonVect.o
	g++ -c PolygonDyn.cpp -std=c++11 -o PolygonDyn.o
	g++ -c PolyLine.cpp -std=c++11 -o PolyLine.o
	g++ -c Shape.cpp -std=c++11 -o Shape.o
	g++ main.o Circle.o Rectangle.o Triangle.o ComposedShape.o Polygon.o PolyLine.o PolygonVect.o PolygonDyn.o Shape.o -o exe
	./exe
clean:
	rm *.o