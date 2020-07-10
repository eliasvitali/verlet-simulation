# verlet-simulation
Planetary Orbit Simulation Exercise Using the Verlet Algorithm

# Summary 
This implementation is based on [this paper](http://physics.ucsc.edu/~peter/242/leapfrog.pdf) outlining the so-called 'Leap-Frog' or Verlet Algorithm. This algorithm can be applied to various scenarios, but it is used here to simulate planetary orbits on a 2D plane. 

The idea is that, given an initial set of conditions such as the position and velocity of an object, one can predict its position and velocity for the next time step, if all forces are known. My implementation takes into account the gravitational forces of all major objects within our solar system -- the Sun and 9 (yes, including Pluto) planets.
