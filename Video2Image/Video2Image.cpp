// g++ -std=c++11 Video2Image.cpp -o Video2Image.o `pkg-config --cflags --libs opencv`

// Opencv Heders
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
// System Heders
#include <string>
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char *argv[])
{
	//=== ARGS ===
	if(argc!=4)
	{
	    //cout<<"./video2image.o <pathVideoName.avi> <pathimages> <imagestype>"<<endl;
	    cout<<"example: ./video2image.o /home/video.avi /home/Imagens png"<<endl;
	    exit(-1);
	}
        
	// Initialize Variables  
	Mat frame;
	
	// Setup
	int cont = 0;
	char name[300];
	VideoCapture cap(argv[1]); 
	while( cap.read(frame) )
	{
		if(frame.empty()){ exit(-1); }
		cont++;
		sprintf(name,"%s/%d.%s",argv[2],cont,argv[3]);
		printf("Saved: %s\n",name);
		imwrite(name,frame);
	}
	return 0;
}
