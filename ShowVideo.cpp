// g++ -std=c++11 ShowVideo.cpp -o ShowVideo.o `pkg-config --cflags --libs opencv`

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
	if(argc!=2)
	{
	    cout<<"./program.o <pathVideoName.avi>"<<endl;
	    exit(-1);
	}
          
	// Initialize Variables
	Mat frame;
	int pp   = 0;
	int key  = 0;
	int cont = 0;
	
	// Run Video
	VideoCapture cap(argv[1]); 
	while( cap.read(frame) )
	{
		cont++;
		printf("Frame: %d\n",cont);
		
		imshow("Frame",frame);
		key = waitKey(pp);
		if(key=='p'){ if(pp==0){pp=30;} else{pp=0;} }
		else if(key==27){ return 0; }
	}
	return 0;
}
