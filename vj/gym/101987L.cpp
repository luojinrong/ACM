#include<iostream>
#include<queue>
#define maxn 2005
using namespace std;
int m, n, w_con, h_bre, eve_need[maxn], want[maxn], work_al[maxn], bre_al[maxn];
//m 人数，n 天数，w_con 持续工作时间，h_bre 最小休息时间
//eve_need 每天需要人数，want 每人想要工作天数，
//work_al 已经工作天数，bre_al 已经休息天数，在一个状态时，另一个状态置为-1
int work_num, flag, work_d[maxn][maxn], pos[maxn];
//work_num 每天在工作人数
//flag 有没有安排方案
//work_d 每个人每次开始工作的日子
//pos 在work_d中记录到的位置，即每个人已工作的次数
struct canwork {
    int rest;
    int pos;
    bool operator<(const canwork&a) const {
        return rest < a.rest;//最大值优先
    }
};
priority_queue<canwork>que;

void pre() {
    work_num = 0;
    for (int i = 0; i < m; i++) {
        if (work_al[i] != -1) {//处理工作
            work_al[i]++;
            if (work_al[i] > w_con) {//当前工人工作天数达标
                work_al[i] = -1;
                bre_al[i] = -2;//-2标记今天刚开始休息方便下面bre++处理
            }
            else {
                work_num++;
            }
        }
        if (bre_al[i] != -1) {//处理休息
            if (bre_al[i] == -2) {
                bre_al[i] = 0;
            }
            else if(bre_al[i]!=-3) {
                bre_al[i]++;
                if (bre_al[i] >= h_bre&&want[i]>=w_con) {
                    que.push({ want[i],i });
                    bre_al[i] = -3;//标记已加入准备队列
                }
            }
        }
    }
}

void plan(int now) {//安排工作,now说明现在是第几天
    while (eve_need[now] > 0 && (!que.empty())) {//找到需要的工人或者不存在空闲工人退出
        canwork tmp = que.top();
        //当前工人加入工作
        want[tmp.pos] -= w_con;
        bre_al[tmp.pos] = -1;
        work_al[tmp.pos] = 1;
        work_d[tmp.pos][pos[tmp.pos]++] = now + 1;
        que.pop();
        eve_need[now]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> w_con >> h_bre;
    flag = 1;//默认可以安排
    for (int i = 0; i < m; i++) {
        cin >> want[i];
        work_al[i] = bre_al[i] = -1;
        if (want[i] >= w_con) {
            que.push({ want[i],i });
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> eve_need[i];
    }
    //输入完成
    for (int i = 0; i < n; i++) {//对于每天进行遍历
        pre();//可得到今天还在工作的人数
        eve_need[i] -= work_num;//得到今天还需要人数
        if (eve_need[i] < 0) {//今天工作人数超标，不满足
            flag = -1;
            break;
        }
        else if (eve_need[i] > 0) {//还需要工人
            plan(i);
        }
        if (eve_need[i] > 0) {//安排不上
            flag = -1;
            break;
        }
    }
    cout << flag << "\n";
    if (flag == 1) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < pos[i]; j++) {
                cout << work_d[i][j] << " \n"[j == (pos[i] - 1)];
            }
        }
    }
}
