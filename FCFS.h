#ifndef _FCFS_H
#define _FCFS_H
#include "Node.h"

class Fcfs : public Scheduling
{

public:
     virtual void SchedulingAlgorithm(Node* Process)override;
     virtual ~Fcfs()=default;

};


#endif // _FCFS_H
