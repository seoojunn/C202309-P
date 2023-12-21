#include <stdio.h>
#include "alarm.h"

int main() {
    int hour, minute;

    printf("�� �ð� �Ŀ� �˶��� �︱���? (24�ð� ����)\n");
    printf("�ð�: ");
    scanf_s("%d", &hour);

    printf("��: ");
    scanf_s("%d", &minute);

    // ����ü�� ���� �޸� �Ҵ��� �̿��� �˶� ����
    Alarm* myAlarm = createAlarm(hour, minute);

    setAlarm(myAlarm);

    // �˶� ���� ���
    releaseAlarm(myAlarm);
    
// �˶��� �������� �ʾ��� ��� ���ѷ���
    while (1) {
        // �˶��� �����Ǿ��� ���
        if (myAlarm->release[0] == 'h' && myAlarm->release[1] == 'a' && myAlarm->release[2] == 'e' && myAlarm->release[3] == 'j' && myAlarm->release[4] == 'e' && myAlarm->release[5] == '\0') {
            // ���� ���� ����
            int weatherValue = generateRandomWeather();

            // ���� ���� ���
            printWeatherInfo(weatherValue);

            // ������ ���� ���� ���� �� ���
            chooseMusic(weatherValue);

            // �˶��� �����Ǿ����� ���
            printf("�˶��� �����Ǿ����ϴ�.\n");
            break; // �ݺ��� Ż��
        }
        else {
            // �˶� ���� ���� �� ó��
            increaseReleaseAttempts(myAlarm);
            printf("�˶� ������ �����Ͽ����ϴ�. ���� %d��° �õ��Դϴ�.\n", getReleaseAttempts(myAlarm));

            if (getReleaseAttempts(myAlarm) >= 5) {
                printf("�˶����� Ŀ���ϴ�!\n");
            }

            // �˶� ���� �������� �� ��� �Է� ��û
            printf("�˶� ������ �����߽��ϴ�. 'haeje'�� �Է��ϼ���: ");
            scanf_s("%s", myAlarm->release, sizeof(myAlarm->release));
            fflush(stdin); // �Է� ���� ������
        }
    }
    // ���� �޸� ����
    destroyAlarm(myAlarm);

    return 0;
}