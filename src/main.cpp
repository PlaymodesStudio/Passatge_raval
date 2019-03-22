#include "ofMain.h"
#ifdef TARGET_RASPBERRY_PI
#include "ofAppNoWindow.h"
#endif
#include "ofApp.h"


//========================================================================
int main( ){
#ifdef TARGET_RASPBERRY_PI
    ofAppNoWindow window;
#else
    ofAppGLFWWindow window;
#endif
	ofSetupOpenGL(&window, 1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
