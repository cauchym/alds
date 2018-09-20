#include <iostream>

struct Card {char suit, value;};

void printCards(Card C[], int N) {
    for(int i = 0; i < N; i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << C[i].suit << C[i].value;
    }
    std::cout << std::endl;
}

void bubbleSort(Card C[], int N) {
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

void selectionSort(Card C[], int N) {
    int i, j, minj;
    Card t;
    for(i = 0; i < N; i++) {
        minj = i;
        j = i;
        for(j = i; j < N; j++) {
            if (C[j].value < C[minj].value ) {
                minj = j;
            }
        }
        t = C[i];
        C[i] = C[minj];
        C[minj] = t;
    }
}

bool isStable(Card C1[], Card C2[], int n) {
    int i;
    for ( i = 0; i < n; i++ ){
        if ( C1[i].suit != C2[i].suit) {
            return false;
        }
    }
    return true;
}

int main() {
    Card Cb[100], Cs[100];
    int n;
    char ch;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> Cb[i].suit >> Cb[i].value;
    }
    for(int i = 0; i < n; i++) {
        Cs[i] = Cb[i];
    }
    bubbleSort(Cb, n);
    printCards(Cb, n);
    std::cout << "Stable" << std::endl;
    selectionSort(Cs, n);
    printCards(Cs, n);
    if ( isStable(Cb, Cs, n) ){
        std::cout << "Stable" << std::endl;
    } else {
        std::cout << "Not stable" << std::endl;
    }
    std::cout << std::endl;
}
