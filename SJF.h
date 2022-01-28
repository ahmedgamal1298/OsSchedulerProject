#ifndef _SJF_H

#define _SJF_H
#include "Node.h"
class Sjf : public Scheduling
{

public:
    virtual void SchedulingAlgorithm(Node* Process )override;
    virtual ~Sjf()=default;

};




#endif // _SJF_H
