#ifndef DIRECTGRAPH_H
#define DIRECTGRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <utility>
#include <unordered_map>
#include <algorithm>

/***********************************************************************************************
********************** 有向图的建立：基本函数版---------------------模板类
*
*map--多条边的不会记录--没有意义----后期也得处理端口一个入端口对多个出端口情况
*
*注：区别于无向图;set有序，内部元素不可改（只能删除，重新插入）
********************************************/


using namespace std;

template <typename T>
class Edge {
public:
    T vertex;
    int weight;

    Edge(T& neighbour_vertex) {
        this->vertex = neighbour_vertex;
        this->weight = 0;
    }

//    Edge(T neighbour_vertex) { //错误：重载“Edge(const int&)”的调用不明确
//        this->vertex = neighbour_vertex;
//        this->weight = 0;
//    }

    Edge(T neighbour_vertex, int weight = 0) {
        this->vertex = neighbour_vertex;
        this->weight = weight;
    }

    bool operator<(const Edge& obj) const {
        return obj.vertex > vertex;
    }

    bool operator>(const Edge& obj) const {
        return obj.vertex < vertex;
    }


    bool operator==(const Edge& obj) const {
        return obj.vertex == vertex;
    }
};

template <typename T>
class Graph {
public:
    map<T, set<Edge<T>>> adj;  /* 邻接表 */

    bool contains(const T& u);
    bool adjacent(const T& u, const T& v);
    void add_vertex(const T& u);
    void add_edge(const T& u, const T& v, int weight);
    void change_weight(const T& u, const T& v, int weight);
    void remove_weight(const T& u, const T& v);
    void remove_vertex(const T& u);
    void remove_edge(const T& u, const T& v);

    //与无向图比--以下函数不变

    int degree(const T& u);
    int num_vertices();
    int num_edges();
    int largest_degree();
    int get_weight(const T& u, const T& v);
    vector<T> get_vertices();
    map<T, int> get_neighbours(const T& u);
    vector<T> get_neighbours_anothertype(const T& u);

    void show();

    //图遍历算法
    // 深度优先遍历递归辅助函数

    void dft_recursion(const T& u, set<T>& visited, vector<T>& result);

    // 深度优先遍历递归法

    vector<T> depth_first_rec(const T& u);

    // 深度优先遍历迭代法

    vector<T> depth_first_itr(const T& u);

    // 广度优先遍历迭代法

    vector<T> breadth_first(const T& u);

    //连通图和连通分量-------略
    // 关节点算法------略

    /***************************************************************************************
         //Dijkstra算法-------注：与无向图有一定区别
         这个函数使用了 Dijkstra 算法来计算从起始节点到图中其他节点的最短路径。
         返回的 map 包含了每个节点到起始节点的最短距离。
         请注意，这个实现假设边的权重是整数类型。如果你的边的权重是浮点数或其他类型，可能需要相应地调整。
    ******************************************************************************************/

    map<T, int> dijkstra(const T& start); /*  dijkstra最短路径算法 */

    /**********************************************************************************
          //最小生成树
          返回一个新的图，表示输入图的最小生成树。算法的基      本思想是从一个起始节点开始，
          每次选择一条边，该边连接一个已经在最小生成树中的节点和一个不在最小生成树中的节点，
          选择的边的权重最小。重复这个过程直到所有节点都包含在最小生成树中。
   ***********************************************************************************/

    Graph<T> prim(T& start);

    /***************************************************************************************
         //Dijkstra算法-------
         这个函数使用了 Dijkstra 算法来计算源-目的对的最短路径
         返回的 vector 包含源节点到目的节点的最短路径经过的节点。

    ******************************************************************************************/

    std::vector<T> dijkstra_pair(Graph<T>& g, const T& start, const T& target, int& dis);

     //SSSP---dijkstra 实现版本---优先队列--当前最有优版本----串行

