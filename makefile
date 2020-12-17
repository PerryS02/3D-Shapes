shapes3D: shapes3D.o main.o shape.o cone.o specialCube.o camera.o
	g++ -o shapes3D shapes3D.o main.o shape.o cone.o specialCube.o camera.o -l glui -l glut -l GLU -l GL -l Xi -l Xmu -l Xext -l X11 -l m

shapes3D.o: shapes3D.cpp shapes3D.h
	g++ -c shapes3D.cpp

main.o: main.cpp shapes3D.h
	g++ -c main.cpp

shape.o: shape.cpp shape.h
	g++ -c shape.cpp

cone.o: cone.cpp cone.h
	g++ -c cone.cpp

specialCube.o: specialCube.cpp specialCube.h
	g++ -c specialCube.cpp

camera.o: camera.cpp camera.h
	g++ -c camera.cpp
