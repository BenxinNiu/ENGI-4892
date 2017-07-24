#include "EdgeListGraph.hxx"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeListGraph::EdgeListGraph(const VertexCollection& v,const EdgeCollection& e)
{
  myVertices= v;
  myEdges= e;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
VertexCollection EdgeListGraph::vertices() const
{
return myVertices;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::edges() const
{
  return myEdges;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
EdgeCollection EdgeListGraph::incidentEdges(const Vertex& v) const
{
  EdgeCollection result;
  for(int i=0; i<myEdges.size();i++)
    if(myEdges[i].contains(v))
    result.push_back(myEdges[i])；
  return result;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::areAdjacent(const Vertex& v, const Vertex& w) const
{
  bool adj=false;
  for(int i=0;i<myEdges.size()&&adj==false;i++)
    if(myEdges[i].contains(v)&&myEdges[i].contains(w))
    adj=true;
    return adj;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertVertex(const Vertex& v)
{
  bool existing=false;
  for(int i=0;i<myVertices.size()&&existing==false;i++)
  if(v==myVertices[i])
  existing=true;
  if(existing)
  return false;
  else
  myVertices.push_back(v);
  return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeVertex(const Vertex& v)
{
bool found=false;
for(int i=0;i<myVertices.size()&&found==false;i++)
  if(v==myVertices[i]){
  found=true;
  myVertices.erase(i);
  }
return found;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::insertEdge(const Edge& e)
{
  bool existing=false;
  for(int i=0;i<myEdges.size()&&existing==false;i++)
  if(e==myEdges[i])
  existing=true;
  if(existing)
  return false;
  else
  myEdge.push_back(v);
  return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool EdgeListGraph::removeEdge(const Edge& e)
{
  bool found=false;
  for(int i=0;i<myEdges.size()&&found==false;i++)
    if(v==myEdges[i]){
    found=true;
    myEdges.erase(i);
    }
  return found;
}
