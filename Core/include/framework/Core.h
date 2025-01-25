#include<stdio.h>

namespace ss
{
	#define LOG_DATA(D,...) printf(D"\n",####__VA_ARGS__)
}