#include"InvariantParameter.h"
#include"ArrayJingYaLi.h"
#include"ArgClass.h"

double InvariantParameter::pressureClose;//�պ�ѹ��(���Ƶ�λ Mpa  Ӣ�Ƶ�λpsi)
double InvariantParameter::volume;//��ֱ��Ͳ���:����*�׹����  (���Ƶ�λm^3 Ӣ�Ƶ�λbbl)
double InvariantParameter::radius;//��Ͳ�뾶(���Ƶ�λm Ӣ�Ƶ�λinch)
double InvariantParameter::height;//��׶��в�����(���Ƶ�λm Ӣ�Ƶ�λft)
double InvariantParameter::length;//��׶��в�б��(���Ƶ�λm Ӣ�Ƶ�λft)
int    InvariantParameter::num;//���۸��� (��λ��),=��׶γ��ȡ������ܶȡ�������
double InvariantParameter::cH;//����ϵ��,���������Ħ�� (��λ��) 0.8-1
double InvariantParameter::dH;//����ֱ��(���Ƶ�λmmӢ�Ƶ�λinch)

InvariantParameter::InvariantParameter() {}

InvariantParameter::InvariantParameter(double pressureClose, double volume, double radius, double height, double length,
	int num, double cH, double dH) //8��������
{
	this->pressureClose = pressureClose;
	this->volume = volume;
	this->radius = radius;
	this->height = height;
	this->length = length;
	this->num = num;
	this->cH = cH;
	this->dH = dH;
}


InvariantParameter::~InvariantParameter() {}