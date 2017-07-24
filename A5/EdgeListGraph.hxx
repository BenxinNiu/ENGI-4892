#ifndef __EDGE_LIST_GRAPH_HXX_
#define __EDGE_LIST_GRAPH_HXX_

#include "Graph.hxx"

class EdgeListGraph : public Graph
{
  public:
    /** Create a graph without any vertices or edges. */
    EdgeListGraph() { }

    /** Create a graph containing the specified vertices and edges. */
    EdgeListGraph(const VertexCollection& v, const EdgeCollection& e);

    /** Return an iterable collection of all the vertices of the graph. */
    VertexCollection vertices() const;

    /** Return an iterable collection of all the edges of the graph. */
    EdgeCollection edges() const;

    /** Return an iterable collection of the edges incident upon vertex v. */
    EdgeCollection incidentEdges(const Vertex& v) const;

    /** Test whether vertices v and w are adjacent. */
    bool areAdjacent(const Vertex& v, const Vertex& w) const;

    /** Insert a new vertex, return success or failure. */
    bool insertVertex(const Vertex& v);

    /** Remove vertex v and all incident edges, return success or failure. */
    bool removeVertex(const Vertex& v);

    /** Insert a new edge, return success or failure. */
    bool insertEdge(const Edge& e);

    /** Remove edge e, return success or failure. */
    bool removeEdge(const Edge& e);

  private:
    VertexCollection myVertices;
    EdgeCollection myEdges;
};

#endif
