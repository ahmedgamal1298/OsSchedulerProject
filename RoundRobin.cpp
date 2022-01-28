#include <bits/stdc++.h>
#include "RoundRobin.h"

using std::cout;
using std::endl;
using std::for_each;

std::deque<Node*>RRQueue;
std::vector<Node*>AllProcesses;


void CheckArrivedProcceses()
{
    for_each(AllProcesses.begin(),AllProcesses.end(),[&](Node* elem){
                auto it = std::find(RRQueue.begin(),RRQueue.end(),elem);
                if(elem->ArrivalTime <= elem->CurrentTime && elem->BurstTime != 0 && elem != *it)
                    RRQueue.push_back(elem);
             });
}

void RoundRobin::SchedulingAlgorithm(Node* Process )
{
    RRQueue.push_back(AllProcesses.front());
    Node* FirstNode = RRQueue.front();

    while(!RRQueue.empty())
    {

        CheckArrivedProcceses();
        Node* node = RRQueue.front();

        if(node->ArrivalTime > node->CurrentTime)
        {
            if(FirstNode == node)
            {
                cout<<"system time<"<<node->CurrentTime++<<"> "<<"<Idle State>"<<endl;
                node->NumOfIdleState++;
            }
            continue;
        }

        if(node->BurstTime != 0 && node->ResponseTime ==0 && node != node->Head)
            node->ResponseTime = node->CurrentTime - node->ArrivalTime;

        for(int i = 0 ; i < node->quantum ;i++)
        {

            cout<<"system time<"<<node->CurrentTime++<<"> "<<"Process Id<"<<node->ProcessId<<"> "<<"is running"<<endl;
            CheckArrivedProcceses();

            node->BurstTime--;
            if(node->BurstTime == 0)
                break;
        }
        RRQueue.pop_front();
        if(node->BurstTime == 0)
        {
            node->ExitTime = node->CurrentTime;
            continue;
        }
        else
            RRQueue.push_back(node);
    }
}
