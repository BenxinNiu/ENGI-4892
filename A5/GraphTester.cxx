#include <iostream>
#include <queue>
#include <memory>
using namespace std;

#include "Graph.hxx"
#include "EdgeListGraph.hxx"

Vertex a("a"), b("b"), c("c"), d("d"), e("e"), f("f");

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
unique_ptr<Graph> createGraph()
{
  VertexCollection vertices;
  vertices.push_back(a);
  vertices.push_back(b);
  vertices.push_back(c);
  vertices.push_back(d);
  vertices.push_back(e);
  vertices.push_back(f);

  EdgeCollection edges;
  edges.emplace_back(a, b);
  edges.emplace_back(a, c);
  edges.emplace_back(b, d);
  edges.emplace_back(c, d);
  edges.emplace_back(c, e);
  edges.emplace_back(d, f);
  edges.emplace_back(e, f);
  edges.emplace_back(c, f);
  edges.emplace_back(d, e);

  return unique_ptr<Graph>(new EdgeListGraph(vertices, edges));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template<class T>
void printCollection(const T& container)
{
  cout << "[ ";
  for(const auto& e: container)
    cout << e << " ";
  cout << "]" << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void printGraph(const unique_ptr<Graph>& g)
{
  cout << "Vertices: ";
  printCollection(g->vertices());
  cout << "Edges:    ";
  printCollection(g->edges());
  cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main(int ac, char* av[])
{
  unique_ptr<Graph> g = createGraph();

  // Make sure vertices and edges added correctly
  printGraph(g);

  // Test incident edges
  cout << "TEST: Incident edges to vertex c" << endl;
  printCollection(g->incidentEdges(c));
  cout << endl;

  // Remove vertex 'a', should also remove edges to b, c
  cout << "TEST: Remove vertex a" << endl;
  g->removeVertex(a);
  printGraph(g);

  // Remove edge d-f
  Edge df(d, f);
  cout << "TEST: Remove edge " << df << endl;
  g->removeEdge(df);
  printGraph(g);

  // Remove vertex 'c', should also remove edges to d, e, f
  cout << "TEST: Remove vertex c" << endl;
  g->removeVertex(c);
  printGraph(g);

  // Test adjacency
  cout << "TEST: " << d << " adjacent to " << b << " : " << g->areAdjacent(d, b) << endl;
  cout << "TEST: " << d << " adjacent to " << f << " : " << g->areAdjacent(d, f) << endl;
  cout << endl;

  // Remove vertex 'e', should also remove edges to d, f
  cout << "TEST: Remove vertex e" << endl;
  g->removeVertex(e);
  printGraph(g);

  // Add edge f-g
  Edge fg(f, Vertex("g"));
  cout << "TEST: Add edge " << fg << endl;
  g->insertEdge(fg);
  printGraph(g);
}
