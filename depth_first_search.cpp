#include <bits/stdc++.h>
using namespace std;

class graph
{
  int number_of_vertices;
  list<int> * adjacency_list;

public:
  graph(int number_of_vertices);
  ~graph();
  void add_edge(int n, int m);
  void depth_first_search();
private:
  void depth_first_search_utility(int s, vector<bool> & visited_vertices); //not visited vertices reachable from s
};

graph::graph(int number_of_vertices)
{
  this->number_of_vertices = number_of_vertices;
  adjacency_list = new list<int>[number_of_vertices];
}

graph::~graph()
{
  delete [] adjacency_list;
}

void graph::add_edge(int n, int m)
{
  adjacency_list[n].push_back(m);
}

/* get all adjacent vertices of the popped vertex s and if it has not been visited, push it to the stack */

void graph::depth_first_search_utility(int s, vector<bool> & visited_vertices)
{
  // create a stack for depth first search
  stack<int> stack;

  stack.push(s);

  while (!stack.empty())
  {
    s = stack.top();
    stack.pop();

    if (!visited_vertices[s])
    {
      cout<<s<<" ";
      visited_vertices[s] = true;
    }

    for (list<int>::iterator ii = adjacency_list[s].begin(); ii != adjacency_list[s].end(); ++ii)
    {
      if (!visited_vertices[*ii])
      {
        stack.push(*ii);
      }

    }
 } // end of while
} // end of graph::depth_first_search_utility

void graph::depth_first_search()
{
  vector<bool> visited_vertices(number_of_vertices, false);

  for(int i = 0; i < number_of_vertices; i++)
  {
    if (!visited_vertices[i])
    {
      depth_first_search_utility(i, visited_vertices);
    }
  }
}

/* test bench */
int main()
{
  graph binary_tree(7);
  binary_tree.add_edge(0, 2);
  binary_tree.add_edge(0, 1);
  binary_tree.add_edge(1, 4);
  binary_tree.add_edge(1, 3);
  binary_tree.add_edge(2, 6);
  binary_tree.add_edge(2, 5);

  binary_tree.depth_first_search();
  
  cout<<"\n";

  return 0;
}
