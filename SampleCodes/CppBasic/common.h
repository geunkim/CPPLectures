#ifndef __COMMON_H__
#define __COMMON_H__

#define MANAGERS 100
#define MEMBERS  200
#define ELEMENTS 10
#define MIN      0
#define MAX      255

int min(int x, int y) { return (x > y) ? y : x; }
int max(int x, int y) { return (x > y) ? x : y; }

int find_max(int data[]);
int find_min(int data[]);

#endif