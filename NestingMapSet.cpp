#include <bits/stdc++.h>
using namespace std;
int main()
{
    // code here
    // map<pair<int, int>, int> m;
    // pair<int, int> p1, p2;
    // p1 = {2, 3};
    // p2 = {4, 5};
    // cout << (p1 > p2);

    // map<set<int, int>, int> m1;
    // set<int> s1, s2;
    // s1 = {2, 3, 4};
    // s2 = {3, 4};
    // cout << (s1 < s2);

    // suppose we are taking input first name and last name and count of marks
    /*  3
        a b 4
        1 2 3 4
        c d 2
        1 2
        d f 3
        2 3 4*/
    // map<pair<string, string>, vector<int>> m;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; ++i)
    // {
    //     string fn, ln;
    //     int ctn;
    //     cin >> fn >> ln >> ctn;
    //     for (int j = 0; j < ctn; ++j)
    //     {
    //         int x;
    //         cin >> x;
    //         m[{fn, ln}].push_back(x);
    //     }
    // }
    // for (auto &pr : m)
    // {
    //     auto &mFirstPair = pr.first;
    //     auto &mSecondPair = pr.second;
    //     cout << "First Name and Second Name: " << endl;

    //     cout << mFirstPair.first << " " << mFirstPair.second << endl;
    //     cout << "Size of second Pair: " << mSecondPair.size() << endl;
    //     for (auto &element : mSecondPair)
    //     {
    //         cout << element;
    //     }
    //     cout << endl;
    // }

    // map<pair<string, string>, vector<int>> m;
    // m[{"deepak", "tiwari"}].push_back(4);
    // m[{"sakshi", "tiwari"}].push_back(10);
    // m[{"nishtha", "tiwari"}].push_back(30);
    // auto it = m.begin();
    // cout << it->first.first << endl;
    // cout << it->first.second << endl;

    /* the monk and the class Marks*/
    /*  3
        Eve 78
        Bob 99
        Alice 78

        output:
        Bob 99
        Alice 78
        Eve 78
    */
    map<int, set<string>> marks_map;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string name;
        int marks;
        cin >> name >> marks;
        marks_map[-1 * marks].insert(name);
    }
    // auto cur_it = --marks_map.end();
    // while(true)
    for (auto &marks_student_pr : marks_map)
    {
        // auto &students = cur_it->second;
        auto &students = marks_student_pr.second;
        // auto marks = cur_it->first;
        auto marks = marks_student_pr.first;
        for (auto student : students)
        {
            cout << student << " " << -1 * marks << endl;
        }
        // if (cur_it == marks_map.begin())
        //     break;
        // cur_it--;
    }
    return 0;
}