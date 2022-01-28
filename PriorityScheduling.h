#ifndef _PRIORITYSCHEDULING_H_

#define _PRIORITYSCHEDULING_H_
#include "Node.h"
class PriorityScheduling : public Scheduling
{

public:
    virtual void SchedulingAlgorithm(Node* Process)override;

};


#endif // _PRIORITYSCHEDULING_H_
