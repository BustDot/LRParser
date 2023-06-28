#ifndef LRPARSER_SLRPARSER_H
#define LRPARSER_SLRPARSER_H

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

namespace SLR {

    struct Production {
        char left;
        vector<char> rigths;

        bool operator==(Production &rhs) const {
            if (left != rhs.left)
                return false;
            for (int i = 0; i < rigths.size(); i++) {
                if (i >= rhs.rigths.size())
                    return false;
                if (rigths[i] != rhs.rigths[i])
                    return false;
            }
            return true;
        }
    };

/* LR0项目 */
    struct LR0Item {
        Production p;
        /* 点的位置 */
        int location;
    };

/* LR0项目集 */
    struct LR0Items {
        vector<LR0Item> items;
    };

/* LR0项目集规范族 */
    struct CanonicalCollection {
        /* 项目集集合 */
        vector<LR0Items> items;
        /* 保存DFA的图，first为转移到的状态序号，second是经什么转移 */
        vector<pair<int, char> > g[100];
    };

/* 文法结构体 */
    struct Grammar {
        int num;  // 产生式数量
        vector<char> T;   // 终结符
        vector<char> N;   // 非终结符
        vector<Production> prods;  //产生式
    };

    class SLRParser {
        public:
        string str;
        CanonicalCollection CC;
        Grammar grammar;
        map<char, set<char>> first;
        map<char, set<char>> follow;
        queue<pair<LR0Items, int>> Q; // DFA队列， 用于存储待转移的有效项目集
        pair<int, int> action[100][100]; // first表示分析动作，0->ACC 1->S 2->R second表示转移状态或者产生式序号
        int goton[100][100];
        stack<pair<int, char>> ST; // state symbol

        public:
        int isInT(char ch); // 判断ch是否是终结符

        int isInN(char ch); // 判断ch是否是非终结符

        void getFirstSet();

        void getFirstByAlphaSet(vector<char> &alpha, set<char> &FS); // 查找alpha串的FIRST集， 保存到FS集合中

        void getFollowSet();

        bool isInLR0Items(LR0Items &I, LR0Item &t);

        void closure(LR0Items &I);

        void printLR0Items(LR0Items &I);

        int isInCanonicalCollection(LR0Items &I); // 判断是否在项目集规范族中，若在返回序号

        void go(LR0Items &I, char X, LR0Items &J); // 转移函数，I为当前的项目集，J为转移后的项目集, 经X转移

        void DFA(); // 构建DFA和项目集规范族

        void productSLR1AnalysisTable(); // 生成SLR1分析表

        void initGrammar();

        bool process();
    };
}
#endif //LRPARSER_SLRPARSER_H
