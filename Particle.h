#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle();
	~Particle();

	void think(vector<unique_ptr<Particle>>& particles);
	void update();
	void draw();
	glm::vec3 separate(vector<unique_ptr<Particle>>& particles);
	glm::vec3 align(vector<unique_ptr<Particle>>& particles);
	glm::vec3 cohesion(vector<unique_ptr<Particle>>& particles);
	glm::vec3 seek(glm::vec3 target);
	void applyForce(glm::vec3 force);

private:
	glm::vec3 location;
	glm::vec3 velocity;
	glm::vec3 acceleration;
	deque<glm::vec3> log;

	float range;
	float max_force;
	float max_speed;
	ofColor color;
};