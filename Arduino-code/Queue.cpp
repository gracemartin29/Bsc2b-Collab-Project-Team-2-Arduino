#include "Queue.h"

void Queue::pushAndPop(float input){

  for(int i = 0; i < 9; i++){
    latestValues[i] = latestValues[i + 1];
  }

  latestValues[9] = input;

}


float Queue::getAverage(){

  float temp = 0.0;
  float result = 0.0;

  for(int i = 0; i < 10; i++){
    temp = temp + latestValues[i];
  }

  result = temp / 10;

  return result;


}