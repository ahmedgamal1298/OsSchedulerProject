#ifndef PRIORITYSCHEDULING_H

#define PRIORITYSCHEDULING_H
#include "Node.h"
class PriorityScheduling : public Scheduling
{

public:
    virtual void SchedulingAlgorithm(Node* Process)override;

};


#endif // PRIORITYSCHEDULING_H
