#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "alarm.h"

// �Է��� �ð���ŭ ����ϴ� �Լ����
void delay(int seconds) {
    clock_t start_time = clock(); // ���� �ð�
    clock_t wait_time = seconds * CLOCKS_PER_SEC; // ����� �ð� ���

    while (clock() < start_time + wait_time); // ����ϱ�
}

// ���� ����� ����Ͽ� ���� ������ �����ϴ� �Լ����
int generateRandomWeather() {
    srand((unsigned int)time(NULL)); //�õ� �ʱ�ȭ

    int randomValue = rand() % 101;
    randomValue = (randomValue + rand()) % 101;

    return randomValue;
}

// ���� ���� ��� �Լ����
void printWeatherInfo(int weatherValue) {
    const char* weatherString = NULL;

    if (weatherValue >= 90)
        weatherString = "�ſ� ����";
    else if (weatherValue >= 76)
        weatherString = "����";
    else if (weatherValue >= 60)
        weatherString = "����";
    else if (weatherValue >= 50)
        weatherString = "������";
    else if (weatherValue >= 26 && weatherValue < 50)
        weatherString = "�帲";
    else if (weatherValue >= 20 && weatherValue < 26)
        weatherString = "�ҳ���";
    else
        weatherString = "��";

    printf("���� ����: %s\n", weatherString);
}

// ������ ���� ���� ���� �Լ����
void chooseMusic(int weatherValue) {
    if (weatherValue >= 26) {
        printf("���õ� ����: ��Ȱ�� �뷡\n");
    }
    else {
        printf("���õ� ����: ������ ����\n");
    }
}

// �˶� ����ü�� �������� �����ϴ� �Լ����
Alarm* createAlarm(int hour, int minute) {
    Alarm* newAlarm = (Alarm*)malloc(sizeof(Alarm));

    newAlarm->hour = hour;
    newAlarm->minute = minute;
    newAlarm->release[0] = '\0'; // release ���ڿ� �ʱ�ȭ

    return newAlarm;
}

// �������� �Ҵ�� �˶� ����ü�� �����ϴ� �Լ����
void destroyAlarm(Alarm* alarm) {
    free(alarm);
}

// �˶��� �����ϰ� ������ �� �˶��� �︮�� �Լ����
void setAlarm(Alarm* alarm) {
    printf("�˶��� �����Ǿ����ϴ�. %d:%d �Ŀ� �︳�ϴ�.\n", alarm->hour, alarm->minute);
    delay(alarm->hour * 3600 + alarm->minute * 60);
    printf("�Ͼ����!\n");
}

// �˶��� �����ϴ� �Լ����
void releaseAlarm(Alarm* alarm) {
    printf("�˶��� �����Ϸ��� 'haeje'�� �Է��ϼ���: ");
    scanf_s("%s", alarm->release, sizeof(alarm->release));
}