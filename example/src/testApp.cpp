#include "testApp.h"

// This is needed for windows compatability.

#if defined ( WIN32 )
#define __func__ __FUNCTION__
#endif

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

    ft.start(__func__);
    
    if( ( (int) ofRandom(100) ) == 0) {
        sleep(1);
    }
    
    ft.stop(__func__);
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}