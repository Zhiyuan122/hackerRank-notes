/*
使用 vector<int> 来存储多个考试分数
vector<int> v;
v.push_back(10);  // 添加元素 10 到 v 的末尾
cout << v[0];  // 输出第一个元素
int sum = accumulate(v.begin(),v.end(),0); // 求和)

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student
{
private:
    int s1, s2, s3, s4, s5;

public:
    void input()
    {
        cin >> s1 >> s2 >> s3 >> s4 >> s5;
    }
    int calculateTotalScore()
    {
        return s1 + s2 + s3 + s4 + s5;
    }
};

int main()
{
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++)
    {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score)
        {
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
