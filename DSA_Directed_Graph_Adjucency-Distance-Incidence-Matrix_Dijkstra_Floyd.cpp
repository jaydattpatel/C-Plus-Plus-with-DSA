// author: @jaydattpatel
/*

 Directed Graph
 Adjacency Matrix, Distance Matrix, Incidence Metrix 
 Dijkstra Algorithm (Single source shortest path), Floyed Algorithm (All Pair Shortest Path).

*/

#include<iostream>
#include<string>
#include<cstring>
#include<deque>
#include<iomanip>
using namespace std;

const int Infinite = 999999;

class vertex;
class edge;
class Graph;
struct dijkstra;
struct floyd;

class edge
{
    public:
        vertex *v;
        int distance;
        edge()
        {
            v = NULL;
            distance = 0;
        }
    
        edge(vertex &x, int d)
        {
            distance = d;
            v = &x;
        }
};

class vertex
{
    public:
        int value;
        string name;
        deque<edge> E;
        vertex()
        {
            value = 0;
            name = "\0";
        }
        vertex(int v)
        {
            value = v;
            name = "\0";
            
        }
        vertex(string n)
        {
            value  = 0;
            name =  n;
        }
        vertex(int v, string n)
        {
            value  = v;
            name =  n;
        }
        
};

struct dijkstra
    {
            vertex v;
            int distance;
            bool visited;
            dijkstra()
            {
                distance = Infinite;
                visited = false;
            }  
    };

struct floyd
{
    deque<vertex> total_vertex;
};

class Graph
{
    public:
        deque<vertex> V;

        bool is_exist(Graph &G,vertex &v);
        int find_position(Graph &G,vertex &v1);
        void add_vertex(Graph &G,vertex &v1);
        void add_edge(Graph &G,vertex &v1, vertex &v2, int distance);
        bool is_edge(Graph &G, vertex &v1, vertex &v2);
        int get_adj_distance(Graph &G, vertex &v1, vertex &v2);
        void show_vertices(Graph &G);  
        void show_adjucents(Graph &G, vertex &v);  
        void delete_vertex(Graph &G, vertex &v);
        void delete_edge(Graph &G, vertex &v1, vertex &v2);
        void adjacency_matrix(Graph G);
        void distance_matrix(Graph G);
        void incidence_matrix(Graph G);
        int get_min_distance_dijkstra(Graph &G, vertex &v1, vertex &v2);
        void get_Allpair_min_distance_floyd(Graph &G);


};

bool Graph::is_exist(Graph &G,vertex &v)
    {

        bool flag = false;
        if(G.V.empty())
            {
                cout<<"\n\n Vertices is underflow..........!";
                return flag;
            }
     
            for(int i = 0; i < G.V.size() ;i++)
                {
                    if(G.V[i].value == v.value && G.V[i].name == v.name)
                        {
                            flag = true;
                            break;
                        }
                }   
                
            return flag;
    }

int Graph::find_position(Graph &G,vertex &v)
    {
        int position = Infinite;
        if(G.V.empty())
            {
                cout<<"\n\n Vertices is underflow..........!";
                return position;
            }
            
        for(int i = 0; i < G.V.size() ;i++)
            {
                if(G.V[i].value == v.value && G.V[i].name == v.name)
                    {
                        position = i;
                        break;
                    }
            }   
                
            return position;
    }

void Graph::add_vertex(Graph &G,vertex &v1)
    {
        G.V.push_back(v1);
    }

void Graph::add_edge(Graph &G,vertex &v1, vertex &v2, int distance)
    {

        edge e(v2,distance);
        int position = 0;
        if(is_exist(G,v1))
            {
                position = find_position(G,v1);
                if(position != Infinite)
                    {
                        G.V[position].E.push_back(e);
                    }
            }
        else
            {
                add_vertex(G,v1);
                add_edge(G,v1,v2,distance);
            }
    }

