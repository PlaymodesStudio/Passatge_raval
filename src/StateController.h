//
//  StateController.h
//  Passatge_raval
//
//  Created by Eduard Frigola on 21/03/2019.
//

#ifndef StateController_h
#define StateController_h

#include "ofMain.h"

enum UserState{
    STATE_STANDBY,
    STATE_PLAYING,
    STATE_SYNCING
};

class StateController{
public:
    StateController();
    ~StateController(){};
    
    void setup(){};
    
    void userHasEntered(int &userId);
    void userHasLeaved(int &userId);
private:
    UserState users[2];
};

#endif /* StateController_h */
