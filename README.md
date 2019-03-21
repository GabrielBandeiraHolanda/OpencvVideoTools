# Opencv Video Tools
Video manipulation repository, using Opencv library

## Getting Started
This repository provides video manipulation tools based on the Opencv library with C/C++ language.

### Prerequisites

  - SO -> Linux Ubuntu
  - Programming Language -> C/C++
  - LIB -> Opencv

### Installation
- 1: Using the terminal enter in repository folder and type the command:
		make clean
		make

### ChangeVideoFPS
Tool to change FPS of a Video. Follow the steps below to use this Tool:

- 1: To run, type in the terminal:
		
		./VideoTools ChangeFPS <InputVideoPath> <OutputVideoPath> <OutputVideoFPS>
		./VideoTools ChangeFPS home/input.avi home/output.avi 60

- 2: Limitations, only (.avi) and (.mp4) video format is supported.

### Image2Video
Tool to convert a list of images to video. Follow the steps below to use this Tool:

- 1: Images need have sequence starting with 1.png 2.png ... n.png
- 2: To run, type in the terminal:
		
		./VideoTools Image2Video <NumberOfInputImages> <InputFolder> <FileFormatOfInputImages> <OutputVideo> <FPSVideo>
		./VideoTools Image2Video 100 /home/Images png /home/video.avi 60

- 3: Limitations, images must be in numerical sequence starting with 1, only images in (.png) or (.jpg) are supported and only (.avi) video format is supported.

### Video2Image
Tool to generate a list of images, from a video file. Follow the steps below to use this Tool:

- 1: To run, type in the terminal:
		
		./VideoTools Video2Image <InputVideo> <OutputPathImages> <ImageFormatOfOutputImages>
		./VideoTools Video2Image /home/video.avi /home/Imagens png

- 2: Images are saved in sequence starting with 1.png 2.png ... n.png
- 3: Limitations, only images in (.png) or (.jpg) are supported and only (.avi) video format is supported.

### ShowVideo
Tool to show a video file. Follow the steps below to use this Tool:

- 1: To run, type in the terminal:
		
		./VideoTools ShowVideo <InputPthOfVideo>
		./VideoTools ShowVideo home/OutputVideo.avi      

- 2: Press 'p', to control the video actions start and pause. If you want to quit the video, press 'Esc'.

### MergeVideos
Tool to merge a list of videos. Follow the steps below to use this Tool:

- 1: To run, type in the terminal:
		
		./VideoTools MergeVideos <InputPthOfVideos> <NumberOfVideosForMerge> <OutputVideo>
		./VideoTools MergeVideos /home/InputVideos 3 home/OutputVideo.avi

- 2: Limitations, videos must be in numerical sequence starting with 1 and only (.avi) video format is supported.

### RenameFiles
Extra Tool, that rename a multiple files contained in a folder starting with 1 to N. This tool automatic list all 
files contained in Iput Folder that have the specified File Format, and rename all using numeric order starting 
with 1 to N. Example: 1.png, 2.png, ..., N.png. Follow the steps below to use this Tool:

- 1: To run, type in the terminal:
		
	  	./VideoTools Rename <InputFolder> <FileFormat> <OutputFolder>
		./VideoTools Rename /home/images png /home/images
 
- 2: Any format is supported for example: png, jpg, PDF, avi. 
- 3: Output folder can be the same as input folder. 


	    
