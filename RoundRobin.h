#ifndef ROUNDROBIN_H

#define ROUNDROBIN_H
#include "Node.h"
class RoundRobin : public Scheduling
{

public:
    virtual void SchedulingAlgorithm(Node* Process)override;
    virtual ~RoundRobin()=default;
} ;


#endif // ROUNDROBIN_H
