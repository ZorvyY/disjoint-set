#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

const int N = 10;
int lead[N];
int size[N];
int count;

void make_set() {
    for (int i = 0; i < N; i++) {
        lead[i] = i;
        size[i] = 1;
    }
    count = N;
    return;
}

int find(int x) {
    if (lead[x] == x) return x;
    lead[x] = find(lead[x]);
    return lead[x];
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x==y) return count;
    if (size[x] < size[y]) {
        lead[x] = y;
        return --count;
    } else {
        lead[y] = x;
        if (size[y] == size[x]) size[x]++;
        return --count;
    }
}

bool connected(int x, int y) {return find(x) == find(y);}

void show_set() {
    vector<int> sets[N];
    for (int i = 0; i < N; i++) {
        find(i);
    }
    for (int i = 0; i < N; i++) {
        sets[find(i)].push_back(i);
    }
    for (int i = 0; i < N; i++) {
        vector<int> cur = sets[i];
        cout << "\n" << i << ": ";
        for (int j = 0; j<cur.size(); j++) {
            cout << cur[j] << " ";
        }
        cout << "\n";
    }
    return;
}

int main(void)
{
    make_set();
    // This loop allows you to mess around with the set 
    while(true) {
        string temp;
        cin >> temp;
        if (temp == "merge") {
            int a, b;
            cin >> a >> b;
            cout << merge(a,b) << endl;
        }
        if (temp == "connected") {
            int a, b;
            cin >> a >> b;
            if (connected(a,b)) cout << "true\n"; else cout << "false\n";
        }
        if (temp == "find") {
            int a;
            cin >> a;
            cout << find(a) << endl;
        }
        show_set();
    }
    
    return 0;
}
