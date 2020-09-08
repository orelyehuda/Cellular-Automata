//
// Created by orely on 8/30/2020.
//
#include <iostream>
#include "Orbiter.h"



Orbiter::Orbiter() {
	std::cout << "Orbiter constructer called " << std::endl;
}

Orbiter::Orbiter(double mass, double radius, double x, double y) {
	this->mass = mass;
	this->radius = radius;
	this->pos.push_back(x);
	this->pos.push_back(y);

}

Orbiter::~Orbiter() {
	std::cout << "Orbiter deconstructer called " << std::endl;
}

double Orbiter::getMass() {
	return this->mass;
}

void Orbiter::setMass(double mass) {
	this->mass = mass;
}

std::vector<double> Orbiter::getVel() {
	return this->vel;
}

void Orbiter::setVel(std::vector<double> vel) {
	this->vel = vel;
}

std::vector<double> Orbiter::getPos() {
	return this->pos;
}

void Orbiter::setPos(std::vector<double> pos) {
	this->pos = pos;
}

void Orbiter::setRadius(double radius) {
	this->radius = radius;
}

double Orbiter::getRadius() {
	return this->radius;
}