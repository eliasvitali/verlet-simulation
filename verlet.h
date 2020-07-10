#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<math.h>
#include<string.h>
#include"bodies.h"

using namespace std;

bodies plnts[9]; //instantiate object 'plnts'
				 //array of 9 bodies (8 plnts + sun)

//verlet algorithm
//computes new positions and velocities for a body
//using forces
double verlet()
{

	/*----------------Part 3.3; to set Mercury initial values:
	 uncomment the next two lines------*/
	//plnts[1].setPosition(46e6, 0);
	//plnts[1].setVelocity(0, 59.22);
	
	double dt;
	int steps;

	const double G = 1.3274585e11; //grav constant
	int i,j,t;			//loop iterators
	double r_half;		//pos at half_step
	double r_x, r_y;	//pos vector components
	double Fx, Fy, L;	//Force & ang mom.
	int planet_count = 1;	//how many planets are being simulated
	printf("Enter the number of planets you would like to simulate: ");
	scanf("%d", &planet_count); //stores how many plnts to simulate
	printf("Enter the number of steps: ");
	scanf("%d", &steps); //stores how many steps to use
	
	double max_per = plnts[planet_count].getPeriod();		//sets timestep
	dt = max_per/(1.*steps);
//	dt = 10000; //adjustable if preferred

	//This loop creates empty .dat files named
	//<planetname>.dat by concatenating the planet name
	//and the string ".dat"
	//It then opens the files using the pointers
	//declared in the class
	for(i = 0; i <= planet_count; i++)
	{
		string planetfile =  plnts[i].getName();
		string name_file = planetfile + ".dat";
		plnts[i].pfile = fopen(name_file.c_str(), "w"); //c.str() converts char* to string
	}

	//The actual bulk of the verlet algorithm
	//time loop that updates the planet.dat
	//files with their new positions and mom.
	//along the way
	//runs for as many steps as
	//entered by the user
	for(t = 0; t < steps; t++)
	{

	//	To decrease sun's mass: uncomment next line
		//plnts[0].setMass(plnts[0].getMass() - plnts[0].getMass()*(0.5/(1.*steps)));
	
		//Initialize planet's angular momenta
		for(i = 0; i <= planet_count; i++)
		{
			plnts[i].setAng(0);
		}

		//calculate half-positions using 12a from (Young, 2014)
		for(i = 0; i <= planet_count; i++)
		{
			plnts[i].setPosition(plnts[i].getPositionX() + 0.5*dt*plnts[i].getVelocityX(), plnts[i].getPositionY() + 0.5*dt*plnts[i].getVelocityY());
		}
		
		//Sets initial force on planet to be zero on every iteration
		for(i = 0; i <= planet_count; i++)
		{
			plnts[i].setForce(0,0);
		}
		
		
		//This loop calculates the total force on each planet from each body
		//The double loop calculates each planet's force against each other body's
		for(i = 0; i <= planet_count; i++)
		{
			for(j = 0; j <= planet_count; j++)
			{
				if(i != j)		//avoids planet calculating force with itself
				{
					L = 0;
					Fx = 0;		//initialize temporary force component variables
					Fy = 0;
					
					r_x = plnts[j].getPositionX() - plnts[i].getPositionX(); //position vector from ith planet to jth planet
					r_y = plnts[j].getPositionY() - plnts[i].getPositionY();
					r_half = sqrt(r_x*r_x + r_y*r_y);			//magnitude of position vector
					
					Fx = G*plnts[j].getMass()*r_x/(r_half*r_half*r_half);	//calculate Force components using newtons' law
					Fy = G*plnts[j].getMass()*r_y/(r_half*r_half*r_half);
					
					plnts[i].setForce(plnts[i].getForceX() + Fx, plnts[i].getForceY() + Fy); //assign force components to ith planet
					
				}
			}
		}
		
		//Update planet velocities
		for(i = 0; i <= planet_count; i++)
		{
			plnts[i].setVelocity(plnts[i].getVelocityX() + dt*plnts[i].getForceX(), plnts[i].getVelocityY() + dt*plnts[i].getForceY());
		}
		
		//Update planet positions
		for(i = 0; i <= planet_count; i++)
		{
			plnts[i].setPosition(plnts[i].getPositionX() + 0.5*dt*plnts[i].getVelocityX(), plnts[i].getPositionY() + 0.5*dt*plnts[i].getVelocityY());
		}
	
		//Update angular momentum
		for(i = 0; i <= planet_count; i++)
		{
			L = plnts[i].getMass()*(r_x*plnts[i].getVelocityY() - r_y*plnts[i].getVelocityX());
			plnts[i].setAng(plnts[i].getAng() + L);
		}
		//Write data to "planet".dat file
		for (i = 0; i <= planet_count; i++)
		{
			fprintf(plnts[i].pfile, "%g %g %g\n", plnts[i].getPositionX(), plnts[i].getPositionY(), plnts[i].getAng());
		}
	}
}
