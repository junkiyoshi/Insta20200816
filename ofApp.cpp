#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255, 64);
	ofNoFill();
	ofSetCircleResolution(72);
	ofSetLineWidth(0.2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	for (int x = 210; x < ofGetWidth(); x += 300) {

		for (int y = 210; y < ofGetHeight(); y += 300) {

			ofPushMatrix();
			ofTranslate(x, y);

			int radius_start = 120;
			int radius_span = 1;
			auto noise_seed = ofRandom(1000);

			ofDrawCircle(glm::vec2(), radius_start);
			for (int radius = radius_start - radius_span; radius >= 0; radius -= radius_span) {

				auto tmp_radius = radius_span;
				auto deg = ofMap(ofNoise(noise_seed + radius * 0.005 - ofGetFrameNum() * 0.015), 0, 1, -720, 720);
				auto location = glm::vec2(tmp_radius * cos(deg * DEG_TO_RAD), tmp_radius * sin(deg * DEG_TO_RAD));
				ofDrawCircle(location, radius);

				ofTranslate(location);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}