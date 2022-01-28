#include "FCFS.h"

void Fcfs::SchedulingAlgorithm(Node* Process )
{

    Process->Tail->NextNode = Process;
    Process->PrevNode = Process->Tail;
    Process->Tail = Process;

}
