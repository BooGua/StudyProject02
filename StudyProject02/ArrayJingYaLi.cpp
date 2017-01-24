#include<iostream>
#include<math.h>
#include"InvariantParameter.h"
#include"ArrayJingYaLi.h"
#include"ArgClass.h"

using namespace std;

/*
垂直井筒压入液体
*/
void ArrayJingYaLi::attach(ArgClass argArrayClass)
{
	if (moment_height + argArrayClass.getValue_Height() <= HEIGHT_UPRIGHT) { //井筒加入新段未满时，直接加入
		moment_height = moment_height + argArrayClass.getValue_Height();
		arrayList_height.push_back(argArrayClass);
	}
	else { //井筒加入新段后超出井筒长度
		moment_height = moment_height + argArrayClass.getValue_Height();
		arrayList_height.push_back(argArrayClass);
		if (moment_height - HEIGHT_UPRIGHT < arrayList_height[0].getValue_Height()) {
			//超出井筒长度小于末端第一段长度，需将末端分成两部分，一部分留下，一部分压入水平井段
			ArgClass newArgArrayClass(argArrayClass, moment_height - HEIGHT_UPRIGHT);
			newArgArrayClass.Calculator();//分出段根据新数据重新计算液柱净压力、摩擦阻力。
			attach_horizontal(newArgArrayClass);
			arrayList_height[0].setValue_Height(arrayList_height[0].getValue_Height()
				- (moment_height - HEIGHT_UPRIGHT));
			arrayList_height[0].Calculator();//留下段根据新数据重新计算液柱净压力、摩擦阻力。
			moment_height = HEIGHT_UPRIGHT;
		}
		else {
			//超出井筒长度大于末端第一段长度，需现将末端第一段全部压入水平井筒，重复此步骤，直到超出井筒长度小于末端第一段长度
			while (moment_height - arrayList_height[0].getValue_Height() > HEIGHT_UPRIGHT) {
				//重复将末端第一段全部压入水平井筒
				moment_height = moment_height - arrayList_height[0].getValue_Height();
				ArgClass newArgArrayClass(argArrayClass, argArrayClass.getValue_Height());
				attach_horizontal(newArgArrayClass);
				arrayList_height.erase(arrayList_height.begin());
			}
			if (moment_height - arrayList_height[0].getValue_Height() == HEIGHT_UPRIGHT) {
				//超出长度刚好等于新加段长度，直接将末端段移入水平井
				moment_height = HEIGHT_UPRIGHT;
				attach_horizontal(arrayList_height[0]);//更改过。原句：ArgClass newArgArrayClass(argArrayClass, argArrayClass.getValue_Height());
				arrayList_height.erase(arrayList_height.begin());
			}
			else { //此情况需将末端段分成两部分，一部分移入水平井筒
				ArgClass newArgArrayClass(argArrayClass, moment_height - HEIGHT_UPRIGHT);
				newArgArrayClass.Calculator(); //分出段根据新数据重新计算液柱净压力、摩擦阻力。
				attach_horizontal(newArgArrayClass);
				arrayList_height[0].setValue_Height(HEIGHT_UPRIGHT - moment_height + arrayList_height[0].getValue_Height());
				arrayList_height[0].Calculator(); //留下段根据新数据重新计算液柱净压力、摩擦阻力。
				moment_height = HEIGHT_UPRIGHT;
			}
		}
	}
}
/*
水平井筒压入液体
*/
void ArrayJingYaLi::attach_horizontal(ArgClass argArrayClass)
{
	//加进来的argArrayClass是已经分割过的类，代码实现类似于垂直井筒
	//只有当水平井筒移除段时，才累加M
	if (moment_length + argArrayClass.getValue_Height() <= LENGTH_HORIZONTAL) {
		moment_length = moment_length + argArrayClass.getValue_Height();
		arrayList_horizontal.push_back(argArrayClass);
	}
	else {
		moment_length = moment_length + argArrayClass.getValue_Height();
		arrayList_horizontal.push_back(argArrayClass);
		while (moment_length - arrayList_horizontal[0].getValue_Height() > LENGTH_HORIZONTAL) {
			moment_length = moment_length - arrayList_horizontal[0].getValue_Height();

			PressureJ = arrayList_horizontal[0].getPressureJ(); //记录井口压力
			ResistanceBend = arrayList_horizontal[0].getResistanceBend(); //记录弯曲摩阻。
			this->M_sand = M_sand + arrayList_horizontal[0].getM(); //累加M。
			array_density = arrayList_horizontal[0].getDensity(); //记录density。
			this->Q = arrayList_horizontal[0].getQ(); //记录排量。			
			array_holeLength = arrayList_horizontal[0].getHoleLength(); //记录holeLength。
			array_holeDensity = arrayList_horizontal[0].getHoleDensity();//记录holeDensity。
			array_emissvity = arrayList_horizontal[0].geteEmissvity();//记录missvity。

			arrayList_horizontal.erase(arrayList_horizontal.begin());
		}
		if (moment_length - arrayList_horizontal[0].getValue_Height() == LENGTH_HORIZONTAL) {
			moment_length = LENGTH_HORIZONTAL;
			PressureJ = arrayList_horizontal[0].getPressureJ(); //记录井口压力
			ResistanceBend = arrayList_horizontal[0].getResistanceBend(); //记录弯曲摩阻。
			this->M_sand = M_sand + arrayList_horizontal[0].getM(); //累加M。
			array_density = arrayList_horizontal[0].getDensity(); //记录density。
			this->Q = arrayList_horizontal[0].getQ(); //记录排量。			
			array_holeLength = arrayList_horizontal[0].getHoleLength(); //记录holeLength。
			array_holeDensity = arrayList_horizontal[0].getHoleDensity();//记录holeDensity。
			array_emissvity = arrayList_horizontal[0].geteEmissvity();//记录missvity。

			arrayList_horizontal.erase(arrayList_horizontal.begin());
		}
		else {
			ArgClass newArgArrayClass(argArrayClass, moment_length - LENGTH_HORIZONTAL);
			newArgArrayClass.Calculator(); //分出段根据新数据重新计算液柱净压力、摩擦阻力。
			PressureJ = newArgArrayClass.getPressureJ(); //记录井口压力
			ResistanceBend = newArgArrayClass.getResistanceBend(); //记录弯曲摩阻。
			this->M_sand = M_sand + newArgArrayClass.getM(); //累加M。
			array_density = newArgArrayClass.getDensity(); //记录density。
			this->Q = newArgArrayClass.getQ(); //记录排量。			
			array_holeLength = newArgArrayClass.getHoleLength(); //记录holeLength。
			array_holeDensity = newArgArrayClass.getHoleDensity();//记录holeDensity。
			array_emissvity = newArgArrayClass.geteEmissvity();//记录missvity。
			//TODO:分出来的段已经从井筒中移除，用不用销毁？

			arrayList_horizontal[0].setValue_Height(LENGTH_HORIZONTAL - moment_length
				+ arrayList_horizontal[0].getValue_Height());
			arrayList_horizontal[0].Calculator();//留下的部分重新计算参数。
			moment_length = LENGTH_HORIZONTAL;
		}
	}
}

