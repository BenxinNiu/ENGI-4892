#ifndef __VERTEX_HXX_
#define __VERTEX_HXX_

#include <iostream>
#include <vector>
using namespace std;

/**
  Generic vertex, where 'name' identifies the vertex, and 'visit' is used
  by various algorithms to mark the vertex as such.
*/
class Vertex
{
  public:
    Vertex(string n) : name(n), visit(false) { }

    // Set/query vertex state
    void setVisited(bool state) { visit = state; }
    bool visited() const { return visit; }

    // Two vertices are considered equal if they have the same name
    bool operator== (const Vertex& v) const {
      return v.name == name;
    }

    // Output vertex information
    friend ostream& operator<< (ostream& out, const Vertex& v) {
      return out << v.name;
    }

  private:
    string name;
    bool visit;
};

using VertexCollection = std::vector<Vertex>;

#endif
