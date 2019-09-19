/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-09 20:18:49
 * @Author: lydia
 * @Date: 2019-08-09 19:57:34
 */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string line;
    stringstream ss;
    while (getline(cin, line)) {
        ss.str("");
        ss.clear();
        ss.str(line);

        float aminX, aminY, aminZ;
        float amaxX, amaxY, amaxZ;

        float bminX, bminY, bminZ;
        float bmaxX, bmaxY, bmaxZ;

        ss >> aminX >> aminY >> aminZ >> amaxX >> amaxY >> amaxZ >> bminX >> bminY >> bminZ >> bmaxX >> bmaxY >> bmaxZ;

        // x轴方向碰撞？
        bool collisionX = amaxX >= bminX && bmaxX >= aminX;
        // y轴方向碰撞？
        bool collisionY = amaxY >= bminY && bmaxY >= aminY;
        // z轴方向碰撞？
        bool collisionZ = amaxZ >= bminZ && bmaxZ >= aminZ;
        // 只有三个轴向都有碰撞时才碰撞
        bool collision = collisionX && collisionY && collisionZ;

        if (collision) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}