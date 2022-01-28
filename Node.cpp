#include "Node.h"

Node::~Node()
{
    delete NextNode;
    delete PrevNode;
}

Node* Node::Head = nullptr;
Node* Node::Tail = nullptr;
int Node::CurrentTime = 0;
int Node::quantum = 0;
double Node::OverallCpuUsage = 0;
int Node::NumOfIdleState = 0;
