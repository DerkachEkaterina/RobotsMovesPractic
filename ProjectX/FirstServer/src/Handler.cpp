#include "Handler.h"

void request(Robot_Actions action, unsigned char* request, unsigned char power)
{
    request[0] = 0xAA;
    if (action == Robot_Actions::UP) {
        request[1] = 0x01;
        request[2] = power;
        request[3] = power;
        request[4] = 0x00;
        request[5] = 0x00;
    }
    else if (action == Robot_Actions::DOWN) {
        request[1] = 0x01;
        request[2] = power;
        request[3] = power;
        request[4] = 0x01;
        request[5] = 0x01;
    }
    else if (action == Robot_Actions::LEFT) {
        request[1] = 0x01;
        request[2] = power;
        request[3] = power;
        request[4] = 0x01;
        request[5] = 0x00;
    }
    else if (action == Robot_Actions::RIGHT) {
        request[1] = 0x01;
        request[2] = power;
        request[3] = power;
        request[4] = 0x00;
        request[5] = 0x01;
    }
    else if (action == Robot_Actions::HEAD_LEFT) {
        request[1] = 0x02;
        request[2] = power;
        request[3] = 0x00;
        request[4] = 0x00;
        request[5] = 0x00;
    }
    else if (action == Robot_Actions::HEAD_RIGHT) {
        request[1] = 0x02;
        request[2] = power;
        request[3] = 0x00;
        request[4] = 0x01;
        request[5] = 0x00;
    }
}

char* request(Robot_Actions action, char power) {
    char* request = new char[6];
    request[0] = 0xAA;
    if (action == Robot_Actions::UP) {
        request[1] = 0x01;
        request[2] = power;
        request[3] = power;
        request[4] = 0x00;
        request[5] = 0x00;
        return request;
    }
    if (action == Robot_Actions::LEFT) {
        request[1] = 0x01;
        request[2] = power;
        request[3] = power;
        request[4] = 0x01;
        request[5] = 0x01;
        return request;
    }
    if (action == Robot_Actions::DOWN) {
        request[1] = 0x01;
        request[2] = power;
        request[3] = power;
        request[4] = 0x01;
        request[5] = 0x00;
        return request;
    }
    if (action == Robot_Actions::RIGHT) {
        request[1] = 0x01;
        request[2] = power;
        request[3] = power;
        request[4] = 0x00;
        request[5] = 0x01;
        return request;
    }

    if (action == Robot_Actions::HEAD_LEFT) {
        request[1] = 0x02;
        request[2] = power;
        request[3] = 0x00;
        request[4] = 0x00;
        request[5] = 0x00;
        return request;
    }
    if (action == Robot_Actions::HEAD_RIGHT) {
        request[1] = 0x02;
        request[2] = power;
        request[3] = power;
        request[4] = 0x01;
        request[5] = 0x01;
        return request;
    }
}
