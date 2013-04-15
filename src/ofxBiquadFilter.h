//
//  ofxBiquadFilter.h
//
//  ofxAddon by Nikolaj Møbius (DZL) && Jonas Jongejan (halfdanj)
//  Original C++ code by Nigel Redmon on 11/24/12
//  EarLevel Engineering: earlevel.com
//  Copyright 2012 Nigel Redmon
//
//  For a complete explanation of the Biquad code:
//  http://www.earlevel.com/main/2012/11/26/Biquad-c-source-code/
//
//  License:
//
//  This source code is provided as is, without warranty.
//  You may copy and distribute verbatim copies of this document.
//  You may modify and use this source code to create binary code
//  for your own purposes, free or commercial.
//

#pragma once

#include "ofMain.h"
#include "ofxBiquadFilterInstance.h"


//
// The base template filter
//

template<class VectorType>
class ofxBiquadFilter_ {
public:
    
    ofxBiquadFilter_(ofxBiquadFilterType type=OFX_BIQUAD_TYPE_LOWPASS,
                    double Fc=0.50,
                    double Q=0.707,
                    double peakGainDB=0.0);
    

    //Call this with the value you want to filter on. Outputs the filtered value
    VectorType update(VectorType inputValue);
    
    void setType(ofxBiquadFilterType type);
    void setQ(double Q);
    void setFc(double Fc);
    void setPeakGain(double peakGainDB);

    
    vector<ofxBiquadFilterInstance> instances;

private:
    int dimensions;

};




//
//The types of filters supported:
//

typedef ofxBiquadFilter_<float> ofxBiquadFilter1f;
typedef ofxBiquadFilter_<ofVec2f> ofxBiquadFilter2f;
typedef ofxBiquadFilter_<ofVec3f> ofxBiquadFilter3f;
typedef ofxBiquadFilter_<ofVec4f> ofxBiquadFilter4f;
typedef ofxBiquadFilter_<ofFloatColor> ofxBiquadFilterColor;

