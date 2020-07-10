#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<math.h>

using namespace std;

class planets
{
	private:
		string name;
		double m,T;
		double pos[2], vel[2], force[2], acc[2];
	public:
		void setName(string nm)
		{
			name = nm;
		}
		string getName()
		{
	//		cout << "Name = " << name << endl;
			return name;
		}
		void setMass(double a)
		{
			m = a;
		}
		double getMass()
		{
		//	cout << "The mass of " << name << " is " << m << " solar masses" << endl;
			return m;
		}
		void setPosition(double x, double y)
		{
			pos[0] = x;
			pos[1] = y;
		}	
		double getPositionX()
		{
		//	cout << "The position of " << name << " is " << "("<< pos.x << ", " << pos.y << ") " << "E6 km" << endl;
			return pos[0];
		}
		double getPositionY()
		{
		//	cout << "The position of " << name << " is " << "("<< pos.x << ", " << pos.y << ") " << "E6 km" << endl;
			return pos[1];
		}
		void setVelocity(double x, double y)
		{
			vel[0] = x;
			vel[1] = y;
		}	
		double getVelocityX()
		{
//			cout << "The velocity of " << name << " is " << "("<< vel.x << ", " << vel.y << ") " << "km/s" << endl;
			return vel[0];
		}
		double getVelocityY()
		{
			return vel[1];
		}
		void setAcc(double x, double y)
		{
			acc[0] = x;
			acc[1] = y;
		}
		double getAccX()
		{
			return acc[0];
		}
		double getAccY()
		{
			return acc[1];
		}
		void setForce(double x, double y)
		{
			force[0] = x;
			force[1] = y;
		}
		double getForceX()
		{
			return force[0];
		}
		double getForceY()
		{
			return force[1];
		}

		void setPeriod(double t)
		{
			T = t;
		}
		double getPeriod()
		{
			return T;
		}
};

