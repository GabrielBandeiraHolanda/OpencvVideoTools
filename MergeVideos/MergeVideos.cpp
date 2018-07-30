// g++ -std=c++11 MergeVideos.cpp -o MergeVideos.o `pkg-config --cflags --libs opencv`

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
	    //cout<<"./videounion.o <PathAVIfiles> <nvideos> <aviVideoName.avi>"<<endl;
		cout<<"example: ./videounion.o /home 3 home/teste.avi"<<endl;
	    exit(-1);
	}

	// Configuration:
	int nvideos = atoi(argv[2]);
	char *path = argv[1];
	char *newvideofile = argv[3];

	// Start the video Union:
	VideoWriter vid;
	for(int i=1;i<=nvideos;i++)
	{
		char namefile[300]; sprintf(namefile,"%s%d.avi",path,i);
		printf("%s\n",namefile);
		Mat frame;
		VideoCapture cap(namefile);
		if( vid.isOpened()==false )
		{
			cap.read(frame);
			vid.open(newvideofile,CV_FOURCC('M','J','P','G'),cap.get(CV_CAP_PROP_FPS),frame.size(),true);
		}
		while(cap.read(frame))
		{
			vid.write(frame);
		}
	}
	vid.release();
    return 0;
}







