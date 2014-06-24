ofxBiquadFilter
===============
This is a simple addon to implement a biquad filter. Use it when you need to filter a value, for example smooth a input value over time. You can set it to filter out movements that have high frequency (lowpass filter), or make a highpassfilter that only lets fast movements through. 

This is a much better way to get nice smooth movements then running average, and much easier. 

For normal use, the only value that you need to change is the fc value. The fc value is the cutoff frequency, where 1 is the rate you supply new values. So for example, if you supply values 60 times a second (60 fps), then a fc value of 0.5 means the filter will cut off 30hz. 

Created by DZL (http://dzlsevilgeniuslair.blogspot.com/)  &  Jonas Jongejan (http://halfdanj.dk)

Example usage
===============
in the header:
```
ofxBiquadFilter2f filter;
```

in the cpp:
```
void setup(){
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
