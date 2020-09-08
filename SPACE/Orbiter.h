//
// Created by orely on 8/30/2020.
//

#ifndef ORBIT_ORBITER_H
#define ORBIT_ORBITER_H
#include <vector>

class Orbiter {
private:
	double mass;
	double radius;

	std::vector <double> vel;
	std::vector <double> pos;
public:
	Orbiter();
	Orbiter(double, double, double, double);
	~Orbiter();

	double getMass();
	void setMass(double mass);

	std::vector<double> getVel();
	void setVel(std::vector<double> vel);

	std::vector<double> getPos();
	void setPos(std::vector<double> pos);

	void setRadius(double);
	double getRadius(void);


};

#endif //ORBIT_ORBITER_H