    std::unordered_map<T, std::pair<std::vector<T>, int>> sssp11(Graph<T>& g, const T& source);

    //Delta-Stepping 算法---实现SSSP---并行版本（后期考虑）


};


template <typename T>
void Graph<T>::show() {
    for (const auto& u : adj) {
        cout << " vetex" << u.first << ": ";
        for (const auto& v : adj[u.first])
            cout << "(Adjacency vertices :" << v.vertex << ", edge weight: " << v.weight << " )";
        cout << endl;
    }
}

template <typename T>
bool Graph<T>::contains(const T& u) {
    return adj.find(u) != adj.end();
}

template <typename T>
bool Graph<T>::adjacent(const T& u, const T& v) {
    if (contains(u) && contains(v) && u != v) {
        for (auto edge : adj[u])
            if (edge.vertex == v)
                return true;
    }
    return false;
}

template <typename T>
void Graph<T>::add_vertex(const T& u) {
    if (!contains(u)) {
        set<Edge<T>> edge_list;
        adj[u] = edge_list;
    }
}

template <typename T>
void Graph<T>::add_edge(const T& u, const T& v, int weight) {
    if (!adjacent(u, v)) {
        adj[u].insert(Edge<T>(v, weight));
        // 对于有向图，不在反向方向添加边
    }
}

//template <typename T>                   //对于std::set中的元素，由于它是有序的，并且set中元素的值是不可修改的，因此我们无法通过迭代器直接修改set中的元素。
//void Graph<T>::change_weight(const T& u, const T& v, int weight) {
//    if (contains(u) && contains(v)) {
//        for (Edge<T>& edge : adj[u]) {
//            if (edge.vertex == v) {
//                edge.weight = weight;
//                break;
//            }
//        }
//    }
//}

template <typename T>
void Graph<T>::change_weight(const T& u, const T& v, int weight) {
    if (contains(u) && contains(v)) {
        auto it = adj[u].find(Edge<T>(v));
        if (it != adj[u].end()) {
            adj[u].erase(it);
            adj[u].insert(Edge<T>(v, weight));
        }
    }
}

template <typename T>
void Graph<T>::remove_weight(const T& u, const T& v) {
    if (contains(u) && contains(v)) {
        auto it = adj[u].find(Edge<T>(v));
        if (it != adj[u].end()) {
            adj[u].erase(it);
            adj[u].insert(Edge<T>(v, 0));
        }
    }

//    if (contains(u) && contains(v)) {
//        for (Edge<T>& edge : adj[u]) {
//            if (edge.vertex == v) {
//                edge.weight = 0;
//                break;
//            }
//        }
//    }
}

template <typename T>
void Graph<T>::remove_vertex(const T& u) {
    if (contains(u)) {
        for (auto& vertex : adj) {
            for (auto it = vertex.second.begin(); it != vertex.second.end();) {
                if (it->vertex == u)
                    it = vertex.second.erase(it);
                else
                    ++it;
            }
        }
        adj.erase(u);
    }
}

template <typename T>
void Graph<T>::remove_edge(const T& u, const T& v) {
    if (u == v || !contains(u) || !contains(v))
        return;

    for (Edge<T>& edge : adj[u]) {
        if (edge.vertex == v) {
            adj[u].erase(edge);
            break;
        }
    }
}

// 其他函数保持不变...

template <typename T> int Graph<T>::degree(const T& u) {
    if (contains(u)) return adj[u].size();

    return -1; // 度数为-1说明图中没有该顶点
}

template <typename T> int Graph<T>::num_vertices() {
    return adj.size();
}

template <typename T> int Graph<T>::num_edges() {
    int count = 0;
    set<Edge<T>> vertex_set;

    for (auto vertex : adj) {
        vertex_set.insert(Edge<T>(vertex.first, 0));
        for (auto edge : vertex.second) {
            if (vertex_set.find(edge) != vertex_set.end()) continue;
            count++;
        }
    }
    return count;
}

