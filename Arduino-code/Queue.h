#ifndef QUEUE_H
#define QUEUE_H

class Queue{

private:
float latestValues[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};


public:

void pushAndPop(float input);

float getAverage(float result);


};

#endif