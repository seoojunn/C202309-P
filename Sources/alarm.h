#pragma once

typedef struct {
    int hour;
    int minute;
    char release[10];
} Alarm;

void delay(int seconds);
int generateRandomWeather();
void printWeatherInfo(int weatherValue);
void chooseMusic(int weatherValue);
Alarm* createAlarm(int hour, int minute);
void destroyAlarm(Alarm* alarm);
void setAlarm(Alarm* alarm);
void releaseAlarm(Alarm* alarm);