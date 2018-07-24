#define MAX_SIZE 50 //默认长度为50

//定长顺序存储方式
typedef struct FlString
{
	char data[MAX_SIZE];
	int length;
}FlString;

void StrAssign(FlString &str, char cstr[]); //创建串
void StrCopy(FlString &str, FlString st); //复制串
int StrLength(FlString s); //求串长
FlString Concat(FlString s, FlString t); //串连接
FlString SubStr(FlString s, int i, int j); //求子串
FlString InsStr(FlString s1, int i, FlString t); //串插入
FlString DelStr(FlString s, int i, int j); //删除串
void DispStr(FlString s); //输出串
