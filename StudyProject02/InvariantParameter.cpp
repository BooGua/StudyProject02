#include"InvariantParameter.h"
#include"ArrayJingYaLi.h"
#include"ArgClass.h"

double InvariantParameter::pressureClose;//闭合压力(公制单位 Mpa  英制单位psi)
double InvariantParameter::volume;//垂直井筒体积:垂深*套管面积  (公制单位m^3 英制单位bbl)
double InvariantParameter::radius;//井筒半径(公制单位m 英制单位inch)
double InvariantParameter::height;//射孔段中部垂深(公制单位m 英制单位ft)
double InvariantParameter::length;//射孔段中部斜深(公制单位m 英制单位ft)
int    InvariantParameter::num;//孔眼个数 (单位无),=射孔段长度×孔眼密度×发射率
double InvariantParameter::cH;//修正系数,用来算孔眼摩阻 (单位无) 0.8-1
double InvariantParameter::dH;//孔眼直径(公制单位mm英制单位inch)

InvariantParameter::InvariantParameter() {}

InvariantParameter::InvariantParameter(double pressureClose, double volume, double radius, double height, double length,
	int num, double cH, double dH) //8个变量。
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