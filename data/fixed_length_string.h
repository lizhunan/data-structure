#define MAX_SIZE 50 //Ĭ�ϳ���Ϊ50

//����˳��洢��ʽ
typedef struct FlString
{
	char data[MAX_SIZE];
	int length;
}FlString;

void StrAssign(FlString &str, char cstr[]); //������
void StrCopy(FlString &str, FlString st); //���ƴ�
int StrLength(FlString s); //�󴮳�
FlString Concat(FlString s, FlString t); //������
FlString SubStr(FlString s, int i, int j); //���Ӵ�
FlString InsStr(FlString s1, int i, FlString t); //������
FlString DelStr(FlString s, int i, int j); //ɾ����
void DispStr(FlString s); //�����
