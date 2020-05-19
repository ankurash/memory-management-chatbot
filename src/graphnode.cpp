#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) //pointer  -> unique pointer
{
    _childEdges.push_back(std::move(edge)); //move
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot) //pointer -> instance
{
    _chatBot = std::move(chatbot); //
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot)); //move instead of copy
    //_chatBot = nullptr; // invalidate pointer at source;; not required after move
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get(); //since unique pointers

    ////
    //// EOF STUDENT CODE
}