template <typename T> int Graph<T>::largest_degree() {
    if (num_vertices() == 0) return 0;

    unsigned max_degree = 0;
    for (auto vertex : adj) {
        if (vertex.second.size() > max_degree)
            max_degree = vertex.second.size();
    }
    return max_degree;
}

template <typename T> int  Graph<T>::get_weight(const T& u, const T& v) {
    if (contains(u) && contains(v)) {
        for (Edge<T> edge : adj[u])
            if (edge.vertex == v) return edge.weight;
    }
    return -1;
}

template <typename T> vector<T> Graph<T>::get_vertices() {
    vector<T> vertices;
    for (auto vertex : adj)
        vertices.push_back(vertex.first);

    return vertices;
}

template <typename T> map<T, int> Graph<T>::get_neighbours(const T& u)
{
    map<T, int> neighbours;

    if (contains(u)) {
        for (Edge<T> edge : adj[u])
            neighbours[edge.vertex] = edge.weight;
    }

    return neighbours;
}

template <typename T> vector<T> Graph<T>::get_neighbours_anothertype(const T& u)
{
    vector<T> neighbours;

    if (contains(u)) {
        for (const Edge<T>& edge : adj[u]) {
            neighbours.push_back(static_cast<T>(edge.vertex));
        }
    }

    return neighbours;
}



//遍历算法
template <typename T>
void Graph<T>::dft_recursion(const T& u, set<T>& visited, vector<T>& result) {
    visited.insert(u);
    result.push_back(u);

    for (const auto& neighbor : adj[u]) {
        if (visited.find(neighbor.vertex) == visited.end()) {
            dft_recursion(neighbor.vertex, visited, result);
        }
    }
}

template <typename T>
vector<T> Graph<T>::depth_first_rec(const T& u) {
    set<T> visited;
    vector<T> result;
    dft_recursion(u, visited, result);
    return result;
}

template <typename T>
vector<T> Graph<T>::depth_first_itr(const T& u) {
    set<T> visited;
    vector<T> result;
    stack<T> s;

    s.push(u);
    visited.insert(u);

    while (!s.empty()) {
        T current = s.top();
        s.pop();
        result.push_back(current);

        for (const auto& neighbor : adj[current]) {
            if (visited.find(neighbor.vertex) == visited.end()) {
                s.push(neighbor.vertex);
                visited.insert(neighbor.vertex);
            }
        }
    }

    return result;
}

template <typename T>
vector<T> Graph<T>::breadth_first(const T& u) {
    set<T> visited;
    vector<T> result;
    queue<T> q;

    q.push(u);
    visited.insert(u);

    while (!q.empty()) {
        T current = q.front();
        q.pop();
        result.push_back(current);

        for (const auto& neighbor : adj[current]) {
            if (visited.find(neighbor.vertex) == visited.end()) {
                q.push(neighbor.vertex);
                visited.insert(neighbor.vertex);
            }
        }
    }

    return result;
}


template <typename T> map<T, int> Graph<T>::dijkstra(const T& start)
 {
    // 使用 map 来保存每个节点的最短距离
    map<T, int> distance;

    // 初始化距离，将起始节点的距离设为0，其他节点的距离设为无穷大
    for (const auto& vertex : adj) {
        distance[vertex.first] = numeric_limits<int>::max();
    }
    distance[start] = 0;

    // 使用优先队列来选择当前距离最小的节点
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        T current = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        // 如果当前距离已经大于最短距离，就不再处理
        if (current_distance > distance[current]) {
            continue;
        }

        // 遍历当前节点的邻接节点，更新最短距离(邻居)
        for (const Edge<T>& neighbor : adj[current]) {
            int new_distance = current_distance + neighbor.weight;
            if (new_distance < distance[neighbor.vertex]) {
                distance[neighbor.vertex] = new_distance;
                pq.push({new_distance, neighbor.vertex});
            }
        }
    }

    return distance;
}

