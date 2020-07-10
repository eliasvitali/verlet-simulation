//Filename: bodies.h
//SRC: Elias Vitali
//Date: December 2017
//Description: this file contains the main class used
//'bodies' which stores the properties of all of the 
//planets

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<math.h>
#include<string.h>

using namespace std;

class bodies				//Class declaration
{
	private:
		string name;		//stores filename as string
		char* filename;		//filename for planets
		double m,T;			//mass and period
		double pos[2], vel[2], force[2], ang; //pos, vel, force and ang momentum
	public:	
		FILE *pfile;			//pointer for filename
		void setName(string nm)	//sets name
		{
			name = nm;
		}
		string getName()		//returns name
		{
			return name;
		}
		void setMass(double a)	//sets mass
		{
			m = a;
		}
		double getMass()		//returns mass
		{
			return m;
		}
		void setPosition(double x, double y) //sets pos vector
		{
			pos[0] = x;
			pos[1] = y;
		}	
		double getPositionX()	//returns x position
		{
			return pos[0];
		}
		double getPositionY()	//returns y position
		{
			return pos[1];
		}
		void setVelocity(double x, double y)//sets velocity vector
		{
			vel[0] = x;
			vel[1] = y;
		}	
		double getVelocityX()	//returns x velocity
		{
			return vel[0];
		}
		double getVelocityY()	//returns y velocity
		{
			return vel[1];
		}
		void setForce(double x, double y)	//sets force vector
		{
			force[0] = x;
			force[1] = y;
		}
		double getForceX()		//returns x force
		{
			return force[0];
		}
		double getForceY()		//returns y force
		{
			return force[1];
		}
		void setPeriod(double t)	//sets period
		{
			T = t;
		}
		double getPeriod()		//returns period
		{
			return T;
		}
		void setAng(double x)	//sets ang momentum
		{
			ang = x; 
		}
		double getAng()			//returns ang mom.
		{
			return ang;
		}
};
