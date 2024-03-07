/*
Author: Michael Padilla
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 9 F

This program creates a particle dynamically and moves it base on time and prints
its new position every 10 seconds
*/

#include <cmath>
#include <iostream>
using namespace std;

class Coord3D {
public:
  double x;
  double y;
  double z;
};

class Particle {
public:
  Coord3D pos;
  Coord3D vel;
};

// dynamically allocate memory for a particle and initialize it
Particle *createParticle(double x, double y, double z, double vx, double vy,
                         double vz) {
  Particle *pparticle = new Particle;
  Coord3D pos = {x, y, z};
  Coord3D vel = {vx, vy, vz};
  (*pparticle).pos = pos;
  (*pparticle).vel = vel;

  return 0;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz) {
  (*p).vel.x = vx;
  (*p).vel.y = vy;
  (*p).vel.z = vz;
}

// get its current position
Coord3D getPosition(Particle *p) { return (*p).pos; }

// update particle's position after elapsed time dt
void move(Particle *p, double dt) {
  (*p).pos.x = (*p).pos.x + (*p).pos.x * dt;
  (*p).pos.y = (*p).pos.y + (*p).pos.y * dt;
  (*p).pos.z = (*p).pos.z + (*p).pos.z * dt;
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p) { delete p; }

int main() {
  Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
  double time = 0.0;
  double dt = 0.1;
  while (time < 3.0) {
    setVelocity(p, 10.0 * time, 0.3, 0.1);

    move(p, dt);
    time += dt;

    cout << "Time: " << time << " \t";
    cout << "Position: " << getPosition(p).x << ", " << getPosition(p).y << ", "
         << getPosition(p).z << endl;
  }

  deleteParticle(p);

  return 0;
}
