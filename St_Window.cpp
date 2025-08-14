#include <iostream>
using namespace std;

// 포션 개수 초기화 포인터호출
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main() {
    int status[4] = {0}; // 0: HP, 1: MP, 2: 공격력, 3: 방어력
    int HPPotion = 0, MPPotion = 0;

    // 1) HP, MP 둘 중 하나라도 50 이하이면 재입력
    while (true) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> status[0] >> status[1];

        if (status[0] > 50 && status[1] > 50) break;
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }

    // 2) 공격력, 방어력 둘 중 하나라도 0 이하이면 재입력
    while (true) {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> status[2] >> status[3];

        if (status[2] > 0 && status[3] > 0) break;
        cout << "다시 입력해주세요.\n";
    }

    // 3) 포션 지급 (포인터로 전달해서 값 변경하게?
    setPotion(5, &HPPotion, &MPPotion);
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";

    // 4) 스탯 관리 
    while (true) {
        cout << "\n<스탯 관리 시스템>\n"
             << "1. HP 회복\n"
             << "2. MP 회복\n"
             << "3. HP 강화\n"
             << "4. MP 강화\n"
             << "5. 공격 스킬 사용\n"
             << "6. 필살기 사용\n"
             << "7. 나가기\n"
             << "번호를 선택해주세요: ";

        int choice;
        cin >> choice;

        if (choice == 7) {
            cout << "시스템을 종료합니다.\n";
            break;
        }
        else if (choice == 1) {               // HP 회복 (포션 1개 소모)
            if (HPPotion > 0) {
                status[0] += 20;
                HPPotion--;
                cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
                cout << "현재 HP: " << status[0] << "\n";
                cout << "남은 포션 수: " << HPPotion << "\n";
            } else {
                cout << "포션이 부족합니다.\n";
            }
        }
        else if (choice == 2) {               // MP 회복 (포션 1개 소모)
            if (MPPotion > 0) {
                status[1] += 20;
                MPPotion--;
                cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
                cout << "현재 MP: " << status[1] << "\n";
                cout << "남은 포션 수: " << MPPotion << "\n";
            } else {
                cout << "포션이 부족합니다.\n";
            }
        }
        else if (choice == 3) {               // HP 강화
            status[0] *= 2;
            cout << "* HP가 2베 증가했습니다. 현재 HP: " << status[0] << "\n";
        }
        else if (choice == 4) {               // MP 강화
            status[1] *= 2;
            cout << "* MP가 2배 증가했습니다. 현재 MP: " << status[1] << "\n";
        }
        else if (choice == 5) {               // 공격 스킬 (MP 50 소모)
            if (status[1] >= 50) {
                status[1] -= 50;
                cout << "* 스킬을 사용하여 MP가 50 소모되었습니다.\n";
                cout << "현재 MP: " << status[1] << "\n";
            } else {
                cout << "스킬 사용이 불가합니다.\n";
            }
        }
        else if (choice == 6) {               // 필살기 (MP 100 소모)
            if (status[1] > 0) {
                status[1] -= status[1]/2 ;
                cout << "* 필살기를 사용하여 MP가 100 소모되었습니다.\n";
                cout << "현재 MP: " << status[1] << "\n";
            } else {
                cout << "필살기 사용이 불가합니다.\n";
            }
        }
        else {
            cout << "잘못된 번호입니다.\n";
        }
    }

    return 0;
}