bool Graph::is_edge(Graph &G, vertex &v1, vertex &v2)
    {
        
        bool flag = false;
        int position = 0;
        if(G.V.empty())
            {
                cout<<"\n\n Vertices is underflow..........!";
                return flag;
            }
        if(is_exist(G,v1))
        {
            position = find_position(G,v1);
            if(position != Infinite)
                {
                    if(!(G.V[position].E.empty()))
                        {
                            for(int i = 0 ; i < G.V[position].E.size() ;i++)
                                {
                                    if(G.V[position].E[i].v->value == v2.value && 
                                        G.V[position].E[i].v->name == v2.name)
                                        {
                                            flag = true;
                                            break;
                                        }
                                }
                        }
                }
        }
        else
            return flag;
            
        return flag;
    }

int Graph::get_adj_distance(Graph &G, vertex &v1, vertex &v2)
    {

        int dist = Infinite;
        int position = 0;
        if(G.V.empty())
            {
                cout<<"\n\n Vertices is underflow..........!";
                return dist;
            }
        if(is_exist(G,v1))
        {
            position = find_position(G,v1);
            if(position != Infinite)
                {
                    bool flag = true;
                    if(!(G.V[position].E.empty()))
                        {
                            for(int i = 0; i < G.V[position].E.size() ;i++)
                                {
                                    if(G.V[position].E[i].v->value == v2.value && 
                                        G.V[position].E[i].v->name == v2.name)
                                        {
                                            dist = G.V[position].E[i].distance;
                                            flag = false;
                                            break;
                                        }
                                }
                        }
                }
        }
        else
        {
            cout<<"\n\n No Main vertex found..........!";
            return dist;
        }
            
        return dist;
    }

void Graph::show_vertices(Graph &G)
{
    if(!G.V.empty())
    {
        cout<<"\n\nVertices List:";
        for(int i = 0; i < G.V.size() ;i++)
                cout<<"\n( "<<G.V[i].value<<", "<<G.V[i].name<<" )";
    }
    else
        cout<<"\n\n Vertices is underflow..........!";
} 

void Graph::show_adjucents(Graph &G, vertex &v)
    {
        if(G.V.empty())
            {
                cout<<"\n\n Vertices is underflow..........!";
                return;
            }
        int position = 0;
        if(is_exist(G,v))
        {
            position = find_position(G,v);
            if(position != Infinite)
            {
                    if(!(G.V[position].E.empty()))
                    {
                        cout<<"\n\n Adjucents of ("<<G.V[position].value<<", "<<G.V[position].name<<" ) : ";
                        for(int i = 0; i < G.V[position].E.size() ;i++)
                            {
                                cout<<"\n("<<G.V[position].E[i].v->value<<", "
                                    <<G.V[position].E[i].v->name<<" ) ( Distance: "
                                    <<G.V[position].E[i].distance<<" )";    
                            }
                    }
                    else
                        cout<<"\n\n Adjucent edge vertex is underflow........!";
            }
        }          
        else
            cout<<"\n\n No Main vertex found for adjucent........!";
    }
void Graph::delete_vertex(Graph &G, vertex &v)
    {
        if(G.V.empty())
            {
                cout<<"\n\n Vertices is underflow..........!";
                return;
            }
        int position = 0;
        if(is_exist(G,v))
        {
            position = find_position(G,v);
            if(position != Infinite)
            {
                for(int i = 0; i < G.V.size() ;i++)
                {       
                    if(!(G.V[i].E.empty()))
                    {
                        for(int j = 0; j < G.V[i].E.size() ;j++)
                            {
                                if(G.V[i].E[j].v->value == v.value && G.V[i].E[j].v->name == v.name)
                                {
                                    G.V[i].E.erase(G.V[i].E.begin() + j);
                                    break;
                                }
                            }
                    }
                }
                cout<<"\n\n("<<G.V[position].value<<", "<<G.V[position].name<<") ";
                G.V.erase(G.V.begin() + position);
                cout<< "Vertex Deleted..........! ";
            }
        }
        else
        {
            cout<<"\n\n No Main vertex found to delete vertex........!";
        }
    }
