int bestW = 0;
vector<int> answer, used;
vector<pair<int, vector<int>>> v;

void recursiveFirstPart(int N, int W, const vector<int>& w, int curW, int index) {
    if (index == N) {
        v.emplace_back(curW, used);
    } else {
        recursiveFirstPart(N, W, w, curW, index + 1);
        used.push_back(index);
        recursiveFirstPart(N, W, w, curW + w[index], index + 1);
        used.pop_back();
    }
}

void recursiveSecondPart(int N, int W, const vector<int>& w, int curW, int index) {
    if (index == N) {
        if (curW > W) return;
        if (v.empty() || W - curW < v[0].first) {
            if (bestW < curW && curW <= W) {
                bestW = curW;
                answer = used;
            }
        } else {
            int left = 0, right = v.size();
            while (right - left > 1) {
                int mid = (left + right) / 2;
                (v[mid].first + curW <= W ? left : right) = mid;
            }
            if (curW + v[left].first > bestW) {
                bestW = curW + v[left].first;
                answer = v[left].second;
                answer.insert(answer.end(), used.begin(), used.end());
            }
        }
    } else {
        recursiveSecondPart(N, W, w, curW, index);
        used.push_back(index);
        recursiveSecondPart(N, W, w, curW + w[index], index + 1);
        used.pop_back();
    }
}

void solve(int N, int W, const vector<int>& w) {
    recursiveFirstPart(N / 2, W, w, 0, 0);
    sort(v.begin(), v.end(), [&](auto& l, auto& r) {
        return l.first < r.first;
        });
    recursiveSecondPart(N, W, w, 0, N / 2);
    cout << "N = " << N << ", W = " << W << "\nw = [ ";
    for (int el : w) {
        cout << el << ' ';
    }
    cout << "]\nBest sum = " << bestW << "\nIndexes for this sum (from 1 to N):\n";
    for (int el : answer) {
        cout << el + 1 << ' ';
    }
}
