#ifndef FCFS_H
#define FCFS_H
#include "Node.h"

class Fcfs : public Scheduling
{

public:
     virtual void SchedulingAlgorithm(Node* Process)override;
     virtual ~Fcfs()=default;

};


#endif // FCFS_H
