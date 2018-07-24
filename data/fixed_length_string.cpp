/*
	定长顺序存储方式字符串
*/

#include "fixed_length_string.h"
#include "lib.h"

int main()
{
	FlString flstr;
	char cs[] = { 'h','e','l','l','o',' ','w','o','r','l','d','\0' };
	StrAssign(flstr, cs);
	DispStr(flstr);
	DispStr(SubStr(flstr,3,7));
	DispStr(DelStr(flstr,6,6));
	return 0;
}

void StrAssign(FlString & str, char cstr[])
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
	{
		str.data[i] = cstr[i];
	}
	str.length = i;
}

void StrCopy(FlString & str, FlString st)
{
	//将st复制给str（不破坏t）
	int i;
	for (i = 0; i < st.length; i++)
	{
		str.data[i] = st.data[i];
	}
	str.length = st.length;
}

int StrLength(FlString s)
{
	return s.length;
}

FlString Concat(FlString s, FlString t)
{
	//返回由s和t组成的新串
	FlString str;
	int i;
	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++)
	{
		str.data[i] = s.data[i];
	}
	for (i = 0; i < t.length; i++)
	{
		str.data[s.length + 1] = t.data[i];
	}
	return str;
}

FlString SubStr(FlString s, int i, int j)
{
	//返回串s从i开始连续j个字符组成的子串
	FlString str;
	int k;
	str.length = 0;
	if (i <= 0 || i > s.length || j<0 || i + j - 1>s.length) //如果参数不正确返回空串
	{
		return str;
	}
	for (k = i - 1; k < i + j - 1; k++)
	{
		str.data[k - i + 1] = s.data[k];
	}
	str.length = j;
	return str;
}

FlString InsStr(FlString s1, int i, FlString t)
{
	//将串t插入到串s1的第i个字符中
	int j;
	FlString str;
	str.length = 0;
	if (i <= 0 || i > s1.length + 1) //参数不正确返回空串
	{
		return  str;
	}
	for (j = 0; j < i - 1; j++)
	{
		str.data[j] = s1.data[j];
	}
	for (j = 0; j < t.length; j++)
	{
		str.data[i + j - 1] = t.data[j];
	}
	for (j = i - 1; j < s1.length; j++)
	{
		str.data[t.length + j] = s1.data[j];
	}
	str.length = s1.length + t.length;
	return str;
}

FlString DelStr(FlString s, int i, int j)
{
	int k;
	FlString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j > s.length + 1) //如果参数不正确返回空串
	{
		return str;
	}
	for (k = 0; k < i - 1; k++)
	{
		str.data[k] = s.data[k];
	}
	for (k = i + j - 1; k < s.length; k++)
	{
		str.data[k - j] = s.data[k];
	}
	str.length = s.length - j;
	return str;
}

void DispStr(FlString s)
{
	int i;
	if (s.length > 0)
	{
		for (i = 0; i < s.length; i++)
		{
			printf("%c", s.data[i]);
		}
		printf("\n");
	}
}
