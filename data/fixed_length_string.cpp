/*
	����˳��洢��ʽ�ַ���
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
	//��st���Ƹ�str�����ƻ�t��
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
	//������s��t��ɵ��´�
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
	//���ش�s��i��ʼ����j���ַ���ɵ��Ӵ�
	FlString str;
	int k;
	str.length = 0;
	if (i <= 0 || i > s.length || j<0 || i + j - 1>s.length) //�����������ȷ���ؿմ�
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
	//����t���뵽��s1�ĵ�i���ַ���
	int j;
	FlString str;
	str.length = 0;
	if (i <= 0 || i > s1.length + 1) //��������ȷ���ؿմ�
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
	if (i <= 0 || i > s.length || i + j > s.length + 1) //�����������ȷ���ؿմ�
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
