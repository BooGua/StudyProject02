#pragma once
#include<vector>
#include"ArgClass.h"

/*
此类用于模拟井筒，包括垂直井筒部分和水平井筒部分。
此类负责计算总净液柱压力、总摩擦阻力，以及孔眼摩阻。
*/

using namespace std;

class ArrayJingYaLi {
private:
	double HEIGHT_UPRIGHT = 100; //井筒垂直高度
	double LENGTH_HORIZONTAL = 200; //井筒水平长度
	double moment_height = 0; //液体临时垂直高度
	double moment_length = 0; //液体临时水平长度

	/*
	计算孔眼摩阻所用临时量
	*/
	double array_holeLength = 0;
	double array_holeDensity = 0;
	double array_emissvity = 0;
	double array_density = 0; //压裂液密度,根据kind不同改变

	double M_sand = 0; //通过孔眼的支撑剂质量,累积量，Kg。Mmax=907Kg	
	double Q = 0; //排出段的排量

	double JingYeZhu = 0;
	double MoCaZuLi = 0;
	double KongYanMoZu = 0;
	double PressureJ = 0;
	double ResistanceBend = 0;

	vector<ArgClass> arrayList_height; //垂直队列
	vector<ArgClass> arrayList_horizontal; //水平队列

public:
	/*
	垂直井筒加入一段液体
	*/
	void attach(ArgClass argArrayClass);
	/*
	水平井筒加入一段液体
	*/
	void attach_horizontal(ArgClass argArrayClass);
	/*
	计算总净液柱压力
	*/
	double CalculateJingYeZhuYaLi();
	/*
	计算总摩擦阻力
	*/
	double CalculateMoCaZuLi();
	/*
	计算孔眼摩阻
	*/
	double CalculateKongYanMoZu();
	/*
	计算总净压力
	*/
	double CalculateJingYaLi();
};