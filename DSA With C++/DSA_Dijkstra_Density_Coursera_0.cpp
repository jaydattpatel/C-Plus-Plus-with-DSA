
#include <exception>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <random>
#include <tuple>

#include <ctime>

using namespace std;

class Graph
{
    private:
        const unsigned int n_vertices;  /// param v number of vertices
        unsigned int n_edges; ///number of edges in the graph
        vector<double> adj_; /// places to store the adjacency matrix.
    public:
        /// Initialize a graph with v vertices. Use an 1-dimension array with v*v
        /// places to store the adjacency matrix.
        /// param v number of vertices
        Graph(unsigned int v): n_vertices(v), n_edges(0), adj_(v * v, 0) {}

        /// return number of vertices in the graph
        unsigned int vertices() const { return n_vertices; }

        /// return number of edges in the graph
        unsigned int edges() const { return n_edges; }

        /// return true if there is an edge from node x to node y
        bool adjacent(unsigned int x, unsigned int y) const {
            return adj_[index_for(x, y)] > 0;
        }

        /// return list of all nodes y that connected to node x
        vector<unsigned int> neighbors(unsigned int x) const {
            vector<unsigned int> result;
            for (int i = 0; i < n_vertices; ++i)
                if (adjacent(x, i))
                    result.push_back(i);

            return result;
        }

        /// Add an edge from node x to node y
        void add_edge(unsigned int x, unsigned int y, double weight) 
        {
            if (weight < 0)
                throw invalid_argument("Weight of an edge can not be negative!");
            if (adj_[index_for(x, y)] == 0)
                ++n_edges;

            adj_[index_for(x, y)] = weight;
            adj_[index_for(y, x)] = weight;
        }

        /// Remove the edge from node x to node y
        void remove_edge(unsigned int x, unsigned int y) 
        {
            adj_[index_for(x, y)] = 0;
            adj_[index_for(y, x)] = 0;
            --n_edges;
        }

        /// return the value of the edge from x to y
        double get_edge_value(unsigned int x, unsigned int y) 
        {
            return adj_[index_for(x, y)];
        }

    protected:
      /// return Convert index of 2-dimension array to a 1-dimension array
      unsigned int index_for(unsigned int x, unsigned int y) const {
          if (x >= n_vertices || y >= n_vertices)
              throw invalid_argument("Index out of bounds!");

          return x * n_vertices + y;
      }
};


class ShortestPath 
{
    private:
          Graph g_;

          // Store the final distance from the source node
          vector<double> dist_;

          unsigned int source_;

          // Tuple type to store the distance from the source node to a node and that node's id
          using DistNode = tuple<double, unsigned int>;
    public:
          /// This class compute the shortest path for the given graph g
          /// from the start node source to all other nodes.
          ///  g the given graph, source the start node
          ShortestPath(Graph g, unsigned int source = 0):
              g_(g),
              dist_(g.vertices(), numeric_limits<double>::max()),
              source_(source) {
              compute();
          }

          /// return the distance from the source node to the node idx
          double operator[](int idx) const {
              return dist_[idx];
          }
    protected:
          /// Compute the shortest path from the given start node to all other
          /// nodes with the Dijkstra algorithms.
          void compute() 
          {
              // queue of the next node to visit
              // each elements is a tuple of the distance to the node and the node's id
              // this priority queue is sorted with the minimum distance at the top
              priority_queue<DistNode, vector<DistNode>, less<DistNode>> nodes;

              // start the queue with the source node,
              // the distance to itself is 0
              nodes.push(make_tuple(0, source_));

              while (!nodes.empty()) 
              {
                  // extract the next node and distance from the queue
                  double d;
                  unsigned int n;
                  tie(d, n) = nodes.top();
                  nodes.pop();

                  // update the distance array and find the next nodes to visit
                  if (d < dist_[n])
                      dist_[n] = d;

                  for (const auto& w: g_.neighbors(n)) 
                    {
                        auto new_dist = dist_[n] + g_.get_edge_value(n, w);
                        if (new_dist < dist_[w]) 
                          {
                              dist_[w] = new_dist;
                              nodes.push(make_tuple(new_dist, w));
                          }
                    }
              }
          } 
};


class Simulator 
{
    private:
        double avg_;
        int num_;
        double den_;
        mt19937 random_generator_;
        uniform_real_distribution<double> distance_distribution_;
        uniform_real_distribution<double> existence_distribution_;

    public:
        /// Create a simulator with the given parameter
        Simulator(int num = 50, double density = 0.2,double distance_min = 1, double distance_max = 10,int times = 50):
            num_(num),
            den_(density),
            random_generator_(time(NULL)),
            distance_distribution_(distance_min, distance_max),
            existence_distribution_(0.0, 1.0) 
            {
              double sum_avg_dist = 0;
              for (int i = 0; i < times; ++i) 
                {
                    sum_avg_dist += run_simulation();
                }
              avg_ = sum_avg_dist / times;
            }

        /// return the average distance of the shortest path
        double average_distance() const {
            return avg_;
        }

    protected:
        /// Generate a graph and run the simulation.
        /// return the average shortest path of the generated graph
        double run_simulation() 
        {
            Graph g = generate_graph();
            ShortestPath sp(g, 0);
            int count = 0;
            double sum = 0;

            for (int i = 1; i < g.vertices(); ++i)
                if (sp[i] < numeric_limits<double>::max()) 
                {
                    ++count;
                    sum += sp[i];
                }

            return sum / count;
        }

        /// return a generated graph with given parameter
        Graph generate_graph() 
        {
            Graph g(num_);
            for (int i = 0; i < num_ - 1; ++i)
                for (int j = i + 1; j < num_; ++j)
                    if (existence_distribution_(random_generator_) < den_)
                        g.add_edge(i, j, distance_distribution_(random_generator_));
            return g;
        }
};


int main()
{
    cout << "Starting..." << endl;

    Simulator sim20;
    cout << "Density 20%: average distance is "
         << sim20.average_distance() << endl;

    Simulator sim40(50, 0.4);
    cout << "Density 40%: average distance is "
         << sim40.average_distance() << endl;

    return 0;
}
