#include <iostream>
// using namespace std;

struct Card {char suit, value;};

void bubbleSort(struct Card C[], int N) {
    bool flag = 1;
    int count = 0;
    for (int i = 0; flag; i++) { //未ソート部分の先頭idx
        flag = 0;
        for (int j = N - 1; j >= i+ 1; j--) {
            if (C[j].value < C[j-1].value) { // <=としないことで安定に
                int tmpS = C[j].suit;
                int tmpV = C[j].value;
                C[j].suit = C[j-1].suit;
                C[j].value = C[j-1].value;
                C[j-1].suit = tmpS;
                C[j-1].value = tmpV;
                flag = 1;
                count++;
            }
        }
    }
}

void selectionSort(struct Card C[], int N) {

}

void printCards(struct Card C[], int N) {
    for(int i; i < N; i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << C[i].value;
    }
    std::cout << std::endl;
} 

int main() {
    Card Cb[100], Cs[100];
    int n;
    char ch;
    std::cin >> n;
    for(int i; i < n; i++) {
        std::cin >> Cb[i].suit >> Cb[i].value;
    }
    for (int i;i < n;i++) Cs[i] = Cb[i];
    bubbleSort(Cb, n);
    // printCards(Cb, n);
    // printCards(Cs, n);

    for(int j; j < n; j++) {
        if (j > 0) {
            std::cout << " ";
        }
        std::cout << Cb[j].value;
    }
    std::cout << std::endl;

    for(int k; k < n; k++) {
        if (k > 0) {
            std::cout << " ";
        }
        std::cout << Cs[k].value;
    }
    std::cout << std::endl;
}
