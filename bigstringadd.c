#include <string.h>
#include <assert.h>

/*
 使用字符串来表示２个大数相加
*/
char* bigadd(const char* a, const char* b, char* res)
{
	assert(a && b && res);
	int aLen = strlen(a);
	int bLen = strlen(b);
	int maxLen = (aLen>bLen)?aLen:bLen;
	int minLen = (aLen>bLen)?bLen:aLen;
	const char* maxStr = (aLen>bLen)?a:b;
	const char* minStr = (aLen>bLen)?b:a;

	memset(res, 0, maxLen+2);
	int i = 0;
	for(i = minLen-1; i >= 0; --i)
	{
		res[maxLen-minLen+i+1] += minStr[i] + maxStr[maxLen-minLen+i]-'0';
		if(res[maxLen-minLen+i+1] > '9')
		{
			res[maxLen-minLen+i+1] -= 10;
			res[maxLen-minLen+i] = 1;
		}
	}

	for(i = maxLen-minLen-1; i >= 0; --i)
	{
		res[i+1] += maxStr[i];
		if(res[i+1] > '9')
		{
			res[i+1] -= 10;
			res[i] = 1;
		}
	}

	if(res[0] == 0)
		return res+1;
	else
	{
		res[0] += '0';
		return res;
	}
}
