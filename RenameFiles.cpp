//compile: g++ -std=c++11 Rename.cpp -o Rename.o

// System Heders
#include <string>
#include <vector>
#include <iostream>
#include <dirent.h>

using namespace std;

int main(int argc, char** argv)
{
  if(argc!=4)
  {
    cerr<<"./Rename.o <InputFolder> <FileFormat> <OutputFolder>"<<endl;
	  cerr<<"example: ./Rename.o /home/images png /home/images"<<endl;
	  exit(-1);
  }

  struct dirent **namelist;
	int n = scandir(argv[1], &namelist, 0, alphasort);
  if (n < 0)
  {
    perror("scandir");
  }
  else
  {
    int file = 1;
    string comparestrings;
    string format(argv[2]);
    char inputnamepath [300];
  	char outputnamepath[300];

		while(n--)
		{
			if( n>=2 )
			{
        comparestrings = namelist[n]->d_name;
        sprintf(inputnamepath,"%s/%s",argv[1],namelist[n]->d_name);
				if (comparestrings.find(format) != std::string::npos)
				{
					sprintf(outputnamepath, "%s/%d.%s",argv[3],file,argv[2]);
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

  return 0;
}
