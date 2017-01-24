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
	构建参数类，不变量
	*/
	double pressureClose = 24; //闭合压力
	double volume = 25.5495; //垂直井筒体积
	double radius = 0.115; //套管内径
	double height = 2461; //垂深
	double length = 3718; //斜深
	int num = 48; //孔眼个数,=射孔段长度×孔眼密度×发射率
	double cH = 0.8; //修正系数
	double dH = 1; //孔眼直径

	//setParameter(pressureClose, volume, radius, height, length, num, cH, dH);

	InvariantParameter invariantParameter(pressureClose, volume, radius, height, length, num, cH, dH);

	/*
	改变量
	*/
	double pressureJ = 63.81; //套压
	double q = 12.388; //排出排量
	double sandMass = 1;
	double dVolume = 2;
	int kind = 1;
	double dVorD = 1780; //100目，支撑剂体积密度
	double dTorT = 3220; //100目，支撑剂视密度
	double resistanceBend = 1;
	double speedFlow = 0.00489; //流速系数，液体不同，发生变化
	double slope = 1;
	double sandRatio = 3.03; //砂比
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
