// g++ -std=c++11 Image2Video.cpp -o Image2Video.o `pkg-config --cflags --libs opencv`

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
	  if(argc!=6)
	  {
	    //cout<<"./image2video.o <A> <B> <C> <D> <E>"<<endl;
	    //cout<<"A -> Numero De Imagens (As Imagens devem estar em sequencia numerica iniciando com 1)"<<endl;
	    //cout<<"B -> Caminho Da Pasta Das Imagens (So é suportado imagens em (.png) ou (.jpg))"<<endl;
	    //cout<<"C -> Formato Das Imagens"<<endl;
	    //cout<<"D -> Nome Do Video Com Formato .avi (So é suportado salvar o video em (.avi))"<<endl;
	    //cout<<"E -> FPS Do Video"<<endl;
	    cout<<"exemplo: ./image2video.o 100 '/home/Imagens' png /home/video.avi 3"<<endl;
	    exit(-1);
	  }

	  // Initialize Variables
	  Mat frame;
	  char Path_ImgName[300];

	  // Setup
	  int fps     = atoi(argv[5]); if( fps<=0 ){ cout<<"ERROR invalid number to FPS"<<endl; exit(-1); }
	  int nimages = atoi(argv[1]);
	  sprintf(Path_ImgName,"%s/1.%s",argv[2],argv[3]);
	  frame = imread(Path_ImgName,1);
	  if( frame.empty() ){ cout<<"ERROR Image or Path, not found"<<endl; exit(-1);}

	  // Start Writing Process
	  VideoWriter vid(argv[4],CV_FOURCC('M','J','P','G'),fps,frame.size(),true);
	  for(int i=1;i<=nimages;i++)
	  {
		sprintf(Path_ImgName,"%s/%d.%s",argv[2],i,argv[3]);
		printf("Saving %s\n",Path_ImgName);

		frame = imread(Path_ImgName,1);
		vid.write( frame );
	  }
	  vid.release();
	  return 0;
}
