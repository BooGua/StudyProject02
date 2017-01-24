#pragma once
/*
�������ڴ洢�����������̬����ȫ�ֵ��á�
*/
class InvariantParameter
{
public:
	InvariantParameter();
	InvariantParameter(double pressureClose, double volume, double radius, double height,
		double length, int num, double cH, double dH);
	~InvariantParameter();
public:
	static double  pressureClose;//�պ�ѹ��(���Ƶ�λ Mpa  Ӣ�Ƶ�λpsi)
	static double  volume;//��ֱ��Ͳ���:����*�׹����  (���Ƶ�λm^3 Ӣ�Ƶ�λbbl)
	static double  radius;//��Ͳ�뾶(���Ƶ�λm Ӣ�Ƶ�λinch)
	static double  height;//��׶��в�����(���Ƶ�λm Ӣ�Ƶ�λft)
	static double  length;//��׶��в�б��(���Ƶ�λm Ӣ�Ƶ�λft)
	static int     num;//�ܿ��۸���
	static double  cH;//����ϵ��,���������Ħ�� (��λ��) 0.8-1
	static double  dH;//����ֱ��(���Ƶ�λmmӢ�Ƶ�λinch)
};
