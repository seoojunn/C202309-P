#include <stdio.h>
#include <stdlib.h>

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

int main() {
    // ���� ���� ����
    int weatherValue = generateRandomWeather();

    // ���� ���� ���
    printWeatherInfo(weatherValue);

    return 0;

}