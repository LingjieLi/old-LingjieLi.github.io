/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-30 20:43:41
 * @Author: lydia
 * @Date: 2019-08-30 20:43:41
 */

#include <iostream>

using namespace std;

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <stdint.h>

using namespace std;

struct LinkNode {
    uint64_t key;
    uint64_t value;
    LinkNode* next = NULL;
};

struct SkipLinkNode {
    uint64_t key;
    int count;
    LinkNode* pointer = NULL;
    SkipLinkNode* next = NULL;
};

class SkipLinkList {
public:
    SkipLinkList(int skipStep = 128);
    ~SkipLinkList();
    bool simpleCheck();

public:
    void insert(uint64_t key, uint64_t value);
    bool find(uint64_t key, uint64_t& value);

private:
    LinkNode* _listHeader = NULL;
    SkipLinkNode* _skipListHeader = NULL;
    int _skipStep;
    int _itemCount;
};

SkipLinkList::SkipLinkList(int skipStep)
    : _skipStep(skipStep)
    , _listHeader(NULL)
    , _skipListHeader(NULL)
    , _itemCount(0)
{
}

SkipLinkList::~SkipLinkList()
{
    LinkNode* node = _listHeader;
    while (node != NULL) {
        LinkNode* toDelNode = node;
        node = node->next;
        delete toDelNode;
    }

    SkipLinkNode* skipNode = _skipListHeader;
    while (skipNode != NULL) {
        SkipLinkNode* toDelNode = skipNode;
        skipNode = skipNode->next;
        delete toDelNode;
    }
}

bool SkipLinkList::simpleCheck()
{
    uint64_t lastKey = 0;
    int nodeCount = 0;
    LinkNode* node = _listHeader;
    while (node != NULL) {
        nodeCount++;
        if (node->key < lastKey) {
            return false;
        }
        lastKey = node->key;
        node = node->next;
    }
    if (nodeCount < _skipStep) {
        return (_skipListHeader == NULL);
    }

    lastKey = 0;
    int skipNodeCount = 0;
    int expectNodeCount = 0;
    SkipLinkNode* skipNode = _skipListHeader;
    while (skipNode != NULL) {
        skipNodeCount++;
        if (skipNode->key < lastKey) {
            return false;
        }
        lastKey = skipNode->key;
        expectNodeCount += skipNode->count;
        skipNode = skipNode->next;
    }
    return nodeCount == expectNodeCount && skipNodeCount >= ((nodeCount + _skipStep - 1) / _skipStep);
}

void SkipLinkList::insert(uint64_t key, uint64_t value)
{
    // TODO:
    SkipLinkNode* skipNode = _skipListHeader;
    if (skipNode == NULL) {
        _listHeader = new LinkNode;
        _listHeader->key = key;
        _listHeader->value = value;

        _skipListHeader = new SkipLinkNode;
        _skipListHeader->count = _skipStep;
        _skipListHeader->key = key;
        _skipListHeader->next = NULL;
        _skipListHeader->pointer = _listHeader;
    }
    SkipLinkNode* _lastSkipNode = skipNode;
    while (skipNode != NULL && skipNode->key < key) {
        _lastSkipNode = skipNode;
        skipNode = skipNode->next;
    }

    if (skipNode == NULL) { //尾部插入
        LinkNode* pNode = _lastSkipNode->pointer;
        LinkNode* insertPoint = _lastSkipNode->pointer; //插入点
        bool isChange = false;
        int nowSize = 0;
        while (pNode != NULL) {
            if (pNode->key == key) {
                pNode->value == value;
                isChange = true;
                break;
            }
            if (pNode->key < key) {
                insertPoint = pNode;
            }
            nowSize++;
            pNode = pNode->next;
        }
        if (!isChange) {
            LinkNode* insertNode = new LinkNode;
            insertNode->key = key;
            insertNode->value = value;
            if (nowSize == _skipStep) { //增加跳表
                insertNode->next = NULL;
                _lastSkipNode = new SkipLinkNode;
                _lastSkipNode->count = _skipStep;
                _lastSkipNode->key = key;
                _lastSkipNode->next = NULL;
                _lastSkipNode->pointer = insertNode;

            } else { //不需要增加跳表

                insertNode->next = insertPoint->next;
                insertPoint->next = insertNode;
            }
        }

    } else if (skipNode->key >= key) { //中间插入

        LinkNode* insertNode = new LinkNode;
        insertNode->key = key;
        insertNode->value = value;

        LinkNode* pNode = _lastSkipNode->pointer;
        LinkNode* insertPoint = _lastSkipNode->pointer; //插入点
        bool isChange = false;
        int nowSize = 0;
        while (pNode != NULL) {
            if (pNode->key == key) {
                pNode->value == value;
                isChange = true;
                break;
            }
            if (pNode->key < key) {
                insertPoint = pNode;
            }
            nowSize++;
            pNode = pNode->next;
        }

        if (!isChange) {
            if (nowSize == _skipStep) {
                _lastSkipNode = _lastSkipNode->next;
                insertPoint = _lastSkipNode->pointer; //插入点
                while (nowSize == _skipStep && _lastSkipNode != NULL) {
                    nowSize = 0;
                    while (pNode != NULL) {
                        if (pNode->key == key) {
                            pNode->value == value;
                            isChange = true;
                            break;
                        }
                        if (pNode->key < key) {
                            insertPoint = pNode;
                        }
                        nowSize++;
                        pNode = pNode->next;
                    }

                    _lastSkipNode = _lastSkipNode->next;
                    insertPoint = _lastSkipNode->pointer; //插入点
                }

                if (nowSize == _skipStep) {
                    ///增加跳表
                    insertNode->next = NULL;
                    _lastSkipNode = new SkipLinkNode;
                    _lastSkipNode->count = _skipStep;
                    _lastSkipNode->key = key;
                    _lastSkipNode->next = NULL;
                    _lastSkipNode->pointer = insertNode;
                } else {
                    insertNode->next = insertPoint->next;
                    insertPoint->next = insertNode;
                }

            } else {
                insertNode->next = insertPoint->next;
                insertPoint->next = insertNode;
            }
        }
    }
}

