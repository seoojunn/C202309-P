#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "alarm.h"

// 입력한 시간만큼 대기하는 함수블록
void delay(int seconds) {
    clock_t start_time = clock(); // 현재 시간
    clock_t wait_time = seconds * CLOCKS_PER_SEC; // 대기할 시간 계산

    while (clock() < start_time + wait_time); // 대기하기
}

// 랜덤 모듈을 사용하여 가상 날씨를 생성하는 함수블록
int generateRandomWeather() {
    srand((unsigned int)time(NULL)); //시드 초기화

    int randomValue = rand() % 101;
    randomValue = (randomValue + rand()) % 101;

    return randomValue;
}

// 날씨 정보 출력 함수블록
void printWeatherInfo(int weatherValue) {
    const char* weatherString = NULL;

    if (weatherValue >= 90)
        weatherString = "매우 더움";
    else if (weatherValue >= 76)
        weatherString = "더움";
    else if (weatherValue >= 60)
        weatherString = "맑음";
    else if (weatherValue >= 50)
        weatherString = "선선함";
    else if (weatherValue >= 26 && weatherValue < 50)
        weatherString = "흐림";
    else if (weatherValue >= 20 && weatherValue < 26)
        weatherString = "소나기";
    else
        weatherString = "비";

    printf("현재 날씨: %s\n", weatherString);
}

// 날씨에 따른 음악 선택 함수블록
void chooseMusic(int weatherValue) {
    if (weatherValue >= 26) {
        printf("선택된 음악: 쾌활한 노래\n");
    }
    else {
        printf("선택된 음악: 잔잔한 음악\n");
    }
}

// 알람 구조체를 동적으로 생성하는 함수블록
Alarm* createAlarm(int hour, int minute) {
    Alarm* newAlarm = (Alarm*)malloc(sizeof(Alarm));

    newAlarm->hour = hour;
    newAlarm->minute = minute;
    newAlarm->release[0] = '\0'; // release 문자열 초기화

    return newAlarm;
}

// 동적으로 할당된 알람 구조체를 해제하는 함수블록
void destroyAlarm(Alarm* alarm) {
    free(alarm);
}

// 알람을 설정하고 딜레이 후 알람을 울리는 함수블록
void setAlarm(Alarm* alarm) {
    printf("알람이 설정되었습니다. %d:%d 후에 울립니다.\n", alarm->hour, alarm->minute);
    delay(alarm->hour * 3600 + alarm->minute * 60);
    printf("일어나세요!\n");
}

// 알람을 해제하는 함수블록
void releaseAlarm(Alarm* alarm) {
    printf("알람을 해제하려면 'haeje'를 입력하세요: ");
    scanf_s("%s", alarm->release, sizeof(alarm->release));
}