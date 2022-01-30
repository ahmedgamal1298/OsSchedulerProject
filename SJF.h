#ifndef SJF_H

#define SJF_H
#include "Node.h"
class Sjf : public Scheduling
{

public:
    virtual void SchedulingAlgorithm(Node* Process )override;
    virtual ~Sjf()=default;

};




#endif // SJF_H
