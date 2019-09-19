/*
 * @Description: problem 3: 华容道
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-04 15:01:42
 * @Author: lydia
 * @Date: 2019-09-04 12:11:50
 */

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

enum DIRECTION {
    LEFT,
    RIGHT,
    UP,
    DOWN
};
struct status {
    bool current = false;
    bool left = false; //是否被访问过
    bool right = false;
    bool up = false;
    bool down = false;
};

class HuaRongDao {
public:
    HuaRongDao(int _targetx, int _targety, int _posx, int _posy, int _row = 3, int _col = 3)
        : targetx(_targetx)
        , targety(_targety)
        , startx(_posx)
        , starty(_posy)
        , row(_row)
        , col(_col)
    {
        status s;
        mmap = vector<vector<status>>(row, vector<status>(col, s));

        cout << startx << "," << starty << " => " << targetx << "," << targety << "\n";
    };
    void access()
    {
        route(startx, starty);
        if (res) {
            cout << "can arrive\n";
            while (!mroute.empty()) {
                switch (mroute.top()) {
                case LEFT:
                    cout << "LEFT\t";
                    break;
                case RIGHT:
                    cout << "RIGHT\t";
                    break;
                case UP:
                    cout << "UP\t";
                    break;
                case DOWN:
                    cout << "DOWN\t";
                    break;
                default:
                    break;
                }

                mroute.pop();
            }
            cout << "\n";
        } else {
            cout << "can't arrive \n";
        }
    }

private:
    bool route(int posx, int posy)
    {
        if (res) {
            return false;
        }
        if (posx == targetx && posy == targety) {
            cout << "arrived\n";
            res = true;
            return true;
        }
        if (mmap[posx][posy].current) {
            cout << "(" << posx << "," << posy << ")BACK\t";
            return false;
        }
        mmap[posx][posy].current = true;
        bool left = search(LEFT, posx, posy);
        bool right = search(RIGHT, posx, posy);
        bool up = search(UP, posx, posy);
        bool down = search(DOWN, posx, posy);

        if (!left && !right && !up && !down) { //走入死胡同，后退一步
            mroute.pop();
            return false;
        }

        return true;
    }
    bool search(DIRECTION dir, int posx, int posy)
    {
        if (!isDirect(dir, posx, posy)) {
            return false;
        } else {
            switch (dir) {
            case LEFT:
                mmap[posx][posy].left = true;
                mmap[posx][posy - 1].right = true;
                mroute.push(LEFT);
                cout << "(" << posx << "," << posy << ")LEFT\t";
                if (!route(posx, posy - 1)) {
                    cout << "BACK\t";
                    mroute.pop();
                    return false;
                }
                break;
            case RIGHT:
                mmap[posx][posy].right = true;
                mmap[posx][posy + 1].left = true;
                mroute.push(RIGHT);
                cout << "(" << posx << "," << posy << ")RIGHT\t";
                if (!route(posx, posy + 1)) {
                    cout << "BACK\t";
                    mroute.pop();
                    return false;
                }
                break;
            case UP:
                mmap[posx][posy].up = true;
                mmap[posx - 1][posy].down = true;
                mroute.push(UP);
                cout << "(" << posx << "," << posy << ")UP\t";
                if (!route(posx - 1, posy)) {
                    cout << "BACK\t";
                    mroute.pop();
                    return false;
                }
                break;
            case DOWN:
                mmap[posx][posy].down = true;
                mmap[posx + 1][posy].up = true;
                mroute.push(DOWN);
                cout << "(" << posx << "," << posy << ")DOWN\t";
                if (!route(posx + 1, posy)) {
                    cout << "BACK\t";
                    mroute.pop();
                    return false;
                }
                break;

            default:
                break;
            }
        }

        return true;
    };
    bool isDirect(DIRECTION dir, int r, int c)
    {
        switch (dir) {
        case DIRECTION::LEFT:
            if (c == 0 || mmap[r][c].left)
                return false;
            return true;
            break;
        case DIRECTION::RIGHT:
            if (c == col - 1 || mmap[r][c].right)
                return false;
            return true;
            break;
        case DIRECTION::UP:
            if (r == 0 || mmap[r][c].up)
                return false;
            return true;
            break;
        case DIRECTION::DOWN:
            if (r == row - 1 || mmap[r][c].down)
                return false;
            return true;
            break;
        }
    };

private:
    vector<vector<status>>
        mmap; //地图
    int targetx, targety;
    int row, col;
    int startx, starty;
    bool res = false;

    stack<DIRECTION>
        mroute;
};

int main()
{
    int posx = 1, posy = 2, targetx = 2, targety = 2;
    HuaRongDao* game = new HuaRongDao(targetx, targety, posx, posy);
    game->access();
    return 0;
}