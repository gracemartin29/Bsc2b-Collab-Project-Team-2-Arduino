#ifndef QUEUE_H
#define QUEUE_H

//class to calculate average current out of latest 10 readings
class Queue{

private:
float latestValues[10] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};


public:

void pushAndPop(float input);

float getAverage();


};

#endif