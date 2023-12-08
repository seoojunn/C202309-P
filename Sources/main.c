#include <stdio.h>
#include "alarm.h"

int main() {
    int hour, minute;

    printf("몇 시간 후에 알람을 울릴까요? (24시간 형식)\n");
    printf("시간: ");
    scanf_s("%d", &hour);

    printf("분: ");
    scanf_s("%d", &minute);

    // 구조체와 동적 메모리 할당을 이용한 알람 생성
    Alarm* myAlarm = createAlarm(hour, minute);

    setAlarm(myAlarm);

    // 알람 해제 기능
    releaseAlarm(myAlarm);

    // 알람이 해제되었을 경우
    if (myAlarm->release[0] == 'h' && myAlarm->release[1] == 'a' && myAlarm->release[2] == 'e' && myAlarm->release[3] == 'j' && myAlarm->release[4] == 'e' && myAlarm->release[5] == '\0') {
        // 가상 날씨 생성
        int weatherValue = generateRandomWeather();

        // 날씨 정보 출력
        printWeatherInfo(weatherValue);

        // 날씨에 따른 음악 선택 및 출력
        chooseMusic(weatherValue);
    }
    else {
        printf("알람이 계속 울립니다.\n");
    }

    // 동적 메모리 해제
    destroyAlarm(myAlarm);

    return 0;
}