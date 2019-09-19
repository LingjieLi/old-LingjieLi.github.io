#include <vector>
#include <limits>
#include <queue>
#include <iostream>

using namespace std;

enum Color {
    Black,
    White
};

struct Neighbor {
    int node;
    int length = std::numeric_limits<int>::max();
    Neighbor* next = nullptr;
};
struct Node {
    int idx;
    int value = std::numeric_limits<int>::max();
    Color color = Color::White;
    Node* parent = nullptr;
    Neighbor* neighbor = nullptr;
};

struct cmp {
    bool operator()(const Node* a, const Node* b)
    {
        return a->value < b->value;
    }
};

class Solution {
public:
    //最长时间
    //N节点个数
    //K起始节点序号
    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        priority_queue<Node*, vector<Node*>, cmp> pdata; //优先数据列表

        ///初始化数据
        vector<Node*> data;
        data.resize(N + 1);

        for (Node* cur : data) {
            cur = nullptr;
        }

        //初始化数据 O(N)
        for (vector<int> route : times) {
            int from = route[0];
            int to = route[1];
            int time = route[2];
            if (!data[from]) {
                data[from] = new Node;
                data[from]->idx = from;
            }
            if (!data[to]) {
                data[to] = new Node;
                data[to]->idx = to;
            }

            Neighbor* neigh = new Neighbor;
            neigh->node = to;
            neigh->length = time;

            Neighbor* temp = data[from]->neighbor;
            data[from]->neighbor = neigh;
            data[from]->neighbor->next = temp;
        }
        data[K]->value = 0;

        pdata.push(data[K]);

        while (!pdata.empty()) {

            Node* min_node = pdata.top();
            pdata.pop();

            Node* current = data[min_node->idx];
            Neighbor* neigh = current->neighbor;
            current->color = Color::Black;

            ///访问邻接
            while (neigh != nullptr) {
                if (data[neigh->node]->value > current->value + neigh->length) { //relax
                    data[neigh->node]->value = current->value + neigh->length;
                    data[neigh->node]->parent = current;

                    pdata.push(data[neigh->node]);
                }

                neigh = neigh->next;
            }
        }

        ///最长路径
        int min_time;

        for (vector<Node*>::iterator it = ++data.begin(); it != data.end(); it++) {
            if ((*it) == nullptr || (*it)->value == numeric_limits<int>::max()) {
                return -1;
            }
        }
        if (data.size() > 2) {
            min_time = (*(++data.begin()))->value;
            for (vector<Node*>::iterator it = ++data.begin(); it != data.end(); it++) {
                if ((*it)->value > min_time) {
                    min_time = (*it)->value;
                }
            }
        } else {
            min_time = 0;
        }
        return min_time;
    }
};

int main()
{
    vector<int> r1 = { 2, 1, 1 };
    vector<int> r2 = { 2, 3, 1 };
    vector<int> r3 = { 3, 4, 1 };

    vector<int> r4 = { 1, 2, 1 };
    vector<vector<int>> times;
    // times.push_back(r1);
    // times.push_back(r2);
    // times.push_back(r3);
    times.push_back(r4);

    Solution* sol = new Solution;
    int time = sol->networkDelayTime(times, 2, 2);

    std::cout << "time: " << time << "\n";
}