#pragma once

//��Ŀ����
//
//ĳ̽�նӸ���Ե��¶�Ѩ����̽�ա� ̽�նӳ�Ա�ڽ���̽������ʱ������Я���ļ�¼���᲻���ڵؼ�¼���������꣬���ڼ�¼�ļ�϶��Ҳ���¼�������ݡ� ̽������������̽�ն���Ҫ��ȡ��ĳ��Ա��̽�չ����������̽�ն��ܲ�����Զ���㼣λ�á�
//
//������¼����ʱ����������ݸ�ʽΪ(x, y)����(1, 2)��(100, 200)������0 < x < 1000��0 < y < 1000��ͬʱ���ڷǷ����꣬��(01, 1)��(1, 01)��(0, 100)���ڷǷ����ꡣ
//	�趨̽�ն��ܲ�������Ϊ(0, 0)��ĳλ������ܲ��ľ���Ϊ��x * x + y * y��
//	���������������ܲ��ľ�����ͬ�����һ�ε��������Ϊ��Զ���㼣��
//	����¼���е����궼���Ϸ�������ܲ����꣨0, 0���� ��ע������Ҫ����˫������Ƕ�׵����������sfsdfsd((1, 2))��
//	�������� :
//
//�ַ�������ʾ��¼���е����ݡ�
//
//�磺ferga13fdsf3(100, 200)f2r3rfasf(300, 400)
//
//������� :
//
//	�ַ�������ʾ��Զ�㼣��������ꡣ
//
//	�磺(300, 400)
//
//	ʾ��1
//
//	����
//
//	1
//	ferg(3, 10)a13fdsf3(3, 4)f2r3rfasf(5, 10)
//	���
//
//	1
//	(5, 10)
//	˵��
//
//	��¼���еĺϷ�������3����(3, 10)��(3, 4)��(5, 10)������(5, 10)������ܲ���Զ�����꣬ ���(5, 10)��
//
//	ʾ��2
//
//	����
//
//	1
//	asfefaweawfaw(0, 1)fe
//	���
//
//	1
//	(0, 0)
//	˵��
//
//	��¼���е����궼���Ϸ�������ܲ�����(0, 0)

#include <string>
#include <vector>
using namespace std;
class hw005
{
public:
	hw005();
	~hw005();
	int Calculation();
private:
	
};