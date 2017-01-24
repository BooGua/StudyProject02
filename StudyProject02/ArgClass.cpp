#include <iostream>
#include <math.h>
#include"InvariantParameter.h"
#include"ArrayJingYaLi.h"
#include"ArgClass.h"

using namespace std;

ArgClass::ArgClass() {}

ArgClass::ArgClass(double pressureJ, double q, double sandMass, double dVolume, int kind, double dVorD,
	double dTorT, double resistanceBend, double speedFlow, double slope,
	double sandRatio, double dragReduction, double holeLength, double holeDensity, double emissvity)
{
	this->pressureJ = pressureJ;
	this->q = q;
	this->sandMass = sandMass;
	this->dVolume = dVolume;
	this->kind = kind;
	this->dVorD = dVorD;
	this->dTorT = dTorT;
	this->resistanceBend = resistanceBend;
	this->speedFlow = speedFlow;
	this->slope = slope;
	this->sandRatio = sandRatio;
	this->dragReduction = dragReduction;
	this->holeLength = holeLength;
	this->holeDensity = holeDensity;
	this->emissvity = emissvity;

	this->M = sandMass / InvariantParameter::num; //当前砂质量。

	if (kind == 1) { //压裂液密度。
		this->density = dVorD;
	}
	else if (kind == 2) {
		this->density = (1020 + dVorD * sandRatio) / (1 + dVorD * sandRatio / dTorT);
	}

	this->value_Height = dVolume / 3.14 / InvariantParameter::radius / InvariantParameter::radius;
}

ArgClass::ArgClass(ArgClass argArrayClass, double height) //传入更改高度，砂质量、阶段体积、支撑剂质量也要改变。
{
	this->pressureJ = argArrayClass.getPressureJ();
	this->q = argArrayClass.getQ();
	this->sandMass = argArrayClass.getSandMass();
	this->dVolume = argArrayClass.getdVolume();
	this->kind = argArrayClass.getKind();
	this->dVorD = argArrayClass.getdVorD();
	this->dTorT = argArrayClass.getdTorT();
	this->resistanceBend = argArrayClass.getResistanceBend();
	this->speedFlow = argArrayClass.getSpeedFlow();
	this->slope = argArrayClass.getSlope();
	this->sandRatio = argArrayClass.getSandRatio();
	this->dragReduction = argArrayClass.getDragReduction();
	this->holeLength = argArrayClass.getHoleLength();
	this->holeDensity = argArrayClass.getHoleDensity();
	this->emissvity = argArrayClass.geteEmissvity();

	double bili = argArrayClass.getValue_Height() / height; //改变比例。

	this->sandMass = argArrayClass.getSandMass() / bili; //按比例改变当前砂质量。
	this->dVolume = argArrayClass.getdVolume() / bili; //按比例改变当前阶段体积。
	this->M = argArrayClass.getM() / bili; //按比例改变支撑剂质量。
	this->value_Height = height; //改变高度。

	this->density = argArrayClass.getDensity();

	this->value_JingYeZhu = 0;//井筒静液柱压力归零。
	this->value_MoCaZuLi = 0;//井筒摩擦阻力归零。归零后还需在水平井筒中根据新参数重新计算。
}

void ArgClass::Calculator()
{
	/*
	计算净液柱压力
	*/
	if (kind == 1) { //纯液情况，取密度为1020。
		value_JingYeZhu = 0.000001 * 1020 * 9.8 * value_Height;
	}
	else { //混砂液情况，采用第一种计算公式。
		value_JingYeZhu = 0.0000001 * ((1020 + dVorD * sandRatio)
			/ (1 + dVorD * sandRatio / dTorT))
			* 9.8 * value_Height;
	}
	/*
	计算井筒摩擦阻力
	*/
	double value_p = 1000; //不可压缩流体密度，视为恒定值1000
	double value_u = 0.001; //不可压缩流体粘度，视为恒定值0.001
	double v = 4 * q / 60 / 3.14 / pow(InvariantParameter::radius, 2);
	double Nre = value_p * InvariantParameter::radius * v / value_u;
	if (Nre < 2300) {
		value_MoCaZuLi = -0.000001 * (64 / Nre) * value_p * pow(v, 2) / 2 / InvariantParameter::radius;
	}
	else {
		value_MoCaZuLi = -0.000001 * (0.3164 / pow(Nre, 0.25)) * value_p * pow(v, 2) / 2
			/ InvariantParameter::radius;
	}
	if (kind == 2) { //纯液无需修正，混砂液采用修正公式。
		double p_d = dTorT / 1020;
		double f_update = -0.1448 * p_d * p_d + 0.1094 * p_d + 1.0354;
		value_MoCaZuLi = value_MoCaZuLi * p_d * f_update;
	}

}

ArgClass::~ArgClass()
{
}

double ArgClass::getPressureJ()
{
	return pressureJ;
}

double ArgClass::getQ()
{
	return q;
}

double ArgClass::getSandMass()
{
	return sandMass;
}

double ArgClass::getdVolume()
{
	return dVolume;
}

int ArgClass::getKind()
{
	return kind;
}

double ArgClass::getdVorD()
{
	return dVorD;
}

double ArgClass::getdTorT()
{
	return dTorT;
}

double ArgClass::getResistanceBend()
{
	return resistanceBend;
}

double ArgClass::getSpeedFlow()
{
	return speedFlow;
}

double ArgClass::getSlope()
{
	return slope;
}

double ArgClass::getSandRatio()
{
	return sandRatio;
}

double ArgClass::getDragReduction()
{
	return dragReduction;
}

double ArgClass::getHoleLength()
{
	return holeDensity;
}

double ArgClass::getHoleDensity()
{
	return holeDensity;
}

double ArgClass::geteEmissvity()
{
	return emissvity;
}

double ArgClass::getValue_JingYeZhu()
{
	return value_JingYeZhu;
}

double ArgClass::getValue_MoCaZuLi()
{
	return value_MoCaZuLi;
}

double ArgClass::getValue_Height()
{
	return value_Height;
}

double ArgClass::getM()
{
	return M;
}

double ArgClass::getDensity()
{
	return density;
}

void ArgClass::setValue_Height(double height)
{
	this->value_Height = height;
}

void ArgClass::setM(double m)
{
	M = m;
}

void ArgClass::PrintArgClass() {
	cout << "//////////////////打印开始///////////////////" << endl;
	cout << "pressureJ: " << pressureJ << endl;
	cout << "q: " << q << endl;
	cout << "sandMass: " << sandMass << endl;
	cout << "dVolume: " << dVolume << endl;
	cout << "kind: " << kind << endl;
	cout << "dVorD: " << dVorD << endl;
	cout << "dTorT: " << dTorT << endl;
	cout << "resistanceBend: " << resistanceBend << endl;
	cout << "speedFlow: " << speedFlow << endl;
	cout << "slope: " << slope << endl;
	cout << "sandRatio: " << sandRatio << endl;
	cout << "dragReduction: " << dragReduction << endl;
	cout << "holeLength: " << holeLength << endl;
	cout << "holeDensity: " << holeDensity << endl;
	cout << "emissvity: " << emissvity << endl;
	cout << "M: " << M << endl;
	cout << "density: " << density << endl;
	cout << "value_Height: " << value_Height << endl;
	cout << "value_JingYeZhu: " << value_JingYeZhu << endl;
	cout << "value_MoCaZuLi: " << value_MoCaZuLi << endl;
	cout << "//////////////////打印结束///////////////////" << endl;
}