//
//  ofxBiquadFilterInstance.h
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

#include <math.h>
#include "ofxBiquadFilterInstance.h"

ofxBiquadFilterInstance::ofxBiquadFilterInstance(ofxBiquadFilterType type, double Fc, double Q, double peakGainDB) {
    setBiquad(type, Fc, Q, peakGainDB);
    z1 = z2 = 0.0;
}


ofxBiquadFilterInstance::~ofxBiquadFilterInstance() {
}

void ofxBiquadFilterInstance::setType(ofxBiquadFilterType type) {
    this->type = type;
    calcBiquad();
}

void ofxBiquadFilterInstance::setQ(double Q) {
    this->Q = Q;
    calcBiquad();
}

void ofxBiquadFilterInstance::setFc(double Fc) {
    this->Fc = Fc;
    calcBiquad();
}

void ofxBiquadFilterInstance::setPeakGain(double peakGainDB) {
    this->peakGain = peakGainDB;
    calcBiquad();
}

void ofxBiquadFilterInstance::setBiquad(ofxBiquadFilterType type, double Fc, double Q, double peakGainDB) {
    this->type = type;
    this->Q = Q;
    this->Fc = Fc;
    setPeakGain(peakGainDB);
}

void ofxBiquadFilterInstance::calcBiquad(void) {
    double norm;
    double V = pow(10, fabs(peakGain) / 20.0);
    double K = tan(M_PI * Fc);
    switch (this->type) {
        case OFX_BIQUAD_TYPE_LOWPASS:
            norm = 1 / (1 + K / Q + K * K);
            a0 = K * K * norm;
            a1 = 2 * a0;
            a2 = a0;
            b1 = 2 * (K * K - 1) * norm;
            b2 = (1 - K / Q + K * K) * norm;
            break;

        case OFX_BIQUAD_TYPE_HIGHPASS:
            norm = 1 / (1 + K / Q + K * K);
            a0 = 1 * norm;
            a1 = -2 * a0;
            a2 = a0;
            b1 = 2 * (K * K - 1) * norm;
            b2 = (1 - K / Q + K * K) * norm;
            break;

        case OFX_BIQUAD_TYPE_BANDPASS:
            norm = 1 / (1 + K / Q + K * K);
            a0 = K / Q * norm;
            a1 = 0;
            a2 = -a0;
            b1 = 2 * (K * K - 1) * norm;
            b2 = (1 - K / Q + K * K) * norm;
            break;

        case OFX_BIQUAD_TYPE_NOTCH:
            norm = 1 / (1 + K / Q + K * K);
            a0 = (1 + K * K) * norm;
            a1 = 2 * (K * K - 1) * norm;
            a2 = a0;
            b1 = a1;
            b2 = (1 - K / Q + K * K) * norm;
            break;

        case OFX_BIQUAD_TYPE_PEAK:
            if (peakGain >= 0) {    // boost
                norm = 1 / (1 + 1/Q * K + K * K);
                a0 = (1 + V/Q * K + K * K) * norm;
                a1 = 2 * (K * K - 1) * norm;
                a2 = (1 - V/Q * K + K * K) * norm;
                b1 = a1;
                b2 = (1 - 1/Q * K + K * K) * norm;
            }
            else {    // cut
                norm = 1 / (1 + V/Q * K + K * K);
                a0 = (1 + 1/Q * K + K * K) * norm;
                a1 = 2 * (K * K - 1) * norm;
                a2 = (1 - 1/Q * K + K * K) * norm;
                b1 = a1;
                b2 = (1 - V/Q * K + K * K) * norm;
            }
            break;
        case OFX_BIQUAD_TYPE_LOWSHELF:
            if (peakGain >= 0) {    // boost
                norm = 1 / (1 + sqrt(2) * K + K * K);
                a0 = (1 + sqrt(2*V) * K + V * K * K) * norm;
                a1 = 2 * (V * K * K - 1) * norm;
                a2 = (1 - sqrt(2*V) * K + V * K * K) * norm;
                b1 = 2 * (K * K - 1) * norm;
                b2 = (1 - sqrt(2) * K + K * K) * norm;
            }
            else {    // cut
                norm = 1 / (1 + sqrt(2*V) * K + V * K * K);
                a0 = (1 + sqrt(2) * K + K * K) * norm;
                a1 = 2 * (K * K - 1) * norm;
                a2 = (1 - sqrt(2) * K + K * K) * norm;
                b1 = 2 * (V * K * K - 1) * norm;
                b2 = (1 - sqrt(2*V) * K + V * K * K) * norm;
            }
            break;
        case OFX_BIQUAD_TYPE_HIGHSHELF:
            if (peakGain >= 0) {    // boost
                norm = 1 / (1 + sqrt(2) * K + K * K);
                a0 = (V + sqrt(2*V) * K + K * K) * norm;
                a1 = 2 * (K * K - V) * norm;
                a2 = (V - sqrt(2*V) * K + K * K) * norm;
                b1 = 2 * (K * K - 1) * norm;
                b2 = (1 - sqrt(2) * K + K * K) * norm;
            }
            else {    // cut
                norm = 1 / (V + sqrt(2*V) * K + K * K);
                a0 = (1 + sqrt(2) * K + K * K) * norm;
                a1 = 2 * (K * K - 1) * norm;
                a2 = (1 - sqrt(2) * K + K * K) * norm;
                b1 = 2 * (K * K - V) * norm;
                b2 = (V - sqrt(2*V) * K + K * K) * norm;
            }
            break;
    }

    return;
}
