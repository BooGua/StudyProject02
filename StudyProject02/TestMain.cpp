#include<iostream>
#include"InvariantParameter.h"
#include"ArrayJingYaLi.h"
#include"ArgClass.h"

using namespace std;


void setParameter(double pressureClose, double volume, double radius, double height,
	double length, int num, double cH, double dH) {

	InvariantParameter invariantParameter(pressureClose, volume, radius, height, length,
		num, cH, dH);
}

double getPressure(double pressureJ, double q, double sandMass, double dVolume, int kind, double dVorD,
	double dTorT, double resistanceBend, double speedFlow, double slope, double sandRatio, double dragReduction,
	double holeLength, double holeDensity, double emissvity) {

	ArgClass argClass(pressureJ, q, sandMass, dVolume, kind, dVorD, dTorT, resistanceBend, speedFlow,
		slope, sandRatio, dragReduction, holeLength, holeDensity, emissvity);

	argClass.Calculator();

	ArrayJingYaLi arrayJingYaLi;
	arrayJingYaLi.attach(argClass);

	return arrayJingYaLi.CalculateJingYaLi();
}

void main() {
	/*
	���������࣬������
	*/
	double pressureClose = 24; //�պ�ѹ��
	double volume = 25.5495; //��ֱ��Ͳ���
	double radius = 0.115; //�׹��ھ�
	double height = 2461; //����
	double length = 3718; //б��
	int num = 48; //���۸���,=��׶γ��ȡ������ܶȡ�������
	double cH = 0.8; //����ϵ��
	double dH = 1; //����ֱ��

	//setParameter(pressureClose, volume, radius, height, length, num, cH, dH);

	InvariantParameter invariantParameter(pressureClose, volume, radius, height, length, num, cH, dH);

	/*
	�ı���
	*/
	double pressureJ = 63.81; //��ѹ
	double q = 12.388; //�ų�����
	double sandMass = 1;
	double dVolume = 2;
	int kind = 1;
	double dVorD = 1780; //100Ŀ��֧�ż�����ܶ�
	double dTorT = 3220; //100Ŀ��֧�ż����ܶ�
	double resistanceBend = 1;
	double speedFlow = 0.00489; //����ϵ����Һ�岻ͬ�������仯
	double slope = 1;
	double sandRatio = 3.03; //ɰ��
	double dragReduction = 1;

	double holeLength = 1;
	double holeDensity = 1;
	double emissvity = 1;

	//double result = getPressure(pressureJ, q, sandMass, dVolume, kind, dVorD, dTorT, resistanceBend, speedFlow,
		//slope, sandRatio, dragReduction, holeLength, holeDensity, emissvity);
	//cout << result << endl;


	ArgClass argClass(pressureJ, q, sandMass, dVolume, kind, dVorD, dTorT, resistanceBend, speedFlow,
		slope, sandRatio, dragReduction, holeLength, holeDensity, emissvity);
	argClass.PrintArgClass();
	argClass.Calculator();
	argClass.PrintArgClass();

	ArrayJingYaLi arrayJingYaLi;
	arrayJingYaLi.attach(argClass);

	cout << arrayJingYaLi.CalculateJingYaLi() << endl;

}
