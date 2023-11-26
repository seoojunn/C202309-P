#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//입력한 시간만큼 대기하는 함수블록
void delay(int seconds) {
    clock_t start_time = clock(); //현재 시간
    clock_t wait_time = seconds * CLOCKS_PER_SEC; //대기할 시간 계산

    while (clock() < start_time + wait_time); // 대기하기
}
// 랜덤 모듈을 사용하여 가상 날씨를 생성
int generateRandomWeather() {
    return rand() % 101;
}

// 날씨 정보 출력
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
    else if (weatherValue >= 26)
        weatherString = "흐림";
    else if (weatherValue >= 20)
        weatherString = "소나기";
    else
        weatherString = "비";

    printf("현재 날씨: %s\n", weatherString);
}
// 날씨에 따른 음악 선택
void chooseMusic(int weatherValue) {
    if (weatherValue >= 26) {
        printf("선택된 음악: 잔잔한 음악\n");
    }
    else {
        printf("선택된 음악: 쾌할한 노래\n");
    }
}

int main() {
    int hour, minute;

    printf("몇 시간 후에 알람을 울릴까요? (24시간 형식)\n");
    printf("시간: ");
    scanf_s("%d", &hour);

    printf("분: ");
    scanf_s("%d", &minute);

    printf("알람이 설정되었습니다. %d:%d 후에 울립니다.\n", hour, minute);

    // 시간 변환 후 대기
    delay(hour * 3600 + minute * 60);

    printf("일어나세요!\n");

    // 가상 날씨 생성
    int weatherValue = generateRandomWeather();

    // 날씨 정보 출력
    printWeatherInfo(weatherValue);

    // 날씨에 따른 음악 선택 및 출력
    chooseMusic(weatherValue);

    return 0;
}

