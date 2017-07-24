#ifndef __GRAPH_HXX_
#define __GRAPH_HXX_

#include "Edge.hxx"
#include "Vertex.hxx"

/**
  Generic Graph ADT, mostly as defined in class but with a few minor changes.

  For all const methods, the pre/postconditions are as follows:
    pre-condition:  a valid graph
    post-condition: graph is unchanged
*/
class Graph
{
  public:
    /** Return an iterable collection of all the vertices of the graph. */
    virtual VertexCollection vertices() const = 0;

    /** Return an iterable collection of all the edges of the graph. */
    virtual EdgeCollection edges() const = 0;

    /** Return an iterable collection of the edges incident upon vertex v. */
    virtual EdgeCollection incidentEdges(const Vertex& v) const = 0;

    /** Test whether vertices v and w are adjacent. */
    virtual bool areAdjacent(const Vertex& v, const Vertex& w) const = 0;

    /** Insert a new vertex, return success or failure. */
    virtual bool insertVertex(const Vertex& v) = 0;

    /** Remove vertex v and all incident edges, return success or failure. */
    virtual bool removeVertex(const Vertex& v) = 0;

    /** Insert a new edge, return success or failure. */
    virtual bool insertEdge(const Edge& e) = 0;

    /** Remove specified edge, return success or failure. */
    virtual bool removeEdge(const Edge& e) = 0;
};

#endif
