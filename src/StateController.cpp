//
//  StateController.cpp
//  Passatge_raval
//
//  Created by Eduard Frigola on 21/03/2019.
//

#include "StateController.h"

StateController::StateController(){
    users[0] = STATE_STANDBY;
    users[1] = STATE_STANDBY;
}

void StateController::userHasEntered(int &userId){
    ofLog() << "User " + ofToString(userId) + " enters";
    if(users[!userId] == STATE_STANDBY){
        users[userId] = STATE_PLAYING;
    }else{
        users[userId] = STATE_SYNCING;
    }
}

void StateController::userHasLeaved(int &userId){
    ofLog() << "User " + ofToString(userId) + " leaves";
    users[userId] = STATE_STANDBY;
}

