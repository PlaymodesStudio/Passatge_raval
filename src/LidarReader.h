//
//  LidarReader.h
//  Passatge_raval
//
//  Created by Eduard Frigola on 19/03/2019.
//

#ifndef LidarReader_h
#define LidarReader_h

#include "ofMain.h"
#ifdef TARGET_RASPBERRY_PI
#include "ofxGPIO.h"
#else
#include "ofxGui.h"
#endif

class LidarReader : public ofThread{
public:
    LidarReader();
    ~LidarReader(){
        stopThread();
        waitForThread(true);
    };
    
    void setup(uint8_t _user, uint8_t address);
    void draw(){
#ifndef TARGET_RASPBERRY_PI
        gui.draw();
#endif
    }
    
    ofEvent<int> userEnteredEvent;
    ofEvent<int> userLeavedEvent;
private:
    void threadedFunction();
    
#ifdef TARGET_RASPBERRY_PI
    I2c * bus;
#else
    ofxPanel gui;
    ofEventListener listener;
#endif
    uint8_t user;
    ofParameter<bool> isSomething;
    bool isUser;
    float lastEventTime;
    float toleranceTime;
    unsigned short noUserThreshold;
};

#endif /* LidarReader_h */
