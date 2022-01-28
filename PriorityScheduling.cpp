#include "PriorityScheduling.h"

void PriorityScheduling::SchedulingAlgorithm(Node* Process)
{
    Node* copyhead = Process->Head;
    while(copyhead != nullptr)
    {
        if( Process->ArrivalTime <= copyhead->ArrivalTime )
        {
            if(Process->ArrivalTime < copyhead->ArrivalTime || Process->priority > copyhead->priority || ( Process->priority == copyhead->priority && Process->ProcessId > copyhead->ProcessId  ) )
            {
                Process->NextNode = copyhead;
                Process->PrevNode = copyhead->PrevNode;
                if(copyhead->PrevNode != nullptr)copyhead->PrevNode->NextNode = Process;
                copyhead->PrevNode = Process;
                if(Process->NextNode == Process->Head)copyhead->Head = Process;
                break;
            }
            else if( Process->priority <= copyhead->priority || ( Process->priority == copyhead->priority  && Process->ProcessId <= copyhead->ProcessId   ))
            {
                 Process->NextNode = copyhead->NextNode;
                 Process->PrevNode = copyhead;
                 if(copyhead->NextNode != nullptr)
                    copyhead->NextNode->PrevNode = Process;
                 copyhead->NextNode = Process;
                 break;
            }
        }
        else
        {
            if(copyhead->NextNode == nullptr)
            {
                copyhead->NextNode = Process;
                Process->PrevNode = copyhead;
                break;
            }
            copyhead = copyhead->NextNode;
        }
    }
}
