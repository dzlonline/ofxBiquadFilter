## ofxBiquadFilter

This openFrameworks addon implements a biquad filter. Use it when you need to filter a value over time. You can set it to filter out high frequancy noise (lowpass filter), this could for example be fast mouse movements, or other noisy data. Or you can use it as a highpassfilter that only will let fast movements through, this could for example be used to detect abrupt changes in a value. 

## Usage
For normal use, the only value that you need to change is the `fc` value. This describes the cutoff frequency, where 1 is the rate you supply new values. So for example, if you supply values 60 times a second (60 fps), then a fc value of 0.5 means the filter will cut off 30hz. 

The addon comes with filters that supports both 1d, 2d 3d and 4d vectors, and it can also work of ofFloatColors. The types are 

- `ofxBiquadFilter1f`
- `ofxBiquadFilter2f`
- `ofxBiquadFilter3f`
- `ofxBiquadFilter4f`
- `ofxBiquadFilterColor`
 
The type of the filter can be set with the command `.setType(ofxBiquadFilterType type)`. The most commonly used filter types are the `OFX_BIQUAD_TYPE_LOWPASS` (default) and `OFX_BIQUAD_TYPE_HIGHPASS`, but there are other types of filters defined. 

Call `update(..)` with the new input value to update the filter, and get the filtered value by calling `value()`.

## Example

in the header:
``` cpp
ofxBiquadFilter2f filter;
```

in the cpp:
``` cpp
void setup(){
  // Sets the cutoff frequency to 1/10 of the framerate
  // Lowering this value will make the circle move slower
  filter.setFc(0.1);  
}

void update(){
  //Update the filter
  filter.update(ofVec2f(mouseX,mouseY));
}

void draw(){
  ofCircle(filter.value().x, filter.value().y);
}

```



*Created by  [Jonas Jongejan](http://halfdanj.dk) and [DZL](http://dzlsevilgeniuslair.blogspot.com/)*