template <typename T> Graph<T> Graph<T>::prim( T& start) {
    // 创建一个新的图来存储最小生成树
    Graph<T> minimumSpanningTree;

    // 使用 set 来保存已经包含在最小生成树中的节点
    set<T> includedNodes;

    // 使用优先队列来选择当前边权重最小的边
    priority_queue<Edge<T>, vector<Edge<T>>, greater<Edge<T>>> pq;

    // 将起始节点添加到最小生成树中
    includedNodes.insert(start);

    // 将起始节点的所有边添加到优先队列
    for (const Edge<T>& edge : adj[start]) {
        pq.push(edge);
    }

    // 主循环
    while (!pq.empty()) {
        Edge<T> currentEdge = pq.top();
        pq.pop();

        T currentVertex = currentEdge.vertex;

        // 如果该节点已经包含在最小生成树中，则跳过
        if (includedNodes.find(currentVertex) != includedNodes.end()) {
            continue;
        }

        // 将该节点添加到最小生成树中
        minimumSpanningTree.add_vertex(currentVertex);
        minimumSpanningTree.add_edge(currentEdge.vertex, currentEdge.vertex, currentEdge.weight);

        // 将该节点标记为已包含
        includedNodes.insert(currentVertex);

        // 将该节点的所有边添加到优先队列
        for (const Edge<T>& edge : adj[currentVertex]) {
            if (includedNodes.find(edge.vertex) == includedNodes.end()) {
                pq.push(edge);
            }
        }
    }

    return minimumSpanningTree;
}


template <typename T> std::vector<T> Graph<T>::dijkstra_pair(Graph<T>& g, const T& start, const T& target, int& dis)
{
    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> pq;
    std::unordered_map<T, int> distance;
    std::unordered_map<T, T> predecessor;
    std::vector<T> path;

    for (const auto& vertex : g.get_vertices()) {
        distance[vertex] = std::numeric_limits<int>::max();
    }

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        T current = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if (current_distance > distance[current]) {
            continue;
        }
        //approach 1:---low
        //        for ( auto &neighbor : g.get_neighbours_anothertype(current))
        //        {
        //            //   int new_distance = current_distance + neighbor.weight;
        //            int new_distance = current_distance + g.get_weight(current,neighbor);
        //            if (new_distance < distance[neighbor]) {
        //                distance[neighbor] = new_distance;
        //                predecessor[neighbor] = current;
        //                pq.push({new_distance, neighbor});
        //            }
        //        }

        //approach 2:---fast
                for (const Edge<T>& neighbor : adj[current])
                {
                    int new_distance = current_distance + neighbor.weight;
                    if (new_distance < distance[neighbor.vertex]) {
                        distance[neighbor.vertex] = new_distance;
                        predecessor[neighbor.vertex] = current;
                        pq.push({new_distance, neighbor.vertex});
                    }
                }
    }

    dis = distance[target];

    if (distance[target] == std::numeric_limits<int>::max()) {
        // 源点无法到达目标结点
        return path;
    }
    //回溯建立路径
    T current = target;
    while (current != start) {
        path.push_back(current);
        current = predecessor[current];
    }
    path.push_back(start);

    std::reverse(path.begin(), path.end());

    return path;
}


template <typename T>std::unordered_map<T, std::pair<std::vector<T>, int>> Graph<T>::sssp11(Graph<T>& g, const T& source)
{
    std::unordered_map<T, std::pair<std::vector<T>, int>> shortestPaths;

    for (const auto& vertex : g.get_vertices())
    {
        if (vertex == source) {
            continue;  // 跳过源节点自身
        }

        int distance;
        std::vector<T> path = g.dijkstra_pair(g, source, vertex, distance);

        shortestPaths[vertex] = std::make_pair(path, distance);
    }
    return shortestPaths;
}

#endif // DIRECTGRAPH_H
