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

    // �˶��� �����Ǿ��� ���
    if (strcmp(myAlarm->release, "haeje") == 0) {
        // ���� ���� ����
        int weatherValue = generateRandomWeather();

        // ���� ���� ���
        printWeatherInfo(weatherValue);

        // ������ ���� ���� ���� �� ���
        chooseMusic(weatherValue);
    }
    else {
        printf("�˶��� ��� �︳�ϴ�.\n");
    }

    // ���� �޸� ����
    destroyAlarm(myAlarm);

    return 0;
}