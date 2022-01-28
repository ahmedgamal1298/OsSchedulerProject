#ifndef _ROUNDROBIN_H_

#define _ROUNDROBIN_
#include "Node.h"
class RoundRobin : public Scheduling
{

public:
    virtual void SchedulingAlgorithm(Node* Process)override;
    virtual ~RoundRobin()=default;
} ;


#endif // _ROUNDROBIN_H_
