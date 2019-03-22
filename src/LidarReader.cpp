//
//  LidarReader.cpp
//  Passatge_raval
//
//  Created by Eduard Frigola on 19/03/2019.
//

#include "LidarReader.h"

LidarReader::LidarReader(){
    isSomething = false;
    isUser = false;
    lastEventTime = 0;
    toleranceTime = 2;
    noUserThreshold = 320;
}

void LidarReader::setup(uint8_t _user, uint8_t address){
    user = _user;
    isSomething.set("is Something", false);
#ifdef TARGET_RASPBERRY_PI
    bus = new I2c("/dev/i2c-1");
    bus->addressSet(address);
#else
    gui.setup("User " + ofToString(int(user)));
    gui.add(isSomething);
    listener = isSomething.newListener([this](bool &b){
        lastEventTime = ofGetElapsedTimef();
    });
#endif
    startThread();
}

void LidarReader::threadedFunction(){
    while(isThreadRunning()){
        usleep(20000);
#ifdef TARGET_RASPBERRY_PI
        bus->writeByte(0x00, 0x04);
        while(bus->tryReadByte(0x01) >> 7 != 0);
        uint16_t highByte = bus->readByte(0x0f);
        uint16_t lowByte = bus->readByte(0x10);
        uint32_t readVal = lowByte + (highByte << 8);
        if(readVal < noUserThreshold){
            if(!isSomething){
                isSomething = true;
                lastEventTime = ofGetElapsedTimef();
            }
        }else{
            if(isSomething){
                isSomething = false;
                lastEventTime = ofGetElapsedTimef();
            }
        }
#endif
        if(isSomething != isUser){
            float currentTime = ofGetElapsedTimef();
            if(lastEventTime + toleranceTime < currentTime){
                isUser = isSomething;
                int intUser = int(user);
                if(isUser){
                    userEnteredEvent.notify(intUser);
                }else{
                    userLeavedEvent.notify(intUser);
                }
            }
        }
    }
}
