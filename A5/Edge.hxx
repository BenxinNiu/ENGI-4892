#ifndef __EDGE_HXX_
#define __EDGE_HXX_

#include <iostream>
#include <vector>
using namespace std;

#include "Vertex.hxx"

/**
  Generic weighted edge which contains 2 vertices and a non-negative weight
*/
class Edge
{
  public:
    Edge(Vertex vx1, Vertex vx2, int w = 0) : v1(vx1), v2(vx2), eweight(w) { }

    unsigned int weight() const {
      return eweight;
    }

    bool contains(const Vertex& v) const {
      return v1 == v || v2 == v;
    }

    Vertex opposite(const Vertex& v) const {
      if(v1 == v) return v2;
      else        return v1;
    }

    VertexCollection endVertices() const {
      return VertexCollection{v1, v2};
    }

    // Two edges are considered equal if they have the same endpoints
    bool operator== (const Edge& e) const {
      return (v1 == e.v1 && v2 == e.v2) || (v1 == e.v2 && v2 == e.v1);
    }

    // Output edge information
    friend ostream& operator<< (ostream& out, const Edge& e) {
      return out << "(" << e.v1 << ", " << e.v2 << ")";
    }

  private:
    Vertex v1, v2;
    unsigned int eweight;
};

using EdgeCollection = std::vector<Edge>;

#endif
