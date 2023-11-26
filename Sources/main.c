#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//�Է��� �ð���ŭ ����ϴ� �Լ����
void delay(int seconds) {
    clock_t start_time = clock(); //���� �ð�
    clock_t wait_time = seconds * CLOCKS_PER_SEC; //����� �ð� ���

    while (clock() < start_time + wait_time); // ����ϱ�
}
// ���� ����� ����Ͽ� ���� ������ ����
int generateRandomWeather() {
    return rand() % 101;
}

// ���� ���� ���
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
    else if (weatherValue >= 26)
        weatherString = "�帲";
    else if (weatherValue >= 20)
        weatherString = "�ҳ���";
    else
        weatherString = "��";

    printf("���� ����: %s\n", weatherString);
}
// ������ ���� ���� ����
void chooseMusic(int weatherValue) {
    if (weatherValue >= 26) {
        printf("���õ� ����: ������ ����\n");
    }
    else {
        printf("���õ� ����: ������ �뷡\n");
    }
}

int main() {
    int hour, minute;

    printf("�� �ð� �Ŀ� �˶��� �︱���? (24�ð� ����)\n");
    printf("�ð�: ");
    scanf_s("%d", &hour);

    printf("��: ");
    scanf_s("%d", &minute);

    printf("�˶��� �����Ǿ����ϴ�. %d:%d �Ŀ� �︳�ϴ�.\n", hour, minute);

    // �ð� ��ȯ �� ���
    delay(hour * 3600 + minute * 60);

    printf("�Ͼ����!\n");

    // ���� ���� ����
    int weatherValue = generateRandomWeather();

    // ���� ���� ���
    printWeatherInfo(weatherValue);

    // ������ ���� ���� ���� �� ���
    chooseMusic(weatherValue);

    return 0;
}

