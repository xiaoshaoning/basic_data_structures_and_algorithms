#include <iostream>
#include <list>

using namespace std;

class graph
{
  int number_of_vertices;
  list<int> * adjacency_list;
public:
  graph(int number_of_vertices); //constructor
  ~graph();
  void add_edge(int v, int w);
  void breadth_first_search(int s);
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

void graph::add_edge(int v, int w)
{
  adjacency_list[v].push_back(w); // add w to v's list
}

void graph::breadth_first_search(int s)
{
  bool * visited = new bool[number_of_vertices];
  
  for(int i = 0; i < number_of_vertices; i++)
  {
    visited[i] = false;
  }

  list<int> queue;

  visited[s] = true;

  queue.push_back(s);

  list<int>::iterator my_iterator;

  while(!queue.empty())
  {
    s = queue.front();
    cout<<s<<" ";
    queue.pop_front();

    for (my_iterator = adjacency_list[s].begin(); my_iterator != adjacency_list[s].end(); ++my_iterator)
    {
      if (!visited[*my_iterator])
      {
        visited[*my_iterator] = true;
        queue.push_back(*my_iterator);
      }
    } // end of for
  } // end of while

  delete [] visited;

} // end of function

int main()
{
  graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  g.add_edge(2, 3);
  g.add_edge(3, 3);

  cout <<"following is breadth first traversal "
       <<"(starting from vertex 2) \n";
  g.breadth_first_search(2);
  
  cout<<"\n";

  return 0;
}  


