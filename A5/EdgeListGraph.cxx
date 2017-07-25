#include "EdgeListGraph.hxx"
#include <vector>
using namespace std;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeListGraph::EdgeListGraph(const VertexCollection& v,const EdgeCollection& e)
{
  myVertices= v;   // initialize all vertices in the graph
  myEdges= e;     //  initialize all edges in the graph
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
VertexCollection EdgeListGraph::vertices() const
{
    return myVertices;  // access private member
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::edges() const
{
  return myEdges;  // access private member
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::incidentEdges(const Vertex& v) const
{
  EdgeCollection result;      // the vector which contains all incident edges to v
  for(int i=0; i<myEdges.size();i++)   // traverse the vector that contains edges
    if(myEdges[i].contains(v))         // if vertext "v" is in this edeg
    result.push_back(myEdges[i]);      // then push it to result vector
  return result;    // return result
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::areAdjacent(const Vertex& v, const Vertex& w) const
{
  bool adj=false; // boolean value indicate whether two vertex are are adjacent
  for(int i=0;i<myEdges.size()&&adj==false;i++)   // traverse the vector that contains edges
    if(myEdges[i].contains(v)&&myEdges[i].contains(w)) //if this edge contains both vertext "v" and "w"
    adj=true;      // set bool to true which exits the loop
    return adj;    // return result, if adjacent adj is ture otherwise adj remain unchanged( false )
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertVertex(const Vertex& v)
{
  bool existing=false;   //boolean value indicate whether this vertex already exists
  for(int i=0;i<myVertices.size()&&existing==false;i++) // traverse the vector that contains all vertex in graph
  if(v==myVertices[i])  // if vertex "v" already exists
  existing=true;  // set true   exit loop
  if(existing)    // insert failed because "v" already exists
  return false;
  else
  myVertices.push_back(v);  // else insert "v"
  return true;     // success
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeVertex(const Vertex& v)
{
  bool found=false;     //boolean value indicate whether the vertex has been found
  EdgeCollection del;   // vector that temporarily hold all edges which contains the vertext that is to be deleted
  for(int i=0;i<myVertices.size()&&found==false;i++) // travese the vector that contains all vertex
    if(v==myVertices[i]){    // found it
    found=true;             // set it to true  cause exiting loop
    myVertices.erase(myVertices.begin()+i);  // delete this vertex from the vector
    }
  if(found){          // deletion happened
  for(int j=0;j<myEdges.size();j++)  //travese the vector that contains all edges
    if(myEdges[j].contains(v))   // if this edge contains the vertex that was deleted
    del.push_back(myEdges[j]);   // record this edge in a vector for later processing
  for(int j=0;j<del.size();j++)  // delete all edges stored in this vector from "myEdge" vector
  removeEdge(del[j]);            // this loop essentially remove edges that contains the vertext that we wish to delete
}
  return found;         // return result,  if vertext is not found in vector "found" remains unchanged
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertEdge(const Edge& e)
{
  bool existing=false; //boolean value indicate whether this edge already exists
  for(int i=0;i<myEdges.size()&&existing==false;i++) // traverse the vector that contains all edges in graph
  if(e==myEdges[i])    // if this "e" already exists
  existing=true;       // set it to true  cause exiting loop
  if(existing)
  return false;   // insert failed as it already exists
  else{                   //otherwise begin insertion
  myEdges.push_back(e);   // insert new edge
  for(int i=0; i<myVertices.size(); i++)  // this loop checks if the new edge brings any new vertex to the graph
    if(!e.contains(myVertices[i])){   // the edge "e" contains new vertex that does NOT exist in myVertices vector
    insertVertex(e.endVertices()[0]);   // insert new vertex
    insertVertex(e.endVertices()[1]);   // for simplicity, both vertext in egde "e" are inserted.
                                        // it is safe to do so because insertVertex function checks for existing vertex
  }
  return true;
}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeEdge(const Edge& e)
{
  bool found=false;   //boolean value indicate whether the edge has been found
  for(int i=0;i<myEdges.size()&&found==false;i++) // traverse the vector that contains all edges in graph
    if(e==myEdges[i]){    // found it!
    found=true;        // set boolean to true   cause exiting loop after deletion
    myEdges.erase(myEdges.begin()+i);  // delete this edge from graph
    }
  return found;   // return result,  if "e" not found which indicates fail, "found" remains unchanged(false)
                      // otherwise "found" was set to true in the loop
}
