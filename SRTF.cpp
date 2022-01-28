#include <bits/stdc++.h>
#include "SRTF.h"

using std::cout;
using std::endl;

std::vector<Node*>SRTFProcesses;


void Srtf::SchedulingAlgorithm(Node* Process)
{

    while(!SRTFProcesses.empty())
    {
        Node* copyhead = SRTFProcesses.front();
        Node* RunningNode = copyhead;

        for(auto it = SRTFProcesses.begin()+1 ; it < SRTFProcesses.end(); it++)
        {
            Node* node = *it;
            if( node->ArrivalTime <= node->CurrentTime && node->BurstTime < RunningNode->BurstTime)
                    RunningNode = node;
        }

        if(RunningNode!=copyhead)
            copyhead = RunningNode;
        else if(copyhead->ArrivalTime > copyhead->CurrentTime)
        {
            cout<<"system time<"<<copyhead->CurrentTime++<<"> "<<"<Idle State>"<<endl;
            copyhead->NumOfIdleState++;
            continue;
        }
        cout<<"system time<"<<copyhead->CurrentTime++<<"> "<<"Process Id<"<<copyhead->ProcessId<<"> "<<"is running"<<endl;

        if(copyhead->BurstTime != 0 && copyhead->ResponseTime ==0 && copyhead != copyhead->Head)
            copyhead->ResponseTime = copyhead->CurrentTime;

        copyhead->BurstTime--;

        if(copyhead->BurstTime == 0)
        {
            copyhead->ExitTime = copyhead->CurrentTime;

            auto it = std::find(SRTFProcesses.begin(),SRTFProcesses.end(),copyhead);
            SRTFProcesses.erase(it);
        }
    }
}