/*
遍历累加垂直井筒中的液柱净压力
*/
double ArrayJingYaLi::CalculateJingYeZhuYaLi()
{
	double result = 0;
	for (ArgClass argArrayClass : arrayList_height) {
		result = result + argArrayClass.getValue_JingYeZhu();
	}
	JingYeZhu = result;
	return result;
}

/*
遍历累加垂直及水平井筒中的摩擦阻力
*/
double ArrayJingYaLi::CalculateMoCaZuLi()
{
	double result = 0;
	for (ArgClass argArrayClass : arrayList_height) {
		result = result + argArrayClass.getValue_MoCaZuLi();
	}
	for (ArgClass argArrayClass : arrayList_horizontal) {
		result = result + argArrayClass.getValue_MoCaZuLi();
	}
	MoCaZuLi = result;
	return result;
}

/*
计算孔眼摩阻
*/
double ArrayJingYaLi::CalculateKongYanMoZu()
{
	double result = 0;
	 
	if (M_sand == 0) {
		return 0;
	}
	else if (M_sand > 907) {
		M_sand = 907;
	}
	double M_sand_temp = M_sand;
	double true_num = array_holeLength * array_holeDensity * array_emissvity;
	double C_d = 0.56 + 9.458 * 0.000001 * M_sand_temp / InvariantParameter::num;
	
	result = 2.25 * 0.000000001 * array_density * pow(Q, 2) / pow(true_num, 2)
		/ pow(InvariantParameter::dH, 4) / pow(C_d, 2);
	//TODO: 压裂液密度的计算模型有误，要到ArgClass的构造函数中更改。需和磊磊确定。

	KongYanMoZu = result;

	return result;
}

/*
净压力总体计算
*/
double ArrayJingYaLi::CalculateJingYaLi() 
{
	CalculateJingYeZhuYaLi();
	CalculateMoCaZuLi();
	CalculateKongYanMoZu();

	return PressureJ + JingYeZhu - MoCaZuLi - KongYanMoZu - ResistanceBend - InvariantParameter::pressureClose;
}
