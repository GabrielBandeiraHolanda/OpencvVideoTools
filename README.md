# Opencv Video Tools
Video manipulation repository, using Opencv library

## Getting Started
This repository provides video manipulation tools based on the Opencv library with C/C++ language.

### Prerequisites

  - SO -> Linux Ubuntu
  - Programming Language -> C/C++
  - LIB -> Opencv

### Image2Video
Tool to convert a list of images to video. Follow the steps below to use this Tool:

- 1: Using the terminal enter in repository folder and type the command:  

		g++ -std=c++11 Image2Video.cpp -o Image2Video.o `pkg-config --cflags --libs opencv`
- 2: Images need have sequence starting with 1.png 2.png ... n.png
- 3: To run, type in the terminal:
		
		./image2video.o 100 '/home/Imagens' png /home/video.avi 3
		./image2video.o  A        B          C         D        E
  A = Number of images, B = Path of images, C = Image file format, D = Output Video Name, E = Video FPS

- 4: Limitations, images must be in numerical sequence starting with 1, only images in (.png) or (.jpg) are supported and only (.avi) video format is supported.

### Video2Image
Tool to generate a list of images, from a video file. Follow the steps below to use this Tool:

- 1: Using the terminal enter in repository folder and type the command: 

		g++ -std=c++11 Video2Image.cpp -o Video2Image.o `pkg-config --cflags --libs opencv`
- 2: To run, type in the terminal:
		
		./video2image.o /home/video.avi /home/Imagens png
		./image2video.o  	A              B       C
  A = Input Video Path, B = Path that images will be saved, C = Image file format

- 3: Images are saved in sequence starting with 1.png 2.png ... n.png
- 4: Limitations, only images in (.png) or (.jpg) are supported and only (.avi) video format is supported.

### ShowVideo
Tool to show a video file. Follow the steps below to use this Tool:

- 1: Using the terminal enter in repository folder and type the command: 

		g++ -std=c++11 ShowVideo.cpp -o ShowVideo.o `pkg-config --cflags --libs opencv`
- 2: To run, type in the terminal:
		
		./ShowVideo.o /home/video.avi
		./ShowVideo.o  	     A       
  A = Input Video

- 3: Press 'p', to control the video actions start and pause. If you want to quit the video, press 'Esc'. 


	    
