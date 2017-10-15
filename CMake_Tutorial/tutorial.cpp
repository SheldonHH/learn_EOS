// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
int main (int argc, char *argv[]) // argc 代表命令行的input variable个数，argv代表input variable的array
{
  if (argc < 2)
    {
    fprintf(stdout,"Usage: %s number\n",argv[0]); // write formated data into stream
    return 1; 
    }

  double inputValue = atof(argv[1]); // 把string 转换成double
  // boost函数，我们会将用lexical_cast，使转换更加简洁

  double outputValue = sqrt(inputValue); 
  fprintf(stdout,"The square root of %g is %g\n", inputValue, outputValue);
  return 0;
}