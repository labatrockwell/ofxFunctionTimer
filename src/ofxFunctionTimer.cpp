//
//  timerTool.cpp
//  Blooms
//
//  Created by Lucas Vickers on 12/19/12.
//
//

#include "ofxFunctionTimer.h"

#if defined(WIN32) || defined(WIN64)
#include <Windows.h>
#include <winsock2.h>
#else
#include <time.h>
#include <sys/time.h>
#endif

using namespace std;

unsigned long long ofxFunctionTimer::epochMS()
{
#if defined(WIN32) || defined(WIN64)
    
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	ULARGE_INTEGER ts;
    
	ts.HighPart = ft.dwHighDateTime;
	ts.LowPart = ft.dwLowDateTime;
    
	unsigned long long time = ts.QuadPart;
	time /= 10000;
	//cout << time << endl;
	
	return time;
    
#else
    
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    
    unsigned long long millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;
    
    // fake the MS
    return millisecondsSinceEpoch;
    
#endif
}

ofxFunctionTimer::ofxFunctionTimer()
{
    enabled = true;
}


void ofxFunctionTimer::start(std::string func_name)
{
    if (! enabled ) { return; }
    
    _stats[func_name] = epochMS();
}

void ofxFunctionTimer::stop(std::string func_name)
{
    if (! enabled ) { return; }
    
    int len = func_name.length();
    
    int space = 30 - len;
 
    outputMutex.lock();
    
    unsigned long long delay = epochMS() - _stats[func_name];
    
    // if you don't want to see these, set the .enabled to false in the code that calls this
    if(delay > 15) {
        cout << func_name << " took ";
        
        for(int i=0; i<space; ++i) {
            cout << " " ;
        }
        cout << delay << " ms to process.";
        if( delay > 20 ) {
            cout << " *****" << endl;
        } else {
            cout << endl;
        }
    }
    
    outputMutex.unlock();
    
}

    