void Graph::delete_edge(Graph &G, vertex &v1, vertex &v2)
    {
        if(G.V.empty())
            {
                cout<<"\n\n Vertices is underflow..........!";
                return;
            }
        int position = 0;
        if(is_exist(G,v1))
        {
            position = find_position(G,v1);
            if(position != Infinite)
            {
                    if(!(G.V[position].E.empty()))
                    {
                        bool flag = false;
                        for(int i = 0; i < G.V[position].E.size() ;i++)
                            {
                                if(G.V[position].E[i].v->value == v2.value && G.V[position].E[i].v->name == v2.name)
                                    {
                                        G.V[position].E.erase(G.V[position].E.begin() + i);
                                        break;
                                    }  
                            }
                    }
                    else
                        cout<<"\n\nAdjucent edge vertex is empty ........!";
            }
        }          
        else
        {
            cout<<"\n\n No Main vertex found to delete edge........!";
        }
    }

void Graph::adjacency_matrix(Graph G)
{
    if(G.V.empty())
        {
            cout<<"\n\n Vertices is underflow..........!";
            return;
        }
    
    cout<<"\n\n____________________";
    for(int i = 0; i < G.V.size() ;i++)
            cout<<"______________";

    cout<<"\n| Adjacency Matrix |";
    for(int i = 0; i < G.V.size() ;i++)
            printf(" %10s  |", G.V[i].name.c_str());

    cout<<"\n--------------------";
    for(int i = 0; i < G.V.size() ;i++)
            cout<<"--------------";   

    for(int i = 0; i < G.V.size() ;i++)
    {  
        printf("\n|(%5d,%10s)|",G.V[i].value, G.V[i].name.c_str());
        for(int j = 0; j < G.V.size() ; j++)
                printf("  %5d      |", G.is_edge(G,G.V[i],G.V[j]));
    }
    cout<<"\n--------------------";
    for(int i = 0; i < G.V.size() ;i++)
            cout<<"--------------";          

} 

void Graph::distance_matrix(Graph G)
{
    if(G.V.empty())
        {
            cout<<"\n\n Vertices is underflow..........!";
            return;
        }
    cout<<"\n\n____________________";
    for(int i = 0; i < G.V.size() ;i++)
            cout<<"______________";

    cout<<"\n|  Distance Matrix |";
    for(int i = 0; i < G.V.size() ;i++)
            printf(" %10s  |", G.V[i].name.c_str());

    cout<<"\n--------------------";
    for(int i = 0; i < G.V.size() ;i++)
            cout<<"--------------"; 

    for(int i = 0; i < G.V.size() ;i++)
        {
            printf("\n|(%5d,%10s)|",G.V[i].value ,G.V[i].name.c_str());
            for(int j = 0; j < G.V.size() ; j++)
                printf("   %7d   |", G.get_adj_distance(G,G.V[i],G.V[j]));
        }
    cout<<"\n--------------------";
    for(int i = 0; i < G.V.size() ;i++)
            cout<<"--------------";         

}

void Graph::incidence_matrix(Graph G)
{
    if(G.V.empty())
    {
        cout<<"\n\n Vertices is underflow..........!";
        return;
    }
    
    deque<pair<vertex*,vertex*>> total_edges;
    pair<vertex*,vertex*> pair;
    
    for(int i = 0; i < G.V.size() ;i++)
        {       
            if(!(G.V[i].E.empty()))
            {
                for(int j = 0; j < G.V[i].E.size() ;j++)
                    {
                        pair.first = &G.V[i];
                        pair.second = G.V[i].E[j].v;
                        total_edges.push_back(pair);
                    }    
            }
        }
    
    cout<<"\n\n____________________";
    for(int i = 0; i < total_edges.size() ;i++)
        cout<<"________";
        
    cout<<"\n| Incidence Matrix |";
    string ss("E-");

    for(int i = 0; i < total_edges.size() ;i++)
    {
        string num = to_string(i); 
        printf(" %2s%3s |",ss.c_str(),num.c_str());
    }

    cout<<"\n--------------------";
    for(int i = 0; i < total_edges.size() ;i++)
        cout<<"--------";   

    for(int i = 0; i < G.V.size() ;i++)
    {
        printf("\n|(%5d,%10s)|",G.V[i].value ,G.V[i].name.c_str());
        for(int j = 0; j < total_edges.size() ; j++)
        {
            // vertex source,destination;
            // source.value = G.V[i].
            if( G.V[i].name == total_edges[j].first->name &&
                G.V[i].value == total_edges[j].first->value )
                    {
                        printf("  %3d  |",1);
                    }
            else if( G.V[i].name == total_edges[j].second->name &&
                        G.V[i].value == total_edges[j].second->value )
                    {
                        printf("  %3d  |",-1);
                    }
            else
                printf("  %3d  |",0);
        }
    }

    cout<<"\n--------------------";
    for(int i = 0; i < total_edges.size() ;i++)
        cout<<"--------";   
        
}

