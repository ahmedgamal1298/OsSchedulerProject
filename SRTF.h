#ifndef _SRTF_H_
#define _SRTF_H_
#include "Node.h"
class Srtf : public Scheduling
{

public:
    virtual void SchedulingAlgorithm(Node* Process)override;
    virtual ~Srtf()=default;
};


#endif // _SRTF_H_
