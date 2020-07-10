//Filename: planets.cpp
//SRC: Elias Vitali
//Date: December 2017

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<math.h>
#include<string.h>
#include"verlet.h"
using namespace std;

// Function to read the planet data file
// Stores initial properties of planets by calling plnts[i] from the planets class
void readFile()
{
	char title[20];
	double xpos, ypos, velx, vely, wt, per;

	FILE *fp;									//file pointer
	fp = fopen("planet.dat", "r");				//reads planet.dat

	if (fp == NULL)								//checks to make sure file actually opened
	{
		printf("Failed to open file!\n");
		exit(1);
	}
	char buffer[100];							//buffer
	fgets(buffer, 100, fp);						//skips first line of file

	int idx;
	for(idx = 0; idx <=8; idx++)				//gets information from planet.dat file
	{
		fscanf(fp,"%s %lf %lf %lf %lf %lf %lf", title, &wt, &xpos, &ypos, &vely, &velx, &per);
		plnts[idx].setName(title);						//sets name of planet
		plnts[idx].setPosition(1e6*xpos, 1e6*ypos);		//sets the position of the planet
		plnts[idx].setVelocity(velx, vely);				//sets the velocity of the planet
		plnts[idx].setMass(wt);							//sets the mass of the planet
		plnts[idx].setPeriod(per);						//sets the period of the planet
	}
}

// Runs all of the above
int main()
{
	readFile();
	verlet();
}
