#include <iostream>


const int KNUT_TO_SICKLE = 29;
const int SICKLE_TO_GALLEON = 17;
const int KNUT_TO_GALLEON = KNUT_TO_SICKLE * SICKLE_TO_GALLEON;


int main() {

    int knuts;
    std::cin >> knuts;

    int galleons = knuts / KNUT_TO_GALLEON;
    knuts = knuts % KNUT_TO_GALLEON;
    int sickles = knuts / KNUT_TO_SICKLE;
    knuts = knuts % KNUT_TO_SICKLE;

    std::cout << galleons << ' ' << sickles << ' ' << knuts << std::endl;

    return 0;
}