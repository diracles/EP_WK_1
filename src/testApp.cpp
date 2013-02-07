#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    player.loadMovie("mina.mp4");
    player.play();
    player.setLoopState(OF_LOOP_NONE);
    
    currFrame.allocate(player.getWidth(), player.getHeight(), OF_IMAGE_COLOR_ALPHA);
    
    alpha = 255;
    walker = 0;

    
}

//--------------------------------------------------------------
void testApp::update(){
    player.setFrame(mouseX);
    player.update();
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    /*
     int sampleX = ofClamp(mouseX,0,player.getWidth()-1);
     int sampleY =  ofClamp(mouseY,0,player.getHeight()-1);
     
     
     ofColor sample = player.getPixelsRef().getColor(sampleX, sampleY);
     ofBackground(sample);
     ofSetColor(255,0,255,128);
     */
    
    
    player.draw(0, 0);
    
    currFrame.draw(5, 5);
    ofSetColor(255,0,255,128);
    
    ofSetLineWidth(10);
    //ofEllipse(float walker, y, 10, 10)
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == ' '){
        if(player.isPlaying()){
            player.stop();
        }
        else {
            player.play();
        }
    }
    else if (key == OF_KEY_DOWN){
        unsigned char* pixels = currFrame.getPixels();
        for (int y = 0; y < currFrame.getHeight(); y++) {
            for (int x = 0; x < currFrame.getWidth(); x++) {
                int loc = y*currFrame.getWidth() + x;
                int r = pixels[loc];
                int g = pixels[loc+1];
                int b = pixels[loc+2];
                int a = pixels[loc + 3];
                a = 100;
                
                currFrame.update();
            }
        }
        
    }
    player.getPixelsRef().getColor(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
      for (int i=0; i<25; i++) {
     currFrame.setFromPixels(player.getPixelsRef());
          player.nextFrame();
        
    }
 
    
    //frames.push_back(currFrame);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}





