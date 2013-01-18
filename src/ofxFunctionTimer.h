//
//  timerTool.h
//  Blooms
//
//  Created by Lucas Vickers on 12/19/12.
//
//

#ifndef __ofxFunctionTimer__
#define __ofxFunctionTimer__

#include <iostream>
#include <map>
#include "ofMain.h"

class ofxFunctionTimer {

public:
    
    static unsigned long long epochMS();

    ofxFunctionTimer();
    
    void start(std::string func_name);
    void stop(std::string func_name);
    
    bool enabled;
    
protected:
    
    ofMutex outputMutex;
    
    std::map<std::string, unsigned long long> _stats;
    

};

    
#endif /* defined(__ofxFunctionTimer__) */
