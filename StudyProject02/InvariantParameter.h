#pragma once
/*
此类用于存储不变参数，静态，可全局调用。
*/
class InvariantParameter
{
public:
	InvariantParameter();
	InvariantParameter(double pressureClose, double volume, double radius, double height,
		double length, int num, double cH, double dH);
	~InvariantParameter();
public:
	static double  pressureClose;//闭合压力(公制单位 Mpa  英制单位psi)
	static double  volume;//垂直井筒体积:垂深*套管面积  (公制单位m^3 英制单位bbl)
	static double  radius;//井筒半径(公制单位m 英制单位inch)
	static double  height;//射孔段中部垂深(公制单位m 英制单位ft)
	static double  length;//射孔段中部斜深(公制单位m 英制单位ft)
	static int     num;//总孔眼个数
	static double  cH;//修正系数,用来算孔眼摩阻 (单位无) 0.8-1
	static double  dH;//孔眼直径(公制单位mm英制单位inch)
};
