#include <iostream>
#include <list>
#include <cstring> // for strcmp

// ��r�p�֐�
bool stationCompare(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

// �w�����X�g��\������֐�
void displayStations(const std::list<const char*>& stations) {
    for (const auto& station : stations) {
        std::cout << station << " -> ";
    }
    std::cout << "END\n";
}

int main() {
    // 1970�N�̎R����w���i�p��\�L�j
    std::list<const char*> yamanoteLine1970 = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
        "Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro",
        "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi",
        "Harajuku", "Shibuya", "Ebisu", "Meguro", "Gotanda", "Osaki",
        "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
    };

    std::cout << "Stations in 1970:\n";
    displayStations(yamanoteLine1970);

    // 1971�N�ɐ����闢�w��ǉ�
    auto it1970 = yamanoteLine1970.begin();
    while (it1970 != yamanoteLine1970.end() && strcmp(*it1970, "Tabata") != 0) {
        ++it1970;
    }
    if (it1970 != yamanoteLine1970.end()) {
        yamanoteLine1970.insert(std::next(it1970), "Nishi-Nippori");
    }

    std::cout << "\nStations in 2019 \n";
    displayStations(yamanoteLine1970);

    // 2020�N�ɍ��փQ�[�g�E�F�C�w��ǉ�
    auto it2020 = yamanoteLine1970.begin();
    while (it2020 != yamanoteLine1970.end() && strcmp(*it2020, "Tamachi") != 0) {
        ++it2020;
    }
    if (it2020 != yamanoteLine1970.end()) {
        yamanoteLine1970.insert(std::next(it2020), "Takanawa Gateway");
    }

    std::cout << "\nStations in 2022 \n";
    displayStations(yamanoteLine1970);

    return 0;
}