#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lidarReader.setup(0, 0x61);
    lidarReader2.setup(1, 0x62);
    
    listeners.push(lidarReader.userEnteredEvent.newListener(&stateController, &StateController::userHasEntered));
    listeners.push(lidarReader.userLeavedEvent.newListener(&stateController, &StateController::userHasLeaved));
    listeners.push(lidarReader2.userEnteredEvent.newListener(&stateController, &StateController::userHasEntered));
    listeners.push(lidarReader2.userLeavedEvent.newListener(&stateController, &StateController::userHasLeaved));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    lidarReader.draw();
    lidarReader2.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
