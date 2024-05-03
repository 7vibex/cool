#include <iostream>
#include <vector>

bool esteSecventaCool(const std::vector<int>& secventa, int lungime) {
    for (int i = 0; i < lungime; ++i) {
        for (int j = i + 1; j < lungime; ++j) {
            if (secventa[i] == secventa[j]) {
                return false;
            }
        }
    }

    int minVal = secventa[0];
    int maxVal = secventa[0];
    for (int i = 1; i < lungime; ++i) {
        if (secventa[i] < minVal) {
            minVal = secventa[i];
        }
        if (secventa[i] > maxVal) {
            maxVal = secventa[i];
        }
    }

    return maxVal - minVal + 1 == lungime;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    int maxVal = 0;
    bool foundCoolSequence = false;
    for (int i = 0; i <= n - k; ++i) {
        if (esteSecventaCool(std::vector<int>(A.begin() + i, A.begin() + i + k), k)) {
            foundCoolSequence = true;
            maxVal = A[i];
            for (int j = i + 1; j < i + k; ++j) {
                if (A[j] > maxVal) {
                    maxVal = A[j];
                }
            }
            break;
        }
    }

    if (foundCoolSequence) {
        std::cout << "Secvența este cool. Valoarea maximă din secvență este: " << maxVal << std::endl;
    }
    else {
        std::vector<int> elementeDistincte(A.begin(), A.end());
        std::vector<int> aparitii(n, 0);
        for (int i = 0; i < n; ++i) {
            aparitii[A[i]]++;
        }
        int distincte = 0;
        for (int i = 0; i < n; ++i) {
            if (aparitii[A[i]] == 1) {
                distincte++;
            }
        }
        std::cout << "Secvența nu este cool. Numărul de elemente distincte din șir este: " << distincte << std::endl;
    }

    return 0;
}