int Graph::get_min_distance_dijkstra(Graph &G, vertex &v1, vertex &v2)
{
    if(G.V.empty())
    {
        cout<<"\n\n Vertices is underflow..........!";
        return Infinite;
    }

    if((!is_exist(G,v1)) || (!is_exist(G,v2)))
    {
        cout<<"\n\n Vertex not found ..........!";
        return Infinite;
    }

    cout<<"\n\nFinding Path from ("<<v1.value<<", "<<v1.name<<") to ("<<v2.value<<", "<<v2.name<<") :";
    deque<vertex> path;
    deque<dijkstra> total_vertex;
    dijkstra dj;
    int pos = find_position(G,v1);
    dj.v = G.V[pos];
    dj.distance = 0;
    total_vertex.push_back(dj);
    for(int i = 0; i < G.V.size(); i++)
        {
            if( G.V[i].value == v1.value && G.V[i].name == v1.name)
                continue;
            dj.v = G.V[i];
            dj.distance = Infinite;
            total_vertex.push_back(dj);
        }


    dijkstra pivot;
    int pivot_position_in_total_vertex;

    cout<<"\n______________________________";
    for(int i = 0; i < total_vertex.size() ;i++)
            cout<<"_____________";

    printf("\n|\t Pivot Sequence      |");
    for(int i = 0; i < total_vertex.size(); i++)
                    printf(" %10s |",total_vertex[i].v.name.c_str());

    cout<<"\n------------------------------";
    for(int i = 0; i < total_vertex.size() ;i++)
            cout<<"-------------";

    for(int i = 0; i < total_vertex.size(); i++)
        {
            int min = Infinite;
            for(int i = 0; i < total_vertex.size(); i++)
                {

                    if((!total_vertex[i].visited) && (total_vertex[i].distance <= min))
                        {
                            pivot = total_vertex[i];
                            pivot_position_in_total_vertex = i;
                            min = total_vertex[i].distance;
                        }
                }

            path.push_back(pivot.v);
            printf("\n|(%5d,%10s,Edges:%3d)|",pivot.v.value, pivot.v.name.c_str(),pivot.v.E.size());
            for(int i = 0; i < total_vertex.size(); i++)
                    printf("  %7d   |",total_vertex[i].distance);

            for(int i = 0; i < total_vertex.size(); i++)
                {
                    
                    for(int j = 0; j < pivot.v.E.size(); j++)
                    {   

                        if(total_vertex[i].v.value == pivot.v.E[j].v->value &&
                            total_vertex[i].v.name == pivot.v.E[j].v->name)
                        {

                            if(total_vertex[i].distance > 
                            total_vertex[pivot_position_in_total_vertex].distance + pivot.v.E[j].distance)
                            {
                                total_vertex[i].distance = 
                                total_vertex[pivot_position_in_total_vertex].distance + pivot.v.E[j].distance;
                            }
                        }    
                    }  
                }
            total_vertex[pivot_position_in_total_vertex].visited = true;
        }
    cout<<"\n------------------------------";
    for(int i = 0; i < total_vertex.size() ;i++)
            cout<<"-------------";

    int dis = Infinite;
    for(int i = 0; i < total_vertex.size() ;i++)
        {
            if(total_vertex[i].v.value == v2.value && total_vertex[i].v.name == v2.name)
            {
                dis = total_vertex[i].distance;
                break;
            }
        }
    cout<<"\nTotal Minumum Distance: "<<dis;
    
    cout<<"\nPath from ("<<v1.value<<", "<<v1.name<<") to ("<<v2.value<<", "<<v2.name<<") : ";
    if(dis != Infinite)
        {
            cout<<"\n\n";
            for(int i = 0; i < path.size() ;i++)
                {
                    cout<<" -> ("<<path[i].value<<", "<<path[i].name<<")";
                    if(path[i].value == v2.value && path[i].name == v2.name)
                            break;    
                }
        }
    else
        {
            cout<< "Infinite\n\n";
        }
    return dis;
}

