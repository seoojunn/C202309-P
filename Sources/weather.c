#include <stdio.h>
#include <stdlib.h>

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

int main() {
    // 가상 날씨 생성
    int weatherValue = generateRandomWeather();

    // 날씨 정보 출력
    printWeatherInfo(weatherValue);

    return 0;

}