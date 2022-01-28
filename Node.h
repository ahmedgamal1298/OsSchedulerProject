#ifndef _NODE_H
#define _NODE_H







class Node
{

private:
    static const constexpr int def = 0;

public:

    int ProcessId;
    int ArrivalTime;
    int BurstTime;
    int burst;
    int RemaningTime;

    double ResponseTime;
    double ExitTime;
    double TurnaroundTime;
    double WaitingTime;


    int priority;//in case of Priority scheduling algorithm
    Node*NextNode = nullptr;
    Node*PrevNode = nullptr;



    static Node*Head;
    static Node*Tail;
    static int CurrentTime;
    static int quantum;//in case of round robin algorithm
    static double OverallCpuUsage;
    static int NumOfIdleState;//for calculating CPU time

    Node(int passedId = def,int passedArrival = def,int passedBurst = def,int passedpriority = def,int passedquantum = def)
    :ArrivalTime(passedArrival),BurstTime(passedBurst),ProcessId(passedId),priority(passedpriority)
    {
        RemaningTime = BurstTime;
        burst = BurstTime;
        ResponseTime = 0.0;
        WaitingTime = 0.0;
        TurnaroundTime = 0.0;
        ExitTime = 0.0;

    }


    ~Node();

};

class Scheduling
{

public:
    virtual void SchedulingAlgorithm(Node* Process = nullptr)=0;
    virtual ~Scheduling()=default;
};


#endif // _NODE_H