bool SkipLinkList::find(uint64_t key, uint64_t& value)
{
    // TODO:

    SkipLinkNode* pSkipNode = _skipListHeader;
    SkipLinkNode* lastSkipNode = _skipListHeader;
    while (pSkipNode != NULL) {
        if (pSkipNode->key > key) {
            LinkNode* pNode = lastSkipNode->pointer;
            while (pNode != NULL) {
                if (pNode->key == key) {
                    return true;
                }
            }
            return false;

        } else if (pSkipNode->key == key) {
            return true;
        }
        lastSkipNode = pSkipNode;
        pSkipNode = pSkipNode->next;
    }

    LinkNode* pNode = lastSkipNode->pointer;
    while (pNode != NULL) {
        if (pNode->key == key) {
            return true;
        }
        pNode = pNode->next;
    }
    return false;
}

vector<string> splitString(const string& text, const string& sepStr)
{
    vector<string> vec;
    string str(text);
    string sep(sepStr);
    size_t n = 0, old = 0;
    while (n != string::npos) {
        n = str.find(sep, n);
        if (n != string::npos) {
            vec.push_back(str.substr(old, n - old));
            n += sep.length();
            old = n;
        }
    }
    vec.push_back(str.substr(old, str.length() - old));
    return vec;
}
template <typename T>
bool stringToInteger(const string& text, T& value)
{
    const char* str = text.c_str();
    char* endPtr = NULL;
    value = (T)strtol(str, &endPtr, 10);
    return (endPtr && *endPtr == 0);

    bool testSkipLinkList(string inputParam)
    {
        vector<string> inputVec = splitString(inputParam, ":");
        if (inputVec.size() != 2 || (inputVec[0] != "list" && inputVec[0] != "count")) {
            cout << "input format error!" << endl;
            return false;
        }
        // prepare data
        vector<pair<uint64_t, uint64_t>> keyValueVec;
        if (inputVec[0] == "list") {
            vector<string> kvVec = splitString(inputVec[1], ";");
            for (size_t i = 0; i < kvVec.size(); i++) {
                vector<string> kvStr = splitString(kvVec[i], ",");
                uint64_t key, value;
                if (kvStr.size() != 2 || !stringToInteger<uint64_t>(kvStr[0], key) || !stringToInteger<uint64_t>(kvStr[1], value)) {
                    cout << "key-value list format error!" << endl;
                    return false;
                }
                keyValueVec.push_back(make_pair(key, value));
            }
        }

        if (inputVec[0] == "count") {
            uint64_t count;
            if (!stringToInteger<uint64_t>(inputVec[1], count)) {
                cout << "count format error!" << endl;
                return false;
            }
            for (uint64_t i = 0; i < count; i++) {
                keyValueVec.push_back(make_pair(i, i));
            }
            random_shuffle(keyValueVec.begin(), keyValueVec.end());
        }

        uint64_t maxKey = 0;
        uint64_t value;

        SkipLinkList list(4);
        for (size_t i = 0; i < keyValueVec.size(); i++) {
            list.insert(keyValueVec[i].first, keyValueVec[i].second);

            // test find
            bool ret = list.find(keyValueVec[i].first, value);
            if (!ret || value != keyValueVec[i].second) {
                cout << "test find error!" << endl;
                return false;
            }
            // test replace
            list.insert(keyValueVec[i].first, keyValueVec[i].second + 1);
            ret = list.find(keyValueVec[i].first, value);
            if (!ret || value != keyValueVec[i].second + 1) {
                cout << "test replace error!" << endl;
                return false;
            }
            maxKey = max(maxKey, keyValueVec[i].first);
        }

        // test not exist key
        if (list.find(maxKey + 1, value)) {
            cout << "find not exist error!" << endl;
            return false;
        }
        return list.simpleCheck();
    }
    int main()
    {
        bool res;
        string _inputParam;
        getline(cin, _inputParam);
        res = testSkipLinkList(_inputParam);
        if (res) {
            cout << "PASS" << endl;
        } else {
            cout << "FAIL" << endl;
        }
        return 0;
    }