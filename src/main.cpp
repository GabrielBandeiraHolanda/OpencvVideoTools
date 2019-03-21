/**
 * @file main.cpp
 * @brief Implementation main method
 * @author $Author:$ Holanda, Gabriel Bandeira
 * @version $Revision:$
 * @date $Date:$ 21/03/2019
 */

// Opencv Heders
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
// System Heders
#include <string>
#include <vector>
#include <iostream>
#include <dirent.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
  if(argc<2){
    cout<<"\nVideoTools Methods: Rename, Image2Video, Video2Image, MergeVideos, ShowVideo and ChangeFPS is accepted !\n"<<endl;
    return -1;
  }
  string VideoToolsMethod(argv[1]);
  if( VideoToolsMethod=="Rename" ){
    if(argc!=5){
      cout<<"./VideoTools Rename <InputFolder> <FileFormat> <OutputFolder>"<<endl;
  	  cout<<"example: ./VideoTools /home/images png /home/images"<<endl;
  	  return -1;
    }

    struct dirent **namelist;
  	int n = scandir(argv[2], &namelist, 0, alphasort);
    if (n < 0){
      perror("scandir");
    }
    else{
      int file = 1;
      string comparestrings;
      string format(argv[3]);
      char inputnamepath [300];
    	char outputnamepath[300];
  		while(n--){
  			if( n>=2 ){
          comparestrings = namelist[n]->d_name;
          sprintf(inputnamepath,"%s/%s",argv[2],namelist[n]->d_name);
  				if (comparestrings.find(format) != std::string::npos){
  					sprintf(outputnamepath, "%s/%d.%s",argv[4],file,argv[3]);
  					printf("%s\n",inputnamepath);
  					printf("%s\n",outputnamepath);

  					rename(inputnamepath,outputnamepath);
  					file++;
  				}
          comparestrings.clear();
  			}
  			free(namelist[n]);
  		}
  		free(namelist);
  	}
  }
  else if( VideoToolsMethod== "Image2Video" ){
    if(argc!=7){
      cout<<"./VideoTools Image2Video <NumberOfInputImages> <InputFolder> <FileFormatOfInputImages> <OutputVideo> <FPSVideo>"<<endl;
	    cout<<"exemplo: ./VideoTools Image2Video 100 /home/Images png /home/video.avi 60"<<endl;
	    return -1;
	  }

    Mat frame;
	  char Path_ImgName[300];
	  int fps     = atoi(argv[6]);
    if( fps<=0 ){
      cout<<"ERROR invalid number to FPS"<<endl;
      return -1;
    }
	  int nimages = atoi(argv[2]);
	  sprintf(Path_ImgName,"%s/1.%s",argv[3],argv[4]);
	  frame = imread(Path_ImgName,1);
	  if(frame.empty()){
      cout<<"ERROR Image or Path, not found"<<endl;
      return -1;
    }

	  // Start Writing Process
	  VideoWriter vid(argv[5],CV_FOURCC('M','J','P','G'),fps,frame.size(),true);
	  for(int i=1;i<=nimages;i++){
      sprintf(Path_ImgName,"%s/%d.%s",argv[3],i,argv[4]);
      printf("Saving %s\n",Path_ImgName);
      frame = imread(Path_ImgName,1);
      vid.write( frame );
    }
    vid.release();
  }
  else if( VideoToolsMethod== "Video2Image" ){
    if(argc!=5){
      cout<<"./VideoTools Video2Image <InputVideo> <OutputPathImages> <ImageFormatOfOutputImages>"<<endl;
      cout<<"example: ./VideoTools Video2Image /home/video.avi /home/Imagens png"<<endl;
      return -1;
    }

    Mat frame;
    int cont = 0;
    char name[300];
    VideoCapture cap(argv[2]);
    while( cap.read(frame) ){
      if(frame.empty()){
        return -1;
      }
      cont++;
      sprintf(name,"%s/%d.%s",argv[3],cont,argv[4]);
      printf("Saved: %s\n",name);
      imwrite(name,frame);
    }
  }
  else if( VideoToolsMethod== "MergeVideos" ){
  	if(argc!=5){
      cout<<"./VideoTools MergeVideos <InputPthOfVideos> <NumberOfVideosForMerge> <OutputVideo>"<<endl;
      cout<<"example: ./VideoTools MergeVideos /home/InputVideos 3 home/OutputVideo.avi"<<endl;
  	  return -1;
  	}

  	// Configuration:
  	int nvideos = atoi(argv[3]);
  	char *path = argv[2];
  	char *newvideofile = argv[4];

  	// Start the video Union:
  	VideoWriter vid;
  	for(int i=1;i<=nvideos;i++){
  		char namefile[300]; sprintf(namefile,"%s%d.avi",path,i);
  		printf("%s\n",namefile);
  		Mat frame;
  		VideoCapture cap(namefile);
  		if( vid.isOpened()==false ){
  			cap.read(frame);
  			vid.open(newvideofile,CV_FOURCC('M','J','P','G'),cap.get(CV_CAP_PROP_FPS),frame.size(),true);
  		}
  		while(cap.read(frame)){
  			vid.write(frame);
  		}
  	}
  	vid.release();
  }
  else if( VideoToolsMethod== "ShowVideo" ){
    if(argc!=3)
    {
      cout<<"./VideoTools ShowVideo <InputPthOfVideo>"<<endl;
      cout<<"./VideoTools ShowVideo home/OutputVideo.avi"<<endl;
      return -1;
    }

     // Initialize Variables
     Mat frame;
     int pp   = 0;
     int key  = 0;
     int cont = 0;

     // Run Video
     VideoCapture cap(argv[2]);
     while( cap.read(frame) ){
       cont++;
       printf("Frame: %d\n",cont);

       imshow("Frame",frame);
       key = waitKey(pp);
       if(key=='p'){ if(pp==0){pp=30;} else{pp=0;} }
       else if(key==27){ return 0; }
     }
  }
  else if( VideoToolsMethod== "ChangeFPS" ){
    //=== ARGS ===
  	if(argc!=5){
  		cout<<"./VideoTools ChangeFPS <InputVideoPath> <OutputVideoPath> <OutputVideoFPS>"<<endl;
  		cout<<"example: ./VideoTools ChangeFPS home/input.avi home/output.avi 60"<<endl;
  		return -1;
  	}
  	// Configuration:
  	int FPS = atoi(argv[4]);
  	char *oldvideo = argv[2];
  	char *newvideo = argv[3];

    printf("Wait Converting Video '%s', if big video maybe take a while...\n",argv[2]);
  	// Start ChangeFPS
  	Mat frame;
  	VideoWriter vid;
  	VideoCapture cap(oldvideo);
  	cap.read(frame);
  	vid.open(newvideo, CV_FOURCC('M','J','P','G'), FPS, frame.size(), true);
  	vid.write(frame);
  	while(cap.read(frame)){
  		vid.write(frame);
  	}
  	vid.release();
  }
  else{
    cout<<"Only methods: Rename, Image2Video, Video2Image, MergeVideos, ShowVideo and ChangeFPS is accepted !!"<<endl;
    return -1;
  }

  return 0;
}
