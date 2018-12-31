#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetLineWidth(1.5);
	ofEnableDepthTest();

	font.loadFont("fonts/Kazesawa-bold.ttf", 150, true, true, true);

	this->number_of_particle = 120;
	for (int i = 0; i < this->number_of_particle; i++) {

		auto particle = make_unique<Particle>();
		this->particles.push_back(move(particle));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (auto& particle : this->particles) {

		particle->think(this->particles);
	}

	for (auto& particle : this->particles) {

		particle->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofSetColor(239);
	this->font.drawString("2018", -this->font.stringWidth("2018") * 0.5, -this->font.stringHeight("2018") * 0.5);

	for (auto& particle : this->particles) {

		particle->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}