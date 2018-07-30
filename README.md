# OpencvVideoTools
Video manipulation repository, using Opencv library

This repository provides video manipulation tools based on the Opencv library with C/C++ language.

* Requirements

  - SO -> Linux Ubuntu
  - Programming Language -> C/C++
  - LIB -> Opencv

  

- Image2Video

	Tool to convert a list of images to video. Follow the steps below to use this Tool:

	- 1: Compile on terminal using the command: g++ -std=c++11 Image2Video.cpp -o Image2Video.o `pkg-config --cflags --libs opencv`
    - 2: Images need have sequence starting with 1.png 2.png ... n.png
	- 3: To run, enter in folder and type in the terminal:
	
		EXAMPLE: ./image2video.o 100 '/home/Imagens' png /home/video.avi 3
		
		./image2video.o A B C D E
	    
		-A: Number of images, to convert in videos. 
	    -B: Path of images  
	    -C: Image file formats 
	    -D: Name Of Video
	    -E: Video FPS
	
	- 4: Limitations, images must be in numerical sequence starting with 1, only images in (.png) or (.jpg) are supported and only (.avi) video format is supported.
