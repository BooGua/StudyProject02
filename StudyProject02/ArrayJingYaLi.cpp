#include<iostream>
#include<math.h>
#include"InvariantParameter.h"
#include"ArrayJingYaLi.h"
#include"ArgClass.h"

using namespace std;

/*
��ֱ��Ͳѹ��Һ��
*/
void ArrayJingYaLi::attach(ArgClass argArrayClass)
{
	if (moment_height + argArrayClass.getValue_Height() <= HEIGHT_UPRIGHT) { //��Ͳ�����¶�δ��ʱ��ֱ�Ӽ���
		moment_height = moment_height + argArrayClass.getValue_Height();
		arrayList_height.push_back(argArrayClass);
	}
	else { //��Ͳ�����¶κ󳬳���Ͳ����
		moment_height = moment_height + argArrayClass.getValue_Height();
		arrayList_height.push_back(argArrayClass);
		if (moment_height - HEIGHT_UPRIGHT < arrayList_height[0].getValue_Height()) {
			//������Ͳ����С��ĩ�˵�һ�γ��ȣ��轫ĩ�˷ֳ������֣�һ�������£�һ����ѹ��ˮƽ����
			ArgClass newArgArrayClass(argArrayClass, moment_height - HEIGHT_UPRIGHT);
			newArgArrayClass.Calculator();//�ֳ��θ������������¼���Һ����ѹ����Ħ��������
			attach_horizontal(newArgArrayClass);
			arrayList_height[0].setValue_Height(arrayList_height[0].getValue_Height()
				- (moment_height - HEIGHT_UPRIGHT));
			arrayList_height[0].Calculator();//���¶θ������������¼���Һ����ѹ����Ħ��������
			moment_height = HEIGHT_UPRIGHT;
		}
		else {
			//������Ͳ���ȴ���ĩ�˵�һ�γ��ȣ����ֽ�ĩ�˵�һ��ȫ��ѹ��ˮƽ��Ͳ���ظ��˲��裬ֱ��������Ͳ����С��ĩ�˵�һ�γ���
			while (moment_height - arrayList_height[0].getValue_Height() > HEIGHT_UPRIGHT) {
				//�ظ���ĩ�˵�һ��ȫ��ѹ��ˮƽ��Ͳ
				moment_height = moment_height - arrayList_height[0].getValue_Height();
				ArgClass newArgArrayClass(argArrayClass, argArrayClass.getValue_Height());
				attach_horizontal(newArgArrayClass);
				arrayList_height.erase(arrayList_height.begin());
			}
			if (moment_height - arrayList_height[0].getValue_Height() == HEIGHT_UPRIGHT) {
				//�������ȸպõ����¼Ӷγ��ȣ�ֱ�ӽ�ĩ�˶�����ˮƽ��
				moment_height = HEIGHT_UPRIGHT;
				attach_horizontal(arrayList_height[0]);//���Ĺ���ԭ�䣺ArgClass newArgArrayClass(argArrayClass, argArrayClass.getValue_Height());
				arrayList_height.erase(arrayList_height.begin());
			}
			else { //������轫ĩ�˶ηֳ������֣�һ��������ˮƽ��Ͳ
				ArgClass newArgArrayClass(argArrayClass, moment_height - HEIGHT_UPRIGHT);
				newArgArrayClass.Calculator(); //�ֳ��θ������������¼���Һ����ѹ����Ħ��������
				attach_horizontal(newArgArrayClass);
				arrayList_height[0].setValue_Height(HEIGHT_UPRIGHT - moment_height + arrayList_height[0].getValue_Height());
				arrayList_height[0].Calculator(); //���¶θ������������¼���Һ����ѹ����Ħ��������
				moment_height = HEIGHT_UPRIGHT;
			}
		}
	}
}
/*
ˮƽ��Ͳѹ��Һ��
*/
void ArrayJingYaLi::attach_horizontal(ArgClass argArrayClass)
{
	//�ӽ�����argArrayClass���Ѿ��ָ�����࣬����ʵ�������ڴ�ֱ��Ͳ
	//ֻ�е�ˮƽ��Ͳ�Ƴ���ʱ�����ۼ�M
	if (moment_length + argArrayClass.getValue_Height() <= LENGTH_HORIZONTAL) {
		moment_length = moment_length + argArrayClass.getValue_Height();
		arrayList_horizontal.push_back(argArrayClass);
	}
	else {
		moment_length = moment_length + argArrayClass.getValue_Height();
		arrayList_horizontal.push_back(argArrayClass);
		while (moment_length - arrayList_horizontal[0].getValue_Height() > LENGTH_HORIZONTAL) {
			moment_length = moment_length - arrayList_horizontal[0].getValue_Height();

			PressureJ = arrayList_horizontal[0].getPressureJ(); //��¼����ѹ��
			ResistanceBend = arrayList_horizontal[0].getResistanceBend(); //��¼����Ħ�衣
			this->M_sand = M_sand + arrayList_horizontal[0].getM(); //�ۼ�M��
			array_density = arrayList_horizontal[0].getDensity(); //��¼density��
			this->Q = arrayList_horizontal[0].getQ(); //��¼������			
			array_holeLength = arrayList_horizontal[0].getHoleLength(); //��¼holeLength��
			array_holeDensity = arrayList_horizontal[0].getHoleDensity();//��¼holeDensity��
			array_emissvity = arrayList_horizontal[0].geteEmissvity();//��¼missvity��

			arrayList_horizontal.erase(arrayList_horizontal.begin());
		}
		if (moment_length - arrayList_horizontal[0].getValue_Height() == LENGTH_HORIZONTAL) {
			moment_length = LENGTH_HORIZONTAL;
			PressureJ = arrayList_horizontal[0].getPressureJ(); //��¼����ѹ��
			ResistanceBend = arrayList_horizontal[0].getResistanceBend(); //��¼����Ħ�衣
			this->M_sand = M_sand + arrayList_horizontal[0].getM(); //�ۼ�M��
			array_density = arrayList_horizontal[0].getDensity(); //��¼density��
			this->Q = arrayList_horizontal[0].getQ(); //��¼������			
			array_holeLength = arrayList_horizontal[0].getHoleLength(); //��¼holeLength��
			array_holeDensity = arrayList_horizontal[0].getHoleDensity();//��¼holeDensity��
			array_emissvity = arrayList_horizontal[0].geteEmissvity();//��¼missvity��

			arrayList_horizontal.erase(arrayList_horizontal.begin());
		}
		else {
			ArgClass newArgArrayClass(argArrayClass, moment_length - LENGTH_HORIZONTAL);
			newArgArrayClass.Calculator(); //�ֳ��θ������������¼���Һ����ѹ����Ħ��������
			PressureJ = newArgArrayClass.getPressureJ(); //��¼����ѹ��
			ResistanceBend = newArgArrayClass.getResistanceBend(); //��¼����Ħ�衣
			this->M_sand = M_sand + newArgArrayClass.getM(); //�ۼ�M��
			array_density = newArgArrayClass.getDensity(); //��¼density��
			this->Q = newArgArrayClass.getQ(); //��¼������			
			array_holeLength = newArgArrayClass.getHoleLength(); //��¼holeLength��
			array_holeDensity = newArgArrayClass.getHoleDensity();//��¼holeDensity��
			array_emissvity = newArgArrayClass.geteEmissvity();//��¼missvity��
			//TODO:�ֳ����Ķ��Ѿ��Ӿ�Ͳ���Ƴ����ò������٣�

			arrayList_horizontal[0].setValue_Height(LENGTH_HORIZONTAL - moment_length
				+ arrayList_horizontal[0].getValue_Height());
			arrayList_horizontal[0].Calculator();//���µĲ������¼��������
			moment_length = LENGTH_HORIZONTAL;
		}
	}
}

/*
�����ۼӴ�ֱ��Ͳ�е�Һ����ѹ��
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
�����ۼӴ�ֱ��ˮƽ��Ͳ�е�Ħ������
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
�������Ħ��
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
	//TODO: ѹ��Һ�ܶȵļ���ģ������Ҫ��ArgClass�Ĺ��캯���и��ġ��������ȷ����

	KongYanMoZu = result;

	return result;
}

/*
��ѹ���������
*/
double ArrayJingYaLi::CalculateJingYaLi() 
{
	CalculateJingYeZhuYaLi();
	CalculateMoCaZuLi();
	CalculateKongYanMoZu();

	return PressureJ + JingYeZhu - MoCaZuLi - KongYanMoZu - ResistanceBend - InvariantParameter::pressureClose;
}
