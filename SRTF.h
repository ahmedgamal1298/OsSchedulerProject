#ifndef SRTF_H
#define SRTF_H
#include "Node.h"
class Srtf : public Scheduling
{

public:
    virtual void SchedulingAlgorithm(Node* Process)override;
    virtual ~Srtf()=default;
};


#endif // SRTF_H
