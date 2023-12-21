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
    
// 알람이 해제되지 않았을 경우 무한루프
    while (1) {
        // 알람이 해제되었을 경우
        if (myAlarm->release[0] == 'h' && myAlarm->release[1] == 'a' && myAlarm->release[2] == 'e' && myAlarm->release[3] == 'j' && myAlarm->release[4] == 'e' && myAlarm->release[5] == '\0') {
            // 가상 날씨 생성
            int weatherValue = generateRandomWeather();

            // 날씨 정보 출력
            printWeatherInfo(weatherValue);

            // 날씨에 따른 음악 선택 및 출력
            chooseMusic(weatherValue);

            // 알람이 해제되었음을 출력
            printf("알람이 해제되었습니다.\n");
            break; // 반복문 탈출
        }
        else {
            // 알람 해제 실패 시 처리
            increaseReleaseAttempts(myAlarm);
            printf("알람 해제에 실패하였습니다. 현재 %d번째 시도입니다.\n", getReleaseAttempts(myAlarm));

            if (getReleaseAttempts(myAlarm) >= 5) {
                printf("알람음이 커집니다!\n");
            }

            // 알람 해제 실패했을 때 계속 입력 요청
            printf("알람 해제에 실패했습니다. 'haeje'를 입력하세요: ");
            scanf_s("%s", myAlarm->release, sizeof(myAlarm->release));
            fflush(stdin); // 입력 버퍼 날리기
        }
    }
    // 동적 메모리 해제
    destroyAlarm(myAlarm);

    return 0;
}