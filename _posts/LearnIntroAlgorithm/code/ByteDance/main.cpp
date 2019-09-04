/*
 * @Description: bytedance 糖果题
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-27 18:15:59
 * @Author: lydia
 * @Date: 2019-08-25 19:06:42
 */
/*#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}
    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

///获得最大公约数
int gcd(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    }
    while (b != 0) {
        int r = b;
        b = a % b;
        a = r;
    }

    return a;
};

int main()
{
    int n;
    vector<int> data; //甜度数据

    cin >> n;
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }
    data.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }
    ///create graph

    vector<Node*> graph(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        vector<Node*> neighbors;
        for (int j = i + 1; j <= n; j++) {
            if (i != j) {
                //cout << data[i] << "\t" << data[j] << "\t" << gcd(data[i], data[j]) << "\n";
                if (gcd(data[i], data[j]) > 1) { ///判断是否存在边
                    if (graph[j] == nullptr) {
                        graph[j] = new Node;
                        graph[j]->val = j;
                    }
                    neighbors.push_back(graph[j]);
                }
            }
        }
        if (graph[i] == nullptr) {
            graph[i] = new Node;
            graph[i]->val = i;
        }
        graph[i]->neighbors = neighbors;
    }
    ///判断最大连通子图
    multimap<int, int> parent; //{id,组号}
    //扫描所有边
    for (Node* from : graph) {
        if (from != nullptr) {
            for (Node* to : from->neighbors) {
                if (to != nullptr) {
                    from->val > to->val ? parent.insert(pair<int, int>(from->val, to->val)) : parent.insert(pair<int, int>(to->val, from->val));
                }
            }
        }
    }

    ///合并组号
    map<int, int> temp;
    for (multimap<int, int>::iterator it = parent.begin(); it != parent.end(); it++) {
        ///找到真正的组号
        int group_id = it->second;
        multimap<int, int>::iterator next = parent.find(group_id);
        while (next != parent.end()) {
            group_id = next->second;
            next = parent.find(group_id);
        }
        it->second = group_id;
        temp.insert(pair<int, int>(it->first, it->second));
    }
    vector<int> grap_contain(n + 1, 0);
    //查找最大组
    for (map<int, int>::iterator it = temp.begin(); it != temp.end(); it++) {
        cout << "真正组号：" << data[it->first] << "\t" << data[it->second] << "\n";
        grap_contain[it->second]++;
    }
    int res = 0;
    for (int val : grap_contain) {
        if (val >= res) {
            res = val;
        }
    }

    cout << res + 1 << "\n";

    return 0;
}*/
#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;
int main()
{
    cout << "this task:" << getpid() << "\n";
    pid_t pid;
    if (pid = fork()) {
        cout << "new task:" << pid << "\n";
    }
    return 0;
}