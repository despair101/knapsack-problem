int bestW = 0;
vector<int> answer;
vector<int> used;

void recursive(int N, int W, const vector<int>& w, int curW, int index) {
    if (index == N) {
        if (bestW < curW && curW <= W) {
            bestW = curW;
            answer = used;
        }
    } else {
        recursive(N, W, w, curW, index + 1);
        used.push_back(index);
        recursive(N, W, w, curW + w[index], index + 1);
        used.pop_back();
    }
}

void solve(int N, int W, const vector<int>& w) {
    recursive(N, W, w, 0, 0);
    cout << "N = " << N << ", W = " << W << "\nw = [ ";
    for (int el : w) {
        cout << el << ' ';
    }
    cout << "]\nBest sum = " << bestW << "\nIndexes for this sum (from 1 to N):\n";
    for (int el : answer) {
        cout << el + 1 << ' ';
    }
}