void Graph::get_Allpair_min_distance_floyd(Graph &G)
{
    floyd floyd;
    for(int i = 0; i < G.V.size(); i++)
        floyd.total_vertex.push_back(G.V[i]);

    int matrix[floyd.total_vertex.size()][floyd.total_vertex.size()];

    for(int row = 0; row < G.V.size(); row++)
        for(int col = 0; col < G.V.size(); col++)
        {   
            if(row == col)
                matrix[row][col] = 0;
            else
                matrix[row][col] = Infinite;
        }

    for(int row = 0; row < G.V.size(); row++)
        {
            for(int col = 0; col < G.V.size(); col++)
            {   
                for(int p = 0; p < floyd.total_vertex[row].E.size(); p++)
                {
                    if(floyd.total_vertex[row].E[p].v->value  == floyd.total_vertex[col].value &&
                    floyd.total_vertex[row].E[p].v->name  == floyd.total_vertex[col].name)
                    {
                        matrix[row][col] = floyd.total_vertex[row].E[p].distance;
                    }
                }
            }
        }
    
        for(int i = 0; i < G.V.size(); i++)
        {
            for(int row = 0; row < G.V.size(); row++)
            {   
                for(int col = 0; col < G.V.size(); col++)
                {
                    matrix[row][col] = min( matrix[row][col], (matrix[row][i] + matrix[i][col])); 
                }
            }
        }
    cout<<"\n\nFloyd Algorithm All Pair Shortest Path Matrix : ";
    cout<<"\n____________________";
    for(int i = 0; i < G.V.size() ;i++)
            cout<<"______________";

    cout<<"\n|  All Pair Matrix |";
    for(int i = 0; i < G.V.size() ;i++)
            printf(" %10s  |", G.V[i].name.c_str());

    cout<<"\n--------------------";
    for(int i = 0; i < G.V.size() ;i++)
            cout<<"--------------"; 

    for(int row = 0; row < G.V.size() ;row++)
        {
            printf("\n|(%5d,%10s)|",G.V[row].value ,G.V[row].name.c_str());
            for(int col = 0; col < G.V.size() ; col++)
                printf("   %7d   |", matrix[row][col]);
        }
    cout<<"\n--------------------";
    for(int i = 0; i < G.V.size() ;i++)
            cout<<"--------------";  
}


int main()
    {
        Graph G;
        vertex v1(1,"Ahmedabad"), v2(2,"Bangalore"), v3(3,"Chennai"), v4(4,"Kolkatta"), v5(5,"Mumbai"), v6(6,"Delhi");
        G.V.push_back(v1);
        G.V.push_back(v2);
        G.V.push_back(v3);
        G.add_vertex(G,v4);
        G.add_vertex(G,v5);
        G.add_vertex(G,v6);

        G.add_edge(G,v1,v2,50);
        G.add_edge(G,v1,v3,45);
        G.add_edge(G,v1,v4,10);
        G.add_edge(G,v2,v3,10);
        G.add_edge(G,v2,v4,15);
        G.add_edge(G,v3,v5,30);
        G.add_edge(G,v4,v1,10);
        G.add_edge(G,v4,v5,15);
        G.add_edge(G,v5,v2,20);
        G.add_edge(G,v5,v3,35);

        G.show_vertices(G);
        G.show_adjucents(G,v1);
        G.show_adjucents(G,v2);
        G.show_adjucents(G,v3);
        G.show_adjucents(G,v4);
        G.show_adjucents(G,v5);

        G.adjacency_matrix(G);
        G.distance_matrix(G);
        G.incidence_matrix(G);

        int dis = G.get_min_distance_dijkstra(G,v1,v3);
        G.get_Allpair_min_distance_floyd(G);

        G.delete_vertex(G,v3);
        G.delete_edge(G, v5, v4); 

        G.show_vertices(G);
        G.show_adjucents(G,v1);
        G.show_adjucents(G,v2);
        G.show_adjucents(G,v3);
        G.show_adjucents(G,v4);
        G.show_adjucents(G,v5);
        
        return 0;
    }