/****************************************************************************************************
*                       OS SCHEDULER PROJECT                                                        *
*                       Created By AHMED GAMAL                                                      *
*                           23 JAN 2022                                                             *
* THIS PROJECT IS USED TO IMPLEMENT PRIORITY,ROUND ROBIN,SJF,SRTF AND FCFS SCHEDULING ALGORITHMS    *
*                                                                                                   *
*****************************************************************************************************/


#include <bits/stdc++.h>
#include "Node.h"
#include "PriorityScheduling.h"
#include "RoundRobin.h"
#include "SRTF.h"
#include "SJF.h"
#include "FCFS.h"

using namespace std;


enum Algorithms{FCFS,RR,SJF,PRIORITY_SCHEDULING,SRTF};
Algorithms TYPE = RR;


extern vector<Node*>SRTFProcesses;//used for SRTF algorithm
extern vector<Node*>AllProcesses;

vector<Node*>Queue;
int N{0};//number of processes

Node* AddProcess()
{
    int id,arrival,burst,priority;

    cout<<"Enter process Id,Arrival time ,Burst time";
    (TYPE==PRIORITY_SCHEDULING)? cout<<",priority" :cout<<" ";
    cout<<":: Enter -1 to exit: ";

    cin>>id;

    while(id != -1)
    {
        cin>>arrival>>burst;
        if(TYPE == PRIORITY_SCHEDULING)cin>>priority;

        Node* Process = new Node(id,arrival,burst,priority);


        ++N;
        if(!Process->Head)
        {
            Process->Head = Process;
            Process->Tail = Process->Head;
            AllProcesses.push_back(Process);
            if(TYPE == SRTF)SRTFProcesses.push_back(Process);
        }
        else
        {
            switch(TYPE)
            {
                case FCFS:
                {
                    AllProcesses.push_back(Process);
                    Scheduling* FCFS_O = new Fcfs();
                    FCFS_O->SchedulingAlgorithm(Process);
                    break;
                }
                case SJF:
                {
                    AllProcesses.push_back(Process);
                    Scheduling* SJF_O = new Sjf();
                    SJF_O->SchedulingAlgorithm(Process);
                    break;
                }
                case PRIORITY_SCHEDULING:
                {
                    AllProcesses.push_back(Process);
                    Scheduling* PriorityScheduling_O = new PriorityScheduling();
                    PriorityScheduling_O->SchedulingAlgorithm(Process);
                    break;
                }
                case RR:
                    AllProcesses.push_back(Process);
                    break;
                case SRTF:
                    SRTFProcesses.push_back(Process);
                    break;
            }
        }

        cout<<"Enter process Id,Arrival time ,Burst time";
        (TYPE==PRIORITY_SCHEDULING)? cout<<",priority" :cout<<" ";
        cout<<":: Enter -1 to exit: ";
        cin>>id;
    }
    if(TYPE == RR && N!=0)
    {
        cout<<"Enter Quantum : ";
        cin>>Node::quantum;
    }
    Queue =  (TYPE == SRTF) ? SRTFProcesses : AllProcesses;
    return Node::Head;
}

void OS_RunningProcceses(Node* head)
{
    if(head == nullptr)return;
    if(TYPE == FCFS || TYPE == PRIORITY_SCHEDULING || TYPE == SJF)
    {
        Node* copyhead = head;
        while(copyhead != nullptr)
        {
            if(TYPE == PRIORITY_SCHEDULING || TYPE == SJF)
            {
                Node* node = copyhead->NextNode;

                Node* min_node = copyhead;

                while(node != nullptr)
                {
                    if( node->ArrivalTime <= node->CurrentTime && (   ( (TYPE == PRIORITY_SCHEDULING)? node->priority >copyhead->priority : node->BurstTime <copyhead->BurstTime) ) )
                    {
                        min_node = node;
                        break;
                    }
                    else
                        node = node->NextNode;
                }
                if( min_node != copyhead )
                {
                    min_node->PrevNode->NextNode = min_node->NextNode;
                    if(min_node->NextNode != nullptr)min_node->NextNode->PrevNode = min_node->PrevNode;
                    min_node->NextNode = copyhead;
                    min_node->PrevNode = copyhead->PrevNode;
                    copyhead->PrevNode->NextNode = min_node;
                    copyhead->PrevNode = min_node;
                    copyhead = min_node;
                }
            }

            if(copyhead->ArrivalTime > copyhead->CurrentTime )
            {
                cout<<"system time<"<<copyhead->CurrentTime++<<"> "<<"<Idle State>"<<endl;
                copyhead->NumOfIdleState++;
                continue;
            }
            if(copyhead->BurstTime != 0 && copyhead->ResponseTime ==0 && copyhead != copyhead->Head)
                copyhead->ResponseTime = copyhead->CurrentTime;


            for(int i = 0; i < copyhead->BurstTime ; i++)
            {
                cout<<"system time<"<<copyhead->CurrentTime++<<"> "<<"Process Id<"<<copyhead->ProcessId<<"> "<<"is running"<<endl;
                copyhead->RemaningTime--;
            }

            if(copyhead->RemaningTime == 0 )
                copyhead->ExitTime = copyhead->CurrentTime;

            copyhead = copyhead->NextNode;
        }
    }
    else if(TYPE == SRTF)
    {
        Scheduling* SRTF_O = new Srtf();
        SRTF_O->SchedulingAlgorithm();
    }
    else if(TYPE == RR)
    {
        Scheduling* RR_O = new RoundRobin();
        RR_O->SchedulingAlgorithm();
    }
}

void GetStatisticalInformation()
{
  if(N==0)return;
  double AverageResponseTime {0.0};
  double AverageWaitingTime {0.0};
  double AverageTurnaroundTime {0.0};

  std::for_each(Queue.begin(),Queue.end(),[&](Node* elem)
                {
                    AverageResponseTime += elem->ResponseTime;
                    elem->TurnaroundTime =elem->ExitTime - elem->ArrivalTime ;
                    AverageWaitingTime += elem->TurnaroundTime - elem->burst;
                    AverageTurnaroundTime += elem->TurnaroundTime;
                });
                Node::OverallCpuUsage = ( (Node::CurrentTime - Node::NumOfIdleState) / static_cast<double>(Node::CurrentTime) )*100;

                AverageResponseTime /= N;
                AverageWaitingTime /= N;
                AverageTurnaroundTime /= N;

                cout<<endl<<"Average CPU Usage : "<<Node::OverallCpuUsage<<"%"<<endl;
                cout<<"Average Waiting Time : "<<AverageWaitingTime<<endl;
                cout<<"Average Response Time : "<<AverageResponseTime<<endl;
                cout<<"Average Turnaround Time : "<<AverageTurnaroundTime<<endl;
}
int main()
{
    Node* head = AddProcess();
    OS_RunningProcceses(head);
    GetStatisticalInformation();

    return 0;
}

