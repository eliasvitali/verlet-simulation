planets: planets.o bodies.h verlet.h
	g++ planets.o -o planets -lm
	
planets.o: planets.cpp bodies.h verlet.h
	g++ planets.cpp bodies.h verlet.h -c


